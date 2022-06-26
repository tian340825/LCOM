#include "myqcombobox.h"

myQComboBox::myQComboBox(QWidget *parent)
{

}

void myQComboBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit clicked(true);
    }
    QComboBox::mousePressEvent(event);

}
