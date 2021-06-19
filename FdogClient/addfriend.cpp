#include "addfriend.h"
#include "ui_addfriend.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
Addfriend::Addfriend(QPixmap icon,QString otheraccount,QString name,QString account,QString sex, QString age,QString Profession,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Addfriend)
{
    ui->setupUi(this);
    setWindowFlags (Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    Globalobserver::setAddfriendp(this);
    //显示该用户信息
    this->setOtheraccount(otheraccount);
    this->setAccount(account);
    this->setName(name);
    ui->pushButton_3->setIcon(QIcon(icon));
    ui->pushButton_3->setIconSize(QSize(70,70));
    ui->label_8->setText(name);
    ui->label_9->setText(otheraccount);
    ui->label_10->setText("性别:"+sex);
    ui->label_11->setText("年龄:"+age);
    ui->label_12->setText("职业:"+Profession);
    sqconn.connData();
    sqconn.queryUserInfo(account);
    ui->comboBox->addItem(this->getName());
    QStringList groupings = sqconn.getGrouping();
    ui->comboBox_2->addItems(groupings);
}

Addfriend::~Addfriend()
{
    delete ui;
}

void Addfriend::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
        QPainter painter(this);
        QPixmap pixmap(":/lib/background.png");//做好的图
        qDrawBorderPixmap(&painter, this->rect(), QMargins(0, 0, 0, 0), pixmap);
        QRect rect(this->rect().x()+8, this->rect().y()+8, this->rect().width()-16, this->rect().height()-16);
        painter.fillRect(rect, QColor(255, 255, 255));
}

void Addfriend::mousePressEvent(QMouseEvent *event)
{
    isPressedWidget = true; // 当前鼠标按下的即是QWidget而非界面上布局的其它控件
    last = event->globalPos();
}

void Addfriend::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressedWidget)
        {
            int dx = event->globalX() - last.x();
            int dy = event->globalY() - last.y();
            last = event->globalPos();
            move(x()+dx, y()+dy);
        }
}

void Addfriend::mouseReleaseEvent(QMouseEvent *event)
{
    int dx = event->globalX() - last.x();
    int dy = event->globalY() - last.y();
    move(x()+dx, y()+dy);
    isPressedWidget = false; // 鼠标松开时，置为false
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
        QString otheraccount = this->getOtheraccount(); //发送方
        QString account = this->getAccount(); //接收方
        QString info = ui->lineEdit->text(); //验证信息
        QString name = ui->comboBox->currentText();//备注(默认网名)
        QString grouping = ui->comboBox_2->currentText();//分组
        QDateTime curDateTime=QDateTime::currentDateTime();
        QString time = curDateTime.toString("MM.dd");
        if(info=="")info="你好";
        //消息格式：接收方+添加方+验证信息+备注名字（默认网名）+分组+消息类型
        QString data = otheraccount+account+info+":"+name+":"+grouping+"yan";
        sqconn.setverify(time,account,"等待同意",name,grouping,otheraccount);
        //qDebug()<<"发送验证消息"<<data;
        //qDebug()<<"完成后：全局函数值：";
        //qDebug()<<Globalobserver::getAddfriendp();
        //qDebug()<<Globalobserver::getMainwindowp();
        //发送消息
        emit sendaddinfo(data);
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

QString Addfriend::getOtheraccount() const
{
    return otheraccount;
}

void Addfriend::setOtheraccount(const QString &value)
{
    otheraccount = value;
}

QString Addfriend::getAccount() const
{
    return account;
}

void Addfriend::setAccount(const QString &value)
{
    account = value;
}

QString Addfriend::getName() const
{
    return name;
}

void Addfriend::setName(const QString &value)
{
     name = value;
}
