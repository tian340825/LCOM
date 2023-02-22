#ifndef RECVTHREAD_H
#define RECVTHREAD_H

#include <QThread>
/*-------------user-------------------*/
/*---port--*/
#include <QSerialPort>//提供访问串口的功能
#include <QSerialPortInfo>//提供系统中存在的串口的信息
#define L_LOG qDebug() << "[" << __FILE__ << ":" << __LINE__ << ":" << __func__ << __DATE__ << __TIME__<< "]"

class RecvThread : public QThread
{
     Q_OBJECT
public:
    RecvThread(QSerialPort *serial);
    ~RecvThread();

    void closeThread();
    void read();
private:
    void run();
    void serialRecvData();
signals:
   void serialRecvDataSig(QByteArray &str);
   void warningSig(QString &str);
private:
    QSerialPort *serial;
    QByteArray recvStr;
    bool recvSigFlg = false;
    qint64  msTimeStampLast = 0;;

};


#endif // MAINTHREAD_H
