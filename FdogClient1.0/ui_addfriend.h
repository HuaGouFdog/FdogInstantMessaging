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
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QLabel *label;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_5;
    QWidget *widget_2;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_3;
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
        Addfriend->resize(459, 305);
        Addfriend->setMaximumSize(QSize(459, 337));
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/fdogicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Addfriend->setWindowIcon(icon);
        Addfriend->setStyleSheet(QLatin1String("*{font-family:Microsoft YaHei;\n"
"\n"
"}\n"
"#Addfriend{\n"
"\n"
"}"));
        verticalLayout = new QVBoxLayout(Addfriend);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        widget_4 = new QWidget(Addfriend);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setStyleSheet(QStringLiteral("background-color: rgb(112, 217, 255);"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton = new QToolButton(widget_4);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(0, 34));
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(18, 18));
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        label = new QLabel(widget_4);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 34));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(9);
        font.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label);

        toolButton_2 = new QToolButton(widget_4);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(25, 25));
        toolButton_2->setMaximumSize(QSize(25, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/zuixiaohua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(widget_4);
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


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(Addfriend);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setMinimumSize(QSize(5, 5));
        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 131, 211));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(179, 248, 255);"));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 110, 61, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei"));
        font1.setStyleStrategy(QFont::PreferAntialias);
        label_8->setFont(font1);
        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 130, 61, 16));
        label_9->setFont(font1);
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 150, 71, 16));
        label_10->setFont(font1);
        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 170, 71, 16));
        label_11->setFont(font1);
        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 190, 111, 16));
        label_12->setFont(font1);
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 20, 81, 81));
        pushButton_3->setAutoDefault(true);
        pushButton_3->setFlat(true);
        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 210, 451, 51));
        widget_3->setStyleSheet(QStringLiteral("background-color: rgb(201, 255, 255);"));
        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 10, 75, 31));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QLatin1String("background-color: rgb(130, 178, 255);\n"
"border-style:solid;\n"
"color: rgb(255, 255, 255);\n"
"border-radius:5px;\n"
""));
        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 10, 75, 31));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QLatin1String("background-color: rgb(130, 178, 255);\n"
"border-style:solid;\n"
"color: rgb(255, 255, 255);\n"
"border-radius:5px;\n"
""));
        stackedWidget = new QStackedWidget(widget_5);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(130, 0, 327, 211));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 40, 301, 71));
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QLatin1String("border-style:solid;\n"
"border-width:1px;\n"
"border-color: rgb(136, 136, 136);\n"
"border-radius:3px;\n"
""));
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 121, 20));
        label_3->setFont(font1);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 20, 54, 31));
        label_4->setFont(font1);
        comboBox = new QComboBox(page_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(100, 20, 171, 31));
        comboBox->setStyleSheet(QStringLiteral(""));
        comboBox->setEditable(true);
        comboBox_2 = new QComboBox(page_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(100, 60, 171, 31));
        comboBox_2->setEditable(true);
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 60, 54, 31));
        label_5->setFont(font1);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 30, 31, 31));
        label_6->setStyleSheet(QStringLiteral("border-image: url(:/lib/down.png);"));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 20, 261, 51));
        label_7->setFont(font1);
        stackedWidget->addWidget(page_3);

        verticalLayout->addWidget(widget_5);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

        retranslateUi(Addfriend);

        pushButton_3->setDefault(false);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Addfriend);
    } // setupUi

    void retranslateUi(QWidget *Addfriend)
    {
        Addfriend->setWindowTitle(QApplication::translate("Addfriend", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        toolButton->setText(QApplication::translate("Addfriend", "...", nullptr));
        label->setText(QApplication::translate("Addfriend", "\350\212\261\347\213\227Fdog - \346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        toolButton_2->setText(QApplication::translate("Addfriend", "...", nullptr));
        toolButton_3->setText(QApplication::translate("Addfriend", "...", nullptr));
        label_8->setText(QApplication::translate("Addfriend", "\344\273\212\345\244\234\346\227\240\351\243\216", nullptr));
        label_9->setText(QApplication::translate("Addfriend", "12346578", nullptr));
        label_10->setText(QApplication::translate("Addfriend", "\346\200\247\345\210\253\357\274\232\347\224\267", nullptr));
        label_11->setText(QApplication::translate("Addfriend", "\345\271\264\351\276\204\357\274\23220\345\262\201", nullptr));
        label_12->setText(QApplication::translate("Addfriend", "\346\211\200\345\234\250\345\234\260\357\274\232\346\261\237\350\213\217 \345\256\277\350\277\201", nullptr));
        pushButton_3->setText(QString());
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
