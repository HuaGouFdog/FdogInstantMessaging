#ifndef FDOGLOG_H
#define FDOGLOG_H
#include<iostream>
#include<time.h>
#include<fstream>
#include<map>
#ifndef linux
#include<unistd.h>
#include<sys/syscall.h>
#include<sys/stat.h>
#include<sys/types.h>
#endif
#ifndef WIN32
//TODO
#endif

#define RED   "\e[1;31m"
#define BLUE  "\e[1;34m"
#define GREEN "\e[1;32m"
#define WHITE "\e[1;37m"
#define DEFA  "\e[0m"

#define LOG_INIT  loginit()
#define __FTIME__ GetDateTime() //时间宏
#define __PID__   GetPid()      //进程宏
#define __TID__   GetTid()      //线程宏
#define __NAME__  (name) #name  //名字宏

struct FdogLogConf
{
    std::string logswitch;  //日志开关
    std::string logfile;   //是否写入文件
    std::string logterminal;//是否打印到终端
    std::string logname;    //日志文件名字
    std::string logpath;    //日志文件保存路径
    std::string logmixsize; //日志文件最大大小
    std::string logbehavior;//日志文件达到最大大小行为
    std::string logoverlay; //日志文件覆盖时间
    std::string logoutputlevelfile;//日志输出等级(file)
    std::string logoutputlevelterminal;//日志输出等级
    std::string loglevelbold;//日志等级是否加粗
    std::string error;      //日志颜色设置
    std::string warn;       //日志颜色设置
    std::string info;       //日志颜色设置
    std::string debug;      //日志颜色设置
    std::string trace;      //日志颜色设置
};

 FdogLogConf flogconf;
 std::map<std::string,std::string *> FlogConfInfo;
 char szbuf[128];

/*创建文件夹以及文件名*/
 bool CreateFile( std::string fileurl_s){
    int len = fileurl_s.length();
    if(!len){
        fileurl_s = "log";
        if (0 != access(fileurl_s.c_str(), 0)){
            if(-1 == mkdir(fileurl_s.c_str(),0)){
                std::cout<<"没路径";
                return 0;
            }
        }
    }
    std::string fileurl_s_cy(len,'\0');
    for(int i =0;i<len;i++){
        fileurl_s_cy[i]=fileurl_s[i];
        if(fileurl_s_cy[i]=='/' || fileurl_s_cy[i]=='\\'){
            if (-1 == access(fileurl_s_cy.c_str(), 0)){
                if(0!=mkdir(fileurl_s_cy.c_str(),0)){
                    std::cout<<"有路径";
                    return 0;
                }
            }
        }
    }
    return 1;
}

 void loginit(){
    FlogConfInfo["logswitch"]=&flogconf.logswitch;
    FlogConfInfo["logfile"]=&flogconf.logfile;
    FlogConfInfo["logterminal"]=&flogconf.logterminal;
    FlogConfInfo["logname"]=&flogconf.logname;
    FlogConfInfo["logpath"]=&flogconf.logpath;
    FlogConfInfo["logmixsize"]=&flogconf.logmixsize;
    FlogConfInfo["logbehavior"]=&flogconf.logbehavior;
    FlogConfInfo["logoverlay"]=&flogconf.logoverlay;
    FlogConfInfo["logoutputlevelfile"]=&flogconf.logoutputlevelfile;
    FlogConfInfo["logoutputlevelterminal"]=&flogconf.logoutputlevelterminal;
    FlogConfInfo["loglevelbold"]=&flogconf.loglevelbold;
    FlogConfInfo["error"]=&flogconf.error;
    FlogConfInfo["warn"]=&flogconf.warn;
    FlogConfInfo["info"]=&flogconf.info;
    FlogConfInfo["debug"]=&flogconf.debug;
    FlogConfInfo["trace"]=&flogconf.trace;
    std::string str;
    std::ifstream file;
    char str1[100]={0};
    file.open("fdoglog/fdoglog.conf");
    if(!file.is_open()){
        //std::cout<<"没打开"<<std::endl;
    }
    while(getline(file,str)){
        if(!str.length())continue;
    std::string str_copy = str;
    int j =0;
    for(int i = 0;i<str.length();i++){
        if(str[i]==' ')continue;
        str_copy[j]=str[i];
        j++;
    }
    str_copy.erase(j);
        if(str_copy[0]!='#'){
        sscanf(str_copy.data(),"%[^=]",str1);
            auto iter = FlogConfInfo.find(str1);
            if(iter!=FlogConfInfo.end()){
                sscanf(str_copy.data(),"%*[^=]=%s",str1);
                *iter->second = str1;
            }
        }
    }
    std::cout<<"路径:"<<flogconf.logpath<<"\n";
    if(flogconf.logfile == "on"){
        if(!CreateFile(flogconf.logpath)){
            std::cout<<"Log work path creation failed\n";
        }
    }
}
/*获取当前时间*/
 std::string GetDateTime(){
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep));
    return tmp;
}
/*获取进程id和线程id*/
#ifndef linux
 unsigned long GetPid(){
    return getpid();
}
 unsigned long GetTid(){
    return syscall(__NR_gettid);
}
#endif
#ifndef WIN32
//  unsigned long GetPid(){
//     return GetCurrentProcessId();
// }
//  unsigned long GetTid(){
//     return GetCurrentThreadId();
// }
#endif
/*写日志*/
 bool WriteLog(const std::string data)
{  
    //在此写入文件
    std::ofstream file;
    file.open(flogconf.logpath+flogconf.logname, std::ios::app | std::ios::out);
    if(!file){
        return 0;
    }
    file<<data;
    file.close();
    return 1;
}

/*执行配置文件中的设置行为*/
 void behavior(std::string info,std::string logtype,int beha){
    //文件 是否写入文件  写入文件的等级
    if(behavior == 0){
        return;
    }
    if(!flogconf.logfile.compare("on")){
        //判断写入等级是否符合
        if(beha == 1 || beha == 3){
            if(!WriteLog(info)){            
                std::cout<<"["+__FTIME__+"]"+RED+" "+logtype+" "+DEFA+"root "+std::to_string(__PID__)+
                 " ["+szbuf+"/"+__FILE__+"] in function "+__func__+":"+std::to_string(__LINE__)+" "+"日志写入失败"+"\n";
            }
        }
    }
    //终端 是否显示在终端，显示等级
    if(!flogconf.logterminal.compare("on")){
        if(beha == 2 || beha == 3){
            std::cout<<info;
        }
    }
    return;
}


/*ERROR（错误）:此信息输出后，主体系统核心模块不能正常工作，需要修复才能正常工作。*/
#define LOG_Error(text) do{\
getcwd(szbuf, sizeof(szbuf)-1);\
std::string data ="["+__FTIME__+"]"+RED+" ERROR "+DEFA+"root "+std::to_string(__TID__)+" ["+szbuf+"/"+__FILE__+"] "+\
__func__+":"+std::to_string(__LINE__)+" "+text+"\n";\
int beha = 0;\
if(flogconf.logoutputlevelfile.find("0")!=std::string::npos) beha = beha+1;\
if(flogconf.logoutputlevelterminal.find("0")!=std::string::npos) beha = beha+2;\
behavior(data,"ERROR",beha);\
}while(0)

/*WARN（警告）:此信息输出后，系统一般模块存在问题，不影响系统运行。*/
#define LOG_Warn(text) do{\
std::string data ="["+__FTIME__+"]"+RED+" WARNING "+DEFA+"root "+std::to_string(__TID__)+" ["+szbuf+"/"+__FILE__+"] "+\
__func__+":"+std::to_string(__LINE__)+" "+text+"\n";\
int beha = 0;\
if(flogconf.logoutputlevelfile.find("1")!=std::string::npos) beha = beha+1;\
if(flogconf.logoutputlevelterminal.find("1")!=std::string::npos) beha = beha+2;\
behavior(data,"WARNING",beha);\
}while(0)

/*INFO（通知）:此信息输出后，主要是记录系统运行状态等关联信息。*/
#define LOG_Info(text) do{\
getcwd(szbuf, sizeof(szbuf)-1);\
std::string data ="["+__FTIME__+"]"+BLUE+" INFO "+DEFA+"root "+std::to_string(__TID__)+" ["+szbuf+"/"+__FILE__+"] "+\
__func__+":"+std::to_string(__LINE__)+" "+text+"\n";\
int beha = 0;\
if(flogconf.logoutputlevelfile.find("2")!=std::string::npos) beha = beha+1;\
if(flogconf.logoutputlevelterminal.find("2")!=std::string::npos) beha = beha+2;\
behavior(data,"INFO",beha);\
}while(0)

/*DEBUG（调试）:最细粒度的输出，除却上面各种情况后，你希望输出的相关信息，都可以在这里输出。*/
#define LOG_Debug(text) do{\
getcwd(szbuf, sizeof(szbuf)-1);\
std::string data ="["+__FTIME__+"]"+GREEN+" DEBUG "+DEFA+"root "+std::to_string(__TID__)+" ["+szbuf+"/"+__FILE__+"] "+\
__func__+":"+std::to_string(__LINE__)+" "+text+"\n";\
int beha = 0;\
if(flogconf.logoutputlevelfile.find("3")!=std::string::npos) beha = beha+1;\
if(flogconf.logoutputlevelterminal.find("3")!=std::string::npos) beha = beha+2;\
behavior(data,"DEBUG",beha);\
}while(0)

/*TRACE（跟踪）:最细粒度的输出，除却上面各种情况后，你希望输出的相关信息，都可以在这里输出。*/
#define LOG_Trace(text) do{\
getcwd(szbuf, sizeof(szbuf)-1);\
std::string data ="["+__FTIME__+"]"+WHITE+" TRACE "+DEFA+"root "+std::to_string(__TID__)+" ["+szbuf+"/"+__FILE__+"] "+\
__func__+":"+std::to_string(__LINE__)+" "+text+"\n";\
int beha = 0;\
if(flogconf.logoutputlevelfile.find("4")!=std::string::npos) beha = beha+1;\
if(flogconf.logoutputlevelterminal.find("4")!=std::string::npos) beha = beha+2;\
behavior(data,"TRACE",beha);\
}while(0)

#endif
