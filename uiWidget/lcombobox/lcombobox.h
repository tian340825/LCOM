#ifndef MYQCOMBOBOX_H
#define MYQCOMBOBOX_H


#include <QWidget>
#include <QComboBox>
#include <QMouseEvent>
#define L_LOG qDebug() << "[" << __FILE__ << ":" << __LINE__ << ":" << __func__ << __DATE__ << __TIME__<< "]"

class LComboBox : public QComboBox
{
    Q_OBJECT
public:
     LComboBox(QWidget*parent=0);
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked(bool);
};

#endif // MYQCOMBOBOX_H
