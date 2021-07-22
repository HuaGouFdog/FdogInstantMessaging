package main

import (
	"database/sql"
	"fmt"
	"io/ioutil"
	"os"

	"github.com/gin-gonic/gin"
	_ "github.com/go-sql-driver/mysql"
	"github.com/naoina/toml"
)

/*保存配置文件中的信息*/
type InfoConfig struct {
	Addr        string
	Port        string
	Smsid       string
	Smskey      string
	Endpoint    string
	Region      string
	Smssdkappid string
	Smsignname  string
	Templateid  string
	User        string
	Passwd      string
	Addr2       string
	Database    string
}

var Info InfoConfig

//type DB sql.DB

var db *sql.DB

/*读取配置文件*/
func initConfig(file string) error {
	f, err := os.Open(file)
	if err != nil {
		return err
	}
	defer f.Close()
	buf, err := ioutil.ReadAll(f)
	if err != nil {
		return err
	}
	if err := toml.Unmarshal(buf, &Info); err != nil {
		return err
	}
	return nil
}

/*连接数据库*/
func ConnectMysql(user string, passwd string, addr2 string, database string) (*sql.DB, error) {
	db, err := sql.Open("mysql", user+":"+passwd+"@("+addr2+")/"+database)
	if err != nil {
		fmt.Println("连接数据库失败1")
		return db, err
	}
	return db, nil
}

func main() {
	err := initConfig("../ProgramRunInfo.conf")
	if err != nil {
		fmt.Printf("配置文件读取失败")
	}
	/*
			user = "root"
		passwd = "3226960*"
		addr2 = "82.156.111.139"
		datbase = "fdogsql"
	*/
	db, err = ConnectMysql(Info.User, Info.Passwd, Info.Addr2, Info.Database)
	if err != nil {
		fmt.Println("连接数据库失败2")
	}
	//gin中间件：Default 使用 Logger 和 Recovery 中间件
	rDefault := gin.Default()
	InitRouter(rDefault)
	//监听服务
	rDefault.Run(":" + Info.Port)
	//fmt.Println(Info.Addr + "\n" + Info.Port + "\n" + Info.Smsid + "\n" + Info.Smskey)
	//fmt.Println(Info.Smssdkappid + "\n" + Info.Smsignname + "\n" + Info.Templateid + "\n" + Info.Region + "\n" + Info.Endpoint)
	defer db.Close()
}
