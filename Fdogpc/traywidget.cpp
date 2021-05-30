#include "traywidget.h"
#include "ui_traywidget.h"
Traywidget::Traywidget(QString name,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Traywidget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->listWidget->setFrameShape(QListWidget::NoFrame);
    ui->label->setText(name);
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

void Traywidget::setTrayWidgetItem(QPixmap pixmap,const QString &str)
{
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
