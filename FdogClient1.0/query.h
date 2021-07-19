#ifndef QUERY_H
#define QUERY_H

#include <QWidget>
#include"usersql.h"
namespace Ui {
class Query;
}

class Query : public QWidget
{
    Q_OBJECT
private:
    Usersql sqconn;
    QPixmap icon = "";      //头像
    QString account;
    QPoint last;                        //窗口拖动用变量
    bool isPressedWidget;

public:
    QPixmap PixmapToRound(QPixmap &src, int radius);
    explicit Query(QString account,QWidget *parent = 0);
    ~Query();
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *event);//鼠标点击
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放

private slots:

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_toolButton_4_clicked();
    void MainSendAddData(QString);

private:
    Ui::Query *ui;
};

#endif // QUERY_H
