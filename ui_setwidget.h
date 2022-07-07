/********************************************************************************
** Form generated from reading UI file 'setwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETWIDGET_H
#define UI_SETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setWidget
{
public:
    QGridLayout *gridLayout;
    QWidget *tileWidget;
    QGridLayout *gridLayout_6;
    QPushButton *closePushButton;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton11111;
    QFrame *line;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *setWidget)
    {
        if (setWidget->objectName().isEmpty())
            setWidget->setObjectName(QString::fromUtf8("setWidget"));
        setWidget->resize(640, 480);
        gridLayout = new QGridLayout(setWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tileWidget = new QWidget(setWidget);
        tileWidget->setObjectName(QString::fromUtf8("tileWidget"));
        tileWidget->setMinimumSize(QSize(0, 50));
        tileWidget->setMaximumSize(QSize(16777215, 40));
        gridLayout_6 = new QGridLayout(tileWidget);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        closePushButton = new QPushButton(tileWidget);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setMinimumSize(QSize(40, 40));
        closePushButton->setMaximumSize(QSize(40, 40));
        closePushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border:none"));

        gridLayout_6->addWidget(closePushButton, 0, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 0, 5, 1, 1);

        label_8 = new QLabel(tileWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(80, 0));
        label_8->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Microsoft YaHei UI\";\n"
"color:rgb(253, 127, 151);"));

        gridLayout_6->addWidget(label_8, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(1, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 3, 1, 1);


        gridLayout->addWidget(tileWidget, 0, 0, 1, 1);

        tabWidget = new QTabWidget(setWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::West);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(260, 250, 113, 22));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton11111 = new QPushButton(tab_2);
        pushButton11111->setObjectName(QString::fromUtf8("pushButton11111"));
        pushButton11111->setMinimumSize(QSize(200, 200));
        pushButton11111->setMaximumSize(QSize(200, 200));
        pushButton11111->setStyleSheet(QString::fromUtf8("border-image: url(:/image/check/locm.png);"));

        gridLayout_2->addWidget(pushButton11111, 0, 0, 1, 1);

        line = new QFrame(tab_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 200));
        line->setMaximumSize(QSize(20, 200));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 0, 1, 1, 1);

        plainTextEdit = new QPlainTextEdit(tab_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setMinimumSize(QSize(200, 200));
        plainTextEdit->setMaximumSize(QSize(200, 200));

        gridLayout_2->addWidget(plainTextEdit, 0, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(setWidget);
        QObject::connect(closePushButton, SIGNAL(clicked()), setWidget, SLOT(hide()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(setWidget);
    } // setupUi

    void retranslateUi(QWidget *setWidget)
    {
        setWidget->setWindowTitle(QCoreApplication::translate("setWidget", "Form", nullptr));
        closePushButton->setText(QString());
        label_8->setText(QCoreApplication::translate("setWidget", "   \350\256\276\347\275\256", nullptr));
        lineEdit->setText(QCoreApplication::translate("setWidget", "\346\262\241\346\203\263\345\245\275\346\200\216\344\271\210\345\201\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("setWidget", "\347\232\256\350\202\244", nullptr));
        pushButton11111->setText(QString());
        plainTextEdit->setPlainText(QCoreApplication::translate("setWidget", "\346\254\242\350\277\216\344\275\277\347\224\250\n"
"LCOM\n"
"\345\237\272\344\272\216QT C++\n"
"https://github.com/tian340825/LCOM\n"
"\345\275\223\345\211\215\347\211\210\346\234\2541.0 Debug", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("setWidget", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setWidget: public Ui_setWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETWIDGET_H
