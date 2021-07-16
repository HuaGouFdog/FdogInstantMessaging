#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTcpServer>
#include<QTcpSocket>
#include<QHostInfo>
#include<QTcpSocket>
#include<QUdpSocket>
#include"testsql.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QTcpSocket * tcpClient;
    QUdpSocket * udpClient;
    Testsql * sqconn;
public:
    explicit MainWindow(QWidget *parent = 0);
    QString getLocalIP();
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();
    void onConnected();
    void onDisconnected();
    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
