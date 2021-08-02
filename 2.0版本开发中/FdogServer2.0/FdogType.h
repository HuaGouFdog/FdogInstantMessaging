#ifndef FDOGTYPE_H
#define FDOGTYPE_H
#include<thread>
#include<mutex>
#include<vector>
#include<sys/socket.h>
/*线程结构体*/
typedef struct FdogThread
{
    std::thread * m_thread = nullptr; //线程
    bool m_status = true; //状态量默认为0  空闲：0  忙碌：1

}thread_t;

/*线程池结构体*/
typedef std::vector<thread_t*> Threads;//线程池载体

typedef struct FdogThreadPool
{
    Threads m_threads;  //线程池
    int m_cores;        //CPU核心数
    int m_cores_num = 0;        //申请CPU核心数
    int m_cores_min;    //CPU核心数最小
    int m_cores_max;    //CPU核心数最大
    int m_status;       //线程可用数
}threadpool_t;

/*TCP连接池结构体*/
typedef struct FdogTcpPool
{
    thread_t *thread = nullptr;//一个线程
    //std::vector<>              //一个mysql连接
                               //一个Tcp连接
}tcppool_t;

//锁
std::mutex mutex_t;

#endif