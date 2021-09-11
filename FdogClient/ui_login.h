/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QLabel *mian_label;
    QLabel *label_2;
    QPushButton *register_btn;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QToolButton *toolButton_3;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_4;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QPushButton *pushButton_3;
    QToolButton *toolButton_5;
    QWidget *widget_2;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_5;
    QWidget *page_2;
    QLabel *label_13;
    QPushButton *pushButton_6;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QToolButton *toolButton_6;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(446, 342);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        Login->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/fdogicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QLatin1String("*{font-family:Microsoft YaHei;}\n"
"\n"
"#Login{\n"
"background-color: rgb(84, 62, 255);\n"
"}"));
        gridLayout = new QGridLayout(Login);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 2, 0, 0);
        widget = new QWidget(Login);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(431, 304));
        widget->setMaximumSize(QSize(425, 330));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei"));
        font1.setStyleStrategy(QFont::PreferAntialias);
        widget->setFont(font1);
        widget->setStyleSheet(QLatin1String("#widet{\n"
"border-radius: 10px;\n"
"border-style:solid;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"}"));
        mian_label = new QLabel(widget);
        mian_label->setObjectName(QStringLiteral("mian_label"));
        mian_label->setGeometry(QRect(0, 0, 431, 131));
        mian_label->setFont(font1);
        mian_label->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"border-top-left-radius:10px;\n"
"border-top-right-radius:10px;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 129, 431, 200));
        label_2->setMinimumSize(QSize(431, 200));
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
""));
        register_btn = new QPushButton(widget);
        register_btn->setObjectName(QStringLiteral("register_btn"));
        register_btn->setGeometry(QRect(10, 290, 71, 21));
        register_btn->setFont(font1);
        register_btn->setStyleSheet(QLatin1String("#register_btn{\n"
"color: rgb(149, 149, 149);\n"
"}\n"
"#register_btn:hover{\n"
"color: rgb(120, 120, 120);\n"
"}"));
        register_btn->setAutoDefault(false);
        register_btn->setFlat(true);
        horizontalLayoutWidget_2 = new QWidget(widget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(110, 230, 227, 31));
        horizontalLayoutWidget_2->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(horizontalLayoutWidget_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(78, 25));
        checkBox->setFont(font1);
        checkBox->setStyleSheet(QLatin1String("#checkBox{\n"
"color: rgb(149, 149, 149);\n"
"}\n"
"#checkBox:hover{\n"
"color: rgb(120, 120, 120);\n"
"}"));

        horizontalLayout_2->addWidget(checkBox);

        checkBox_2 = new QCheckBox(horizontalLayoutWidget_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setMinimumSize(QSize(78, 25));
        checkBox_2->setFont(font1);
        checkBox_2->setStyleSheet(QLatin1String("#checkBox_2{\n"
"color: rgb(149, 149, 149);\n"
"}\n"
"#checkBox_2:hover{\n"
"color: rgb(120, 120, 120);\n"
"}"));

        horizontalLayout_2->addWidget(checkBox_2);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 0));
        pushButton_2->setMaximumSize(QSize(57, 20));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QLatin1String("#pushButton_2{\n"
"color: rgb(149, 149, 149);\n"
"}\n"
"#pushButton_2:hover{\n"
"color: rgb(120, 120, 120);\n"
"}"));
        pushButton_2->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_2);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 150, 221, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei"));
        comboBox->setFont(font2);
        comboBox->setStyleSheet(QLatin1String("QComboBox \n"
"{ \n"
"font-size:15px;\n"
"}\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"min-height: 50px; \n"
"min-width: 60px; \n"
"\n"
"}\n"
"::drop-down{\n"
"	border-style:solid;\n"
"	border-width:1px;\n"
"	width:20px ;\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-bottom-color: rgb(129, 129, 129);\n"
"}\n"
"::down-arrow{\n"
"border-image: url(:/lib/jietou1.png);\n"
"}"));
        comboBox->setEditable(true);
        comboBox->setMaxVisibleItems(10);
        comboBox->setInsertPolicy(QComboBox::NoInsert);
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
        comboBox->setIconSize(QSize(10, 10));
        toolButton_3 = new QToolButton(widget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(229, 134, 16, 16));
        toolButton_3->setFont(font1);
        toolButton_3->setStyleSheet(QLatin1String("border-width:2px;\n"
"border-style:solid;\n"
"border-radius: 8px;\n"
"border-color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/zaixian.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon1);
        toolButton_3->setAutoRaise(true);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 79, 72, 72));
        label_5->setFont(font1);
        label_5->setStyleSheet(QLatin1String("\n"
"border-style:solid;\n"
"border-radius: 36px;\n"
"background-color: rgba(255, 255, 255,200);"));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 150, 204, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei"));
        font3.setPointSize(12);
        font3.setStyleStrategy(QFont::PreferAntialias);
        lineEdit_2->setFont(font3);
        lineEdit_2->setStyleSheet(QLatin1String("border-style:solid;\n"
"border-width:1px;\n"
"border-top-color: rgba(255, 255, 255, 0);\n"
"border-right-color: rgba(255, 255, 255, 0);\n"
"border-left-color: rgba(255, 255, 255, 0);\n"
"border-bottom-color: rgb(129, 129, 129);\n"
"\n"
"\n"
""));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 190, 221, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Microsoft YaHei"));
        font4.setPointSize(14);
        font4.setStyleStrategy(QFont::PreferAntialias);
        lineEdit->setFont(font4);
        lineEdit->setStyleSheet(QLatin1String("border-style:solid;\n"
"border-width:1px;\n"
"border-top-color: rgba(255, 255, 255, 0);\n"
"border-right-color: rgba(255, 255, 255, 0);\n"
"border-left-color: rgba(255, 255, 255, 0);\n"
"border-bottom-color: rgb(129, 129, 129);"));
        lineEdit->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 270, 221, 37));
        QFont font5;
        font5.setFamily(QStringLiteral("Microsoft YaHei"));
        font5.setPointSize(13);
        font5.setBold(false);
        font5.setWeight(50);
        font5.setKerning(true);
        font5.setStyleStrategy(QFont::PreferAntialias);
        pushButton->setFont(font5);
        pushButton->setMouseTracking(false);
        pushButton->setTabletTracking(false);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setToolTipDuration(-1);
        pushButton->setStyleSheet(QLatin1String("#pushButton{\n"
"background-color: rgb(99, 188, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"}\n"
"#pushButton:hover{\n"
"background-color: rgb(99, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"\n"
"}\n"
"#pushButton:pressed{\n"
"background-color: rgb(99, 188, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"padding-left:2px;\n"
"padding-top:2px;\n"
"}\n"
""));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);
        horizontalWidget = new QWidget(widget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(4, 0, 421, 41));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton_4 = new QToolButton(horizontalWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(83, 39));
        toolButton_4->setMaximumSize(QSize(83, 39));
        toolButton_4->setStyleSheet(QLatin1String("border-style:solid;\n"
"background-color: rgba(255, 255, 255, 0);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/mainicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon2);
        toolButton_4->setIconSize(QSize(80, 80));
        toolButton_4->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton = new QToolButton(horizontalWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(25, 25));
        toolButton->setMaximumSize(QSize(25, 25));
        toolButton->setSizeIncrement(QSize(25, 25));
        toolButton->setFont(font1);
        toolButton->setStyleSheet(QLatin1String("border-style:solid;\n"
"background-color: rgba(255, 255, 255, 0);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/zuixiaohua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon3);
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(horizontalWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(25, 25));
        toolButton_2->setMaximumSize(QSize(25, 25));
        toolButton_2->setFont(font1);
        toolButton_2->setStyleSheet(QLatin1String("border-style:solid;\n"
"background-color: rgba(255, 255, 255, 0);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lib/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon4);
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);

        toolButton->raise();
        toolButton_4->raise();
        toolButton_2->raise();
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(183, 82, 66, 66));
        pushButton_3->setStyleSheet(QLatin1String("border-image: url(:/lib/icon2505897252.png);\n"
"border-width:0px;\n"
"border-style:solid;\n"
"border-radius:32px;\n"
"border-color: rgb(255, 255, 255);"));
        toolButton_5 = new QToolButton(widget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(380, 280, 30, 30));
        toolButton_5->setStyleSheet(QLatin1String("border-style:solid;\n"
"background-color: rgba(255, 255, 255, 0);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/lib/erweima.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon5);
        toolButton_5->setIconSize(QSize(30, 30));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 431, 331));
        widget_2->setStyleSheet(QLatin1String("#widget_2{\n"
"background-color: rgba(0, 0, 0, 50);\n"
"}"));
        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(150, 270, 131, 35));
        QFont font6;
        font6.setFamily(QStringLiteral("Microsoft YaHei"));
        font6.setPointSize(13);
        font6.setBold(false);
        font6.setWeight(50);
        font6.setStyleStrategy(QFont::PreferAntialias);
        pushButton_4->setFont(font6);
        pushButton_4->setStyleSheet(QLatin1String("#pushButton_4{\n"
"color: rgb(255, 255, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"#pushButton_4:hover{\n"
"color: rgb(255, 255, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"#pushButton_4:pressed{\n"
"color: rgb(255, 255, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"padding-left:2px;\n"
"padding-top:2px;\n"
"}\n"
"\n"
""));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 170, 71, 31));
        QFont font7;
        font7.setFamily(QStringLiteral("Microsoft YaHei"));
        font7.setPointSize(14);
        font7.setBold(true);
        font7.setWeight(75);
        font7.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font7);
        label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 255, 255, 0);"));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 431, 331));
        stackedWidget = new QStackedWidget(widget_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-1, -1, 431, 331));
        stackedWidget->setStyleSheet(QLatin1String("#page,#page_2{\n"
"border-image: url(:/lib/error.png);\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 100, 250, 20));
        label_4->setFont(font1);
        label_4->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 120, 250, 20));
        label_6->setFont(font1);
        label_6->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 140, 250, 20));
        label_7->setFont(font1);
        label_7->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        label_8 = new QLabel(page);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(90, 160, 250, 20));
        label_8->setFont(font1);
        label_8->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        label_9 = new QLabel(page);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(90, 180, 250, 20));
        label_9->setFont(font1);
        label_9->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        label_10 = new QLabel(page);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(90, 200, 250, 20));
        label_10->setFont(font1);
        label_10->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        label_11 = new QLabel(page);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(50, 100, 36, 41));
        label_11->setStyleSheet(QLatin1String("border-image: url(:/lib/anquan.png);\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_12 = new QLabel(page);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(90, 240, 321, 20));
        label_12->setFont(font1);
        label_12->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 290, 71, 31));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QLatin1String("#pushButton_5{\n"
"color: rgb(255, 255, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;\n"
"background-color: rgb(134, 219, 255);\n"
"}\n"
"#pushButton_5:hover{\n"
"color: rgb(255, 255, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;\n"
"}\n"
"#pushButton_5:pressed{\n"
"color: rgb(255, 255, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;\n"
"padding-left:2px;\n"
"padding-top:2px;\n"
"}\n"
""));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_13 = new QLabel(page_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(140, 130, 161, 16));
        label_13->setFont(font);
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(350, 290, 71, 31));
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QLatin1String("#pushButton_6{\n"
"color: rgb(255, 255, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;\n"
"	background-color: rgb(134, 219, 255);\n"
"}\n"
"#pushButton_6:hover{\n"
"color: rgb(255, 255, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;\n"
"}\n"
"#pushButton_6:pressed{\n"
"color: rgb(255, 255, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;\n"
"padding-left:2px;\n"
"padding-top:2px;\n"
"}\n"
""));
        label_14 = new QLabel(page_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(140, 150, 161, 16));
        label_14->setFont(font);
        label_15 = new QLabel(page_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(90, 130, 31, 31));
        label_15->setStyleSheet(QStringLiteral("border-image: url(:/lib/network.png);"));
        stackedWidget->addWidget(page_2);
        label_3->raise();
        label->raise();
        pushButton_4->raise();
        stackedWidget->raise();
        label_16 = new QLabel(widget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(0, 310, 431, 20));
        label_16->setStyleSheet(QLatin1String("background-color: rgb(253, 255, 206);\n"
"color: rgb(126, 126, 126);"));
        toolButton_6 = new QToolButton(widget);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(391, 308, 25, 25));
        toolButton_6->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-style:solid;"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/lib/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon6);
        toolButton_6->setIconSize(QSize(12, 11));
        toolButton_6->setAutoRaise(true);
        mian_label->raise();
        label_2->raise();
        register_btn->raise();
        horizontalLayoutWidget_2->raise();
        comboBox->raise();
        lineEdit_2->raise();
        lineEdit->raise();
        pushButton->raise();
        toolButton_5->raise();
        widget_2->raise();
        label_5->raise();
        pushButton_3->raise();
        toolButton_3->raise();
        horizontalWidget->raise();
        label_16->raise();
        toolButton_6->raise();

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        QWidget::setTabOrder(comboBox, lineEdit);
        QWidget::setTabOrder(lineEdit, checkBox);
        QWidget::setTabOrder(checkBox, checkBox_2);
        QWidget::setTabOrder(checkBox_2, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton);
        QWidget::setTabOrder(pushButton, register_btn);
        QWidget::setTabOrder(register_btn, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, toolButton_3);
        QWidget::setTabOrder(toolButton_3, toolButton);
        QWidget::setTabOrder(toolButton, toolButton_2);

        retranslateUi(Login);

        register_btn->setDefault(false);
        pushButton_2->setDefault(false);
        comboBox->setCurrentIndex(-1);
        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", nullptr));
        mian_label->setText(QString());
        label_2->setText(QString());
        register_btn->setText(QApplication::translate("Login", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        checkBox->setText(QApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        checkBox_2->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        pushButton_2->setText(QApplication::translate("Login", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        toolButton_3->setText(QApplication::translate("Login", "...", nullptr));
        label_5->setText(QString());
        lineEdit_2->setPlaceholderText(QApplication::translate("Login", "Fdog\345\217\267\347\240\201/\351\202\256\347\256\261/\346\211\213\346\234\272\345\217\267", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("Login", "\345\257\206\347\240\201", nullptr));
        pushButton->setText(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton->setShortcut(QApplication::translate("Login", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        toolButton_4->setText(QApplication::translate("Login", "...", nullptr));
        toolButton->setText(QApplication::translate("Login", "...", nullptr));
        toolButton_2->setText(QApplication::translate("Login", "...", nullptr));
        pushButton_3->setText(QString());
        toolButton_5->setText(QString());
        pushButton_4->setText(QApplication::translate("Login", "\345\217\226\346\266\210", nullptr));
        label->setText(QApplication::translate("Login", "\347\231\273\345\275\225\344\270\255", nullptr));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("Login", "\344\275\240\350\276\223\345\205\245\347\232\204\345\270\220\346\210\267\345\220\215\346\210\226\345\257\206\347\240\201\344\270\215\346\255\243\347\241\256\357\274\214\345\216\237\345\233\240\345\217\257\350\203\275\346\230\257\357\274\232", nullptr));
        label_6->setText(QApplication::translate("Login", "1. \345\270\220\346\210\267\345\220\215\350\276\223\345\205\245\346\234\211\350\257\257;", nullptr));
        label_7->setText(QApplication::translate("Login", "2. \345\277\230\350\256\260\345\257\206\347\240\201;", nullptr));
        label_8->setText(QApplication::translate("Login", "3. \346\234\252\345\214\272\345\210\206\345\255\227\346\257\215\345\244\247\345\260\217\345\206\231;", nullptr));
        label_9->setText(QApplication::translate("Login", "4. \346\234\252\345\274\200\345\220\257\345\260\217\351\224\256\347\233\230;", nullptr));
        label_10->setText(QApplication::translate("Login", "5. \345\270\220\346\210\267\345\220\215\346\234\252\347\273\221\345\256\232QQ\345\217\267\343\200\202", nullptr));
        label_11->setText(QString());
        label_12->setText(QApplication::translate("Login", "\345\246\202\346\236\234\344\275\240\347\232\204\345\257\206\347\240\201\344\270\242\345\244\261\346\210\226\350\200\205\351\201\227\345\277\230\357\274\214\345\217\257\344\273\245\350\256\277\351\227\256Fdog\345\256\230\347\275\221\346\211\276\345\233\236\345\257\206\347\240\201\343\200\202", nullptr));
        pushButton_5->setText(QApplication::translate("Login", "\347\241\256\345\256\232", nullptr));
        label_13->setText(QApplication::translate("Login", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250\350\266\205\346\227\266\357\274\214\350\257\267\351\207\215\350\257\225\343\200\202", nullptr));
        pushButton_6->setText(QApplication::translate("Login", "\347\241\256\345\256\232", nullptr));
        label_14->setText(QApplication::translate("Login", "(\351\224\231\350\257\257\347\240\201\357\274\2320x00000001)", nullptr));
        label_15->setText(QString());
        label_16->setText(QApplication::translate("Login", "  \357\274\201\350\257\245\350\264\246\345\217\267\345\267\262\347\273\217\347\231\273\345\275\225\357\274\214\350\257\267\345\213\277\351\207\215\345\244\215\347\231\273\345\275\225\343\200\202", nullptr));
        toolButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
