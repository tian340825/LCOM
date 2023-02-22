#include "thread/recvThread/recvThread.h"
#include <QDebug>
#include <QMutex>
#include <QDateTime>
#include <QEventLoop>
#include <QTimer>
RecvThread::RecvThread(QSerialPort *serial)
{
    this->serial=serial;
    connect(serial, &QSerialPort::readyRead, this, &RecvThread::serialRecvData,Qt::DirectConnection);//接受串口数据
}

RecvThread::~RecvThread()
{

}

void RecvThread::closeThread()
{

}

void RecvThread::read()
{
    serialRecvData();
}

void RecvThread::run()
{
    while (1)
    {
        if(recvSigFlg == true)
        {
            L_LOG << "recv sig"<<serial->bytesAvailable();
            if(serial->bytesAvailable() >=  1024 ) //  缓存区数据太大时，分批读取
            {
                QByteArray array = serial->read(1024);
                emit serialRecvDataSig(array);
            }
            else
            {
                qint64  timeInterval = QDateTime::currentMSecsSinceEpoch() - msTimeStampLast;
                L_LOG << "recv sig 1rrrrrrrrrrrrr111 ";

                if(timeInterval >= 100)
                {
                    if(msTimeStampLast != 0)
                    {
                        QByteArray buffer = serial->readAll();
                        L_LOG<<buffer;
                        emit serialRecvDataSig(buffer);
                        recvSigFlg = false;
                    }
                    else
                    {
                        L_LOG << "recv sig 3333333333 ";
                    }
                }
                else
                {
                    L_LOG << "recv sig"<< timeInterval <<"  2222222";
                }
            }
        }

        QEventLoop loop;
        QTimer::singleShot(10, &loop, SLOT(quit()));
        loop.exec();
    }

}
void RecvThread::serialRecvData()
{
    L_LOG << "recv serialRecvData ";
    msTimeStampLast = QDateTime::currentMSecsSinceEpoch();
    recvSigFlg = true;
}
