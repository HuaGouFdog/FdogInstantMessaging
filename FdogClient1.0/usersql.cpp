#include "usersql.h"
#include<QMessageBox>
#include<QDebug>
#include<QNetworkAccessManager>
#include<QEventLoop>
#include<QNetworkReply>
#include<QPixmap>
#include<QBitmap>
#include<QPainter>
#include"globalobserver.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
Usersql::Usersql()
{
    
}

bool Usersql::connData()
{
    if(QSqlDatabase::contains(QSqlDatabase::defaultConnection))
    {
        this->dbconn = QSqlDatabase::database(QSqlDatabase::defaultConnection);
    }
    else
    {
        this->dbconn = QSqlDatabase::addDatabase("QMYSQL");
    }
    this-> dbconn.setHostName("xxxxxxx");//主机名字
    this-> dbconn.setDatabaseName("fdogsql");//数据库名字
    if(this->dbconn.open("root", "xxxxxxxx"))
    {
        this->query = (QSqlQuery)this->dbconn; //进行绑定 此后可以使用query对象对数据库进行操作。
        return true;
    }
    return false;
}

bool Usersql::queryUser(const QString &user, const QString &password)
{
    this->query.exec("select * from user");
    while(query.next())
    {
        //遍历账户
        if(user==(this->query.value(0).toString()))
        {
            if(password==(this->query.value(3).toString()))
            {
                this->iconurl = this->query.value(5).toString();
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

QPixmap Usersql::getIconUrl(const QString &url1)
{
    this->iconurl = url1;
    QUrl url(this->iconurl);
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply = manager.get(QNetworkRequest(url));
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    QByteArray jpegData = reply->readAll();
    this->icon.loadFromData(jpegData);
    return icon;
}

QPixmap Usersql::getPixmapIcon(const QString &url)
{
    QString strurl;
    //数据库查询该帐户
    this->query.exec("select * from user");
    while(query.next())
    {
        if(url==(this->query.value(0).toString()))
        {
            strurl = this->query.value(5).toString();
        }
    }
    QPixmap pixmap = getIconUrl(strurl);
    pixmap=this->icon.scaled(QSize(pixmap.width(), pixmap.height()), Qt::IgnoreAspectRatio);
    pixmap=Globalobserver::PixmapToRound(pixmap, pixmap.width()/2);
    return pixmap;
}

void Usersql::queryUserInfo(const QString &account)
{
    //获取账号基本信息
    this->query.exec("select * from user");
    while(query.next())
    {
        if(account==(this->query.value(0).toString()))
        {
            this->account = this->query.value(0).toString();            //账号
            this->phone = this->query.value(1).toString();              //手机号
            this->name = this->query.value(2).toString();               //昵称
            this->passwd = this->query.value(3).toString();             //密码
            this->signature =this->query.value(4).toString();           //个性签名
            this->icon = getIconUrl(this->query.value(5).toString());   //头像
            this->grade = this->query.value(6).toString();              //等级
            this->namet = this->query.value(7).toString();              //姓名
            this->sex =this->query.value(8).toString();                 //性别
            this->age = this->query.value(9).toString();                //年龄
            this->birthday = this->query.value(10).toString();          //生日
            this->profession =this->query.value(11).toString();         //职业
        }
    }
    //获取帐号分组信息
    this->query.exec("select * from grouping");
    while(query.next())
    {
        if(account==(this->query.value(2).toString()))
        {
            this->grouping.append(this->query.value(1).toString());
        }
    }
    //获取帐户好友信息
    this->query.exec("select * from friend");
    while(query.next())
    {
        if(account==(this->query.value(3).toString()))
        {
            this->mfriend.append(this->query.value(2).toString()+this->query.value(1).toString());
            this->mfriendname.append(this->query.value(4).toString());
        }
    }
}

void Usersql::AccountIP(const QString &ip)
{
    //-1离线 0在线 1F我吧 2隐身 3离开 4忙碌 5勿扰

    QString s = QString("update state set isline=%1,ip=\"%2\" where account=%3").arg(QString::number(this->sate),ip,this->getAccount());
    this->query.exec(s);
}
QString Usersql::getOtherAccountName(const QString &otheraccount)
{
    this->query.exec("select * from user");
    while(query.next())
    {
        if(otheraccount==(this->query.value(0).toString()))
        {
            return this->query.value(2).toString();
        }
    }
    return "";
}

QString Usersql::getOtherAccountSex(const QString &otheraccount)
{
    this->query.exec("select * from user");
    while(query.next())
    {
        if(otheraccount==(this->query.value(0).toString()))
        {
            return this->query.value(8).toString();
        }
    }
    return "";
}

QString Usersql::getOtherAccountAge(const QString &otheraccount)
{
    this->query.exec("select * from user");
    while(query.next())
    {
        if(otheraccount==(this->query.value(0).toString()))
        {
            return this->query.value(9).toString();
        }
    }
    return "";
}

QString Usersql::getOtherAccountProfession(const QString &otheraccount)
{
    this->query.exec("select * from user");
    while(query.next())
    {
        if(otheraccount==(this->query.value(0).toString()))
        {
            return this->query.value(11).toString();
        }
    }
    return "";
}

void Usersql::setverify(const QString &time, const QString &account, const QString &sate, const QString &name, const QString &grouping, const QString &otheraccount)
{
    //时间 添加方 状态 备注 分组 属于谁
    QString data = QString("INSERT INTO setverify VALUES('%1','%2','%3','%4','%5','%6')")
            .arg(time, account,sate, name, grouping, otheraccount);
    this->query.exec(data);
}

void Usersql::getverify(const QString &time, const QString &otheraccount, const QString &sate, const QString &name, const QString &grouping, const QString &account)
{
    QString data = QString("INSERT INTO getverify VALUES('%1','%2','%3','%4','%5','%6')")
            .arg(time,otheraccount,sate, name, grouping, account);
    qDebug()<<data;
    this->query.exec(data);
}

QString Usersql::getverifygrouping(const QString &account, const QString &otheraccount)
{
    QString data = QString("select * from setverify where account='%1' and otheraccount = '%2' ").arg(account,otheraccount);
    this->query.exec(data);
    while(query.next())
    {
        return this->query.value(4).toString();
    }
    return " ";
}

void Usersql::updatagrouping(const QString &otheraccount,const QString &account)
{
    //我是1234578
    QString accountgrouping;//12345678的分组 当前帐号分组名称
    QString accountname;//获取对方账号名字
    QString accountid;//获取当前帐户分组id
    QString otheraccountgrouping; //获取对方账号分组名称
    QString otheraccountname; //获取自己账号名字
    QString otheraccountid;//获取对方分组id
    //获取双方分组信息
    QString data = QString("select * from getverify where otheraccount= '%1' and account = '%2' ")
            .arg(otheraccount,account);
    this->query.exec(data);
    while(query.next())
    {
        accountname = this->query.value(3).toString();//获取对方账号名字
        accountgrouping = this->query.value(4).toString();//获取当前帐号分组名称
    }

    data = QString("select * from setverify where account = '%1' and otheraccount= '%2'")
            .arg(account,otheraccount);
    this->query.exec(data);
    while(query.next())
    {
        otheraccountname = this->query.value(3).toString();//获取自己账号名字
        otheraccountgrouping = this->query.value(4).toString();//获取对方账号分组名称
    }
    //获取分组对应ID
    data = QString("select * from grouping where account ='%1' and name ='%2'").arg(account,accountgrouping);
    this->query.exec(data);
    while(query.next())
    {
        accountid = this->query.value(0).toString();//获取1分组id
    }
    data = QString("select * from grouping where account ='%1' and name ='%2'").arg(otheraccount,otheraccountgrouping);
    this->query.exec(data);
    while(query.next())
    {
        otheraccountid = this->query.value(0).toString();//获取2分组id
    }
    //写入数据库好友表
    qDebug()<<"由"+otheraccount+"向"+account+"发起的添加好友申请，如果"+account+"同意，"
                                                                  "就将"+account+"的名字设置为"+otheraccountname+"放在"+otheraccount+"的"+otheraccountgrouping+"分组下";
    data = QString("INSERT INTO friend VALUES('123','%1','%2','%3','%4')")
            .arg(account, otheraccountid,otheraccount,otheraccountname);
    this->query.exec(data);

    qDebug()<<"账号"+account+"接收到"+otheraccount+"发来的添加好友申请，如果"+account+"同意，"
                                                                     "就将"+otheraccount+"的名字设置为"+accountname+"放在"+account+"的"+accountgrouping+"分组下";
    data = QString("INSERT INTO friend VALUES('123','%1','%2','%3','%4')")
            .arg(otheraccount, accountid,account,accountname);//好友账号，好友所在分组，本身账号，好友名字
    this->query.exec(data);

    data = QString("update setverify set state='%1' where account='%2' and otheraccount='%3' ")
            .arg("同意",account,otheraccount);//好友账号，好友所在分组，本身账号，好友名字
    this->query.exec(data);
}

QString Usersql::isLine(const QString &account)
{
    QString line ="-1";
    QString ip="";
    QString data = QString("select * from state where account='%1'").arg(account);
    this->query.exec(data);
    while(query.next())
    {
        line = this->query.value(1).toString();//获取在线状态
        ip = this->query.value(2).toString();//获取ip
    }
    if(line!="-1")//如果在线就返回ip
    {
        return ip;
    }
    return "";
}

QPixmap Usersql::getIcon() const
{
    return icon;
}

void Usersql::setIcon(const QPixmap &value)
{
    icon = value;
}

QString Usersql::getIP() const
{
    return IP;
}

void Usersql::setIP(const QString &value)
{
    IP = value;
}

int Usersql::getSate() const
{
    return sate;
}

void Usersql::setSate(int value)
{
    sate = value;
}

QString Usersql::getAccount() const
{
    return account;
}

void Usersql::setAccount(const QString &value)
{
    account = value;
}

QString Usersql::getName() const
{
    return name;
}

void Usersql::setName(const QString &value)
{
    name = value;
}

QString Usersql::getSignature() const
{
    return signature;
}

void Usersql::setSignature(const QString &value)
{
    signature = value;
}

QString Usersql::getPasswd() const
{
    return passwd;
}

void Usersql::setPasswd(const QString &value)
{
    passwd = value;
}

QString Usersql::getAge() const
{
    return age;
}

void Usersql::setAge(const QString &value)
{
    age = value;
}

QStringList Usersql::getGrouping() const
{
    return grouping;
}

void Usersql::setGrouping(const QStringList &value)
{
    grouping = value;
}

QStringList Usersql::getMfriend() const
{
    return mfriend;
}

void Usersql::setMfriend(const QStringList &value)
{
    mfriend = value;
}

QStringList Usersql::getMfriendname() const
{
    return mfriendname;
}

void Usersql::setMfriendname(const QStringList &value)
{
    mfriendname = value;
}

QString Usersql::getGrade() const
{
    return grade;
}

void Usersql::setGrade(const QString &value)
{
    grade = value;
}

QString Usersql::getProfession() const
{
    return profession;
}

void Usersql::setProfession(const QString &value)
{
    profession = value;
}

QString Usersql::getSex() const
{
    return sex;
}

void Usersql::setSex(const QString &value)
{
    sex = value;
}

