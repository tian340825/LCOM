#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "uiWidget/fameless/framelessmainwindow.h"
#include "uiWidget/lpushbutton/lpushbutton.h"
#include <QPainter>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include "uiWidget/lcombobox/lcombobox.h"
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
#include "thread/mainThread/mainthread.h"
#define L_LOG qDebug() << "[" << __FILE__ << ":" << __LINE__ << ":" << __func__ << __DATE__ << __TIME__<< "]"

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

private:
    Ui::MainWindow *ui;
    enum SendType {
        sendNULL  = 0,
        sendReturn,//\r
        sendLinFeed,//\n
        sendReturnLinFeed,//\r\n
        sendLinFeedReturn,//\n\r
    };
    SendType sendType = sendReturnLinFeed;

    QSerialPort *serial_1;
    QSerialPort *serial_2;

    QTimer *recvTimer;
    QTimer *sendTimer;
    QTimer *serialCheckTimer;
    QString currentFileName;
    MainThread *mainThread_1;
    MainThread *mainThread_2;

    int reCheckFlag = 0;
    bool isSerialOpen_1 = false;
    bool isSerialOpen_2 = false;
    bool isSendFile = false;
    bool isDefOrCom = false;

    QString serialRecvData_1;


    /******Ui Cfg***********/
    void initUiCfg(void);
    void setWindowsMode(bool flg);
    void initSendPushButtonMune();
    /******Ui Sig*********/
    void serialPortRecvSign();
    void serialPortErrorSign(QSerialPort::SerialPortError error);
    void serialCheckTimerSig();
    void sendPushButtonSign();
    void openPortPushButtonSig();
    /******Ui Fun*********/
    void serialPortSend(const QString &str,bool &hexSend);
    void serialPortRecv(QByteArray &str);
    void serialPortFirstCheck(bool);
    void serialPortSecondCheck(bool);
    void baudRateBoxFirstUpadta(const QString &tabName);
    void baudRateBoxSecondUpadta(const QString &tabName);
    void tabWidgetUpadata(int index);
    /******serial Cfg*****/
    void serialFirstCfg();
    void serialSecondCfg();

/********************thread slots*********************/
private slots:
    void serialFirstOpen();
    void serialFirstClose();
    void serialFirstRecvData(QByteArray &str);
    void serialFirstSendData(QByteArray &str);

    void serialSecondOpen();
    void serialSecondClose();
    void serialSecondRecvData(QByteArray &str);
    void serialSecondSendData(QByteArray &str);
    void serialFirstWarning(QString &str);
    void serialSecondWarning(QString &str);
    void upadaQss(QString oldStr,QString newStr);
private slots:
    void listSendClicked(QString &str,bool &isHex);
    void on_showTextEdit_textChanged();
    void on_rxShowPushButton_clicked();
    void on_fileSendPushButton_clicked();
    void on_sendTextEdit_textChanged();
    void on_clearSendPushButton_clicked();
    void on_comboBox_2_currentTextChanged(const QString &arg1);
    void on_serialOpenPushButton_1_clicked();
    void on_serialOpenPushButton_2_clicked();
};
#endif // MAINWINDOW_H
