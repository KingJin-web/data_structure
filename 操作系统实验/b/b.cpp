#include <windows.h>
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

// 线程1对应的p函数实体：缓冲区buffer写操作
DWORD WINAPI Write(LPVOID lpParameter)
{
    unsigned char str[6] = "Hello";
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        // 等待缓冲区空
        WaitForSingleObject(semaphore2, INFINITE);
        // 缓冲区空时，向缓冲区写入数据
        buffer = str[i];
        // 通知缓冲区满
        ReleaseSemaphore(semaphore1, 1, NULL);
    }
    return 0;
}
// 线程2对应的V函数实体：缓冲区buffer读操作
DWORD WINAPI Read(LPVOID lpParameter)
{
    int i = 1;
    unsigned char c;
    for (i = 1; i <= 5; i++)
    {
        // 等待缓冲区满
        WaitForSingleObject(semaphore1, INFINITE);
        // 从缓存buffer获取数据
        c = buffer;
        // 输出从缓冲区buffer取出的数据
        cout << c;
        // 通知缓冲区空
        ReleaseSemaphore(semaphore2, 1, NULL);
    }
    // 回车换行
    cout << endl;
    return 0;
}
int main()
{
    // buffer清空
    buffer = ' ';
    // 创建信号量
    semaphore1 = CreateSemaphore(NULL, 0, 1, NULL);
    semaphore2 = CreateSemaphore(NULL, 1, 1, NULL);
    // 创建线程
    hThread1 = CreateThread(NULL, 0, Write, NULL, 0, NULL);
    hThread2 = CreateThread(NULL, 0, Read, NULL, 0, NULL);
    // 在子线程执行完前主线程不能退出，否则显示结果异常
    //Sleep(10000);
    // 关闭句柄
    CloseHandle(Write);
    CloseHandle(Read);
    // 释放信号量
    CloseHandle(semaphore1);
    CloseHandle(semaphore2);
}