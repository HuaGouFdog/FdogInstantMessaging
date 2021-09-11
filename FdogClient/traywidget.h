#ifndef TRAYWIDGET_H
#define TRAYWIDGET_H

#include <QWidget>
#include<qdrawutil.h>
#include<QPainter>
#include<QListWidgetItem>
namespace Ui {
class Traywidget;
}

class Traywidget : public QWidget
{
    Q_OBJECT
private:
    QString name;
public:
    explicit Traywidget(QString name,QWidget *parent = 0);
    ~Traywidget();
    void setTrayWidgetItem(QPixmap pixmap,const QString &str,const QString &account);
    void deleteItem();//清空列表
    void paintEvent(QPaintEvent *e);
    QString getName() const;
    void setName(const QString &value);

signals:
    void senddata();
    void senddata2();
    void senddata3(QString account);

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Traywidget *ui;
};

#endif // TRAYWIDGET_H
