#include "chat.h"
#include "ui_chat.h"
#include<QTcpServer>
#include<QTcpSocket>
#include<QHostInfo>
#include<QDateTime>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
Chat::Chat(QPixmap mypixmap,QPixmap pixmap,QString otheraccount,QString name,MainWindow * main,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    setWindowFlags (Qt::FramelessWindowHint);//隐藏标题栏
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlag(Qt::CoverWindow);
    setAttribute(Qt::WA_TranslucentBackground);
    this->otheraccount=otheraccount;
    this->name=name;
    this->setWindowTitle(name);
    tcpClient=new QTcpSocket(this);
    LabSocketate = new QLabel("Socket状态：");
    LabSocketate->setMinimumWidth(250);
    this->setWindowIcon(QIcon(pixmap));
    this->pixmap=pixmap;
    this->mypixmap=mypixmap;
    //ui->statusBar->addWidget(LabSocketate);
    //QString localIP = getLocalIP();
    ui->label->setText(this->name);
    //接收主窗口的消息信号
    mainwindow = main;
    connect(mainwindow,SIGNAL(sendChatData(QString)),this,SLOT(onSocketReadyRead(QString)));
}

void Chat::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
        QPainter painter(this);
        QPixmap pixmap(":/lib/background.png");//做好的图
        qDrawBorderPixmap(&painter, this->rect(), QMargins(0, 0, 0, 0), pixmap);
        QRect rect(this->rect().x()+8, this->rect().y()+8, this->rect().width()-16, this->rect().height()-16);
        painter.fillRect(rect, QColor(255, 255, 255,0));
}

void Chat::mousePressEvent(QMouseEvent *event)
{
    isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    last = event->globalPos();
}

void Chat::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget)
        {
            int dx = event->globalX() - last.x();
            int dy = event->globalY() - last.y();
            last = event->globalPos();
            move(x()+dx, y()+dy);
        }
}

void Chat::mouseReleaseEvent(QMouseEvent *event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x()+dx, y()+dy);
    isPressedWidget = false; // 鼠标松开时，置为false
}

Chat::~Chat()
{
    delete ui;

}

void Chat::closeEvent(QCloseEvent *e)
{
    //qDebug()<<"关不掉";
    //this->hide();
    e->ignore();
    e->accept();
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

QWidget *Chat::CreateWidgetL_R(int i,QString data)
{
    QFont font1;
    font1.setFamily("Microsoft YaHei");
    font1.setPointSize(15);
    font1.setStyleStrategy(QFont::PreferAntialias);
    QWidget * widget = new QWidget();
    widget->setStyleSheet("background:rgba(0,0,0,0);");
    widget->setFixedSize(660,50);
    QHBoxLayout *horLayout = new QHBoxLayout();//水平布局
    horLayout->setContentsMargins(0,0,0,0);
    horLayout->setSpacing(0);
    QPushButton * btnicon = new QPushButton();
    btnicon->setFixedSize(55,40);
    btnicon->setIconSize(QSize(40,40));
    btnicon->setStyleSheet("background:rgba(0,0,0,0);");
    QLabel * label = new QLabel(data);
    label->setFont(font1);
    label->setStyleSheet("background-color: rgb(140, 105, 255);border-style:solid;border-width:2px;border-color: rgb(125, 242, 255);border-radius:10px;");// background-color: rgb(255, 123, 249);
    label->setTextInteractionFlags(Qt::TextSelectableByMouse);
    label->setMaximumHeight(40);
    if(i==1)
    {
        label->setAlignment(Qt::AlignVCenter|Qt::AlignLeft);
        horLayout->addWidget(btnicon);
        horLayout->addWidget(label);
        horLayout->addStretch();
        btnicon->setIcon(this->pixmap);
    }
    else
    {
        label->setAlignment(Qt::AlignVCenter|Qt::AlignRight);
        horLayout->addStretch();
        horLayout->addWidget(label);
        horLayout->addWidget(btnicon);
        btnicon->setIcon(this->mypixmap);
    }
    widget->setLayout(horLayout);
    return widget;
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
    QDateTime curDateTime=QDateTime::currentDateTime();
    QString time = curDateTime.toString("hh:mm:ss");
    if(this->isread==true)
    {
        data = data.mid(8);
        data = data.left(data.size() - 1);
        qDebug()<<"数据："<<data;
        //创建一个widget
        QWidget * widget = CreateWidgetL_R(1,data);
        ui->verticalLayout_5->addWidget(widget);
        widget->show();
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
    QWidget * widget = CreateWidgetL_R(2,ui->lineEdit->text());
    ui->verticalLayout_5->addWidget(widget);
    widget->show();
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
    QByteArray str = msg.toUtf8();
    //发送信号
    emit sendData(str);
}


void Chat::on_pushButton_4_clicked()
{
    on_toolButton_3_clicked();
}

void Chat::on_toolButton_3_clicked()
{
    this->close();
    emit sendCount(this->otheraccount);
}

void Chat::on_toolButton_clicked()
{
    this->hide();
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
