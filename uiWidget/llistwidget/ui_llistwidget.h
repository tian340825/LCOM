/********************************************************************************
** Form generated from reading UI file 'llistwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LLISTWIDGET_H
#define UI_LLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <uiWidget/lcombobox/lcombobox.h>

QT_BEGIN_NAMESPACE

class Ui_LListWidget
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer;
    LComboBox *comComboBox;
    QPushButton *setPushButton;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *LListWidget)
    {
        if (LListWidget->objectName().isEmpty())
            LListWidget->setObjectName(QString::fromUtf8("LListWidget"));
        LListWidget->resize(427, 598);
        gridLayout_2 = new QGridLayout(LListWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea_2 = new QScrollArea(LListWidget);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 411, 582));
        gridLayout = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line_5 = new QFrame(scrollAreaWidgetContents_3);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setMaximumSize(QSize(16777215, 5));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_7 = new QLabel(scrollAreaWidgetContents_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(16777215, 30));
        label_7->setStyleSheet(QString::fromUtf8("font: 9pt \"Microsoft YaHei UI\";\n"
"color:rgb(253, 127, 151);"));

        horizontalLayout->addWidget(label_7);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        comComboBox = new LComboBox(scrollAreaWidgetContents_3);
        comComboBox->setObjectName(QString::fromUtf8("comComboBox"));
        comComboBox->setMaximumSize(QSize(16777215, 30));
        comComboBox->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(comComboBox);

        setPushButton = new QPushButton(scrollAreaWidgetContents_3);
        setPushButton->setObjectName(QString::fromUtf8("setPushButton"));
        setPushButton->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(setPushButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_3);

        gridLayout_2->addWidget(scrollArea_2, 0, 0, 1, 1);


        retranslateUi(LListWidget);

        QMetaObject::connectSlotsByName(LListWidget);
    } // setupUi

    void retranslateUi(QWidget *LListWidget)
    {
        LListWidget->setWindowTitle(QCoreApplication::translate("LListWidget", "Form", nullptr));
        label_7->setText(QCoreApplication::translate("LListWidget", "\345\221\275\344\273\244\345\210\227\350\241\250", nullptr));
        setPushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LListWidget: public Ui_LListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LLISTWIDGET_H
