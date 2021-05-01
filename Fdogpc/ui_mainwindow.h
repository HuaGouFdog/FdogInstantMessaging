/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *icon_tool;
    QSpacerItem *horizontalSpacer;
    QToolButton *skin_tool;
    QToolButton *min_tool;
    QToolButton *close_tool;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QLabel *signature_label;
    QToolButton *toolButton_2;
    QLabel *username_label;
    QPushButton *pushButton;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton;
    QLineEdit *lineEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *tab_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(325, 659);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/fdogicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral("*{font-family:Microsoft YaHei;}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(15, 15, 15, 15);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(4, 8, 6, 8);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(301, 601));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"\n"
"background-color: rgb(193, 255, 183);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(15, 15, 15, 15);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 5, 3, 5);
        horizontalSpacer_4 = new QSpacerItem(4, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        icon_tool = new QToolButton(widget);
        icon_tool->setObjectName(QStringLiteral("icon_tool"));
        icon_tool->setMinimumSize(QSize(20, 20));
        icon_tool->setMaximumSize(QSize(20, 20));
        icon_tool->setStyleSheet(QStringLiteral(""));
        icon_tool->setIcon(icon);
        icon_tool->setIconSize(QSize(33, 33));
        icon_tool->setCheckable(false);
        icon_tool->setChecked(false);
        icon_tool->setAutoRaise(true);

        horizontalLayout->addWidget(icon_tool);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        skin_tool = new QToolButton(widget);
        skin_tool->setObjectName(QStringLiteral("skin_tool"));
        skin_tool->setMinimumSize(QSize(25, 25));
        skin_tool->setMaximumSize(QSize(25, 25));
        skin_tool->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/skin.png"), QSize(), QIcon::Normal, QIcon::Off);
        skin_tool->setIcon(icon1);
        skin_tool->setIconSize(QSize(20, 20));
        skin_tool->setAutoRaise(true);

        horizontalLayout->addWidget(skin_tool);

        min_tool = new QToolButton(widget);
        min_tool->setObjectName(QStringLiteral("min_tool"));
        min_tool->setMinimumSize(QSize(25, 25));
        min_tool->setMaximumSize(QSize(25, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/zuixiaohua.png"), QSize(), QIcon::Normal, QIcon::Off);
        min_tool->setIcon(icon2);
        min_tool->setIconSize(QSize(20, 20));
        min_tool->setAutoRaise(true);

        horizontalLayout->addWidget(min_tool);

        close_tool = new QToolButton(widget);
        close_tool->setObjectName(QStringLiteral("close_tool"));
        close_tool->setMinimumSize(QSize(25, 25));
        close_tool->setMaximumSize(QSize(25, 25));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_tool->setIcon(icon3);
        close_tool->setIconSize(QSize(20, 20));
        close_tool->setAutoRaise(true);

        horizontalLayout->addWidget(close_tool);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(301, 87));
        widget_2->setMaximumSize(QSize(301, 93));
        signature_label = new QLabel(widget_2);
        signature_label->setObjectName(QStringLiteral("signature_label"));
        signature_label->setGeometry(QRect(80, 40, 161, 18));
        signature_label->setStyleSheet(QLatin1String(":hover{\n"
"border-style:solid;\n"
"border-width:1px;\n"
"	border-color: rgb(108, 108, 108);\n"
"}"));
        toolButton_2 = new QToolButton(widget_2);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(49, 47, 18, 18));
        toolButton_2->setMinimumSize(QSize(18, 18));
        toolButton_2->setMaximumSize(QSize(15, 15));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lib/zaixian.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon4);
        toolButton_2->setAutoRaise(true);
        username_label = new QLabel(widget_2);
        username_label->setObjectName(QStringLiteral("username_label"));
        username_label->setGeometry(QRect(80, 16, 71, 16));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        username_label->setFont(font);
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(15, 10, 53, 53));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QLatin1String("#pushButton{\n"
"border-radius:25px;\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-color: rgba(255, 255, 255,20);\n"
"}\n"
"#pushButton::hover{\n"
"border-radius:25px;\n"
"border-style:solid;\n"
"border-width:4px;\n"
"border-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        pushButton->setIconSize(QSize(50, 50));
        toolButton_5 = new QToolButton(widget_2);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(142, 13, 41, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei"));
        font1.setBold(true);
        font1.setWeight(75);
        toolButton_5->setFont(font1);
        toolButton_5->setStyleSheet(QLatin1String("color: rgb(255, 47, 11);\n"
"border-image: url(:/lib/dengji.png);"));
        toolButton_5->setIconSize(QSize(60, 20));
        toolButton_5->setAutoRaise(true);
        toolButton_6 = new QToolButton(widget_2);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(195, 13, 40, 20));
        toolButton_6->setMinimumSize(QSize(40, 20));
        toolButton_6->setMaximumSize(QSize(40, 20));
        toolButton_6->setLayoutDirection(Qt::LeftToRight);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/lib/svip.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon5);
        toolButton_6->setIconSize(QSize(60, 20));
        toolButton_6->setAutoRaise(true);
        signature_label->raise();
        username_label->raise();
        pushButton->raise();
        toolButton_5->raise();
        toolButton_6->raise();
        toolButton_2->raise();

        verticalLayout_2->addWidget(widget_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(27, 30));
        toolButton->setMaximumSize(QSize(27, 31));
        toolButton->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,22);"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/lib/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon6);
        toolButton->setIconSize(QSize(30, 30));
        toolButton->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(272, 30));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,22);border-color:rgba(0,0,0,255);color: rgba(9, 0, 3,0);border-style:none;border-width:1px;border-radius:0px;font:15px \"\351\273\221\344\275\223\";"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(318, 384));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QWidget::tab{\n"
"background-color: rgb(255, 255, 255);\n"
"border-style:none;\n"
"border-width:1px;\n"
"border-radius:0px;\n"
"font:18px \"\351\273\221\344\275\223\";\n"
"height:38px;\n"
"width:105px;\n"
"	color: rgb(100, 100, 100);\n"
"}\n"
""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(15);
        verticalLayout_3->setContentsMargins(15, 15, 15, 15);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(tab);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setFont(font);
        listWidget->setStyleSheet(QStringLiteral("width:10px;"));
        listWidget->setAutoScrollMargin(16);
        listWidget->setBatchSize(100);

        verticalLayout_3->addWidget(listWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setSpacing(15);
        gridLayout_2->setContentsMargins(15, 15, 15, 15);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QLatin1String("QScrollBar:vertical{\n"
"background-color:rgba(0,0,0,0);\n"
"border-color:rgba(0,0,6,0);\n"
"border-style:solid;\n"
"border-width:0px;\n"
"width:10px;\n"
"padding-top:0px;\n"
"padding-bottom:0px;\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:vertical{\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-radius:4px;\n"
"background-color:rgba(145,145,145,255);\n"
"border-color:rgba(0,0,0,0);\n"
"min-height:44px;}\n"
"\n"
"\n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,0);}\n"
"\n"
"\n"
"QScrollBar::sub-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,0);}"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 310, 396));
        scrollAreaWidgetContents->setCursor(QCursor(Qt::ArrowCursor));
        scrollAreaWidgetContents->setStyleSheet(QLatin1String("#scrollAreaWidgetContents{\n"
"background:transparent;\n"
"}"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        scrollArea_2 = new QScrollArea(tab_3);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 0, 311, 411));
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 309, 409));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setSpacing(15);
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        tabWidget->addTab(tab_3, QString());

        verticalLayout_2->addWidget(tabWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 9, -1, 9);
        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        toolButton_4 = new QToolButton(widget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(30, 30));
        toolButton_4->setMaximumSize(QSize(30, 30));
        toolButton_4->setStyleSheet(QStringLiteral(""));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/lib/sangangy.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon7);
        toolButton_4->setIconSize(QSize(25, 25));
        toolButton_4->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton_4);

        toolButton_3 = new QToolButton(widget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(30, 30));
        toolButton_3->setMaximumSize(QSize(30, 30));
        toolButton_3->setStyleSheet(QStringLiteral(""));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/lib/tianjiahaoyou.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon8);
        toolButton_3->setIconSize(QSize(25, 25));
        toolButton_3->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Fdog", nullptr));
        icon_tool->setText(QApplication::translate("MainWindow", "...", nullptr));
        skin_tool->setText(QApplication::translate("MainWindow", "...", nullptr));
        min_tool->setText(QApplication::translate("MainWindow", "...", nullptr));
        close_tool->setText(QApplication::translate("MainWindow", "...", nullptr));
        signature_label->setText(QString());
        toolButton_2->setText(QApplication::translate("MainWindow", "...", nullptr));
        username_label->setText(QString());
        pushButton->setText(QString());
        toolButton_5->setText(QString());
        toolButton_6->setText(QString());
        toolButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\346\266\210\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\350\201\224\347\263\273\344\272\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\347\251\272\351\227\264", nullptr));
        toolButton_4->setText(QString());
        toolButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
