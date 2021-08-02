#include"FdogThreadPool.h"
FdogThreadPool::FdogThreadPool()
:m_threadpool(new threadpool_t)
{
    //使用默认配置
    CreateThreadPool(std::thread::hardware_concurrency(),1,std::thread::hardware_concurrency()*2,0);
}

FdogThreadPool::FdogThreadPool(int cores,int cores_min,int cores_max, int status)
:m_threadpool(new threadpool_t)
{
    CreateThreadPool(cores,cores_min,cores_max,status);
}
    
void FdogThreadPool::CreateThreadPool(int cores,int cores_min = 1,int cores_max = std::thread::hardware_concurrency()*2, int status)const
{
    m_threadpool->m_cores = cores;
    m_threadpool->m_cores_min = cores_min;
    m_threadpool->m_cores_max = cores_max;
    m_threadpool->m_status = status;
    m_threadpool->m_threads.reserve(cores);
    for(int i =0;i<cores;i++)
    {
        m_threadpool->m_threads.push_back(new thread_t{new std::thread,true});
    }
}

thread_t* FdogThreadPool::GetAvilableThread()
{
    int count = 0;
    bool status = true;
    while(1)
    {
        //加锁
        mutex_t.lock();
        if(m_threadpool->m_status <= 0)
        {
            //等待执行 超10次没有则申请线程
            if((++count)>10 && status==true)
            {
                //直接申请线程并返回，如果申请已经达到最大线程量，不预申请，依旧等待
                auto thread = ApplyThread();
                if(thread != nullptr)
                {
                    mutex_t.unlock();
                    return thread;
                }
                status = false;
            }
            mutex_t.unlock();
            continue;
        }
        for(auto &i :m_threadpool->m_threads)
        {
            if(i->m_status==true)
            {
                m_threadpool->m_status-=1;
                i->m_status = false;
                return i;
            }
        }
        mutex_t.unlock();
    }
    return nullptr;
}

thread_t* FdogThreadPool::ApplyThread()
{
    //判断当前是否可以申请
    mutex_t.lock();
    if(m_threadpool->m_cores < m_threadpool->m_cores_max)
    {
        //可申请 申请的线程的状态无需放入线程池，用完即销毁
        m_threadpool->m_cores_num += 1;
        return new thread_t{new std::thread,false};
        mutex_t.unlock();
    }
    mutex_t.unlock();
    return nullptr;
}


void FdogThreadPool::ReleaseThread(thread_t* const thread)
{   
    //判断当前线程池数量，是否超量，若超量直接释放可不是继续存放在线程池
    if(m_threadpool->m_cores_num>0)
    {
        m_threadpool->m_cores_num-= 1;
        DeleteThread(thread);
    }
    thread->m_status=true;
    m_threadpool->m_status+=1;
}

void FdogThreadPool::DeleteThread(thread_t * thread)
{
    delete(thread);
    thread=nullptr;
}

FdogThreadPool::~FdogThreadPool()
{
    //vector为普通变量，无需手动释放，但是vector里面的数据为手动申请的内存，需要手动释放。
    for(auto i :m_threadpool->m_threads)
    {
        delete(i->m_thread);
        i->m_thread=nullptr;
    }
    delete(m_threadpool);
    m_threadpool=nullptr;
}
