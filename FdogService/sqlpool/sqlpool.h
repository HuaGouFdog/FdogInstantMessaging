#ifndef SQLPOOL_H
#define SQLPOOL_H
#include<vector>
#include<map>
#include<mutex>
#include<mysql/mysql.h>
using namespace std;

static std::mutex mutexPool;
static std::mutex mutexBusy;

struct SqlPoolConf
{
    string host;
    string mysqluser;
    string mysqlpassword;
    string database;
};


class SqlPool
{
private:
    vector<MYSQL *> conns; //连接池
    map<MYSQL *, bool> availableConn;//监视可用连接
    int sqlPoolNum; //连接池默认连接数
    int sqlPoolMix; //连接池最大连接数
    int sqlBusyNum; //sql连接忙碌数
    int sqlLiveNum; //sql连接存活数
    int sqlEixtNum; //释放sql连接数
    int sqlShutdown; //销毁sql连接池
    SqlPoolConf sqlpoolconf;
    map<string,string *> confInfo;
public:

    SqlPool();

    //读取配置文件
    bool getConfToStruct(std::string filepath);

    //初始化函数
    bool SqlPoolCreateInit();

    //获取一个连接
    MYSQL * getSqlConnectOne();

    //释放一个连接
    bool releaseSqlConnectone(MYSQL * conn);

    //申请一个连接
    MYSQL * requestAdditionalsqlConnectOne();

    //销毁一个连接
    bool destorySqlConnectOne();

//释放资源
    ~SqlPool();
};

#endif