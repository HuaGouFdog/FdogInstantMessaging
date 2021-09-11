#include "verify.h"
#include "ui_verify.h"
#include"globalobserver.h"
#include"agreefriend.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

Verify::Verify(QString account,QString otheraccount,QString time,QPixmap icon,QString name,QString sex,QString age,QString add,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Verify)
{
    ui->setupUi(this);
    this->time=time;
    this->name=name;
    this->sex=sex;
    this->age=age;
    this->account=account;
    this->otheraccount=otheraccount;
    setWindowFlags (Qt::FramelessWindowHint);
    ui->label_3->setText(time);
    ui->pushButton_3->setIcon(Globalobserver::PixmapToRound(icon, icon.width()/2));
    ui->label_5->setText(name);
    ui->label_6->setText(sex+"  "+age);
    ui->label_7->setText("附加信息："+add);
}

Verify::~Verify()
{
    delete ui;
}

void Verify::mousePressEvent(QMouseEvent *event)
{
    isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    last = event->globalPos();
}

void Verify::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget)
        {
            int dx = event->globalX() - last.x();
            int dy = event->globalY() - last.y();
            last = event->globalPos();
            move(x()+dx, y()+dy);
        }
}

void Verify::mouseReleaseEvent(QMouseEvent *event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x()+dx, y()+dy);
    isPressedWidget = false; // 鼠标松开时，置为false
}

void Verify::on_pushButton_clicked()
{
    Usersql sqconn;
    sqconn.connData();
    sqconn.queryUserInfo(this->account);
    QStringList grouping =sqconn.getGrouping();
    agreefriend = new Agreefriend(this->account,this->otheraccount,this->name,grouping);
    agreefriend->show();
}

void Verify::on_toolButton_clicked()
{
    this->hide();
}

void Verify::on_toolButton_2_clicked()
{
    this->hide();
}
