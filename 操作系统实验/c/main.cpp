#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAKEIN "takein" //对应进程的状态
#define WAIT "wait"
#define RUN "run"
#define FINISH "finish"
#define MAX 5 //进程数量
#define TRUE 1
#define FALSE 0

typedef struct pcd //进程结构体
{
    char processName[20];         //进程名称
    int arriveTime;               //进程到达时间
    int startTime;                //进程开始时间
    int endTime;                  //进程结束时间
    int runTime;                  //进程运行时间大小
    int turnOverTime;             //周转时间
    float userweightTurnOverTime; //带权周转时间
    char provessStatus[10];       //进程状态
    int runTimeed;                //进程已经运行的时间
    int bz;                       //第一次运行标志位
} pcd;

pcd pcds[MAX]; //进程数组
//pcd pcds[MAX] = {"A", 0, 4, 0, 0, 0, 0, 0};

int currentTime = 0;  //当前时间
int processIndex = 0; //进程编号
int cpuTime = 2;      //时间片大小
int size = MAX;   //进程数组中的有效值

void createPcbs() //进程的初始化函数，输入进程信息
{
    //freopen("input.txt", "r", stdin); // 以只读操作读文件，将输入有标准输入流重定向到input.txt
    printf("进程名\t到达时间\t运行时间\t\n");
    int index;
    for (index = 0; index < MAX; index++)
    {

        scanf("%s", pcds[index].processName);
        scanf("%d", &pcds[index].arriveTime);
        scanf("%d", &pcds[index].runTime);
        pcds[index].bz = 0;
        pcds[index].endTime = 0;
        pcds[index].startTime = 0;
        pcds[index].turnOverTime = 0;
        pcds[index].userweightTurnOverTime = 0;
        strcpy(pcds[index].provessStatus, TAKEIN);
        printf("%s \t %d    \t%d\n", pcds[index].processName, pcds[index].arriveTime,
               pcds[index].runTime);
    }
    fclose(stdin); //关闭标准输入流重定向
    printf("\n********************************************************\n");
   
}

void printfPcbsInfo() //打印所有进程的所有信息
{
    int index = 0;
    printf("当前时间为：%d时各进程的信息......\n\n", currentTime);
    printf("进程名\t到达时间\t运行时间\t开始时间\t结束时间\t周转时间\t带权周转时间\t状态\n");
    for (index = 0; index < MAX; index++)
    {
        printf("%s\t%8d\t%8d\t%8d\t%8d\t%8d\t%8.2f\t%4s\n",
               pcds[index].processName,
               pcds[index].arriveTime,
               pcds[index].runTime,
               pcds[index].startTime,
               pcds[index].endTime,
               pcds[index].turnOverTime,
               pcds[index].userweightTurnOverTime,
               pcds[index].provessStatus);
    }
}

void sortPcbs()
{ //按到达时间排序
    int index = 0, i, j;
    int minindex = 0, minvalue = 0;
    for (index = 0; index < MAX; index++)
    {
        minvalue = pcds[index].arriveTime;
        for (j = index; j < MAX; j++)
        {
            if (pcds[j].arriveTime < minvalue)
            {
                pcd temp = pcds[index];
                pcds[index] = pcds[j];
                pcds[j] = temp;
            }
        }
    }
}

void movePcbs(int pindex) //改变就绪队列的顺序
{
    int index = 0;
    pcd temp = pcds[pindex];
    for (index = pindex; index < size - 1; index++)
    {
        pcds[index] = pcds[index + 1];
    }
    pcds[size - 1] = temp;
}

void removeFromPcbs(int pindex)
{ //删除完成任务的进程
    movePcbs(pindex);
    strcpy(pcds[size - 1].provessStatus, FINISH); //更改完成进程的状态
    if (size == 1)
    {
        printfPcbsInfo(); //最后一项的输出
    }
    processIndex++;
    size--; //进程数组的逻辑大小减小一个
}

int proIsEnd(int pindex)
{ //判断一个进程是否完成
    int x = -1;
    if (pcds[pindex].runTimeed == pcds[pindex].runTime)
    {
        pcds[pindex].endTime = currentTime;
        pcds[pindex].turnOverTime = currentTime - pcds[pindex].arriveTime;                                //计算周转时间
        pcds[pindex].userweightTurnOverTime = (pcds[pindex].turnOverTime * (1.0)) / pcds[pindex].runTime; //计算带权周转时间
        removeFromPcbs(pindex);                                                                           //删除完成全部服务的进程
        return TRUE;
    }
    return x;
}

int runProcess(int pindex)
{ //指定时间片进程运行函数
    int i = 0;
    for (i = 0; i < cpuTime; i++)
    {
        currentTime++;
        strcpy(pcds[pindex].provessStatus, RUN); //更改进程的状态
        pcds[pindex].runTimeed++;                //进程运行时间加一
        if (pcds[pindex].bz == 0)
        {
            pcds[pindex].startTime = currentTime;
        }
        pcds[pindex].bz = 1;
        printfPcbsInfo(); //保证每个单位时间输出一次结果
        if (proIsEnd(pindex) == TRUE)
        { //判断进程时候执行完毕
            return 0;
        }
    }
    movePcbs(pindex);                           //执行玩一个进程后需要对进程数组进行重新排序
    strcpy(pcds[size - 1].provessStatus, WAIT); //对刚进行完的进程更改状态
    return 0;
}

void startProcess()
{ //开始执行程序
    int first = 0;
    while (1)
    {
        if (currentTime >= pcds[first].arriveTime)
        {
            runProcess(first);
        } //因为是按照队列的特征用数组实现的，所以每次执行的进程都是进程数组的第一个元素。
        else
        {
            movePcbs(first);
            strcpy(pcds[size - 1].provessStatus, WAIT);
        }
        if (processIndex == MAX) //判断进程数组是否全部执行完毕 。
            break;
    }
}

int main()
{
    createPcbs();   //初始化进程列表
    sortPcbs();     //按到达时间排序
    startProcess(); //开始轮转调度算法
    system("pause");
    return 0;
}
