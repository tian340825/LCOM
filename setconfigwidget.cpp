#include "setconfigwidget.h"
#include "ui_setconfigwidget.h"

setConfigWidget::setConfigWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setConfigWidget)
{
    ui->setupUi(this);
}

setConfigWidget::~setConfigWidget()
{
    delete ui;
}
