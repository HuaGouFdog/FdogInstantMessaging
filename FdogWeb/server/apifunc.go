package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"time"

	_ "github.com/go-sql-driver/mysql"
)

//获取验证码随机数
func GetRandVerifyCode() int {
	rand.Seed(time.Now().UnixNano())
	return rand.Intn(90001) + 10000
}

//获取验证码状态
func GetCodeStatus(_w_phone string, timeUnixnew string) (int, error) {
	//1) 手机号存在 验证码没有超过60秒 0
	//2) 手机号不存在 返回 1
	//3) 手机号存在 验证码超过60秒 2
	rows, err := db.Query("select phone,time from tb_phonecode where phone = " + _w_phone)
	defer rows.Close()
	if err != nil {
		fmt.Println(err)
		return -1, nil
	}
	var phone string
	var time string
	for rows.Next() {
		rows.Scan(&phone, &time)
		if err != nil {
			fmt.Printf(err.Error())
			continue
		}
		//手机号存在
		fmt.Println("获取验证码状态phone:" + phone)
		fmt.Println("获取验证码状态time:" + time)
		//判断时间戳并返回值
		return JudgeTimeStamp(time, timeUnixnew), nil
	}
	//手机号不存在
	fmt.Printf("手机号不存在")
	return 1, nil
}

//通过时间戳判断是否超时
func JudgeTimeStamp(timeUnixold string, timeUnixnew string) int {
	fmt.Printf("进入时间戳判断\n")
	timeUnixold_int, err1 := strconv.Atoi(timeUnixold)
	if err1 != nil {
		return -1
	}
	timeUnixnew_int, err2 := strconv.Atoi(timeUnixnew)
	if err2 != nil {
		return -1
	}
	if (timeUnixold_int + 60) <= timeUnixnew_int {
		return 2
	}
	return 0
}

//插入验证码
func InsertSqlData(_w_phone string, code string, timeUnix string) (err error) {
	//fmt.Printf("当前时间戳：%s", timeUnix)
	str := "INSERT INTO tb_phonecode (phone,code,time) VALUES (" + _w_phone + "," + code + "," + timeUnix + ")"
	//fmt.Printf("mysqlstr:%s\n", str)
	_, errn := db.Query(str)
	if errn != nil {
		fmt.Println(errn)
		return nil
	}
	return
}

//更新验证码
func UpsqlData(_w_phone string, code string, timeUnix string) (err error) {
	//fmt.Printf("当前时间戳：%s", timeUnix)
	str := "UPDATE tb_phonecode set code =" + code + ",time = " + timeUnix + " where phone = " + _w_phone
	//fmt.Printf("mysqlstr:%s\n", str)
	_, errn := db.Query(str)
	if errn != nil {
		fmt.Println(errn)
		return nil
	}
	return
}
