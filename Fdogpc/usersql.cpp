#include "usersql.h"
#include<QMessageBox>
#include<QDebug>
#include<QNetworkAccessManager>
#include<QEventLoop>
#include<QNetworkReply>
#include<QPixmap>
#include<QBitmap>
#include<QPainter>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

void Usersql::conndata()
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
    //dbconn.open("root", "3226960*"); //第一个参数写用户名，这里我们就写root就可以，第二个参数密码是mysql的登陆密码。
    //可以使用如下语句判断是否连接成功
    if(this->dbconn.open("root", "3226960*"))
    {
    //如果判断为真，则连接成功
        //qDebug()<<"success";
    }
    this->query = (QSqlQuery)this->dbconn; //进行绑定 此后可以使用query对象对数据库进行操作。
}

bool Usersql::queryuser(QString user, QString password)
{
    this->query.exec("select * from user");
        while(query.next())
        {
            //遍历账户
            qDebug()<<this->query.value(0).toString();
            if(user==(this->query.value(0).toString()))
            {
                if(password==(this->query.value(3).toString()))
                {
                   this->iconurl = this->query.value(5).toString();
                   qDebug()<<"该账户存在";
                   return true;
                }
                else
                {
                   qDebug()<<"该账户不存在";
                   return false;
                }
            }
        }

        return false;
}

QPixmap Usersql::geticonurl(QString url1)
{
    this->iconurl = url1;
    QUrl url(this->iconurl);
    qDebug()<<url;
        QNetworkAccessManager manager;
        QEventLoop loop;
        // qDebug() << "Reading picture form " << url;
        QNetworkReply *reply = manager.get(QNetworkRequest(url));
        //请求结束并下载完成后，退出子事件循环
        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        //开启子事件循环
        loop.exec();
        QByteArray jpegData = reply->readAll();
        this->icon.loadFromData(jpegData);
        return icon;
}

QPixmap Usersql::getPixmapIcon(QString url)
{
    QString strurl;
    //数据库查询该帐户
    this->query.exec("select * from user");
        while(query.next())
        {
            //遍历账户
            if(url==(this->query.value(0).toString()))
            {
                strurl = this->query.value(5).toString();
            }
        }
        qDebug()<<strurl;
    QPixmap a = geticonurl(strurl);
    a=this->icon.scaled(QSize(a.width(), a.height()), Qt::IgnoreAspectRatio);
    a=PixmapToRound(a, a.width()/2);
    return a;
}

 QPixmap Usersql::PixmapToRound(QPixmap &src, int radius)
{
    if (src.isNull()) {
            return QPixmap();
        }
        QSize size(2*radius, 2*radius);
        //掩码图（黑白色）
        QBitmap mask(size);
        QPainter painter(&mask);
        //Antialiasing：反走样（抗锯齿）
        painter.setRenderHint(QPainter::Antialiasing);
        //SmoothPixmapTransform：用来在对图片进行缩放时启用线性插值算法而不是最邻近算法
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        //填充矩形
        painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
        //画刷
        painter.setBrush(QColor(0, 0, 0));
        //绘制圆角矩形
        /*QPainter::drawRoundedRect
           (const QRectF &rect,
            qreal xRadius,
            qreal yRadius,
            Qt::SizeMode mode = Qt::AbsoluteSize)
        */
        painter.drawRoundedRect(0, 0, size.width(), size.height(), 190, 190);
        //自适应图片
        QPixmap image = src.scaled(size);
        //setMask：创建不规则窗口使用
        image.setMask(mask);
        return image;
}

void Usersql::queryUserInfo(QString account)
{
    //获取帐户个人基本信息
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
            this->icon = geticonurl(this->query.value(5).toString());   //头像
            this->grade = this->query.value(6).toString();              //等级
            this->namet = this->query.value(7).toString();              //姓名
            this->sex =this->query.value(8).toString();                 //性别
            this->age = this->query.value(9).toString();                //年龄
            this->birthday = this->query.value(10).toString();          //生日
            this->profession =this->query.value(11).toString();         //职业
        }
    }
    //获取帐户分组信息
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


void Usersql::conndataOther(QString mysqlname)
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
   this-> dbconn.setDatabaseName(mysqlname);//数据库名字
    //dbconn.open("root", "3226960*"); //第一个参数写用户名，这里我们就写root就可以，第二个参数密码是mysql的登陆密码。
    //可以使用如下语句判断是否连接成功
    if(this->dbconn.open("root", "3226960*"))
    {
    //如果判断为真，则连接成功
        qDebug()<<"success";
    }
    this->query = (QSqlQuery)this->dbconn; //进行绑定 此后可以使用query对象对数据库进行操作。
}

QStringList Usersql::getGroupname_Groupcount()
{
    QStringList GG;
    //qDebug()<<QString("select * from `%1`").arg(this->getAccount());
    this->query.exec(QString("select * from `%1`").arg(this->getAccount()));
        while(query.next())
        {
            //qDebug()<<this->query.value(0).toString();
            GG.append(this->query.value(0).toString());
            GG.append(this->query.value(1).toString());
        }
        //qDebug()<<"分组信息已经获取";
        return GG;
}

void Usersql::AccountIP1(QString ip)
{
    QString s = QString("update state set isline=%1,ip=\"%2\" where account=%3").arg("1",ip,this->getAccount());
    this->query.exec(s);
}

void Usersql::AccountIP2(QString ip)
{
    QString s = QString("update state set isline=%1,ip=\"%2\" where account=%3").arg("0",ip,this->getAccount());
    this->query.exec(s);
}

QString Usersql::getOtherAccountName(QString otheraccount)
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

QString Usersql::getOtherAccountSex(QString otheraccount)
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

QString Usersql::getOtherAccountAge(QString otheraccount)
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

QString Usersql::getOtherAccountProfession(QString otheraccount)
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

void Usersql::setverify(QString time, QString account, QString sate, QString name, QString grouping, QString otheraccount)
{
    //时间 添加方 状态 备注 分组 属于谁
    QString data = QString("INSERT INTO setverify VALUES('%1','%2','%3','%4','%5','%6')")
            .arg(time, account,sate, name, grouping, otheraccount);
    this->query.exec(data);
}

void Usersql::getverify(QString time, QString otheraccount, QString sate, QString name, QString grouping, QString account)
{
    QString data = QString("INSERT INTO getverify VALUES('%1','%2','%3','%4','%5','%6')")
            .arg(time,otheraccount,sate, name, grouping, account);
    qDebug()<<data;
    this->query.exec(data);
}

QString Usersql::getverifygrouping(QString account, QString otheraccount)
{
    QString data = QString("select * from setverify where account='%1' and otheraccount = '%2' ").arg(account,otheraccount);
    this->query.exec(data);
    while(query.next())
    {
        return this->query.value(4).toString();
    }
    return " ";
}

void Usersql::updatagrouping(QString otheraccount,QString account)
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

QPixmap Usersql::getIcon() const
{
    return icon;
}

void Usersql::setIcon(const QPixmap &value)
{
    icon = value;
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

Usersql::Usersql()
{
    
}
