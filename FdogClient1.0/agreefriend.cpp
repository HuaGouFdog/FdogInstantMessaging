#include "agreefriend.h"
#include "ui_agreefriend.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
Agreefriend::Agreefriend(QString account,QString otheraccount,QString name,QStringList grouping,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Agreefriend)
{
    ui->setupUi(this);
    this->account = account;
    this->otheraccount = otheraccount;
   ui->lineEdit->setText(name);
   ui->comboBox->addItems(grouping);
   Globalobserver::setAgreefriend(this);
   connect(Globalobserver::getAgreefriend(),SIGNAL(updategrouping(QString,QString,QString,QString)),
           Globalobserver::getMainwindowp(),SLOT(updatamaingrouping(QString,QString,QString,QString)));

   connect(Globalobserver::getAgreefriend(),SIGNAL(updateverify(QString,QString)),
           Globalobserver::getMainwindowp(),SLOT(updatamainverify(QString,QString)));
}

Agreefriend::~Agreefriend()
{
    delete ui;
}

void Agreefriend::on_pushButton_clicked()
{
    //同意
    //数据库找到发起方，更新数据，在对应分组增加该好友
    //QString time, QString otheraccount, QString sate, QString name, QString grouping, QString account
    Usersql sqconn;
    sqconn.connData();
    sqconn.getverify("今日",this->otheraccount,"同意",ui->lineEdit->text(),ui->comboBox->currentText(),this->account);
    //数据库找到目的方
    //两个作用，第一个是告诉自己更新列表，第二个是告诉对方更新列表
    //通知主界面更新ui
    emit updategrouping(this->otheraccount,this->account,ui->lineEdit->text(),ui->comboBox->currentText());//更新数据库内容
    //emit updateverify(this->otheraccount,this->account);//更新列表显示内容
    this->hide();
}

void Agreefriend::on_pushButton_2_clicked()
{
    Usersql sqconn;
    sqconn.connData();
    sqconn.getverify("今日",this->otheraccount,"拒绝",ui->lineEdit->text(),ui->comboBox->currentText(),this->account);
    //拒绝
    emit updateverify(this->otheraccount,this->account);
    //两个作用，第一个是告诉自己更新列表，第二个是告诉对方更新列表
    //通知主界面更新ui
    this->hide();
}
