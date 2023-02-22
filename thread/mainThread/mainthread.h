#ifndef MAINTHREAD_H
#define MAINTHREAD_H

#include <QThread>
#include "thread/sendThread/sendThread.h"
#include "thread/recvThread/recvThread.h"
/*-------------user-------------------*/
/*---port--*/
#include <QSerialPort>//提供访问串口的功能
#include <QSerialPortInfo>//提供系统中存在的串口的信息
#define L_LOG qDebug() << "[" << __FILE__ << ":" << __LINE__ << ":" << __func__ << __DATE__ << __TIME__<< "]"

class MainThread : public QThread
{
     Q_OBJECT
public:
    MainThread(QSerialPort *serial);
    ~MainThread();
    bool serialOpen();
    bool serialClose();
    bool serialReOpen();
    void write(QByteArray &str);
    void writeHex(QByteArray &str);
    void writeFile(QString &str,int maxSize,int timeMs);
    void serialPortErrorSign(QSerialPort::SerialPortError error);
private:
    void run();
/********************thread slots*********************/

private slots:
    void serialRecvData(QByteArray &str);
    void serialSendData(QByteArray &str);
signals:
   void serialOpenSig();
   void serialCloseSig();
   void serialRecvDataSig(QByteArray &str);
   void serialSendDataSig(QByteArray &str);
   void warningSig(QString &str);
private:
    bool isSerialOpen = false;
    QSerialPort *serial;
    RecvThread *recvThread;
    SendThread *sendThread;
    QByteArray str;
private:
    QByteArray recvStr;
    int maxSize = 65535;
    int time = 0;
    bool sendSigFlg = false;
    bool recvSigFlg = false;
    QString sendFileName;
    qint64  msTimeStampLast = 0;
    bool isStop = false;
};


#endif // MAINTHREAD_H
