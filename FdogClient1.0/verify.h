#ifndef VERIFY_H
#define VERIFY_H
class Agreefriend;
#include <QWidget>
#include"agreefriend.h"
#include"usersql.h"
#include"globalobserver.h"
namespace Ui {
class Verify;
}

class Verify : public QWidget
{
    Q_OBJECT

    QPoint last;         //窗口拖动用变量
    bool isPressedWidget;
    Agreefriend * agreefriend;
    QString account;    //账号
    QString time; //时间
    QString name; //对方网名
    QString sex;  //对方性别
    QString age;  //对方年龄
    QString otheraccount;//对方账号

public:
    //时间 头像  名字 男 16岁
    //附加信息
    explicit Verify(QString account,QString otheraccount,QString time,QPixmap icon,QString name,QString sex,QString age,QString add = "申请添加我为好友",QWidget *parent = 0);
    ~Verify();
    void mousePressEvent(QMouseEvent *event);//鼠标点击
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::Verify *ui;
};

#endif // VERIFY_H
