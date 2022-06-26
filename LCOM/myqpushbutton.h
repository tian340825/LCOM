#ifndef MYQPUSHBUTTON_H
#define MYQPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

class myQPushButton : public QPushButton
{
   Q_OBJECT

public:
    explicit myQPushButton(QWidget *parent = 0);
private slots:
    void mousePressEvent(QMouseEvent *event);

signals:
//    void rightClicked();
      void leftButtonClicked();
      void rightButtonClicked();
};

#endif // MYQPUSHBUTTON_H
