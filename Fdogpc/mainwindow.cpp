#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"query.h"
#include<QMenu>
#include<QDebug>
#include<QPainter>
#include<QBitmap>
#include<QSize>
#include<QLabel>
#include<qdrawutil.h>
#include<QGraphicsDropShadowEffect>
#include<QListWidget>
#include<QHostInfo>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

MainWindow::MainWindow(QString account,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    void showMessage(const QString & title, const QString & message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int millisecondsTimeoutHint = 10000)
//    显示一个气球消息，使用所给出的标题、消息、图标和指定的时间，标题和消息必须是纯文本字符串。
    tcpClient=new QTcpSocket(this);
    LabSocketate = new QLabel("Socket状态：");
    LabSocketate->setMinimumWidth(250);
    QString localIP = getLocalIP();

    //连接到服务器
    QString addr =localIP;
    quint16 port = 60;
    tcpClient->connectToHost(addr,port);

    connect(tcpClient,SIGNAL(connected()),
            this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(disconnected()),
            this,SLOT(onDisconnected()));
    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    connect(tcpClient,SIGNAL(readyRead()),
            this,SLOT(onSocketReadyRead()));


    //ui->widget->setLayout(horLayout);
    //个人信息弹框
    this->aa->setWindowFlags(Qt::FramelessWindowHint | Qt::CustomizeWindowHint | Qt::X11BypassWindowManagerHint|Qt::Tool);
    //主窗口样式
    this->setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);
    setAttribute(Qt::WA_TranslucentBackground);
    //创建右击菜单
    systemtrayicon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/lib/fdogicon.png");
    //创建基础内容
    this->account = account;
    //通过账户，查询数据库基本数据,头像，昵称，个性签名
    //直接从网络下载图片不理想，可以先使用本地头像，再搜索网络头像
    sqconn.conndata();
    sqconn.queryUserInfo(this->account);
    sqconn.AccountIP1(getLocalIP());      //获取ip登录在线
    this->icon = sqconn.getIcon();
    qDebug()<<"pixmap "<<this->icon;
    this->account = sqconn.getAccount();
    this->name = sqconn.getName();
    this->signature = sqconn.getSignature();
    ui->username_label->setText(this->name);
    ui->signature_label->setText(this->signature);
    ui->signature_label->setToolTip(this->signature);
    //图标不可点击
    ui->icon_tool->setEnabled(false);
    this->icon=this->icon.scaled(QSize(this->icon.width(), this->icon.height()), Qt::IgnoreAspectRatio);
    this->icon= PixmapToRound(this->icon, this->icon.width()/2);
    ui->pushButton->setIcon(QIcon(this->icon));
    //添加垂直布局 最外面布局
    QVBoxLayout * layout = new QVBoxLayout();
    //设置边距为0
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    //获取分组信息，以及好友列表
    QStringList grouping = sqconn.getGrouping();
    QStringList mfriend = sqconn.getMfriend();
    QStringList mfriendname = sqconn.getMfriendname();
    qDebug()<<mfriend;
    //显示等级
    ui->toolButton_5->setText("   "+sqconn.getGrade());
   // grouping.length()
    for(int j = 0;j<grouping.length();j++)
    {
        //创建分组信息
        QPushButton * btn = new QPushButton(QIcon(":/lib/jietou.png")," "+grouping.at(j));
        this->listbtn.append(btn);
        this->iswidget.append(true);
        btn->setFixedSize(312,38);
        QSize btnsize(13,13);
        btn->setIconSize(btnsize);
        btn->setStyleSheet("QPushButton{text-align: left;background-color: rgba(232, 255, 149,0);border-style:solid;}"
                           "QPushButton::hover{text-align: left;background-color: rgba(203, 203, 203, 100);border-style:solid;}");
        //加入分组信息
        layout->addWidget(btn);
        QListWidget * listwidget = new QListWidget(this);
        connect(listwidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),
                this,SLOT(on_Double_widget_clicked(QListWidgetItem*)));
        this->listwidget.append(listwidget);
        listwidget->setFrameShape(QListWidget::NoFrame);
        listwidget->setGridSize(QSize(312,50));
        int sum = -1;
        for(int i = 0;i<mfriend.length();i++)
        {
            QString mf = mfriend.at(i);
            char a = mf.at(0).toLatin1();
            if(a-48==j)
            {
                sum++;
                QHBoxLayout *horLayout = new QHBoxLayout();//水平布局
                horLayout->setContentsMargins(0,0,0,0);
                horLayout->setSpacing(0);

                QLabel * l1 = new QLabel();
                l1->setFixedSize(15,32);

                QPushButton * btnicon = new QPushButton();
                btnicon->setFixedSize(32,32);
                btnicon->setIconSize(QSize(32,32));
                btnicon->setIcon(sqconn.getPixmapIcon(mf.mid(1)));
                btnicon->setStyleSheet("background:rgba(0,0,0,0)");
                QLabel * la2 = new QLabel(QString("%1").arg(mf.mid(1)));
                la2->setObjectName("label2");
                la2->hide();
                QLabel * la3 = new QLabel(QString("%1").arg(mfriendname.at(i)));
                la3->setObjectName("label3");

                horLayout->addWidget(l1);
                horLayout->addWidget(btnicon);
                horLayout->addWidget(la2);
                horLayout->addWidget(la3);
                QWidget *widget =new QWidget(this);
                widget->setLayout(horLayout);
                QListWidgetItem * Listitem = new QListWidgetItem(listwidget);
                Listitem->setSizeHint(QSize(312, 50));  //每次改变Item的高度
                listwidget->setItemWidget(Listitem,widget);
                listwidget->setStyleSheet("QListWidget{color:gray;font-size:12px;background:#FAFAFD;}\
                                QScrollBar{width:0;height:0}");
                listwidget->setFixedSize(312,50*(sum+1));
            }
        }
        btn->setText(grouping.at(j)+"     "+QString::number(sum+1));
        layout->addWidget(listwidget);
    }
    layout->addStretch();
    ui->scrollAreaWidgetContents->setLayout(layout);
    //初始化QSignalMapper
    myMapper = new QSignalMapper(this);
    for(int i = 0;i<this->listbtn.length();i++)
    {
        connect(this->listbtn[i],SIGNAL(clicked(bool)),myMapper,SLOT(map()));
        myMapper->setMapping(listbtn[i],i);
    }
    connect(myMapper,SIGNAL(mapped(int)),this,SLOT(on_widget_clicked(int)));
    QString str = QString("Fdog:%1(%2)\n声音:关闭\n消息提示框:关闭\n会话消息:任务栏头像闪动").arg(this->name,this->account);
    systemtrayicon->setIcon(icon);
    systemtrayicon->setToolTip(str);
    systemtrayicon->show();
    systemtrayicon->hide();
    menu = new QMenu(this);
    menu->addAction(QIcon(":/lib/zaixian"),"我在线上");
    menu->addAction(QIcon(":/lib/xiaolian"),"F我吧");
    menu->addAction(QIcon(":/lib/yinshenim"),"隐身");
    menu->addAction(QIcon(":/lib/likaishijian"),"离开");
    menu->addAction(QIcon(":/lib/wurao"),"请勿打扰");
    menu->addAction(QIcon(":/lib/lixianim"),"离线");
    menu->addSeparator();
    menu->addAction("打开主界面");
    menu->addAction("退出");
    systemtrayicon->setContextMenu(menu);
    //头像悬浮弹出
    ui->pushButton->setAttribute(Qt::WA_Hover,true);
    ui->pushButton->installEventFilter(this);
    //去除边框
    ui->scrollArea->setFrameShape(QFrame::NoFrame);
    ui->scrollArea_2->setFrameShape(QFrame::NoFrame);
    ui->listWidget->setFrameShape(QFrame::NoFrame);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)

    QPainter painter(this);
    QPixmap pixmap(":/lib/background.png");
    qDrawBorderPixmap(&painter, this->rect(), QMargins(0, 0, 0, 0), pixmap);
    // 绘制中心区域的背景色（不然会是透明的）
    QRect rect(this->rect().x()+8, this->rect().y()+8, this->rect().width()-16, this->rect().height()-16);
    painter.fillRect(rect, QColor(255, 255, 255));
}

MainWindow::~MainWindow()
{
    qDebug()<<"退出";
    //断开连接
    if(tcpClient->state()==QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
    sqconn.AccountIP2(getLocalIP());      //获取ip登录离线
    //释放内存

    delete ui;
}

QString MainWindow::getLocalIP()
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

void MainWindow::on_min_tool_clicked()
{

     this->hide();
     connect(systemtrayicon,SIGNAL(activated(QSystemTrayIcon::ActivationReason))
             ,this,SLOT(on_activatedSysTratIcon(QSystemTrayIcon::ActivationReason)));
}

void MainWindow::on_activatedSysTratIcon(QSystemTrayIcon::ActivationReason reason)
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

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    last = event->globalPos();
//    if (event->button() == Qt::LeftButton)
//    {
//        m_point = event->globalPos()-frameGeometry().topLeft();
//    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget)
        {
            int dx = event->globalX() - last.x();
            int dy = event->globalY() - last.y();
            last = event->globalPos();
            move(x()+dx, y()+dy);
        }
    //move(event->globalPos() - m_point);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x()+dx, y()+dy);
    isPressedWidget = false; // 鼠标松开时，置为false
}

void MainWindow::on_close_tool_clicked()
{
    systemtrayicon->hide();
    this->close();
}

void MainWindow::showicon()
{
    systemtrayicon->show();
}

void MainWindow::setAccount(QString account)
{

}

QPixmap MainWindow::PixmapToRound(QPixmap &src, int radius)
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

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->pushButton) {
        if(event->type() == QEvent::HoverEnter) {
            qDebug() <<"鼠标来了";
            ui->pushButton->setStyleSheet("border-radius:25px;border-style:solid;border-width:4px;border-color: rgb(255, 255, 255);");
            QPoint globalPos = this->mapToGlobal(QPoint(0, 0));
            this->aa->setFixedSize(300,150);
            this->aa->move(globalPos.x()-302, globalPos.y()+50);
            this->aa->show();
            return true;
        }
        if(event->type() == QEvent::HoverLeave) {
            qDebug() <<"鼠标走了";
            ui->pushButton->setStyleSheet("border-radius:25px;border-style:solid;border-width:2px;border-color: rgba(255, 255, 255,20);");
            this->aa->hide();
            return true;
        }
    }
    return QWidget::eventFilter(obj,event);
}
void MainWindow::on_toolButton_3_clicked()
{
    a = new Query();
    a->show();
}

void MainWindow::on_widget_clicked(int i)
{
    if(this->iswidget[i]==true)
    {
        this->listwidget[i]->setVisible(false);
        this->iswidget[i]=false;
        return;
    }
    this->listwidget[i]->setVisible(true);
    this->iswidget[i]=true;
}

void MainWindow::on_Double_widget_clicked(QListWidgetItem * witem)
{
    QWidget * pwig=NULL;
    for(int i =0;i<this->listwidget.length();i++)
    {
        pwig = this->listwidget[i]->itemWidget(witem);
       if(pwig!=NULL)break;
    }
        Chat * a = new Chat(pwig->findChild<QLabel *>("label2")->text(),
                            pwig->findChild<QLabel *>("label3")->text(),this);
        a->setAccount(this->account);
        listchat.append(a);
        this->count++;
        if(this->count==1)
        {
            a->setIsdown(1);
        }
        else
        {
            a->setIsdown(0);
        }
        connect(a,SIGNAL(sendData(QString)),this,SLOT(MainSendData(QString)));
        connect(a,SIGNAL(sendCount()),this,SLOT(listchatcount()));
        a->show();
}

void MainWindow::onSocketStateChange(QAbstractSocket::SocketState socketState)
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

void MainWindow::onConnected()
{
    //发送自己的帐户
    QByteArray straccount = this->account.toUtf8();
    tcpClient->write(straccount);
    qDebug()<<"写入";
    //发送信号
    //ui->plainTextEdit->appendPlainText("已连接服务器");
    //ui->plainTextEdit->appendPlainText("**peer address"+tcpClient->peerAddress().toString());
    //ui->plainTextEdit->appendPlainText("**peer port:"+QString::number(tcpClient->peerPort()));
    //ui->pushButton->setEnabled(false);
    //ui->pushButton_2->setEnabled(true);
}

void MainWindow::onDisconnected()
{
    //ui->plainTextEdit->appendPlainText("已断开服务器的连接");
    //ui->pushButton->setEnabled(true);
    //ui->pushButton_2->setEnabled(true);
}

void MainWindow::onSocketReadyRead()
{
    qDebug()<<"我收到了消息";
    while (tcpClient->canReadLine()) {
        //ui->plainTextEdit->appendPlainText("[in]"+tcpClient->readLine());
        //传给聊天界面,这里要确定传给哪个界面
        QString data = tcpClient->readLine();
        qDebug()<<"数据："<<data;
        for(int i = 0;i<listchat.length();i++)
        {
            qDebug()<<"getname:"<<listchat[i]->getName()<<"   data.mid"<<data.mid(0,8);
            if(listchat[i]->getName()==data.mid(0,8))
            {
                qDebug()<<"找到正确窗口:"<<data.mid(0,8);
                listchat[i]->setIsread(true);
                emit sendChatData(data);
                qDebug()<<"成功发送信号";
            }
        }
    }
}

void MainWindow::listchatcount()
{
    this->count--;
}

void MainWindow::MainSendData(QString str)
{
    QByteArray strdata = str.toUtf8();
    strdata.append('\n');
    tcpClient->write(strdata);
}
