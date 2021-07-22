#Fdog即时通讯软件web端搭建部署说明

##	一.	短信接口提供商为腾讯云(其他服务商个人无法申请，并且腾讯云第一次免费提供100条，对应个人实验是管够)

	登录腾讯云官网：https://cloud.tencent.com/
	
	搜索栏搜索短信，会看到免费领取短信字样
	
	进入短信管理页面，左边菜单栏选择国内短信
	
	签名管理：选择创建模板，选择自用，网站，签名内容(短信标题，配置文件参数之一)，申请说明（就写体验腾讯云短信服务）
	
	正文模板管理：模板类型，普通短信，使用标准模板(自己写也可以)，申请说明同上，成功之后的会显示模板ID(短信标题，配置文件参数之一)
	
	点击左边菜单栏选择应用管理下的应用列表，创建应用（名字自便），之后会得到一个SDKAppID（配置文件参数之一）
	
	搜索栏搜索访问管理，进入点击左边菜单栏选择访问密钥，选择API访问密钥管理，会得到SecretId（配置文件参数之一）以及SecretKey（配置文件参数之一）
	
## 	二.	Mysql数据库

	数据库使用MySql5.7版本
	
	创建数据库省略，(数据库名字不作要求，配置文件参数之一）.....
	
	创建表tb_phonecode(表的名字不作要求，配置文件参数之一)，字段为三个，分别是phone，code，time (不可自定义，若要自定义，请对应修改代码)

	mysql> create table tb_phonecode
    	-> (
    	-> phone VARCHAR(13),
    	-> code VARCHAR(7),
    	-> time VarCHAR(15)
    	-> );

##	三.	前端采用html+js,抛弃了1.0采用的jsp，前后端分离，直接调用后台接口

	css文件在css文件夹，js文件在js文件夹，图片资源在img文件夹中
	
	ChangeBackground.js负责注册界面文本框，按钮等行为
	
	BehaviorCheck.js负责注册，注册成功，账号找回界面左侧动态图
	
	index.html		网站主页面  	使用indexcss.css
	
	register.html	账号注册页面	使用registercss.css，ChangeBackground.js，BehaviorCheck.js
	
	registers.html	账号注册成功页面	使用registersuccesscss.css
	
	retaccount.html	账号找回页面
	
	document.html	文档页面


##  四.	后端尝试采用golang语言重写，来替代1.0java+tomcat带来的繁琐部署以及运行

	计算机系统：ubuntu16.04

	golang版本：1.16.5
	
	使用gin框架，没有使用go path，改用go mod来更好的管理包。
	
	安装golang
	
	使用代理
	
	export GOPROXY=https://goproxy.io,direct
	
	export GO111MODULE=on
	
	安装gin
	
	使用go mod（golang版本需达到1.11或以上）
	
	包含main.go   router.go   funcgather.go	 apifunc.go	
	
	依次说明，未完待续！
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

