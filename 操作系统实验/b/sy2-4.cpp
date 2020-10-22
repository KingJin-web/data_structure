#include<windows.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// 定义两个线程函数Write()和Read()
// Read()、Write()函数分别使用VC++的P、V操作WaitForSingleObject()和ReleaseSemaphore()
DWORD WINAPI Write(LPVOID lpParameter);
DWORD WINAPI Read(LPVOID lpParameter);
// 缓冲区资源
unsigned char buffer;
// 两个信号量，分别使用缓冲区buffer的两个资源：满和空
// semaphore1 表示缓冲区buffer满，初始值为0，最大值为1
// semaphore2 表示缓冲区buffer空，初始值为1，最大值为1
HANDLE semaphore1;
HANDLE semaphore2;
//线程句柄
 HANDLE hThread1;
 HANDLE hThread2;
void main()
{  
	// buffer清空
	buffer=' ';
	// 创建信号量
	semaphore1=CreateSemaphore(NULL,0,4,NULL);
    semaphore2=CreateSemaphore(NULL,4,4,NULL);
	// 创建线程
    hThread1=CreateThread(NULL,0,Write,NULL,4,NULL);
    hThread2=CreateThread(NULL,4,Read,NULL,0,NULL);
	// 在子线程执行完前主线程不能退出，否则显示结果异常
	Sleep(10000);
	// 关闭句柄
    CloseHandle(Write);
    CloseHandle(Read);
	// 释放信号量
	CloseHandle(semaphore1);
	CloseHandle(semaphore2);
}
// 线程1对应的p函数实体：缓冲区buffer写操作
DWORD WINAPI Write(LPVOID lpParameter)
{
	//unsigned char str[6]="Hello";
	int i=0;
    for (i=0;i<12;i++)
	{
		// 等待缓冲区空
		WaitForSingleObject( semaphore2, INFINITE );
		// 缓冲区空时，向缓冲区写入数据
		cout<<"生产"<<endl;
		// 通知缓冲区满
		ReleaseSemaphore( semaphore1, 4, NULL ); //满则加一
	}
    return 0;
}
// 线程2对应的V函数实体：缓冲区buffer读操作
DWORD WINAPI Read(LPVOID lpParameter)
{
	int i=1;

	for (i=1;i<=12;i++)
	{
		// 等待缓冲区满
		WaitForSingleObject( semaphore1, INFINITE);
		// 从缓存buffer获取数据
		
		// 输出从缓冲区buffer取出的数据
		cout<<"消费"<<endl;
    	// 通知缓冲区空 读出来就空了，则加一
		ReleaseSemaphore( semaphore2, 4, NULL );
	}
	// 回车换行
    cout<<endl;
    return 0;  
}
