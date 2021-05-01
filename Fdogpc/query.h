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

public:
    QPixmap PixmapToRound(QPixmap &src, int radius);
    explicit Query(QWidget *parent = 0);
    ~Query();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_toolButton_4_clicked();

private:
    Ui::Query *ui;
};

#endif // QUERY_H
