#ifndef USERSQL_H
#define USERSQL_H
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QString>
class usersql
{
private:
     QSqlDatabase dbconn;    //连接数据库
     QSqlQuery query;        //查询操作
public:
    usersql();
    bool conndata(); //连接数据库
    QString AccountIP(QString account);//获取目标ip
    QString update(QString account,QString port);
    QString update(QString port);
};

#endif // USERSQL_H
