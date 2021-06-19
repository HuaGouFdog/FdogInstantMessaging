#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QWidget>
#include<QDebug>
#include<QDateTime>
#include"mainwindow.h"
#include"usersql.h"
#include"globalobserver.h"
namespace Ui {
class Addfriend;
}

class Addfriend : public QWidget
{
    Q_OBJECT
    QString otheraccount;
    QString account;
    Usersql sqconn;
    QString name;
    QPoint last;                        //窗口拖动用变量
    bool isPressedWidget;

public:
    explicit Addfriend(QPixmap icon,QString otheraccount,QString name,QString account,QString sex, QString age,QString Profession,QWidget *parent = 0);
    ~Addfriend();
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *event);//鼠标点击
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放

    QString getOtheraccount() const;
    void setOtheraccount(const QString &value);

    QString getAccount() const;
    void setAccount(const QString &value);

    QString getName() const;
    void setName(const QString &value);

signals:
    void sendaddinfo(QString data);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

private:
    Ui::Addfriend *ui;
};

#endif // ADDFRIEND_H
