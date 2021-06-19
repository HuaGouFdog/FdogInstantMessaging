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
    QPixmap pixmap;
    QPixmap mypixmap;
    QPoint last;                        //窗口拖动用变量
    bool isPressedWidget;
public:
    explicit Chat(QPixmap mypixmap,QPixmap pixmap,QString otheraccount,QString name,MainWindow * main, QWidget *parent = 0);
    QString getLocalIP();
    QWidget * CreateWidgetL_R(int i,QString data);
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *event);//鼠标点击
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放
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
    void sendCount(QString otheraccount);
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

    void on_toolButton_clicked();

private:
    Ui::Chat *ui;
};

#endif // CHAT_H
