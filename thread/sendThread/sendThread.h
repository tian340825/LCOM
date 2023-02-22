#ifndef SENDTHREAD_H
#define SENDTHREAD_H

#include <QThread>
/*-------------user-------------------*/
/*---port--*/
#include <QSerialPort>//提供访问串口的功能
#include <QSerialPortInfo>//提供系统中存在的串口的信息
#define L_LOG qDebug() << "[" << __FILE__ << ":" << __LINE__ << ":" << __func__ << __DATE__ << __TIME__<< "]"

class SendThread : public QThread
{
    Q_OBJECT
public:
    SendThread(QSerialPort *serial);
    ~SendThread();
    void stop();
    void write(QByteArray &str);
    void writeFile(QString &str,int maxSize,int timeMs);
    void writeHex(QByteArray &str);
    void setDataPack(int maxSize,int time);//设置每包数据最大长度,以及分包发送的间隔
signals:
   void serialSendDataSig(QByteArray &str);
   void warningSig(QString &str);
private:
    void run();
    void serialRecvData();

private:
    QByteArray recvStr;
    int maxSize = 65535;
    int time = 0;
    QSerialPort *serial;
    bool sendSigFlg = false;
    QString sendFileName;
    qint64  msTimeStampLast = 0;
    bool isStop = false;
};


#endif // MAINTHREAD_H
