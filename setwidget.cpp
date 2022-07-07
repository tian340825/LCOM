#include "setwidget.h"
#include "ui_setwidget.h"

setWidget::setWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setWidget)
{
    ui->setupUi(this);
}

setWidget::~setWidget()
{
    delete ui;
}
