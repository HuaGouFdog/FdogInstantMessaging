#include "addfriend.h"
#include "ui_addfriend.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
Addfriend::Addfriend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Addfriend)
{
    ui->setupUi(this);
    //获取该用户信息 需要一个账户
}

Addfriend::~Addfriend()
{
    delete ui;
}

void Addfriend::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()+1);
    switch(ui->stackedWidget->currentIndex())
    {
    case 0:
        ui->pushButton_2->setText("关闭");
    break;
    case 1:
        ui->pushButton_2->setText("取消");
    break;
    case 2:
        ui->pushButton_2->setText("完成");
        ui->pushButton->hide();
    break;
    }
}

void Addfriend::on_pushButton_2_clicked()
{
    this->close();
}

void Addfriend::on_toolButton_2_clicked()
{
    this->hide();
}

void Addfriend::on_toolButton_3_clicked()
{
    this->close();
}
