/**
 * @File Name: sqllist.cpp
 * @brief  
 * @Author : L email:tianlicoder@foxmail.com
 * @Version : 1.0
 * @Creat Date : 2023-02-15
 * 
 * @copyright Copyright (c) 
 * 
 */

#include "sqllist.h"
#define DEBUG_TEST_MODE  1 ///<正式版本删除
/**
 * @brief  Construct a new Sql List:: Sql List object
 * @param  sqlname: 
 */
SqlList::SqlList(QString sqlname)
{
    L_LOG << QSqlDatabase::drivers();
    // 创建一个数据库连接，指定数据库驱动
    sqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
    sqlDatabase.setDatabaseName(sqlname);
    // 数据库连接需要设置的信息
    sqlDatabase.setHostName("127.0.0.1"); // 数据库服务器IP
    //  db.setDatabaseName("lcom");// 数据库名
    //db.setUserName("root");// 用户名
    //  db.setPassword("123456");// 密码
    // db.setPort(3306);// 端口号
    // 连接数据库
    bool ok = sqlDatabase.open();
    if (ok)
    {
        if(DEBUGLOG == 1)
        L_LOG << "database connect is ok";
    }

    else
    {
        if(DEBUGLOG == 1)
        L_LOG << "database connect is fail";
    }

    QStringList *tableName = new QStringList;
    /**
     * @brief  Construct a new check Sql Table All object
     */
    checkSqlTableAll(tableName);
    if(tableName->size() == 0)
    {
        /**
         * @brief  if no tab,create tab1
         */
        if(checkSqlTable("tab1") == false)
        {
            createSqlTable("tab1");
        }
    }
}

/**
 * @brief  Rename Sql
 * @param  sqlname: 
 */
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
        if(DEBUGLOG == 1)
        L_LOG << "database connect is ok";
    }

    else
    {
        if(DEBUGLOG == 1)
        L_LOG << "database connect is fail";
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

/**
 * @brief  delete sql
 * @param  table: 
 */
void SqlList::deleteSqlTable(const QString &table)
{
    QSqlQuery query(sqlDatabase);
    query.exec(QString("DROP TABLE %1").arg(table));

    //query.prepare("DELETE FROM sqlite_master WHERE type='table' and name='%1'").arg(table);
    //query.bindValue(":tab", table);
    // query.exec();
}

/**
 * @brief  create tabel
 * @param  table: 
 */
void SqlList::createSqlTable(const QString &table)
{
    if(DEBUGLOG == 1)
    L_LOG <<"createSqlTable" << "\n ";
    QSqlQuery query(sqlDatabase);
    QString strexec = QString("create table %1 (id int primary key,hex int,str varchar(2048),sendStr varchar(64),queue int,time int,toolTipStr varchar(1024)"
                              ",example varchar(102400),actual varchar(102400),result int)").arg(table);
    query.exec(strexec);
    checkSqlTable(table);
    for(int i = 1;i <= 50;i++)
    {
        addSqlTableInfo(table,i,0,"","发送(\\r\\n)",0,1000,"按下回车自定义提示消息");
    }
#if DEBUG_TEST_MODE
    /**
    * @brief  兼容旧版本，
    */
    query.exec("select * from lcom");
    while(query.next()) //一行一行遍历
    {
        //取出当前行的内容
        //以列为单位的
         L_LOG <<"|" << query.value("id").toInt() \
        <<"|"<< query.value("hex").toInt() \
         <<"|"<< query.value("str").toString() \
         <<"|"<<query.value("queue").toInt() \
         <<"|"<<query.value("time").toInt();
    }
#endif
}

/**
 * @brief  Check if the table exists
 * @param  table: 
 * @return true: 
 * @return false: 
 */
bool SqlList::checkSqlTable(const QString &table)
{
    QSqlQuery query(sqlDatabase);
    query.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg(table));
    if(query.next())
    {
        if(query.value(0).toInt()==0)
        {
            if(DEBUGLOG == 1)
            L_LOG <<"表不存在" << "\n ";
           return false;
        }
        else
        {
            if(DEBUGLOG == 1)
            L_LOG <<"表存在" << "\n ";
#if DEBUG_TEST_MODE
            /**
            * @brief  兼容旧版本，
            */            
            checkSqlTableRow(table,"toolTipStr");
            checkSqlTableRow(table,"example");
            checkSqlTableRow(table,"actual");
            checkSqlTableRow(table,"result");
#endif
            return true;
        }

    }
    return false;

}

/**
 * @brief  check all table
 * @param  table: 
 */
void SqlList::checkSqlTableAll(QStringList * table)
{
    //查询所以的table
    QSqlQuery query(sqlDatabase);
    //占位符 : + 自定义名字
    QString strexec = QString("SELECT name FROM sqlite_master WHERE type='table' order by name");
    query.exec(strexec);
    while (query.next()) 
    {
        if(DEBUGLOG == 1)
        L_LOG << "table name:" << query.value(0).toString();
       // if(!(table->isEmpty()))
        //{
            table->append(query.value(0).toString());
        //}
    }
#if DEBUG_TEST_MODE
        /**
        * @brief  兼容旧版本，
        */     
    for(int i = 0;i < table->count();i++)
    {
        checkSqlTableRow(table->at(i),"toolTipStr");
        checkSqlTableRow(table->at(i),"example");
        checkSqlTableRow(table->at(i),"actual");
        checkSqlTableRow(table->at(i),"result");
    }
    #endif
}

/**
 * @brief  rename table
 * @param  oldTable: 
 * @param  newTable: 
 */
void SqlList::alterSqlTable(const QString &oldTable, const QString &newTable)
{

    QSqlQuery query(sqlDatabase);
    //占位符 : + 自定义名字
    QString strexec = QString("ALTER TABLE %1 RENAME TO %2;").arg(oldTable).arg(newTable);
    query.exec(strexec);
}

/**
 * @brief  add info by table
 * @param  table: 
 * @param  id: 
 * @param  hex: 
 * @param  str: 
 * @param  sendStr: 
 * @param  queue: 
 * @param  time: 
 * @param  toolTipStr: 
 */
void SqlList::addSqlTableInfo(const QString &table, const int &id, const bool &hex, const QString &str,const QString &sendStr, const int &queue, const int &time,const QString &toolTipStr)
{
    QSqlQuery query(sqlDatabase);
    //占位符 : + 自定义名字
    QString strexec = QString("INSERT INTO %1 (id, hex, str, sendStr,queue, time, toolTipStr)\
                         VALUES(:id ,:hex,:str,:sendStr,:queue,:time,:toolTipStr)").arg(table);
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
    if(toolTipStr.isEmpty())
    {
        query.bindValue(":toolTipStr",QString(""));
    }
    else
    {
        query.bindValue(":toolTipStr", toolTipStr);
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

/**
 * @brief  alter info by table
 * @param  table: 
 * @param  id: 
 * @param  hex: 
 * @param  str: 
 * @param  sendStr: 
 * @param  queue: 
 * @param  time: 
 * @param  toolTipStr: 
 */
void SqlList::alterSqlTableInfo(const QString &table, const int &id, const bool &hex, const QString &str,
                                const QString &sendStr, const int &queue, const int &time,QString &toolTipStr)
{
    QString tStr;
    if(toolTipStr.isEmpty())
    {
        tStr = "按下回车自定义提示消息";
    }
    else
    {
        tStr = toolTipStr;
    }
    QString senddata = str;
    senddata.replace("'", "''");
    QSqlQuery query(sqlDatabase);
    QString strexec = QString("UPDATE %1 set hex=%3, str=\'%4\', sendStr = \"%5\",queue =%6,toolTipStr =\"%8\", time = %7 where id = %2")
            .arg(table).arg(id).arg(hex).arg(senddata).arg(sendStr).arg(queue).arg(time).arg(tStr);
    query.exec(strexec);
}

/**
 * @brief  alter str by table
 * @param  table: 
 * @param  id: 
 * @param  str: 
 * @param  toolTipStr: 
 */
void SqlList::alterSqlTableInfoStr(const QString &table,const int &id, const QString &str,QString &toolTipStr)
{
    QString tStr;
    if(toolTipStr.isEmpty())
    {
        tStr = "按下回车自定义提示消息";
    }
    else
    {
        tStr = toolTipStr;
    }
    QString senddata = str;
    senddata.replace("'", "''");
    QSqlQuery query(sqlDatabase);
    QString strexec = QString("UPDATE %1 set str='%3',toolTipStr ='%4' where id=%2;")
                            .arg(table).arg(id).arg(senddata).arg(tStr);
    query.exec(strexec);
}

/**
 * @brief  alter sendStr by table
 * @param  table: 
 * @param  id: 
 * @param  sendStr: 
 */
void SqlList::alterSqlTableInfoSendStr(const QString &table,const int &id, const QString &sendStr)
{
    QSqlQuery query(sqlDatabase);
    QString strexec = QString("UPDATE %1 set sendStr=%3 where id=%2;")
                            .arg(table).arg(id).arg(sendStr);
    query.exec(strexec);
}

/**
 * @brief  cheak table row
 * @param  table: 
 * @param  toolTipStr: 
 */
void SqlList::checkSqlTableRow(const QString &table,const QString &toolTipStr)
{
    QSqlQuery query(sqlDatabase);
    QString strexec = QString("select * from sqlite_master where name='%1'  and sql like '%%2%';")
                            .arg(table).arg(toolTipStr);
    query.exec(strexec);
    if(query.next())
    {
        //query.exec(QString("alter table %1 add %2 varchar(1024);").arg(table).arg(toolTipStr));
    }
    else
    {
        if(toolTipStr == "toolTipStr")
            query.exec(QString("alter table %1 add %2 varchar(1024);").arg(table).arg(toolTipStr));
        else  if(toolTipStr == "example" || toolTipStr == "result" )
            query.exec(QString("alter table %1 add %2 varchar(10240);").arg(table).arg(toolTipStr));
        else  if(toolTipStr == "result")
            query.exec(QString("alter table %1 add %2 int;").arg(table).arg(toolTipStr));
    }
}

/**
 * @brief  alter info example result
 * @param  table: 
 * @param  id: 
 * @param  example: 
 */
void SqlList::alterSqlTableInfoExampleResult(const QString &table, const int &id, const QString &example)
{
    QSqlQuery query(sqlDatabase);
    QString strexec = QString("UPDATE %1 set example=%3 where id=%2;")
                            .arg(table).arg(id).arg(example);
    query.exec(strexec);
}

/**
 * @brief  select table by id
 * @param  table: 
 * @param  id: 
 * @return true: 
 * @return false: 
 */
bool SqlList::selectTableResult(const QString &table, const int &id)
{
    QString sql = QString("SELECT * FROM %1 WHERE id=%2").arg(table).arg(id);
    QSqlQuery query(sqlDatabase);
    query.exec(sql);
    QString result;
    while (query.next())
    {
        if(DEBUGLOG == 1)
        {
            L_LOG << QString("id: %1, time: %5")
                .arg(query.value("id").toInt())
                .arg(query.value("result").toInt());
        }
        result =  query.value("result").toString();
    }
    if(result == "PASS")
        return true;
    return false;
}


void SqlList::alterSqlTableInfoActualResult(const QString &table, const int &id, const QString &example)
{
    QSqlQuery query(sqlDatabase);
    QString strexec = QString("UPDATE %1 set actualt=%3 where id=%2;")
                            .arg(table).arg(id).arg(example);
    query.exec(strexec);
}

void SqlList::selectTableLineInfo(const QString &table, const int &id, bool &hex, QString &str, QString &sendStr, int &queue, int &time,QString &toolTipStr)
{

    QString sql = QString("SELECT * FROM %1 WHERE id=%2").
                        arg(table).arg(id);
    QSqlQuery query(sqlDatabase);
    query.exec(sql);

   while (query.next())
   {
       if(DEBUGLOG == 1)
       {
            L_LOG << QString("id: %1, hex: %2 ,str: %3,queue: %4, time: %5")
                .arg(query.value("id").toInt())
                .arg(query.value("hex").toInt())
                .arg(query.value("str").toString())
                .arg(query.value("queue").toInt())
                .arg(query.value("time").toInt());
        }
        toolTipStr = query.value("toolTipStr").toString();
        hex = query.value("hex").toBool();
        str = query.value("str").toString();
        queue = query.value("queue").toInt();
        time = query.value("time").toInt();
        sendStr = query.value("sendStr").toString();
   }
}

void SqlList::selectTableQueueLineInfo(const QString &table, QList<int> *id, QList<bool> *hex, QStringList *str, QStringList *sendStr,int &queue, QList<int> *time)
{

    QString sql = QString("SELECT * FROM %1 WHERE queue=%2")
        .arg(table).arg(queue);
    QSqlQuery query(sqlDatabase);
    query.exec(sql);

    while(query.next())
    {
        if(DEBUGLOG == 1)
        {
            L_LOG << QString("id: %1, hex: %2 ,str: %3,sendstr %6,queue: %4, time: %5")
                .arg(query.value("id").toInt())
                .arg(query.value("hex").toInt())
                .arg(query.value("str").toString())
                .arg(query.value("queue").toInt())
                .arg(query.value("time").toInt())
                .arg(query.value("sendStr").toInt());
        }
        hex->append(query.value("hex").toBool());
        str->append(query.value("str").toString());
        time->append(query.value("time").toInt());
        id->append(query.value("id").toBool());
        sendStr->append(query.value("sendStr").toString());

    }
}

