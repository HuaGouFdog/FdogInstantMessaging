#include "usersql.h"
#include<QVariant>
#include<QDebug>
usersql::usersql()
{
    
}

void usersql::conndata()
{
    if(QSqlDatabase::contains(QSqlDatabase::defaultConnection))
    {
        this->dbconn = QSqlDatabase::database(QSqlDatabase::defaultConnection);
    }
    else
    {
        this->dbconn = QSqlDatabase::addDatabase("QMYSQL");
    }
   this-> dbconn.setHostName("82.156.111.0");//主机名字
   this-> dbconn.setDatabaseName("fdogsql");//数据库名字
    //dbconn.open("root", "1111111"); //第一个参数写用户名，这里我们就写root就可以，第二个参数密码是mysql的登陆密码。
    //可以使用如下语句判断是否连接成功
    if(this->dbconn.open("root", "1111111"))
    {
    //如果判断为真，则连接成功
        //qDebug()<<"success";
    }
    this->query = (QSqlQuery)this->dbconn; //进行绑定 此后可以使用query对象对数据库进行操作。
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
