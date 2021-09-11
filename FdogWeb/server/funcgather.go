package main

import (
	"fmt"
	"net/http"
	"strconv"
	"time"

	_ "github.com/go-sql-driver/mysql"

	"github.com/gin-gonic/gin"
	"github.com/tencentcloud/tencentcloud-sdk-go/tencentcloud/common"
	"github.com/tencentcloud/tencentcloud-sdk-go/tencentcloud/common/errors"
	"github.com/tencentcloud/tencentcloud-sdk-go/tencentcloud/common/profile"
	sms "github.com/tencentcloud/tencentcloud-sdk-go/tencentcloud/sms/v20210111"
)

/*
smssdkappid = "1400499299"
smsignname = "花狗的小站"
templateid = "901425"
templateparamset = "123456"
*/

//验证手机号是否注册
func GetPhoneNumberVerify(c *gin.Context) {
	_w_phone := c.Query("_w_phone")
	var phone string
	rows, err := db.Query("select phone from user where phone = " + _w_phone)
	defer rows.Close()
	if err != nil {
		fmt.Println(err)
		return
	}
	for rows.Next() {
		rows.Scan(&phone)
		if err != nil {
			fmt.Printf(err.Error())
			continue
		}
		fmt.Println("phone:", phone)
	}
	/*调用 db.Query 执行 SQL 语句, 此方法会返回一个 Rows 作为查询的结果
	rows.Next() 迭代查询数据. rows.Scan() 读取每一行的值 db.Close() 关闭查询*/
	c.JSON(http.StatusOK, gin.H{
		"phone": phone,
	})
	return
}

//发送短信验证码
func SendVerifyCode(c *gin.Context) {
	//手机号
	_w_phone := c.Query("_w_phone")
	//验证码生成
	code := strconv.Itoa(GetRandVerifyCode())
	fmt.Printf("验证码为：%s\n", code)
	//时间戳生成
	timeUnixNew := strconv.FormatInt(time.Now().Unix(), 10)
	//验证码状态判断 有手机号记录且验证码有效：0		无手机号记录：1		有手机号记录且验证码无效：2
	codeStatus, err := GetCodeStatus(_w_phone, timeUnixNew)
	if err != nil {
		return
	}
	switch codeStatus {
	case 0:
		return
	case 1:
		err := InsertSqlData(_w_phone, code, timeUnixNew)
		if err != nil {
			return
		}
	case 2:
		err := UpsqlData(_w_phone, code, timeUnixNew)
		if err != nil {
			return
		}
	default:
	}
	//使用腾讯云接口发送短信
	credential := common.NewCredential(
		Info.Smsid,  //腾讯云访问管理APIid
		Info.Smskey, //腾讯云访问管理APIkey
	)
	cpf := profile.NewClientProfile()
	cpf.HttpProfile.Endpoint = Info.Endpoint
	client, _ := sms.NewClient(credential, Info.Region, cpf) //Region为地域参数
	request := sms.NewSendSmsRequest()
	request.PhoneNumberSet = common.StringPtrs([]string{"+86" + _w_phone}) //_w_phone为要发送的手机号，+86必需，表示中国
	request.SmsSdkAppId = common.StringPtr(Info.Smssdkappid)               //短信SdkAppId
	request.SignName = common.StringPtr(Info.Smsignname)                   //短信签名内容
	request.TemplateId = common.StringPtr(Info.Templateid)                 //模板ID
	request.TemplateParamSet = common.StringPtrs([]string{code})           //模板内容参数，code为参数，验证码
	response, err := client.SendSms(request)                               //发送短信
	if _, ok := err.(*errors.TencentCloudSDKError); ok {
		fmt.Printf("An API error has returned: %s", err)
		return
	}
	if err != nil {
		panic(err)
	}
	fmt.Printf("%s", response.ToJsonString())
}

//获取验证码
func GetVerifyCode(c *gin.Context) {
	_w_phone := c.Query("_w_phone")
	var code string
	rows, err := db.Query("select code from tb_phonecode where phone = " + _w_phone)
	defer rows.Close()
	if err != nil {
		fmt.Println(err)
		return
	}
	for rows.Next() {
		rows.Scan(&code)
		if err != nil {
			fmt.Printf(err.Error())
			continue
		}
		fmt.Println("code:", code)
	}
	c.JSON(http.StatusOK, gin.H{
		"code": code,
	})
	return
}

//上传文件
func SendUploadFile(c *gin.Context) {
}

//下载文件
func GetFileDownloadUrl(c *gin.Context) {
}
