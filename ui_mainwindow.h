/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <lcombobox.h>
#include <llistwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QWidget *tileWidget;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *closePushButton;
    QLabel *label_8;
    QPushButton *minPushButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *maxPushButton;
    QSplitter *splitter_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget_Main;
    QWidget *tab;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QFrame *line_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    LComboBox *comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *baudRateLabel;
    QComboBox *baudRateBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *parityBitsLabel;
    QComboBox *parityBitsBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *stopBitLabel;
    QComboBox *stopBitBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *dataBitsLabel;
    QComboBox *dataBitsBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *timeDispLabel;
    QComboBox *timeDispBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *timerLabel;
    QSpinBox *timerSpinBox;
    QWidget *tab_3;
    QGridLayout *gridLayout_7;
    LListWidget *widget_2;
    QSplitter *splitter_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QTextEdit *showTextEdit;
    QTextEdit *sendTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *hexSendPushButton;
    QFrame *line_10;
    QPushButton *fileSendPushButton;
    QFrame *line;
    QPushButton *clearSendPushButton;
    QFrame *line_9;
    QLineEdit *SendTimerLineEdit;
    QFrame *line_8;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *sendPushButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *hexShowPushButton;
    QFrame *line_3;
    QPushButton *timeShowPushButton;
    QPushButton *rxShowPushButton;
    QPushButton *txShowPushButton;
    QFrame *line_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *clearShowPushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setSizeIncrement(QSize(0, 0));
        MainWindow->setBaseSize(QSize(0, 0));
        MainWindow->setMouseTracking(true);
        MainWindow->setTabletTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/check/locm.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMouseTracking(true);
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(10);
        gridLayout_4->setVerticalSpacing(0);
        gridLayout_4->setContentsMargins(10, 10, 10, 10);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        tileWidget = new QWidget(centralwidget);
        tileWidget->setObjectName(QString::fromUtf8("tileWidget"));
        tileWidget->setMinimumSize(QSize(0, 40));
        tileWidget->setMaximumSize(QSize(16777215, 40));
        tileWidget->setMouseTracking(false);
        tileWidget->setTabletTracking(false);
        tileWidget->setToolTipDuration(0);
        gridLayout_6 = new QGridLayout(tileWidget);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_6->setContentsMargins(0, 0, 0, 1);
        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_6, 0, 5, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 0, 7, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 0, 9, 1, 1);

        closePushButton = new QPushButton(tileWidget);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setMinimumSize(QSize(40, 40));
        closePushButton->setMaximumSize(QSize(40, 40));
        closePushButton->setMouseTracking(false);
        closePushButton->setTabletTracking(false);
        closePushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:none"));
        closePushButton->setCheckable(false);

        gridLayout_6->addWidget(closePushButton, 0, 8, 1, 1);

        label_8 = new QLabel(tileWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(80, 0));
        label_8->setMouseTracking(false);
        label_8->setTabletTracking(false);
        label_8->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Microsoft YaHei UI\";\n"
"color:rgb(253, 127, 151);"));
        label_8->setLineWidth(0);
        label_8->setIndent(0);

        gridLayout_6->addWidget(label_8, 0, 2, 1, 1);

        minPushButton = new QPushButton(tileWidget);
        minPushButton->setObjectName(QString::fromUtf8("minPushButton"));
        minPushButton->setMinimumSize(QSize(40, 40));
        minPushButton->setMaximumSize(QSize(40, 40));
        minPushButton->setMouseTracking(false);
        minPushButton->setTabletTracking(false);
        minPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:none"));

        gridLayout_6->addWidget(minPushButton, 0, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(1, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        maxPushButton = new QPushButton(tileWidget);
        maxPushButton->setObjectName(QString::fromUtf8("maxPushButton"));
        maxPushButton->setMinimumSize(QSize(40, 40));
        maxPushButton->setMaximumSize(QSize(40, 40));
        maxPushButton->setMouseTracking(false);
        maxPushButton->setTabletTracking(false);
        maxPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:none"));
        maxPushButton->setAutoExclusive(false);

        gridLayout_6->addWidget(maxPushButton, 0, 6, 1, 1);


        gridLayout_2->addWidget(tileWidget, 0, 0, 1, 1);

        splitter_4 = new QSplitter(centralwidget);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setMinimumSize(QSize(50, 0));
        splitter_4->setMouseTracking(false);
        splitter_4->setTabletTracking(false);
        splitter_4->setStyleSheet(QString::fromUtf8("\n"
"QPushButton\n"
"{\n"
"    background-color:rgb(255,255,255);//\350\203\214\346\231\257\350\211\262\357\274\210\344\271\237\345\217\257\344\273\245\350\256\276\347\275\256\345\233\276\347\211\207\357\274\211\n"
"    border-radius:10px;                   //\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240\n"
"    font:20px \"Segoe UI Black\";                      //\345\255\227\344\275\223\357\274\214\345\255\227\344\275\223\345\244\247\345\260\217\n"
"    font: 900 9pt \"Segoe UI Black\";\n"
"    color:rgb(120, 120, 120);                //\345\255\227\344\275\223\351\242\234\350\211\262\n"
"}\n"
"//\351\274\240\346\240\207\346\214\211\344\270\213\346\240\267\345\274\217\n"
"QPushButton:checked\n"
"{\n"
"    background-color:rgb(255,255,255);//\350\203\214\346\231\257\350\211\262\357\274\210\344\271\237\345\217\257\344\273\245\350\256\276\347\275\256\345\233\276\347\211\207\357\274\211\n"
"    border-radius:10px;                   //\350\276\271\346\241\206\345"
                        "\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240\n"
"    font:20px \"Segoe UI Black\";                       //\345\255\227\344\275\223\357\274\214\345\255\227\344\275\223\345\244\247\345\260\217\n"
"    color:rgb(253, 127, 151);                //\345\255\227\344\275\223\351\242\234\350\211\262\n"
"}\n"
"//\351\274\240\346\240\207\346\202\254\345\201\234\346\240\267\345\274\217\n"
"QPushButton:hover\n"
"{\n"
"    border-style:outset;                //\350\276\271\346\241\206\346\240\267\345\274\217\357\274\210inset/outset\357\274\211\n"
"    border-radius:1px;                  //\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240\n"
"    border-color:rgb(253, 127, 151);    //\350\276\271\346\241\206\351\242\234\350\211\262\n"
"    background-color:rgb(255,255,255);\n"
"    font:23px \"Segoe UI Black\";                      //\345\255\227\344\275\223\357\274\214\345\255\227\344\275\223\345\244\247\345\260\217\n"
"    color:rgb(253, 127, 151);\n"
""
                        "}\n"
"QPushButton#pushPushButton\n"
"{\n"
"    background-color:rgb(255,255,255);//\350\203\214\346\231\257\350\211\262\357\274\210\344\271\237\345\217\257\344\273\245\350\256\276\347\275\256\345\233\276\347\211\207\357\274\211\n"
"    border-radius:10px;                   //\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240\n"
"    font:20px \"Segoe UI Black\";                      //\345\255\227\344\275\223\357\274\214\345\255\227\344\275\223\345\244\247\345\260\217\n"
"    image: url(:/image/check/open.png);\n"
"    color:rgb(120, 120, 120);                //\345\255\227\344\275\223\351\242\234\350\211\262\n"
"}\n"
"//\351\274\240\346\240\207\346\214\211\344\270\213\346\240\267\345\274\217\n"
"QPushButton#pushPushButton:checked\n"
"{\n"
"    background-color:rgb(255,255,255);//\350\203\214\346\231\257\350\211\262\357\274\210\344\271\237\345\217\257\344\273\245\350\256\276\347\275\256\345\233\276\347\211\207\357\274\211\n"
"    border-radius:10px;                "
                        "   //\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240\n"
"    font:20px \"Segoe UI Black\";                      //\345\255\227\344\275\223\357\274\214\345\255\227\344\275\223\345\244\247\345\260\217\n"
"    color:rgb(253, 127, 151);                //\345\255\227\344\275\223\351\242\234\350\211\262\n"
"}\n"
"//\351\274\240\346\240\207\346\202\254\345\201\234\346\240\267\345\274\217\n"
"QPushButton#pushPushButton:hover\n"
"{\n"
"    border-style:outset;                //\350\276\271\346\241\206\346\240\267\345\274\217\357\274\210inset/outset\357\274\211\n"
"    border-radius:1px;                  //\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\345\203\217\347\264\240\n"
"    border-color:rgb(253, 127, 151);    //\350\276\271\346\241\206\351\242\234\350\211\262\n"
"    background-color:rgb(255,255,255);\n"
"    image: url(:/image/noCheck/open.png);\n"
"    font:23px \"Segoe UI Black\";                      //\345\255\227\344\275\223\357\274"
                        "\214\345\255\227\344\275\223\345\244\247\345\260\217\n"
"    color:rgb(253, 127, 151);\n"
"}"));
        splitter_4->setLineWidth(0);
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_4->setHandleWidth(0);
        splitter_4->setChildrenCollapsible(false);
        groupBox_3 = new QGroupBox(splitter_4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(3);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(50, 0));
        groupBox_3->setMouseTracking(false);
        groupBox_3->setTabletTracking(false);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout_3->setContentsMargins(5, 0, 0, 0);
        tabWidget_Main = new QTabWidget(groupBox_3);
        tabWidget_Main->setObjectName(QString::fromUtf8("tabWidget_Main"));
        tabWidget_Main->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget_Main->sizePolicy().hasHeightForWidth());
        tabWidget_Main->setSizePolicy(sizePolicy1);
        tabWidget_Main->setMinimumSize(QSize(50, 0));
        tabWidget_Main->setMaximumSize(QSize(16777215, 16777215));
        tabWidget_Main->setMouseTracking(false);
        tabWidget_Main->setTabletTracking(false);
        tabWidget_Main->setFocusPolicy(Qt::NoFocus);
        tabWidget_Main->setContextMenuPolicy(Qt::NoContextMenu);
        tabWidget_Main->setLayoutDirection(Qt::LeftToRight);
        tabWidget_Main->setStyleSheet(QString::fromUtf8(""));
        tabWidget_Main->setTabPosition(QTabWidget::West);
        tabWidget_Main->setTabShape(QTabWidget::Rounded);
        tabWidget_Main->setIconSize(QSize(35, 35));
        tabWidget_Main->setElideMode(Qt::ElideNone);
        tabWidget_Main->setUsesScrollButtons(false);
        tabWidget_Main->setDocumentMode(false);
        tabWidget_Main->setTabsClosable(false);
        tabWidget_Main->setMovable(false);
        tabWidget_Main->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setMinimumSize(QSize(50, 0));
        tabWidget_Main->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(16777215, 30));
        label_7->setMouseTracking(false);
        label_7->setTabletTracking(false);
        label_7->setStyleSheet(QString::fromUtf8("font: 9pt \"Microsoft YaHei UI\";\n"
"color:rgb(253, 127, 151);"));

        verticalLayout->addWidget(label_7);

        line_5 = new QFrame(tab_2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setMaximumSize(QSize(16777215, 5));
        line_5->setMouseTracking(false);
        line_5->setTabletTracking(false);
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        verticalSpacer = new QSpacerItem(0, 1, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMouseTracking(false);
        label->setTabletTracking(false);

        horizontalLayout_3->addWidget(label);

        comboBox = new LComboBox(tab_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMouseTracking(false);
        comboBox->setTabletTracking(false);

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        baudRateLabel = new QLabel(tab_2);
        baudRateLabel->setObjectName(QString::fromUtf8("baudRateLabel"));
        baudRateLabel->setMouseTracking(false);
        baudRateLabel->setTabletTracking(false);

        horizontalLayout_4->addWidget(baudRateLabel);

        baudRateBox = new QComboBox(tab_2);
        baudRateBox->addItem(QString());
        baudRateBox->addItem(QString());
        baudRateBox->addItem(QString());
        baudRateBox->addItem(QString());
        baudRateBox->addItem(QString());
        baudRateBox->addItem(QString());
        baudRateBox->addItem(QString());
        baudRateBox->addItem(QString());
        baudRateBox->setObjectName(QString::fromUtf8("baudRateBox"));
        baudRateBox->setMinimumSize(QSize(0, 0));
        baudRateBox->setMaximumSize(QSize(16777215, 16777215));
        baudRateBox->setSizeIncrement(QSize(0, 0));
        baudRateBox->setBaseSize(QSize(0, 0));
        baudRateBox->setMouseTracking(false);
        baudRateBox->setTabletTracking(false);

        horizontalLayout_4->addWidget(baudRateBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        parityBitsLabel = new QLabel(tab_2);
        parityBitsLabel->setObjectName(QString::fromUtf8("parityBitsLabel"));
        parityBitsLabel->setMouseTracking(false);
        parityBitsLabel->setTabletTracking(false);

        horizontalLayout_5->addWidget(parityBitsLabel);

        parityBitsBox = new QComboBox(tab_2);
        parityBitsBox->addItem(QString());
        parityBitsBox->addItem(QString());
        parityBitsBox->addItem(QString());
        parityBitsBox->addItem(QString());
        parityBitsBox->addItem(QString());
        parityBitsBox->setObjectName(QString::fromUtf8("parityBitsBox"));
        parityBitsBox->setMouseTracking(false);
        parityBitsBox->setTabletTracking(false);

        horizontalLayout_5->addWidget(parityBitsBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        stopBitLabel = new QLabel(tab_2);
        stopBitLabel->setObjectName(QString::fromUtf8("stopBitLabel"));
        stopBitLabel->setMouseTracking(false);
        stopBitLabel->setTabletTracking(false);

        horizontalLayout_6->addWidget(stopBitLabel);

        stopBitBox = new QComboBox(tab_2);
        stopBitBox->addItem(QString());
        stopBitBox->addItem(QString());
        stopBitBox->addItem(QString());
        stopBitBox->setObjectName(QString::fromUtf8("stopBitBox"));
        stopBitBox->setMouseTracking(false);
        stopBitBox->setTabletTracking(false);

        horizontalLayout_6->addWidget(stopBitBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        dataBitsLabel = new QLabel(tab_2);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));
        dataBitsLabel->setMouseTracking(false);
        dataBitsLabel->setTabletTracking(false);

        horizontalLayout_7->addWidget(dataBitsLabel);

        dataBitsBox = new QComboBox(tab_2);
        dataBitsBox->addItem(QString());
        dataBitsBox->addItem(QString());
        dataBitsBox->addItem(QString());
        dataBitsBox->addItem(QString());
        dataBitsBox->setObjectName(QString::fromUtf8("dataBitsBox"));
        dataBitsBox->setMouseTracking(false);
        dataBitsBox->setTabletTracking(false);

        horizontalLayout_7->addWidget(dataBitsBox);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        timeDispLabel = new QLabel(tab_2);
        timeDispLabel->setObjectName(QString::fromUtf8("timeDispLabel"));
        timeDispLabel->setMouseTracking(false);
        timeDispLabel->setTabletTracking(false);

        horizontalLayout_8->addWidget(timeDispLabel);

        timeDispBox = new QComboBox(tab_2);
        timeDispBox->addItem(QString());
        timeDispBox->addItem(QString());
        timeDispBox->setObjectName(QString::fromUtf8("timeDispBox"));
        timeDispBox->setMouseTracking(false);
        timeDispBox->setTabletTracking(false);

        horizontalLayout_8->addWidget(timeDispBox);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        timerLabel = new QLabel(tab_2);
        timerLabel->setObjectName(QString::fromUtf8("timerLabel"));
        timerLabel->setMouseTracking(false);
        timerLabel->setTabletTracking(false);

        horizontalLayout_9->addWidget(timerLabel);

        timerSpinBox = new QSpinBox(tab_2);
        timerSpinBox->setObjectName(QString::fromUtf8("timerSpinBox"));
        timerSpinBox->setMouseTracking(false);
        timerSpinBox->setTabletTracking(false);
        timerSpinBox->setMinimum(20);
        timerSpinBox->setMaximum(2000);
        timerSpinBox->setSingleStep(10);

        horizontalLayout_9->addWidget(timerSpinBox);


        verticalLayout->addLayout(horizontalLayout_9);

        tabWidget_Main->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_7 = new QGridLayout(tab_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        widget_2 = new LListWidget(tab_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        gridLayout_7->addWidget(widget_2, 0, 0, 1, 1);

        tabWidget_Main->addTab(tab_3, QString());

        gridLayout_3->addWidget(tabWidget_Main, 0, 1, 1, 1);

        splitter_4->addWidget(groupBox_3);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(splitter_3->sizePolicy().hasHeightForWidth());
        splitter_3->setSizePolicy(sizePolicy2);
        splitter_3->setMouseTracking(false);
        splitter_3->setTabletTracking(false);
        splitter_3->setLineWidth(0);
        splitter_3->setOrientation(Qt::Vertical);
        splitter_3->setOpaqueResize(true);
        splitter_3->setHandleWidth(0);
        splitter_3->setChildrenCollapsible(true);
        groupBox = new QGroupBox(splitter_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(30, 30));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        groupBox->setMouseTracking(false);
        groupBox->setTabletTracking(false);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, 0, 0);
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(3);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy3);
        splitter->setMouseTracking(false);
        splitter->setTabletTracking(false);
        splitter->setLineWidth(0);
        splitter->setOrientation(Qt::Vertical);
        splitter->setHandleWidth(0);
        splitter->setChildrenCollapsible(false);
        showTextEdit = new QTextEdit(splitter);
        showTextEdit->setObjectName(QString::fromUtf8("showTextEdit"));
        showTextEdit->setMinimumSize(QSize(0, 0));
        showTextEdit->setMouseTracking(false);
        showTextEdit->setTabletTracking(false);
        splitter->addWidget(showTextEdit);
        sendTextEdit = new QTextEdit(splitter);
        sendTextEdit->setObjectName(QString::fromUtf8("sendTextEdit"));
        sendTextEdit->setMinimumSize(QSize(0, 0));
        sendTextEdit->setMouseTracking(false);
        sendTextEdit->setTabletTracking(false);
        sendTextEdit->setLayoutDirection(Qt::LeftToRight);
        splitter->addWidget(sendTextEdit);

        gridLayout->addWidget(splitter, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hexSendPushButton = new QPushButton(groupBox);
        hexSendPushButton->setObjectName(QString::fromUtf8("hexSendPushButton"));
        hexSendPushButton->setMinimumSize(QSize(50, 50));
        hexSendPushButton->setMaximumSize(QSize(50, 50));
        hexSendPushButton->setMouseTracking(false);
        hexSendPushButton->setTabletTracking(false);
        hexSendPushButton->setCheckable(true);
        hexSendPushButton->setChecked(false);

        horizontalLayout->addWidget(hexSendPushButton);

        line_10 = new QFrame(groupBox);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setMinimumSize(QSize(20, 20));
        line_10->setMaximumSize(QSize(20, 20));
        line_10->setMouseTracking(false);
        line_10->setTabletTracking(false);
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_10);

        fileSendPushButton = new QPushButton(groupBox);
        fileSendPushButton->setObjectName(QString::fromUtf8("fileSendPushButton"));
        fileSendPushButton->setMinimumSize(QSize(50, 50));
        fileSendPushButton->setMaximumSize(QSize(50, 50));
        fileSendPushButton->setMouseTracking(false);
        fileSendPushButton->setTabletTracking(false);
        fileSendPushButton->setCheckable(false);

        horizontalLayout->addWidget(fileSendPushButton);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(20, 20));
        line->setMaximumSize(QSize(20, 20));
        line->setMouseTracking(false);
        line->setTabletTracking(false);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        clearSendPushButton = new QPushButton(groupBox);
        clearSendPushButton->setObjectName(QString::fromUtf8("clearSendPushButton"));
        clearSendPushButton->setMinimumSize(QSize(50, 50));
        clearSendPushButton->setMaximumSize(QSize(50, 50));
        clearSendPushButton->setMouseTracking(false);
        clearSendPushButton->setTabletTracking(false);

        horizontalLayout->addWidget(clearSendPushButton);

        line_9 = new QFrame(groupBox);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setMinimumSize(QSize(20, 20));
        line_9->setMaximumSize(QSize(20, 20));
        line_9->setMouseTracking(false);
        line_9->setTabletTracking(false);
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_9);

        SendTimerLineEdit = new QLineEdit(groupBox);
        SendTimerLineEdit->setObjectName(QString::fromUtf8("SendTimerLineEdit"));
        SendTimerLineEdit->setMinimumSize(QSize(0, 50));
        SendTimerLineEdit->setMaximumSize(QSize(80, 50));
        SendTimerLineEdit->setMouseTracking(false);
        SendTimerLineEdit->setTabletTracking(false);
        SendTimerLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:none"));

        horizontalLayout->addWidget(SendTimerLineEdit);

        line_8 = new QFrame(groupBox);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setMinimumSize(QSize(20, 20));
        line_8->setMaximumSize(QSize(20, 20));
        line_8->setMouseTracking(false);
        line_8->setTabletTracking(false);
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_8);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        sendPushButton = new QToolButton(groupBox);
        sendPushButton->setObjectName(QString::fromUtf8("sendPushButton"));
        sendPushButton->setMinimumSize(QSize(80, 40));
        sendPushButton->setMaximumSize(QSize(150, 50));
        sendPushButton->setMouseTracking(false);
        sendPushButton->setTabletTracking(false);
        sendPushButton->setPopupMode(QToolButton::MenuButtonPopup);
        sendPushButton->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout->addWidget(sendPushButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        hexShowPushButton = new QPushButton(groupBox);
        hexShowPushButton->setObjectName(QString::fromUtf8("hexShowPushButton"));
        hexShowPushButton->setMinimumSize(QSize(50, 50));
        hexShowPushButton->setMaximumSize(QSize(50, 50));
        hexShowPushButton->setMouseTracking(false);
        hexShowPushButton->setTabletTracking(false);
        hexShowPushButton->setCheckable(true);
        hexShowPushButton->setChecked(false);

        horizontalLayout_2->addWidget(hexShowPushButton);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMinimumSize(QSize(20, 20));
        line_3->setMaximumSize(QSize(20, 20));
        line_3->setMouseTracking(false);
        line_3->setTabletTracking(false);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_3);

        timeShowPushButton = new QPushButton(groupBox);
        timeShowPushButton->setObjectName(QString::fromUtf8("timeShowPushButton"));
        timeShowPushButton->setMinimumSize(QSize(50, 50));
        timeShowPushButton->setMaximumSize(QSize(50, 50));
        timeShowPushButton->setMouseTracking(false);
        timeShowPushButton->setTabletTracking(false);
        timeShowPushButton->setCheckable(true);
        timeShowPushButton->setChecked(true);

        horizontalLayout_2->addWidget(timeShowPushButton);

        rxShowPushButton = new QPushButton(groupBox);
        rxShowPushButton->setObjectName(QString::fromUtf8("rxShowPushButton"));
        rxShowPushButton->setMinimumSize(QSize(50, 50));
        rxShowPushButton->setMaximumSize(QSize(50, 50));
        rxShowPushButton->setMouseTracking(false);
        rxShowPushButton->setTabletTracking(false);
        rxShowPushButton->setCheckable(true);
        rxShowPushButton->setChecked(true);

        horizontalLayout_2->addWidget(rxShowPushButton);

        txShowPushButton = new QPushButton(groupBox);
        txShowPushButton->setObjectName(QString::fromUtf8("txShowPushButton"));
        txShowPushButton->setMinimumSize(QSize(50, 50));
        txShowPushButton->setMaximumSize(QSize(50, 50));
        txShowPushButton->setMouseTracking(false);
        txShowPushButton->setTabletTracking(false);
        txShowPushButton->setCheckable(true);
        txShowPushButton->setChecked(true);

        horizontalLayout_2->addWidget(txShowPushButton);

        line_6 = new QFrame(groupBox);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setMinimumSize(QSize(20, 20));
        line_6->setMaximumSize(QSize(20, 20));
        line_6->setMouseTracking(false);
        line_6->setTabletTracking(false);
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        clearShowPushButton = new QPushButton(groupBox);
        clearShowPushButton->setObjectName(QString::fromUtf8("clearShowPushButton"));
        clearShowPushButton->setMinimumSize(QSize(50, 50));
        clearShowPushButton->setMaximumSize(QSize(50, 50));
        clearShowPushButton->setMouseTracking(false);
        clearShowPushButton->setTabletTracking(false);

        horizontalLayout_2->addWidget(clearShowPushButton);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        splitter_3->addWidget(groupBox);
        splitter_4->addWidget(splitter_3);

        gridLayout_2->addWidget(splitter_4, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(closePushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(clearSendPushButton, SIGNAL(clicked()), sendTextEdit, SLOT(clear()));
        QObject::connect(clearShowPushButton, SIGNAL(clicked()), showTextEdit, SLOT(clear()));
        QObject::connect(maxPushButton, SIGNAL(clicked()), MainWindow, SLOT(showMinimized()));
        QObject::connect(minPushButton, SIGNAL(clicked()), MainWindow, SLOT(showMinimized()));

        tabWidget_Main->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        closePushButton->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "   LCOM 1.0", nullptr));
        minPushButton->setText(QString());
        maxPushButton->setText(QString());
        groupBox_3->setTitle(QString());
        tabWidget_Main->setTabText(tabWidget_Main->indexOf(tab), QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267", nullptr));
        baudRateLabel->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        baudRateBox->setItemText(0, QCoreApplication::translate("MainWindow", "115200", nullptr));
        baudRateBox->setItemText(1, QCoreApplication::translate("MainWindow", "1200", nullptr));
        baudRateBox->setItemText(2, QCoreApplication::translate("MainWindow", "2400", nullptr));
        baudRateBox->setItemText(3, QCoreApplication::translate("MainWindow", "4800", nullptr));
        baudRateBox->setItemText(4, QCoreApplication::translate("MainWindow", "9600", nullptr));
        baudRateBox->setItemText(5, QCoreApplication::translate("MainWindow", "19200", nullptr));
        baudRateBox->setItemText(6, QCoreApplication::translate("MainWindow", "57600", nullptr));
        baudRateBox->setItemText(7, QCoreApplication::translate("MainWindow", "38400", nullptr));

        parityBitsLabel->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        parityBitsBox->setItemText(0, QCoreApplication::translate("MainWindow", "NoParity", nullptr));
        parityBitsBox->setItemText(1, QCoreApplication::translate("MainWindow", "EvenParity", nullptr));
        parityBitsBox->setItemText(2, QCoreApplication::translate("MainWindow", "OddParity", nullptr));
        parityBitsBox->setItemText(3, QCoreApplication::translate("MainWindow", "SpaceParity", nullptr));
        parityBitsBox->setItemText(4, QCoreApplication::translate("MainWindow", "MarkParity", nullptr));

        stopBitLabel->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        stopBitBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        stopBitBox->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        stopBitBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        dataBitsLabel->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        dataBitsBox->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));
        dataBitsBox->setItemText(1, QCoreApplication::translate("MainWindow", "5", nullptr));
        dataBitsBox->setItemText(2, QCoreApplication::translate("MainWindow", "6", nullptr));
        dataBitsBox->setItemText(3, QCoreApplication::translate("MainWindow", "7", nullptr));

        timeDispLabel->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\210\263", nullptr));
        timeDispBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        timeDispBox->setItemText(1, QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));

        timerLabel->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\345\273\266\346\227\266", nullptr));
        tabWidget_Main->setTabText(tabWidget_Main->indexOf(tab_2), QString());
        tabWidget_Main->setTabText(tabWidget_Main->indexOf(tab_3), QString());
        groupBox->setTitle(QString());
        sendTextEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">11111111111111</p></body></html>", nullptr));
        hexSendPushButton->setText(QCoreApplication::translate("MainWindow", "Hex", nullptr));
        fileSendPushButton->setText(QString());
        clearSendPushButton->setText(QString());
        SendTimerLineEdit->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        sendPushButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\\r\\n", nullptr));
        hexShowPushButton->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
        timeShowPushButton->setText(QString());
        rxShowPushButton->setText(QCoreApplication::translate("MainWindow", "Rx", nullptr));
        txShowPushButton->setText(QCoreApplication::translate("MainWindow", "Tx", nullptr));
        clearShowPushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
