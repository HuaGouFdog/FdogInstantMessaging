#ifndef USERSQL_H
#define USERSQL_H
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QString>
#include<QPixmap>

class Usersql
{
private:
     QSqlDatabase dbconn;    //连接数据库
     QSqlQuery query;        //查询操作
     QString account = "";   //账号
     QString phone = "";     //手机
     QString name = "";      //昵称
     QString passwd = "";    //密码
     QString signature ="";  //个性签名
     QString iconurl = "";   //地址
     QPixmap icon = "";      //头像
     QString grade = "";     //帐号等级
     QString namet = "";     //姓名
     QString sex = "";       //性别
     QString age = "";       //年龄
     QString birthday = "";  //生日
     QString profession = "";//职业
     QStringList grouping;   //分组信息
     QStringList mfriend;    //好友帐户
     QStringList mfriendname;//好友昵称
     bool power; //权限
public:
    Usersql();
    void conndata(); //连接数据库
    bool queryuser(QString user,QString password); //查询是否有该账户
    QPixmap geticonurl(QString url);//获取账户图片
    QPixmap getPixmapIcon(QString url);//根据账户获取头像
    QPixmap PixmapToRound(QPixmap &src, int radius);
    void queryUserInfo(QString account); //获取账号信息
    void conndataOther(QString mysqlname); //获取分组信息连接
    QStringList getGroupname_Groupcount();//获取分组名称,人数
    void AccountIP1(QString ip);//获取ip更新在线状态
    void AccountIP2(QString ip);//获取ip更新离线状态
    QString getOtherAccountName(QString otheraccount);//根据账号获取名字
    QString getOtherAccountSex(QString otheraccount);//根据账号获取性别
    QString getOtherAccountAge(QString otheraccount);//根据账号获取年龄
    void setverify(QString time,QString account,QString sate,QString name,QString grouping,QString otheraccount);
    void getverify(QString time,QString otheraccount,QString sate,QString name,QString grouping,QString account);

    //getset
    QPixmap getIcon() const;
    void setIcon(const QPixmap &value);
    QString getAccount() const;
    void setAccount(const QString &value);
    QString getName() const;
    void setName(const QString &value);
    QString getSignature() const;
    void setSignature(const QString &value);
    QString getPasswd() const;
    void setPasswd(const QString &value);
    QString getAge() const;
    void setAge(const QString &value);
    QStringList getGrouping() const;
    void setGrouping(const QStringList &value);
    QStringList getMfriend() const;
    void setMfriend(const QStringList &value);
    QStringList getMfriendname() const;
    void setMfriendname(const QStringList &value);
    QString getGrade() const;
    void setGrade(const QString &value);
    QString getProfession() const;
    void setProfession(const QString &value);
    QString getSex() const;
    void setSex(const QString &value);
};

#endif // USERSQL_H
