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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Query
{
public:
    QFrame *line;
    QWidget *widget;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QComboBox *comboBox_2;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_2;
    QToolButton *toolButton_4;

    void setupUi(QWidget *Query)
    {
        if (Query->objectName().isEmpty())
            Query->setObjectName(QStringLiteral("Query"));
        Query->resize(898, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/fdogicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Query->setWindowIcon(icon);
        Query->setStyleSheet(QLatin1String("*{font-family:Microsoft YaHei;}\n"
"#Query{\n"
"background-color: rgb(193, 255, 183);\n"
"}"));
        line = new QFrame(Query);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 179, 901, 21));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setStyleStrategy(QFont::PreferAntialias);
        line->setFont(font);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(Query);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 199, 881, 391));
        widget->setMinimumSize(QSize(0, 300));
        widget->setFont(font);
        widget->setStyleSheet(QLatin1String("#widget{\n"
"background-color: rgb(160, 255, 200);\n"
"}"));
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(80, 20, 131, 31));
        lineEdit_4->setFont(font);
        lineEdit_4->setReadOnly(true);
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(80, 60, 81, 21));
        pushButton_3->setFont(font);
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 20, 51, 51));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QStringLiteral("border-radius:25px;"));
        pushButton_4->setIconSize(QSize(50, 50));
        pushButton = new QPushButton(Query);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(600, 110, 121, 41));
        pushButton->setMinimumSize(QSize(90, 30));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("background-color: rgb(111, 188, 255);\n"
"border-style:solid;\n"
"color: rgb(255, 255, 255);\n"
"border-radius:5px;"));
        label_2 = new QLabel(Query);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-10, 70, 911, 531));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_2 = new QLineEdit(Query);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 130, 150, 30));
        lineEdit_2->setMinimumSize(QSize(0, 30));
        lineEdit_2->setMaximumSize(QSize(150, 16777215));
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QLatin1String("border-color: rgb(110, 149, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;"));
        lineEdit_3 = new QLineEdit(Query);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(178, 130, 150, 30));
        lineEdit_3->setMinimumSize(QSize(0, 30));
        lineEdit_3->setMaximumSize(QSize(150, 16777215));
        lineEdit_3->setFont(font);
        lineEdit_3->setStyleSheet(QLatin1String("border-color: rgb(110, 149, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;"));
        comboBox_2 = new QComboBox(Query);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(424, 130, 80, 30));
        comboBox_2->setMinimumSize(QSize(70, 30));
        comboBox_2->setMaximumSize(QSize(80, 16777215));
        comboBox_2->setFont(font);
        comboBox_2->setStyleSheet(QLatin1String("border-color: rgb(110, 149, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;"));
        comboBox = new QComboBox(Query);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(336, 130, 80, 30));
        comboBox->setMinimumSize(QSize(70, 30));
        comboBox->setMaximumSize(QSize(80, 16777215));
        comboBox->setFont(font);
        comboBox->setStyleSheet(QLatin1String("border-color: rgb(110, 149, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;"));
        checkBox = new QCheckBox(Query);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(526, 90, 57, 30));
        checkBox->setMinimumSize(QSize(0, 30));
        checkBox->setFont(font);
        checkBox->setStyleSheet(QStringLiteral(""));
        lineEdit = new QLineEdit(Query);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(16, 90, 489, 30));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(489, 16777215));
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QLatin1String("border-color: rgb(110, 149, 255);\n"
"border-style:solid;\n"
"border-width:1px;\n"
"border-radius:5px;"));
        layoutWidget = new QWidget(Query);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 5, 881, 28));
        layoutWidget->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(layoutWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setFont(font);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        toolButton_2 = new QToolButton(layoutWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/zuixiaohua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton_2);

        toolButton_4 = new QToolButton(layoutWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon2);
        toolButton_4->setIconSize(QSize(20, 20));
        toolButton_4->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton_4);

        layoutWidget->raise();
        label_2->raise();
        line->raise();
        widget->raise();
        pushButton->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        comboBox_2->raise();
        comboBox->raise();
        checkBox->raise();
        lineEdit->raise();

        retranslateUi(Query);
        QObject::connect(toolButton_2, SIGNAL(clicked()), Query, SLOT(showMinimized()));

        QMetaObject::connectSlotsByName(Query);
    } // setupUi

    void retranslateUi(QWidget *Query)
    {
        Query->setWindowTitle(QApplication::translate("Query", "\346\237\245\346\211\276", nullptr));
        pushButton_3->setText(QApplication::translate("Query", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        pushButton_4->setText(QString());
        pushButton->setText(QApplication::translate("Query", "\346\237\245\346\211\276", nullptr));
        label_2->setText(QString());
        lineEdit_2->setPlaceholderText(QApplication::translate("Query", "\344\270\255\345\233\275-\346\261\237\350\213\217-\346\263\260\345\267\236", nullptr));
        lineEdit_3->setPlaceholderText(QApplication::translate("Query", "\346\225\205\344\271\241\357\274\232\346\261\237\350\213\217", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("Query", "\344\270\215\351\231\220", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("Query", "12-16", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("Query", "17-21", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("Query", "22-30", nullptr));

        comboBox->setItemText(0, QApplication::translate("Query", "\344\270\215\351\231\220", nullptr));
        comboBox->setItemText(1, QApplication::translate("Query", "\347\224\267", nullptr));
        comboBox->setItemText(2, QApplication::translate("Query", "\345\245\263", nullptr));

        checkBox->setText(QApplication::translate("Query", "\345\234\250\347\272\277", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("Query", "\350\276\223\345\205\245Fdog\346\237\245\346\211\276", nullptr));
        toolButton->setText(QApplication::translate("Query", "...", nullptr));
        label->setText(QApplication::translate("Query", "\346\237\245\346\211\276", nullptr));
        toolButton_2->setText(QApplication::translate("Query", "...", nullptr));
        toolButton_4->setText(QApplication::translate("Query", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Query: public Ui_Query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERY_H
