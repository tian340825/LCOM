#ifndef SETWIDGET_H
#define SETWIDGET_H

#include <QWidget>

namespace Ui {
class setWidget;
}

class setWidget : public QWidget
{
    Q_OBJECT

public:
    explicit setWidget(QWidget *parent = nullptr);
    ~setWidget();

private:
    Ui::setWidget *ui;
};

#endif // SETWIDGET_H
