#ifndef LOGIN_H
#define LOGIN_H
#include<QSystemTrayIcon>
#include <QWidget>
#include<QMovie>
#include<QSize>
#include<QMouseEvent>
#include<QPoint>
#include<QStringList>
#include<QListWidget>
#include<QPainter>
#include<QDesktopServices>
#include<QListView>
#include<QDebug>
#include<qdrawutil.h>
#include<QGraphicsDropShadowEffect>
#include<QDir>
#include<QCoreApplication>
#include<QFile>
#include<QTextCodec>
#include<QMenu>
#include<QMessageBox>
#include<algorithm>
#include<QTimer>
#include<QHBoxLayout>
#include"usersql.h"
#include"mainwindow.h"
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT
    QTcpSocket * tcpClient = NULL;//连接网络
    QSystemTrayIcon  * systemtrayicon = NULL;  //系统托盘
    QPoint m_point;                     //点类
    QMovie * m_movie = NULL;                   //添加动态图
    QMovie * m_movie2 = NULL;                  //添加动态图2
    QSize m_si;                         //动态图压缩大小
    QSize m_si2;                        //动态图压缩大小2
    Usersql sqconn;                     //数据库类
    MainWindow * w = NULL;                     //主界面类
    QString account ="";                //查询账户
    QPoint last;                        //窗口拖动用变量
    bool isPressedWidget;
    bool ispasswd=false;                //判断是否是密码
    QStringList infoList;               //用户账号
    QStringList infopasswd;             //用户密码
    QStringList icon;                   //头像保存地址
    QListWidget * m_AccountList = NULL;        //下拉列表框
    QMenu * menu = NULL;                       //右击菜单
    QAction *m_pShowAction = NULL;             //显示选项
    QAction *m_pCloseAction = NULL;            //退出选项
    QSignalMapper * myMapper = NULL;
    QVector<int> infoListsign;
    QTimer timesignin;
    quint16 port;
    QString addr =getLocalIP();
    bool network = true; //是否能正常连接主机

    QAction * searchAction = NULL;
    QAction * searchAction_2 = NULL;
    QAction * searchAction_3 = NULL;
    QHBoxLayout *horLayout = NULL;
    QPushButton * la = NULL;
    QLabel * la2 = NULL;
    QPushButton * b1 = NULL;

public:
    explicit Login(QWidget *parent = 0);
    QString getLocalIP();                           //获取本机IP地址
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *event);//鼠标点击
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放
    QStringList GetDirNameList(const QString &strDirpath);
    ~Login();

private slots:

    void on_toolButton_2_clicked();

    void on_toolButton_clicked();

    void on_register_btn_clicked();

    void on_pushButton_clicked();

    void on_activatedSysTratIcon(QSystemTrayIcon::ActivationReason reason);

    void on_comboBox_currentIndexChanged(int index);
    void onConnected();//连接
    //void onSocketStateChange(QAbstractSocket::SocketState);//状态
    void onSocketErrorChange(QAbstractSocket::SocketError);//连接错误类型

    void showwidget();
    void closewidget();
    void deleteaccount(int i);



    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_toolButton_6_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
