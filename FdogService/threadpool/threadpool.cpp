#include"threadpool.h"
#include<iostream>
#include<unistd.h>
using namespace std;


void * workFunction(void * arg){
    ThreadPool * threadpool = (ThreadPool*)arg;
    while(1){
        mutexPool.lock();
        //判断任务队列是否有任务 empty返回0表示没有元素
        while(threadpool->taskQueue.empty() && !threadpool->threadShutdown){
            //阻塞线程
            threadpool->queueEmpty.wait(locker);
            cout<<"我被唤醒"<<endl;
            //判断是否需要退出线程
            if(threadpool->threadEixtNum>0){
                cout<<"我被要求自杀"<<endl;
                threadpool->worksTreadEixt(std::this_thread::get_id());
                threadpool->threadEixtNum--;
                threadpool->threadLiveNum--;
                mutexPool.unlock();
                return nullptr;
            }
        }
        if(threadpool->threadShutdown){
            mutexPool.unlock();
            return nullptr;
        }
        //取任务执行
        //cout<<"取一个任务"<<endl;
        Task task = threadpool->getTask();
        //cout<<"取到一个任务，开始执行"<<endl;
        mutexPool.unlock();
        mutexBusy.lock();
        threadpool->threadBusyNum++;
        mutexBusy.unlock();
        task.function(task.arg);
        mutexBusy.lock();
        threadpool->threadBusyNum--;
        mutexBusy.unlock();

    }

    return nullptr;
}

void * managerFunction(void * arg){
    cout<<"进管理函数"<<endl;
    ThreadPool * threadpool = (ThreadPool*)arg;
    while(!threadpool->threadShutdown){
        //三秒检测一次
        sleep(2);
        mutexPool.lock();
        //取出线程池中任务数量
        int queueSize = threadpool->getTaskResidualQuantity();
        //取出当前存活线程数量
        int threadLiveNum = threadpool->getThreadLiveQuantity();
        //取出忙的线程的数量
        int threadBusyNum = threadpool->getThreadBusyQuantity();
        mutexPool.unlock();
        cout<<"检测： 当前存活线程："<<threadLiveNum<<"   当前忙碌线程:"<<threadBusyNum<<" 当前任务数："<<queueSize<<" 当前vector大小："<< threadpool->worksTID.size()<<endl;
        //添加线程  判断当前任务是否剩余过量 以及是否线程是否达到最大值

        if(queueSize>0 && threadLiveNum < threadpool->threadMax){
            cout<<"申请线程"<<endl;
            threadpool->requestAdditionalThreads();
        }
        //销毁线程  判断是否有过剩线程浑水摸鱼
        if(threadpool->threadBusyNum < threadpool->threadLiveNum && threadpool->threadLiveNum > threadpool->threadNum){
            cout<<"销毁线程:"<<threadpool->threadBusyNum<<" "<<threadpool->threadLiveNum<<"  "<<threadpool->threadNum<<endl;
            threadpool->destroyThreads();
        }
    }
    return nullptr;
}
ThreadPool::ThreadPool(){
    ThreadCreateInit();
}

bool ThreadPool::ThreadCreateInit(){

    this->threadMin = 1;
    this->threadNum =std::thread::hardware_concurrency();
    this->threadMax =std::thread::hardware_concurrency()*2;
    this->threadBusyNum = 0;
    this->threadLiveNum = 0;
    this->threadEixtNum = 0;
    this->threadShutdown = 0;

    //this->locker = new unique_lock<std::mutex> locker(mutexPool);

    this->managerTID = new std::thread(managerFunction,this);
    cout<<"管理者tid："<<managerTID->get_id()<<endl;
    this->managerTID->detach();
    for(int i = 0;i<this->threadNum;i++){
        cout<<"初始化多线程"<<endl;
        std::thread * th = new std::thread(workFunction,this);
        cout<<"工作tid："<<th->get_id()<<" 地址："<<th<<endl;
        this->worksTID.emplace_back(th);
        this->workAddr[th->get_id()] = th;
        th->detach();
        this->threadLiveNum+=1;
    }
    mutexPool.unlock();
    cout<<"完成初始化"<<endl;
    return true;
}

int ThreadPool::getTaskResidualQuantity(){
    int queueSize = this->taskQueue.size();
    return queueSize;
}

int ThreadPool::getThreadLiveQuantity(){
    int threadLiveNum = this->threadLiveNum;
    return  threadLiveNum;    
}

int ThreadPool::getThreadBusyQuantity(){
    int threadBusyNum = this->threadBusyNum;
    return threadBusyNum;
}

bool ThreadPool::requestAdditionalThreads(){
    mutexPool.lock();

    //申请线程
    std::thread * th = new std::thread(workFunction,this);
    cout<<"申请的工作tid："<<th->get_id()<<" 地址："<<th<<endl;
    this->workAddr[th->get_id()] = th;
    th->detach();
    this->worksTID.emplace_back(th);
    this->threadLiveNum+=1;
    mutexPool.unlock();
    cout<<"线程申请成功，+1"<<endl;
    return true;
}

bool ThreadPool::destroyThreads(){
    mutexPool.lock();
    this->threadEixtNum = this->threadLiveNum-this->threadNum;
    cout<<"要销毁的线程数："<<this->threadEixtNum<<endl;
    mutexPool.unlock();
    //唤醒线程 让线程自杀
    if(threadEixtNum>1){
        this->queueEmpty.notify_all();
    }else{
        this->queueEmpty.notify_one();
    }
    return true;
}

bool ThreadPool::worksTreadEixt(std::thread::id Tid){
    //获取当前线程id 在vector找这个值，然后删除该值
    cout<<"准备删除tid:"<<Tid<<endl;
    
    std::thread * th = this->workAddr[Tid];
    int c = 0;
    for(std::vector<std::thread *>::iterator it=this->worksTID.begin();it!=this->worksTID.end(); it++){
        cout<<"查找tid对应的地址:"<<(*it)<<endl;
        c++;
        if(c>16){
            return true;
        }
        if(*it == th){
            cout<<"找到当前tid的地址"<<"解决它"<<endl;
            it = this->worksTID.erase(it);
            return true;
        }
    }

    //cout<<"记录值："<<value<<endl;
    //this->worksTID.push_back(value);
    //this->worksTID.pop_back
    //cout<<"当前tid所指向地址:"<<thAddr<<endl;
    //int count = this->worksTID.size();
    // for(int i=0;i<count;i++){
    //     cout<<"count值："<<count<<"查找地址:"<<&this->worksTID[i]<<endl;
    //     if(&this->worksTID[i]== thAddr){
    //         cout<<"找到当前地址"<<"解决它"<<endl;
    //         //this->worksTID.erase()
    //     }
    // }
    cout<<"线程完成自杀"<<endl;
    return true;
}

bool ThreadPool::addTasks(void (*func)(void * ),void * arg){
    //mutexPool.unlock();
    //mutexPool.lock();
    //std::cout<<"addtask:收到连接"<<std::endl;
    //看后期是否需要控制任务总数 可以阻塞这个函数
    int queueSize = this->getTaskResidualQuantity();
    while(queueSize >= 800){
        //阻塞生产者线程
        this->queueFull.wait(locker);
    }

    if(this->threadShutdown){
        //mutexPool.unlock();
        return true;
    }
    Task task;
    task.function = func;
    task.arg = arg;
    this->taskQueue.push(task);
    this->queueEmpty.notify_one();
    //mutexPool.unlock();
    //std::cout<<"addtask:收到连接并添加任务到任务队列"<<std::endl;
    return true;
}

Task ThreadPool::getTask(){
     //mutexPool.unlock();
     //mutexPool.lock();
    cout<<"获取任务"<<endl;
    Task task;
    task.function = this->taskQueue.front().function;
    task.arg = this->taskQueue.front().arg;
    this->taskQueue.pop();
    this->queueFull.notify_one();
    //mutexPool.unlock();
    return task;
}

ThreadPool::~ThreadPool(){

    delete this->managerTID;
    for(int i = 0;i<this->worksTID.size();i++){
        delete this->worksTID[i];
    }
    this->worksTID.clear();
    this->workAddr.clear();
}