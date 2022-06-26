#include "conifg.h"
#include "ui_conifg.h"

conifg::conifg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::conifg)
{
    ui->setupUi(this);
   // this->setWindowFlags(Qt::FramelessWindowHint);
}

conifg::~conifg()
{
    delete ui;
}

QString conifg::parityBitsBoxCountStr()
{
    if(ui->parityBitsBox->currentText() == "NoParity")
    {
        return "0";
    }
    else if(ui->parityBitsBox->currentText() == "EvenParity")
    {
        return "2";
    }
    else if(ui->parityBitsBox->currentText() == "OddParity")
    {
        return "3";
    }
    else if(ui->parityBitsBox->currentText() == "SpaceParity")
    {
        return "4";
    }
    else if(ui->parityBitsBox->currentText() == "MarkParity")
    {
        return "5";
    }
    else
    {
        return "-1";
    }
}

QString conifg::stopBitBoxCountStr()
{
    return ui->stopBitBox->currentText();
}

QString conifg::dataBitsBoxCountStr()
{
    return ui->dataBitsBox->currentText();
}

bool conifg::timeDispEnable()
{
    return (ui->timeDispBox->currentText() == "打开" )? true :false;
}

bool conifg::close()
{
    hide();
}
