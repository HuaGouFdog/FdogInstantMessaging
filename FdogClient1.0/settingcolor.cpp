#include "settingcolor.h"
#include "ui_settingcolor.h"

Settingcolor::Settingcolor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settingcolor)
{
    ui->setupUi(this);
}

Settingcolor::~Settingcolor()
{
    delete ui;
}
