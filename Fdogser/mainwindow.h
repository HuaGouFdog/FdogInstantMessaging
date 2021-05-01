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
    usersql sqconn;
    QLabel * LabListen;//状态栏标签
    QLabel * LabSocketState;//状态栏标签
    QTcpServer * tcpServer;//TCP服务器
    //QTcpSocket * tcpSocket;//TCP通信的Socket
    QList <QTcpSocket *> tcpSocket;
    QList <bool> isfrist;
    QString getLocalIP();//获取本机IP地址
protected:
    //void closeEvent(QCloseEvent * event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onNewConnection();
    void onSocketStateChange(QAbstractSocket::SocketState socketState);
    void onClientConnected(int);
    void onClientDisconnected(int);
    void onSocketReadyRead(int);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
