#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUiCfg();
    initSigCfg();
   // this->setWindowFlags(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUiCfg()
{
    cfgWidget = new conifg;
    serial = new QSerialPort(this);
    PriecSendTimer = new QTimer;
    PriecSendTimer->setInterval(1000);//默认周期1000ms
    recvTimer = new QTimer;
    recvTimer->setInterval(cfgWidget->timerSpinBoxCount());
    recvTimer->setSingleShot(true);//只运行一次
    serialCheckTimer = new QTimer;
    serialCheckTimer->setInterval(1000);//默认周期1000ms
    serialCheckTimer->setSingleShot(true);//只运行一次
    tableName = new QStringList;
    sqlist = new SqlList("F:/lscom.db");
    ui->loopSendSpinBox->setMaximum(60*60*24*1000);
    ui->loopSendSpinBox->setMinimum(100);
    ui->loopSendSpinBox->setSuffix("ms");
    ui->loopSendSpinBox->setSingleStep(100);
    ui->loopSendSpinBox->setValue(1000);
    initTabwidget();
    //this->setStyleSheet("background-color:red;");
}

void MainWindow::initSigCfg()
{
    connect(ui->expandTabPushButton,&QPushButton::clicked,this,&MainWindow::expandTabWigetSign); //展开
    connect(ui->setMenuPushButton,&QPushButton::clicked,this,&MainWindow::setMenuPushButtonSign);//设置界面
    connect(ui->openPortPushButton,&QPushButton::clicked,this,&MainWindow::openPortPushButtonSig);//打开串口
    connect(ui->sendPushButton,&myQPushButton::leftButtonClicked,this,&MainWindow::sendPushButtonSign);//发送数据
    connect(ui->sendPushButton,&myQPushButton::rightButtonClicked,this,&MainWindow::sendPushButtonRightSign);//切换发送数据方式
    connect(ui->loopSendPushButton,&QPushButton::clicked,this,&MainWindow::loopSendPushButtonSign);//循环发送
    connect(ui->loopSendListPushButton,&QPushButton::clicked,this,&MainWindow::loopSendListPushButtonSign);//列表循环发送
    connect(ui->addTabPushButton,&QPushButton::clicked,this,&MainWindow::addTabPushButtonSig);//添加tab
    connect(ui->savePushButton,&QPushButton::clicked,this,&MainWindow::savePushButtonSig);//保存tab
    connect(ui->openFilePushButton,&QPushButton::clicked,this,&MainWindow::openFilePushButtonSig);//打开文件
    connect(ui->lodaPushButton,&QPushButton::clicked,this,&MainWindow::lodaPushButtonSig);//打开数据库
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::serialPortRecvSign);//接受串口数据
    connect(ui->comComboBox,&myQComboBox::clicked,this,&MainWindow::serialPortCheck);//串口显示框下拉刷新
    connect(PriecSendTimer,&QTimer::timeout,this,[=](){timerTimeoutSig();});//定时器槽关联,关联至发送按钮槽函数，即定时到来时，自动发送数据
    connect(recvTimer,&QTimer::timeout,this,[=](){serialPortRecv();});
    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),  this, &MainWindow::serialPortErrorSign);
    connect(serialCheckTimer,&QTimer::timeout,this,[=](){serialCheckTimerSig();});
}

void MainWindow::sendPushButtonSign()
{
    if(isSerialOpen == false)
    {
        serialCheckTimer->start(1000);
        return;
    }
    bool hexStatus =((ui->sendPushButton->text() == "发送(Hex\\r\\n)") || (ui->sendPushButton->text() == "发送(Hex)") );
    serialPortSend(ui->sendTextEdit->toPlainText().toUtf8(),hexStatus);
    if(isSendFile == true)
    {
        ui->sendTextEdit->clear();
        isSendFile = false;
    }
}

void MainWindow::sendPushButtonRightSign()
{
#if 0
    QMenu* pMenu = new QMenu(this);
   // ui->sendPushButton->setMenu(pMenu);
    QAction* buttonAction1 = new QAction("发送(S\\r\\n)",this);
    QAction* buttonAction2 = new QAction("发送(S)",this);
    QAction* buttonAction3 = new QAction("发送(Hex)",this);
    QAction* buttonAction4 = new QAction("发送(Hex\\r\\n)",this);
    pMenu->addAction(buttonAction1);
    pMenu->addAction(buttonAction2);
    pMenu->addAction(buttonAction3);
    pMenu->addAction(buttonAction4);
   // QWidget *pWindow = this->window();
    int x=ui->sendPushButton->geometry().x();
    int y=ui->sendPushButton->geometry().y();
    QPoint pos(x,y);
    pMenu->exec(mapToGlobal(pos));
    pMenu->show();
    //给动作设置信号槽
    connect( buttonAction1, &QAction::triggered, [=]()
    {
        ui->sendPushButton->setText("发送(S\\r\\n)");
        pMenu->hide();
    });
    connect( buttonAction2, &QAction::triggered, [=]()
    {
        ui->sendPushButton->setText("发送(S)");
        pMenu->hide();
    });
    connect( buttonAction3, &QAction::triggered, [=]()
    {
        ui->sendPushButton->setText("发送(Hex)");
        pMenu->hide();
    });
    connect( buttonAction4, &QAction::triggered, [=]()
    {
        ui->sendPushButton->setText("发送(Hex\\r\\n)");
        pMenu->hide();
    });
#else
    if(ui->sendPushButton->text() == "发送(S\\r\\n)")
    {
        ui->sendPushButton->setText("发送(S)");
    }
    else if(ui->sendPushButton->text() == "发送(S)送")
    {
        ui->sendPushButton->setText("发送(Hex)");
    }
    else if(ui->sendPushButton->text() == "发送(Hex)")
    {
       ui->sendPushButton->setText("发送(Hex\\r\\n)");
    }
    else
    {
       ui->sendPushButton->setText("发送(S\\r\\n)");
    }
#endif

}

void MainWindow::setMenuPushButtonSign(bool checked)
{
    cfgWidget->show();
}

void MainWindow::expandTabWigetSign(bool checked)
{
    if(checked == true)
    {
        ui->righGroupBox->hide();
        ui->expandTabPushButton->setStyleSheet(tr("image: url(:/image/closeTab.png);"));
    }
    else
    {
         ui->righGroupBox->show();
         ui->expandTabPushButton->setStyleSheet(tr("image: url(:/image/openTab.png);"));
    }
}

void MainWindow::openPortPushButtonSig()
{
    if (ui->openPortPushButton->text() == QString("打开")) {

        QString str = ui->comComboBox->currentText();
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

        QSerialPortInfo info(portnameStr);
        if(info.isBusy()){
            qDebug()<< "The serial port is occupied" <<portnameStr;
            return;
        }

        ui->openPortPushButton->setText("关闭");
        //清空缓冲区
        serial->flush();
        //设置端口号
        serial->setPortName(portnameStr);
        //设置波特率
        serial->setBaudRate( static_cast<QSerialPort::BaudRate> (ui->baudRateBox->currentText().toInt()) );
        //设置停止位
        serial->setStopBits( static_cast<QSerialPort::StopBits> (cfgWidget->parityBitsBoxCountStr().toInt()));
        //设置数据位
        serial->setDataBits( static_cast<QSerialPort::DataBits> (cfgWidget->dataBitsBoxCountStr().toInt()));
        //设置校验
       serial->setParity( static_cast<QSerialPort::Parity>   (cfgWidget->parityBitsBoxCountStr().toInt()));
        //设置流控
        serial->setFlowControl(QSerialPort::NoFlowControl);

        isSerialOpen = serial->open(QIODevice::ReadWrite);
        if (!isSerialOpen) {
            QMessageBox::critical(this, tr("ERROR"), QString("串口连接中断，请检查是否正确连接！\r\n%1\r\n%2").arg(portnameStr).arg(serial->errorString()));
            qDebug()<< QString("Failed to open serial port:") << portnameStr << serial->errorString();
            serial->clearError();
            ui->openPortPushButton->setText("打开");
        }
        else {
            qDebug()<< QString("The serial port is open: ") <<portnameStr;
        }
    }
    else {
         ui->openPortPushButton->setText("打开");
         serial->close();
         isSerialOpen=false;
    }
}

void MainWindow::addTabPushButtonSig()
{
    //  bool checkTableNameFlag = false;
    qDebug() << "is exist";
    while(1)
    {
       bool ok;
       QString text = QInputDialog::getText(this, tr("新增Tab"),tr("请输入表名:不能重复"), QLineEdit::Normal,0, &ok);
       if(ok && !text.isEmpty())
       {
          if(tableName->contains(text))
          {
              qDebug() << text << "is exist";
              text = QInputDialog::getText(this, tr("新增Tab"),tr("请输入表名:不能重复"), QLineEdit::Normal,0, &ok);
          }
          else
          {
              tableName->append(text);
              qDebug() << text << "set success";
              break;
          }
      }
      else
      {
          return;
      }
    }
    sqlist->createSqlTable(tableName->last());
    createTabWidget(tableName->last());
}

void MainWindow::savePushButtonSig()
{
    //ui->tabWidget->currentIndex();
        //QTableWidget * tableWidget = (QTableWidget *)(widget->layout()->widget());
        if(1)
        {
            for(int i = 0;i < ui->tabWidget->count(); i++)
            {
                QWidget * widget = ui->tabWidget->widget(i);
                QGridLayout *layout = (QGridLayout *)(widget->layout());
                QLayoutItem* pLayout = layout->itemAtPosition(0, 0);
                 QTableWidget * tableWidget = (QTableWidget *)( pLayout->widget());


                    for(int row=0; row < tableWidget->rowCount(); row++)
                    {
                         QCheckBox *hexCheckBox=   (QCheckBox *)(tableWidget->cellWidget(row, 0));
                         QLineEdit *sendStrButton = (QLineEdit *)(tableWidget->cellWidget(row,2));

                         QLineEdit *queueSpinBox=  (QLineEdit *)(tableWidget->cellWidget(row,3));


                         QSpinBox *timeSpinBox=  (QSpinBox *)(tableWidget->cellWidget(row,4));
                         QString tab =tableWidget->windowTitle();
                         bool hex = hexCheckBox->isChecked();
                         QString str = tableWidget->item(row,1)->text();
                         QString sendStr = sendStrButton->text();
                         int queue = queueSpinBox->text().toInt();
                         int time = timeSpinBox->text().toInt();
                         //qDebug() << QString("hex %1,str: %2,queue %3,timer %4").arg(hexCheckBox->isChecked()).arg(tableWidget->item(row,1)->text()).arg(queueSpinBox->value()).arg(timeSpinBox->value());
                         qDebug() << QString("tab %6,hex %1,str %2,sendStr %3,queue %4,timer %5").arg(hex).arg(str).arg(sendStr).arg(queue).arg(time).arg(tab);
                         sqlist->alterSqlTableInfo(tab,row+1,hex,str,sendStr,queue,time);
                         sqlist->selectTableLineInfo(tab,row,hex,str,sendStr,queue,time);
                    }


           }
        }
}

void MainWindow::listSendPushButtonSig()
{
    if(isSerialOpen == false)
    {
        serialCheckTimer->start(1000);
        return;
    }
    QWidget * widget = ui->tabWidget->widget(ui->tabWidget->currentIndex());
    QGridLayout *layout = (QGridLayout *)(widget->layout());
    QLayoutItem* pLayout = layout->itemAtPosition(0, 0);
    QTableWidget * tableWidget = (QTableWidget *)( pLayout->widget());

    int row = tableWidget->currentRow();
    QCheckBox *hexCheckBox=(QCheckBox *)(tableWidget->cellWidget(row, 0));
    bool hex = hexCheckBox->isChecked();
    QString str = tableWidget->item(row,1)->text();
    serialPortSend(str.toUtf8(),hex);
}

void MainWindow::listSendSetPushButtonSig()
{
    //  bool checkTableNameFlag = false;
    qDebug() << "is exist";
    while(1)
    {
       bool ok;
       QString text = QInputDialog::getText(this, tr("备注"),tr("请输入备注:"), QLineEdit::Normal,0, &ok);
       if(ok && !text.isEmpty())
       {
           sqlist->createSqlTable(tableName->last());
           createTabWidget(tableName->last());
           QWidget * widget = ui->tabWidget->widget(ui->tabWidget->currentIndex());
           QGridLayout *layout = (QGridLayout *)(widget->layout());
           QLayoutItem* pLayout = layout->itemAtPosition(0, 0);
           QTableWidget * tableWidget = (QTableWidget *)( pLayout->widget());

           int row = tableWidget->currentRow();
           QPushButton *sendStrButton = (QPushButton *)(tableWidget->cellWidget(row,2));
           sendStrButton->setText(text);
           return;

       }
      else
      {
          return;
      }
    }


}

void MainWindow::loopSendPushButtonSign()
{
    if(isSerialOpen == false)
    {
        serialCheckTimer->start(1000);
        return;
    }
    if(ui->loopSendPushButton->isChecked()==true) //勾选了16进制发送
    {
       PriecSendTimer->start(ui->loopSendSpinBox->value());//启动周期发送定时器
       ui->loopSendSpinBox->setEnabled(false);//失能周期输入文本框
   }
   else
   {
       PriecSendTimer->stop();//关闭定时器
       ui->loopSendSpinBox->setEnabled(true);//使能周期输入文本框
    }
}

void MainWindow::loopSendListPushButtonSign()
{
    if(isSerialOpen == false)
    {
        serialCheckTimer->start(1000);
        return;
    }
    if(ui->loopSendListPushButton->isChecked()==true)
    {
       loopListCount = 1;
       savePushButtonSig();
       PriecSendTimer->start(1000);//启动周期发送定时器
       ui->loopSendSpinBox->setEnabled(false);//失能周期输入文本框
   }
   else
   {
       loopListCount = 1;
       PriecSendTimer->stop();//关闭定时器
       ui->loopSendSpinBox->setEnabled(true);//使能周期输入文本框
    }
}

void MainWindow::serialPortCheck(bool)
{
    ui->comComboBox->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
         QString portName=QString("%1(%2)").arg(info.description()).arg(info.portName());
         ui->comComboBox->addItem(portName);
    }
}

void MainWindow::serialPortSend(const QString &str,bool &hexshow)
{
    QTextCursor cursor = ui->showTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->showTextEdit->setTextCursor(cursor);
        QByteArray senddata = str.toUtf8();
        QString receive;
        //判断是否有非16进制字符
        if(hexshow == true) //勾选了16进制发送
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
        }
        receive=QString(senddata);
      //  if (ui->timeDispCheckBox->isChecked() == true
        if(cfgWidget->timeDispEnable() == true)
        {
            receive = QString("[%1]:Tx -> %2").arg(QTime::currentTime().toString("HH:mm:ss:zzz")).arg(receive);
        }

        if(ui->hexShowPushButton->isChecked())
        {
            /*hex显示*/
            receive = senddata.toHex(' ').trimmed().toUpper();
            ui->showTextEdit->setTextColor(QColor(Qt::green));
        }
        ui->showTextEdit->setTextColor(cfgWidget->sendShowcolorValue());
         //在接受窗口显示收到的数据
        ui->showTextEdit->insertPlainText(receive);
        //通过串口发送数据
        serial->write(senddata);
        //勾选了发送新行
        if((ui->sendPushButton->text() == "发送(S\\r\\n)") || (ui->sendPushButton->text() == "发送(Hex\\r\\n)"))
        {
           ui->showTextEdit->insertPlainText("\r\n");
           serial->write("\r\n");
        }
}

void MainWindow::serialPortRecv()
{
     // bool hexStatus = ui->hexSendCheckBox->isChecked();
     // serialPortSend(ui->sendTextEdit->toPlainText().toUtf8(),hexStatus);
     //从接收缓冲区中读取数据
     QByteArray buffer = serial->readAll();

     //界面中读取的数据中加入刚读取的数据
     //QString recv = QString(buffer);

    // ui->showTextEdit->insertPlainText(recv);
    // serialPortSend(recv,(bool)false);
     QByteArray senddata = QString(buffer).toUtf8();
     QString receive;
     receive=QString(senddata);
     if(cfgWidget->timeDispEnable() == true)
     {
        receive = QString("[%1]:Rx -> %2").arg(QTime::currentTime().toString("HH:mm:ss:zzz")).arg(receive);
     }

     if(ui->hexShowPushButton->isChecked())
     {
        /*hex显示*/
        receive = senddata.toHex(' ').trimmed().toUpper();
        ui->showTextEdit->setTextColor(QColor(Qt::green));
     }
     ui->showTextEdit->setTextColor(cfgWidget->recvShowcolorValue());
     //在接受窗口显示收到的数据
     ui->showTextEdit->insertPlainText(receive);
}

void MainWindow::serialPortRecvSign()
{
    if(!recvTimer->isActive()) //勾选了16进制发送
    {
       recvTimer->start(cfgWidget->timerSpinBoxCount());//启动周期发送定时器
    }
}

void MainWindow::serialPortErrorSign(QSerialPort::SerialPortError error)
{
     qDebug() << QString("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%1").arg(error);
    if (error == QSerialPort::PermissionError) {
        serialCheckTimer->start(1000);
    }
}

void MainWindow::serialCheckTimerSig()
{
    if(isSerialOpen == true)
    {
        qDebug() << QString("close");
       serial->close();
      // QMessageBox::critical(this, tr("Error"), "串口连接中断，请检查是否正确连接！");
       ui->openPortPushButton->setText("打开");
       serialCheckTimer->start(1000);
       isSerialOpen = false;
    }
    else
    {
        qDebug() << QString("open");
        serialCheckTimer->stop();
        openPortPushButtonSig();
    }
}

void MainWindow::initTabwidget()
{
    //检查数据库
    sqlist->checkSqlTableAll(tableName);
    createTableWiget(ui->tableWidget,tableName->first());
    qDebug() << QString("create table %1").arg(tableName->first());

    //创建
    for(int i = 1;i < tableName->size();++i)
    {
      qDebug() << QString("create table %1").arg(tableName->at(i));
      createTabWidget(tableName->at(i));
    }

}

void MainWindow::createTabWidget(const QString &name)
{
    QWidget * widget = new QWidget();
    ui->tabWidget->addTab(widget,name);
    QTableWidget * tableWidget = new QTableWidget(widget);
    createTableWiget(tableWidget,name);
    QGridLayout *layout = new QGridLayout;
    //向 layout 中添加控件，并指定各个控件的位置
    layout->addWidget(tableWidget, 0, 0);
    //将 layout 添加到 widget 窗口中
    widget->setLayout(layout);
}

void MainWindow::createTableWiget(QTableWidget *tableWidget, const QString &name)
{
    tableWidget->setWindowTitle(name);  //表名
  //tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //表格禁止编辑
  //tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
  //设置行列数
  tableWidget->setColumnCount(5);
  tableWidget->setRowCount(0);
  //设置每列宽
   ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
   ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
   ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
   ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
   ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
   ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Interactive);
   ui->tableWidget->verticalHeader()->setDefaultSectionSize(10);
   //ui->tableWidget->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
   tableWidget->setColumnWidth(0,10);
   tableWidget->setColumnWidth(1,10);
   tableWidget->setColumnWidth(2,10);
   tableWidget->setColumnWidth(3,70);
   tableWidget->setColumnWidth(4,70);
   tableWidget->setColumnWidth(4,70);
  //设置表头
  QStringList header;
  header.append(QObject::tr("HEX"));
  header.append(QObject::tr("字符串"));
  header.append(QObject::tr("点击发送"));
  header.append(QObject::tr("顺序"));
  header.append(QObject::tr("延时(ms)"));
  tableWidget->setHorizontalHeaderLabels(header);


  int row = tableWidget->rowCount(); //获取表格行数
  // ui->tableWidget->setRowCount(row+1);  //表格加一行

  for(int i = 1; i <= 50;i++)
  {
      bool hex;
      QString str;
      QString sendStr;
      int queue;
      int time;

      sqlist->selectTableLineInfo(name,i,hex,str,sendStr,queue,time);
      qDebug() << QString("id: %1, hex: %2 ,str: %3,queue: %4, time: %5").arg(i).arg(hex).arg(str).arg(sendStr).arg(queue);
      row = tableWidget->rowCount();
      tableWidget->setRowCount(i);  //表格加一行
      QCheckBox *checkBox = new QCheckBox();
      tableWidget->setCellWidget(row,0,checkBox);
      if(hex == true)
      {
          checkBox->setCheckState(Qt::Checked);
      }
      else
      {
          checkBox->setCheckState(Qt::Unchecked);
      }
      QTableWidgetItem *tableWidgetItem1 = new QTableWidgetItem(str);
      tableWidget->setItem(row, 1, tableWidgetItem1);

      myQPushButton *button = new myQPushButton();
      button->setText(sendStr);
      button->setEnabled(true);
      tableWidget->setCellWidget(row,2,button);
      button->setStyleSheet("QPushButton{background-color:rgba(100,225,100,30);border-style:outset;border-width:8px;border-radius:20px;border-color:rgba(255,255,255,30);font:bold 15px;color:rgb(0,0,0);padding:6px;}\
                            QPushButton:pressed{background-color:rgba(100,255,100,200);border-color:rgba(255,255,255,30);border-style:inset;color:rgba(0,0,0,100);}\QPushButton:hover{border-color:rgba(255,255,255,200);color:rgba(0,0,0,200);}");
      connect(button,&myQPushButton::leftButtonClicked,this,&MainWindow::listSendPushButtonSig);
      connect(button,&myQPushButton::rightButtonClicked,this,&MainWindow::listSendSetPushButtonSig);

      QLineEdit * queueLine = new QLineEdit;
      tableWidget->setCellWidget(row,3,queueLine);
      QRegExp rx1("^\\d\\d?$");
      queueLine->setValidator(new QRegExpValidator(rx1,queueLine));
      queueLine->setText(QString("%1").arg(queue));

      QLineEdit * msLine = new QLineEdit;
      tableWidget->setCellWidget(row,4,msLine);
      QRegExp rx2("^\\d\\d\\d\\d\\d\\d\\d\\d?$");
      msLine->setValidator(new QRegExpValidator(rx2,msLine));
      msLine->setText(QString("%1").arg(time));

  }
}

void MainWindow::deleteTabWidget()
{

}

void MainWindow::lodaPushButtonSig()
{
    QString fileName = QFileDialog::getOpenFileName(this,"选择文件","./", "Files(*.db)");
   // ui->sendTextEdit->clear();
    //ui->sendTextEdit->insertPlainText(fileName);
    if(fileName.isEmpty())
    {
        return;
    }
    sqlist->reSqlList(fileName);
    tableName->clear();
    for(int i = 1;i < ui->tabWidget->count(); i++)
        ui->tabWidget->removeTab(i);
    initTabwidget();
}

void MainWindow::openFilePushButtonSig()
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
    isSendFile = true;
}

void MainWindow::timerTimeoutSig()
{
    if(ui->loopSendPushButton->isChecked()==true)
    {
        sendPushButtonSign();
    }
    else if(ui->loopSendListPushButton->isChecked()==true)
    {
        if(loopListCount == 50)
        {
            loopListCount = 1;
        }
        bool hex;
        QString str;
        QString sendStr;
        int queue = loopListCount;
        int time;
        int i;
        QWidget * widget = ui->tabWidget->widget(ui->tabWidget->currentIndex());
        QGridLayout *layout = (QGridLayout *)(widget->layout());
        QLayoutItem* pLayout = layout->itemAtPosition(0, 0);
        QTableWidget * tableWidget = (QTableWidget *)( pLayout->widget());
        QString tab =tableWidget->windowTitle();
        sqlist->selectTableQueueLineInfo(tab,i,hex,str,sendStr,queue,time);
        if(str.isEmpty())
        {
            loopListCount = 1;
        }
        else
        {
            //tableWidget->item(i,1)->setBackgroundColor(QColor("85, 255, 0"));
//            tableWidget->item(i-1,1)->setBackgroundColor(QColor("0, 0, 0"));
            serialPortSend(str.toUtf8(),hex);
            PriecSendTimer->stop();
            PriecSendTimer->start(time);
            loopListCount++;
        }

    }
}
