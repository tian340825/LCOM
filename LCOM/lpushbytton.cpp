#include "lpushbytton.h"

LPushBytton::LPushBytton(QWidget *parent)
    : QPushButton{parent}
{

}

void LPushBytton::mouseReleaseEvent(QMouseEvent *e)
{
    if (Qt::LeftButton == e->button())
    {
        emit leftButtonClicked();
    }
    else if (Qt::RightButton == e->button())
    {
        emit rightButtonClicked();
    }

}
