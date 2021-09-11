#ifndef THREADPOOL_H
#define THREADPOOL_H
#include<thread>
#include<vector>
#include<queue>
#include<map>
#include<mutex>
#include<condition_variable>

static std::mutex mutexPool;           //互斥锁 锁整个线程
static std::mutex mutexBusy;           //互斥锁 锁忙碌线程数量
static std::unique_lock<std::mutex> locker(mutexPool);

typedef struct Task                    //任务函数用于接受任意函数，任意参数的函数
{
    void (*function)(void* arg);
    void* arg;
}Task;

class ThreadPool
{
public:
    std::queue<Task> taskQueue;             //任务队列
    std::thread * managerTID;               //管理线程
    std::vector<std::thread *> worksTID;    //工作线程
    std::map<std::thread::id,std::thread *> workAddr;   //记录线程的地址
    int threadNum;                          //默认工作线程数
    int threadMin;                          //最小工作线程
    int threadMax;                          //最大工作线程
    int threadBusyNum;                      //忙碌线程数量
    int threadLiveNum;                      //存活线程数量
    int threadEixtNum;                      //退出线程数量
    std::condition_variable queueFull;      //条件变量
    std::condition_variable queueEmpty;     //条件变量
    int threadShutdown;                     //是否要销毁线程池
public:

    //默认构造函数
    ThreadPool();
    //初始化线程池 默认配置
    bool ThreadCreateInit();

    //获取当前任务队列的剩余任务数量
    int getTaskResidualQuantity();

    //获取当前存活线程数量
    int getThreadLiveQuantity();

    //获取当前忙碌线程数量
    int getThreadBusyQuantity();

    //额外申请线程
    bool requestAdditionalThreads();

    //销毁线程
    bool destroyThreads();

    //对vector做修改
    bool worksTreadEixt(std::thread::id Tid);

    //添加任务
    bool addTasks(void (*func)(void * ),void * arg);

    //获取任务
    Task getTask();
    
    //管理函数
    friend void * managerFunctionv(void * arg);
    
    //工作函数
    friend void * workFunction(void * arg);

    //释放资源
    ~ThreadPool();

};

#endif