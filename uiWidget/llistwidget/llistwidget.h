#ifndef LLISTWIDGET_H
#define LLISTWIDGET_H

#include <QWidget>
#include <QPushButton>

#include <QObject>
#include <QLineEdit>
#include <QLabel>
#include <QRegExpValidator>
#include <QCheckBox>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QTimer>
#include "library/sql/sqllist.h"
#include <QInputDialog>
#include "uiWidget/lcombobox/lcombobox.h"
#include <QFileDialog>
#include "uiWidget/lpushbutton/lpushbutton.h"
#define L_LOG qDebug() << "[" << __FILE__ << ":" << __LINE__ << ":" << __func__ << __DATE__ << __TIME__<< "]"

namespace Ui {
class LListWidget;
}

class LListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LListWidget(QWidget *parent = nullptr);
    ~LListWidget();

private:
    #define DEBUGLOG 0
    void initLineListWidget();
    void cyclicSendSig();
    void initSqlList();
    void initSetPushButton();
    void updataListWidget(const QString &tabName);
    void saveListWidget();
    void saveAsListWidget();
    void addTabListWidget();
    void clearListWidget();
    SqlList *sqlist;
    QStringList *tableName;
    QCheckBox *checkBox[50];
    QLabel *label[50];
    LPushButton *sendPushButton[50];
    QLineEdit *queneEdit[50];
    QLineEdit *msEdit[50];
    QLineEdit *lineEdit[50];

    QList<bool> *hexCyclic;
    QList<int> *timeCyclic;
    QList<int> *idCyclic;
    QStringList *strCyclic;
    QStringList *sendStrCyclic;
    bool initOver = false;
    bool cyclicExeOneFlg = false;

    Ui::LListWidget *ui;
    QTimer *cyclicSendTimer;
    int cyclicCount = 1;
signals:
    void sendDataClicked(QString &str,bool &isHex);
};

#endif // LLISTWIDGET_H
