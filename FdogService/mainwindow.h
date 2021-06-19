#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<usersql.h>
#include<QMainWindow>
#include<QLabel>
#include<QTcpServer>
#include<QTcpSocket>
#include<QList>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    usersql sqconn;             //连接数据库
    QLabel * LabListen;         //状态栏标签
    QLabel * LabSocketState;    //状态栏标签
    QTcpServer * tcpServer;     //TCP服务器
    QList <QTcpSocket *> tcpSocket;//TCP通信的Socket
    QList <bool> isfrist;       //判断是否第一条消息
public:
    explicit MainWindow(QWidget *parent = 0);
    QString getLocalIP();       //获取本机IP地址
    ~MainWindow();


private slots:
    void onNewConnection();
    void onSocketStateChange(QAbstractSocket::SocketState socketState);
    void onClientConnected(int);
    void onClientDisconnected(int);
    void onSocketReadyRead(int);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
