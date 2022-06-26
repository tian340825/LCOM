#ifndef CONIFG_H
#define CONIFG_H

#include <QWidget>

namespace Ui {
class conifg;
}

class conifg : public QWidget
{
    Q_OBJECT

public:
    explicit conifg(QWidget *parent = nullptr);
    ~conifg();

   QString parityBitsBoxCountStr();
   QString stopBitBoxCountStr();
   QString dataBitsBoxCountStr();
   bool  timeDispEnable();
   bool close();
private:
    Ui::conifg *ui;
};

#endif // CONIFG_H
