#include "conifg.h"
#include "ui_conifg.h"

conifg::conifg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::conifg)
{
    ui->setupUi(this);
   // this->setWindowFlags(Qt::FramelessWindowHint);
   initConfig();
}

conifg::~conifg()
{
    delete ui;
}

void conifg::initConfig()
{
    colorDialog = new QColorDialog;
    colorDialog->setOption(QColorDialog::ShowAlphaChannel);
    connect(colorDialog, &QColorDialog::currentColorChanged,this, &conifg::colorValue);
    connect(ui->sendColorPushButton,&QPushButton::clicked,this,&conifg::sendShowSendColorDialog); //展开
    connect(ui->recvColorPushButton,&QPushButton::clicked,this,&conifg::recvShowSendColorDialog); //展开
}

void conifg::colorValue(const QColor &color)
{
    int r, g, b, a;
    color.getRgb(&r, &g, &b, &a);
    QString clor =  QString("background-color: rgba(%1, %2, %3, %4)").arg(r).arg(g).arg(b).arg(a);
    if(setColorFlg == false)
    {
        ui->recvColorPushButton->setStyleSheet(clor);
    }
    else
    {
        ui->sendColorPushButton->setStyleSheet(clor);
    }
}

void conifg::sendShowSendColorDialog()
{
    colorDialog->show();
    setColorFlg = true;
}

void conifg::recvShowSendColorDialog()
{
    colorDialog->show();
    setColorFlg = false;

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

int conifg::timerSpinBoxCount()
{
    return ui->timerSpinBox->value();
}

bool conifg::timeDispEnable()
{
    return (ui->timeDispBox->currentText() == "打开" )? true :false;
}

bool conifg::close()
{
    hide();
}

QColor conifg::sendShowcolorValue()
{
  //  int r, g, b, a;
    //ui->sendColorPushButton->palette().color(QPalette::Background).getRgb(&r, &g, &b, &a);
  //  QString clor =  QString("background-color: rgba(%1, %2, %3, %4)").arg(r).arg(g).arg(b).arg(a);
    return ui->sendColorPushButton->palette().color(QPalette::Background);
}

QColor conifg::recvShowcolorValue()
{
    return ui->recvColorPushButton->palette().color(QPalette::Background);
}

