/********************************************************************************
** Form generated from reading UI file 'settingcolor.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGCOLOR_H
#define UI_SETTINGCOLOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settingcolor
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QPushButton *pushButton;
    QWidget *widget;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Settingcolor)
    {
        if (Settingcolor->objectName().isEmpty())
            Settingcolor->setObjectName(QStringLiteral("Settingcolor"));
        Settingcolor->resize(794, 472);
        tabWidget = new QTabWidget(Settingcolor);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 371, 271));
        tabWidget->setStyleSheet(QLatin1String("#tab,#tab_2{\n"
"border-image: url(:/lib/10001.jpg);\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 60, 75, 23));
        tabWidget->addTab(tab_2, QString());
        widget = new QWidget(Settingcolor);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(420, 110, 241, 181));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 123, 249);"));
        label = new QLabel(Settingcolor);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 330, 141, 51));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("background-color: rgb(175, 148, 255);"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label->setWordWrap(false);
        horizontalLayoutWidget = new QWidget(Settingcolor);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(270, 370, 401, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(label_2);

        textEdit = new QTextEdit(horizontalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout->addWidget(textEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(Settingcolor);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Settingcolor);
    } // setupUi

    void retranslateUi(QWidget *Settingcolor)
    {
        Settingcolor->setWindowTitle(QApplication::translate("Settingcolor", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Settingcolor", "Tab 1", nullptr));
        pushButton->setText(QApplication::translate("Settingcolor", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Settingcolor", "Tab 2", nullptr));
        label->setText(QApplication::translate("Settingcolor", "\344\275\240\345\223\210", nullptr));
        pushButton_2->setText(QApplication::translate("Settingcolor", "PushButton", nullptr));
        label_2->setText(QApplication::translate("Settingcolor", "3213123333", nullptr));
        textEdit->setHtml(QApplication::translate("Settingcolor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\275\240\345\245\275</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settingcolor: public Ui_Settingcolor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGCOLOR_H
