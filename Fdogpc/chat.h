#ifndef CHAT_H
#define CHAT_H
class MainWindow;
#include"mainwindow.h"
#include <QWidget>
#include<QTcpSocket>
#include<QLabel>
namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT
private:
    QTcpSocket * tcpClient;
    QLabel * LabSocketate;
    QString name;//对方网名
    QString otheraccount;//对方账号
    QString account;  //本身帐户
    MainWindow * mainwindow;//主窗口指针
    bool isread = false;
    int isdown;
    QString getLocalIP();
public:

    explicit Chat(QString otheraccount,QString name,MainWindow * main, QWidget *parent = 0);
    QWidget * CreateWidgetL();
    QWidget * CreateWidgetR();
    ~Chat();

    QString getName() const;
    void setName(const QString &value);

    QString getID() const;
    void setID(const QString &value);

    bool getIsread() const;
    void setIsread(bool value);

    MainWindow *getMainwindow() const;
    void setMainwindow(MainWindow *value);

    QString getAccount() const;
    void setAccount(const QString &value);

    int getIsdown() const;
    void setIsdown(int value);

    QString getOtheraccount() const;
    void setOtheraccount(const QString &value);

signals:
    void sendData(QString str);
    void sendCount();
private slots:
    void closeEvent(QCloseEvent *e);
    void onSocketStateChange(QAbstractSocket::SocketState socketState);
    void onConnected();
    void onDisconnected();
    void onSocketReadyRead(QString data);
//    void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();

    void on_toolButton_3_clicked();

private:
    Ui::Chat *ui;
};

#endif // CHAT_H
