/********************************************************************************
** Form generated from reading UI file 'verify.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFY_H
#define UI_VERIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Verify
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QWidget *widget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QWidget *tab_2;

    void setupUi(QWidget *Verify)
    {
        if (Verify->objectName().isEmpty())
            Verify->setObjectName(QStringLiteral("Verify"));
        Verify->resize(575, 447);
        Verify->setStyleSheet(QLatin1String("*{font-family:Microsoft YaHei;}\n"
"#Verify{\n"
"background-color: rgb(116, 195, 255);\n"
"}"));
        verticalLayout = new QVBoxLayout(Verify);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Verify);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(15, 15));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("border-image: url(:/lib/yinshenim.png);"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(Verify);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        toolButton = new QToolButton(Verify);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/zuixiaohua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(Verify);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);


        verticalLayout->addLayout(horizontalLayout);

        widget = new QWidget(Verify);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 417));
        widget->setFont(font);
        widget->setStyleSheet(QStringLiteral("background-color: rgb(179, 255, 250);"));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 551, 401));
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 10, 54, 12));
        label_3->setFont(font);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(110, 32, 54, 20));
        label_5->setFont(font);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(110, 60, 54, 16));
        label_6->setFont(font);
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(110, 80, 54, 21));
        label_7->setFont(font);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 70, 91, 31));
        pushButton->setFont(font);
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 40, 61, 61));
        pushButton_3->setFont(font);
        pushButton_3->setIconSize(QSize(55, 55));
        pushButton_3->setAutoDefault(false);
        pushButton_3->setFlat(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(widget);


        retranslateUi(Verify);

        tabWidget->setCurrentIndex(0);
        pushButton_3->setDefault(false);


        QMetaObject::connectSlotsByName(Verify);
    } // setupUi

    void retranslateUi(QWidget *Verify)
    {
        Verify->setWindowTitle(QApplication::translate("Verify", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("Verify", "\351\252\214\350\257\201\344\277\241\346\201\257", nullptr));
        toolButton->setText(QApplication::translate("Verify", "...", nullptr));
        toolButton_2->setText(QApplication::translate("Verify", "...", nullptr));
        label_3->setText(QApplication::translate("Verify", "4\346\234\21028\346\227\245", nullptr));
        label_5->setText(QApplication::translate("Verify", "4\346\234\21028\346\227\245", nullptr));
        label_6->setText(QApplication::translate("Verify", "4\346\234\21028\346\227\245", nullptr));
        label_7->setText(QApplication::translate("Verify", "4\346\234\21028\346\227\245", nullptr));
        pushButton->setText(QApplication::translate("Verify", "\346\267\273\345\212\240/\346\213\222\347\273\235", nullptr));
        pushButton_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Verify", "\345\245\275\345\217\213\351\252\214\350\257\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Verify", "\347\276\244\351\252\214\350\257\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Verify: public Ui_Verify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFY_H
