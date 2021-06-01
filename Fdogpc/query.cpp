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

Query::Query(QString account,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Query)
{
    ui->setupUi(this);
    this->account = account;
    setWindowFlags (Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->pushButton_3->setIcon(QIcon(":/lib/add.png"));
}

Query::~Query()
{
    delete ui;
}

void Query::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
        QPainter painter(this);
        QPixmap pixmap(":/lib/background.png");//做好的图
        qDrawBorderPixmap(&painter, this->rect(), QMargins(0, 0, 0, 0), pixmap);
        QRect rect(this->rect().x()+8, this->rect().y()+8, this->rect().width()-16, this->rect().height()-16);
        painter.fillRect(rect, QColor(255, 255, 255));
}

void Query::mousePressEvent(QMouseEvent *event)
{
    isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    last = event->globalPos();
}

void Query::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget)
        {
            int dx = event->globalX() - last.x();
            int dy = event->globalY() - last.y();
            last = event->globalPos();
            move(x()+dx, y()+dy);
        }
}

void Query::mouseReleaseEvent(QMouseEvent *event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x()+dx, y()+dy);
    isPressedWidget = false; // 鼠标松开时，置为false
}

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

void Query::on_pushButton_clicked()
{
    QString otheraccount = ui->lineEdit->text();
    //this->account = account;
    //qDebug()<<"输入的账号是："<<ui->lineEdit->text();
    //链接数据库
    this->sqconn.conndata();
    //获取头像
    this->icon=sqconn.getPixmapIcon(otheraccount);
    this->icon=this->icon.scaled(QSize(this->icon.width(), this->icon.height()), Qt::IgnoreAspectRatio);
    this->icon= PixmapToRound(this->icon, this->icon.width()/2);
    ui->pushButton_4->setIcon(QIcon(this->icon));
    //获取昵称
    ui->label_2->setText(sqconn.getOtherAccountName(otheraccount));
    ui->label_3->setText(sqconn.getOtherAccountAge(otheraccount)+"岁");


}

void Query::on_pushButton_3_clicked()
{
    //头像, 搜索账号,名字，本身账号，性别，年龄职业
    //this->account 被搜索账号
    Addfriend * a = new Addfriend(this->icon,ui->lineEdit->text(),ui->label_2->text(),this->account,sqconn.getOtherAccountSex(this->account),ui->label_3->text(),sqconn.getOtherAccountProfession(this->account));
    connect(Globalobserver::getAddfriendp(),SIGNAL(sendaddinfo(QString)),Globalobserver::getMainwindowp(),SLOT(MainSendAddData(QString)));
    a->show();
}


void Query::on_toolButton_4_clicked()
{
    this->hide();
}

void Query::MainSendAddData(QString)
{
    qDebug()<<"查找窗口接收到信号";
}
