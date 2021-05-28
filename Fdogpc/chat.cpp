#include "chat.h"
#include "ui_chat.h"
#include<QTcpServer>
#include<QTcpSocket>
#include<QHostInfo>
#include<QDateTime>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
Chat::Chat(QString otheraccount,QString name,MainWindow * main,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    this->otheraccount=otheraccount;
    this->name=name;
    this->setWindowTitle(name);
    tcpClient=new QTcpSocket(this);
    LabSocketate = new QLabel("Socket状态：");
    LabSocketate->setMinimumWidth(250);

    //ui->statusBar->addWidget(LabSocketate);
    //QString localIP = getLocalIP();
    ui->label->setText(this->name);
    //接收主窗口的消息信号
    mainwindow = main;
    connect(mainwindow,SIGNAL(sendChatData(QString)),this,SLOT(onSocketReadyRead(QString)));
}

QWidget *Chat::CreateWidgetL()
{
    //对面发送的，应显示在左边
    QWidget * datawidget = new QWidget();
    return datawidget;
}

QWidget *Chat::CreateWidgetR()
{
    //自己发送的，应显示在右边
    QWidget * datawidget = new QWidget();
//    QHBoxLayout *horLayout1 = new QHBoxLayout();//水平布局
//    QPushButton * IconButton = new QPushButton(QIcon(":\lib\10001.jpg"));
//    QLabel * nameLabel = new QLabel("今夜无风：312312321");
//    horLayout1->addWidget(IconButton);
//    horLayout1->addWidget(nameLabel);
//    QHBoxLayout *horLayout2 = new QHBoxLayout();//水平布局
//    QLabel * userLabel = new QLabel(data);
//    horLayout2->addWidget(userLabel);//添加消息
//    datawidget->setLayout(horLayout1);
//    datawidget->setLayout(horLayout2);
    return datawidget;
}

Chat::~Chat()
{
    delete ui;

}

void Chat::closeEvent(QCloseEvent *e)
{
    qDebug()<<"关不掉";
    //this->hide();
    e->ignore();
    e->accept();
}

QString Chat::getName() const
{
    return name;
}

void Chat::setName(const QString &value)
{
    name = value;
}

bool Chat::getIsread() const
{
    return isread;
}

void Chat::setIsread(bool value)
{
    isread = value;
}

MainWindow *Chat::getMainwindow() const
{
    return mainwindow;
}

void Chat::setMainwindow(MainWindow *value)
{
    mainwindow = value;
}

QString Chat::getAccount() const
{
    return account;
}

void Chat::setAccount(const QString &value)
{
    account = value;
}

int Chat::getIsdown() const
{
    return isdown;
}

void Chat::setIsdown(int value)
{
    isdown = value;
}

QString Chat::getOtheraccount() const
{
    return otheraccount;
}

void Chat::setOtheraccount(const QString &value)
{
    otheraccount = value;
}

QString Chat::getLocalIP()
{
    //获取本机IPv4地址
    QString hostName = QHostInfo::localHostName();//本机主机名
    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    QString localIP="";
    QList<QHostAddress> addList = hostInfo.addresses();
    if(!addList.isEmpty())
    {
        for(int i = 0;i<addList.count();i++)
        {
            QHostAddress aHost = addList.at(i);
            if(QAbstractSocket::IPv4Protocol==aHost.protocol())
            {
                localIP = aHost.toString();
                break;
            }
        }
    }
    return localIP;
}

void Chat::onSocketStateChange(QAbstractSocket::SocketState socketState)
{
    switch (socketState) {
    case QAbstractSocket::UnconnectedState:
        LabSocketate->setText("scoket状态：UnconnectedState");
        break;
    case QAbstractSocket::HostLookupState:
        LabSocketate->setText("scoket状态：HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        LabSocketate->setText("scoket状态：ConnectingState");
        break;
    case QAbstractSocket::ConnectedState:
        LabSocketate->setText("scoket状态：ConnectedState");
        break;
    case QAbstractSocket::BoundState:
        LabSocketate->setText("scoket状态：BoundState");
        break;
    case QAbstractSocket::ClosingState:
        LabSocketate->setText("scoket状态：ClosingState");
        break;
    case QAbstractSocket::ListeningState:
        LabSocketate->setText("scoket状态：ListeningState");
        break;
    default:
        break;
    }
}

void Chat::onConnected()
{
//    ui->plainTextEdit->appendPlainText("已连接服务器");
//    ui->plainTextEdit->appendPlainText("**peer address"+tcpClient->peerAddress().toString());
//    ui->plainTextEdit->appendPlainText("**peer port:"+QString::number(tcpClient->peerPort()));
//    ui->pushButton->setEnabled(false);
//    ui->pushButton_2->setEnabled(true);
}

void Chat::onDisconnected()
{
//    ui->plainTextEdit->appendPlainText("已断开服务器的连接");
//    ui->pushButton->setEnabled(true);
//    ui->pushButton_2->setEnabled(true);
}

void Chat::onSocketReadyRead(QString data)
{
    qDebug()<<"接收到信号";
    qDebug()<<"是真是假："<<this->isread;
    QDateTime curDateTime=QDateTime::currentDateTime();
    QString time = curDateTime.toString("hh:mm:ss");
    if(this->isread==true)
    {
        ui->plainTextEdit->appendPlainText("他   "+time+"\n"+data);
        this->isread=false;
    }
}

void Chat::on_pushButton_3_clicked()
{
    QDateTime curDateTime=QDateTime::currentDateTime();
    QString time = curDateTime.toString("hh:mm:ss");
    //数据格式为: 到达方账号，发送方账号，内容
    QString msg = this->getOtheraccount()+this->getAccount()+ui->lineEdit->text();
    //我发送的内容显示在右边
    ui->plainTextEdit->appendPlainText("我   "+time+"\n"+ui->lineEdit->text());
    //ui->scrollAreaWidgetContents-> CreateWidgetR();
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
    QByteArray str = msg.toUtf8();
    //str.append('\n');
    //发送信号
    emit sendData(str);
    //tcpClient->write(str);
}


void Chat::on_pushButton_4_clicked()
{
    if(this->isdown==1)
    {
        this->hide();
    }
    else
    {
        this->close();
    }
    //发送信号
    emit sendCount();
}

void Chat::on_toolButton_3_clicked()
{
    if(this->isdown==1)
    {
        this->hide();
    }
    else
    {
        this->close();
    }
    emit sendCount();
}
