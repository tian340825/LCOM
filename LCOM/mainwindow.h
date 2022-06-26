#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qnamespace.h>
#include <QPushButton>
#include <QMouseEvent>
#include "conifg.h"
#include "sqllist.h"
/*-------------user-------------------*/
/*---port--*/
#include <QSerialPort>//提供访问串口的功能
#include <QSerialPortInfo>//提供系统中存在的串口的信息
/*---QString--*/
#include <QString>
/*---QDateTime--*/
#include <QDateTime>
/*---QTimer--*/
#include <QTimer>
/*---QDebug--*/
#include <QTableWidgetItem>
#include <qinputdialog.h>
#include <QObject>
#include <QCheckBox>
#include <QSpinBox>
#include "myqcombobox.h"
//#include <QHeaderView>
#include<QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initUiCfg();
    void initSigCfg();
    void sendPushButtonSign();
    void sendPushButtonRightSign();
    void setMenuPushButtonSign(bool checked);
    void expandTabWigetSign(bool checked);
    void openPortPushButtonSig();
    void addTabPushButtonSig();
    void savePushButtonSig();
    void listSendPushButtonSig();
    void listSendSetPushButtonSig();
    void loopSendPushButtonSign();
    void loopSendListPushButtonSign();
    void serialPortCheck(bool);
    void serialPortSend(const QString &str,bool &hexshow);
    void serialPortRecv();

    void initTabwidget();
    void createTabWidget(const QString &name);
    void createTableWiget(QTableWidget * tableWidget,const QString &name);
    void deleteTabWidget();
    void lodaPushButtonSig();
    void openFilePushButtonSig();
    void timerTimeoutSig();
    Ui::MainWindow *ui;
    conifg *cfgWidget;
    QTimer *PriecSendTimer;
    SqlList *sqlist;
    QStringList *tableName;
    QSerialPort *serial;
    int  loopListCount;
    bool isSerialOpen;
    bool isSendFile;
signals:
};
#endif // MAINWINDOW_H
