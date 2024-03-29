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
#define L_LOG qDebug() << "[" << __FILE__ << ":" << __LINE__ << ":" << __func__ << __DATE__ << __TIME__<< "]"

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
