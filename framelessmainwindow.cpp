#include "framelessmainwindow.h"

#include <QMouseEvent>
#include <QGridLayout>
#include <QGraphicsDropShadowEffect>


FramelessWindow::FramelessWindow(QWidget *parent) : QMainWindow(parent) {
    this->setWindowFlags(Qt::FramelessWindowHint);                //取消标题栏
    // 去掉标题栏,去掉工具栏，窗口置顶
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    //setWindowOpacity(0.7); //设置窗体透明度
    installEventFilter(this);
    //this->centralWidget->setMouseTracking(true);

    setMouseTracking(true);
}

FramelessWindow::~FramelessWindow() {

}


void FramelessWindow::region(const QPoint &currentGlobalPoint)
{
    // 获取窗体在屏幕上的位置区域，topLeft为坐上角点，rightButton为右下角点
    QRect rect = this->rect();

    QPoint topLeft = this->mapToGlobal(rect.topLeft()); //将左上角的(0,0)转化为全局坐标
    QPoint rightButton = this->mapToGlobal(rect.bottomRight());

    int x = currentGlobalPoint.x(); //当前鼠标的坐标
    int y = currentGlobalPoint.y();
    qDebug() << QString("%1 %2").arg(x).arg(y);
    qDebug() << QString("%1 %2").arg(topLeft.x()).arg(topLeft.y());
    qDebug() << QString("%1 %2").arg(rightButton.x()).arg(rightButton.x());
    if(((topLeft.x() + PADDING >= x) && (topLeft.x() <= x))
            && ((topLeft.y() + PADDING >= y) && (topLeft.y() <= y)))
    {
        qDebug() << QString("LEFTTOP");

        // 左上角
        dir = LEFTTOP;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));  // 设置光标形状
    }else if(((x >= rightButton.x() - PADDING) && (x <= rightButton.x()))
              && ((y >= rightButton.y() - PADDING) && (y <= rightButton.y())))
    {
        qDebug() << QString("RIGHTBOTTOM");

        // 右下角
        dir = RIGHTBOTTOM;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    }else if(((x <= topLeft.x() + PADDING) && (x >= topLeft.x()))
              && ((y >= rightButton.y() - PADDING) && (y <= rightButton.y())))
    {
        qDebug() << QString("LEFTBOTTOM");

        //左下角
        dir = LEFTBOTTOM;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    }else if(((x <= rightButton.x()) && (x >= rightButton.x() - PADDING))
              && ((y >= topLeft.y()) && (y <= topLeft.y() + PADDING)))
    {
        qDebug() << QString("RIGHTTOP");

        // 右上角
        dir = RIGHTTOP;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    }else if((x <= topLeft.x() + PADDING) && (x >= topLeft.x()))
    {
        qDebug() << QString("LEFT");

        // 左边
        dir = LEFT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }else if((x <= rightButton.x()) && (x >= rightButton.x() - PADDING))
    {
        qDebug() << QString("RIGHT");

        // 右边
        dir = RIGHT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }else if((y >= topLeft.y()) && (y <= topLeft.y() + PADDING))
    {
        qDebug() << QString("UP");

        // 上边
        dir = UP;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }else if((y <= rightButton.y()) && (y >= rightButton.y() - PADDING))
    {
        qDebug() << QString("DOWN");

        // 下边
        dir = DOWN;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }else
    {
        qDebug() << QString("NONE");

        // 默认
        dir = NONE;
        this->setCursor(QCursor(Qt::ArrowCursor));
    }
}


//三个鼠标事件的重写
//鼠标按下事件
void FramelessWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << QString("fff");

    switch(event->button())
    {
        case Qt::LeftButton:
            isLeftPressDown = true;
            qDebug() << QString("7fff7eee");

            if(dir != NONE)
            {
                this->mouseGrabber(); //返回当前抓取鼠标输入的窗口
                qDebug() << QString("77efffee");

            }
            else
            {
                qDebug() << QString("77efffee");

                m_movePoint = event->globalPos() - this->frameGeometry().topLeft();
                //globalPos()鼠标位置，topLeft()窗口左上角的位置
            }
            break;
        case Qt::RightButton:
            this->setWindowState(Qt::WindowMinimized);
            break;
        default:
            FramelessWindow::mousePressEvent(event);
    }
}



//鼠标移动事件
void FramelessWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint globalPoint = event->globalPos();   //鼠标全局坐标

    QRect rect = this->rect();  //rect == QRect(0,0 1280x720)
    QPoint topLeft = mapToGlobal(rect.topLeft());
    QPoint bottomRight = mapToGlobal(rect.bottomRight());
    qDebug() << QString("1111");

    if (this->windowState() != Qt::WindowMaximized)
    {
        qDebug() << QString("22222222");

        if(!isLeftPressDown)  //没有按下左键时
        {
            qDebug() << QString("333");

            this->region(globalPoint); //窗口大小的改变——判断鼠标位置，改变光标形状
       }
        else
        {
            qDebug() << QString("5555");

            if(dir != NONE)
            {
                qDebug() << QString("666");

                QRect newRect(topLeft, bottomRight); //定义一个矩形  拖动后最大1000*1618

                switch(dir)
                {
                    case LEFT:
                    qDebug() << QString("77");

                        if(bottomRight.x() - globalPoint.x() <= this->minimumWidth())
                        {
                            newRect.setLeft(topLeft.x());  //小于界面的最小宽度时，设置为左上角横坐标为窗口x
                            //只改变左边界
                        }
                        else
                        {
                            newRect.setLeft(globalPoint.x());
                        }
                        break;
                    case RIGHT:
                    qDebug() << QString("757");

                        newRect.setWidth(globalPoint.x() - topLeft.x());  //只能改变右边界
                        break;
                    case UP:
                    qDebug() << QString("766");

                        if(bottomRight.y() - globalPoint.y() <= this->minimumHeight())
                        {
                            newRect.setY(topLeft.y());
                        }
                        else
                        {
                            newRect.setY(globalPoint.y());
                        }
                        break;
                    case DOWN:
                    qDebug() << QString("7557");

                        newRect.setHeight(globalPoint.y() - topLeft.y());
                        break;
                    case LEFTTOP:
                    qDebug() << QString("7eee7");

                        if(bottomRight.x() - globalPoint.x() <= this->minimumWidth())
                        {
                            newRect.setX(topLeft.x());
                        }
                        else
                        {
                            newRect.setX(globalPoint.x());
                        }

                        if(bottomRight.y() - globalPoint.y() <= this->minimumHeight())
                        {
                            newRect.setY(topLeft.y());
                        }
                        else
                        {
                            newRect.setY(globalPoint.y());
                        }
                        break;
                     case RIGHTTOP:
                    qDebug() << QString("77eee");

                          if (globalPoint.x() - topLeft.x() >= this->minimumWidth())
                          {
                              newRect.setWidth(globalPoint.x() - topLeft.x());
                          }
                          else
                          {
                              newRect.setWidth(bottomRight.x() - topLeft.x());
                          }
                          if (bottomRight.y() - globalPoint.y() >= this->minimumHeight())
                          {
                              newRect.setY(globalPoint.y());
                          }
                          else
                          {
                              newRect.setY(topLeft.y());
                          }
                          break;
                     case LEFTBOTTOM:
                    qDebug() << QString("77eeeeee");

                          if (bottomRight.x() - globalPoint.x() >= this->minimumWidth())
                          {
                              newRect.setX(globalPoint.x());
                          }
                          else
                          {
                              newRect.setX(topLeft.x());
                          }
                          if (globalPoint.y() - topLeft.y() >= this->minimumHeight())
                          {
                              newRect.setHeight(globalPoint.y() - topLeft.y());
                          }
                          else
                          {
                              newRect.setHeight(bottomRight.y() - topLeft.y());
                          }
                          break;
                      case RIGHTBOTTOM:
                          newRect.setWidth(globalPoint.x() - topLeft.x());
                          newRect.setHeight(globalPoint.y() - topLeft.y());
                          break;
                      default:
                          break;
                }
                this->setGeometry(newRect);
                qDebug() << QString("77eerrre");

            }
            else
            {
                qDebug() << QString("77eettte");

                move(event->globalPos() - m_movePoint); //移动窗口
                event->accept();
            }
        }
    }
}


//鼠标释放事件
void FramelessWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << QString("mouseReleaseEvent");

    if (event->button() == Qt::LeftButton)
    {
        qDebug() << QString("LeftButton");

        isLeftPressDown = false;
        if (dir != NONE)
        {
            this->releaseMouse(); //释放鼠标抓取
            this->setCursor(QCursor(Qt::ArrowCursor));
            dir = NONE; //热心网友指正
        }
    }
}
