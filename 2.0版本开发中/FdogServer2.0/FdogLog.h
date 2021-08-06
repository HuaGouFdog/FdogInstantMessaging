//日志类
#ifndef FDOGLOG_H
#define FDOGLOG_H
#include<iostream>
#include<time.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include"FdogStaticFunc.h"
static bool isfile = false;//是否开始日志保存
static std::string fiileurl = "";//日志保存地址
static int log_output_level = 5; //输出等级

static std::string GetDateTime()//获取时间
{
    //获取系统时间
	time_t now_time =time(NULL);
	//获取本地时间
	tm * t_tm = localtime(&now_time);
	std::string datatinme = asctime(t_tm);
    datatinme.erase(datatinme.end() - 1);
    return "["+datatinme+"]";
}

static void WriteLog(std::string fileurl,std::string data)
{
    std::cout<<"路径:"<<fileurl<<"\n";
    if(fileurl=="")
    {
        fileurl = "logs";
        if (0 != access(fileurl.c_str(), 0))
        {
            // if this folder not exist, create a new one.
            mkdir(fileurl.c_str(),0);   // 返回 0 表示创建成功，-1 表示失败
            //换成 ::_mkdir  ::_access 也行，不知道什么意思
        }
    }
    else
    {
        if (0 != access(fileurl.c_str(), 0))
        {
            // if this folder not exist, create a new one.
            mkdir(fileurl.c_str(),0);   // 返回 0 表示创建成功，-1 表示失败
            //换成 ::_mkdir  ::_access 也行，不知道什么意思
        }
    }
    
    //在此编写写入文件
}

/*保存日志*/
#define RECORD_LOG(isfile_b,fileurl_s) do{\
isfile=isfile_b;\
fiileurl=fileurl_s;\
std::cout<<"日志写入开始工作"<<fileurl_s<<"\n";\
}while(0)

/*修改日志输出等级*/
#define Log_Output_Level(level) do{\
log_output_level = level;\
}while(0)

//标准库已有 __FILE__源文件名宏  __func__函数名宏  __LINE__ 行数宏
#define __FTIME__ GetDateTime() //自定义时间宏

/*ERROR（错误）：此信息输出后，主体系统核心模块不能正常工作，需要修复才能正常工作。*/
#define LOG_Error(text) do{\
std::string data = __FTIME__+"ERROR "+__FILE__+":"+__func__+":"+std::to_string(__LINE__)+" "+text+"\n";\
if(isfile) WriteLog(fiileurl,data);\
if(log_output_level>0)std::cout<<data;\
}while(0)

/*WARN（警告）：此信息输出后，系统一般模块存在问题，不影响系统运行。*/
#define LOG_Warn(text) do{\
std::string data = __FTIME__+"WARN "+__FILE__+":"+__func__+":"+std::to_string(__LINE__)+" "+text+"\n";\
if(isfile) WriteLog(fiileurl,data);\
if(log_output_level>1)std::cout<<data;\
}while(0)

/*INFO（通知）：此信息输出后，主要是记录系统运行状态等关联信息。*/
#define LOG_Info(text) do{\
std::string data = __FTIME__+"INFO "+__FILE__+":"+__func__+":"+std::to_string(__LINE__)+" "+text+"\n";\
if(isfile) WriteLog(fiileurl,data);\
if(log_output_level>2)std::cout<<data;\
}while(0)

/*DEBUG（调试）：最细粒度的输出，除却上面各种情况后，你希望输出的相关信息，都可以在这里输出。*/
#define LOG_Debug(text) do{\
std::string data = __FTIME__+"DEBUG "+__FILE__+":"+__func__+":"+std::to_string(__LINE__)+" "+text+"\n";\
if(isfile) WriteLog(fiileurl,data);\
if(log_output_level>3)std::cout<<data;\
}while(0)

/*TRACE（跟踪）：最细粒度的输出，除却上面各种情况后，你希望输出的相关信息，都可以在这里输出。*/
#define LOG_Trace(text) do{\
std::string data = __FTIME__+"TRACE "+__FILE__+":"+__func__+":"+std::to_string(__LINE__)+" "+text+"\n";\
if(isfile) WriteLog(fiileurl,data);\
if(log_output_level>4)std::cout<<data;\
}while(0)
#endif

