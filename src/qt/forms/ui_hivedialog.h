/********************************************************************************
** Form generated from reading UI file 'hivedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIVEDIALOG_H
#define UI_HIVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qt/qcustomplot.h"
#include "qt/tinypie.h"

QT_BEGIN_NAMESPACE

class Ui_HiveDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *createBeesTitleLabel;
    QSpacerItem *horizontalSpacer_9;
    QLabel *warningLabel;
    QLabel *warningLabel2;
    QFrame *createBeesForm;
    QFormLayout *formLayout_2;
    QLabel *currentBeeCostLabel_2;
    QLabel *currentBeeCostLabel_21;
    QHBoxLayout *horizontalLayout_91;
    QLabel *currentBalance;
    QSpacerItem *horizontalSpacer_91;
    QLabel *beesToCreateLabel_2;
    QHBoxLayout *horizontalLayout_8;
    QSpinBox *beeCountSpinner;
    QSpacerItem *horizontalSpacer_8;
    QLabel *totalCostLabel_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *totalCostLabel;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *createBeesButton;
    QPushButton *releaseSwarmButton;
    QPushButton *showHiveOptionsButton;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *beeCostLabel;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *yourHiveHeader_2;
    QLabel *globalNetworkHiveTitleLabel;
    QSpacerItem *horizontalSpacer_20;
    QCheckBox *showAdvancedStatsCheckbox;
    QFrame *globalHiveSummary;
    QVBoxLayout *verticalLayout_2;
    QFrame *globalHiveSummaryTextRow;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLabel *globalImmatureLabel;
    QSpacerItem *immatureLabelSpacer_2;
    QLabel *label_12;
    QLabel *globalMatureLabel;
    QSpacerItem *immatureLabelSpacer_3;
    QLabel *label_11;
    QLabel *potentialRewardsLabel;
    QSpacerItem *immatureLabelSpacer_5;
    QLabel *label_16;
    QLabel *beePopIndexLabel;
    QSpacerItem *immatureLabelSpacer_6;
    TinyPie *beePopIndexPie;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_13;
    QLabel *blocksTillGlobalRefresh;
    QLabel *label_15;
    QPushButton *refreshGlobalSummaryButton;
    QCustomPlot *beePopGraph;
    QFrame *globalHiveSummaryError;
    QHBoxLayout *horizontalLayout_2;
    QLabel *globalHiveSummaryErrorLabel;
    QPushButton *retryGlobalSummaryButton;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *verticalSpacer;
    QFrame *walletHiveStatsFrame;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *yourHiveHeader;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_13;
    QCheckBox *includeDeadBeesCheckbox;
    QTableView *currentHiveView;
    QHBoxLayout *yourHiveSummary;
    QLabel *label_14;
    QLabel *localHiveWeightLabel;
    TinyPie *hiveWeightPie;
    QSpacerItem *immatureLabelSpacer_4;
    QLabel *label;
    QLabel *immatureLabel;
    QSpacerItem *immatureLabelSpacer;
    QLabel *label_3;
    QLabel *matureLabel;
    QSpacerItem *horizontalSpacer_16;
    QLabel *deadTitleLabel;
    QLabel *deadLabel;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_4;
    QLabel *blocksFoundLabel;
    QSpacerItem *deadLabelSpacer;
    QLabel *label_10;
    QLabel *costLabel;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_5;
    QLabel *rewardsPaidLabel;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_7;
    QLabel *profitLabel;
    QSpacerItem *horizontalSpacer_11;

    void setupUi(QWidget *HiveDialog)
    {
        if (HiveDialog->objectName().isEmpty())
            HiveDialog->setObjectName(QStringLiteral("HiveDialog"));
        HiveDialog->resize(824, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HiveDialog->sizePolicy().hasHeightForWidth());
        HiveDialog->setSizePolicy(sizePolicy);
        HiveDialog->setMinimumSize(QSize(0, 500));
        HiveDialog->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(HiveDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        createBeesTitleLabel = new QLabel(HiveDialog);
        createBeesTitleLabel->setObjectName(QStringLiteral("createBeesTitleLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        createBeesTitleLabel->setFont(font);

        horizontalLayout_9->addWidget(createBeesTitleLabel);

        horizontalSpacer_9 = new QSpacerItem(13, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        warningLabel = new QLabel(HiveDialog);
        warningLabel->setObjectName(QStringLiteral("warningLabel"));
        warningLabel->setMaximumSize(QSize(16, 16));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        warningLabel->setFont(font1);
        warningLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/warning")));
        warningLabel->setScaledContents(true);

        horizontalLayout_9->addWidget(warningLabel);

        warningLabel2 = new QLabel(HiveDialog);
        warningLabel2->setObjectName(QStringLiteral("warningLabel2"));
        warningLabel2->setFont(font);
        warningLabel2->setOpenExternalLinks(true);

        horizontalLayout_9->addWidget(warningLabel2);


        verticalLayout->addLayout(horizontalLayout_9);

        createBeesForm = new QFrame(HiveDialog);
        createBeesForm->setObjectName(QStringLiteral("createBeesForm"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(createBeesForm->sizePolicy().hasHeightForWidth());
        createBeesForm->setSizePolicy(sizePolicy1);
        createBeesForm->setMinimumSize(QSize(0, 145));
        createBeesForm->setStyleSheet(QLatin1String("#createBeesForm{background:url(:/icons/hive_background_flash);\n"
"background-repeat:no-repeat;\n"
"background-position:bottom right;\n"
"background-color:white;}"));
        createBeesForm->setFrameShape(QFrame::StyledPanel);
        createBeesForm->setFrameShadow(QFrame::Sunken);
        formLayout_2 = new QFormLayout(createBeesForm);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        currentBeeCostLabel_2 = new QLabel(createBeesForm);
        currentBeeCostLabel_2->setObjectName(QStringLiteral("currentBeeCostLabel_2"));
        currentBeeCostLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, currentBeeCostLabel_2);

        currentBeeCostLabel_21 = new QLabel(createBeesForm);
        currentBeeCostLabel_21->setObjectName(QStringLiteral("currentBeeCostLabel_21"));
        currentBeeCostLabel_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, currentBeeCostLabel_21);

        horizontalLayout_91 = new QHBoxLayout();
        horizontalLayout_91->setObjectName(QStringLiteral("horizontalLayout_91"));
        currentBalance = new QLabel(createBeesForm);
        currentBalance->setObjectName(QStringLiteral("currentBalance"));
        currentBalance->setFont(font1);

        horizontalLayout_91->addWidget(currentBalance);

        horizontalSpacer_91 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_91->addItem(horizontalSpacer_91);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, horizontalLayout_91);

        beesToCreateLabel_2 = new QLabel(createBeesForm);
        beesToCreateLabel_2->setObjectName(QStringLiteral("beesToCreateLabel_2"));
        beesToCreateLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, beesToCreateLabel_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        beeCountSpinner = new QSpinBox(createBeesForm);
        beeCountSpinner->setObjectName(QStringLiteral("beeCountSpinner"));
        beeCountSpinner->setMinimumSize(QSize(80, 20));
        beeCountSpinner->setMinimum(1);
        beeCountSpinner->setMaximum(9999999);

        horizontalLayout_8->addWidget(beeCountSpinner);

        horizontalSpacer_8 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout_8);

        totalCostLabel_3 = new QLabel(createBeesForm);
        totalCostLabel_3->setObjectName(QStringLiteral("totalCostLabel_3"));
        totalCostLabel_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, totalCostLabel_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        totalCostLabel = new QLabel(createBeesForm);
        totalCostLabel->setObjectName(QStringLiteral("totalCostLabel"));
        totalCostLabel->setFont(font);

        horizontalLayout_4->addWidget(totalCostLabel);

        label_9 = new QLabel(createBeesForm);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        horizontalSpacer_10 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        formLayout_2->setLayout(3, QFormLayout::FieldRole, horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        createBeesButton = new QPushButton(createBeesForm);
        createBeesButton->setObjectName(QStringLiteral("createBeesButton"));
        createBeesButton->setMinimumSize(QSize(100, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/bee"), QSize(), QIcon::Normal, QIcon::Off);
        createBeesButton->setIcon(icon);

        horizontalLayout_3->addWidget(createBeesButton);

        releaseSwarmButton = new QPushButton(createBeesForm);
        releaseSwarmButton->setObjectName(QStringLiteral("releaseSwarmButton"));
        releaseSwarmButton->setMinimumSize(QSize(100, 0));
        releaseSwarmButton->setFont(font);
        releaseSwarmButton->setStyleSheet(QStringLiteral("color:red;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/lock_closed"), QSize(), QIcon::Normal, QIcon::Off);
        releaseSwarmButton->setIcon(icon1);

        horizontalLayout_3->addWidget(releaseSwarmButton);

        showHiveOptionsButton = new QPushButton(createBeesForm);
        showHiveOptionsButton->setObjectName(QStringLiteral("showHiveOptionsButton"));
        showHiveOptionsButton->setMinimumSize(QSize(100, 0));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/options"), QSize(), QIcon::Normal, QIcon::Off);
        showHiveOptionsButton->setIcon(icon2);

        horizontalLayout_3->addWidget(showHiveOptionsButton);

        horizontalSpacer_7 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        formLayout_2->setLayout(4, QFormLayout::FieldRole, horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        beeCostLabel = new QLabel(createBeesForm);
        beeCostLabel->setObjectName(QStringLiteral("beeCostLabel"));
        beeCostLabel->setFont(font1);

        horizontalLayout_10->addWidget(beeCostLabel);

        horizontalSpacer_18 = new QSpacerItem(13, 13, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_18);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout_10);


        verticalLayout->addWidget(createBeesForm);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        yourHiveHeader_2 = new QHBoxLayout();
        yourHiveHeader_2->setObjectName(QStringLiteral("yourHiveHeader_2"));
        globalNetworkHiveTitleLabel = new QLabel(HiveDialog);
        globalNetworkHiveTitleLabel->setObjectName(QStringLiteral("globalNetworkHiveTitleLabel"));
        globalNetworkHiveTitleLabel->setFont(font);

        yourHiveHeader_2->addWidget(globalNetworkHiveTitleLabel);

        horizontalSpacer_20 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        yourHiveHeader_2->addItem(horizontalSpacer_20);

        showAdvancedStatsCheckbox = new QCheckBox(HiveDialog);
        showAdvancedStatsCheckbox->setObjectName(QStringLiteral("showAdvancedStatsCheckbox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(showAdvancedStatsCheckbox->sizePolicy().hasHeightForWidth());
        showAdvancedStatsCheckbox->setSizePolicy(sizePolicy2);
        showAdvancedStatsCheckbox->setMaximumSize(QSize(1000, 16777215));
        showAdvancedStatsCheckbox->setFocusPolicy(Qt::StrongFocus);
        showAdvancedStatsCheckbox->setChecked(false);

        yourHiveHeader_2->addWidget(showAdvancedStatsCheckbox);


        verticalLayout->addLayout(yourHiveHeader_2);

        globalHiveSummary = new QFrame(HiveDialog);
        globalHiveSummary->setObjectName(QStringLiteral("globalHiveSummary"));
        globalHiveSummary->setStyleSheet(QStringLiteral("#globalHiveSummary {background-color:white;}"));
        globalHiveSummary->setFrameShape(QFrame::StyledPanel);
        globalHiveSummary->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(globalHiveSummary);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        globalHiveSummaryTextRow = new QFrame(globalHiveSummary);
        globalHiveSummaryTextRow->setObjectName(QStringLiteral("globalHiveSummaryTextRow"));
        globalHiveSummaryTextRow->setStyleSheet(QStringLiteral(""));
        globalHiveSummaryTextRow->setFrameShape(QFrame::StyledPanel);
        globalHiveSummaryTextRow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(globalHiveSummaryTextRow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_6 = new QLabel(globalHiveSummaryTextRow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_6);

        globalImmatureLabel = new QLabel(globalHiveSummaryTextRow);
        globalImmatureLabel->setObjectName(QStringLiteral("globalImmatureLabel"));

        horizontalLayout->addWidget(globalImmatureLabel);

        immatureLabelSpacer_2 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(immatureLabelSpacer_2);

        label_12 = new QLabel(globalHiveSummaryTextRow);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_12);

        globalMatureLabel = new QLabel(globalHiveSummaryTextRow);
        globalMatureLabel->setObjectName(QStringLiteral("globalMatureLabel"));

        horizontalLayout->addWidget(globalMatureLabel);

        immatureLabelSpacer_3 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(immatureLabelSpacer_3);

        label_11 = new QLabel(globalHiveSummaryTextRow);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_11);

        potentialRewardsLabel = new QLabel(globalHiveSummaryTextRow);
        potentialRewardsLabel->setObjectName(QStringLiteral("potentialRewardsLabel"));

        horizontalLayout->addWidget(potentialRewardsLabel);

        immatureLabelSpacer_5 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(immatureLabelSpacer_5);

        label_16 = new QLabel(globalHiveSummaryTextRow);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_16->setOpenExternalLinks(true);

        horizontalLayout->addWidget(label_16);

        beePopIndexLabel = new QLabel(globalHiveSummaryTextRow);
        beePopIndexLabel->setObjectName(QStringLiteral("beePopIndexLabel"));

        horizontalLayout->addWidget(beePopIndexLabel);

        immatureLabelSpacer_6 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(immatureLabelSpacer_6);

        beePopIndexPie = new TinyPie(globalHiveSummaryTextRow);
        beePopIndexPie->setObjectName(QStringLiteral("beePopIndexPie"));
        sizePolicy2.setHeightForWidth(beePopIndexPie->sizePolicy().hasHeightForWidth());
        beePopIndexPie->setSizePolicy(sizePolicy2);
        beePopIndexPie->setMinimumSize(QSize(20, 20));

        horizontalLayout->addWidget(beePopIndexPie);

        horizontalSpacer_12 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);

        label_13 = new QLabel(globalHiveSummaryTextRow);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_13);

        blocksTillGlobalRefresh = new QLabel(globalHiveSummaryTextRow);
        blocksTillGlobalRefresh->setObjectName(QStringLiteral("blocksTillGlobalRefresh"));
        blocksTillGlobalRefresh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(blocksTillGlobalRefresh);

        label_15 = new QLabel(globalHiveSummaryTextRow);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_15);

        refreshGlobalSummaryButton = new QPushButton(globalHiveSummaryTextRow);
        refreshGlobalSummaryButton->setObjectName(QStringLiteral("refreshGlobalSummaryButton"));
        refreshGlobalSummaryButton->setMinimumSize(QSize(75, 0));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/refresh"), QSize(), QIcon::Normal, QIcon::Off);
        refreshGlobalSummaryButton->setIcon(icon3);

        horizontalLayout->addWidget(refreshGlobalSummaryButton);


        verticalLayout_2->addWidget(globalHiveSummaryTextRow);

        beePopGraph = new QCustomPlot(globalHiveSummary);
        beePopGraph->setObjectName(QStringLiteral("beePopGraph"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(beePopGraph->sizePolicy().hasHeightForWidth());
        beePopGraph->setSizePolicy(sizePolicy3);
        beePopGraph->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(beePopGraph);


        verticalLayout->addWidget(globalHiveSummary);

        globalHiveSummaryError = new QFrame(HiveDialog);
        globalHiveSummaryError->setObjectName(QStringLiteral("globalHiveSummaryError"));
        globalHiveSummaryError->setStyleSheet(QLatin1String("#globalHiveSummaryError {\n"
"background-color:white;\n"
"}"));
        globalHiveSummaryError->setFrameShape(QFrame::StyledPanel);
        globalHiveSummaryError->setFrameShadow(QFrame::Sunken);
        horizontalLayout_2 = new QHBoxLayout(globalHiveSummaryError);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        globalHiveSummaryErrorLabel = new QLabel(globalHiveSummaryError);
        globalHiveSummaryErrorLabel->setObjectName(QStringLiteral("globalHiveSummaryErrorLabel"));
        globalHiveSummaryErrorLabel->setFont(font1);
        globalHiveSummaryErrorLabel->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(globalHiveSummaryErrorLabel);

        retryGlobalSummaryButton = new QPushButton(globalHiveSummaryError);
        retryGlobalSummaryButton->setObjectName(QStringLiteral("retryGlobalSummaryButton"));
        retryGlobalSummaryButton->setMinimumSize(QSize(75, 0));

        horizontalLayout_2->addWidget(retryGlobalSummaryButton);

        horizontalSpacer_17 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_17);


        verticalLayout->addWidget(globalHiveSummaryError);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        walletHiveStatsFrame = new QFrame(HiveDialog);
        walletHiveStatsFrame->setObjectName(QStringLiteral("walletHiveStatsFrame"));
        walletHiveStatsFrame->setFrameShape(QFrame::StyledPanel);
        walletHiveStatsFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(walletHiveStatsFrame);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        yourHiveHeader = new QHBoxLayout();
        yourHiveHeader->setObjectName(QStringLiteral("yourHiveHeader"));
        label_8 = new QLabel(walletHiveStatsFrame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        yourHiveHeader->addWidget(label_8);

        horizontalSpacer_13 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        yourHiveHeader->addItem(horizontalSpacer_13);

        includeDeadBeesCheckbox = new QCheckBox(walletHiveStatsFrame);
        includeDeadBeesCheckbox->setObjectName(QStringLiteral("includeDeadBeesCheckbox"));
        sizePolicy2.setHeightForWidth(includeDeadBeesCheckbox->sizePolicy().hasHeightForWidth());
        includeDeadBeesCheckbox->setSizePolicy(sizePolicy2);
        includeDeadBeesCheckbox->setMaximumSize(QSize(1000, 16777215));
        includeDeadBeesCheckbox->setFocusPolicy(Qt::StrongFocus);
        includeDeadBeesCheckbox->setChecked(false);

        yourHiveHeader->addWidget(includeDeadBeesCheckbox);


        verticalLayout_4->addLayout(yourHiveHeader);

        currentHiveView = new QTableView(walletHiveStatsFrame);
        currentHiveView->setObjectName(QStringLiteral("currentHiveView"));
        currentHiveView->setMinimumSize(QSize(0, 0));
        currentHiveView->setContextMenuPolicy(Qt::CustomContextMenu);
        currentHiveView->setTabKeyNavigation(false);
        currentHiveView->setSortingEnabled(true);

        verticalLayout_4->addWidget(currentHiveView);

        yourHiveSummary = new QHBoxLayout();
        yourHiveSummary->setObjectName(QStringLiteral("yourHiveSummary"));
        label_14 = new QLabel(walletHiveStatsFrame);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        yourHiveSummary->addWidget(label_14);

        localHiveWeightLabel = new QLabel(walletHiveStatsFrame);
        localHiveWeightLabel->setObjectName(QStringLiteral("localHiveWeightLabel"));

        yourHiveSummary->addWidget(localHiveWeightLabel);

        hiveWeightPie = new TinyPie(walletHiveStatsFrame);
        hiveWeightPie->setObjectName(QStringLiteral("hiveWeightPie"));
        sizePolicy2.setHeightForWidth(hiveWeightPie->sizePolicy().hasHeightForWidth());
        hiveWeightPie->setSizePolicy(sizePolicy2);
        hiveWeightPie->setMinimumSize(QSize(20, 20));

        yourHiveSummary->addWidget(hiveWeightPie);

        immatureLabelSpacer_4 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        yourHiveSummary->addItem(immatureLabelSpacer_4);

        label = new QLabel(walletHiveStatsFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        yourHiveSummary->addWidget(label);

        immatureLabel = new QLabel(walletHiveStatsFrame);
        immatureLabel->setObjectName(QStringLiteral("immatureLabel"));

        yourHiveSummary->addWidget(immatureLabel);

        immatureLabelSpacer = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        yourHiveSummary->addItem(immatureLabelSpacer);

        label_3 = new QLabel(walletHiveStatsFrame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        yourHiveSummary->addWidget(label_3);

        matureLabel = new QLabel(walletHiveStatsFrame);
        matureLabel->setObjectName(QStringLiteral("matureLabel"));

        yourHiveSummary->addWidget(matureLabel);

        horizontalSpacer_16 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        yourHiveSummary->addItem(horizontalSpacer_16);

        deadTitleLabel = new QLabel(walletHiveStatsFrame);
        deadTitleLabel->setObjectName(QStringLiteral("deadTitleLabel"));
        deadTitleLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        yourHiveSummary->addWidget(deadTitleLabel);

        deadLabel = new QLabel(walletHiveStatsFrame);
        deadLabel->setObjectName(QStringLiteral("deadLabel"));

        yourHiveSummary->addWidget(deadLabel);

        horizontalSpacer_15 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        yourHiveSummary->addItem(horizontalSpacer_15);

        label_4 = new QLabel(walletHiveStatsFrame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        yourHiveSummary->addWidget(label_4);

        blocksFoundLabel = new QLabel(walletHiveStatsFrame);
        blocksFoundLabel->setObjectName(QStringLiteral("blocksFoundLabel"));

        yourHiveSummary->addWidget(blocksFoundLabel);

        deadLabelSpacer = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        yourHiveSummary->addItem(deadLabelSpacer);

        label_10 = new QLabel(walletHiveStatsFrame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        yourHiveSummary->addWidget(label_10);

        costLabel = new QLabel(walletHiveStatsFrame);
        costLabel->setObjectName(QStringLiteral("costLabel"));

        yourHiveSummary->addWidget(costLabel);

        horizontalSpacer_14 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        yourHiveSummary->addItem(horizontalSpacer_14);

        label_5 = new QLabel(walletHiveStatsFrame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        yourHiveSummary->addWidget(label_5);

        rewardsPaidLabel = new QLabel(walletHiveStatsFrame);
        rewardsPaidLabel->setObjectName(QStringLiteral("rewardsPaidLabel"));

        yourHiveSummary->addWidget(rewardsPaidLabel);

        horizontalSpacer_19 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        yourHiveSummary->addItem(horizontalSpacer_19);

        label_7 = new QLabel(walletHiveStatsFrame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        yourHiveSummary->addWidget(label_7);

        profitLabel = new QLabel(walletHiveStatsFrame);
        profitLabel->setObjectName(QStringLiteral("profitLabel"));

        yourHiveSummary->addWidget(profitLabel);

        horizontalSpacer_11 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        yourHiveSummary->addItem(horizontalSpacer_11);


        verticalLayout_4->addLayout(yourHiveSummary);


        verticalLayout->addWidget(walletHiveStatsFrame);


        retranslateUi(HiveDialog);

        QMetaObject::connectSlotsByName(HiveDialog);
    } // setupUi

    void retranslateUi(QWidget *HiveDialog)
    {
        createBeesTitleLabel->setText(QApplication::translate("HiveDialog", "Create Bees", Q_NULLPTR));
        warningLabel->setText(QString());
        warningLabel2->setText(QApplication::translate("HiveDialog", "<span style=\"color:#ff0000;\">Please <a href=\"https://hive.litecoinca.sh/guide/\"><span style=\"text-decoration: underline;\">learn about The Hive</span></a> before creating bees</span>", Q_NULLPTR));
        currentBeeCostLabel_2->setText(QApplication::translate("HiveDialog", "Current bee cost:", Q_NULLPTR));
        currentBeeCostLabel_21->setText(QApplication::translate("HiveDialog", "Available balance:", Q_NULLPTR));
        currentBalance->setText(QApplication::translate("HiveDialog", "0 OBD", Q_NULLPTR));
        beesToCreateLabel_2->setText(QApplication::translate("HiveDialog", "Bees to create:", Q_NULLPTR));
        totalCostLabel_3->setText(QApplication::translate("HiveDialog", "Total cost:", Q_NULLPTR));
        totalCostLabel->setText(QApplication::translate("HiveDialog", "0 OBD", Q_NULLPTR));
        label_9->setText(QApplication::translate("HiveDialog", "+ network transaction fee", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        createBeesButton->setToolTip(QApplication::translate("HiveDialog", "Create bees now. You will be shown a confirmation dialogue including final transaction fees.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        createBeesButton->setText(QApplication::translate("HiveDialog", "Create bees", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        releaseSwarmButton->setToolTip(QApplication::translate("HiveDialog", "Click to unlock your wallet for Hive Mining and Rialto messaging. Note that this doesn't unlock the wallet for transactions; you must\n"
"still fully unlock it to send funds.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        releaseSwarmButton->setText(QApplication::translate("HiveDialog", "WALLET IS LOCKED: Unlock for Rialto and Hive", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        showHiveOptionsButton->setToolTip(QApplication::translate("HiveDialog", "Open the Options dialogue to edit Hive mining settings.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        showHiveOptionsButton->setText(QApplication::translate("HiveDialog", "Hive mining options", Q_NULLPTR));
        beeCostLabel->setText(QApplication::translate("HiveDialog", "0 OBD", Q_NULLPTR));
        globalNetworkHiveTitleLabel->setText(QApplication::translate("HiveDialog", "Global Network Hive", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        showAdvancedStatsCheckbox->setToolTip(QApplication::translate("HiveDialog", "If ticked, advanced global network hive stats will be displayed", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        showAdvancedStatsCheckbox->setText(QApplication::translate("HiveDialog", "Show bee population graph", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("HiveDialog", "The total number of immature bees across the whole network", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("HiveDialog", "Immature bees: ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        globalImmatureLabel->setToolTip(QApplication::translate("HiveDialog", "The total number of immature bees across the whole network", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        globalImmatureLabel->setText(QApplication::translate("HiveDialog", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_12->setToolTip(QApplication::translate("HiveDialog", "The total number of mature bees across the whole network", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("HiveDialog", "Mature bees: ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        globalMatureLabel->setToolTip(QApplication::translate("HiveDialog", "The total number of mature bees across the whole network", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        globalMatureLabel->setText(QApplication::translate("HiveDialog", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_11->setToolTip(QApplication::translate("HiveDialog", "The total block rewards available on the network over the lifespan of a single bee", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_11->setText(QApplication::translate("HiveDialog", "Honey pot: ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        potentialRewardsLabel->setToolTip(QApplication::translate("HiveDialog", "The total block rewards available on the network over the lifespan of a single bee", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        potentialRewardsLabel->setText(QApplication::translate("HiveDialog", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_16->setToolTip(QApplication::translate("HiveDialog", "The Global Index is a measure of network bee population. At a value of 100,\n"
"the network is saturated with the maximum number of bees that are expected\n"
"to make back their cost. At values below 100, it is expected at all bees will be profitable.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_16->setText(QApplication::translate("HiveDialog", "<a href=\"https://hive.litecoinca.sh/gi/\"><span style=\"text-decoration: underline;\">Global index</span></a>: ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        beePopIndexLabel->setToolTip(QApplication::translate("HiveDialog", "The Global Index is a measure of network bee population. At a value of 100,\n"
"the network is saturated with the maximum number of bees that are expected\n"
"to make back their cost. At values below 100, it is expected at all bees will be profitable.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        beePopIndexLabel->setText(QApplication::translate("HiveDialog", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        beePopIndexPie->setToolTip(QApplication::translate("HiveDialog", "The Global Index is a measure of network bee population. At a value of 100,\n"
"the network is saturated with the maximum number of bees that are expected\n"
"to make back their cost. At values below 100, it is expected at all bees will be profitable.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_13->setToolTip(QApplication::translate("HiveDialog", "Global network hive stats are automatically refreshed every 10 blocks", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_13->setText(QApplication::translate("HiveDialog", "(Stats refresh: ", Q_NULLPTR));
        blocksTillGlobalRefresh->setText(QApplication::translate("HiveDialog", "10", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_15->setToolTip(QApplication::translate("HiveDialog", "Global network hive stats are automatically refreshed every 10 blocks", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_15->setText(QApplication::translate("HiveDialog", " blocks) ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        refreshGlobalSummaryButton->setToolTip(QApplication::translate("HiveDialog", "Refresh global hive stats now", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        refreshGlobalSummaryButton->setText(QApplication::translate("HiveDialog", "Refresh", Q_NULLPTR));
        globalHiveSummaryErrorLabel->setText(QApplication::translate("HiveDialog", "Network hive summary not yet generated.", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        retryGlobalSummaryButton->setToolTip(QApplication::translate("HiveDialog", "Attempt to generate global network hive stats now", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        retryGlobalSummaryButton->setText(QApplication::translate("HiveDialog", "Generate Now", Q_NULLPTR));
        label_8->setText(QApplication::translate("HiveDialog", "Your Hive", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        includeDeadBeesCheckbox->setToolTip(QApplication::translate("HiveDialog", "If ticked, your hive display and summary will include bees that have expired as well as bees that are currently living.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        includeDeadBeesCheckbox->setText(QApplication::translate("HiveDialog", "Include expired bees", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_14->setToolTip(QApplication::translate("HiveDialog", "Hive Weight = is your hive population / global hive population. \n"
"This represents how much of the global hive you control as well as\n"
"your hive's chance of mining any given hivemineable block.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_14->setText(QApplication::translate("HiveDialog", "Hive weight:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        localHiveWeightLabel->setToolTip(QApplication::translate("HiveDialog", "Hive Weight = is your hive population / global hive population. \n"
"This represents how much of the global hive you control as well as\n"
"your hive's chance of mining any given hivemineable block.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        localHiveWeightLabel->setText(QApplication::translate("HiveDialog", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        hiveWeightPie->setToolTip(QApplication::translate("HiveDialog", "Hive Weight = is your hive population / global hive population. \n"
"This represents how much of the global hive you control as well as\n"
"your hive's chance of mining any given hivemineable block.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("HiveDialog", "Current number of immature bees in your hive", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("HiveDialog", "Immature:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        immatureLabel->setToolTip(QApplication::translate("HiveDialog", "Current number of immature bees in your hive", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        immatureLabel->setText(QApplication::translate("HiveDialog", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("HiveDialog", "Current number of mature bees in your hive", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("HiveDialog", "Mature:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        matureLabel->setToolTip(QApplication::translate("HiveDialog", "Current number of mature bees in your hive", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        matureLabel->setText(QApplication::translate("HiveDialog", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        deadTitleLabel->setToolTip(QApplication::translate("HiveDialog", "Current number of expired bees in your hive", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        deadTitleLabel->setText(QApplication::translate("HiveDialog", "Expired:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        deadLabel->setToolTip(QApplication::translate("HiveDialog", "Current number of expired bees in your hive", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        deadLabel->setText(QApplication::translate("HiveDialog", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("HiveDialog", "The number of blocks hivemined by your bees", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("HiveDialog", "Blocks found:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        blocksFoundLabel->setToolTip(QApplication::translate("HiveDialog", "The number of blocks hivemined by your bees", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        blocksFoundLabel->setText(QApplication::translate("HiveDialog", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_10->setToolTip(QApplication::translate("HiveDialog", "Total bee cost of your hive", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_10->setText(QApplication::translate("HiveDialog", "Cost:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        costLabel->setToolTip(QApplication::translate("HiveDialog", "Total bee cost of your hive", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        costLabel->setText(QApplication::translate("HiveDialog", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("HiveDialog", "Total block rewards earned by your bees", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("HiveDialog", "Rewards:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        rewardsPaidLabel->setToolTip(QApplication::translate("HiveDialog", "Total block rewards earned by your bees", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        rewardsPaidLabel->setText(QApplication::translate("HiveDialog", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("HiveDialog", "Total profit made by your bees", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("HiveDialog", "Profit:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        profitLabel->setToolTip(QApplication::translate("HiveDialog", "Total profit made by your bees", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        profitLabel->setText(QApplication::translate("HiveDialog", "0", Q_NULLPTR));
        Q_UNUSED(HiveDialog);
    } // retranslateUi

};

namespace Ui {
    class HiveDialog: public Ui_HiveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIVEDIALOG_H
