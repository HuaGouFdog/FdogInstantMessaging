#ifndef FDOGTHREADPOOL_H
#define FDOGTHREADPOOL_H
#include"FdogType.h"
//记得添加互斥锁
class FdogThreadPool
{
private:
    threadpool_t * m_threadpool = nullptr;//线程池结构体指针
public:
    /*使用默认配置*/
    FdogThreadPool();
    /*自定义*/
    FdogThreadPool(int cores,int cores_min,int cores_max, int status);
    /*创建连接池*/
    void CreateThreadPool(int cores,int cores_min, int cores_max,int status)const;
    /*获取可用连接*/
    thread_t* GetAvilableThread();
    /*申请可用线程*/
    thread_t* ApplyThread();
    /*释放线程资源到线程池*/
    void ReleaseThread(thread_t * const);
    /*从线程池释资源*/
    void DeleteThread(thread_t * const)
    /*释放资源*/
    ~FdogThreadPool();
};

#endif