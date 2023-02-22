#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uiWidget/fameless/framelessmainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sendTimer = new QTimer;
    sendTimer->setInterval(ui->SendTimerLineEdit->text().toUInt());

    serial_1 = new QSerialPort(this);
    serial_2 = new QSerialPort(this);
    mainThread_1 = new MainThread(serial_1);
    mainThread_1->start();
    mainThread_2= new MainThread(serial_2);
    mainThread_2->start();
    //first serial thread
    connect(mainThread_1, &MainThread::serialOpenSig, this, &MainWindow::serialFirstOpen,Qt::DirectConnection);//打开串口
    connect(mainThread_1, &MainThread::serialCloseSig, this, &MainWindow::serialFirstClose,Qt::DirectConnection);//关闭串口
    connect(mainThread_1, &MainThread::serialRecvDataSig, this, &MainWindow::serialFirstRecvData,Qt::DirectConnection);//接收串口数据
    connect(mainThread_1, &MainThread::warningSig, this, &MainWindow::serialFirstWarning,Qt::DirectConnection);//串口异常提示
    connect(mainThread_1, &MainThread::serialSendDataSig, this, &MainWindow::serialFirstSendData,Qt::DirectConnection);//发送串口数据

    //first serial thread
    connect(mainThread_2, &MainThread::serialOpenSig, this, &MainWindow::serialSecondOpen,Qt::DirectConnection);//打开串口
    connect(mainThread_2, &MainThread::serialCloseSig, this, &MainWindow::serialSecondClose,Qt::DirectConnection);//关闭串口
    connect(mainThread_2, &MainThread::serialRecvDataSig, this, &MainWindow::serialSecondRecvData,Qt::DirectConnection);//接收串口数据
    connect(mainThread_2, &MainThread::warningSig, this, &MainWindow::serialSecondWarning,Qt::DirectConnection);//串口异常提示
    connect(mainThread_2, &MainThread::serialSendDataSig, this, &MainWindow::serialSecondSendData,Qt::DirectConnection);//发送串口数据

    connect(sendTimer,&QTimer::timeout,this,[=](){sendPushButtonSign();});//定时发送定时器
    connect(ui->sendPushButton,&QToolButton::clicked,this,&MainWindow::sendPushButtonSign);//发送数据

    connect(ui->SerialPortBox_1,&LComboBox::clicked,this,&MainWindow::serialPortFirstCheck);//串口检测下拉刷新
    connect(ui->baudRateBox_1,&LComboBox::currentTextChanged,this,&MainWindow::baudRateBoxFirstUpadta);//波特率更新
    connect(ui->SerialPortBox_2,&LComboBox::clicked,this,&MainWindow::serialPortSecondCheck);//串口检测下拉刷新
    connect(ui->baudRateBox_2,&LComboBox::currentTextChanged,this,&MainWindow::baudRateBoxSecondUpadta);//波特率更新

    connect(ui->tabWidget_Main, &QTabWidget::tabBarClicked, this ,&MainWindow::tabWidgetUpadata);//界面切换
    connect(ui->widget_2,&LListWidget::sendDataClicked,this,&MainWindow::listSendClicked);//列表发送
    initUiCfg();
}

MainWindow::~MainWindow()
{
    if (isSerialOpen_1)
    {
        serial_1->close();
    }
    if (isSerialOpen_2)
    {
        serial_2->close();
    }
    delete ui;
}


/**************Ui Cif*****************/
void MainWindow::initUiCfg()
{
    setWindowsMode(false);
    initSendPushButtonMune();
    //set SendTimerLineEdit config
    QRegExp rx2("^\\d\\d\\d\\d\\d\\d\\d\\d?$");
    ui->SendTimerLineEdit->setValidator(new QRegExpValidator(rx2,ui->SendTimerLineEdit));

}


void MainWindow::setWindowsMode(bool flg)
{
    if(flg == false)
    {
        ui->serialOpenPushButton_1->hide();
        ui->serialOpenPushButton_2->hide();
        ui->serialSetGroupBox_2->hide();
        ui->showTextEdit_2->hide();
        ui->splitter->setStretchFactor(0,9);
        ui->splitter->setStretchFactor(1,1);
        //ui->sendTextEdit->setEnabled(true);//可输入
        isDefOrCom = false;
    }
    else
    {
        ui->serialOpenPushButton_1->show();
        ui->serialOpenPushButton_2->show();
        ui->serialSetGroupBox_2->show();
        ui->showTextEdit_2->show();
        ui->splitter->setStretchFactor(0,99);
        ui->splitter->setStretchFactor(1,1);
        //ui->sendTextEdit->setEnabled(false);//不可输入
        isDefOrCom = true;
    }
}

void MainWindow::initSendPushButtonMune()
{
    //ui init size
    ui->tabWidget_Main->setAttribute(Qt::WA_StyledBackground);
    ui->tabWidget_Main->setTabEnabled(0, false);
    ui->splitter_4->setStretchFactor(0,2);
    ui->splitter_4->setStretchFactor(1,8);
    ui->tileWidget->hide();
    on_comboBox_2_currentTextChanged("Default");

    QMenu *menu = new QMenu();
    QAction* project0Action = menu->addAction(tr("定时发送"));
    project0Action->setCheckable(true);
    connect(project0Action, &QAction::triggered, this, [=](){
         if(project0Action->isChecked() == true)
         {
                ui->SendTimerLineEdit->setEnabled(false);//失能周期输入文本框
                sendTimer->start(ui->SendTimerLineEdit->text().toUInt());
         }
         else
         {
             ui->SendTimerLineEdit->setEnabled(true);//失能周期输入文本框
             if(sendTimer->isActive() == true)
             {
                 sendTimer->stop();
             }
         }
    });

    //sendPushButton add menu
    QMenu* menu2 = menu->addMenu("回车换行");
    menu2->addSeparator();
    QAction* project1Action= menu2->addAction(tr("无"));
    QAction* project2Action= menu2->addAction(tr("\\r"));
    QAction* project3Action= menu2->addAction(tr("\\n"));
    QAction* project4Action= menu2->addAction(tr("\\r\\n"));
    QAction* project5Action= menu2->addAction(tr("\\n\\r"));
    project1Action->setCheckable(true);
    project2Action->setCheckable(true);
    project3Action->setCheckable(true);
    project4Action->setCheckable(true);
    project5Action->setCheckable(true);
    project4Action->setChecked(true);
   QActionGroup * m_MenuActionGroup = new QActionGroup(this);
    m_MenuActionGroup->addAction(project1Action);
    m_MenuActionGroup->addAction(project2Action);
    m_MenuActionGroup->addAction(project3Action);
    m_MenuActionGroup->addAction(project4Action);
    m_MenuActionGroup->addAction(project5Action);
    connect(project1Action, &QAction::triggered, this, [=](){
         sendType = sendNULL;
    });
    connect(project2Action, &QAction::triggered, this, [=](){
         sendType = sendReturn;
    });
    connect(project3Action, &QAction::triggered, this, [=](){
         sendType = sendLinFeed;
    });
    connect(project4Action, &QAction::triggered, this, [=](){
         sendType = sendReturnLinFeed;
    });
    connect(project5Action, &QAction::triggered, this, [=](){
        sendType = sendLinFeedReturn;
    });
    // SendTimerLineEdit set
    ui->sendPushButton->setMenu(menu);
}

/******Ui Sig*********/
void MainWindow::sendPushButtonSign()
{
    bool hexStatus =ui->hexSendPushButton->isChecked();
    if(false == ui->sendTextEdit->isEnabled())
    {
        mainThread_1->writeFile(currentFileName,ui->fileSizeSpinBox->text().toInt(),ui->fileTimerSpinBox->text().toInt());
        on_clearSendPushButton_clicked();
        return;
    }
   // L_LOG<<"111"<<ui->sendTextEdit->toHtml();
    QString oldHtml =ui->sendTextEdit->toHtml();
    QString newHtml;

    QString senddata = ui->sendTextEdit->toPlainText().toUtf8();
    senddata.replace("\n", "\r\n");
    //判断是否增加回车换行
    switch(sendType)
    {
        case  sendNULL:
            break;
        case  sendReturn:
             if(hexStatus == true)
              senddata += "0D";
             else
              senddata += "\r";
            break;
        case  sendLinFeed:
            if(hexStatus == true)
             senddata += "0A";
            else
            senddata += "\n";
            break;
        case  sendReturnLinFeed:
            if(hexStatus == true)
             senddata += "0D0A";
            else
            senddata += "\r\n";
            break;
        case  sendLinFeedReturn:
            if(hexStatus == true)
             senddata += "0A0D";
            else
            senddata += "\n\r";
            break;
        default:
            break;
    }
    serialPortSend(senddata,hexStatus);
}

void MainWindow::openPortPushButtonSig()
{
    if (isSerialOpen_1 == false || isSerialOpen_2 == false)
    {
        if(!isSerialOpen_1)
        {
            serialFirstCfg();
            mainThread_1->serialOpen();
        }
        if(!isSerialOpen_2 && isDefOrCom == true)
        {
            serialSecondCfg();
            mainThread_2->serialOpen();
        }

    }
    else
    {
        if(isSerialOpen_1)
        {
           mainThread_1->serialClose();
        }
        if(isSerialOpen_2 && isDefOrCom == true)
        {
            mainThread_2->serialClose();
        }
    }
}
/******Ui Fun*********/
void MainWindow::tabWidgetUpadata(int index)
{
    L_LOG << QString("%1").arg(index);
    static int lastActiveTab = 1;
    static bool minFlg = false;

    switch(index)
    {
        case -1:
            openPortPushButtonSig();
          break;
        default:
        L_LOG << QString("%1").arg(QString(ui->tabWidget_Main->currentIndex()));
        if(lastActiveTab == index)//缩小界面
        {
            if(minFlg == true)
            {
                QList<int> sizes;
                // 在保持比例的情况下，绝对值要尽量大
                sizes << 500 << 500;
                ui->splitter_4->setSizes(sizes);
            }
            else
            {
                QList<int> sizes;
                // 在保持比例的情况下，绝对值要尽量大
                sizes << 1 << 50000;
                ui->splitter_4->setSizes(sizes);
            }
            minFlg = !minFlg;
        }
        else
        {
            if(minFlg == true)
            {
                QList<int> sizes;
                // 在保持比例的情况下，绝对值要尽量大
                sizes << 500 << 500;
                ui->splitter_4->setSizes(sizes);
                minFlg = !minFlg;
            }
        }
        lastActiveTab = index;
        break;
    }
}

void MainWindow::serialFirstCfg()
{
    QString str = ui->SerialPortBox_1->currentText();
    QString itemNames;
    QStringList children = str.split("(");
    for (int i = 0; i < children.size(); i++)
    {
        QString child = children[i];
        int epos = child.indexOf(")");
        L_LOG << child << epos;
        if(epos >= 0)
        {
            itemNames = child.mid(0, epos);
        }
     }
     const QString portnameStr = itemNames;
     L_LOG << QString("%1").arg(portnameStr);
     QSerialPortInfo info(portnameStr);
     if(info.isBusy()){
         L_LOG<< "The serial port is occupied" <<portnameStr;
         return;
     }
     L_LOG << QString("set port end");

    //清空缓冲区
    serial_1->flush();
    //设置端口号
    serial_1->setPortName(portnameStr);
    //设置波特率
    serial_1->setBaudRate( static_cast<QSerialPort::BaudRate> (ui->baudRateBox_1->currentText().toInt()) );
    //设置停止位
    serial_1->setStopBits( static_cast<QSerialPort::StopBits> (ui->parityBitsBox_1->currentText().toInt()));
    //设置数据位
    serial_1->setDataBits( static_cast<QSerialPort::DataBits> (ui->dataBitsBox_1->currentText().toInt()));
    //设置校验
    serial_1->setParity( static_cast<QSerialPort::Parity>   (ui->parityBitsBox_1->currentText().toInt()));
    //设置流控
    serial_1->setFlowControl(QSerialPort::NoFlowControl);


}

void MainWindow::serialSecondCfg()
{
    QString str = ui->SerialPortBox_2->currentText();
    QString itemNames;
    QStringList children = str.split("(");
    for (int i = 0; i < children.size(); i++)
    {
        QString child = children[i];
        int epos = child.indexOf(")");
        L_LOG << child << epos;
        if(epos >= 0)
        {
            itemNames = child.mid(0, epos);
        }
     }
     const QString portnameStr = itemNames;
     L_LOG << QString("%1").arg(portnameStr);
     QSerialPortInfo info(portnameStr);
     if(info.isBusy()){
         L_LOG<< "The serial port is occupied" <<portnameStr;
         return;
     }
     L_LOG << QString("set port end");

    //清空缓冲区
    serial_2->flush();
    //设置端口号
    serial_2->setPortName(portnameStr);
    //设置波特率
    serial_2->setBaudRate( static_cast<QSerialPort::BaudRate> (ui->baudRateBox_2->currentText().toInt()) );
    //设置停止位
    serial_2->setStopBits( static_cast<QSerialPort::StopBits> (ui->parityBitsBox_2->currentText().toInt()));
    //设置数据位
    serial_2->setDataBits( static_cast<QSerialPort::DataBits> (ui->dataBitsBox_2->currentText().toInt()));
    //设置校验
    serial_2->setParity( static_cast<QSerialPort::Parity>   (ui->parityBitsBox_2->currentText().toInt()));
    //设置流控
    serial_2->setFlowControl(QSerialPort::NoFlowControl);
}

void MainWindow::listSendClicked(QString &str, bool &isHex)
{
    QString senddata = str;

    serialPortSend(str, isHex);

}

void MainWindow::on_showTextEdit_textChanged()
{
    ui->showTextEdit->moveCursor(QTextCursor::End);//光标移动到末尾
}

void MainWindow::serialPortSend(const QString &str,bool &hexSend)
{
   // QTextCursor cursor = ui->showTextEdit->textCursor();
  //  cursor.movePosition(QTextCursor::End);
 //   ui->showTextEdit->setTextCursor(cursor);
    QByteArray senddata = str.toUtf8();
    //判断是否有非16进制字符
    if(hexSend == true) //勾选了16进制发送
    {
        L_LOG<<111;
        if(isSerialOpen_1)
        {
            L_LOG<<122;
            mainThread_1->writeHex(senddata);
        }
        if(isDefOrCom == true)
        {
            L_LOG<<133;

            if(isSerialOpen_2)
            {
                L_LOG<<144;
                mainThread_2->writeHex(senddata);
            }
        }
    }
    else
    {
        if(isSerialOpen_1)
        {
            L_LOG<<22;
            mainThread_1->write(senddata);
        }
        L_LOG<<"isDefOrCom:"<<isDefOrCom;
        if(isDefOrCom == true)
        {
            L_LOG<<33;

            if(isSerialOpen_2)
            {
                L_LOG<<44;
                mainThread_2->write(senddata);
            }
        }
    }

}

void MainWindow::serialPortFirstCheck(bool)
{
    ui->SerialPortBox_1->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
         QString portName=QString("%1(%2)").arg(info.description()).arg(info.portName());
         ui->SerialPortBox_1->addItem(portName);
    }
    if (isSerialOpen_1)
    {
        mainThread_1->serialClose();
    }

}

void MainWindow::serialPortSecondCheck(bool)
{
    ui->SerialPortBox_2->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
         QString portName=QString("%1(%2)").arg(info.description()).arg(info.portName());
         ui->SerialPortBox_2->addItem(portName);
    }
    if (isSerialOpen_2)
    {
        mainThread_2->serialClose();
    }
}

void MainWindow::baudRateBoxFirstUpadta(const QString &tabName)
{
    serial_2->setBaudRate( static_cast<QSerialPort::BaudRate> (tabName.toInt()) );
    if (isSerialOpen_1)
    {
        mainThread_1->serialReOpen();
    }
}

void MainWindow::baudRateBoxSecondUpadta(const QString &tabName)
{
    serial_2->setBaudRate( static_cast<QSerialPort::BaudRate> (tabName.toInt()) );
    if (isSerialOpen_2)
    {
        mainThread_2->serialReOpen();
    }

}
/********************thread slots*********************/

void MainWindow::serialFirstOpen()
{
    L_LOG;
    isSerialOpen_1 = true;
    if(isSerialOpen_2 == true || isDefOrCom == false)
        ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/check/serial.png);}");
    else
        ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/check/serial_first.png);}");
}
void MainWindow::serialSecondOpen()
{
    L_LOG;
    isSerialOpen_2 = true;
    if(isSerialOpen_1 == true)
        ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/check/serial.png);}");
    else
        ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/check/serial_second.png);}");
}

void MainWindow::serialFirstClose()
{
    L_LOG;
    isSerialOpen_1 = false;
    if(isSerialOpen_2 == true && isDefOrCom == true)
        ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/check/serial_second.png);}");
    else
        ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/noCheck/serial.png);}");

}
void MainWindow::serialSecondClose()
{
    L_LOG;
    isSerialOpen_2 = false;
    if(isSerialOpen_1 == true)
        ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/check/serial_first.png);}");
    else
        ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/noCheck/serial.png);}");
}

void MainWindow::serialFirstWarning(QString &str)
{
    isSerialOpen_1 = false;
    L_LOG<<str;
    QMessageBox::critical(this, tr("Error"), str);
}

void MainWindow::serialSecondWarning(QString &str)
{
    isSerialOpen_1 = false;
    L_LOG<<str;
    QMessageBox::critical(this, tr("Error"), str);
}

void MainWindow::upadaQss(QString oldStr,QString newStr)
{
    QFile file(":/image/qss/default.qss");
    QString strAll;
    QStringList strList;
    if(file.open(QIODevice::ReadWrite |QIODevice::Text))
    {
            QTextStream stream(&file);
            strList=strAll.split("\n");           //以换行符为基准分割文本
            for(int i=0;i<strList.count();i++)    //遍历每一行
            {

                L_LOG<< QString("i");
                if(strList.at(i).contains(oldStr))    //"123456789"是要修改的内容
                {
                    L_LOG<< QString("1");
                    strList.at(i);

                    stream<<newStr<<'\n';
                    continue;
                }
                //如果没有找到要替换的内容，照常写入
                else
                {
                    L_LOG<< QString("123");

                    if(i==strList.count()-1)
                    {
                       stream<<strList.at(i);
                    }
                    else
                    {
                       stream<<strList.at(i)<<'\n';
                    }
                }
            }
    }
    else
    {
        L_LOG<< QString("open file");
    }
    file.close();

    qApp->setStyleSheet(file.readAll());

}

void MainWindow::serialFirstRecvData(QByteArray &str)
{
#if 1
    QByteArray senddata = str;
    char tmp =0x00;
    QString receive;
    receive=QString::fromStdString(senddata.toStdString());
    //ui->showTextEdit->setWordWrapMode(QTextOption::WrapAnywhere);自动换行
    if(ui->hexShowPushButton->isChecked() == true)
    {
       /*hex显示*/
       receive = senddata.toHex(' ').trimmed().toUpper();
       ui->showTextEdit->setTextColor(QColor(Qt::green));
    }
   receive.replace(tmp, QString("\\0"));//insertPlainText 0x00 is not displayed
   L_LOG << QString("[%1]").arg(receive);
   if(ui->timeShowPushButton->isChecked() == true)
   {
       QString time = QString("[%1]:Rx -> ").arg(QTime::currentTime().toString("HH:mm:ss:zzz"));

       ui->showTextEdit->append(time);
       ui->showTextEdit->moveCursor(QTextCursor::End);
       ui->showTextEdit->insertPlainText(receive);
   }
   else
   {
       ui->showTextEdit->moveCursor(QTextCursor::End);
       ui->showTextEdit->append(receive);
   }
   serialRecvData_1.clear();
   serialRecvData_1 = receive;
#endif
}
void MainWindow::serialSecondRecvData(QByteArray &str)
{
    L_LOG<<str;
#if 1
    QByteArray senddata = str;
    QString receive;
    receive=QString(senddata);
    //ui->showTextEdit_2->setWordWrapMode(QTextOption::WrapAnywhere);
    if(ui->hexShowPushButton->isChecked() == true)
    {
       /*hex显示*/
       receive = senddata.toHex(' ').trimmed().toUpper();
       ui->showTextEdit_2->setTextColor(QColor(Qt::green));
    }

   L_LOG << QString("[%1]").arg(receive);
   L_LOG << serialRecvData_1;
   if(ui->timeShowPushButton->isChecked() == true)
   {
       QString time = QString("[%1]:Rx -> ").arg(QTime::currentTime().toString("HH:mm:ss:zzz"));

       ui->showTextEdit_2->append(time);
       ui->showTextEdit_2->moveCursor(QTextCursor::End);
       if(serialRecvData_1 != receive)
       {
           // 先保存当前的文字颜色
           auto cur_text_color = ui->showTextEdit_2->textColor();
           // 设置当前行要使用的颜色，假设为红色
           ui->showTextEdit_2->setTextColor(Qt::red);
           L_LOG <<" 11111111111";

           // 写入一行内容
           QString str = u8"This a test line";
           ui->showTextEdit_2->insertPlainText(receive);

           // 最后恢复原来的颜色
           ui->showTextEdit_2->setTextColor(cur_text_color);
       }
       else
       {
           L_LOG <<" 22222222222";
           ui->showTextEdit_2->insertPlainText(receive);
       }
   }
   else
   {
       ui->showTextEdit_2->moveCursor(QTextCursor::End);
       if(serialRecvData_1 != receive)
       {
           // 先保存当前的文字颜色
           auto cur_text_color = ui->showTextEdit_2->textColor();
           // 设置当前行要使用的颜色，假设为红色
           ui->showTextEdit_2->setTextColor(Qt::red);
           L_LOG <<" 3333333333333333";

           // 写入一行内容
           QString str = u8"This a test line";
           ui->showTextEdit_2->append(receive);

           // 最后恢复原来的颜色
           ui->showTextEdit_2->setTextColor(cur_text_color);
       }
       else
       {
           L_LOG <<" 333333333333333";
           ui->showTextEdit_2->append(receive);
       }
   }
   ui->showTextEdit_2->moveCursor(QTextCursor::End);//光标移动到末尾

#endif
}
void MainWindow::serialFirstSendData(QByteArray &str)
{
    QTextCursor cursor = ui->showTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->showTextEdit->setTextCursor(cursor);
    QString receive;
    QString timer;
    QByteArray senddata = str;
    L_LOG << str;
    //发送至显示
    if(ui->txShowPushButton->isChecked() == true)
    {
        if(ui->timeShowPushButton->isChecked() == true)
        {
            timer = QString("[%1]:Tx -> ").arg(QTime::currentTime().toString("HH:mm:ss:zzz"));
        }

        if(ui->hexShowPushButton->isChecked())
        {
            /*hex显示*/
            receive = senddata.toHex(' ').trimmed().toUpper();
            ui->showTextEdit->setTextColor(QColor(Qt::green));
        }
        else
        {
            receive = QString(str);
        }
        receive = timer + receive;
        //ui->showTextEdit->setTextColor(cfgWidget->sendShowcolorValue());
        //在接受窗口显示收到的数据
       ui->showTextEdit->append(receive);
       //ui->showTextEdit->insertPlainText(receive);
    }
}
void MainWindow::serialSecondSendData(QByteArray &str)
{
    QTextCursor cursor = ui->showTextEdit_2->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->showTextEdit_2->setTextCursor(cursor);
    QString receive;
    QString timer;
    QByteArray senddata = str;
    L_LOG << str;

    //发送至显示
    if(ui->txShowPushButton->isChecked() == true)
    {
        if(ui->timeShowPushButton->isChecked() == true)
        {
            timer = QString("[%1]:Tx -> ").arg(QTime::currentTime().toString("HH:mm:ss:zzz"));
        }

        if(ui->hexShowPushButton->isChecked())
        {
            /*hex显示*/
            receive = senddata.toHex(' ').trimmed().toUpper();
            ui->showTextEdit_2->setTextColor(QColor(Qt::green));
        }
        else
        {
            receive = QString(str);
            ui->showTextEdit_2->setTextColor(QColor(Qt::black));
        }
        receive = timer + receive;
       ui->showTextEdit_2->append(receive);
    }
}

void MainWindow::on_rxShowPushButton_clicked()
{
    //打开rx会收到之前数据
     serial_1->readAll();
}

void MainWindow::on_fileSendPushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"选择文件","./", "Files(*.*)");
    // ui->sendTextEdit->clear();
    //ui->sendTextEdit->insertPlainText(fileName);
    if(fileName.isEmpty())
    {
        return;
    }

    QFile aFile(fileName);
    currentFileName = fileName;

    if(!aFile.exists())//如果文件不存在
    {
        return;
    }
    if(!aFile.open(QIODevice::ReadOnly |QIODevice::Text))//如果不是以只读和文本方式打开文件返回false
    {
        return;
    }

     QFileInfo file_info(fileName);
     QFileIconProvider icon_provider;
     QIcon icon = icon_provider.icon(file_info);
     QTextDocumentFragment fragment;
     QFile writeFile("F:/git/LCOM/image/svg/file.svg");
     L_LOG<< QString(writeFile.fileName());
     L_LOG<< QString(fileName);
#if 1
   // L_LOG<< QString("@@@ gb2312 str is:%1\n").arg(strGb2312.toLocal8Bit().data());
    // QTextCodec* utf8Codec= QTextCodec::codecForName("utf-8");
    // QTextCodec* gb2312Codec = QTextCodec::codecForName("gb2312");

    // QString strUnicode= gb2312Codec->toUnicode(strGb2312.toLocal8Bit().data());
    // QByteArray ByteUtf8= utf8Codec->fromUnicode(strUnicode);

    // char *utf8code = ByteUtf8.data();
    // printf("@@@ Utf8  strGb2312toUtf8:%s\n",utf8code);
     QString svgFileSize = QString("  <text transform=\"matrix(0.902189 0 0 1 6.59265 0)\" stroke=\"#000\" font-weight=\"normal\" xml:space=\"preserve\" text-anchor=\"start\" font-family=\"\'Yrsa\'\" font-size=\"24\" stroke-width=\"0\" id=\"svg_4\" y=\"50.27103\" x=\"65.18486\" fill=\"#A8FFE9\">%1</text>").arg(aFile.size());
     QString svgFileType = QString("  <text font-weight=\"bold\" xml:space=\"preserve\" text-anchor=\"start\" font-family=\"\'Yrsa\'\" font-size=\"30\" id=\"svg_7\" y=\"37.85699\" x=\"12.85699\" stroke-width=\"0\" stroke=\"#BBBBBB\" fill=\"#ffffff\">%1</text>").arg(file_info.suffix());
     QString svgFileName = QString("  <text style=\"cursor: move;\" xml:space=\"preserve\" text-anchor=\"start\" font-family=\"\'Yrsa\'\" font-size=\"15\" id=\"svg_13\" y=\"23.85699\" x=\"65.85699\" stroke-width=\"0\" stroke=\"#ffffff\" fill=\"#000000\">%1</text>>").arg(QString(file_info.fileName().toUtf8()));
     QString strAll;
     QStringList strList;
     QFile readFile("F:/git/LCOM/image/svg/file.svg");
     if(readFile.open((QIODevice::ReadOnly|QIODevice::Text)))
     {
         QTextStream stream(&readFile);
         strAll=stream.readAll();
     }
     if(writeFile.open(QIODevice::WriteOnly |QIODevice::Text))
     {
             QTextStream stream(&writeFile);
             strList=strAll.split("\n");           //以换行符为基准分割文本
             for(int i=0;i<strList.count();i++)    //遍历每一行
             {

                 L_LOG<< QString("i");
                 if(strList.at(i).contains("  <text transform"))    //"123456789"是要修改的内容
                 {
                     L_LOG<< QString("1");
                     strList.at(i);

                     stream<<svgFileSize<<'\n';
                     continue;
                 }
                 if(strList.at(i).contains("  <text font-weight"))    //"123456789"是要修改的内容
                 {                     L_LOG<< QString("2");
                     strList.at(i);

                     stream<<svgFileType<<'\n';
                     continue;
                 }
                 if(strList.at(i).contains("  <text style=\"cursor: move;\""))    //"123456789"是要修改的内容
                 {                     L_LOG<< svgFileName;
                    strList.at(i);
                     stream<<svgFileName<<'\n';
                     continue;
                 }
                 //如果没有找到要替换的内容，照常写入
                 else
                 {
                     L_LOG<< QString("123");

                     if(i==strList.count()-1)
                     {
                        stream<<strList.at(i);
                     }
                     else
                     {
                        stream<<strList.at(i)<<'\n';
                     }
                 }
             }
     }
     else
     {
         L_LOG<< QString("open file");
     }
     writeFile.close();
    this->update();
     ui->sendTextEdit->clear();
#endif
     QString path = QString("<img src=\"%1\" width=\"300\" height=\"60\">").arg("F:/git/LCOM/image/svg/file.svg");
     ui->sendTextEdit->setText(path);
     ui->sendTextEdit->setEnabled(false);//不可输入
    aFile.close();
}


void MainWindow::on_sendTextEdit_textChanged()
{
    QString senddata = ui->sendTextEdit->toPlainText();
    senddata.replace("\n", "\r\n");
    ui->inputStrLenLineEdit->setText(QString("%1").arg(senddata.length()));
}


void MainWindow::on_clearSendPushButton_clicked()
{
    ui->sendTextEdit->clear();
    if(false == ui->sendTextEdit->isEnabled())
    {
        ui->sendTextEdit->setEnabled(true);
    }
}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    if(arg1 != "Default")
    {
        setWindowsMode(true);
    }
    else
    {
        setWindowsMode(false);
    }
}


void MainWindow::on_serialOpenPushButton_1_clicked()
{
    if (isSerialOpen_1 == false)
    {
        if(!isSerialOpen_1)
        {
            serialFirstCfg();
            mainThread_1->serialOpen();
        }

    }
    else
    {
        if(isSerialOpen_1)
        {
           mainThread_1->serialClose();
        }
    }
}


void MainWindow::on_serialOpenPushButton_2_clicked()
{
    if (isSerialOpen_2 == false)
    {
        if(!isSerialOpen_2)
        {
            serialSecondCfg();
            isSerialOpen_2 = mainThread_2->serialOpen();
            if(isSerialOpen_2 == true)
            {
                ui->serialOpenPushButton_2->setCheckable(true);
            }
        }

    }
    else
    {
        if(isSerialOpen_2)
        {
            mainThread_2->serialClose();
            isSerialOpen_2=false;
        }
    }
}


