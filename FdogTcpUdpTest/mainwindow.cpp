#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QDateTime>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpClient=new QTcpSocket(this);
    connect(tcpClient,SIGNAL(connected()),
            this,SLOT(onConnected()));
    connect(tcpClient,SIGNAL(disconnected()),
            this,SLOT(onDisconnected()));
    udpClient = new QUdpSocket(this);

    this->sqconn = new Testsql();
    sqconn->connData();
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    //连接服务器
    //向服务器发送account  linestate  time  ip  tcpport udpport
    if(sqconn->queryUser(ui->lineEdit_3->text(),ui->lineEdit_4->text()))
    {
        ui->textEdit->append("账号——密码校对完毕，正确");
        //获取本机IP,本机端口,连接服务器
        QString addr = ui->lineEdit->text();
        if(addr=="")
        {
           addr  = ui->lineEdit->placeholderText();
        }
        qDebug()<<"addr"<<addr;
        quint16 port = ui->spinBox->value();
        qDebug()<<"port"<<port;
        this->tcpClient->connectToHost(addr,port);
        ui->lineEdit_9->setText(getLocalIP());
    }
    else
    {
        ui->textEdit->append("账号——密码校对完毕，错误");

    }

}

void MainWindow::onConnected()
{
    ui->textEdit->append("已连接服务器(TCP协议)");
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_6->setEnabled(true);
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyyMMddhhmmss");
    if(ui->comboBox->currentIndex()==0)ui->comboBox->setCurrentIndex(1);
    QString msg =ui->lineEdit_3->text()+QString::number(ui->comboBox->currentIndex()-1)+current_date;
    QByteArray str = msg.toUtf8();
    str.append('\n');
    tcpClient->write(str);
    ui->textEdit->append("已通过TCP协议向服务端发送数据(1-8位为账号，9位为登录状态，10-23为登录时间):\n"+msg);
    //通过UDP协议向数据库发送信息
    quint16 port = 6666;
    QHostAddress udpaddr("82.156.111.139");
    QString msg2 = "6666";
    QByteArray str2 = msg2.toUtf8();
    udpClient->writeDatagram(str2,udpaddr,port);
    ui->textEdit->append("已通过UDP协议向服务端发送数据(Port):\n"+msg2);
    //查询数据库
    ui->textEdit->append("数据库获取的数据为：\n"+sqconn->queryState(ui->lineEdit_3->text()));
}

void MainWindow::onDisconnected()
{
    ui->textEdit->append("已断开服务器的连接(TCP协议)");
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_6->setEnabled(false);
    ui->comboBox->setCurrentIndex(0);
}

void MainWindow::on_pushButton_6_clicked()
{
    if(tcpClient->state()==QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
}
