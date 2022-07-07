#ifndef FRAMELESSWINDOW_H
#define FRAMELESSWINDOW_H
#include <QDebug>

#include <QMainWindow>
#ifdef Q_OS_WIN
#include "windows.h"
#include "windowsx.h"
#pragma comment (lib,"user32.lib")
#endif
struct FramelessWindowPrivate;
#define PADDING 2
enum Direction { UP=0, DOWN=1, LEFT, RIGHT, LEFTTOP, LEFTBOTTOM, RIGHTBOTTOM, RIGHTTOP, NONE };
class FramelessWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit FramelessWindow(QWidget *parent = 0);
    ~FramelessWindow();

public:
    void region(const QPoint &currentGlobalPoint);  //鼠标的位置,改变光标
protected:
    //鼠标按下移动及释放事件
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QPoint m_movePoint;  //鼠标的位置
    bool isLeftPressDown = false;  // 判断左键是否按下
    Direction dir;        // 窗口大小改变时，记录改变方向
};

#endif // FRAMELESSWINDOW_H
