#ifndef MAINWINDOW_H
#define MAINWINDOW_H
class Chat;
class Globalobserver;
class Verify;
#include<QMainWindow>
#include<QSystemTrayIcon>
#include<QMouseEvent>
#include<QPoint>
#include<QMovie>
#include<QSize>
#include<QLabel>
#include<QPushButton>
#include<QListWidget>
#include<QSignalMapper>
#include<QTcpSocket>
#include<QLabel>
#include<QList>
#include<QTimer>
#include<QMenu>
#include<QDebug>
#include<QPainter>
#include<QBitmap>
#include<QSize>
#include<qdrawutil.h>
#include<QGraphicsDropShadowEffect>
#include<QListWidget>
#include<QHostInfo>
#include"query.h"
#include"usersql.h"
#include"chat.h"
#include"verify.h"
#include"traywidget.h"
#include"addfriend.h"
#include"globalobserver.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    /*创系统图标以及托盘菜单*/
    QSystemTrayIcon  * systemtrayicon;  //系统托盘
    QMenu * menu;                       //菜单
    QMenu * mainmenu;                   //主界面菜单
    QAction *m_pShowAction;             //显示选项
    QAction *m_pCloseAction;            //退出选项
    QAction *m_pOnLineAction;           //在线
    QAction *m_pCallAction;             //call我
    QAction *m_pCloakingAction;         //隐身
    QAction *m_pLeaveAction;            //离开
    QAction *m_pBusyAction;             //忙碌
    QAction *m_pDisturbAction;          //请勿打扰
    QAction *m_pOffLineAtion;           //离线
    /*消息通知*/
    Traywidget * tarywidget;            //右下角消息显示列表
    QPixmap icondata;                   //用于保存需要闪动头像
    bool iconbool =false;               //和icondata搭配使用
    /*定时器用于托盘头像闪动，显示等*/
    QTimer timerT;
    QTimer timerNoT;
    QTimer timemouse;
    /*账号基本数据*/
    Usersql sqconn;                 //获取个人信息
    QPixmap icon;                   //头像
    QString account = "";           //账号
    QString name = "";              //昵称
    QString signature ="";          //个性签名
    QList<QPushButton *> listbtn;   //分组名
    QList<QListWidget *> listwidget; //分组列表
    /*子窗口*/
    Query * a;          //查找窗口
    Verify * verify;    //验证窗口
    QWidget * myinfo = new QWidget();//当鼠标悬浮头像弹出该窗口
    /*聊天相关*/
    QStringList stringlistdata; //数据池
    //QStringList stringaccount;  //消息池
    QList<Chat *> listchat;     //保存聊天窗口
    QVector<int> Globalinfo;    //全局消息管理 1为普通消息，二位验证消息
    /*连接网络*/
    QTcpSocket * tcpClient;//连接网络
    QLabel * LabSocketate; //显示网络类型
    /*鼠标拖动事件*/
    QList<bool> iswidget;    //列表展开
    QPoint last;             //窗口拖动变量
    bool isPressedWidget;
    /*其他*/
    QSignalMapper * myMapper; //信号管理
    QSignalMapper * menuAction;
    bool ishover = false;//判断鼠标是否进过托盘图标

public:
    explicit MainWindow(QString account,QTcpSocket *tcpClient,QWidget *parent = 0); //构造函数
    ~MainWindow();//析构函数
    void paintEvent(QPaintEvent *e);                //重绘背景
    bool eventFilter(QObject *obj, QEvent *event);  //事件过滤器
    void showicon();                                //显示系统托盘图标
    QString getLocalIP();                           //获取本机IP地址
    void datawidget(QPixmap pixmap,QString str,QString account);   //更新消息列表
signals:
    void sendChatData(QString data);//给聊天窗口发送信号及数据
    void sendquitData();//给登录窗口发送信息

private slots:
    void on_min_tool_clicked();     //最小化
    void on_close_tool_clicked();   //关闭按钮
    void on_toolButton_3_clicked(); //主界面在线按钮
    void mousePressEvent(QMouseEvent *event);   //鼠标点击
    void mouseMoveEvent(QMouseEvent *event);    //鼠标移动
    void mouseReleaseEvent(QMouseEvent *event); //鼠标释放
    void onWidgetClicked(int i);              //分组按钮被点击
    void onDoubleWidgetClicked(QListWidgetItem * witem);//好友列表被双击
    void on_activatedSysTratIcon(QSystemTrayIcon::ActivationReason reason);//对托盘按钮的点击
    /*TCP相关*/
    void onConnected();         //连接
    void onDisconnected();      //断开连接
    void onSocketReadyRead();   //收到数据
    void onSocketStateChange(QAbstractSocket::SocketState socketState); //状态
    void onSocketErrorChange(QAbstractSocket::SocketError);             //连接错误类型
    void listchatcount(QString otheraccount);       //监视chat数据
    /*托盘图标闪动相关*/
    void sltTimerT();//定时器开始
    void sltTimerNoT();//定时器停止
    void actionexe(int);//菜单，切换在线状态
    /*信息发送相关*/
    void showdata();
    void MainSendData(QString str);     //发送普通消息
    void MainSendAddData(QString str);  //发送验证消息
    /*消息验证*/
    void updatamaingrouping(QString,QString,QString,QString); //更新好友列表
    void updatamainverify(QString,QString);         //更新验证消息

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void showAllChat();
    void hideAllChat();
    void showAChat(QString account);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
