#Fdog即时通讯软件web端

#web端运行说明(当前版本2.0)

>	下面为运行说明文档，如有疑惑，详情可查看Fdogweb搭建部署文档。

**1.设置配置文件ProgramRunInfo.conf**

>	addr:  			Fdogweb服务ip 如"127.0.0.1"

>	port:  			Fdogweb服务端口 如"8020"

>	smsid:  		腾讯云API密钥id

>	smskey:			腾讯云API密钥key

>	endpoint: 		短信接口"sms.tencentcloudapi.com" 无需修改

>	region: 		地域参数   如"ap-nanjing"表示南京

>	smssdkappid: 	短信SdkAppId

>	smsignname: 	短信签名内容

>	templateid: 	已审核通过的模板ID

>	user:			mysql用户名
	
>	passwd:			mysql密码

>	addr2:			mysqlP

>	datbase:		mysql数据库名

**2.终端运行Fdogweb命令**

> cd httpServer

> go mod init HttpServer

> go mod tidy

> go build

> ./HttpServer


**3.打开浏览器输入地址:**
> IP:端口/index
>如 http://www.xxx.com:18888/index
