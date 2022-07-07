#ifndef SETCONFIGWIDGET_H
#define SETCONFIGWIDGET_H

#include <QWidget>

namespace Ui {
class setConfigWidget;
}

class setConfigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit setConfigWidget(QWidget *parent = nullptr);
    ~setConfigWidget();

private:
    Ui::setConfigWidget *ui;
};

#endif // SETCONFIGWIDGET_H
