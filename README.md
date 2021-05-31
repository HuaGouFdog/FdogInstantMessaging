---
typora-root-url: READMEimg
---

# FdogInstantMessaging

#### 介绍
FdogInstantMessaging，Fdog即时通讯软件。

利用在校所学知识进行编写，主要包括网页端，客户端，以及服务端。

网页端主要使用html，jsp，javaweb，使用Tomcat部署在腾讯云服务器上面：[注册网址](https://www.fdogcsdn.cn/FdogMaven/index.jsp) ，并使用腾讯云的短信接口进行短信注册，由于一个月体验已到期，现在无法正常发送短信。

客户端和服务端是在win10平台使用qt5.10进行编写。

由于无法将服务器数据库密码等重要信息上传，所以下载下来的程序无法正常运行，这里只提供源码以及数据库的字段。

欢迎大家下载学习，走前给个星星！

我的博客：https://blog.csdn.net/Fdog_



#### 图例

##### 1.登录界面

##### ![](https://img-blog.csdnimg.cn/20210528152616336.png)



##### 2.主界面



![](https://img-blog.csdnimg.cn/20210528152616300.png)



##### 3.聊天窗口

<img src="https://img-blog.csdnimg.cn/20210528152616304.png" style="zoom:80%;" />



##### 4.查找

<img src="https://img-blog.csdnimg.cn/20210528152616288.png" style="zoom:67%;" />



##### 6.添加好友

![](https://img-blog.csdnimg.cn/20210528152616214.png)



##### 7.右下角托盘图标

![](https://img-blog.csdnimg.cn/20210528152616283.png)







---

#### 技术讲解

Fdog系列已写目录：

[Fdog系列（一）：思来想去，不如写一个聊天软件，那就从仿QQ注册页面开始吧。](https://zxfdog.blog.csdn.net/article/details/115558479)

[Fdog系列（二）：html写完注册页面之后怎么办，用java写后台响应呀。](https://zxfdog.blog.csdn.net/article/details/115601897)

[Fdog系列（三）：使用腾讯云短信接口发送短信，数据库写入，部署到服务器，web收尾篇。](https://zxfdog.blog.csdn.net/article/details/115659789)

[Fdog系列（四）：使用Qt框架模仿QQ实现登录界面，界面篇。](https://blog.csdn.net/Fdog_/article/details/115864249)

[Fdog系列（五）：使用Qt模仿QQ实现登录界面到主界面，功能篇](https://zxfdog.blog.csdn.net/article/details/116308548)

[Fdog系列（六）：利用Qt通过服务端进行客户端与客户端通信（资料少，建议收藏）](https://zxfdog.blog.csdn.net/article/details/116355817)



数据库的一些字段可能需要：

![](https://img-blog.csdnimg.cn/20210528153827550.png)



![](https://img-blog.csdnimg.cn/2021052815390824.png)

![](https://img-blog.csdnimg.cn/20210528153459534.png)



![](https://img-blog.csdnimg.cn/20210528153459539.png)



![](https://img-blog.csdnimg.cn/20210528153459542.png)

---

#### 使用环境

网页端
1.  tomcat7.x
2.  mysql7.x
3.  centOS7.x

PC端
1.  win10，qt5.10


服务端
1.  win10，qt5.10

---

#### 使用说明

1.  将网页端部署完毕，可完成Fdog账号注册功能
2.  打开服务端，自动接收TCP请求 默认60端口
3.  登录两个客户端，可互发信息



备注：只上传了源码，并没有上传可执行文件（太大了，github又慢），如下载源码后无法编译，右击项目，重新构建即可。



---

#### 更新目录

##### 2021.5.1 更新
    1. 完成基本的登录，客户端与客户端的通信
    备注：目前还无法实现好友添加



##### 2021.5.28 更新

```
1. 修复了服务端由客户端关闭顺序引起的崩溃
2. 优化服务端界面ui
3. 优化主界面ui
4. 实现主界面登录状态切换和系统托盘登录状态切换
5. 实现来消息时的头像闪动
6. 实现右下角消息列表
7. 主界面列表消息显示
```



##### 2021.5.29 更新

```
1. 修复一个好友多次发送消息导致打开多个窗口
2. 优化好友列表样式
3. 优化好友聊天窗口ui以及内容显示
4. 实现任务栏显示聊天对象头像
```



##### 2021.5.30更新

```
1. 优化登录界面动态图，以及登录界面头像锯齿化问题
2. 优化全局字体反锯齿，优化后字体平滑
3. 优化分组按钮箭头展开闭合效果以及消息列表
4. 优化右下角消息框ui
```



---

#### 其他

微信交流群：

![image](https://user-images.githubusercontent.com/59921436/116808595-3f322280-ab6c-11eb-84d3-055fa639930d.png)


