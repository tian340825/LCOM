#include "sendThread.h"
#include <QDebug>
#include <QMutex>
#include <QFile>
#include <QDateTime>
#include <QEventLoop>
#include <QTimer>
SendThread::SendThread(QSerialPort *serial)
{
    this->serial=serial;
}

void SendThread::stop()
{
    isStop = true;
}

void SendThread::write(QByteArray &str)
{
    L_LOG<<str;
    serial->write(str);
    emit serialSendDataSig(str);
}

void SendThread::writeFile(QString &str, int maxSize, int timeMs)
{
    sendFileName = str;
    sendSigFlg = true;
    this->maxSize = maxSize;
    this->time = timeMs;
}
void SendThread::writeHex(QByteArray &str)
{
    QByteArray senddata;
    int cnt = str.size();          //要发送数据的长度
    char *data = str.data();
    for(int i=0;i<cnt;i++)//判断是否有非16进制字符
    {
        if(data[i]>='0' && (data[i]<='9'))
        continue;
        else if(data[i]>='a' && (data[i]<='f'))
        continue;
        else if(data[i]>='A' && (data[i]<='F'))
        continue;
        else if(data[i] == ' ')     //输入为空格
        continue;
        else
        {
            QString warningStr = QString("输入非16进制字符！");
            emit warningSig(warningStr);
            return;
        }
    }
    senddata = senddata.fromHex(str);
    L_LOG<<senddata;
    write(senddata);
}

void SendThread::run()
{
    while(!isStop)
    {
        if(sendSigFlg == true)
        {
            QFile aFile(sendFileName);
            if(!aFile.exists())//如果文件不存在
            {
                L_LOG << "file don't exist"<<sendFileName;
                sendSigFlg = false;

            }
            if(!aFile.open(QIODevice::ReadOnly |QIODevice::Text))//如果不是以只读和文本方式打开文件返回false
            {
                L_LOG << "file open error ";
                sendSigFlg = false;
            }
            QByteArray filedata;

            for(int i = 0;i <= aFile.size() / maxSize ;i++)
            {
                filedata = aFile.read(maxSize);
                L_LOG << "send file data ";
                emit serialSendDataSig(filedata);
                msleep(time);
            }
            sendSigFlg = false;
        }

        QEventLoop loop;
        QTimer::singleShot(10, &loop, SLOT(quit()));
        loop.exec();
    }
}


SendThread::~SendThread()
{

}
