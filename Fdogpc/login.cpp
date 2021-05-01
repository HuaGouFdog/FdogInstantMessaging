#include "login.h"
#include "ui_login.h"
#include"mainwindow.h"
#include<QPainter>
#include <QDesktopServices>
#include<QListView>
#include<QDebug>
#include<qdrawutil.h>
#include<QGraphicsDropShadowEffect>
#include<QDir>
#include<QCoreApplication>
#include<QFile>
#include<QTextCodec>
#include"usersql.h"
#include<QMenu>
#include<QMessageBox>
#include<algorithm>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    //this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint);
    //窗体风格
    this->setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);//WindowStaysOnTopHint窗口顶置
    //窗体透明
    setAttribute(Qt::WA_TranslucentBackground);
    //初始化系统托盘
    systemtrayicon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/lib/qusefdogicon.png");
    //添加图标
    systemtrayicon->setIcon(icon);
    //当鼠标悬浮，显示文字
    systemtrayicon->setToolTip(QObject::trUtf8("Fdog"));
    //显示图标
    menu = new QMenu(this);
    m_pShowAction = new QAction("打开主界面");
    m_pCloseAction = new QAction("退出");
    menu->addAction(m_pShowAction);
    menu->addSeparator();
    menu->addAction(m_pCloseAction);
    connect(m_pShowAction,SIGNAL(triggered(bool)),this,SLOT(showwidget()));
    connect(m_pCloseAction,SIGNAL(triggered(bool)),this,SLOT(closewidget()));
    systemtrayicon->setContextMenu(menu);
    systemtrayicon->show();
    //加载动态图
    m_movie = new QMovie(":/lib/mian.gif");
    //设置动态图大小
    m_si.setWidth(431);
    m_si.setHeight(151);
    m_movie->setScaledSize(m_si);
    //添加动态图
    ui->mian_label->setMovie(m_movie);
    //开始动画
    m_movie->start();
    //创建一个action
    QAction * searchAction = new QAction(ui->lineEdit);
    //填加图标
    searchAction->setIcon(QIcon(":/lib/suo.png"));
    //表示action所在方位（左侧）。
    ui->lineEdit->addAction(searchAction,QLineEdit::LeadingPosition);

    QAction * searchAction_2 = new QAction(ui->lineEdit);
    searchAction_2->setIcon(QIcon(":/lib/jianpan.png"));
    //表示action所在方位（右侧）。
    ui->lineEdit->addAction(searchAction_2,QLineEdit::TrailingPosition);

    QAction * searchAction_3 = new QAction(ui->lineEdit);
    searchAction_3->setIcon(QIcon(":/lib/fdog.png"));
    //表示action所在方位（左侧）。
    ui->lineEdit_2->addAction(searchAction_3,QLineEdit::LeadingPosition);
    //连接数据库
    this->sqconn.conndata();
    //获取本地信息
    //获取exe运行目录
    QString fileName1 = QCoreApplication::applicationDirPath()+"//..//FdogUserFile";
    //获取目录
    infoList = GetDirNameList(fileName1);
    //QTextCodec *codec = QTextCodec::codecForName("GBK");
    //加载自定义的下拉列表框
    m_AccountList = new QListWidget(this);
    m_AccountList->setFocusPolicy(Qt::NoFocus);
    ui->comboBox->setModel(m_AccountList->model());
    ui->comboBox->setView(m_AccountList);
    //创建信息
    qDebug()<<"数据长度："<<infoList.size();
    int infosize =0;
    myMapper = new QSignalMapper(this);
    for(int i =0;i<infoList.size();i++)
    {
        //获取帐号
        QString local_account = infoList.at(i);
        //获取昵称
        QString local_name;
        //获取密码
        QString local_passwd;
        //获取头像
        QString ic = fileName1+QString("//%1//%2.jpg").arg(infoList.at(i)).arg(infoList.at(i));
        //qDebug()<<"保存的图片"<<ic;
        this->icon.append(ic);
        QIcon local_icon(ic);
        //qDebug()<<local_icon;
        QFile file_my(fileName1+QString("//%1//data.txt").arg(infoList.at(i)));
        //qDebug()<<file_my;
        //打开文件
        if(!file_my.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"文件打开失败"<<endl;
        }
        this->ispasswd = false;
        while(!file_my.atEnd())
        {
            infopasswd.append("");
            QByteArray line = file_my.readLine();
            QString str(QString::fromLocal8Bit(line.data()));
            //qDebug()<< str;
            if(this->ispasswd)
            {
                //还应该查看是否有密码存在，如果有则读取，并显示勾中
                infopasswd.insert(i,str);
                //qDebug()<<"有密码"<<str;
                local_passwd.append(str);
                this->ispasswd =false;
            }
            else
            {
                local_name.append(str);
                this->ispasswd =true;
            }
            qDebug()<<infopasswd;
        }
        QHBoxLayout *horLayout = new QHBoxLayout();//水平布局
        QLabel * la = new QLabel();
        QString s = ic;
        la->setStyleSheet(QString("border-image: url(%1);border-radius:17px;").arg(s));
        la->setFixedSize(34,34);
        QLabel * la2 = new QLabel(QString("%1\n%2").arg(local_name.left(local_name.length()-1),local_account));
        QPushButton * b1 = new QPushButton();
        b1->setFixedSize(32,32);
        b1->setStyleSheet("QPushButton{background:rgba(200,200,200,0);border-style:solid;border-image: url(:/lib/delete.png);}"
                          "QPushButton:hover{background:rgba(200,200,200,0);border-style:solid;border-image: url(:/lib/delete2.png);}");
        connect(b1,SIGNAL(clicked(bool)),myMapper,SLOT(map()));
        myMapper->setMapping(b1,infosize);
        infoListsign.append(infosize);
        qDebug()<<"按钮值为："<<infosize;
        infosize++;
        horLayout->addWidget(la);
        horLayout->addWidget(la2);
        horLayout->addWidget(b1);
        QWidget *widget =new QWidget(this);
        widget->setLayout(horLayout);
        QListWidgetItem * Listitem = new QListWidgetItem(m_AccountList);
        m_AccountList->setItemWidget(Listitem,widget);
    }

    connect(myMapper,SIGNAL(mapped(int)),this,SLOT(deleteaccount(int)));
}

Login::~Login()
{
    delete ui;
}

QStringList Login::GetDirNameList(const QString &strDirpath)
{
    QDir dir(strDirpath);
    QFileInfoList Info_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QListIterator<QFileInfo> Iterator(Info_list);
    QStringList strDirNameList;
    QFileInfo Info;
    while (Iterator.hasNext())
    {
        Info = Iterator.next();
        if (Info.isDir())
        {
            strDirNameList << QDir(Info.absoluteFilePath()).dirName();
        }
    }
    return strDirNameList;
}

void Login::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
    QPainter painter(this);
    QPixmap pixmap(":/lib/background.png");
    qDrawBorderPixmap(&painter, this->rect(), QMargins(0, 0, 0, 0), pixmap);
    QRect rect(this->rect().x()+8, this->rect().y()+8, this->rect().width()-16, this->rect().height()-16);
    painter.fillRect(rect, QColor(255, 255, 255));
}

void Login::mousePressEvent(QMouseEvent *event)
{
    isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    last = event->globalPos();
}

void Login::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget)
        {
            int dx = event->globalX() - last.x();
            int dy = event->globalY() - last.y();
            last = event->globalPos();
            move(x()+dx, y()+dy);
        }
}

void Login::mouseReleaseEvent(QMouseEvent *event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x()+dx, y()+dy);
    isPressedWidget = false; // 鼠标松开时，置为false
}

void Login::on_toolButton_2_clicked()
{
    this->close();
    this->systemtrayicon->hide();
}

void Login::on_toolButton_clicked()
{
    this->hide();
    connect(systemtrayicon,SIGNAL(activated(QSystemTrayIcon::ActivationReason))
            ,this,SLOT(on_activatedSysTratIcon(QSystemTrayIcon::ActivationReason)));
}

void Login::on_register_btn_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://www.fdogcsdn.cn/FdogMaven/index.jsp")));
}

void Login::on_activatedSysTratIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:
        //单击托盘图标
        this->show();
        //delete systemtrayicon;
        break;
    case QSystemTrayIcon::DoubleClick:
        //双击托盘图标
        break;
    default:
        break;
    }
}

void Login::on_comboBox_currentIndexChanged(int index)
{
    ui->checkBox_2->setChecked(false);
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText(infoList.at(index));
    if(infopasswd.at(index)!="")
    {
        ui->lineEdit->setText(infopasswd.at(index));
        ui->checkBox_2->setChecked(true);
    }
    QString icon1 = icon.at(index);
    ui->label_4->setStyleSheet(QString("border-image: url(%1);border-width:0px;border-style:solid;border-color: rgb(255, 255, 255);border-radius:33px;").arg(icon1));
    //开始考虑用户是否选择记住密码
}

void Login::on_pushButton_clicked()
{
    ui->pushButton->setText("登录中...");
    bool isuser = sqconn.queryuser(ui->lineEdit_2->text(),ui->lineEdit->text());//输入内容查询
    //用户是否存在
    if(isuser)
    {
        //只获取账号
        QString account = ui->lineEdit_2->text(); //账户
        this->sqconn.queryUserInfo(account);//根据账户获取昵称，密码(如果用户选择记住密码，则保存密码)，头像
        QString name = sqconn.getName();
        QString passwd="";
        if(ui->checkBox_2->isChecked())//判断用户是否保存密码
        {
            passwd = sqconn.getPasswd();
        }
        QPixmap icon = sqconn.getIcon();
        //获取程序当前运行目录
        QString fileName = QCoreApplication::applicationDirPath();
        //用户目录
        QString add = "//..//FdogUserFile";
        //创建用户文件夹
        fileName = fileName + add +QString("//%1").arg(account);
        //qDebug()<<fileName;
        //信息保存
        QDir * file = new QDir;
        //文件夹是否存在，若存在则表示信息已经存在，只需要更新内容即可。
        bool exist_1 = file->exists(fileName);
        if(exist_1)
        {
            //qDebug()<<"创建";
            QFile file(fileName +"//data.txt");
            qDebug()<<fileName +"//data.txt";
            if(file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate))
            {
                //qDebug()<<"txt文件创建成功";
            }
            QTextStream stream(&file);
            //写入
            if(passwd=="")stream<<name;
            else stream<<name<<"\n"<<passwd;
            //qDebug()<<"tup:"<<account;
            icon.save(fileName+QString("//%1.jpg").arg(account),"JPG");
            file.close();
        }
        else
        {   //如果不存在则创建
            bool ok = file->mkpath(fileName);
            if(ok)
            {
                //qDebug()<<"创建";
                QFile file(fileName +"//data.txt");
                qDebug()<<fileName +"//data.txt";
                if(file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate))
                {
                    //qDebug()<<"txt文件创建成功";
                }
                QTextStream stream(&file);
                if(passwd=="")stream<<name;
                else stream<<name<<"\n"<<passwd;
                icon.save(fileName+QString("//%1.jpg").arg(account),"JPG");
                file.close();
            }
            else
            {
                qDebug()<<"未创建成功";
            }
        }
        this->hide();//隐藏登录窗口
        systemtrayicon->hide();//隐藏系统托盘
        //初始化主界面
        w = new MainWindow(account);
        //显示主界面
        w->show();
        //显示系统托盘图标
        w->showicon();
    }
   else//该用户不存在
    {

    }
}

void Login::showwidget()
{
    this->show();
}

void Login::closewidget()
{
    this->close();
}

void Login::deleteaccount(int i) //传进来的是标记数字
{
    //QMessageBox::information(NULL, "提示", "是否要删除本次该账号信息",QMessageBox::Yes|QMessageBox::No);
    QMessageBox *message = new QMessageBox(QMessageBox::Question,tr("提示"), tr("是否要删除该账号信息"), QMessageBox::Yes | QMessageBox::No,this);
    int result = message->exec();
    //infoListsign  0 1 2 3  0 1 2 3  0 1 2  1 2 3
    //这里有一个需要注意的点，当初给每个按钮标记的数字是不会变的，但是当我们删除列表中的一个item之后，列表中的其他item会自动排序
    //所以无法单靠当初标记的数字来进行简单删除，我们可以借助一个vector，将标记的数字存放，而正在要删除的值是标记数字的下标
    //如果单靠标记的数字来判断，比如我要删除第一行，就是0，这时它的下标也是0，这没有问题，但是第二次就会出问题，我要删除第二行，当我点击删除
    //其实传回的值应该是1，但是列表自动排序之后，原来的1变成了0，原来的2变了1.
    switch(result)
    {
    case QMessageBox::Yes:
        infoList.removeAt(infoListsign.indexOf(i));
        infopasswd.removeAt(infoListsign.indexOf(i));
        icon.removeAt(infoListsign.indexOf(i));

        //当前索引是否为删除对象，若是，则使用第一个
        if(infoListsign.indexOf(i)==ui->comboBox->currentIndex())
        {

            if(infoList.length()!=0)
            {
                ui->comboBox->setCurrentIndex(0);
            }
        }
        if(infoList.length()==0)
        {
            ui->lineEdit_2->setText("");
            ui->lineEdit->setText("");
            ui->label_4->setStyleSheet("border-image: url(:/lib/fdogicon.png);border-width:0px;border-style:solid;border-color: rgb(255, 255, 255);border-radius:33px;");
            this->m_AccountList->setItemHidden(this->m_AccountList->item(0),true);
            return;
        }
        //隐藏账号信息  this->m_AccountList->setItemHidden(this->m_AccountList->item(i),true);
        //删除账号信息
        QListWidgetItem * item;
        qDebug()<<"出错0";
        qDebug()<<"infoListsign.indexOf(i)"<<infoListsign.indexOf(i);
        item = this->m_AccountList->takeItem(infoListsign.indexOf(i));
        qDebug()<<"出错1";
        this->m_AccountList->removeItemWidget(item);
        qDebug()<<"出错2";
        delete item;
        infoListsign.erase(infoListsign.begin()+infoListsign.indexOf(i));
        break;
    case QMessageBox::No:
        //什么也不做
    break;
    }
}



