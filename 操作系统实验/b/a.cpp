#include<windows.h>
#include<iostream>
using namespace std;
//声明全局变量
int buffer;	//缓冲池

// 定义两个线程函数Write()和Read()
// Read()、Write()函数分别使用VC++的P、V操作WaitForSingleObject()和ReleaseSemaphore()
DWORD WINAPI producer(LPVOID IpParameter);
DWORD WINAPI consumer(LPVOID IpParameter);

// 两个信号量，分别使用缓冲区buffer的两个资源：满和空

HANDLE empty;
HANDLE full;
//线程句柄
HANDLE pThread;	//producer线程句柄
HANDLE cThread;	//consumer线程句柄
int main()
{  
	// buffer清空
	buffer=0;
	// 创建信号量
	// empty 表示缓冲区buffer满，初始值为0，最大值为1
    // full 表示缓冲区buffer空，初始值为1，最大值为1
    empty=CreateSemaphore(NULL,1,1,NULL);
	full=CreateSemaphore(NULL,0,1,NULL);
	// 创建线程
   	pThread = CreateThread(NULL,0,producer,NULL,0,NULL);
	cThread = CreateThread(NULL,0,consumer,NULL,0,NULL);
	// 在子线程执行完前主线程不能退出，否则显示结果异常
	Sleep(1000);
	// 关闭句柄
    CloseHandle(pThread);
    CloseHandle(cThread);
	// 释放信号量
	CloseHandle(empty);
	CloseHandle(full);
}
// 线程1对应的p函数实体：缓冲区buffer写操作
DWORD WINAPI producer(LPVOID IpParameter)
	{
		for(int k=0;k<5;k++)
		{
			
			WaitForSingleObject(empty,INFINITE);	//P操作
			cout<<"\n生产者生产一个产品"<<endl;
			cout<<"\n把一个产品放入了空的缓冲区"<<endl;
			ReleaseSemaphore(full,1,NULL);	//v操作
		}
		return 0;
	}
// 线程2对应的V函数实体：缓冲区buffer读操作
	DWORD WINAPI consumer(LPVOID IpParameter)
	{
		for(int k=0;k<5;k++)
		{
			WaitForSingleObject(full,INFINITE);	//P操作
			cout<<"\n将缓冲区里的产品取出，放入消费产品里头"<<endl;
			cout<<"\n消费者消费一个产品"<<endl;
			ReleaseSemaphore(empty,1,NULL);	//V操作
			
		}
		return 0;
	}

