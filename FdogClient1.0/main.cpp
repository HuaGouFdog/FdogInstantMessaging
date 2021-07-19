#include "mainwindow.h"
#include <QApplication>
#include"login.h"
#include"globalobserver.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login n;
    n.show();
    return a.exec();
}
