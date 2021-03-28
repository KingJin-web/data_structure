#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define processnum 5  //进程数
#define resourcenum 3 //资源数

int Available[resourcenum] = {3, 3, 2}; //可利用资源
int Max[processnum][resourcenum] = {7, 5, 3,
                                    3, 2, 2,
                                    9, 0, 2,
                                    2, 2, 2,
                                    4, 3, 3}; //max矩阵
int Allocation[processnum][resourcenum] = {0, 1, 0,
                                           2, 0, 0,
                                           3, 0, 2,
                                           2, 1, 1,
                                           0, 0, 2}; //分配矩阵
int Need[processnum][resourcenum];                   //
bool Finish[processnum];

int request[resourcenum] = {0, 0, 0}; //需求资源

int WORK[resourcenum]; //工作向量
int temp[processnum];

void init()
{
    cout << "请输入进程数和当前可用资源数目";

    cout << "请输入当前可用资源";
    for (int i = 0; i < resourcenum; i++)
    {
        cin >> Available[i];
    }

    cout << "请输入Max矩阵";
    for (int i = 0; i < processnum; i++)
    {
        for (int j = 0; j < resourcenum; j++)
        {
            cin >> Max[i][j];
        }
    }

    cout << "请输入Allocation矩阵";
    for (int i = 0; i < processnum; i++)
    {
        for (int j = 0; j < resourcenum; j++)
        {
            cin >> Allocation[i][j];
        }
    }

    cout << "请输入Need矩阵";
    for (int i = 0; i < processnum; i++)
    {
        for (int j = 0; j < resourcenum; j++)
        {
            cin >> Need[i][j];
        }
    }
}

void need()
{
    for (int i = 0; i < processnum; i++)
    {
        for (int j = 0; j < resourcenum; j++)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
}

void show()
{
    cout << "当前资源剩余";
    for (int i = 0; i < resourcenum; i++)
    {
        cout << Available[i] << " ";
    }

    cout << endl;
    cout << "ID"
         << "       "
         << "Max"
         << "          "
         << "Allocation"
         << "         "
         << "Need"
         << "         " << endl;
    for (int i = 0; i < processnum; i++)
    {
        printf(" P%d\t", i);
        for (int j = 0; j < resourcenum; j++)
        {
            cout << Max[i][j] << " ";
        }
        printf("\t\t");
        for (int j = 0; j < resourcenum; j++)
        {
            cout << Allocation[i][j] << " ";
        }
        printf("\t\t");
        for (int j = 0; j < resourcenum; j++)
        {
            cout << Need[i][j] << " ";
        }
        cout << endl;
    }
}

int safe() //在假定分配资源的情况下检查系统的安全性
{
    //temp[]用来记录进程安全执行的顺序
    int i, j, m, k = 0, count;

    for (i = 0; i < processnum; i++)
    {
        Finish[i] = false;
    }

    for (j = 0; j < resourcenum; j++)
    {
        WORK[j] = Available[j]; //把可利用资源数赋给WORK[]
    }

    for (i = 0; i < processnum; i++)
    {

        count = 0;
        for (j = 0; j < resourcenum; j++)
        {
            if (Finish[i] == false && Need[i][j] <= WORK[j])
                count++;
        }
        if (count == resourcenum) //当进程各类资源都满足NEED<=WORK时
        {
            for (m = 0; m < resourcenum; m++)
            {
                WORK[m] = WORK[m] + Allocation[i][m];
            }
            Finish[i] = true;
            temp[k] = i; //记录下满足条件的进程
            k++;
            if (i == 4)
            {
                i = -1;
            }
        }
    }

    for (i = 0; i < processnum; i++)
    {
        if (Finish[i] == false)
        {
            printf("系统不安全!!!本次资源申请不成功!!!\n");
            return 1;
        }
    }

    printf("\n");
    printf("经安全性检查，系统安全，本次分配成功。\n");
    printf("\n");
    printf("本次安全序列：");

    for (i = 0; i < processnum; i++) //打印安全系统的进程调用顺序
    {
        printf("进程");
        printf("%d", temp[i]);
        if (i < processnum - 1)
            printf("->");
    }
    printf("\n");
    return 0;
}

void blank(int k)
{
    int s = k;
    cout << "请输入申请资源";
    for (int i = 0; i < resourcenum; i++) //输入申请资源
    {
        cin >> request[i];
    }
    int count = 0;
    int count1 = 0;
    for (int i = 0; i < resourcenum; i++) //判断need
    {
        if (request[i] <= Need[s][i])
        {
            count++;
        }
    }

    for (int i = 0; i < resourcenum; i++) //判断Available
    {
        if (request[i] <= Available[i])
        {
            count1++;
        }
    }

    if (count == resourcenum && count1 == resourcenum) //如果满足条件，开始分配资源
    {

        for (int i = 0; i < resourcenum; i++)
        {
            Available[i] -= request[i];
        }

        for (int i = 0; i < resourcenum; i++)
        {
            Allocation[s][i] += request[i];
        }

        for (int i = 0; i < resourcenum; i++)
        {
            Need[s][i] -= request[i];
        }
    }
}

int main()
{
    int s;
    int k;
    need();
    show();
    safe();
    show();
    cout << "请输入你要请求的进程";
    cin >> k;
    blank(k);
    s = safe();
    if (s == 0)
    {
        show();
    }
    else
    {
        for (int i = 0; i < resourcenum; i++)
        {
            Available[i] += request[i];
        }

        for (int i = 0; i < resourcenum; i++)
        {
            Allocation[s][i] -= request[i];
        }

        for (int i = 0; i < resourcenum; i++)
        {
            Need[s][i] += request[i];
        }
    }

    return 0;
}