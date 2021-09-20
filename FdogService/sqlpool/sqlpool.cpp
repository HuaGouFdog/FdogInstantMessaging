#include"sqlpool.h"
#include<iostream>
#include<mysql/mysql.h>
#include<fstream>


SqlPool::SqlPool() {

}

bool SqlPool::SqlPoolCreateInit() {
    cout<<"开始初始化"<<endl;
    getConfToStruct("sqlpool.conf");
    this->sqlPoolNum = 1;   //连接池默认连接数
    this->sqlPoolMix = 5;   //连接池最大连接数
    this->sqlBusyNum = 0;   //sql连接忙碌数
    this->sqlLiveNum = 1;   //sql连接存活数
    this->sqlEixtNum = 1;   //释放sql连接数
    this->sqlShutdown = 0; //销毁sql连接池
    for(int i = 0; i< this->sqlPoolNum; i++) {
        MYSQL * conn = nullptr;
        conn = mysql_init(NULL);
        if(mysql_real_connect(conn,this->sqlpoolconf.host.c_str(),this->sqlpoolconf.mysqluser.c_str(),
        this->sqlpoolconf.mysqlpassword.c_str(),this->sqlpoolconf.database.c_str(),0,NULL,CLIENT_FOUND_ROWS)) {
            //cout<<"连接成功"<<endl;
        }
        this->conns.emplace_back(conn);
        this->availableConn[conn] = true;
        this->sqlLiveNum++;
    }

    return true;
}

MYSQL * SqlPool::getSqlConnectOne() {
    mutexPool.lock();
    if(this->sqlBusyNum == this->sqlLiveNum && this->sqlLiveNum < this->sqlPoolMix) {
        //申请新的连接
        MYSQL * conn = requestAdditionalsqlConnectOne();
        this->conns.emplace_back(conn);
        this->availableConn[conn] = false;
        this->sqlBusyNum++;
        this->sqlEixtNum++;
        mutexPool.unlock();
        return conn;
    }

    for(std::map<MYSQL *,bool>::iterator it = availableConn.begin();it!=availableConn.end();it++) {
		if(it->second==true) {
            cout<<"通过value:  "<<"true"<<"    找到的key:"<<it->first<<endl;
            it->second=false;
            cout<<"使用后的值："<<it->second<<endl;
            this->sqlBusyNum++;
            mutexPool.unlock();
            return it->first;
        }
	}
    mutexPool.unlock();
    return nullptr;
}

bool  SqlPool::releaseSqlConnectone(MYSQL * conn) {
    cout<<"进入释放 vertor长度"<<this->conns.size()<<endl; 
    mutexPool.lock();
    if(this->availableConn.count(conn)>0)
	{
    	cout<<"通过key:  "<<conn<<"     找到的value:"<<this->availableConn[conn]<<endl;
        this->availableConn[conn] = true;
        cout<<"使用后的值："<<this->availableConn[conn]<<endl;
        this->sqlBusyNum--;
        //释放之后，判断是不是需要销毁这个连接
        if(this->sqlEixtNum>0) {
            for(vector<MYSQL *>::iterator it = this->conns.begin();it!=this->conns.end();it++) {
                cout<<"it:"<<*it<<"  conn:"<<conn<<endl;
                if(*it == conn) {
                    mysql_close(conn);
                    delete conn;
                    conn = nullptr;
                    cout<<"找到释放"<<endl;
                    it = this->conns.erase(it);
                    mutexPool.unlock();
                    return true;
                }
            }
            this->availableConn.erase(conn);
        }
        mutexPool.unlock();
        return true;
	}
    mutexPool.unlock();
    return false;
}

MYSQL * SqlPool::requestAdditionalsqlConnectOne() {
    MYSQL * conn = nullptr;
    conn = mysql_init(NULL);
    if(mysql_real_connect(conn,this->sqlpoolconf.host.c_str(),this->sqlpoolconf.mysqluser.c_str(),
    this->sqlpoolconf.mysqlpassword.c_str(),this->sqlpoolconf.database.c_str(),0,NULL,CLIENT_FOUND_ROWS)) {
        //cout<<"连接成功"<<endl;
    }
    return conn;
}

bool SqlPool::getConfToStruct(std::string filepath) {
    confInfo["host"] = &this->sqlpoolconf.host;
    confInfo["mysqluser"] = &this->sqlpoolconf.mysqluser;
    confInfo["mysqlpassword"] = &this->sqlpoolconf.mysqlpassword;
    confInfo["database"] = &this->sqlpoolconf.database;
    string str;
    ifstream file;
    char str1[100]={0};
    file.open(filepath);
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
            auto iter = confInfo.find(str1);
            if(iter!=confInfo.end()){
                sscanf(str_copy.data(),"%*[^=]=%s",str1);
                *iter->second = str1;
            }
        }
    }
    return true;
}


SqlPool::~SqlPool() {
    for(int i= 0; i<this->conns.size();i++) {
        mysql_close(this ->conns[i]);
        delete this ->conns[i];
        this->conns[i] = nullptr;
    }
    this->conns.clear();
    this->availableConn.clear();
}