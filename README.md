[TOC]



[![Build Status](https://travis-ci.com/HuaGouFdog/FdogInstantMessaging.svg)](https://travis-ci.com/HuaGouFdog/FdogInstantMessaging)  [![Coverage Status](https://shields.io/badge/coverage-67%25-yellow)](https://coveralls.io/github/HuaGouFdog/FdogInstantMessaging?branch=main)  ![](https://img.shields.io/badge/QQ-2506897252-brightgreen)   ![](https://img.shields.io/badge/CSDN%E5%8D%9A%E5%AE%A2-%E8%8A%B1%E7%8B%97Fdog-brightgreen)   



# *新版本正在编写中，文档重写编写中，未来可期！*



# FdogInstantMessaging(Fdog即时通讯软件)

#### 一. 介绍
FdogInstantMessaging，Fdog即时通讯软件，利用在校所学知识进行编写，主要包括网页端，客户端，以及服务端。

1. 网页端主要使用html前端，java后端，使用Tomcat部署在腾讯云服务器上面，实习软件下载和账号注册等功能。
2. 客户端和服务端是在window平台使用qt5.10进行编写。



备注：

相关软件版本：tomcat7.x，mysql7.x，centOS7.x

fdogsql.sql文件为数据库对应字段及数据

短信使用的是腾讯云的短信服务，其他几家的短信服务都需要企业认证，腾讯云不需要。

每个新用户注册腾讯云都有两个个月短信体验，我的体验已到期，现在无法正常发送短信，不要再再试注册了。

由于无法将服务器数据库密码等重要信息上传，所以下载下来的程序无法正常运行，这里只提供源码以及相关数据库字段。

目前没有上传可执行文件（太大了，github又慢），如下载源码后无法编译，右击项目，重新构建即可。

欢迎大家参考学习，如果对你有帮助的话，别忘了给个星星！

Fdog网站：

https://www.fdogcsdn.cn

我的博客：

https://blog.csdn.net/Fdog_ 

下面是提供一些可能有用的技术参考：

[Fdog系列（一）：思来想去，不如写一个聊天软件，那就从仿QQ注册页面开始吧。](https://zxfdog.blog.csdn.net/article/details/115558479)

[Fdog系列（二）：html写完注册页面之后怎么办，用java写后台响应呀。](https://zxfdog.blog.csdn.net/article/details/115601897)

[Fdog系列（三）：使用腾讯云短信接口发送短信，数据库写入，部署到服务器，web收尾篇。](https://zxfdog.blog.csdn.net/article/details/115659789)

[Fdog系列（四）：使用Qt框架模仿QQ实现登录界面，界面篇。](https://blog.csdn.net/Fdog_/article/details/115864249)

[Fdog系列（五）：使用Qt模仿QQ实现登录界面到主界面，功能篇](https://zxfdog.blog.csdn.net/article/details/116308548)

[Fdog系列（六）：利用Qt通过服务端进行客户端与客户端通信（资料少，建议收藏）](https://zxfdog.blog.csdn.net/article/details/116355817)

[Centos上编译qt程序缺少mysql驱动解决方案](https://zxfdog.blog.csdn.net/article/details/117637402)

[腾讯云云服务器Centos系统安装MySQL数据库详细教程](https://zxfdog.blog.csdn.net/article/details/113573491)

[初学Qt不会样式表怎么办，打包好的Qt样式表一键生成送给你](https://zxfdog.blog.csdn.net/article/details/108296647)



---

#### 二. 图例

##### 1.登录界面

<img src="https://img-blog.csdnimg.cn/20210609112805866.png" style="zoom: 50%;" />

##### 2.主界面以及聊天窗口

<img src="https://img-blog.csdnimg.cn/20210609112805707.png" style="zoom:50%;" />

##### 3.查找以及添加好友界面

<img src="https://img-blog.csdnimg.cn/20210609112805629.png" style="zoom:50%;" />

##### 4.数据库字段

<img src="https://img-blog.csdnimg.cn/20210609112805635.png" style="zoom:50%;" />



---

#### 三. V1.0更新目录

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



##### 2021.6.1更新

```
1. 实现好友添加，并自动更新好友列表
2. 优化搜索好友界面ui
```





##### 2021.6.4更新

```
1. 优化Usersql类的代码，采用单例设计模式
2. 优化部分函数更新写法，增加安全性，以及服务端功能优化
3. 增加对当前用户登录状态的写入，包括在线，隐身，离开，勿扰，等等(后期将会在好友列表中显示列表好友状态)
4. 增加了登录界面登录时的取消按钮，以及当密码错误时，显示密码错误界面，优化用户体验
5. 修复无论是否连接服务器都可以登录到主机面，增加对服务器是否能连接的判断，以及当前网络环境的判断，同时增加界面显示
6. 修复了之前点击关闭按钮，但是依旧无法调用析构函数导致后台存在进程，无法再次编译的问题
```



##### 2021.6.8更新

```
1. 优化对话ui，增加聊天气泡
2. 优化列表颜色显示
```



##### 2021.6.9更新

```
1. 修复了当前聊天窗口显示在桌面，托盘头像依旧闪烁的BUG
2. 增加了当前聊天窗口为非活动窗口时，来消息时的任务栏图标的闪烁
3. 修复了发送消息导致信息列表重复出现好友以及发送方不显示消息列表的问题
4. 修复了无限登陆的问题，规定同一账号在不同IP下可以互相挤掉对方，而在同一IP下只可以登录一个，并弹出提示框
5. 修复了点击同一好友，无限弹出聊天窗口的问题
```





##### 2021.6.11更新

```
1. 修复了关闭登录窗口但是后台进程还存在的问题
2. 修复了修改代码产生的诸多问题，优化整体流畅性
```



##### 2021.6.13更新

```
1. 优化聊天窗口逻辑
2. 修复关闭主窗口导致程序异常结束的问题
```



##### 2021.6.15更新

```
1. 修复并完善某些功能，v1.0版完成。
```



#### FdogWeb2.0更新

##### 2021.7.18更新



```
1. 重写前端相关html，将之前jsp改写为html
```



##### 2021.7.19更新

```
1. 前端html大致完成，后端go接口大致完成，完成基本注册。
```

















---

#### 其他

微信交流群：

![image](https://user-images.githubusercontent.com/59921436/116808595-3f322280-ab6c-11eb-84d3-055fa639930d.png)


