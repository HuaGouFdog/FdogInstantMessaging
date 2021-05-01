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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Query
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_2;
    QToolButton *toolButton_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QFrame *line;
    QWidget *widget;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Query)
    {
        if (Query->objectName().isEmpty())
            Query->setObjectName(QStringLiteral("Query"));
        Query->resize(715, 544);
        QIcon icon;
        icon.addFile(QStringLiteral(":/lib/fdogicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Query->setWindowIcon(icon);
        Query->setStyleSheet(QLatin1String("#Query{\n"
"background-color: rgb(142, 231, 255);\n"
"}"));
        verticalLayout = new QVBoxLayout(Query);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        toolButton = new QToolButton(Query);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setIcon(icon);
        toolButton->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton);

        label = new QLabel(Query);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        toolButton_2 = new QToolButton(Query);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/lib/zuixiaohua.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton_2);

        toolButton_4 = new QToolButton(Query);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/lib/guanbi.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon2);
        toolButton_4->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton_4);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(Query);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setPointSize(11);
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);

        checkBox = new QCheckBox(Query);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setPointSize(13);
        checkBox->setFont(font1);

        horizontalLayout->addWidget(checkBox);

        pushButton = new QPushButton(Query);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_2 = new QLineEdit(Query);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 30));
        lineEdit_2->setFont(font);

        horizontalLayout_2->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(Query);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(0, 30));
        lineEdit_3->setFont(font);

        horizontalLayout_2->addWidget(lineEdit_3);

        comboBox = new QComboBox(Query);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(70, 30));

        horizontalLayout_2->addWidget(comboBox);

        comboBox_2 = new QComboBox(Query);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(70, 30));

        horizontalLayout_2->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(Query);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        widget = new QWidget(Query);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 442));
        widget->setStyleSheet(QLatin1String("#widget{\n"
"background-color: rgb(160, 255, 200);\n"
"}"));
        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(80, 10, 131, 31));
        QFont font2;
        font2.setPointSize(12);
        lineEdit_4->setFont(font2);
        lineEdit_4->setReadOnly(true);
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(80, 50, 81, 21));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 10, 51, 51));
        pushButton_4->setStyleSheet(QStringLiteral("border-radius:25px;"));
        pushButton_4->setIconSize(QSize(50, 50));

        verticalLayout->addWidget(widget);


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
        lineEdit->setPlaceholderText(QApplication::translate("Query", "\350\276\223\345\205\245Fdog\346\237\245\346\211\276", nullptr));
        checkBox->setText(QApplication::translate("Query", "\345\234\250\347\272\277", nullptr));
        pushButton->setText(QApplication::translate("Query", "\346\237\245\346\211\276", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("Query", "\344\270\255\345\233\275-\346\261\237\350\213\217-\346\263\260\345\267\236", nullptr));
        lineEdit_3->setPlaceholderText(QApplication::translate("Query", "\346\225\205\344\271\241\357\274\232\346\261\237\350\213\217", nullptr));
        comboBox->setItemText(0, QApplication::translate("Query", "\344\270\215\351\231\220", nullptr));
        comboBox->setItemText(1, QApplication::translate("Query", "\347\224\267", nullptr));
        comboBox->setItemText(2, QApplication::translate("Query", "\345\245\263", nullptr));

        comboBox_2->setItemText(0, QApplication::translate("Query", "\344\270\215\351\231\220", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("Query", "12-16", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("Query", "17-21", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("Query", "22-30", nullptr));

        pushButton_3->setText(QApplication::translate("Query", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Query: public Ui_Query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERY_H
