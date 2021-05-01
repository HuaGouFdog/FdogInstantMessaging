/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Addfriend
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QLabel *label;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *widget_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QWidget *page_2;
    QLabel *label_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label_5;
    QWidget *page_3;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *Addfriend)
    {
        if (Addfriend->objectName().isEmpty())
            Addfriend->setObjectName(QStringLiteral("Addfriend"));
        Addfriend->resize(453, 300);
        Addfriend->setStyleSheet(QLatin1String("#Addfriend{\n"
"background-color: rgb(61, 155, 255);\n"
"}"));
        verticalLayout = new QVBoxLayout(Addfriend);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton = new QToolButton(Addfriend);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(0, 34));
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/fdogicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(18, 18));
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        label = new QLabel(Addfriend);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 34));
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label);

        toolButton_2 = new QToolButton(Addfriend);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(25, 25));
        toolButton_2->setMaximumSize(QSize(25, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/zuixiaohua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(Addfriend);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(25, 25));
        toolButton_3->setMaximumSize(QSize(25, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(20, 20));
        toolButton_3->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_3);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        widget = new QWidget(Addfriend);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 264));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 131, 231));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(179, 248, 255);"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 20, 91, 91));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/lib/10001.jpg);"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 120, 61, 16));
        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 140, 61, 16));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 160, 71, 16));
        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 180, 71, 16));
        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 200, 111, 16));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 220, 461, 51));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(201, 255, 255);"));
        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 10, 75, 25));
        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 10, 75, 25));
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(130, 0, 321, 221));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 60, 301, 71));
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 30, 121, 20));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 10, 54, 31));
        comboBox = new QComboBox(page_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(90, 10, 171, 31));
        comboBox->setEditable(true);
        comboBox_2 = new QComboBox(page_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(90, 50, 171, 31));
        comboBox_2->setEditable(true);
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 50, 54, 31));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 20, 31, 31));
        label_6->setStyleSheet(QStringLiteral("border-image: url(:/lib/zaixian.png);"));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 10, 261, 51));
        QFont font;
        font.setPointSize(10);
        label_7->setFont(font);
        stackedWidget->addWidget(page_3);

        verticalLayout->addWidget(widget);


        retranslateUi(Addfriend);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Addfriend);
    } // setupUi

    void retranslateUi(QWidget *Addfriend)
    {
        Addfriend->setWindowTitle(QApplication::translate("Addfriend", "Form", nullptr));
        toolButton->setText(QApplication::translate("Addfriend", "...", nullptr));
        label->setText(QApplication::translate("Addfriend", "\350\212\261\347\213\227Fdog - \346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        toolButton_2->setText(QApplication::translate("Addfriend", "...", nullptr));
        toolButton_3->setText(QApplication::translate("Addfriend", "...", nullptr));
        label_2->setText(QString());
        label_8->setText(QApplication::translate("Addfriend", "\344\273\212\345\244\234\346\227\240\351\243\216", nullptr));
        label_9->setText(QApplication::translate("Addfriend", "12346578", nullptr));
        label_10->setText(QApplication::translate("Addfriend", "\346\200\247\345\210\253\357\274\232\347\224\267", nullptr));
        label_11->setText(QApplication::translate("Addfriend", "\345\271\264\351\276\204\357\274\23220\345\262\201", nullptr));
        label_12->setText(QApplication::translate("Addfriend", "\346\211\200\345\234\250\345\234\260\357\274\232\346\261\237\350\213\217 \345\256\277\350\277\201", nullptr));
        pushButton->setText(QApplication::translate("Addfriend", "\344\270\213\344\270\200\346\255\245", nullptr));
        pushButton_2->setText(QApplication::translate("Addfriend", "\345\205\263\351\227\255", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("Addfriend", "\346\210\221\346\230\257...", nullptr));
        label_3->setText(QApplication::translate("Addfriend", "\350\257\267\350\276\223\345\205\245\351\252\214\350\257\201\344\277\241\346\201\257\357\274\232", nullptr));
        label_4->setText(QApplication::translate("Addfriend", "\345\244\207\346\263\250\345\247\223\345\220\215\357\274\232", nullptr));
        label_5->setText(QApplication::translate("Addfriend", "\345\210\206\347\273\204\357\274\232", nullptr));
        label_6->setText(QString());
        label_7->setText(QApplication::translate("Addfriend", "\344\275\240\347\232\204\345\245\275\345\217\213\346\267\273\345\212\240\350\257\267\346\261\202\345\267\262\347\273\217\345\217\221\351\200\201\346\210\220\345\212\237\357\274\214\346\255\243\345\234\250\347\255\211\345\276\205\n"
"\345\257\271\346\226\271\347\241\256\350\256\244\343\200\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Addfriend: public Ui_Addfriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
