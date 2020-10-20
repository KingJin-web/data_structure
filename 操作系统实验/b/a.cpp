// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//


#include "stdio.h"
#include "windows.h"
#include <iostream>
using namespace std;

int i = 0;
DWORD WINAPI FunProc(LPVOID lpParameter);

DWORD WINAPI FunProc(LPVOID lpParameter)
{
    for (; i < 10; i++)
    {
        if (!(i % 10))
            cout << endl;
        else
            cout << i << endl;
    }
    return 0;
}

int main()
{
    cout << i << endl;
    HANDLE hThread;
    hThread = CreateThread(NULL, 0, FunProc, NULL, 0, NULL);
    DWORD dwRet = WaitForSingleObject(hThread, 1);
    if (dwRet == WAIT_OBJECT_0)
    {
        cout<< "创建的线程执行结束" << endl;
    }
    if (dwRet == WAIT_TIMEOUT)
    {
        cout<< "等待超时" << endl;
    }
    if (dwRet == WAIT_ABANDONED)
    {
        cout<< "Abandoned" << endl;
    }
    CloseHandle(hThread);

}