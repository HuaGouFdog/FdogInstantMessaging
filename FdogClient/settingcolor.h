#ifndef SETTINGCOLOR_H
#define SETTINGCOLOR_H

#include <QWidget>

namespace Ui {
class Settingcolor;
}

class Settingcolor : public QWidget
{
    Q_OBJECT

public:
    explicit Settingcolor(QWidget *parent = 0);
    ~Settingcolor();

private:
    Ui::Settingcolor *ui;
};

#endif // SETTINGCOLOR_H
