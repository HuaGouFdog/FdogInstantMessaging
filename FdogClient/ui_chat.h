/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QStringLiteral("Chat"));
        Chat->resize(842, 746);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        Chat->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/icon2505897252.png"), QSize(), QIcon::Normal, QIcon::Off);
        Chat->setWindowIcon(icon);
        Chat->setStyleSheet(QLatin1String("*{font-family:Microsoft YaHei;}\n"
"#Chat{\n"
"background-color: rgb(0, 0, 0);\n"
"}"));
        verticalLayout = new QVBoxLayout(Chat);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, 0, 0);
        widget_4 = new QWidget(Chat);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setMinimumSize(QSize(332, 41));
        widget_4->setMaximumSize(QSize(16777215, 34));
        widget_4->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        horizontalLayout_5 = new QHBoxLayout(widget_4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(260, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label = new QLabel(widget_4);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 33));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei"));
        font1.setPointSize(13);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        toolButton = new QToolButton(widget_4);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/zuixiaohua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButton);

        toolButton_2 = new QToolButton(widget_4);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(widget_4);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon3);
        toolButton_3->setIconSize(QSize(20, 20));
        toolButton_3->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButton_3);

        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        horizontalLayout->addWidget(widget_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget = new QWidget(Chat);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setFont(font);
        widget->setStyleSheet(QStringLiteral("background-color: rgb(191, 191, 191);"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setStyleSheet(QLatin1String("background-color:transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 671, 398));
        scrollAreaWidgetContents->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(8);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout_4->addLayout(verticalLayout_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QLatin1String("background-color: rgb(191, 191, 191);\n"
"border-width:1px;\n"
"border-style:solid;\n"
"border-top-color: rgb(166, 166, 166);"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(4, 0, 4, 0);
        toolButton_4 = new QToolButton(widget_3);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(30, 30));
        toolButton_4->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lib/weixiao.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon4);
        toolButton_4->setIconSize(QSize(20, 20));
        toolButton_4->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(widget_3);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(30, 30));
        toolButton_5->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/lib/caijian.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon5);
        toolButton_5->setIconSize(QSize(20, 20));
        toolButton_5->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(widget_3);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(30, 30));
        toolButton_6->setMaximumSize(QSize(30, 30));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/lib/mianxingtubiao_zhendong.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon6);
        toolButton_6->setIconSize(QSize(20, 20));
        toolButton_6->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        toolButton_7 = new QToolButton(widget_3);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setMinimumSize(QSize(30, 30));
        toolButton_7->setMaximumSize(QSize(30, 30));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/lib/fangda.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon7);
        toolButton_7->setIconSize(QSize(20, 20));
        toolButton_7->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_7);

        toolButton_8 = new QToolButton(widget_3);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setMinimumSize(QSize(30, 30));
        toolButton_8->setMaximumSize(QSize(30, 30));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/lib/shijian.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon8);
        toolButton_8->setIconSize(QSize(20, 20));
        toolButton_8->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_8);


        verticalLayout_4->addWidget(widget_3);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 190));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei"));
        font2.setPointSize(14);
        font2.setStyleStrategy(QFont::PreferAntialias);
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QLatin1String("background-color:transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_4->addWidget(lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(80, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei"));
        font3.setPointSize(10);
        font3.setStyleStrategy(QFont::PreferAntialias);
        pushButton_4->setFont(font3);
        pushButton_4->setStyleSheet(QLatin1String("border-style:solid;\n"
"background-color: rgb(203, 203, 203);\n"
"border-width:1px;\n"
"border-radius:3px;"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(80, 30));
        pushButton_3->setFont(font3);
        pushButton_3->setStyleSheet(QLatin1String("border-style:solid;\n"
"border-color: rgb(68, 68, 68);\n"
"background-color: rgb(68, 68, 68);\n"
"border-width:1px;\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);"));
        pushButton_3->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_3);

        horizontalSpacer_7 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);


        verticalLayout_4->addLayout(horizontalLayout_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 18));

        verticalLayout_4->addWidget(label_3);


        horizontalLayout_3->addWidget(widget);

        widget_2 = new QWidget(Chat);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(151, 0));
        widget_2->setMaximumSize(QSize(149, 16777215));
        widget_2->setStyleSheet(QLatin1String("background-color: rgb(191, 191, 191);\n"
"border-width:1px;\n"
"border-style:solid;\n"
"border-left-color: rgb(166, 166, 166);"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(122, 350));
        label_2->setMaximumSize(QSize(137, 362));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/lib/body.png);"));

        verticalLayout_3->addWidget(label_2);

        verticalSpacer_2 = new QSpacerItem(20, 169, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(widget_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 15);
        QWidget::setTabOrder(pushButton_3, pushButton_4);

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Form", nullptr));
        label->setText(QApplication::translate("Chat", "\344\273\212\345\244\234\346\227\240\351\243\216", nullptr));
        toolButton->setText(QApplication::translate("Chat", "...", nullptr));
        toolButton_2->setText(QApplication::translate("Chat", "...", nullptr));
        toolButton_3->setText(QApplication::translate("Chat", "...", nullptr));
        toolButton_4->setText(QApplication::translate("Chat", "...", nullptr));
        toolButton_5->setText(QApplication::translate("Chat", "...", nullptr));
        toolButton_6->setText(QApplication::translate("Chat", "...", nullptr));
        toolButton_7->setText(QApplication::translate("Chat", "...", nullptr));
        toolButton_8->setText(QApplication::translate("Chat", "...", nullptr));
        lineEdit->setText(QString());
        pushButton_4->setText(QApplication::translate("Chat", "\345\205\263\351\227\255", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_4->setShortcut(QApplication::translate("Chat", "Alt+C", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_3->setText(QApplication::translate("Chat", "\345\217\221\351\200\201", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_3->setShortcut(QApplication::translate("Chat", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        label_3->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
