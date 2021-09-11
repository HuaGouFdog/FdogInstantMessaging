#include "usersql.h"
#include<QVariant>
#include<QDebug>
usersql::usersql()
{
    
}

bool usersql::conndata()
{
    if(QSqlDatabase::contains(QSqlDatabase::defaultConnection))
    {
        this->dbconn = QSqlDatabase::database(QSqlDatabase::defaultConnection);
    }
    else
    {
        this->dbconn = QSqlDatabase::addDatabase("QMYSQL");
    }
   this-> dbconn.setHostName("82.156.111.139");//主机名字
   this-> dbconn.setDatabaseName("fdogsql");//数据库名字
   if(this->dbconn.open("root", "xxxxx"))
   {
       this->query = (QSqlQuery)this->dbconn; //进行绑定 此后可以使用query对象对数据库进行操作
       return true;
   }
   return false;
}
QString usersql::AccountIP(QString account)
{
    this->query.exec("select * from state");
    while(query.next())
    {
        if(this->query.value(0).toString()==account)
        {
            return this->query.value(3).toString();
        }
    }
    return "";
}

QString usersql::update(QString account, QString port)
{
    QString s = QString("update state set port=%1 where account=%2").arg(port,account);
    qDebug()<<s;
    this->query.exec(s);
    return "";
}

QString usersql::update(QString port)
{
    QString s = QString("update state set port=0000 where port=%2").arg(port);
    qDebug()<<s;
    this->query.exec(s);
    return "";
}
