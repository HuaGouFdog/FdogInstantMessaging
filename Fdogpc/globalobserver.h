#ifndef GLOBALOBSERVER_H
#define GLOBALOBSERVER_H
class MainWindow;
class Addfriend;
class Agreefriend;
class Chat;
#include"mainwindow.h"
#include"addfriend.h"
#include"agreefriend.h"
#include"chat.h"
class Globalobserver
{
private:
    static MainWindow * mainwindowp;
    static Addfriend * addfriendp;
    static Agreefriend * agreefriend;
    static QList<Chat *> listchat;

public:
    Globalobserver();
    static void installPersonInfo(MainWindow *p);
    static void installPersonInfo(Addfriend *p);
    static void installPersonInfo(Agreefriend *p);
    static MainWindow *getMainwindowp();
    static void setMainwindowp(MainWindow *value);
    static Addfriend *getAddfriendp();
    static void setAddfriendp(Addfriend *value);
    static Agreefriend *getAgreefriend();
    static void setAgreefriend(Agreefriend *value);
    static QList<Chat *> getListchat();
    static void setListchat(const QList<Chat *> &value);
    static QPixmap PixmapToRound(QPixmap &src, int radius);
};

#endif // GLOBALOBSERVER_H
