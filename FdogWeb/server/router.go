package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

/*初始化路由*/
func InitRouter(router *gin.Engine) {
	//配置静态文件夹路径
	router.StaticFS("/css", http.Dir("../app/css"))
	router.StaticFS("/img", http.Dir("../app/img"))
	router.StaticFS("/js", http.Dir("../app/js"))
	router.LoadHTMLGlob("../app/*.html")

	//主界面
	router.GET("/index", func(c *gin.Context) {
		c.HTML(http.StatusOK, "index.html", gin.H{})
	})

	//注册页面
	router.GET("/register", func(c *gin.Context) {
		c.HTML(http.StatusOK, "register.html", gin.H{})
	})

	//注册成功界面
	router.GET("registers", func(c *gin.Context) {
		c.HTML(http.StatusOK, "registers.html", gin.H{})
	})
	//开发文档页面
	router.GET("/document", func(c *gin.Context) {
		c.HTML(http.StatusOK, "document.html", gin.H{})
	})
	//账号找回界面
	router.GET("/retaccount", func(c *gin.Context) {
		c.HTML(http.StatusOK, "retaccount.html", gin.H{})
	})

	//手机注册验证
	router.GET("/getphonenumberverify", GetPhoneNumberVerify)

	//发送短信验证码
	router.GET("/sendverifycode", SendVerifyCode)

	//验证码验证
	router.GET("/getverifycode", GetVerifyCode)

	//上传文件
	router.GET("/senduploadfile", SendUploadFile)

	//下载文件
	router.GET("/getdownloadfile", GetFileDownloadUrl)

	/*****************************回调接口****************************/
	//获取用户头像
}
