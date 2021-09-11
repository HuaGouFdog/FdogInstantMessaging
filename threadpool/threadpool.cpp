#include"threadpool.h"
#include<iostream>
#include<unistd.h>
using namespace std;


void * workFunction(void * arg){
    ThreadPool * threadpool = (ThreadPool*)arg;
    while(1){
        mutexPool.lock();
        while(threadpool->taskQueue.empty() && !threadpool->threadShutdown){
            threadpool->queueEmpty.wait(locker);
            if(threadpool->threadEixtNum>0){
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
        Task task = threadpool->getTask();
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

    ThreadPool * threadpool = (ThreadPool*)arg;
    while(!threadpool->threadShutdown){

        sleep(2);
        mutexPool.lock();

        int queueSize = threadpool->getTaskResidualQuantity();

        int threadLiveNum = threadpool->getThreadLiveQuantity();

        int threadBusyNum = threadpool->getThreadBusyQuantity();
        mutexPool.unlock();

        if(queueSize>0 && threadLiveNum < threadpool->threadMax){

            threadpool->requestAdditionalThreads();
        }

        if(threadpool->threadBusyNum < threadpool->threadLiveNum && threadpool->threadLiveNum > threadpool->threadNum){
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

    this->managerTID = new std::thread(managerFunction,this);
    this->managerTID->detach();
    for(int i = 0;i<this->threadNum;i++){
        std::thread * th = new std::thread(workFunction,this);
        this->worksTID.emplace_back(th);
        this->workAddr[th->get_id()] = th;
        th->detach();
        this->threadLiveNum+=1;
    }
    mutexPool.unlock();
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
    this->workAddr[th->get_id()] = th;
    th->detach();
    this->worksTID.emplace_back(th);
    this->threadLiveNum+=1;
    mutexPool.unlock();
    return true;
}

bool ThreadPool::destroyThreads(){
    mutexPool.lock();
    this->threadEixtNum = this->threadLiveNum-this->threadNum;
    mutexPool.unlock();
    if(threadEixtNum>1){
        this->queueEmpty.notify_all();
    }else{
        this->queueEmpty.notify_one();
    }
    return true;
}

bool ThreadPool::worksTreadEixt(std::thread::id Tid){

    std::thread * th = this->workAddr[Tid];
    for(std::vector<std::thread *>::iterator it=this->worksTID.begin();it!=this->worksTID.end(); it++){
        if(*it == th){
            it = this->worksTID.erase(it);
            return true;
        }
    }
    return true;
}

bool ThreadPool::addTasks(void (*func)(void * ),void * arg){
    int queueSize = this->getTaskResidualQuantity();
    while(queueSize >= 800){
        //阻塞生产者线程
        this->queueFull.wait(locker);
    }

    if(this->threadShutdown){
        return true;
    }
    Task task;
    task.function = func;
    task.arg = arg;
    this->taskQueue.push(task);
    this->queueEmpty.notify_one();
    return true;
}

Task ThreadPool::getTask(){
    Task task;
    task.function = this->taskQueue.front().function;
    task.arg = this->taskQueue.front().arg;
    this->taskQueue.pop();
    this->queueFull.notify_one();
    return task;
}

ThreadPool::~ThreadPool(){

}
