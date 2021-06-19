#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

MainWindow::MainWindow(QString account,QTcpSocket *tcpClient,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //个人信息弹框
    this->myinfo->setWindowFlags(Qt::FramelessWindowHint | Qt::CustomizeWindowHint | Qt::X11BypassWindowManagerHint|Qt::Tool);
    //主窗口样式
    setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    //setAttribute(Qt::WA_DeleteOnClose);
    setAttribute(Qt::WA_TranslucentBackground);
    //设置全局
    Globalobserver::setMainwindowp(this);
    //获取TCP
    this->tcpClient = tcpClient;
    LabSocketate = new QLabel(this);
    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onSocketErrorChange(QAbstractSocket::SocketError)));
    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));
    //数据库获取数据
    sqconn.connData();
    sqconn.queryUserInfo(account);
    sqconn.setSate(0);
    sqconn.AccountIP(getLocalIP());//获取ip登录在线
    //获取基础内容
    this->account = account;
    this->icon = sqconn.getIcon();
    this->account = sqconn.getAccount();
    this->name = sqconn.getName();
    this->signature = sqconn.getSignature();
    ui->username_label->setText(this->name);
    ui->signature_label->setText(this->signature);
    ui->signature_label->setToolTip(this->signature);
    this->icon=this->icon.scaled(QSize(this->icon.width(), this->icon.height()), Qt::IgnoreAspectRatio);
    this->icon= Globalobserver::PixmapToRound(this->icon, this->icon.width()/2);
    ui->pushButton->setIcon(QIcon(this->icon));
    //获取托盘消息窗口
    this->tarywidget  = new Traywidget(this->name);
    this->tarywidget->setName(this->name);
    connect(this->tarywidget,SIGNAL(senddata()),this,SLOT(showAllChat()));//显示全部
    connect(this->tarywidget,SIGNAL(senddata2()),this,SLOT(hideAllChat()));//忽略全部
    connect(this->tarywidget,SIGNAL(senddata3(QString)),this,SLOT(showAChat(QString)));//忽略全部
    //定时检测身鼠标是否位于托盘之上
    this->timemouse.start(200);
    this->timemouse.setSingleShot(false);
    connect(&timerT,SIGNAL(timeout()),this,SLOT(sltTimerT()));//开始
    connect(&timerNoT,SIGNAL(timeout()),this,SLOT(sltTimerNoT()));//停止
    connect(&timemouse,SIGNAL(timeout()),this,SLOT(showdata()));//显示消息
    //设置托盘图标
    systemtrayicon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/lib/fdogicon.png");
    systemtrayicon->setIcon(icon);
    QString str = QString("Fdog:%1(%2)\n声音:关闭\n消息提示框:关闭\n会话消息:任务栏头像闪动").arg(this->name,this->account);
    systemtrayicon->setToolTip(str);
    systemtrayicon->show();
    //设置菜单
    menu = new QMenu(this);
    m_pShowAction = new QAction("显示主界面");
    m_pCloseAction = new QAction("退出");
    m_pOnLineAction = new QAction(QIcon(":/lib/zaixian"),"在线");
    m_pCallAction = new QAction(QIcon(":/lib/xiaolian"),"F我吧");
    m_pCloakingAction = new QAction(QIcon(":/lib/yinshenim"),"隐身");
    m_pLeaveAction = new QAction(QIcon(":/lib/likaishijian"),"离开");
    m_pBusyAction = new QAction(QIcon(":/lib/manglu"),"忙碌");
    m_pDisturbAction = new QAction(QIcon(":/lib/wurao"),"请勿打扰");
    m_pOffLineAtion = new QAction(QIcon(":/lib/lixianim"),"离线");
    menu->addAction(m_pOnLineAction);
    menu->addAction(m_pCallAction);
    menu->addAction(m_pCloakingAction);
    menu->addAction(m_pLeaveAction);
    menu->addAction(m_pBusyAction);
    menu->addAction(m_pDisturbAction);
    menu->addAction(m_pOffLineAtion);
    menu->addSeparator();
    menu->addAction(m_pShowAction);
    menu->addAction(m_pCloseAction);
    menuAction = new QSignalMapper();
    QAction * actionarry[9]={m_pShowAction,m_pCloseAction,m_pOnLineAction,m_pCallAction,
                             m_pCloakingAction,m_pLeaveAction,m_pBusyAction,m_pDisturbAction,m_pOffLineAtion};
    for(int i =0;i<9;i++)
    {
        connect(actionarry[i],SIGNAL(triggered(bool)),menuAction,SLOT(map()));
        menuAction->setMapping(actionarry[i],i);
    }
    connect(menuAction,SIGNAL(mapped(int)),this,SLOT(actionexe(int)));
    mainmenu = menu;
    ui->toolButton_2->setMenu(menu);
    systemtrayicon->setContextMenu(menu);
    //获取分组列表以及好友
    //添加垂直布局 最外面布局
    QVBoxLayout * layout = new QVBoxLayout();
    //设置边距为0
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    //获取分组信息，以及好友列表
    QStringList grouping = sqconn.getGrouping();
    QStringList mfriend = sqconn.getMfriend();
    QStringList mfriendname = sqconn.getMfriendname();
    //显示等级
    ui->toolButton_5->setText("   "+sqconn.getGrade());
    for(int j = 0;j<grouping.length();j++)
    {
        //创建分组信息
        QPushButton * btn = new QPushButton(QIcon(":/lib/jietou.png")," "+grouping.at(j));//箭头+分组名
        btn->setFont(Globalobserver::font1);
        this->listbtn.append(btn);
        this->iswidget.append(true);
        btn->setFixedSize(312,38);
        QSize btnsize(36,36);
        btn->setIconSize(btnsize);
        btn->setStyleSheet("QPushButton{text-align: left;background-color: rgba(203, 203, 203,200);border-style:solid;}"
                           "QPushButton:hover{text-align: left;background-color: rgb(193, 193, 193);border-style:solid;}");
        //加入分组信息
        layout->addWidget(btn);
        QListWidget * listwidget = new QListWidget(this);
        connect(listwidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(onDoubleWidgetClicked(QListWidgetItem*)));
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
                QLabel * la3 = new QLabel(QString("  %1").arg(mfriendname.at(i)));
                la3->setObjectName("label3");
                la3->setFont(Globalobserver::font2);
                horLayout->addWidget(l1);
                horLayout->addWidget(btnicon);
                horLayout->addWidget(la2);
                horLayout->addWidget(la3);
                QWidget *widget =new QWidget(this);
                widget->setLayout(horLayout);
                widget->setStyleSheet("background:rgba(232, 255, 149,0);");
                QListWidgetItem * Listitem = new QListWidgetItem(listwidget);
                Listitem->setSizeHint(QSize(312, 50));  //每次改变Item的高度
                listwidget->setItemWidget(Listitem,widget);
                listwidget->setFixedSize(312,50*(sum+1));
                listwidget->setStyleSheet("QListWidget::Item{background-color: rgba(203, 203, 203,200);}"
                                          "QListWidget::Item:hover{background-color: rgb(193, 193, 193);}"
                                          "QListWidget::Item:selected{background-color: rgb(193, 193, 193);}"
                                          "QListWidget{outline:0px;}");
            }
        }
        btn->setText(grouping.at(j)+"     "+QString::number(sum+1)+"/"+QString::number(sum+1));
        layout->addWidget(listwidget);
        listwidget->setObjectName(grouping.at(j));
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
    connect(myMapper,SIGNAL(mapped(int)),this,SLOT(onWidgetClicked(int)));
    connect(systemtrayicon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTratIcon(QSystemTrayIcon::ActivationReason)));
    //图标不可点击
    ui->icon_tool->setEnabled(false);
    //头像悬浮弹出
    ui->pushButton->setAttribute(Qt::WA_Hover,true);
    ui->pushButton->installEventFilter(this);
    //去除边框
    ui->scrollArea->setFrameShape(QFrame::NoFrame);
    ui->scrollArea_2->setFrameShape(QFrame::NoFrame);
    ui->scrollArea_3->setFrameShape(QFrame::NoFrame);
}

MainWindow::~MainWindow()
{
    qDebug()<<"主窗口完成析构";
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)

    QPainter painter(this);
    QPixmap pixmap(":/lib/background.png");
    qDrawBorderPixmap(&painter, this->rect(), QMargins(0, 0, 0, 0), pixmap);
    // 绘制中心区域的背景色（不然会是透明的）
    QRect rect(this->rect().x()+8, this->rect().y()+8, this->rect().width()-16, this->rect().height()-16);
    painter.fillRect(rect, QColor(255, 255, 255,0));
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
}

void MainWindow::on_activatedSysTratIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:
        //单击托盘图标
        //处理全局信息
        this->show();
        if (timerT.isActive()) timerT.stop();
        if (timerNoT.isActive()) timerNoT.stop();
        systemtrayicon->setIcon(QIcon(":/lib/fdogicon.png")); //还原托盘原本icon
        //delete systemtrayicon;
        break;
    case QSystemTrayIcon::DoubleClick:
        //双击托盘图标
        //处理全局信息
        for(int i=0;i<stringlistdata.length();i++)
        {
            QString data = stringlistdata.at(i);
            if(data.mid(data.length()-4,3)!="yan")
            {
                //先找聊天窗口，找不到再创建
                int a = 0;
                for(int i =0;i<listchat.length();i++)
                {
                    if(listchat.at(i)->getOtheraccount()==data.mid(0,8))
                    {
                        listchat.at(i)->show();
                        listchat.at(i)->setIsread(true);
                        emit sendChatData(data);
                        a=1;
                        break;
                    }
                }
                if(a==0)
                {
                    //qDebug()<<"没找到已存在窗口";
                    //普通消息 获取相关数据，生成聊天窗口  对方帐号，对方名字，主窗口指针
                    Chat * a = new Chat(this->icon,sqconn.getPixmapIcon(data.mid(0,8)),data.mid(0,8),sqconn.getOtherAccountName(data.mid(0,8)),this);
                    a->setAccount(this->account); //本身账号
                    a->setAttribute(Qt::WA_DeleteOnClose);
                    a->setObjectName(data.mid(0,8));
                    listchat.append(a);
                    connect(a,SIGNAL(sendData(QString)),this,SLOT(MainSendData(QString)));
                    connect(a,SIGNAL(sendCount(QString)),this,SLOT(listchatcount(QString)));
                    a->show();
                    a->setIsread(true);
                    emit sendChatData(data);
                }
            }
            else
            {
                //验证消息 获取相关数据，生成验证窗口
                //时间 头像  名字 男 16岁
                //附加信息
                //QString time,QPixmap icon,QString name,QString sex,QString age,QString add
                qDebug()<<"正在创建验证窗口,发送方为："<<data.mid(0,8);
                verify = new Verify(this->account,
                                    data.mid(0,8),
                                    "今日",
                                    sqconn.getPixmapIcon(data.mid(0,8)),
                                    sqconn.getOtherAccountName(data.mid(0,8)),
                                    sqconn.getOtherAccountSex(data.mid(0,8)),
                                    sqconn.getOtherAccountAge(data.mid(0,8)),
                                    "CSDN上面看到您的");
                verify->show();
                //这里是构造函数初始化窗口，应该使用普通函数进行动态更新
            }
            //删除这条消息
            //判断窗口是否显示isHidden
        }
        //处理完 数据池信息为0
        this->show();
        if (timerT.isActive()) timerT.stop();
        if (timerNoT.isActive()) timerNoT.stop();
        this->tarywidget->deleteItem(); //列表清理
        this->stringlistdata.clear();   //清理数据词内容
        systemtrayicon->setIcon(QIcon(":/lib/fdogicon.png")); //还原托盘原本icon
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
    qDebug()<<"执行关闭1";
    systemtrayicon->hide();
    qDebug()<<"执行关闭2";
    this->close();
    qDebug()<<"执行关闭3";
    sqconn.setSate(-1);
    sqconn.AccountIP(getLocalIP());      //获取ip登录离线
    qDebug()<<"执行关闭4";
    //断开连接
    if(tcpClient->state()==QAbstractSocket::ConnectedState)
    {
        tcpClient->disconnectFromHost();
    }
    qDebug()<<"执行关闭5";
    //释放内存 把窗口释放
    qDeleteAll(this->listchat);
    qDebug()<<"释放";
    emit sendquitData();
}

void MainWindow::showicon()
{
    systemtrayicon->show();
}

void MainWindow::datawidget(QPixmap pixmap, QString str,QString account)
{
//    QFont font;
//    font.setFamily("Microsoft YaHei");
//    font.setPointSize(10);
//    font.setStyleStrategy(QFont::PreferAntialias);
//    QHBoxLayout *horLayout = new QHBoxLayout();//水平布局
//    horLayout->setContentsMargins(0,0,0,0);
//    horLayout->setSpacing(0);
//    QPushButton * btn = new QPushButton();
//    btn->setIcon(pixmap);
//    QSize btnsize(32,32);
//    btn->setIconSize(btnsize);
//    btn->setFixedSize(32,32);
//    btn->setFlat(true);
//    QLabel * la = new QLabel("  "+str);
//    la->setObjectName("label1");
//    la->setFont(font);
//    horLayout->addWidget(btn);
//    horLayout->addWidget(la);
//    QWidget * widget = new QWidget(this);
//    widget->setLayout(horLayout);
//    widget->setObjectName(account);
//    QListWidgetItem * Listitem = new QListWidgetItem(ui->listWidget);
//    Listitem->setSizeHint(QSize(321, 50));  //每次改变Item的高度
//    ui->listWidget->setItemWidget(Listitem,widget);
//    ui->listWidget->setStyleSheet("QListWidget{color:gray;font-size:12px;background:#FAFAFD;}\
//                    QScrollBar{width:0;height:0}");
    //ui->listWidget->setFixedSize(321,50*(1));
    QHBoxLayout *horLayout = new QHBoxLayout();//水平布局
    horLayout->setContentsMargins(0,0,0,0);
    horLayout->setSpacing(0);
    QLabel * l1 = new QLabel();
    l1->setFixedSize(15,32);
    QPushButton * btnicon = new QPushButton();
    btnicon->setFixedSize(32,32);
    btnicon->setIconSize(QSize(32,32));
    btnicon->setIcon(pixmap);
    btnicon->setStyleSheet("background:rgba(0,0,0,0)");
    QLabel * la2 = new QLabel(QString("%1").arg(account));
    la2->setObjectName("label2");
    la2->hide();
    QLabel * la3 = new QLabel(QString("  %1").arg(str));
    la3->setObjectName("label3");
    la3->setFont(Globalobserver::font2);
    horLayout->addWidget(l1);
    horLayout->addWidget(btnicon);
    horLayout->addWidget(la2);
    horLayout->addWidget(la3);
    QWidget *widget =new QWidget(this);
    widget->setLayout(horLayout);
    widget->setStyleSheet("background:rgba(232, 255, 149,0);");
    widget->setObjectName(account);
    QListWidgetItem * Listitem = new QListWidgetItem(ui->listWidget);
    Listitem->setSizeHint(QSize(312, 50));  //每次改变Item的高度
    ui->listWidget->setItemWidget(Listitem,widget);
    //ui->listwidget->setFixedSize(312,50*(sum+1));
    ui->listWidget->setStyleSheet("QListWidget::Item{background-color: rgba(203, 203, 203,200);}"
                              "QListWidget::Item:hover{background-color: rgb(193, 193, 193);}"
                              "QListWidget::Item:selected{background-color: rgb(193, 193, 193);}"
                              "QListWidget{outline:0px;}");
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->pushButton) {
        if(event->type() == QEvent::HoverEnter) {
            qDebug() <<"鼠标来了";
            ui->pushButton->setStyleSheet("border-radius:25px;border-style:solid;border-width:4px;border-color: rgba(255, 255, 255,40);");
            QPoint globalPos = this->mapToGlobal(QPoint(0, 0));
            this->myinfo->setFixedSize(300,150);
            this->myinfo->move(globalPos.x()-302, globalPos.y()+50);
            this->myinfo->show();
            return true;
        }
        if(event->type() == QEvent::HoverLeave) {
            qDebug() <<"鼠标走了";
            ui->pushButton->setStyleSheet("border-radius:25px;border-style:solid;border-width:2px;border-color: rgba(255, 255, 255,20);");
            this->myinfo->hide();
            return true;
        }
    }
    return QWidget::eventFilter(obj,event);
}

void MainWindow::on_toolButton_3_clicked()
{
    a = new Query(this->account);
    a->show();
}

void MainWindow::onWidgetClicked(int i)
{
    if(this->iswidget[i]==true)//闭合
    {
        this->listwidget[i]->setVisible(false);
        this->iswidget[i]=false;
        this->listbtn[i]->setIcon(QIcon(":/lib/jietou2.png"));
        return;
    }
    //展开
    this->listwidget[i]->setVisible(true);
    this->iswidget[i]=true;
    this->listbtn[i]->setIcon(QIcon(":/lib/jietou.png"));

}

void MainWindow::onDoubleWidgetClicked(QListWidgetItem * witem)
{
    QWidget * pwig=NULL;
    for(int i =0;i<this->listwidget.length();i++)
    {
        pwig = this->listwidget[i]->itemWidget(witem);
       if(pwig!=NULL)break;
    }
    //判断当前窗口在不在
    bool isshow = false;
    for(int i=0;i<listchat.length();i++)
    {
        if(listchat[i]->getOtheraccount()==pwig->findChild<QLabel *>("label2")->text())
        {
            isshow=true;
            listchat[i]->show();
        }
    }
    if(!isshow)
    {
        Chat * chat = new Chat(this->icon,sqconn.getPixmapIcon(pwig->findChild<QLabel *>("label2")->text()),
                               pwig->findChild<QLabel *>("label2")->text(),
                               pwig->findChild<QLabel *>("label3")->text(),this);
        chat->setAccount(this->account);
        chat->setAttribute(Qt::WA_DeleteOnClose);
        listchat.append(chat);

        connect(chat,SIGNAL(sendData(QString)),this,SLOT(MainSendData(QString)));
        connect(chat,SIGNAL(sendCount(QString)),this,SLOT(listchatcount(QString)));
        chat->show();
    }
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

void MainWindow::onSocketErrorChange(QAbstractSocket::SocketError)
{

}

void MainWindow::onConnected()
{
    //发送自己的帐户
    QByteArray straccount = this->account.toUtf8();
    tcpClient->write(straccount);
    //qDebug()<<"写入";
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

void MainWindow::onSocketReadyRead() //接收消息
{
    iconbool = false; //新信息需要重新获取头像
    while (tcpClient->canReadLine()) {
        QString data = tcpClient->readLine();
        //判断是验证消息还是普通信息,还是更新消息
        qDebug()<<"data.mid(8,4)的内容是"<<data.mid(8,4);
        qDebug()<<"data的内容是"<<data;
        //数据传入数据池
        stringlistdata.append(data);
        bool isstr =false;
        if(data.mid(data.length()-4,3)=="yan")
        {
            qDebug()<<"接收到验证消息";
            //datawidget(QPixmap(":/lib/verify1.png"),"验证消息");
            for(int i = 0;i<this->stringlistdata.length();i++)
            {
                QString str = stringlistdata[i];
                if(str.mid(str.length()-4,3)=="yan")
                {
                    isstr =true;
                    //后续设置显示条数
                    break;
                }
            }
            if(isstr==false)
            {
                datawidget(QPixmap(":/lib/verify1.png"),"验证消息","10000");
                this->tarywidget->setTrayWidgetItem(QPixmap(":/lib/verify1.png"),"验证消息","10000");
            }
            this->timerT.start(400);
            Globalinfo.append(2);
            //查询对方时间 头像 网名 信息 职业 附加信息
        }
        else if(data.mid(8,4)=="hytg")
        {
            qDebug()<<"进入生成列表";
            QFont font2;
            font2.setFamily("Microsoft YaHei");
            font2.setPointSize(9);
            font2.setStyleStrategy(QFont::PreferAntialias);
            //获取申请时的分组
            QString groupingstr = sqconn.getverifygrouping(this->account,data.mid(0,8));
            qDebug()<<"找到对应分组"<<groupingstr;
            for(int i=0;i<this->listwidget.length();i++)
            {
                if(this->listwidget[i]->objectName()==groupingstr)
                {
                    qDebug()<<"找到对应分组"<<groupingstr;
                    //分组添加内容
                    QHBoxLayout *horLayout = new QHBoxLayout();//水平布局
                    horLayout->setContentsMargins(0,0,0,0);
                    horLayout->setSpacing(0);
                    QLabel * l1 = new QLabel();
                    l1->setFixedSize(15,32);
                    QPushButton * btnicon = new QPushButton();
                    btnicon->setFixedSize(32,32);
                    btnicon->setIconSize(QSize(32,32));
                    btnicon->setIcon(sqconn.getPixmapIcon(data.mid(0,8)));
                    btnicon->setStyleSheet("background:rgba(0,0,0,0)");
                    QLabel * la2 = new QLabel(data.mid(0,8));
                    la2->setObjectName("label2");
                    la2->hide();
                    QLabel * la3 = new QLabel("  "+sqconn.getOtherAccountName(data.mid(0,8)));
                    la3->setObjectName("label3");
                    la3->setFont(font2);
                    horLayout->addWidget(l1);
                    horLayout->addWidget(btnicon);
                    horLayout->addWidget(la2);
                    horLayout->addWidget(la3);
                    QWidget *widget =new QWidget(this);
                    widget->setLayout(horLayout);
                    widget->setStyleSheet("background:rgba(232, 255, 149,0);");
                    QListWidgetItem * Listitem = new QListWidgetItem(this->listwidget[i]);
                    Listitem->setSizeHint(QSize(312, 50));  //每次改变Item的高度
                    this->listwidget[i]->setItemWidget(Listitem,widget);
                    this->listwidget[i]->setFixedSize(312,this->listwidget[i]->geometry().height()+50);
                    this->listwidget[i]->setStyleSheet("QListWidget::Item{background-color: rgb(203, 203, 203);}"
                                              "QListWidget::Item:hover{background-color: rgb(193, 193, 193);}"
                                              "QListWidget::Item:selected{background-color: rgb(193, 193, 193);}"
                                              "QListWidget{outline:0px;}");
                }
            }
        }
        else{
            qDebug()<<"接收到普通消息";
            for(int i = 0;i<this->stringlistdata.length();i++)
            {
                QString str = stringlistdata[i];
                if(str.mid(0,8)==data.mid(0,8))
                {
                    isstr =true;
                    //后续设置显示条数
                    break;
                }
            }
            bool dns = false;
            if(isstr==false)
            {
                //判断当前列表是否已经存在该好友消息
                for(int i =0;i<ui->listWidget->count();i++)
                {
                    QWidget * widget = ui->listWidget->itemWidget(ui->listWidget->item(i));
                    if(widget->objectName()==data.mid(0,8))
                    {
                        dns = true;
                        break;
                    }
                }
                if(dns==false)
                {
                datawidget(QPixmap(sqconn.getPixmapIcon(data.mid(0,8))),sqconn.getOtherAccountName(data.mid(0,8)),data.mid(0,8));
                }
            }
           Globalinfo.append(1);
           bool ishide=false;
           for(int i = 0;i<listchat.length();i++)
           {
               if(listchat[i]->getOtheraccount()==data.mid(0,8)&&!listchat[i]->isHidden())
               {
                   QApplication::alert(listchat[i],0);
                   //qDebug()<<"找到正确窗口:"<<data.mid(0,8);
                   listchat[i]->setIsread(true);
                   emit sendChatData(data);
                   ishide = true;
                   //qDebug()<<"成功发送信号";
                   break;
               }
           }
           if(ishide!=true)
           {
               this->timerT.start(400);//判断当前窗口是否显示在桌面，显示则不在托盘显示，也在消息框显示
               this->tarywidget->setTrayWidgetItem(QPixmap(sqconn.getPixmapIcon(data.mid(0,8))),sqconn.getOtherAccountName(data.mid(0,8)),data.mid(0,8));
           }
        }
    }
}

void MainWindow::listchatcount(QString otheraccount)
{
    for(int i =0;i<listchat.length();i++)
    {
        if(listchat[i]->getOtheraccount()==otheraccount)
        {
            listchat[i]->close();
            listchat.removeOne(listchat[i]);
        }
    }
}

void MainWindow::MainSendData(QString str)//发送聊天信息
{
    qDebug()<<"发送消息";
    QByteArray strdata = str.toUtf8();
    strdata.append('\n');
    tcpClient->write(strdata);
    //消息列表
    bool dns = false;
    //判断当前列表是否已经存在该好友消息
    for(int i =0;i<ui->listWidget->count();i++)
    {
        QWidget * widget = ui->listWidget->itemWidget(ui->listWidget->item(i));
        if(widget->objectName()==strdata.mid(0,8))
        {
            dns = true;
            break;
        }
    }
    if(dns==false)
    {
        datawidget(QPixmap(sqconn.getPixmapIcon(strdata.mid(0,8))),sqconn.getOtherAccountName(strdata.mid(0,8)),strdata.mid(0,8));
    }
}
void MainWindow::MainSendAddData(QString str)//发送验证信息
{
    //qDebug()<<"我是主窗口,我接收到了来做您的验证消息："<<str;
    QByteArray strdata = str.toUtf8();
    strdata.append('\n');
    tcpClient->write(strdata);

}

void MainWindow::actionexe(int value)
{
    //-1离线 0在线 1F我吧 2隐身 3离开 4忙碌 5勿扰
    switch(value)
    {
    case 0:
        this->show();
        break;
    case 1:
        this->close();
        break;
    case 2:
        ui->toolButton_2->setIcon(QIcon(":/lib/zaixian"));
        sqconn.setSate(0);
        break;
    case 3:
        ui->toolButton_2->setIcon(QIcon(":/lib/xiaolian"));
        sqconn.setSate(1);
        break;
    case 4:
        ui->toolButton_2->setIcon(QIcon(":/lib/yinshenim"));
        sqconn.setSate(2);
        break;
    case 5:
        ui->toolButton_2->setIcon(QIcon(":/lib/likaishijian"));
        sqconn.setSate(3);
        break;
    case 6:
        ui->toolButton_2->setIcon(QIcon(":/lib/wanglu"));
        sqconn.setSate(4);
        break;
    case 7:
        ui->toolButton_2->setIcon(QIcon(":/lib/wurao"));
        sqconn.setSate(5);
        break;
    case 8:
        ui->toolButton_2->setIcon(QIcon(":/lib/lixianim"));
        sqconn.setSate(-1);
        break;
    }
    sqconn.AccountIP(this->getLocalIP());
}

void MainWindow::updatamaingrouping(QString otheraccount, QString account,QString name ,QString grouping)
{
    qDebug()<<"收到分组更新消息";
    sqconn.updatagrouping(otheraccount,account);//双方数据库更新完毕
    //开始更新双方分组 先更新自身，找到对应分组，增加对应名字，以及相关数据
    QFont font2;
    font2.setFamily("Microsoft YaHei");
    font2.setPointSize(9);
    font2.setStyleStrategy(QFont::PreferAntialias);
    for(int i=0;i<this->listwidget.length();i++)
    {
        if(this->listwidget[i]->objectName()==grouping)
        {
            //分组添加内容
            QHBoxLayout *horLayout = new QHBoxLayout();//水平布局
            horLayout->setContentsMargins(0,0,0,0);
            horLayout->setSpacing(0);
            QLabel * l1 = new QLabel();
            l1->setFixedSize(15,32);
            QPushButton * btnicon = new QPushButton();
            btnicon->setFixedSize(32,32);
            btnicon->setIconSize(QSize(32,32));
            btnicon->setIcon(sqconn.getPixmapIcon(otheraccount));
            btnicon->setStyleSheet("background:rgba(0,0,0,0)");
            QLabel * la2 = new QLabel(otheraccount);
            la2->setObjectName("label2");
            la2->hide();
            QLabel * la3 = new QLabel("  "+name);
            la3->setObjectName("label3");
            la3->setFont(font2);
            horLayout->addWidget(l1);
            horLayout->addWidget(btnicon);
            horLayout->addWidget(la2);
            horLayout->addWidget(la3);
            QWidget *widget =new QWidget(this);
            widget->setLayout(horLayout);
            widget->setStyleSheet("background:rgba(232, 255, 149,0);");
            QListWidgetItem * Listitem = new QListWidgetItem(this->listwidget[i]);
            Listitem->setSizeHint(QSize(312, 50));  //每次改变Item的高度
            this->listwidget[i]->setItemWidget(Listitem,widget);
            this->listwidget[i]->setFixedSize(312,this->listwidget[i]->geometry().height()+50);
            this->listwidget[i]->setStyleSheet("QListWidget::Item{background-color: rgb(203, 203, 203);}"
                                      "QListWidget::Item:hover{background-color: rgb(193, 193, 193);}"
                                      "QListWidget::Item:selected{background-color: rgb(193, 193, 193);}"
                                      "QListWidget{outline:0px;}");
        }
    }
    //从setverify找到
    QString data = otheraccount+account+"hytg";
    QByteArray strdata = data.toUtf8();
    strdata.append('\n');
    tcpClient->write(strdata);
}

void MainWindow::updatamainverify(QString otheraccount, QString account)
{
    qDebug()<<"收到同意拒绝消息";
    //更新界面
    //更新主界面好友列表
    //更新验证消息窗口
}

void MainWindow::sltTimerT()
{
    //判断最后一条消息发送者，若是普通消息，则显示用户头像，若是验证消息，则显示验证消息图标
    QString str = stringlistdata.at(stringlistdata.length()-1);
    if(str.mid(str.length()-4,3)=="yan")
    {
        systemtrayicon->setIcon(QIcon(":/lib/verify1.png"));
    }
    else
    {
        //qDebug()<<"数："<<sqconn.getPixmapIcon(str.mid(0,8));

        systemtrayicon->setIcon(QIcon((iconbool==false?iconbool=true,icondata = sqconn.getPixmapIcon(str.mid(0,8)):icondata)));
    }
    timerNoT.start(400);
    if(timerT.isActive()) timerT.stop();
}

void MainWindow::sltTimerNoT()
{
    systemtrayicon->setIcon(QIcon(":/lib/verify2.png"));//空白
    timerT.start(400);
    if(timerNoT.isActive()) timerNoT.stop();
}

void MainWindow::showdata()
{
    //先判断鼠标是否在托盘之上
    //qDebug() << "iconIsActivedx:"<<this->systemtrayicon->geometry().x();//x轴
    //qDebug() << "iconIsActivedy:"<<this->systemtrayicon->geometry().y();//y轴
    //qDebug() << "iconIsActivedwidth:"<<this->systemtrayicon->geometry().width();//宽度
    //qDebug() << "iconIsActivedheight:"<<this->systemtrayicon->geometry().height();//高度
    //qDebug() << "鼠标位置x:"<<QCursor::pos().x();
    //qDebug() << "鼠标位置y:"<<QCursor::pos().y();
    //qDebug() << "xMin<=x&&x<=xMax:"<<(xMin<=x&&x<=xMax);
    //qDebug() << "yMin<=y&&y<=yMax:"<<(yMin<=y&&y<=yMax);
    int xMin = systemtrayicon->geometry().x();
    int xMax = systemtrayicon->geometry().x()+systemtrayicon->geometry().width();
    int yMin = systemtrayicon->geometry().y();
    int yMax = systemtrayicon->geometry().y()+systemtrayicon->geometry().height();
    int x = QCursor::pos().x();
    int y = QCursor::pos().y();
    //第一步，鼠标先触碰到图标 设置值为真，检测到真，则可以显示消息框
    //当鼠标离开消息框，设置值为假。
    //判断鼠标是否在信息框范围内
    int taryX = this->tarywidget->geometry().x();
    int taryY = this->tarywidget->geometry().y();
    int taryXmix = this->tarywidget->geometry().width()+taryX;
    int taryYmix = this->tarywidget->geometry().height()+taryY;
    if(taryX<=x&&x<=taryXmix&&taryY<=y&&y<=taryYmix&&this->ishover)
    {
        this->tarywidget->show();
        //qDebug()<<"进入范围";
        return;
    }
    if((xMin<=x&&x<=xMax&&yMin<=y&&y<=yMax)&&stringlistdata.length()!=0)
    {
        //判断消息池是否有消息
        ishover=true;
        //qDebug()<<"ishover为真";
        systemtrayicon->setToolTip("");
        this->tarywidget->setGeometry(xMin-125,yMin-165,270,160);
        this->tarywidget->show();
    }
    else
    {
        this->ishover=false;
        //qDebug()<<"不在托盘中";
        QString str = QString("Fdog:%1(%2)\n声音:关闭\n消息提示框:关闭\n会话消息:任务栏头像闪动").arg(this->name,this->account);
        systemtrayicon->setToolTip(str);
        this->tarywidget->hide();
    }
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QWidget * pwig=NULL;
    pwig = ui->listWidget->itemWidget(item);
    //判断当前窗口在不在
    bool isshow = false;
    for(int i=0;i<listchat.length();i++)
    {
        if(listchat[i]->getOtheraccount()==pwig->findChild<QLabel *>("label2")->text())
        {
            isshow=true;
            listchat[i]->show();
        }
    }
    if(!isshow)
    {
        Chat * chat = new Chat(this->icon,sqconn.getPixmapIcon(pwig->findChild<QLabel *>("label2")->text()),
                               pwig->findChild<QLabel *>("label2")->text(),
                               pwig->findChild<QLabel *>("label3")->text(),this);
        qDebug()<<"问题5";
        chat->setAccount(this->account);
        chat->setAttribute(Qt::WA_DeleteOnClose);
        listchat.append(chat);
        connect(chat,SIGNAL(sendData(QString)),this,SLOT(MainSendData(QString)));
        connect(chat,SIGNAL(sendCount(QString)),this,SLOT(listchatcount(QString)));
        chat->show();
    }
}

void MainWindow::showAllChat()
{
    qDebug()<<"查看全部";
    on_activatedSysTratIcon(QSystemTrayIcon::DoubleClick);
}

void MainWindow::hideAllChat()
{
    if (timerT.isActive()) timerT.stop();
    if (timerNoT.isActive()) timerNoT.stop();
    this->tarywidget->deleteItem(); //列表清理
    this->stringlistdata.clear();   //清理数据词内容
    systemtrayicon->setIcon(QIcon(":/lib/fdogicon.png")); //还原托盘原本icon
}

void MainWindow::showAChat(QString account)
{
    //生成窗口
    Chat * a = new Chat(this->icon,sqconn.getPixmapIcon(account),account,sqconn.getOtherAccountName(account),this);
    a->setAccount(this->account); //本身账号
    a->setAttribute(Qt::WA_DeleteOnClose);
    a->setObjectName(account);
    listchat.append(a);
    connect(a,SIGNAL(sendData(QString)),this,SLOT(MainSendData(QString)));
    connect(a,SIGNAL(sendCount(QString)),this,SLOT(listchatcount(QString)));
    a->show();
    a->setIsread(true);
    //从消息池找有关消息
    for(int i=0;i<stringlistdata.length();i++)
    {
        QString data = stringlistdata[i];
        if(data.mid(0,8)==account)
        {
            qDebug()<<"找到数据";
            emit sendChatData(data);
        }
    }
}
