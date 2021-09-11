/********************************************************************************
** Form generated from reading UI file 'query.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERY_H
#define UI_QUERY_H

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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Query
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_2;
    QToolButton *toolButton_4;
    QWidget *widget_3;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QWidget *widget_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *Query)
    {
        if (Query->objectName().isEmpty())
            Query->setObjectName(QStringLiteral("Query"));
        Query->resize(898, 599);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/fdogicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Query->setWindowIcon(icon);
        Query->setStyleSheet(QLatin1String("*{font-family:Microsoft YaHei;}\n"
"#Query{\n"
"background-color: rgb(193, 255, 183);\n"
"}"));
        gridLayout = new QGridLayout(Query);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(7, 7, 7, 7);
        widget_2 = new QWidget(Query);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QLatin1String("#widget_2{\n"
"background-color: rgb(228, 241, 255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(120, 192, 255);"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setStyleStrategy(QFont::PreferAntialias);
        toolButton->setFont(font);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei"));
        font1.setPointSize(12);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        toolButton_2 = new QToolButton(widget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/zuixiaohua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton_2);

        toolButton_4 = new QToolButton(widget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon2);
        toolButton_4->setIconSize(QSize(20, 20));
        toolButton_4->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton_4);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);

        verticalLayout_2->addWidget(widget);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(0, 151));
        widget_3->setStyleSheet(QLatin1String("#widget_3{\n"
"border-style:solid;\n"
"border-width:2px;\n"
"	border-bottom-color: rgb(198, 198, 198);\n"
"}\n"
""));
        comboBox_2 = new QComboBox(widget_3);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(460, 70, 80, 30));
        comboBox_2->setMinimumSize(QSize(70, 30));
        comboBox_2->setMaximumSize(QSize(80, 16777215));
        comboBox_2->setFont(font);
        comboBox_2->setStyleSheet(QLatin1String("border-color: rgb(110, 149, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;"));
        lineEdit = new QLineEdit(widget_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 20, 500, 31));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(500, 16777215));
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QLatin1String("border-color: rgb(110, 149, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;"));
        comboBox = new QComboBox(widget_3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(370, 70, 80, 30));
        comboBox->setMinimumSize(QSize(70, 30));
        comboBox->setMaximumSize(QSize(80, 16777215));
        comboBox->setFont(font);
        comboBox->setStyleSheet(QLatin1String("border-color: rgb(110, 149, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;"));
        lineEdit_3 = new QLineEdit(widget_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(200, 70, 150, 30));
        lineEdit_3->setMinimumSize(QSize(0, 30));
        lineEdit_3->setMaximumSize(QSize(150, 16777215));
        lineEdit_3->setFont(font);
        lineEdit_3->setStyleSheet(QLatin1String("border-color: rgb(110, 149, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;"));
        lineEdit_2 = new QLineEdit(widget_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(40, 70, 150, 30));
        lineEdit_2->setMinimumSize(QSize(0, 30));
        lineEdit_2->setMaximumSize(QSize(150, 16777215));
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QLatin1String("border-color: rgb(110, 149, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;"));
        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(630, 50, 141, 41));
        pushButton->setMinimumSize(QSize(90, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei"));
        font2.setPointSize(14);
        font2.setStyleStrategy(QFont::PreferAntialias);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QLatin1String("background-color: rgb(111, 188, 255);\n"
"border-style:solid;\n"
"color: rgb(255, 255, 255);\n"
"border-radius:5px;"));
        checkBox = new QCheckBox(widget_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(560, 20, 57, 31));
        checkBox->setMinimumSize(QSize(0, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        font3.setStyleStrategy(QFont::PreferAntialias);
        checkBox->setFont(font3);
        checkBox->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        pushButton_3 = new QPushButton(widget_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(140, 60, 73, 23));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QLatin1String("background-color: rgb(130, 178, 255);\n"
"border-style:solid;\n"
"color: rgb(255, 255, 255);\n"
"border-radius:5px;\n"
""));
        pushButton_4 = new QPushButton(widget_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 20, 66, 66));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QStringLiteral("border-radius:33px;"));
        pushButton_4->setIconSize(QSize(66, 66));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 20, 54, 12));
        label_2->setFont(font);
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 40, 54, 12));
        label_3->setFont(font);

        verticalLayout_2->addWidget(widget_4);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 3);
        verticalLayout_2->setStretch(2, 10);

        gridLayout->addWidget(widget_2, 0, 0, 1, 1);


        retranslateUi(Query);
        QObject::connect(toolButton_2, SIGNAL(clicked()), Query, SLOT(showMinimized()));

        QMetaObject::connectSlotsByName(Query);
    } // setupUi

    void retranslateUi(QWidget *Query)
    {
        Query->setWindowTitle(QApplication::translate("Query", "\346\237\245\346\211\276", nullptr));
        toolButton->setText(QApplication::translate("Query", "...", nullptr));
        label->setText(QApplication::translate("Query", "\346\237\245\346\211\276", nullptr));
        toolButton_2->setText(QApplication::translate("Query", "...", nullptr));
        toolButton_4->setText(QApplication::translate("Query", "...", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("Query", "\344\270\215\351\231\220", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("Query", "12-16", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("Query", "17-21", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("Query", "22-30", nullptr));

        lineEdit->setPlaceholderText(QApplication::translate("Query", "\350\276\223\345\205\245Fdog\346\237\245\346\211\276", nullptr));
        comboBox->setItemText(0, QApplication::translate("Query", "\344\270\215\351\231\220", nullptr));
        comboBox->setItemText(1, QApplication::translate("Query", "\347\224\267", nullptr));
        comboBox->setItemText(2, QApplication::translate("Query", "\345\245\263", nullptr));

        lineEdit_3->setPlaceholderText(QApplication::translate("Query", "\346\225\205\344\271\241\357\274\232\346\261\237\350\213\217", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("Query", "\344\270\255\345\233\275-\346\261\237\350\213\217-\346\263\260\345\267\236", nullptr));
        pushButton->setText(QApplication::translate("Query", "\346\237\245\346\211\276", nullptr));
        checkBox->setText(QApplication::translate("Query", "\345\234\250\347\272\277", nullptr));
        pushButton_3->setText(QApplication::translate("Query", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        pushButton_4->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Query: public Ui_Query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERY_H
