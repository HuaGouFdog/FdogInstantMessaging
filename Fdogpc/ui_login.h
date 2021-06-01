/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QLabel *mian_label;
    QLabel *label_2;
    QPushButton *register_btn;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QToolButton *toolButton_3;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_4;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QPushButton *pushButton_3;
    QToolButton *toolButton_5;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(446, 342);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(10);
        font.setStyleStrategy(QFont::PreferAntialias);
        Login->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/fdogicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QLatin1String("*{font-family:Microsoft YaHei;}\n"
"\n"
"#Login{\n"
"background-color: rgb(84, 62, 255);\n"
"}"));
        gridLayout = new QGridLayout(Login);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 2, 0, 0);
        widget = new QWidget(Login);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(431, 304));
        widget->setMaximumSize(QSize(425, 330));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei"));
        font1.setStyleStrategy(QFont::PreferAntialias);
        widget->setFont(font1);
        widget->setStyleSheet(QLatin1String("#widet{\n"
"border-radius: 10px;\n"
"border-style:solid;\n"
"background-color: rgba(255, 255, 255, 0);\n"
"}"));
        mian_label = new QLabel(widget);
        mian_label->setObjectName(QStringLiteral("mian_label"));
        mian_label->setGeometry(QRect(0, 0, 431, 131));
        mian_label->setFont(font1);
        mian_label->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"border-top-left-radius:10px;\n"
"border-top-right-radius:10px;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 129, 431, 200));
        label_2->setMinimumSize(QSize(431, 200));
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
""));
        register_btn = new QPushButton(widget);
        register_btn->setObjectName(QStringLiteral("register_btn"));
        register_btn->setGeometry(QRect(10, 299, 71, 21));
        register_btn->setFont(font1);
        register_btn->setStyleSheet(QLatin1String("#register_btn{\n"
"color: rgb(149, 149, 149);\n"
"}\n"
"#register_btn:hover{\n"
"color: rgb(120, 120, 120);\n"
"}"));
        register_btn->setAutoDefault(false);
        register_btn->setFlat(true);
        horizontalLayoutWidget_2 = new QWidget(widget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(110, 240, 227, 31));
        horizontalLayoutWidget_2->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(horizontalLayoutWidget_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(78, 25));
        checkBox->setFont(font1);
        checkBox->setStyleSheet(QLatin1String("#checkBox{\n"
"color: rgb(149, 149, 149);\n"
"}\n"
"#checkBox:hover{\n"
"color: rgb(120, 120, 120);\n"
"}"));

        horizontalLayout_2->addWidget(checkBox);

        checkBox_2 = new QCheckBox(horizontalLayoutWidget_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setMinimumSize(QSize(78, 25));
        checkBox_2->setFont(font1);
        checkBox_2->setStyleSheet(QLatin1String("#checkBox_2{\n"
"color: rgb(149, 149, 149);\n"
"}\n"
"#checkBox_2:hover{\n"
"color: rgb(120, 120, 120);\n"
"}"));

        horizontalLayout_2->addWidget(checkBox_2);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 0));
        pushButton_2->setMaximumSize(QSize(57, 20));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QLatin1String("#pushButton_2{\n"
"color: rgb(149, 149, 149);\n"
"}\n"
"#pushButton_2:hover{\n"
"color: rgb(120, 120, 120);\n"
"}"));
        pushButton_2->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_2);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 160, 221, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei"));
        comboBox->setFont(font2);
        comboBox->setStyleSheet(QLatin1String("QComboBox \n"
"{ \n"
"font-size:15px;\n"
"}\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"min-height: 50px; \n"
"min-width: 60px; \n"
"\n"
"}\n"
"::drop-down{\n"
"	border-style:solid;\n"
"	border-width:1px;\n"
"	width:20px ;\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-bottom-color: rgb(129, 129, 129);\n"
"}\n"
"::down-arrow{\n"
"border-image: url(:/lib/jietou1.png);\n"
"}"));
        comboBox->setEditable(true);
        comboBox->setMaxVisibleItems(10);
        comboBox->setInsertPolicy(QComboBox::NoInsert);
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);
        comboBox->setIconSize(QSize(10, 10));
        toolButton_3 = new QToolButton(widget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(229, 134, 16, 16));
        toolButton_3->setFont(font1);
        toolButton_3->setStyleSheet(QLatin1String("border-width:2px;\n"
"border-style:solid;\n"
"border-radius: 8px;\n"
"border-color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/zaixian.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon1);
        toolButton_3->setAutoRaise(true);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 79, 72, 72));
        label_5->setFont(font1);
        label_5->setStyleSheet(QLatin1String("\n"
"border-style:solid;\n"
"border-radius: 36px;\n"
"background-color: rgba(255, 255, 255,200);"));
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 160, 204, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft YaHei"));
        font3.setPointSize(12);
        font3.setStyleStrategy(QFont::PreferAntialias);
        lineEdit_2->setFont(font3);
        lineEdit_2->setStyleSheet(QLatin1String("border-style:solid;\n"
"border-width:1px;\n"
"border-top-color: rgba(255, 255, 255, 0);\n"
"border-right-color: rgba(255, 255, 255, 0);\n"
"border-left-color: rgba(255, 255, 255, 0);\n"
"border-bottom-color: rgb(129, 129, 129);\n"
"\n"
"\n"
""));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 200, 221, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Microsoft YaHei"));
        font4.setPointSize(14);
        font4.setStyleStrategy(QFont::PreferAntialias);
        lineEdit->setFont(font4);
        lineEdit->setStyleSheet(QLatin1String("border-style:solid;\n"
"border-width:1px;\n"
"border-top-color: rgba(255, 255, 255, 0);\n"
"border-right-color: rgba(255, 255, 255, 0);\n"
"border-left-color: rgba(255, 255, 255, 0);\n"
"border-bottom-color: rgb(129, 129, 129);"));
        lineEdit->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 277, 221, 37));
        QFont font5;
        font5.setFamily(QStringLiteral("Microsoft YaHei"));
        font5.setPointSize(13);
        font5.setBold(false);
        font5.setWeight(50);
        font5.setKerning(true);
        font5.setStyleStrategy(QFont::PreferAntialias);
        pushButton->setFont(font5);
        pushButton->setMouseTracking(false);
        pushButton->setTabletTracking(false);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setToolTipDuration(-1);
        pushButton->setStyleSheet(QLatin1String("#pushButton{\n"
"background-color: rgb(99, 188, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"}\n"
"#pushButton:hover{\n"
"background-color: rgb(99, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"\n"
"}\n"
"#pushButton:pressed{\n"
"background-color: rgb(99, 188, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 5px;\n"
"padding-left:2px;\n"
"padding-top:2px;\n"
"}\n"
""));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);
        horizontalLayoutWidget = new QWidget(widget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(4, 0, 421, 41));
        horizontalLayoutWidget->setFont(font1);
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_4 = new QToolButton(horizontalLayoutWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(83, 39));
        toolButton_4->setMaximumSize(QSize(83, 39));
        toolButton_4->setStyleSheet(QLatin1String("border-style:solid;\n"
"background-color: rgba(255, 255, 255, 0);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/mainicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon2);
        toolButton_4->setIconSize(QSize(80, 80));
        toolButton_4->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton = new QToolButton(horizontalLayoutWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(25, 25));
        toolButton->setMaximumSize(QSize(25, 25));
        toolButton->setSizeIncrement(QSize(25, 25));
        toolButton->setFont(font1);
        toolButton->setStyleSheet(QLatin1String("border-style:solid;\n"
"background-color: rgba(255, 255, 255, 0);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/lib/zuixiaohua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon3);
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(horizontalLayoutWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(25, 25));
        toolButton_2->setMaximumSize(QSize(25, 25));
        toolButton_2->setFont(font1);
        toolButton_2->setStyleSheet(QLatin1String("border-style:solid;\n"
"background-color: rgba(255, 255, 255, 0);"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/lib/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon4);
        toolButton_2->setIconSize(QSize(20, 20));
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(183, 82, 66, 66));
        pushButton_3->setStyleSheet(QLatin1String("border-image: url(:/lib/icon2505897252.png);\n"
"border-width:0px;\n"
"border-style:solid;\n"
"border-radius:32px;\n"
"border-color: rgb(255, 255, 255);"));
        toolButton_5 = new QToolButton(widget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(380, 290, 30, 30));
        toolButton_5->setStyleSheet(QLatin1String("border-style:solid;\n"
"background-color: rgba(255, 255, 255, 0);"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/lib/erweima.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon5);
        toolButton_5->setIconSize(QSize(30, 30));
        mian_label->raise();
        label_2->raise();
        register_btn->raise();
        horizontalLayoutWidget_2->raise();
        comboBox->raise();
        label_5->raise();
        lineEdit_2->raise();
        lineEdit->raise();
        pushButton->raise();
        horizontalLayoutWidget->raise();
        pushButton_3->raise();
        toolButton_3->raise();
        toolButton_5->raise();

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        QWidget::setTabOrder(comboBox, lineEdit);
        QWidget::setTabOrder(lineEdit, checkBox);
        QWidget::setTabOrder(checkBox, checkBox_2);
        QWidget::setTabOrder(checkBox_2, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton);
        QWidget::setTabOrder(pushButton, register_btn);
        QWidget::setTabOrder(register_btn, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, toolButton_3);
        QWidget::setTabOrder(toolButton_3, toolButton);
        QWidget::setTabOrder(toolButton, toolButton_2);

        retranslateUi(Login);

        register_btn->setDefault(false);
        pushButton_2->setDefault(false);
        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", nullptr));
        mian_label->setText(QString());
        label_2->setText(QString());
        register_btn->setText(QApplication::translate("Login", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        checkBox->setText(QApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        checkBox_2->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        pushButton_2->setText(QApplication::translate("Login", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        toolButton_3->setText(QApplication::translate("Login", "...", nullptr));
        label_5->setText(QString());
        lineEdit_2->setPlaceholderText(QApplication::translate("Login", "Fdog\345\217\267\347\240\201/\351\202\256\347\256\261/\346\211\213\346\234\272\345\217\267", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("Login", "\345\257\206\347\240\201", nullptr));
        pushButton->setText(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton->setShortcut(QApplication::translate("Login", "Return", nullptr));
#endif // QT_NO_SHORTCUT
        toolButton_4->setText(QApplication::translate("Login", "...", nullptr));
        toolButton->setText(QApplication::translate("Login", "...", nullptr));
        toolButton_2->setText(QApplication::translate("Login", "...", nullptr));
        pushButton_3->setText(QString());
        toolButton_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
