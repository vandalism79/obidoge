// Copyright (c) 2011-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <qt/walletframe.h>

#include <qt/bitcoingui.h>          // for QWidget inheritance visibility
#include <qt/clientmodel.h>
#include <qt/platformstyle.h>
#include <qt/walletmodel.h>
#include <qt/walletview.h>

#include <QHBoxLayout>
#include <QLabel>
#include <QStackedWidget>

WalletFrame::WalletFrame(const PlatformStyle *platformStyleIn, BitcoinGUI *_gui)
    : QFrame(static_cast<QWidget*>(_gui))
    , gui(_gui)
    , clientModel(nullptr)
    , platformStyle(platformStyleIn)
    , bOutOfSync(false)
    , walletStack(nullptr)
{
    walletStack = new QStackedWidget(this);

    // Placeholder page shown when no wallets are loaded
    QLabel *noWallet = new QLabel(tr("No wallet has been loaded."), this);
    noWallet->setAlignment(Qt::AlignCenter);
    walletStack->addWidget(noWallet);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(walletStack);
    setLayout(layout);
}

WalletFrame::~WalletFrame() = default;

void WalletFrame::setClientModel(ClientModel *clientModelIn)
{
    clientModel = clientModelIn;
}

bool WalletFrame::addWallet(const QString& name, WalletModel *walletModel)
{
    if (!gui || !clientModel || !walletModel || mapWalletViews.contains(name))
        return false;

    WalletView *walletView = new WalletView(platformStyle, this);
    walletView->setClientModel(clientModel);
    walletView->setWalletModel(walletModel);
    walletView->showOutOfSyncWarning(bOutOfSync);

    walletStack->addWidget(walletView);
    mapWalletViews[name] = walletView;

    // Make the newly added wallet visible
    walletStack->setCurrentWidget(walletView);
    return true;
}

bool WalletFrame::setCurrentWallet(const QString& name)
{
    if (!mapWalletViews.contains(name))
        return false;

    walletStack->setCurrentWidget(mapWalletViews.value(name));
    return true;
}

bool WalletFrame::removeWallet(const QString &name)
{
    if (!mapWalletViews.contains(name))
        return false;

    WalletView* wv = mapWalletViews.take(name);
    if (wv) {
        walletStack->removeWidget(wv);
        wv->deleteLater();
    }
    return true;
}

void WalletFrame::removeAllWallets()
{
    // Remove all WalletViews from stack and map
    for (auto it = mapWalletViews.begin(); it != mapWalletViews.end(); ++it) {
        WalletView* wv = it.value();
        if (wv) {
            walletStack->removeWidget(wv);
            wv->deleteLater();
        }
    }
    mapWalletViews.clear();
    // leave the placeholder as current (index 0)
    walletStack->setCurrentIndex(0);
}

WalletView* WalletFrame::currentWalletView()
{
    if (!walletStack)
        return nullptr;

    // Prefer current widget if it's a WalletView
    if (WalletView* wv = qobject_cast<WalletView*>(walletStack->currentWidget()))
        return wv;

    // Fallback: first loaded wallet view (prevents silent no-op when placeholder is current)
    if (!mapWalletViews.isEmpty()) {
        WalletView* first = mapWalletViews.begin().value();
        if (first) {
            walletStack->setCurrentWidget(first);
            return first;
        }
    }
    return nullptr;
}

void WalletFrame::gotoOverviewPage()
{
    if (WalletView* wv = currentWalletView())
        wv->gotoOverviewPage();
}

void WalletFrame::gotoHistoryPage()
{
    if (WalletView* wv = currentWalletView())
        wv->gotoHistoryPage();
}

void WalletFrame::gotoReceiveCoinsPage()
{
    if (WalletView* wv = currentWalletView())
        wv->gotoReceiveCoinsPage();
}

void WalletFrame::gotoSendCoinsPage(QString addr)
{
    if (WalletView* wv = currentWalletView())
        wv->gotoSendCoinsPage(addr);
}

void WalletFrame::gotoSignMessageTab(QString addr)
{
    if (WalletView* wv = currentWalletView())
        wv->gotoSignMessageTab(addr);
}

void WalletFrame::gotoVerifyMessageTab(QString addr)
{
    if (WalletView* wv = currentWalletView())
        wv->gotoVerifyMessageTab(addr);
}

void WalletFrame::gotoHivePage()
{
    // ObiDoge: Hive removed. Keep slot for legacy UI connections.
    // Intentionally no-op to satisfy link and avoid accessing removed Hive UI.
}

void WalletFrame::importPrivateKey()
{
    // ObiDoge: keep slot for legacy UI connections. If you have an import dialog,
    // wire it here later. For now, no-op.
}

bool WalletFrame::handlePaymentRequest(const SendCoinsRecipient &recipient)
{
    if (WalletView* wv = currentWalletView())
        return wv->handlePaymentRequest(recipient);
    return false;
}

void WalletFrame::encryptWallet(bool status)
{
    if (WalletView* wv = currentWalletView())
        wv->encryptWallet(status);
}

void WalletFrame::backupWallet()
{
    if (WalletView* wv = currentWalletView())
        wv->backupWallet();
}

void WalletFrame::changePassphrase()
{
    if (WalletView* wv = currentWalletView())
        wv->changePassphrase();
}

void WalletFrame::unlockWallet()
{
    if (WalletView* wv = currentWalletView())
        wv->unlockWallet();
}

void WalletFrame::usedSendingAddresses()
{
    if (WalletView* wv = currentWalletView())
        wv->usedSendingAddresses();
}

void WalletFrame::usedReceivingAddresses()
{
    if (WalletView* wv = currentWalletView())
        wv->usedReceivingAddresses();
}

void WalletFrame::showOutOfSyncWarning(bool fShow)
{
    bOutOfSync = fShow;
    for (auto it = mapWalletViews.begin(); it != mapWalletViews.end(); ++it) {
        if (it.value())
            it.value()->showOutOfSyncWarning(fShow);
    }
}

void WalletFrame::outOfSyncWarningClicked()
{
    // ObiDoge: keep slot for legacy connections.
    // Some forks forward this as a signal; if your GUI expects a signal,
    // connect the overview page directly to BitcoinGUI instead.
}
