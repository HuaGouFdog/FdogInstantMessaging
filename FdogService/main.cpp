#include<iostream>
#include<fstream>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include"threadpool/threadpool.h"
#include"fdoglog/FdogLog.h"
#include"service.h"
#define MAXLINE 4096

using namespace std;

void run(void * arg);
int service(ThreadPool * threadpool);

int main(){
    LOG_INIT;
    fun();
    //LOG_Info("日志服务启用");
    ThreadPool * threadpool = new ThreadPool();
    service(threadpool);
    return 0;
}
void run(void * arg){
    sleep(1);
    //cout<<"run:我被执行了"<<endl;
    int connfd = (long)arg;
    int len = 0;
    char  buff[512];
    //LOG_Info("执行线程");
    while(1)
    {
        len = recv(connfd, buff, MAXLINE, 0);
        buff[len] = '\0';
        if(len!=0)
        {
            printf("recv msg from client: %s\n", buff);
            close(connfd);
        }
        len =0;
        return;
    }
    std::cout<<"退出程序"<<std::endl;
    return;
}

int service(ThreadPool * threadpool){
    int sock, connfd;
    struct sockaddr_in servaddr;
    socklen_t ra_len = sizeof(struct sockaddr_in);
    char  buff[4096];
    int  n;    
    //流式套接字SOCK_STREAM(TCP)   数据包套接字SOCK_DGRAM(UDP)
    if( (sock = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
        //LOG_Error("create socket error");
        return 0;
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    //绑定IP INADDR_ANY表示任何ip
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //绑定端口
    servaddr.sin_port = htons(6666);
    if( bind(sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        //LOG_Error("bind socket error");
        return 0;
    }
    if( listen(sock, 10) == -1){
        return 0;
    }
    while(1){
        //cout<<"等待连接"<<endl;
        //accept会阻塞进程，知道有客户端连接上来为止
        if( (connfd = accept(sock, (struct sockaddr*)NULL, NULL)) == -1){
            continue;
        }
        threadpool->addTasks(run,(void *)(long)connfd);
    }
    close(sock);
    return 0;
}
