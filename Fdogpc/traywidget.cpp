#include "traywidget.h"
#include "ui_traywidget.h"
#include<QDebug>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
Traywidget::Traywidget(QString name,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Traywidget)
{
    qDebug()<<"创1";
    ui->setupUi(this);
    this->setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->listWidget->setFrameShape(QListWidget::NoFrame);
    ui->label->setText(name);
    qDebug()<<"创1";
}

Traywidget::~Traywidget()
{
    delete ui;
}
QString Traywidget::getName() const
{
    return name;
}

void Traywidget::setName(const QString &value)
{
    name = value;
    ui->label->setText(name);
}

void Traywidget::setTrayWidgetItem(QPixmap pixmap,const QString &str,const QString &account)
{
    qDebug()<<"消息1";
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(10);
    //font.setBold(true);
    font.setStyleStrategy(QFont::PreferAntialias);
    QHBoxLayout *horLayout = new QHBoxLayout();//水平布局
    horLayout->setContentsMargins(0,0,0,0);
    horLayout->setSpacing(0);
    QPushButton * btn = new QPushButton();
    btn->setIcon(pixmap);
    QSize btnsize(25,25);
    btn->setIconSize(btnsize);
    btn->setFixedSize(26,26);
    btn->setFlat(true);
    QLabel * la = new QLabel("  "+str);
    la->setFont(font);
    horLayout->addWidget(btn);
    horLayout->addWidget(la);
    QWidget * widget = new QWidget(this);
    widget->setObjectName(account);
    widget->setLayout(horLayout);
    QListWidgetItem * Listitem = new QListWidgetItem(ui->listWidget);
    Listitem->setSizeHint(QSize(270, 26));  //每次改变Item的高度
    ui->listWidget->setItemWidget(Listitem,widget);
    ui->listWidget->setStyleSheet("QListWidget{color:gray;font-size:12px;background:#FAFAFD;}\
                    QScrollBar{width:0;height:0}");
    //ui->listWidget->setFixedSize(270,26*(1));
    //ui->listWidget->sortItems();
}

void Traywidget::deleteItem()
{
    ui->listWidget->clear();
}

void Traywidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
        QPainter painter(this);
        QPixmap pixmap(":/lib/background.png");//做好的图
        qDrawBorderPixmap(&painter, this->rect(), QMargins(0, 0, 0, 0), pixmap);
        QRect rect(this->rect().x()+8, this->rect().y()+8, this->rect().width()-16, this->rect().height()-16);
        painter.fillRect(rect, QColor(255, 255, 255));
}

void Traywidget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    //获得信息，包括头像，名字，账号，传给主界面
    QWidget * widget = ui->listWidget->itemWidget(item);
    //从消息池找到正确的消息
    emit senddata3(widget->objectName());//获取正确的消息
    //删除选中消息
    ui->listWidget->removeItemWidget(item);
}

void Traywidget::on_pushButton_2_clicked()//查看全部
{
    emit senddata();
}

void Traywidget::on_pushButton_clicked()//忽略全部
{
    emit senddata2();
}
