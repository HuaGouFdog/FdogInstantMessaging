#include "mainwindow.h"
#include <QApplication>
#include"login.h"
#include"globalobserver.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    Login n;
    n.setAttribute(Qt::WA_DeleteOnClose);
    n.show();
    return a.exec();
}
