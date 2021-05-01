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
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *verticalLayout_3;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QStringLiteral("Chat"));
        Chat->resize(568, 514);
        QFont font;
        font.setPointSize(5);
        Chat->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/icon2505897252.png"), QSize(), QIcon::Normal, QIcon::Off);
        Chat->setWindowIcon(icon);
        verticalLayout_4 = new QVBoxLayout(Chat);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(16, -1, 16, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(Chat);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        toolButton = new QToolButton(Chat);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/zuixiaohua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(Chat);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(Chat);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon3);
        toolButton_3->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_3);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollArea = new QScrollArea(Chat);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 532, 241));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QFont font2;
        font2.setPointSize(12);
        plainTextEdit->setFont(font2);
        plainTextEdit->setReadOnly(true);

        verticalLayout_5->addWidget(plainTextEdit);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        line = new QFrame(Chat);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(Chat);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 153));
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QLatin1String("background-color:transparent;\n"
"border-width:0;\n"
"border-style:outset;"));
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(Chat);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QFont font3;
        font3.setPointSize(10);
        pushButton_4->setFont(font3);

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(Chat);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFont(font3);
        pushButton_3->setAutoDefault(true);

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout);

        QWidget::setTabOrder(lineEdit, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);
        QWidget::setTabOrder(pushButton_4, plainTextEdit);
        QWidget::setTabOrder(plainTextEdit, scrollArea);
        QWidget::setTabOrder(scrollArea, toolButton);
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
        lineEdit->setText(QString());
        pushButton_4->setText(QApplication::translate("Chat", "\345\205\263\351\227\255", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_4->setShortcut(QApplication::translate("Chat", "Alt+C", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_3->setText(QApplication::translate("Chat", "\345\217\221\351\200\201", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_3->setShortcut(QApplication::translate("Chat", "Return", nullptr));
#endif // QT_NO_SHORTCUT
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
