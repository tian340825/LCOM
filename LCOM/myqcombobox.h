#ifndef MYQCOMBOBOX_H
#define MYQCOMBOBOX_H


#include <QWidget>
#include <QComboBox>
#include <QMouseEvent>

class myQComboBox : public QComboBox
{
    Q_OBJECT
public:
     myQComboBox(QWidget*parent=0);
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked(bool);
};

#endif // MYQCOMBOBOX_H
