#ifndef MAINWINDOW_H
#define MAINWINDOW_H
class Chat;
#include"query.h"
#include<QMainWindow>
#include<QSystemTrayIcon>
#include<QMouseEvent>
#include<QPoint>
#include<QMovie>
#include<QSize>
#include"usersql.h"
#include"chat.h"
#include<QLabel>
#include<QPushButton>
#include<QListWidget>
#include<QSignalMapper>
#include<QTcpSocket>
#include<QLabel>
#include<QList>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QList<Chat *>  listchat;
    QTcpSocket * tcpClient;//连接网络
    QLabel * LabSocketate;
    QWidget * aa = new QWidget();
    QMenu * menu;
    QSystemTrayIcon  * systemtrayicon;
    QPoint m_point;
    Usersql sqconn; //获取个人信息
    Usersql sqconnother; //获取分钟信息
    //QLabel * m_label;
    QPixmap icon = "";      //头像
    QString account = "";   //账号
    QString name = "";      //昵称
    QString signature ="";  //个性签名
    QSignalMapper * myMapper;
    QList<QPushButton *> listbtn;//分组名
    QList<bool> iswidget;//列表展开
    QList<QListWidget *> listwidget; //分组列表
    QPoint last;//窗口拖动用变量
    bool isPressedWidget;
    int count = 0;
    //分组信息
    Query * a; //查找窗口
    //分组好友
public:
    QString getLocalIP();//获取本机IP地址
    explicit MainWindow(QString account,QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void showicon();
    void setAccount(QString account);
    QPixmap PixmapToRound(QPixmap &src, int radius);
    bool eventFilter(QObject *obj, QEvent *event);
    ~MainWindow();
signals:
    void sendChatData(QString data);

private slots:
    void mousePressEvent(QMouseEvent *event);//鼠标点击
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放
    void on_min_tool_clicked(); //最小化
    void on_close_tool_clicked(); //关闭按钮
    void on_activatedSysTratIcon(QSystemTrayIcon::ActivationReason reason);

    void on_toolButton_3_clicked();

    void on_widget_clicked(int i);//分组按钮被点击
    void on_Double_widget_clicked(QListWidgetItem * witem);//好友被双击
    void onSocketStateChange(QAbstractSocket::SocketState socketState);
    void onConnected();
    void onDisconnected();
    void onSocketReadyRead();
    void listchatcount(); //监视chat数据
    void MainSendData(QString str);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
