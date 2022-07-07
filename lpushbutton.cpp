#include "lpushbutton.h"


LPushButton::LPushButton(QWidget *parent):QPushButton(parent)

{


    installEventFilter(this);


}
#if 0
void LPushButton::mousePressEvent(QMouseEvent *event)
{
    if (Qt::LeftButton == event->button())
    {
        emit leftButtonClicked();
    }
    else if (Qt::RightButton == event->button())
    {
        emit rightButtonClicked();
    }
    QPushButton::mousePressEvent(event);
}
#endif
//事件过滤器
bool LPushButton::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == this) {
        if(event->type() == QEvent::HoverEnter) {
            QGraphicsDropShadowEffect *defaultShadow = new QGraphicsDropShadowEffect();
            // 阴影偏移
            defaultShadow->setOffset(0, 0);
            // 阴影颜色;
            defaultShadow->setColor(QColor(253, 127, 151));
            // 阴影半径;
            defaultShadow->setBlurRadius(50);
            this->setGraphicsEffect(defaultShadow);
            return true;
        }
        if(event->type() == QEvent::HoverLeave) {
            QGraphicsDropShadowEffect *no_shadow_effect = new QGraphicsDropShadowEffect(this);
            no_shadow_effect->setOffset(0, 0);
            //阴影颜色
            no_shadow_effect->setColor(QColor(255,255,255));
            //阴影半径
            no_shadow_effect->setBlurRadius(0);
            this->setGraphicsEffect(no_shadow_effect);
            return true;
        }
    }
    return QWidget::eventFilter(obj,event);
}

void LPushButton::setTwoIcon(const QIcon &checkIcon, const QIcon &noCheckIcon)
{
    //this->setFixedSize(64, 32);
    this->checkIcon = checkIcon;
    this->noCheckIcon = noCheckIcon;

}


