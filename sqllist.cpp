#include "sqllist.h"



SqlList::SqlList(QString sqlname)
{
    qDebug() << QSqlDatabase::drivers();
    // 创建一个数据库连接，指定数据库驱动
    sqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
    sqlDatabase.setDatabaseName(sqlname);
    // 数据库连接需要设置的信息
    sqlDatabase.setHostName("127.0.0.1"); // 数据库服务器IP，我用的是本地电脑
    //  db.setDatabaseName("lcom");// 数据库名
    //db.setUserName("root");// 用户名
    //  db.setPassword("123456");// 密码
    // db.setPort(3306);// 端口号
    // 连接数据库
    bool ok = sqlDatabase.open();
    if (ok)
    {
        qDebug() << "database connect is ok";
    }

    else
    {
        qDebug() << "database connect is fail";
    }
    QStringList *tableName = new QStringList;
    checkSqlTableAll(tableName);
    if(tableName->size() == 0)
    {
        if(checkSqlTable("tab1") == false)
        {
            createSqlTable("tab1");
        }
    }
}
void SqlList::reSqlList(QString sqlname)
{
    sqlDatabase.close();
    sqlDatabase.setDatabaseName(sqlname);
    // 数据库连接需要设置的信息
    sqlDatabase.setHostName("127.0.0.1"); // 数据库服务器IP，我用的是本地电脑
    // 连接数据库
    bool ok = sqlDatabase.open();
    if (ok)
    {
        qDebug() << "database connect is ok";
    }

    else
    {
        qDebug() << "database connect is fail";
    }
    QStringList *tableName = new QStringList;
    checkSqlTableAll(tableName);
    if(tableName->size() == 0)
    {
        if(checkSqlTable("tab1") == false)
        {
            createSqlTable("tab1");
        }
    }
}
void SqlList::deleteSqlTable(const QString &table)
{
    QSqlQuery query(sqlDatabase);
    query.exec(QString("DROP TABLE %1").arg(table));

  //  query.prepare("DELETE FROM sqlite_master WHERE type='table' and name='%1'").arg(table);
    //query.bindValue(":tab", table);
   // query.exec();
}

void SqlList::createSqlTable(const QString &table)
{
    qDebug() <<"createSqlTable" << "\n ";
    QSqlQuery query(sqlDatabase);
    QString strexec = QString("create table %1 (id int primary key,hex int,str varchar(2048),sendStr varchar(64),queue int,time int)").arg(table);
    //query.exec("create table lcom (id int primary key,hex varchar(2048),str int,queue int,time int)");
    query.exec(strexec);
    checkSqlTable(table);
    for(int i = 1;i <= 50;i++)
    {
        addSqlTableInfo(table,i,0,"","发送",0,1000);
    }
#if 0
    query.exec("select * from lcom");
    while(query.next()) //一行一行遍历
    {
        //取出当前行的内容
        //以列为单位的
         qDebug() <<"|" << query.value("id").toInt() \
        <<"|"<< query.value("hex").toInt() \
         <<"|"<< query.value("str").toString() \
         <<"|"<<query.value("queue").toInt() \
         <<"|"<<query.value("time").toInt();
    }
#endif
}

bool SqlList::checkSqlTable(const QString &table)
{
    QSqlQuery query(sqlDatabase);
    query.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg(table));
    if(query.next())
    {
        if(query.value(0).toInt()==0)
        {
          // 表不存在
            qDebug() <<"表不存在" << "\n ";
           return false;
        }else
        {
            qDebug() <<"表存在" << "\n ";
            return true;
        }

    }
    return false;

}

void SqlList::checkSqlTableAll(QStringList * table)
{
    //查询所以的table
    QSqlQuery query(sqlDatabase);
    //占位符 : + 自定义名字
    QString strexec = QString("SELECT name FROM sqlite_master WHERE type='table' order by name");
    query.exec(strexec);
    while (query.next()) {
        qDebug() << "table name:" << query.value(0).toString();
        //if(!(table->isEmpty()))
     //   {
            table->append(query.value(0).toString());
       // }
    }
     //qDebug() <<table.size()<<table.at(0);
    // table->.contains(“123”);查询是否包含
}

void SqlList::alterSqlTable(const QString &oldTable, const QString &newTable)
{

    QSqlQuery query(sqlDatabase);
    //占位符 : + 自定义名字
    QString strexec = QString("ALTER TABLE %1 RENAME TO %2;").arg(oldTable).arg(newTable);
    query.exec(strexec);
}

void SqlList::addSqlTableInfo(const QString &table, const int &id, const bool &hex, const QString &str,const QString &sendStr, const int &queue, const int &time)
{
    QSqlQuery query(sqlDatabase);
    //占位符 : + 自定义名字
    QString strexec = QString("INSERT INTO %1 (id, hex, str, sendStr,queue, time) VALUES(:id ,:hex,:str,:sendStr,:queue,:time)").arg(table);
    //query.exec("create table lcom (id int primary key,hex varchar(2048),str int,queue int,time int)");
    query.prepare(strexec);
    //给字段绑定
    query.bindValue(":id", id);
    query.bindValue(":hex", hex);
    if(str.isEmpty())
    {
        query.bindValue(":str",QString(""));
    }
    else
    {
        query.bindValue(":str", sendStr);
    }
    if(sendStr.isEmpty())
    {
        query.bindValue(":sendStr",QString(""));
    }
    else
    {
        query.bindValue(":sendStr", sendStr);
    }
    query.bindValue(":queue", queue);
    query.bindValue(":time", time);
    query.exec();

}

void SqlList::alterSqlTableInfo(const QString &table, const int &id, const bool &hex, const QString &str, const QString &sendStr, const int &queue, const int &time)
{
    QSqlQuery query(sqlDatabase);
    QString strexec = QString("UPDATE %1 set hex=%3, str=\"%4\", sendStr = \"%5\",queue =%6, time = %7 where id = %2")
            .arg(table).arg(id).arg(hex).arg(str).arg(sendStr).arg(queue).arg(time);
    query.exec(strexec);
}

void SqlList::alterSqlTableInfoStr(const QString &table,const int &id, const QString &str)
{
    QSqlQuery query(sqlDatabase);
    QString strexec = QString("UPDATE %1 set str=%3 where id=%2;")
            .arg(table).arg(id).arg(str);
    query.exec(strexec);
}

void SqlList::alterSqlTableInfoSendStr(const QString &table,const int &id, const QString &sendStr)
{
    QSqlQuery query(sqlDatabase);
    QString strexec = QString("UPDATE %1 set sendStr=%3 where id=%2;")
            .arg(table).arg(id).arg(sendStr);
    query.exec(strexec);
}

void SqlList::selectTableLineInfo(const QString &table, const int &id, bool &hex, QString &str, QString &sendStr, int &queue, int &time)
{

   QString sql = QString("SELECT * FROM %1 WHERE id=%2").arg(table).arg(id);
   QSqlQuery query(sqlDatabase);
    query.exec(sql);

   while (query.next())
   {                  // [5] 遍历查询结果

     //  qDebug() <<"表存在" << "\n ";

                  qDebug() << QString("id: %1, hex: %2 ,str: %3,queue: %4, time: %5")
                   .arg(query.value("id").toInt())
                    .arg(query.value("hex").toInt())
                    .arg(query.value("str").toString())
                   .arg(query.value("queue").toInt())
                   .arg(query.value("time").toInt());
                 // qDebug() <<"表存在" << "\n ";


              hex = query.value("hex").toBool();
              str = query.value("str").toString();
              queue = query.value("queue").toInt();
               time = query.value("time").toInt();
               sendStr = query.value("sendStr").toString();
   }
}

void SqlList::selectTableQueueLineInfo(const QString &table, QList<int> *id, QList<bool> *hex, QStringList *str, QStringList *sendStr,int &queue, QList<int> *time)
{

    QString sql = QString("SELECT * FROM %1 WHERE queue=%2").arg(table).arg(queue);
    QSqlQuery query(sqlDatabase);
     query.exec(sql);

    if(query.next())
    {                  // [5] 遍历查询结果

      //  qDebug() <<"表存在" << "\n ";

                   qDebug() << QString("id: %1, hex: %2 ,str: %3,queue: %4, time: %5")
                    .arg(query.value("id").toInt())
                     .arg(query.value("hex").toInt())
                     .arg(query.value("str").toString())
                    .arg(query.value("queue").toInt())
                    .arg(query.value("time").toInt());
                  // qDebug() <<"表存在" << "\n ";


               hex->append(query.value("hex").toBool());
               str->append(query.value("str").toString());
               time->append(query.value("time").toInt());
               id->append(query.value("id").toBool());
               sendStr->append(query.value("sendStr").toString());

    }
}

