#ifndef CONIFG_H
#define CONIFG_H

#include <QWidget>
#include <QColorDialog>
namespace Ui {
class conifg;
}

class conifg : public QWidget
{
    Q_OBJECT

public:
    explicit conifg(QWidget *parent = nullptr);
    ~conifg();
   void initConfig();

   QString parityBitsBoxCountStr();
   QString stopBitBoxCountStr();
   QString dataBitsBoxCountStr();
   int timerSpinBoxCount();
   bool  timeDispEnable();
   bool close();
   QColor sendShowcolorValue();
   QColor recvShowcolorValue();
private:
   void sendShowSendColorDialog();
   void recvShowSendColorDialog();

   void colorValue(const QColor &color);
   bool setColorFlg;
   Ui::conifg *ui;
   QColorDialog *colorDialog;
};

#endif // CONIFG_H
