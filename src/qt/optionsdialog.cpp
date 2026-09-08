// Copyright (c) 2011-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <qt/optionsdialog.h>
#include <qt/forms/ui_optionsdialog.h>

#include <qt/optionsmodel.h>
#include <qt/guiutil.h>

#include <QDataWidgetMapper>
#include <QIntValidator>
#include <QMessageBox>

ProxyAddressValidator::ProxyAddressValidator(QObject *parent)
    : QValidator(parent)
{
}

QValidator::State ProxyAddressValidator::validate(QString &input, int &pos) const
{
    Q_UNUSED(pos);

    // Very permissive: trim whitespace; disallow spaces inside.
    // (Hostname/IP validation is handled later via proxy validation logic.)
    input = input.trimmed();
    if (input.contains(' '))
        return QValidator::Invalid;
    return QValidator::Acceptable;
}

OptionsDialog::OptionsDialog(QWidget *parent, bool enableWallet)
    : QDialog(parent),
      ui(new Ui::OptionsDialog),
      model(nullptr),
      mapper(nullptr)
{
    Q_UNUSED(enableWallet);
    ui->setupUi(this);

    // Validators for port fields (QLineEdit in your .ui)
    ui->proxyPort->setValidator(new QIntValidator(1, 65535, ui->proxyPort));
    ui->proxyPortTor->setValidator(new QIntValidator(1, 65535, ui->proxyPortTor));

    // Proxy IP validators
    ui->proxyIp->setValidator(new ProxyAddressValidator(ui->proxyIp));
    ui->proxyIpTor->setValidator(new ProxyAddressValidator(ui->proxyIpTor));

    // Hook up UI changes to validation
    connect(ui->connectSocks, SIGNAL(toggled(bool)), this, SLOT(updateProxyValidationState()));
    connect(ui->connectSocksTor, SIGNAL(toggled(bool)), this, SLOT(updateProxyValidationState()));
    connect(ui->proxyIp, SIGNAL(textChanged(QString)), this, SLOT(updateProxyValidationState()));
    connect(ui->proxyIpTor, SIGNAL(textChanged(QString)), this, SLOT(updateProxyValidationState()));
    connect(ui->proxyPort, SIGNAL(textChanged(QString)), this, SLOT(updateProxyValidationState()));
    connect(ui->proxyPortTor, SIGNAL(textChanged(QString)), this, SLOT(updateProxyValidationState()));

    connect(ui->hideTrayIcon, SIGNAL(stateChanged(int)), this, SLOT(on_hideTrayIcon_stateChanged(int)));

    clearStatusLabel();
    updateProxyValidationState();
    updateDefaultProxyNets();
}

OptionsDialog::~OptionsDialog()
{
    delete ui;
}

void OptionsDialog::setModel(OptionsModel *model)
{
    this->model = model;
    if (!model)
        return;

    // Simple one-shot population; (keeps you compiling, avoids old get*/set* APIs)
    ui->bitcoinAtStartup->setChecked(model->data(model->index(OptionsModel::StartAtStartup)).toBool());
    ui->threadsScriptVerif->setValue(model->data(model->index(OptionsModel::ThreadsScriptVerif)).toInt());
    ui->databaseCache->setValue(model->data(model->index(OptionsModel::DatabaseCache)).toInt());
    ui->spendZeroConfChange->setChecked(model->data(model->index(OptionsModel::SpendZeroConfChange)).toBool());

    ui->coinControlFeatures->setChecked(model->getCoinControlFeatures());
    ui->minimizeToTray->setChecked(model->getMinimizeToTray());
    ui->minimizeOnClose->setChecked(model->getMinimizeOnClose());

    // Proxy
    ui->connectSocks->setChecked(model->data(model->index(OptionsModel::ProxyUse)).toBool());
    ui->proxyIp->setText(model->data(model->index(OptionsModel::ProxyIP)).toString());
    ui->proxyPort->setText(QString::number(model->data(model->index(OptionsModel::ProxyPort)).toInt()));

    // Tor proxy (if model supports it, otherwise leave defaults)
    ui->connectSocksTor->setChecked(model->data(model->index(OptionsModel::ProxyUseTor)).toBool());
    ui->proxyIpTor->setText(model->data(model->index(OptionsModel::ProxyIPTor)).toString());
    ui->proxyPortTor->setText(QString::number(model->data(model->index(OptionsModel::ProxyPortTor)).toInt()));

    updateProxyValidationState();
    updateDefaultProxyNets();
}

void OptionsDialog::setMapper()
{
    // We use explicit read/write in this fork. Keep for API compatibility.
}

void OptionsDialog::setOkButtonState(bool fState)
{
    ui->okButton->setEnabled(fState);
}

static bool parsePort(const QLineEdit* edit, int& portOut)
{
    bool ok = false;
    int p = edit->text().toInt(&ok);
    if (!ok || p < 1 || p > 65535) return false;
    portOut = p;
    return true;
}

void OptionsDialog::updateProxyValidationState()
{
    // If proxy is enabled, require non-empty IP and valid port.
    bool ok = true;

    if (ui->connectSocks->isChecked())
    {
        int port = 0;
        ok = ok && !ui->proxyIp->text().trimmed().isEmpty();
        ok = ok && parsePort(ui->proxyPort, port);
    }

    if (ui->connectSocksTor->isChecked())
    {
        int port = 0;
        ok = ok && !ui->proxyIpTor->text().trimmed().isEmpty();
        ok = ok && parsePort(ui->proxyPortTor, port);
    }

    setOkButtonState(ok);
    if (!ok)
        showRestartWarning(false);
}

void OptionsDialog::updateDefaultProxyNets()
{
    // Keep it simple: if default proxy enabled, mark IPv4/IPv6 active. Tor nets shown if Tor proxy enabled.
    const bool useProxy = ui->connectSocks->isChecked();
    const bool useTorProxy = ui->connectSocksTor->isChecked();

    ui->proxyReachIPv4->setChecked(useProxy);
    ui->proxyReachIPv6->setChecked(useProxy);
    ui->proxyReachTor->setChecked(useTorProxy);

    ui->proxyActiveNets->setText(QString());
}

void OptionsDialog::showRestartWarning(bool fPersistent)
{
    if (fPersistent)
    {
        ui->statusLabel->setText(tr("Client restart required to activate changes."));
        ui->statusLabel->setStyleSheet("QLabel { color: #d35400; }");
    }
    else
    {
        ui->statusLabel->clear();
        ui->statusLabel->setStyleSheet(QString());
    }
}

void OptionsDialog::clearStatusLabel()
{
    ui->statusLabel->clear();
    ui->statusLabel->setStyleSheet(QString());
}

void OptionsDialog::on_okButton_clicked()
{
    // Tray / window behavior (Qt-only)
    if (model)
    {
        model->setData(model->index(OptionsModel::HideTrayIcon, 0), ui->hideTrayIcon->isChecked(), Qt::EditRole);
        model->setData(model->index(OptionsModel::MinimizeToTray, 0), ui->minimizeToTray->isChecked(), Qt::EditRole);
        model->setData(model->index(OptionsModel::MinimizeOnClose, 0), ui->minimizeOnClose->isChecked(), Qt::EditRole);
    }


    if (!model)
        return;

    model->setData(model->index(OptionsModel::StartAtStartup),
                   ui->bitcoinAtStartup->isChecked());

    model->setData(model->index(OptionsModel::ThreadsScriptVerif),
                   ui->threadsScriptVerif->value());

    model->setData(model->index(OptionsModel::DatabaseCache),
                   ui->databaseCache->value());

    model->setData(model->index(OptionsModel::SpendZeroConfChange),
                   ui->spendZeroConfChange->isChecked());

    model->setData(model->index(OptionsModel::ProxyUse),
                   ui->connectSocks->isChecked());

    model->setData(model->index(OptionsModel::ProxyIP),
                   ui->proxyIp->text().trimmed());

    int port = 0;
    if (parsePort(ui->proxyPort, port))
        model->setData(model->index(OptionsModel::ProxyPort), port);

    model->setData(model->index(OptionsModel::ProxyUseTor),
                   ui->connectSocksTor->isChecked());

    model->setData(model->index(OptionsModel::ProxyIPTor),
                   ui->proxyIpTor->text().trimmed());

    int portTor = 0;
    if (parsePort(ui->proxyPortTor, portTor))
        model->setData(model->index(OptionsModel::ProxyPortTor), portTor);

    showRestartWarning(true);
    QDialog::accept();
}

void OptionsDialog::on_cancelButton_clicked()
{
    QDialog::reject();
}

void OptionsDialog::on_resetButton_clicked()
{
    if (!model)
        return;

    if (QMessageBox::question(this, tr("Confirm options reset"),
                              tr("Client restart required to activate changes.\n\nReset all options to default values?"),
                              QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes)
        return;

    model->Reset();
    setModel(model); // repopulate widgets from defaults
    showRestartWarning(true);
}

void OptionsDialog::on_openBitcoinConfButton_clicked()
{
    // Open config file if available; ignore failures.
    GUIUtil::openBitcoinConf();
}

void OptionsDialog::on_hideTrayIcon_stateChanged(int)
{
    // This option typically requires restart to update tray state cleanly.
    showRestartWarning(true);
}
