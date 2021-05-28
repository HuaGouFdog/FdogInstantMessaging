#include "agreefriend.h"
#include "ui_agreefriend.h"
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
    sqconn.conndata();
    sqconn.getverify("今日",this->otheraccount,"同意",ui->lineEdit->text(),ui->comboBox->currentText(),this->account);
    //数据库找到目的方
    //通知主界面更新ui
    emit updateverify(this->otheraccount,this->account);
    this->hide();
}

void Agreefriend::on_pushButton_2_clicked()
{
    Usersql sqconn;
    sqconn.conndata();
    sqconn.getverify("今日",this->otheraccount,"拒绝",ui->lineEdit->text(),ui->comboBox->currentText(),this->account);
    //拒绝
    emit updateverify(this->otheraccount,this->account);
    //通知主界面更新ui
    this->hide();
}
