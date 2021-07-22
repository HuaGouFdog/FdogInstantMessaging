#include "testsql.h"
Testsql::Testsql()
{

}

bool Testsql::connData()
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
    if(this->dbconn.open("root", "3226960*"))
    {
        this->query = (QSqlQuery)this->dbconn; //进行绑定 此后可以使用query对象对数据库进行操作。
        return true;
    }
    return false;
}

bool Testsql::queryUser(const QString &user, const QString &password)
{
    this->query.exec("select * from user where account='"+user+"'");
    while(query.next())
    {
        //验证密码
        if(password==(this->query.value(3).toString()))return true;
    }
    return false;
}

QString Testsql::queryState(const QString &account)
{
    QString data = "";
    this->query.exec("select * from state where account='"+account+"'");
    while(query.next())
    {
        data = this->query.value(0).toString()+this->query.value(1).toString()+this->query.value(2).toString()+this->query.value(3).toString()+this->query.value(4).toString();
    }
    return data;
}
