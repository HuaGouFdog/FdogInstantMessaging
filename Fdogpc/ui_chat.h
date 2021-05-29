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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
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
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QPlainTextEdit *plainTextEdit;
    QFrame *line;
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
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QStringLiteral("Chat"));
        Chat->resize(707, 647);
        QFont font;
        font.setPointSize(5);
        Chat->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/icon2505897252.png"), QSize(), QIcon::Normal, QIcon::Off);
        Chat->setWindowIcon(icon);
        Chat->setStyleSheet(QLatin1String("#Chat{\n"
"background-color: rgb(0, 0, 0);\n"
"}"));
        verticalLayout = new QVBoxLayout(Chat);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 1, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 2, 8, 6);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(Chat);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        toolButton = new QToolButton(Chat);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/zuixiaohua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(Chat);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(Chat);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon3);
        toolButton_3->setIconSize(QSize(20, 20));
        toolButton_3->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget = new QWidget(Chat);
        widget->setObjectName(QStringLiteral("widget"));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        widget->setFont(font2);
        widget->setStyleSheet(QStringLiteral("background-color: rgb(191, 191, 191);"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 546, 361));
        scrollAreaWidgetContents->setStyleSheet(QStringLiteral(""));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QFont font3;
        font3.setPointSize(12);
        plainTextEdit->setFont(font3);
        plainTextEdit->setStyleSheet(QLatin1String("background-color:transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        plainTextEdit->setReadOnly(true);

        verticalLayout_5->addWidget(plainTextEdit);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout_4->addLayout(verticalLayout_2);

        line = new QFrame(widget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setStyleSheet(QStringLiteral(""));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        toolButton_4 = new QToolButton(widget_3);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(20, 20));
        toolButton_4->setMaximumSize(QSize(20, 20));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lib/weixiao.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon4);
        toolButton_4->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(widget_3);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(20, 20));
        toolButton_5->setMaximumSize(QSize(20, 20));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/lib/caijian.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon5);
        toolButton_5->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(widget_3);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(20, 20));
        toolButton_6->setMaximumSize(QSize(20, 20));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/lib/mianxingtubiao_zhendong.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon6);
        toolButton_6->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        toolButton_7 = new QToolButton(widget_3);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setMinimumSize(QSize(20, 20));
        toolButton_7->setMaximumSize(QSize(20, 20));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/lib/fangda.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon7);
        toolButton_7->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_7);

        toolButton_8 = new QToolButton(widget_3);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setMinimumSize(QSize(20, 20));
        toolButton_8->setMaximumSize(QSize(20, 20));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/lib/shijian.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon8);
        toolButton_8->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_8);


        verticalLayout_4->addWidget(widget_3);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 141));
        lineEdit->setFont(font3);
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
        pushButton_4->setMinimumSize(QSize(70, 25));
        QFont font4;
        font4.setPointSize(10);
        pushButton_4->setFont(font4);
        pushButton_4->setStyleSheet(QLatin1String("border-style:solid;\n"
"background-color: rgb(203, 203, 203);\n"
"border-width:1px;\n"
"border-radius:3px;"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(70, 25));
        pushButton_3->setFont(font4);
        pushButton_3->setStyleSheet(QLatin1String("border-style:solid;\n"
"border-color: rgb(68, 68, 68);\n"
"background-color: rgb(68, 68, 68);\n"
"border-width:1px;\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);"));
        pushButton_3->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addWidget(widget);

        widget_2 = new QWidget(Chat);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(137, 0));
        widget_2->setMaximumSize(QSize(120, 16777215));
        widget_2->setStyleSheet(QLatin1String("background-color: rgb(191, 191, 191);\n"
"border-width:1px;\n"
"border-left-color: rgb(166, 166, 166);"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(120, 310));
        label_2->setMaximumSize(QSize(120, 310));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/lib/body.png);"));

        verticalLayout_3->addWidget(label_2);

        verticalSpacer_2 = new QSpacerItem(20, 169, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(widget_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 13);
        QWidget::setTabOrder(pushButton_3, pushButton_4);
        QWidget::setTabOrder(pushButton_4, toolButton);
        QWidget::setTabOrder(toolButton, toolButton_2);
        QWidget::setTabOrder(toolButton_2, toolButton_3);

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
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
