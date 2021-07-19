#ifndef USERSQL_H
#define USERSQL_H
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QString>
#include<QPixmap>

class Usersql
{
private:
    QString IP = "";
    QSqlDatabase dbconn;    //连接数据库
    QSqlQuery query;        //查询操作
    QString account = "";   //主体账号
    QString phone = "";     //主体手机号
    QString name = "";      //主体昵称
    QString passwd = "";    //主体密码
    QString signature ="";  //主体个性签名
    QString iconurl = "";   //主体地址
    QPixmap icon;           //主体头像
    QString grade = "";     //主体帐号等级
    QString namet = "";     //主体姓名
    QString sex = "";       //主体性别
    QString age = "";       //主体年龄
    QString birthday = "";  //主体生日
    QString profession = "";//主体职业
    QStringList grouping;   //分组信息
    QStringList mfriend;    //好友帐户
    QStringList mfriendname;//好友昵称
    int sate = -1;             //主体账号登录显示状态 -1离线 0在线 1F我吧 2隐身 3离开 4忙碌 5勿扰
    bool power; //权限
public:
    Usersql();
    bool connData(); //连接数据库
    bool queryUser(const QString &user,const QString &password);    //查询是否有该账户
    QPixmap getIconUrl(const QString &url);                         //获取账户图片
    QPixmap getPixmapIcon(const QString &url);                       //调用geticonurl函数并对图片进行圆角化
    void queryUserInfo(const QString &account);    //获取账号基本信息
    void AccountIP(const QString &ip);//获取ip在线状态，包括在线，隐身，Q我，忙碌，离线等等
    QString getOtherAccountName(const QString &otheraccount);  //根据账号获取名字
    QString getOtherAccountSex(const QString &otheraccount);   //根据账号获取性别
    QString getOtherAccountAge(const QString &otheraccount);   //根据账号获取年龄
    QString getOtherAccountProfession(const QString &otheraccount);//根据账号获取职业
    void setverify(const QString &time,const QString &account,const QString &sate,const QString &name,const QString &grouping,const QString &otheraccount);//添加好友数据
    void getverify(const QString &time,const QString &otheraccount,const QString &sate,const QString &name,const QString &grouping,const QString &account);//添加好友数据
    QString getverifygrouping(const QString &account,const QString &otheraccount);//获取主动添加方设置的分组
    void updatagrouping(const QString &otheraccount,const QString &account);//暂无
    QString isLine(const QString &account);
    //getset函数
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
    QString getIP() const;
    void setIP(const QString &value);
    int getA() const;
    void setA(int value);
    int getSate() const;
    void setSate(int value);
};

#endif // USERSQL_H
