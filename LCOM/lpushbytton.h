#ifndef LPUSHBYTTON_H
#define LPUSHBYTTON_H
#include <qnamespace.h>
#include <QPushButton>
#include <QMouseEvent>

class LPushBytton : public QPushButton
{
    Q_OBJECT
public:
    explicit LPushBytton(QWidget *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

    void leftButtonClicked();
    void rightButtonClicked();
};

#endif // LPUSHBYTTON_H
