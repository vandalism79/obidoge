// Copyright (c) 2011-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_WALLETFRAME_H
#define BITCOIN_QT_WALLETFRAME_H

#include <QFrame>
#include <QMap>
#include <QString>

class BitcoinGUI;
class ClientModel;
class PlatformStyle;
class SendCoinsRecipient;
class WalletModel;
class WalletView;
class QStackedWidget;

/**
 * A container for all wallets and their views.
 *
 * BitcoinGUI owns WalletFrame. WalletFrame owns WalletView(s).
 */
class WalletFrame : public QFrame
{
    Q_OBJECT

public:
    explicit WalletFrame(const PlatformStyle* platformStyleIn, BitcoinGUI* guiIn);
    ~WalletFrame();

    void setClientModel(ClientModel* clientModelIn);

    /** Add a wallet view to the frame. */
    bool addWallet(const QString& name, WalletModel* walletModel);

    /** Make wallet 'name' the current wallet; returns false if not found. */
    bool setCurrentWallet(const QString& name);

    /** Remove wallet 'name'; returns false if not found. */
    bool removeWallet(const QString& name);

    /** Remove all wallets from the frame. */
    void removeAllWallets();

    /** Handle a BIP70/URI payment request; returns true if handled. */
    bool handlePaymentRequest(const SendCoinsRecipient& recipient);

public Q_SLOTS:
    // Navigation
    void gotoOverviewPage();
    void gotoHistoryPage();
    void gotoReceiveCoinsPage();
    void gotoSendCoinsPage(QString addr = QString());
    void gotoSignMessageTab(QString addr = QString());
    void gotoVerifyMessageTab(QString addr = QString());

    // Address book
    void usedSendingAddresses();
    void usedReceivingAddresses();

    // Wallet actions
    void backupWallet();
    void encryptWallet(bool status);
    void changePassphrase();
    void unlockWallet();
    void importPrivateKey();

    // Hive (ObiDoge: Hive UI removed; slot may be a no-op in cpp)
    void gotoHivePage();

    // Sync warning banner
    void showOutOfSyncWarning(bool fShow);
    void outOfSyncWarningClicked();

private:
    WalletView* currentWalletView(); // non-const to match walletframe.cpp

private:
    const PlatformStyle* platformStyle {nullptr};
    BitcoinGUI* gui {nullptr};
    ClientModel* clientModel {nullptr};
    bool bOutOfSync {false};

    QStackedWidget* walletStack {nullptr};
    QMap<QString, WalletView*> mapWalletViews;
};

#endif // BITCOIN_QT_WALLETFRAME_H
