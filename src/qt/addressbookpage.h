// Copyright (c) 2011-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_ADDRESSBOOKPAGE_H
#define BITCOIN_QT_ADDRESSBOOKPAGE_H

#include <QDialog>
#include <QSortFilterProxyModel>
#include <QString>

class AddressTableModel;
class OptionsModel;
class PlatformStyle;
class WalletModel;
class QAction;
class QMenu;

namespace Ui {
class AddressBookPage;
}

/**
 * Dialog for editing the wallet address book.
 *
 * Mode:
 *  - ForSelection: user is selecting an address to send funds to
 *  - ForEditing: user is editing the address book
 *
 * Tabs:
 *  - SendingTab: list of sending addresses
 *  - ReceivingTab: list of receiving addresses
 */
class AddressBookPage : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        ForSelection,
        ForEditing
    };

    enum Tabs {
        SendingTab = 0,
        ReceivingTab = 1
    };

    explicit AddressBookPage(const PlatformStyle *platformStyle,
                             Mode mode,
                             Tabs tab,
                             QWidget *parent = nullptr);
    ~AddressBookPage();

    void setModel(AddressTableModel *model);
    void setOptionsModel(OptionsModel *optionsModel);
    void setWalletModel(WalletModel *walletModel);

    /** Return the currently selected address (used by SendCoinsEntry) */
    QString getReturnValue() const { return returnValue; }

public Q_SLOTS:
    void setTab(Tabs tab);
    void done(int retval) override;
    void exportButtonClicked();
    void onEditAction();
    void onNewAddressAction();
    void onDeleteAction();
    void selectionChanged();
    void contextualMenu(const QPoint &point);
    void selectNewAddress(const QModelIndex &parent, int begin, int end);

private Q_SLOTS:
    // Auto-connected from .ui (keep names stable)
    void on_newAddress_clicked();
    void on_copyAddress_clicked();
    void onCopyLabelAction();
    void on_deleteAddress_clicked();
    void on_exportButton_clicked();

private:
    void setMode(Mode mode);
    void updateButtons();

    Ui::AddressBookPage *ui;

    AddressTableModel *model;
    QSortFilterProxyModel *proxyModel;
    WalletModel *walletModel;
    OptionsModel *optionsModel;

    Mode mode;
    Tabs tab;

    QAction *newAction;
    QAction *copyAction;
    QAction *deleteAction;

    QMenu *contextMenu;

    QString newAddressToSelect;
    QString returnValue;

    const PlatformStyle *platformStyle;
};

#endif // BITCOIN_QT_ADDRESSBOOKPAGE_H
