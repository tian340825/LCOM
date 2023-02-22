#include "lcombobox.h"

LComboBox::LComboBox(QWidget *parent)
{

}

void LComboBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked(true);
    }
    QComboBox::mousePressEvent(event);

}
