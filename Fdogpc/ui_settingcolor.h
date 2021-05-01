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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settingcolor
{
public:

    void setupUi(QWidget *Settingcolor)
    {
        if (Settingcolor->objectName().isEmpty())
            Settingcolor->setObjectName(QStringLiteral("Settingcolor"));
        Settingcolor->resize(400, 300);

        retranslateUi(Settingcolor);

        QMetaObject::connectSlotsByName(Settingcolor);
    } // setupUi

    void retranslateUi(QWidget *Settingcolor)
    {
        Settingcolor->setWindowTitle(QApplication::translate("Settingcolor", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settingcolor: public Ui_Settingcolor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGCOLOR_H
