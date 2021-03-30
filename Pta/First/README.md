# 算法设计与分析第一作业：递归
## [6-1 归并排序(递归法) (10 分)](a.cpp)

本题要求实现二路归并排序中的归并操作，待排序列的长度1<=n<=1000。

函数接口定义：
```c++
void Merge(SqList L,int low,int m,int high);
```
其中L是待排序表，使排序后的数据从小到大排列。

裁判测试程序样例：
```c++
#include <iostream>
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
using namespace std;
typedef  int  ElemType;
typedef struct
{
 ElemType *r;
 int  length;
}SqList;

void Create_Sq(SqList &L);//建立待排序列，实现细节隐藏
void Merge(SqList L,int low,int m,int high); 

void MSort(SqList L,int low,int high)
{  /*用分治法进行二路归并排序*/ 
  int mid;
  if(low<high){/*区间长度大于1*/
    mid=(low+high)/2; /*分解*/
    MSort(L,low,mid); /*递归地对low到mid序列排序 */
    MSort(L,mid+1,high); /*递归地对mid+1到high序列排序 */ 
    Merge(L,low,mid,high);/*归并*/ 
 } 
} 

int main()
{
  SqList L;
  int i;
  L.r=new ElemType[MAXSIZE+1];
  L.length=0;
  Create_Sq(L);
  MSort(L,1,L.length);
  for(i=1;i<=L.length;i++)
    if(i==1) cout<<L.r[i];
    else  cout<<" "<<L.r[i];

  return 0;
}
/* 请在这里填写答案 */
```
输入样例：
第一行输入关键字个数(输入的值不大于 MAXSIZE)，接下来输入n个关键字。
```
7
24 53 45 45 12 24 90
```

输出样例：
输出由小到大的有序序列，每一个关键字之间由空格隔开。
```
12 24 24 45 45 53 90
```

## [6-2 求解逆序数问题（分治法） (10 分)](b.cpp)
设a1, a2,…, an是集合{1, 2, …, n}的一个排列，如果i<j且ai>aj，则序偶(ai, aj)称为该排列的一个逆序。例如，2, 3, 1有两个逆序：(3, 1)和(2, 1)。设计算法统计给定排列中含有逆序的个数。

函数接口定义：

```c++
void Merge(int a[],int low,int mid,int high);
void mergesort(int a[],int low,int high);
```

用二路归并法求逆序数；

裁判测试程序样例：
```c++
#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<malloc.h>
#define N 1000
using namespace std;
int ans=0;

void Merge(int a[],int low,int mid,int high);
void mergesort(int a[],int low,int high);

int main()
{
    int a[N],n;
    cin>>n;
    for(int i=0;i<n;i++) 
      cin>>a[i];
    mergesort(a,0,n-1);
    cout<<ans; 
    return 0;
 } 

/* 请在这里填写答案 */
```


输入格式:

第一行输入集合中元素个数n，第二行输入n个集合元素。
```
3
2 3 1
```
输出格式:

含有逆序的个数。
```
2
```
