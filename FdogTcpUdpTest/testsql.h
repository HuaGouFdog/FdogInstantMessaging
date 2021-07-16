#ifndef TESTSQL_H
#define TESTSQL_H
#include<QString>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QVariant>
class Testsql
{
private:
    QSqlDatabase dbconn;    //连接数据库
    QSqlQuery query;        //查询操作
public:
    Testsql();
    bool connData(); //连接数据库
    bool queryUser(const QString &user,const QString &password);    //查询是否有该账户
    QString queryState(const QString & account);
};

#endif // TESTSQL_H
