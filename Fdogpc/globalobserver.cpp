#include "globalobserver.h"
#include<QDebug>
#include<QPainter>
#include<QBitmap>
MainWindow * Globalobserver::mainwindowp =NULL;
Addfriend *  Globalobserver::addfriendp =NULL;
Agreefriend * Globalobserver::agreefriend=NULL;
QList<Chat *> Globalobserver::listchat;
QFont Globalobserver::font1;
QFont Globalobserver::font2;
 MainWindow *Globalobserver::getMainwindowp()
{
    return mainwindowp;
}

 void Globalobserver::setMainwindowp(MainWindow *value)
{
    mainwindowp = value;
}

 Addfriend *Globalobserver::getAddfriendp()
{
    return addfriendp;
}

 void Globalobserver::setAddfriendp(Addfriend *value)
{
    addfriendp = value;
}

 Agreefriend *Globalobserver::getAgreefriend()
 {
     return agreefriend;
 }

 void Globalobserver::setAgreefriend(Agreefriend *value)
 {
     agreefriend = value;
 }

 QList<Chat *> Globalobserver::getListchat()
 {
     return listchat;
 }

 void Globalobserver::setListchat(const QList<Chat *> &value)
 {
     listchat = value;
 }

 Globalobserver::Globalobserver()
 {
     font1.setFamily("Microsoft YaHei");
     font1.setPointSize(8);
     font1.setStyleStrategy(QFont::PreferAntialias);
     font2.setFamily("Microsoft YaHei");
     font2.setPointSize(9);
     font2.setStyleStrategy(QFont::PreferAntialias);
 }

 void Globalobserver::installPersonInfo(MainWindow *p)
 {
     mainwindowp = p;
 }

 void Globalobserver::installPersonInfo(Addfriend *p)
{
     addfriendp = p;
 }

 QPixmap Globalobserver::PixmapToRound(const QPixmap &src, const int &radius)
 {
     if (src.isNull()) {
         return QPixmap();
     }
     QSize size(2*radius, 2*radius);
     //掩码图（黑白色）
     QBitmap mask(size);
     QPainter painter(&mask);
     //Antialiasing：反走样（抗锯齿）
     painter.setRenderHint(QPainter::Antialiasing);
     //SmoothPixmapTransform：用来在对图片进行缩放时启用线性插值算法而不是最邻近算法
     painter.setRenderHint(QPainter::SmoothPixmapTransform);
     //填充矩形
     painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
     //画刷
     painter.setBrush(QColor(0, 0, 0));
     //绘制圆角矩形
     painter.drawRoundedRect(0, 0, size.width(), size.height(), 190, 190);
     //自适应图片
     QPixmap image = src.scaled(size);
     //setMask：创建不规则窗口使用
     image.setMask(mask);
     return image;
 }

