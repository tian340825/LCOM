#include "thread/mainThread/mainthread.h"
#include <QDebug>
#include <QMutex>
#include <QFile>
#include <QDateTime>
#include <QEventLoop>
#include <QTimer>

MainThread::MainThread(QSerialPort *serial)
{
    this->serial=serial;
    recvThread = new RecvThread(serial);
    sendThread = new SendThread(serial);
    recvThread->start();
    sendThread->start();
}

MainThread::~MainThread()
{

}

bool MainThread::serialOpen()
{
    isSerialOpen = serial->open(QIODevice::ReadWrite);
    if (!isSerialOpen)
    {
        QString warningStr = QString("串口连接中断，请检查是否正确连接！\r\n%1\r\n%2").arg(serial->portName()).arg(serial->errorString());
        emit warningSig(warningStr);
        L_LOG<< QString("Failed to open serial port:") << serial->portName() << serial->errorString();
        serial->clearError();
    }
    else
    {
        L_LOG<< QString("The serial port is open: ") <<serial->portName();
        emit serialOpenSig();
    }

   return isSerialOpen;
}


bool MainThread::serialClose()
{
    serial->close();
    emit serialCloseSig();
    isSerialOpen = false;
    return true;
}

bool MainThread::serialReOpen()
{
    serial->close();
    sleep(1);
    serial->open(QIODevice::ReadWrite);
}

void MainThread::write(QByteArray &str)
{
    sendThread->write(str);
}

void MainThread::writeHex(QByteArray &str)
{
    sendThread->writeHex(str);
    L_LOG<<str;
}

void MainThread::writeFile(QString &str, int maxSize, int timeMs)
{
    sendThread->writeFile(str,maxSize,timeMs);
}


void MainThread::run()
{
    connect(sendThread, &SendThread::serialSendDataSig, this, &MainThread::serialSendData,Qt::DirectConnection);//发送串口数据
    connect(recvThread, &RecvThread::serialRecvDataSig, this, &MainThread::serialRecvData,Qt::DirectConnection);//接收串口数据
    while(1)
    {
        QEventLoop loop;
        QTimer::singleShot(1, &loop, SLOT(quit()));
        loop.exec();
    }
}

void MainThread::serialRecvData(QByteArray &str)
{
    L_LOG<<serial->portName()<<"Rx:"<<str;
    emit serialRecvDataSig(str);
}

void MainThread::serialSendData(QByteArray &str)
{
    L_LOG << "Tx:";
    emit serialSendDataSig(str);
}

void MainThread::serialPortErrorSign(QSerialPort::SerialPortError error)
{
     L_LOG << QString("%1").arg(error);
    if ((error == QSerialPort::PermissionError) ||   (isSerialOpen == true))
    {
        L_LOG<< QString("The serial port : ") <<serial->portName()<<"is error";
        emit serialCloseSig();
    }
}
