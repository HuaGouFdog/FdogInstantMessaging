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
#include"usersql.h"
#include"mainwindow.h"
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT
    QSystemTrayIcon  * systemtrayicon;  //系统托盘
    QPoint m_point;                     //点类
    QMovie * m_movie;                   //添加动态图
    QSize m_si;                         //动态图压缩大小
    Usersql sqconn;                     //数据库类
    MainWindow * w;                     //主界面类
    QString account ="";                //查询账户
    QPoint last;                        //窗口拖动用变量
    bool isPressedWidget;
    bool ispasswd=false;                //判断是否是密码
    QStringList infoList;               //用户账号
    QStringList infopasswd;             //用户密码
    QStringList icon;                   //头像保存地址
    QListWidget * m_AccountList;        //下拉列表框
    QMenu * menu;                       //右击菜单
    QAction *m_pShowAction;             //显示选项
    QAction *m_pCloseAction;            //退出选项
    QSignalMapper * myMapper;
    QVector<int> infoListsign;
public:
    explicit Login(QWidget *parent = 0);
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


    void showwidget();
    void closewidget();
    void deleteaccount(int i);



private:
    Ui::Login *ui;
};

#endif // LOGIN_H
