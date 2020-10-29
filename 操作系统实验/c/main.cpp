#include <iostream>
using namespace std;
int id[100];             //id
double send1[100];        //提交时间
double proccess[100];    //运行时间
double start[100];       //开始时间
double end1[100];         //结束时间
double zhouzhuan[100];   //周转时间
double dqzhouzhuan[100]; // 带权周转时间

double avgzhouzhuan;   //平均周转时间
double avgdqzhouzhuan; //带权平均周转时间
static int n;
void input() //输入进程
{
    cout << "请输入进程数:" << endl;
    cin >> n;
    //初始化数组
    for (int i = 0; i < n; i++)
    {
        id[i] = i + 1;
        send1[i] = 0;
        proccess[i] = 0;
        start[i] = 0;
        end1[i] = 0;
        zhouzhuan[i] = 0;
        dqzhouzhuan[i] = 0;
    }
}

void output() //输出进程
{
    for (int i = 0; i < n; i++)
    {

        cout << "id:" << id[i] << " "
             << "提交时间:" << send1[i] << " "
             << "运行时间:" << proccess[i] << " "
             << "开始时间:" << start[i] << " "
             << "结束时间:" << end1[i] << " "
             << "周转时间:" << zhouzhuan[i] << " "
             << "带权周转时间:" << dqzhouzhuan[i] << endl;
    }

    cout << "平均周转时间:" << avgzhouzhuan << endl;
    cout << "带权平均周转时间:" << avgdqzhouzhuan << endl;
}

void inputtime() //输入提交运行时间
{
    int k, j;
    cout << "请输入提交时间" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        send1[i] = k;
    }
    cout << "请输入运行时间" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> j;
        proccess[i] = j;
    }
}

void paixu()
{ //用冒泡排序按提交时间排序
    int i1;
    double i2;
    double i3;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (send1[i] > send1[j])
            {
                i2 = send1[i]; //提交时间交换
                send1[i] = send1[j];
                send1[j] = i2;

                i3 = proccess[i]; //运行时间交换
                proccess[i] = proccess[j];
                proccess[j] = i3;

                i1 = id[i];
                id[i] = id[j];
                id[j] = i1;
            }
        }
    }
}

void fcfs() //fcfs算法实现
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            start[i] = send1[i];
            end1[i] = start[i] + proccess[i];
            zhouzhuan[i] = end1[i] - send1[i];
            avgzhouzhuan = avgzhouzhuan + zhouzhuan[i];
            dqzhouzhuan[i] = zhouzhuan[i] / proccess[i];
            avgdqzhouzhuan = avgdqzhouzhuan + dqzhouzhuan[i];
        }
        else
        {
            start[i] = end1[i - 1];
            if (start[i] < send1[i])
            {
                start[i] = send1[i];
            }
            else
            {
                start[i] = end1[i - 1];
            }
            end1[i] = start[i] + proccess[i];
            zhouzhuan[i] = end1[i] - send1[i];
            avgzhouzhuan = avgzhouzhuan + zhouzhuan[i];
            dqzhouzhuan[i] = zhouzhuan[i] / proccess[i];
            avgdqzhouzhuan = avgdqzhouzhuan + dqzhouzhuan[i];
        }
        avgzhouzhuan = avgzhouzhuan / n;
        avgdqzhouzhuan = avgdqzhouzhuan / n;
    }
}

int main()
{
    input();
    inputtime();
    paixu();
    fcfs();
    output();
}
