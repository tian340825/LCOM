#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "framelessmainwindow.h"
#include "lpushbutton.h"
#include <QPainter>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include "lcombobox.h"
/*-------------user-------------------*/
/*---port--*/
#include <QSerialPort>//提供访问串口的功能
#include <QSerialPortInfo>//提供系统中存在的串口的信息
/*---QString--*/
#include <QString>
/*---QDateTime--*/
#include <QDateTime>
/*---QTimer--*/
#include <QTimer>
/*---QDebug--*/
#include "setwidget.h"
namespace Ui {
class MainWindow;
}
#define MAX_CHECK_FLAG 20
class MainWindow : public FramelessWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addWidget(int index);
    void addWidget1();

private:
    enum SendType {
        sendNULL,
        sendReturn,//\r
        sendLinFeed,//\n
        sendReturnLinFeed,//\r\n
        sendLinFeedReturn,//\n\r
    };

    Ui::MainWindow *ui;
    setWidget *setwidget;
    /**串口********/
    SendType sendType = sendReturnLinFeed;
    QSerialPort *serial;
    QTimer *recvTimer;
    QTimer *sendTimer;
    QTimer *serialCheckTimer;
    int reCheckFlag = 0;
    bool isSerialOpen = false;
    void serialPortSend(const QString &str,bool &hexSend);
    void serialPortRecv();
    void serialPortRecvSign();
    void serialPortErrorSign(QSerialPort::SerialPortError error);
    void serialCheckTimerSig();
    void sendPushButtonSign();
    void openPortPushButtonSig();
    void serialPortCheck(bool);
private slots:
    void listSendClicked(QString &str,bool &isHex);
    void on_showTextEdit_textChanged();

    void on_rxShowPushButton_clicked();
    void on_widgetSetPushButton_clicked();
};
#endif // MAINWINDOW_H
