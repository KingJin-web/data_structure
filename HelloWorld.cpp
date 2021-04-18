#include <stdio.h>
#include <iostream>
using namespace std;
#define M 3
#define N 20
#define Myprintf printf("\n") /*表格控制*/
typedef struct page
{
	int num;  /*记录页面号*/
	int time; /*记录调入内存时间*/
} Page;		  /* 页面逻辑结构，结构为方便算法实现设计*/

Page b[M];		/*内存单元数*/
int c[M][N];	/*暂保存内存当前的状态：缓冲区*/
int queue[100]; /*记录调入队列*/
int K;			/*调入队列计数变量*/

/*初始化内存单元、缓冲区*/
void Init(Page *b, int c[M][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		b[i].num = -1;
		b[i].time = N - i - 1;
	}
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			c[i][j] = -1;
}

/*取得在内存中停留最久的页面,默认状态下为最早调入的页面*/
int GetMax(Page *b)
{
	int i;
	int max = -1;
	int tag = 0;
	for (i = 0; i < M; i++)
	{
		if (b[i].time > max)
		{
			max = b[i].time;
			tag = i;
		}
	}
	return tag;
}

/*判断页面是否已在内存中*/
int Equation(int fold, Page *b)
{
	int i;
	for (i = 0; i < M; i++)
	{
		if (fold == b[i].num)
			return i;
	}
	return -1;
}
/*LRU核心部分*/
void Lru(int fold, Page *b)
{
	int i;
	int val;
	val = Equation(fold, b);
	if (val >= 0) //传入已在内存中的 下标更新为0
	{
		b[val].time = 0;
		for (i = 0; i < M; i++)
			if (i != val)
				b[i].time++;
	}
	else
	{
		queue[++K] = fold; /*记录调入页面*/
		val = GetMax(b);
		b[val].num = fold;
		b[val].time = 0;
		for (i = 0; i < M; i++)
			if (i != val)
				b[i].time++;
	}
}
