#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "framelessmainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : FramelessMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    setMouseTracking(true);
    ui->setupUi(this);
    setMouseTracking(true);
   // setwidget  = new setConfigWidget(this);
 //   setwidget->hide();
    recvTimer = new QTimer;
    recvTimer->setInterval(ui->timerSpinBox->text().toUInt());
    recvTimer->setSingleShot(true);//只运行一次
    sendTimer = new QTimer;
    sendTimer->setInterval(ui->SendTimerLineEdit->text().toUInt());
    serialCheckTimer = new QTimer;
    serialCheckTimer->setInterval(1000);//默认周期1000ms
    serialCheckTimer->setSingleShot(true);//只运行一次
    serial = new QSerialPort(this);
    connect(recvTimer,&QTimer::timeout,this,[=](){serialPortRecv();});
    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),  this, &MainWindow::serialPortErrorSign);
    connect(serialCheckTimer,&QTimer::timeout,this,[=](){serialCheckTimerSig();});
    connect(sendTimer,&QTimer::timeout,this,[=](){sendPushButtonSign();});

    connect(ui->sendPushButton,&QToolButton::clicked,this,&MainWindow::sendPushButtonSign);//发送数据
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::serialPortRecvSign);//接受串口数据
    //设置tabwidget位置
    connect(ui->comboBox,&LComboBox::clicked,this,&MainWindow::serialPortCheck);//串口显示框下拉刷新
    connect(ui->baudRateBox,&LComboBox::currentTextChanged,this,&MainWindow::baudRateBoxUpadta);//串口显示框下拉刷新
    ui->tabWidget_Main->setAttribute(Qt::WA_StyledBackground);
    ui->tabWidget_Main->setTabEnabled(0, false);
    connect(ui->tabWidget_Main, &QTabWidget::tabBarClicked, this ,&MainWindow::addWidget);

  //   connect(b2, &LPushButton::clicked, this ,&MainWindow::addWidget1);

    QList<int> sizes;
    // 在保持比例的情况下，绝对值要尽量大
    sizes << 500 << 500;
    ui->splitter_4->setSizes(sizes);
    resize(QSize(1611, 1139));
   this->setTitleBar(ui->tileWidget);
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
    QMenu* menu2 = menu->addMenu("回车换行");
   // menu2->addAction("回车换行",this,SLOT(actionsSlot()));

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
    // 为QToolButton设置菜单
    ui->sendPushButton->setMenu(menu);
    QRegExp rx2("^\\d\\d\\d\\d\\d\\d\\d\\d?$");
    ui->SendTimerLineEdit->setValidator(new QRegExpValidator(rx2,ui->SendTimerLineEdit));
    connect(ui->widget_2,&LListWidget::sendDataClicked,this,&MainWindow::listSendClicked);
}

MainWindow::~MainWindow()
{
    if (isSerialOpen)
    {
        serial->close();
    }
    delete ui;
}

void MainWindow::addWidget(int index)
{
    qDebug() << QString("%1").arg(index);
    static int lastActiveTab = 1;
    static bool minFlg = false;

    switch(index)
    {
        case -1:
            openPortPushButtonSig();
          break;
        default:
        qDebug() << QString("%1").arg(QString(ui->tabWidget_Main->currentIndex()));
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

void MainWindow::addWidget1()
{

}

void MainWindow::listSendClicked(QString &str, bool &isHex)
{
    QString senddata = str;

    serialPortSend(str, isHex);

}



void MainWindow::on_showTextEdit_textChanged()
{
    ui->showTextEdit->moveCursor(QTextCursor::End);
}

void MainWindow::serialPortSend(const QString &str,bool &hexSend)
{
    QTextCursor cursor = ui->showTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->showTextEdit->setTextCursor(cursor);
    QByteArray senddata = str.toUtf8();
    QByteArray showdata = str.toUtf8();

    QString receive;

    //判断是否有非16进制字符
    if(hexSend == true) //勾选了16进制发送
    {
        int cnt = senddata.size();          //要发送数据的长度
        char *data = senddata.data();
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
                QMessageBox::warning(NULL , "提示", "输入非16进制字符！");
                return;
            }
        }

        //字符串转化为16进制数   "1234" --> 0X1234
        //转换时会自动除去非16进制字符
            senddata = senddata.fromHex(senddata);
          //  senddata = senddata.toHex();  //313131-->3
    }
    else
    {

    }
    qDebug() << QString("%1").arg(QString(senddata));

    //通过串口发送数据
    serial->write(senddata);

    //发送至显示
    if(ui->txShowPushButton->isChecked() == true)
    {
        if(hexSend != true)
            receive = QString(senddata);
        else
        {
            //showdata = senddata.toUtf8();
            receive = QString(senddata).toUtf8();
        }
        if(ui->timeShowPushButton->isChecked() == true)
        {
            receive = QString("[%1]:Tx -> %2").arg(QTime::currentTime().toString("HH:mm:ss:zzz")).arg(receive);
        }

        if(ui->hexShowPushButton->isChecked())
        {
            /*hex显示*/
            receive = senddata.toHex(' ').trimmed().toUpper();
            ui->showTextEdit->setTextColor(QColor(Qt::green));
        }
        //ui->showTextEdit->setTextColor(cfgWidget->sendShowcolorValue());
        //在接受窗口显示收到的数据
       ui->showTextEdit->append(receive);
       //ui->showTextEdit->insertPlainText(receive);
    }

}

void MainWindow::serialPortRecv()
{
     QByteArray buffer = serial->readAll();
     QByteArray senddata = QString(buffer).toUtf8();
     QString receive;
     receive=QString(senddata);
     if(ui->timeShowPushButton->isChecked() == true)
     {
        receive = QString("\r\n[%1]:Rx -> %2").arg(QTime::currentTime().toString("HH:mm:ss:zzz")).arg(receive);
     }

     if(ui->hexShowPushButton->isChecked() == true)
     {
        /*hex显示*/
        receive = senddata.toHex(' ').trimmed().toUpper();
        ui->showTextEdit->setTextColor(QColor(Qt::green));
        QString str = "\r\n";
        ui->showTextEdit->insertPlainText(str);
     }
     //ui->showTextEdit->setTextColor(cfgWidget->recvShowcolorValue());
     //在接受窗口显示收到的数据
     ui->showTextEdit->insertPlainText(receive);

}

void MainWindow::serialPortRecvSign()
{
    if(ui->rxShowPushButton->isChecked() == true)
    {
        if(!recvTimer->isActive()) //勾选了16进制发送
        {
           recvTimer->start(ui->timerSpinBox->text().toUInt());//启动周期发送定时器
        }
    }
}

void MainWindow::serialPortErrorSign(QSerialPort::SerialPortError error)
{
     qDebug() << QString("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%1").arg(error);
    if ((error == QSerialPort::PermissionError) ||   (isSerialOpen == true)) {
        reCheckFlag = 0;
        serialCheckTimer->start(1000);
    }
}

void MainWindow::serialCheckTimerSig()
{
    if(reCheckFlag == 0)
    {
       //关闭
       qDebug() << QString("close");
       serial->close();
      // QMessageBox::critical(this, tr("Error"), "串口连接中断，请检查是否正确连接！");
       ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/noCheck/serial.png);}");
       serialCheckTimer->start(1000);
       isSerialOpen = false;
       reCheckFlag++;
    }
    else if(reCheckFlag == MAX_CHECK_FLAG)
    {
        serialCheckTimer->stop();
        reCheckFlag = 0;
        return;
    }
    else
    {
        //达到最大次数，则停止
        qDebug() << QString("check open");
        QString str = ui->comboBox->currentText();
        QString itemNames;
        QStringList children = str.split("(");
        for (int i = 0; i < children.size(); i++)
        {
            QString child = children[i];
            int epos = child.indexOf(")");
            qDebug() << child << epos;
            if(epos >= 0)
            {
                itemNames = child.mid(0, epos);
            }
         }
         const QString portnameStr = itemNames;
         qDebug() << QString("%1").arg(portnameStr);
         QSerialPortInfo info(portnameStr);
         if(info.isBusy()){
             qDebug()<< "The serial port is occupied" <<portnameStr;
             return;
         }
         qDebug() << QString("set port end");

         //清空缓冲区
         serial->flush();
         //设置端口号
         serial->setPortName(portnameStr);
         //设置波特率
         serial->setBaudRate( static_cast<QSerialPort::BaudRate> (ui->baudRateBox->currentText().toInt()) );
         //设置停止位
         serial->setStopBits( static_cast<QSerialPort::StopBits> (ui->parityBitsBox->currentText().toInt()));
         //设置数据位
         serial->setDataBits( static_cast<QSerialPort::DataBits> (ui->dataBitsBox->currentText().toInt()));
         //设置校验
         serial->setParity( static_cast<QSerialPort::Parity>   (ui->parityBitsBox->currentText().toInt()));
         //设置流控
         serial->setFlowControl(QSerialPort::NoFlowControl);
         qDebug() << QString("set port end");
         isSerialOpen = serial->open(QIODevice::ReadWrite);
         if (!isSerialOpen) {
             qDebug()<< QString("Failed to open serial port:") << portnameStr << serial->errorString();
             serial->clearError();
             ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/noCheck/serial.png);}");
             serialCheckTimer->start(1000);
             reCheckFlag++;
         }
         else {
             ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/check/serial.png);}");
             qDebug()<< QString("The serial port is open: ") <<portnameStr;
             serialCheckTimer->stop();
             reCheckFlag = 0;
         }
    }
}

void MainWindow::sendPushButtonSign()
{
    bool hexStatus =ui->hexSendPushButton->isChecked();
    QString senddata = ui->sendTextEdit->toPlainText().toUtf8();
    senddata.replace("\n", "\r\n");
    //判断是否增加回车换行
    switch(sendType)
    {
        case  sendNULL:
            break;
        case  sendReturn:
            senddata += "\r";
            break;
        case  sendLinFeed:
            senddata += "\n";
            break;
        case  sendReturnLinFeed:
            senddata += "\r\n";
            break;
        case  sendLinFeedReturn:
            senddata += "\n\r";
            break;
        default:
            break;
    }
    serialPortSend(senddata,hexStatus);

}

void MainWindow::serialPortCheck(bool)
{
    ui->comboBox->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
         QString portName=QString("%1(%2)").arg(info.description()).arg(info.portName());
         ui->comboBox->addItem(portName);
    }
}

void MainWindow::baudRateBoxUpadta(const QString &tabName)
{
    serial->setBaudRate( static_cast<QSerialPort::BaudRate> (tabName.toInt()) );
    if (isSerialOpen)
    {
        serial->open(QIODevice::ReadWrite);
        serial->close();
    }

}

void MainWindow::openPortPushButtonSig()
{
    if(serialCheckTimer->isActive() == true)
    {
        serialCheckTimer->stop();
    }

    if (isSerialOpen == false) {
       QString str = ui->comboBox->currentText();
       QString itemNames;
       QStringList children = str.split("(");
       for (int i = 0; i < children.size(); i++)
       {
           QString child = children[i];
           int epos = child.indexOf(")");
           qDebug() << child << epos;
           if(epos >= 0)
           {
               itemNames = child.mid(0, epos);
           }
        }
        const QString portnameStr = itemNames;
        qDebug() << QString("%1").arg(portnameStr);
        QSerialPortInfo info(portnameStr);
        if(info.isBusy()){
            qDebug()<< "The serial port is occupied" <<portnameStr;
            return;
        }
        qDebug() << QString("set port end");

        //清空缓冲区
        serial->flush();
        //设置端口号
        serial->setPortName(portnameStr);
        //设置波特率
        serial->setBaudRate( static_cast<QSerialPort::BaudRate> (ui->baudRateBox->currentText().toInt()) );
        //设置停止位
        serial->setStopBits( static_cast<QSerialPort::StopBits> (ui->parityBitsBox->currentText().toInt()));
        //设置数据位
        serial->setDataBits( static_cast<QSerialPort::DataBits> (ui->dataBitsBox->currentText().toInt()));
        //设置校验
        serial->setParity( static_cast<QSerialPort::Parity>   (ui->parityBitsBox->currentText().toInt()));
        //设置流控
        serial->setFlowControl(QSerialPort::NoFlowControl);
        qDebug() << QString("set port end");
        isSerialOpen = serial->open(QIODevice::ReadWrite);
        if (!isSerialOpen) {
            QMessageBox::critical(this, tr("ERROR"), QString("串口连接中断，请检查是否正确连接！\r\n%1\r\n%2").arg(portnameStr).arg(serial->errorString()));
            qDebug()<< QString("Failed to open serial port:") << portnameStr << serial->errorString();
            serial->clearError();
            ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/noCheck/serial.png);}");
        }
        else {
            ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/check/serial.png);}");
            qDebug()<< QString("The serial port is open: ") <<portnameStr;
        }

    }
    else {
         ui->tabWidget_Main->setStyleSheet("QTabBar::tab:first{image: url(:/image/noCheck/serial.png);}");
         serial->close();
         isSerialOpen=false;
    }
}

void MainWindow::on_rxShowPushButton_clicked()
{
    //打开rx会收到之前数据
     serial->readAll();
}


void MainWindow::on_widgetSetPushButton_clicked()
{
//   setwidget->show();
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

    if(!aFile.exists())//如果文件不存在
    {
        return;
    }
    if(!aFile.open(QIODevice::ReadOnly |QIODevice::Text))//如果不是以只读和文本方式打开文件返回false
    {
        return;
    }
    ui->sendTextEdit->setPlainText(aFile.readAll());
    //isSendFile = true;
}


void MainWindow::on_sendTextEdit_textChanged()
{
    QString senddata = ui->sendTextEdit->toPlainText();
    senddata.replace("\n", "\r\n");
    ui->inputStrLenLineEdit->setText(QString("%1").arg(senddata.length()));
}

