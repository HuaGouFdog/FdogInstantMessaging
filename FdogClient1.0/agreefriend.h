#ifndef AGREEFRIEND_H
#define AGREEFRIEND_H
class Globalobserver;
#include <QWidget>
#include"usersql.h"
#include"globalobserver.h"
namespace Ui {
class Agreefriend;
}

class Agreefriend : public QWidget
{
    Q_OBJECT
private:
    QString account;
    QString otheraccount;

public:
    explicit Agreefriend(QString account,QString otheraccount,QString name,QStringList grouping,QWidget *parent = 0);
    ~Agreefriend();

signals:
    void updategrouping(QString otheraccount,QString account,QString name,QString grouping);
    void updateverify(QString otheraccount,QString account);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Agreefriend *ui;
};

#endif // AGREEFRIEND_H
