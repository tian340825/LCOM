#ifndef LTABWIDGET_H
#define LTABWIDGET_H

#include <QWidget>
#include <QTabBar>
#include <QTabWidget>
#include <QLabel>
#include <QDebug>
#define L_LOG qDebug() << "[" << __FILE__ << ":" << __LINE__ << ":" << __func__ << __DATE__ << __TIME__<< "]"

class LTabWidget: public QTabWidget
{
    Q_OBJECT
public:
    explicit LTabWidget(QWidget *parent = nullptr);

    void updateselect();                          //用来设置一开始选中的状态
    int addTab(QWidget *widget, const QString &); //重载(不是虚函数)

signals:

public slots:
    void slotSetLabelColor(int color);            //自定义槽(响应tabBar点击事件)
};
#endif // LTABWIDGET_H
