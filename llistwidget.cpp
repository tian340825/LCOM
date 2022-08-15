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
    Label3->setText(QString(""));
    Label3->setAlignment( Qt::AlignHCenter);
    Label4->setText(QString(""));
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
        sendPushButton[i]->setText(QString("发送(\\r\\n)"));

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

        lineEdit[i]->setToolTip("按下回车自定义提示消息");
        connect(lineEdit[i], &QLineEdit::returnPressed, this, [=](){
            QString newToolTip;
            while(1)
            {
                bool ok;
                QString text = QInputDialog::getText(this, tr("提示"),tr("请输入提示:"), QLineEdit::Normal,0, &ok);
                if(ok && !text.isEmpty())
                {
                    newToolTip = text;
                    if(DEBUGLOG == 1)
                    qDebug() << text << "set success";
                    break;
                }
                else
                {
                    return;
                }
            }
            lineEdit[i]->setToolTip(newToolTip);
        });
        horizontalLayout->addWidget(label[i]);
        horizontalLayout->addWidget(checkBox[i]);
        horizontalLayout->addWidget(lineEdit[i]);
        horizontalLayout->addWidget(queneEdit[i]);
        horizontalLayout->addWidget(msEdit[i]);
        horizontalLayout->addWidget(sendPushButton[i]);
        horizontalLayout->setContentsMargins(0,0,0,0);
        horizontalLayout->setSpacing(0);
        connect(sendPushButton[i],&LPushButton::leftButtonClicked,this,[=](){
            qDebug() << QString("%1").arg(lineEdit[i]->text());
            QString str = QString("%1").arg(lineEdit[i]->text());
            str.replace("\n", "\r\n");
            bool isHex =checkBox[i]->checkState();
            if(sendPushButton[i]->text() == "发送(\\n)")
            {
                str += "\n";
            }
            else if(sendPushButton[i]->text() == "发送(\\r)")
            {
                str += "\r";
            }
            else if(sendPushButton[i]->text() == "发送(\\r\\n)")
            {
                str += "\r\n";
            }
            else if(sendPushButton[i]->text() == "发送(\\n\\r)")
            {
                str += "\n\r";
            }
            else
            {
            }
            emit sendDataClicked(str,isHex);
        });
        connect(sendPushButton[i],&LPushButton::rightButtonClicked,this,[=](){
            if(sendPushButton[i]->text() == "发送")
            {
                sendPushButton[i]->setText(QString("发送(\\r)"));
            }
            else if(sendPushButton[i]->text() == "发送(\\r)")
            {
                sendPushButton[i]->setText(QString("发送(\\n)"));
            }
            else if(sendPushButton[i]->text() == "发送(\\n)")
            {
                sendPushButton[i]->setText(QString("发送(\\r\\n)"));
            }
            else if(sendPushButton[i]->text() == "发送(\\r\\n)")
            {
                sendPushButton[i]->setText(QString("发送(\\n\\r)"));
            }
            else
            {
                sendPushButton[i]->setText(QString("发送"));
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
    ui->verticalLayout->setContentsMargins(0,0,0,0);
    ui->verticalLayout->setSpacing(0);
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
            if(cyclicExeOneFlg != true)
            {
                cyclicCount = 1;
                cyclicSendTimer->start(1000);
            }
            return;
        }
    }
    if(strCyclic->count() == 1)
    {
        cyclicCount++;
    }
    QString str = QString("%1").arg(strCyclic->first());
    bool isHex = hexCyclic->first();

    if(sendStrCyclic->first() == "发送(\\n)")
    {
        if(isHex == true)
         str += "0A";
        else
        str += "\n";
    }
    else if(sendStrCyclic->first() == "发送(\\r)")
    {
        if(isHex == true)
         str += "0D";
        else
        str += "\r";
    }
    else if(sendStrCyclic->first() == "发送(\\r\\n)")
    {
        if(isHex == true)
         str += "0D0A";
        else
        str += "\r\n";
    }
    else if(sendStrCyclic->first() == "发送(\\n\\r)")
    {
        if(isHex == true)
         str += "0A0D";
        else
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
    myAc0->setText("删除");
    // myAc1->setStatusTip("This is ac1.");
    connect(myAc0, &QAction::triggered, this,[=](){
        qDebug() << QString("删除");
        if(ui->comComboBox->count() >= 2)
        {
            sqlist->deleteSqlTable(ui->comComboBox->currentText());
            ui->comComboBox->removeItem(ui->comComboBox->currentIndex());
            clearListWidget();
            updataListWidget(ui->comComboBox->currentText());
        }
    });

    QAction *myAc1 = new QAction(this);
        myAc1->setText("新增");
        // myAc1->setStatusTip("This is ac1.");
        connect(myAc1, &QAction::triggered, this,[=](){
        qDebug() << QString("新增");
        saveListWidget();
        addTabListWidget();
    });
    QAction *myAc2 = new QAction(this);
        myAc2->setText("另存为");
        //myAc2->setStatusTip("This is ac2");
        connect(myAc2, &QAction::triggered, this,[=](){
        qDebug() << QString("另存为");
        saveAsListWidget();
    });
    QAction *myAc3 = new QAction(this);
    myAc3->setText("导入");
    // myAc3->setStatusTip("This is ac3");
    connect(myAc3, &QAction::triggered, this, [=](){
        QString fileName = QFileDialog::getOpenFileName(this,"选择文件","./", "Files(*.db)");
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
    cyclicSendTimer->setSingleShot(true);//只运行一次
    connect(cyclicSendTimer,&QTimer::timeout,this,[=](){
        saveListWidget();
        cyclicSendSig();});

    QAction *myAc5 = new QAction(this);
    myAc5->setText("重命名");
    // myAc1->setStatusTip("This is ac1.");
    connect(myAc5, &QAction::triggered, this,[=](){
        qDebug() << QString("重命名");
        saveListWidget();

        QString newtab;
        while(1)
        {
            bool ok;
            QString text = QInputDialog::getText(this, tr("新增Tab"),tr("请输入表名:不能重复"), QLineEdit::Normal,0, &ok);
            if(ok && !text.isEmpty())
            {
                if(tableName->contains(text))
                {
                    if(DEBUGLOG == 1)
                    qDebug() << text << "is exist";
                    text = QInputDialog::getText(this, tr("新增Tab"),tr("请输入表名:不能重复"), QLineEdit::Normal,0, &ok);
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
    QMenu* myAc4 = menu->addMenu("循环发送");

    QAction* project1Action= myAc4->addAction(tr("执行1次"));
    QAction* project2Action= myAc4->addAction(tr("执行N次"));
    project1Action->setCheckable(true);
    project2Action->setCheckable(true);
    QActionGroup * m_MenuActionGroup = new QActionGroup(this);
    m_MenuActionGroup->addAction(project1Action);
    m_MenuActionGroup->addAction(project2Action);

    connect(project1Action, &QAction::triggered, this, [=](){
        saveListWidget();
        cyclicCount=1;
        hexCyclic->clear();
        timeCyclic->clear();
        idCyclic->clear();
        strCyclic->clear();
        sendStrCyclic->clear();
        if(DEBUGLOG == 1)
        qDebug() << QString("循环发送");
        cyclicExeOneFlg = true;

        if(project1Action->isChecked())
        {
            cyclicSendTimer->start(1000);
        }
        else
        {
            cyclicSendTimer->stop();
        }

    });
    connect(project2Action, &QAction::triggered, this, [=](){
        saveListWidget();
        cyclicCount=1;
        hexCyclic->clear();
        timeCyclic->clear();
        idCyclic->clear();
        strCyclic->clear();
        sendStrCyclic->clear();
        cyclicExeOneFlg = false;
        if(DEBUGLOG == 1)
        qDebug() << QString("循环发送");
        if(project2Action->isChecked())
        {
            cyclicSendTimer->start(1000);
        }
        else
        {
            cyclicSendTimer->stop();
        }
    });

    menu->addAction(myAc5);

    // 为QToolButton设置菜单
    ui->setPushButton->setMenu(menu);
}

void LListWidget::updataListWidget(const QString &tabName)
{
    bool hex;
    QString str;
    QString sendStr;
    QString toolTipStr;
    int queue;
    int time;

    for(int i = 0;i < 50;i++)
    {
        sqlist->selectTableLineInfo(tabName,i+1,hex,str,sendStr,queue,time,toolTipStr);

        sendPushButton[i]->setText(sendStr);
        lineEdit[i]->setText(str);
        lineEdit[i]->setToolTip(toolTipStr);
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
    QString toolTipStr;

    int queue;
    int time;
    for(int i = 0;i < 50;i++)
    {
        sendStr = sendPushButton[i]->text();
        str = lineEdit[i]->text().toUtf8();
        toolTipStr = lineEdit[i]->toolTip().toUtf8();
        queue = queneEdit[i]->text().toInt();
        time = msEdit[i]->text().toInt();
        hex = checkBox[i]->checkState();
        qDebug() <<QString("%1").arg(str);

        sqlist->alterSqlTableInfo(ui->comComboBox->currentText(),i+1,hex,str,sendStr,queue,time,toolTipStr);
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
            QMessageBox::warning(this,tr("提示"),tr("保存文件成功"));
        }
        else
        {
            QMessageBox::warning(this,tr("提示"),tr("保存文件失败"));
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
        QString text = QInputDialog::getText(this, tr("新增Tab"),tr("请输入表名:不能重复"), QLineEdit::Normal,0, &ok);
        if(ok && !text.isEmpty())
        {
            if(tableName->contains(text))
            {
              if(DEBUGLOG == 1)
              qDebug() << text << "is exist";
              text = QInputDialog::getText(this, tr("新增Tab"),tr("请输入表名:不能重复"), QLineEdit::Normal,0, &ok);
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
    QString toolTipStr = "";
    int queue = 0;
    int time = 1000;

    for(int i = 0;i < 50;i++)
    {
        sendPushButton[i]->setText(sendStr);
        lineEdit[i]->setText(str);
        lineEdit[i]->setToolTip(toolTipStr);
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
