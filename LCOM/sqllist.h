#ifndef SQLLIST_H
#define SQLLIST_H
#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
class SqlList : public QObject
{
    Q_OBJECT
    QSqlDatabase sqlDatabase;

public:
    explicit SqlList(QString sqlname);
    void reSqlList(QString sqlname);
    void deleteSqlTable(const QString &table);//删除表
    void createSqlTable(const QString &table);//创建表
    bool checkSqlTable(const QString &table);//检查表
    void checkSqlTableAll(QStringList * table);//all
    void alterSqlTable(const QString &oldTable,const QString &newTable);//重命名表
public:
    void addSqlTableInfo(const QString &table,const int &id,const bool &hex,const QString &str,const QString &sendStr,const int &queue,const int &time);//添加表信息
    void alterSqlTableInfo(const QString &table,const int &id,const bool &hex,const QString &str,const QString &sendStr,const int &queue,const int &time);//更新表指定id信息
    void alterSqlTableInfoStr(const QString &table,const int &id,const QString &str);//更新Table ser信息
    void alterSqlTableInfoSendStr(const QString &table,const int &id,const QString &sendStr);//更新table sendStr信息
public:
    void selectTableLineInfo(const QString &table,const int &id,bool &hex,QString &str,QString &sendStr,int &queue,int &time);//查询指定id信息
    void selectTableQueueLineInfo(const QString &table, int &id, bool &hex, QString &str, QString &sendStr,const int &queue, int &time);//查询指定queue信息

};
#endif // SQLLIST_H
