#include "ltabwidget.h"

LTabWidget::LTabWidget(QWidget *parent) : QTabWidget(parent)
{

    connect(this,SIGNAL(tabBarClicked(int)),this,SLOT(slotSetLabelColor(int)));

}

void LTabWidget::slotSetLabelColor(int index)
{
}

int LTabWidget::addTab(QWidget *widget, const QString &label)
{
    int nRetrun=QTabWidget::addTab(widget,"");
    int count=this->count()-1;
    QLabel *labelTab=new QLabel(label,this);
    QFont ft;
    ft.setPointSize(20);
    labelTab->setFont(ft);
    labelTab->setAlignment(Qt::AlignCenter);
    this->tabBar()->setTabButton(count,QTabBar::ButtonPosition::RightSide,labelTab);
    this->tabBar()->tabButton(count,QTabBar::ButtonPosition::RightSide)->setFixedHeight(64);
    //this->tabBar()->tabButton(count,QTabBar::ButtonPosition::RightSide)->setObjectName("tabPushButton");
    updateselect();
    return nRetrun;

}

void LTabWidget::updateselect()
{
}
