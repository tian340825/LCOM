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
//#include "setconfigwidget.h"
#include <QFileIconProvider>
#include <QTextDocumentFragment>
namespace Ui {
class MainWindow;
}
#define MAX_CHECK_FLAG 20

//class MainWindow : public FramelessMainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addWidget(int index);
    void addWidget1();

private:
    enum SendType {
        sendNULL  = 0,
        sendReturn,//\r
        sendLinFeed,//\n
        sendReturnLinFeed,//\r\n
        sendLinFeedReturn,//\n\r
    };

    Ui::MainWindow *ui;
   // setConfigWidget *setwidget;
    /**串口********/
    SendType sendType = sendReturnLinFeed;
    QSerialPort *serial;
    QTimer *recvTimer;
    QTimer *sendTimer;
    QTimer *serialCheckTimer;
    QString currentFileName;
    int reCheckFlag = 0;
    bool isSerialOpen = false;
    bool isSendFile = false;
    void serialPortSend(const QString &str,bool &hexSend);
    void serialPortRecv(bool newLineFlg);
    void serialPortRecvSign();
    void serialPortErrorSign(QSerialPort::SerialPortError error);
    void serialCheckTimerSig();
    void sendPushButtonSign();
    void openPortPushButtonSig();
    void serialPortCheck(bool);
    void baudRateBoxUpadta(const QString &tabName);
    void sleep(unsigned int msec);
private slots:
    void listSendClicked(QString &str,bool &isHex);
    void on_showTextEdit_textChanged();

    void on_rxShowPushButton_clicked();
    void on_widgetSetPushButton_clicked();
    void on_fileSendPushButton_clicked();
    void on_sendTextEdit_textChanged();
    void on_clearSendPushButton_clicked();
};
#endif // MAINWINDOW_H
