#ifndef LPUSHBUTTON_H
#define LPUSHBUTTON_H

#include <QWidget>
#include <QPointer>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsEffect>
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>

class LPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit LPushButton(QWidget *parent = nullptr);

    bool eventFilter(QObject *obj, QEvent *event);
    void setTwoIcon(const QIcon &checkIcon,const QIcon &noCheckIcon);
    void mousePressEvent(QMouseEvent *event);
private:
    QIcon checkIcon;
    QIcon noCheckIcon;
signals:
    void leftButtonClicked();
    void rightButtonClicked();
};

#endif // LPUSHBUTTON_H
