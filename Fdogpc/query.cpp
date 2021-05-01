#include "query.h"
#include "ui_query.h"
#include<QDebug>
#include<QPixmap>
#include<QPainter>
#include<QBitmap>
#include"addfriend.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
QPixmap Query::PixmapToRound(QPixmap &src, int radius)
{
    if (src.isNull()) {
            return QPixmap();
        }
        QSize size(2*radius, 2*radius);
        //掩码图（黑白色）
        QBitmap mask(size);
        QPainter painter(&mask);
        //Antialiasing：反走样（抗锯齿）
        painter.setRenderHint(QPainter::Antialiasing);
        //SmoothPixmapTransform：用来在对图片进行缩放时启用线性插值算法而不是最邻近算法
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        //填充矩形
        painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
        //画刷
        painter.setBrush(QColor(0, 0, 0));
        //绘制圆角矩形
        /*QPainter::drawRoundedRect
           (const QRectF &rect,
            qreal xRadius,
            qreal yRadius,
            Qt::SizeMode mode = Qt::AbsoluteSize)
        */
        painter.drawRoundedRect(0, 0, size.width(), size.height(), 190, 190);
        //自适应图片
        QPixmap image = src.scaled(size);
        //setMask：创建不规则窗口使用
        image.setMask(mask);
        return image;
}

Query::Query(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Query)
{
    ui->setupUi(this);
}

Query::~Query()
{
    delete ui;
}

void Query::on_pushButton_clicked()
{
    QString account = ui->lineEdit->text();
    qDebug()<<"输入的账号是："<<ui->lineEdit->text();
    //链接数据库
    this->sqconn.conndata();
    //获取数据
    sqconn.queryUserInfo(account);
    //获取昵称
    qDebug()<<"昵称："<<sqconn.getName();
    ui->lineEdit_4->setText(sqconn.getName());
    //获取头像
    this->icon=sqconn.getIcon();
    this->icon=this->icon.scaled(QSize(this->icon.width(), this->icon.height()), Qt::IgnoreAspectRatio);
    this->icon= PixmapToRound(this->icon, this->icon.width()/2);
    ui->pushButton_4->setIcon(QIcon(this->icon));

}

void Query::on_pushButton_3_clicked()
{
    Addfriend * a = new Addfriend();
    a->show();
}


void Query::on_toolButton_4_clicked()
{
    this->hide();
}
