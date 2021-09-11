#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QHostInfo>
#include<qDebug>
#include<QSignalMapper>
#include<usersql.h>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(!sqconn.conndata())//连接数据库
    {
        ui->plainTextEdit->appendPlainText("数据库连接不成功，请重试！");
        return;
    }
    LabListen = new QLabel("监听状态：");
    LabListen->setMinimumWidth(150);
    ui->statusBar->addWidget(LabListen);

    LabSocketState = new QLabel("Socket状态:");
    LabSocketState->setMinimumWidth(200);
    ui->statusBar->addWidget(LabSocketState);

    QString localIP = getLocalIP();//本机IP
    this->setWindowTitle(this->windowTitle()+"----本机IP:"+localIP);
    ui->comboIP->addItem(localIP);
    tcpServer = new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
    on_pushButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewConnection()
{
    QTcpSocket * tcpSocket = new QTcpSocket();
    tcpSocket = tcpServer->nextPendingConnection();
    this->tcpSocket.append(tcpSocket);
    this->isfrist.append(false);
    onClientConnected(tcpSocket->peerPort());
    QSignalMapper * myMapper1 = new QSignalMapper(this);
    connect(tcpSocket, SIGNAL(disconnected()), myMapper1, SLOT(map()));
    myMapper1->setMapping(tcpSocket,tcpSocket->peerPort());
    connect(myMapper1, SIGNAL(mapped(int)), this, SLOT(onClientDisconnected(int)));

    connect(tcpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    QSignalMapper * myMapper2 = new QSignalMapper(this);
    connect(tcpSocket, SIGNAL(readyRead()), myMapper2, SLOT(map()));
    myMapper2->setMapping(tcpSocket,tcpSocket->peerPort());
    connect(myMapper2, SIGNAL(mapped(int)), this, SLOT(onSocketReadyRead(int)));
}

void MainWindow::onSocketStateChange(QAbstractSocket::SocketState socketState)
{
    switch (socketState) {
    case QAbstractSocket::UnconnectedState:
        LabSocketState->setText("scoket状态：UnconnectedState");
        break;
    case QAbstractSocket::HostLookupState:
        LabSocketState->setText("scoket状态：HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        LabSocketState->setText("scoket状态：ConnectingState");
        break;
    case QAbstractSocket::ConnectedState:
        LabSocketState->setText("scoket状态：ConnectedState");
        break;
    case QAbstractSocket::BoundState:
        LabSocketState->setText("scoket状态：BoundState");
        break;
    case QAbstractSocket::ClosingState:
        LabSocketState->setText("scoket状态：ClosingState");
        break;
    case QAbstractSocket::ListeningState:
        LabSocketState->setText("scoket状态：ListeningState");
        break;
    default:
        break;
    }
}

void MainWindow::onClientConnected(int i)
{
    for(int j=0;j<tcpSocket.length();j++)
    {
        if(tcpSocket[j]->peerPort()==i)
        {
            ui->plainTextEdit->appendPlainText("客户端套接字已连接");
            ui->plainTextEdit->appendPlainText("客户端IP:"+
                                               tcpSocket[j]->peerAddress().toString());
            ui->plainTextEdit->appendPlainText("客户端随机分配端口号:"+
                                               QString::number(tcpSocket[j]->peerPort()));
            ui->listWidget->addItem(tcpSocket[j]->peerAddress().toString()+"  "+QString::number(tcpSocket[j]->peerPort()));
        }
    }
}

void MainWindow::onClientDisconnected(int i)
{

    for(int j=0;j<tcpSocket.length();j++)
    {
        if(tcpSocket[j]->peerPort()==i)
        {
            ui->plainTextEdit->appendPlainText("客户端套接字已断开连接");
            sqconn.update(QString::number(tcpSocket[j]->peerPort()));
            tcpSocket[j]->deleteLater();
            this->tcpSocket.removeAt(j);
            this->isfrist.removeAt(j);
            //对列表做删除操作
            ui->listWidget->takeItem(j);
        }
    }
}

void MainWindow::onSocketReadyRead(int i)
{

    for(int j=0;j<tcpSocket.length();j++)
    {
        if(tcpSocket[j]->peerPort()==i)
        {
            if(this->isfrist[j]==false)
            {
                //获取连接账号
                QString account = tcpSocket[j]->readLine();
                //写入数据库
                qDebug()<<"写入数据库";
                sqconn.update(account,QString::number(tcpSocket[j]->peerPort()));
                this->isfrist[j]=true;
            }
            else
            {
                while(tcpSocket[j]->canReadLine())
                {
                    //ui->plainTextEdit->appendPlainText("[in]"+tcpSocket[i]->readLine());
                    //获取内容
                    QString data = tcpSocket[j]->readLine();
                    //data.mid(0,8);为到达方 data.mid(8,8);为发送方
                    //遍历列表ip是否登录
                    //遍历数据库查询该帐户
                    QString account = data.mid(0,8);
                    qDebug()<<"目标帐户为："<<account;
                    //通过该帐户找到ip地址，然后发送信息
                    QString port = sqconn.AccountIP(account);
                    for(int i =0;i<this->tcpSocket.length();i++)
                    {
                        if(QString::number(tcpSocket[i]->peerPort())==port)//说明在线
                        {   //将数据转发给到达方，并保留发送方帐户，用于窗口识别
                            QByteArray str = data.mid(8).toUtf8();
                            tcpSocket[i]->write(str);
                            qDebug()<<"目标端口号："<<tcpSocket[i]->peerPort();
                        }
                    }
                }
            }
        }
    }
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

void MainWindow::on_pushButton_clicked()
{
    //开始监听
    ui->plainTextEdit->clear();
    QString IP = ui->comboIP->currentText();//IP地址
    qDebug()<<"值："<<ui->spinBox->value();
    quint16 port = ui->spinBox->value();//端口
    QHostAddress addr(IP);
    tcpServer->listen(addr,port);
    ui->plainTextEdit->appendPlainText("开始监听...");
    ui->plainTextEdit->appendPlainText("服务器地址："
                   +tcpServer->serverAddress().toString());
    ui->plainTextEdit->appendPlainText("服务器端口："
                   +QString::number(tcpServer->serverPort()));
    ui->plainTextEdit->appendPlainText("*******************************");
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);

    LabListen->setText("监听状态：正在监听");
}

void MainWindow::on_pushButton_2_clicked()
{
    //停止监听
    if(tcpServer->isListening())
    {
        tcpServer->close();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
        ui->plainTextEdit->clear();
        ui->plainTextEdit->appendPlainText("已停止监听...");
        LabListen->setText("监听状态：已停止监听");
    }
}
