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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settingcolor
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Settingcolor)
    {
        if (Settingcolor->objectName().isEmpty())
            Settingcolor->setObjectName(QStringLiteral("Settingcolor"));
        Settingcolor->resize(493, 315);
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
    } // retranslateUi

};

namespace Ui {
    class Settingcolor: public Ui_Settingcolor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGCOLOR_H
