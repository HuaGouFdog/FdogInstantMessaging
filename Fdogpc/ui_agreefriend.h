/********************************************************************************
** Form generated from reading UI file 'agreefriend.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGREEFRIEND_H
#define UI_AGREEFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Agreefriend
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Agreefriend)
    {
        if (Agreefriend->objectName().isEmpty())
            Agreefriend->setObjectName(QStringLiteral("Agreefriend"));
        Agreefriend->resize(322, 183);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setStyleStrategy(QFont::PreferAntialias);
        Agreefriend->setFont(font);
        Agreefriend->setStyleSheet(QStringLiteral("*{font-family:Microsoft YaHei;}"));
        label = new QLabel(Agreefriend);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 61, 31));
        label->setFont(font);
        label_2 = new QLabel(Agreefriend);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 60, 61, 31));
        label_2->setFont(font);
        comboBox = new QComboBox(Agreefriend);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(100, 60, 151, 31));
        comboBox->setFont(font);
        lineEdit = new QLineEdit(Agreefriend);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 20, 151, 31));
        lineEdit->setFont(font);
        pushButton = new QPushButton(Agreefriend);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 120, 91, 31));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(Agreefriend);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 120, 91, 31));
        pushButton_2->setFont(font);

        retranslateUi(Agreefriend);

        QMetaObject::connectSlotsByName(Agreefriend);
    } // setupUi

    void retranslateUi(QWidget *Agreefriend)
    {
        Agreefriend->setWindowTitle(QApplication::translate("Agreefriend", "Form", nullptr));
        label->setText(QApplication::translate("Agreefriend", "\345\244\207\346\263\250\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Agreefriend", "\345\210\206\347\273\204\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("Agreefriend", "\345\220\214\346\204\217", nullptr));
        pushButton_2->setText(QApplication::translate("Agreefriend", "\346\213\222\347\273\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Agreefriend: public Ui_Agreefriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGREEFRIEND_H
