#include "llistwidget.h"
#include "ui_llistwidget.h"

LListWidget::LListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LListWidget)
{
    ui->setupUi(this);
    initLineListWidget();
    initSetPushButton();
}

LListWidget::~LListWidget()
{
    delete ui;
}

void LListWidget::initLineListWidget()
{
    QLabel *Label0 = new QLabel(this);
    QLabel *Label1 = new QLabel(this);
    QLabel *Label2 = new QLabel(this);
    QLabel *Label3 = new QLabel(this);
    QLabel *Label4 = new QLabel(this);
    QLabel *Label5 = new QLabel(this);

    Label0->setMinimumSize(30,30);
    Label0->setMaximumSize(30,200);

    Label1->setMinimumSize(30,30);
    Label1->setMaximumSize(30,200);

    Label2->setMinimumSize(80,30);

    Label3->setMinimumSize(30,30);
    Label3->setMaximumSize(30,200);

    Label4->setMinimumSize(60,30);
    Label4->setMaximumSize(60,200);

    Label5->setMinimumSize(60,30);
    Label5->setMaximumSize(60,200);

    QHBoxLayout *horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

    Label0->setText(QString(""));
    Label1->setText(QString("Hex"));
    Label1->setAlignment( Qt::AlignHCenter);
    Label2->setText(QString("Str"));
    Label2->setAlignment( Qt::AlignHCenter);
    Label3->setText(QString("quene"));
    Label3->setAlignment( Qt::AlignHCenter);
    Label4->setText(QString("ms"));
    Label4->setAlignment( Qt::AlignHCenter);
    Label5->setText(QString(""));

    horizontalLayout->addWidget(Label0);
    horizontalLayout->addWidget(Label1);
    horizontalLayout->addWidget(Label2);
    horizontalLayout->addWidget(Label3);
    horizontalLayout->addWidget(Label4);
    horizontalLayout->addWidget(Label5);


    ui->verticalLayout->addLayout(horizontalLayout);

    for(int i = 0;i < 50;i++)
    {
        QHBoxLayout *horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        label[i] = new QLabel(this);
        checkBox[i] = new QCheckBox(this);
        queneEdit[i] = new QLineEdit(this);
        msEdit[i] = new QLineEdit(this);
        lineEdit[i] = new QLineEdit(this);
        sendPushButton[i] = new LPushButton(this);

        label[i]->setText(QString("%1").arg(i));
        sendPushButton[i]->setText(QString("??????(\\r\\n)"));

        label[i]->setMinimumSize(30,30);
        label[i]->setMaximumSize(30,200);

        checkBox[i]->setMinimumSize(30,30);
        checkBox[i]->setMaximumSize(30,200);

        lineEdit[i]->setMinimumSize(80,30);

        queneEdit[i]->setMinimumSize(30,30);
        queneEdit[i]->setMaximumSize(30,200);

        msEdit[i]->setMinimumSize(60,30);
        msEdit[i]->setMaximumSize(60,200);

        sendPushButton[i]->setMinimumSize(120,30);
        sendPushButton[i]->setMaximumSize(120,200);


        QRegExp rx1("^\\d\\d?$");
        queneEdit[i]->setValidator(new QRegExpValidator(rx1,queneEdit[i]));
        queneEdit[i]->setText(QString("%1").arg(0));

        QRegExp rx2("^\\d\\d\\d\\d\\d\\d\\d\\d?$");
        msEdit[i]->setValidator(new QRegExpValidator(rx2,msEdit[i]));
        msEdit[i]->setText(QString("%1").arg(1000));

        label[i]->setObjectName(QString::fromUtf8("listLabel"));
        lineEdit[i]->setObjectName(QString::fromUtf8("listLineEdit"));
        sendPushButton[i]->setObjectName(QString::fromUtf8("listPushButton"));

        horizontalLayout->addWidget(label[i]);
        horizontalLayout->addWidget(checkBox[i]);
        horizontalLayout->addWidget(lineEdit[i]);
        horizontalLayout->addWidget(queneEdit[i]);
        horizontalLayout->addWidget(msEdit[i]);
        horizontalLayout->addWidget(sendPushButton[i]);

        connect(sendPushButton[i],&LPushButton::leftButtonClicked,this,[=](){
            qDebug() << QString("%1").arg(lineEdit[i]->text());
            QString str = QString("%1").arg(lineEdit[i]->text());
            str.replace("\n", "\r\n");
            bool isHex =checkBox[i]->checkState();
            if(sendPushButton[i]->text() == "??????(\\n)")
            {
                str += "\n";
            }
            else if(sendPushButton[i]->text() == "??????(\\r)")
            {
                str += "\r";
            }
            else if(sendPushButton[i]->text() == "??????(\\r\\n)")
            {
                str += "\r\n";
            }
            else if(sendPushButton[i]->text() == "??????(\\n\\r)")
            {
                str += "\n\r";
            }
            else
            {
            }
            emit sendDataClicked(str,isHex);
        });
        connect(sendPushButton[i],&LPushButton::rightButtonClicked,this,[=](){
            if(sendPushButton[i]->text() == "??????")
            {
                sendPushButton[i]->setText(QString("??????(\\r)"));
            }
            else if(sendPushButton[i]->text() == "??????(\\r)")
            {
                sendPushButton[i]->setText(QString("??????(\\n)"));
            }
            else if(sendPushButton[i]->text() == "??????(\\n)")
            {
                sendPushButton[i]->setText(QString("??????(\\r\\n)"));
            }
            else if(sendPushButton[i]->text() == "??????(\\r\\n)")
            {
                sendPushButton[i]->setText(QString("??????(\\n\\r)"));
            }
            else
            {
                sendPushButton[i]->setText(QString("??????"));
            }
        });
        ui->verticalLayout->addLayout(horizontalLayout);
        connect(lineEdit[i],&QLineEdit::textChanged,this,[=](){
            QString senddata = lineEdit[i]->text();
            senddata.replace("\n", "\r\n");
        });
        //connect(lineEdit[i],&QLineEdit::textChanged,this,&LListWidget::saveListWidget);
       // connect(msEdit[i],&QLineEdit::textChanged,this,&LListWidget::saveListWidget);
       // connect(queneEdit[i],&QLineEdit::textChanged,this,&LListWidget::saveListWidget);

    }

    initSqlList();
    connect(ui->comComboBox,&LComboBox::currentTextChanged,this,&LListWidget::updataListWidget);
    connect(ui->comComboBox,&LComboBox::clicked,this,&LListWidget::saveListWidget);

}

void LListWidget::cyclicSendSig()
{
   // emit sendDataClicked(str,isHex);
    if(strCyclic->isEmpty())
    {
        qDebug() << "isEmpty";
        sqlist->selectTableQueueLineInfo(ui->comComboBox->currentText(),idCyclic,hexCyclic,strCyclic,sendStrCyclic,cyclicCount,timeCyclic);
    }

    if(strCyclic->isEmpty())
    {
        qDebug() << cyclicCount;

        if(cyclicCount == 1)
        {
            cyclicSendTimer->stop();
            return;
        }
        else
        {
            cyclicCount = 1;
            cyclicSendTimer->start(1000);
            return;
        }
    }
    if(strCyclic->count() == 1)
    {
        cyclicCount++;
    }
    QString str = QString("%1").arg(strCyclic->first());
    bool isHex = hexCyclic->first();

    if(sendStrCyclic->first() == "??????(\\n)")
    {
        str += "\n";
    }
    else if(sendStrCyclic->first() == "??????(\\r)")
    {
        str += "\r";
    }
    else if(sendStrCyclic->first() == "??????(\\r\\n)")
    {
        str += "\r\n";
    }
    else if(sendStrCyclic->first() == "??????(\\n\\r)")
    {
        str += "\n\r";
    }
    else
    {
    }
    emit sendDataClicked(str,isHex);
    cyclicSendTimer->start(timeCyclic->first());
    strCyclic->removeFirst();
    hexCyclic->removeFirst();
    timeCyclic->removeFirst();
    sendStrCyclic->removeFirst();

}

void LListWidget::initSqlList()
{
    hexCyclic = new QList<bool>;
    timeCyclic =new QList<int>;
    idCyclic = new QList<int>;
    strCyclic = new QStringList;
    sendStrCyclic = new QStringList;

    tableName = new QStringList;
    sqlist = new SqlList(QCoreApplication::applicationDirPath()+"/lcomm.db");
    sqlist->checkSqlTableAll(tableName);
    ui->comComboBox->clear();
    for(int i = 0;i < tableName->count();i++)
    {
         QString portName=QString("%1").arg(tableName->at(i));
         ui->comComboBox->addItem(portName);
    }
    updataListWidget(tableName->first());

}

void LListWidget::initSetPushButton()
{
    QAction *myAc0 = new QAction(this);
    myAc0->setText("??????");
    // myAc1->setStatusTip("This is ac1.");
    connect(myAc0, &QAction::triggered, this,[=](){
        qDebug() << QString("??????");
        sqlist->deleteSqlTable(ui->comComboBox->currentText());
        ui->comComboBox->removeItem(ui->comComboBox->currentIndex());
        clearListWidget();
        updataListWidget(ui->comComboBox->currentText());
    });

    QAction *myAc1 = new QAction(this);
        myAc1->setText("??????");
        // myAc1->setStatusTip("This is ac1.");
        connect(myAc1, &QAction::triggered, this,[=](){      
        qDebug() << QString("??????");
        saveListWidget();
        addTabListWidget();
    });
    QAction *myAc2 = new QAction(this);
        myAc2->setText("?????????");
        //myAc2->setStatusTip("This is ac2");
        connect(myAc2, &QAction::triggered, this,[=](){
        qDebug() << QString("?????????");
        saveAsListWidget();
    });
    QAction *myAc3 = new QAction(this);
    myAc3->setText("??????");
    // myAc3->setStatusTip("This is ac3");
    connect(myAc3, &QAction::triggered, this, [=](){
        QString fileName = QFileDialog::getOpenFileName(this,"????????????","./", "Files(*.db)");
        if(fileName.isEmpty())
        {
          return;
        }
        sqlist->reSqlList(fileName);
        tableName->clear();
        ui->comComboBox->clear();
        sqlist->checkSqlTableAll(tableName);
        for(int i = 0;i < tableName->count();i++)
        {
            QString portName=QString("%1").arg(tableName->at(i));
            ui->comComboBox->addItem(portName);
        }
        clearListWidget();
        updataListWidget(ui->comComboBox->currentText());
    });
    cyclicSendTimer = new QTimer;
    cyclicSendTimer->setInterval(1000);
    cyclicSendTimer->setSingleShot(true);//???????????????
    connect(cyclicSendTimer,&QTimer::timeout,this,[=](){
        saveListWidget();
        cyclicSendSig();});

    QAction *myAc4 = new QAction(this);
    myAc4->setText("????????????");
    myAc4->setCheckable(true);
    // myAc3->setStatusTip("This is ac3");
    connect(myAc4, &QAction::triggered, this, [=](){
        saveListWidget();
        cyclicCount=1;
        hexCyclic->clear();
        timeCyclic->clear();
        idCyclic->clear();
        strCyclic->clear();
        sendStrCyclic->clear();
        if(DEBUGLOG == 1)
        qDebug() << QString("????????????");
        if(myAc4->isChecked())
        {
            cyclicSendTimer->start(1000);
        }
        else
        {
            cyclicSendTimer->stop();
        }

    });

    QAction *myAc5 = new QAction(this);
    myAc5->setText("?????????");
    // myAc1->setStatusTip("This is ac1.");
    connect(myAc5, &QAction::triggered, this,[=](){
        qDebug() << QString("?????????");
        QString newtab;
        while(1)
        {
        bool ok;
        QString text = QInputDialog::getText(this, tr("??????Tab"),tr("???????????????:????????????"), QLineEdit::Normal,0, &ok);
        if(ok && !text.isEmpty())
        {
            if(tableName->contains(text))
            {
                if(DEBUGLOG == 1)
                qDebug() << text << "is exist";
                text = QInputDialog::getText(this, tr("??????Tab"),tr("???????????????:????????????"), QLineEdit::Normal,0, &ok);
            }
            else
            {
                newtab = text;
                if(DEBUGLOG == 1)
                qDebug() << text << "set success";
                break;
            }
        }
        else
        {
            return;
        }
        }
        sqlist->alterSqlTable(ui->comComboBox->currentText(),newtab);

        tableName->replace(tableName->indexOf(ui->comComboBox->currentText()),newtab);
        ui->comComboBox->clear();
        //sqlist->checkSqlTableAll(tableName);
        for(int i = 0;i < tableName->count();i++)
        {
            QString portName=QString("%1").arg(tableName->at(i));
            ui->comComboBox->addItem(portName);
        }
        clearListWidget();
        updataListWidget(ui->comComboBox->currentText());
    });
    QMenu *menu = new QMenu();
    menu->addAction(myAc0);
    menu->addAction(myAc1);
    menu->addAction(myAc2);
    menu->addAction(myAc3);
    menu->addAction(myAc4);
    menu->addAction(myAc5);

    // ???QToolButton????????????
    ui->setPushButton->setMenu(menu);
}

void LListWidget::updataListWidget(const QString &tabName)
{
    bool hex;
    QString str;
    QString sendStr;
    int queue;
    int time;

    for(int i = 0;i < 50;i++)
    {
        sqlist->selectTableLineInfo(tabName,i+1,hex,str,sendStr,queue,time);

        sendPushButton[i]->setText(sendStr);
        lineEdit[i]->setText(str);
        queneEdit[i]->setText(QString("%1").arg(queue));
        msEdit[i]->setText(QString("%1").arg(time));
        if(hex == true)
        {
            checkBox[i]->setCheckState(Qt::Checked);
        }
        else
        {
            checkBox[i]->setCheckState(Qt::Unchecked);
        }
    }
}

void LListWidget::saveListWidget()
{
    if(DEBUGLOG == 1)
    qDebug() << "save list"<<ui->comComboBox->currentText();
    bool hex;
    QString str;
    QString sendStr;
    int queue;
    int time;
    for(int i = 0;i < 50;i++)
    {
        sendStr = sendPushButton[i]->text();
        str = lineEdit[i]->text();
        queue = queneEdit[i]->text().toInt();
        time = msEdit[i]->text().toInt();
        hex = checkBox[i]->checkState();

        sqlist->alterSqlTableInfo(ui->comComboBox->currentText(),i+1,hex,str,sendStr,queue,time);
    }
}

void LListWidget::saveAsListWidget()
{
    QFileDialog fileDialog;
    QString fileName = fileDialog.getSaveFileName(this,tr("Open File"),"./",tr("*.db"));
    if(fileName == "")
    {
        return;
    }
    else
    {

        qDebug() << fileName;

        bool ok = QFile::copy(QCoreApplication::applicationDirPath()+"/lcomm.db", fileName);
        if(ok == true)
        {
            QMessageBox::warning(this,tr("??????"),tr("??????????????????"));
        }
        else
        {
            QMessageBox::warning(this,tr("??????"),tr("??????????????????"));
        }
    }
}

void LListWidget::addTabListWidget()
{
    if(DEBUGLOG == 1)
    qDebug() << "addTabListWidget";
    while(1)
    {
        bool ok;
        QString text = QInputDialog::getText(this, tr("??????Tab"),tr("???????????????:????????????"), QLineEdit::Normal,0, &ok);
        if(ok && !text.isEmpty())
        {
            if(tableName->contains(text))
            {
              if(DEBUGLOG == 1)
              qDebug() << text << "is exist";
              text = QInputDialog::getText(this, tr("??????Tab"),tr("???????????????:????????????"), QLineEdit::Normal,0, &ok);
            }
            else
            {
              tableName->append(text);
              if(DEBUGLOG == 1)
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
    updataListWidget(tableName->last());
    ui->comComboBox->addItem(tableName->last());
    ui->comComboBox->setCurrentText(tableName->last());
}

void LListWidget::clearListWidget()
{
    bool hex = false;
    QString str = "";
    QString sendStr = "";
    int queue = 0;
    int time = 1000;

    for(int i = 0;i < 50;i++)
    {
        sendPushButton[i]->setText(sendStr);
        lineEdit[i]->setText(str);
        queneEdit[i]->setText(QString("%1").arg(queue));
        msEdit[i]->setText(QString("%1").arg(time));
        if(hex == true)
        {
            checkBox[i]->setCheckState(Qt::Checked);
        }
        else
        {
            checkBox[i]->setCheckState(Qt::Unchecked);
        }
    }
}
