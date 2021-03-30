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
<hr>


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

<hr>

## [6-3 求解一个整数数组划分为两个子数组的问题（分治法） (10 分)](c.cpp)

已知由n(n≥2)个正整数构成的集合A＝{a
​k
​​ }(0≤k<n)，将其划分为两个不相交的子集A1和A2，元素个数分别为n1和n2,A1和 A2中的元素之和分别为S1和S2。设计一个尽可能高效的划分算法，满足|n1-n2|最小且|S1-S2|最大，算法返回|S1-S2|的结果。

函数接口定义：
```c++
int solve(int a[],int n);
```
裁判测试程序样例：
```c++
#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<malloc.h>
#define N 1000
using namespace std;

int Partition(int a[],int low,int high)
{ int i=low,j=high;
  int pivot;
  pivot=a[low]; 
  while(i<j)
  {
    while(i<j&&a[j]>=pivot) --j;
    a[i]=a[j];    
    while(i<j&&a[i]<=pivot) ++i;
    a[j]=a[i];
  }
  a[i]=pivot;
  return  i;
}
int solve(int a[],int n);
int main()
{
    int a[N],n;
    cin>>n;
    for(int i=0;i<n;i++) 
      cin>>a[i];
    cout<<solve(a,n); 
    return 0;
 } 

/* 请在这里填写答案 */
```

输入格式:

第一行输入集合中元素个数n，第二行输入n个集合元素。
```
9
1 3 5 7 9 2 4 6 8
```
输出格式:

输出|S1-S2|。
```
25
```
<hr>

## [6-4 不带头结点的单链表结点和（递归法） (10 分)](d.cpp)

不带头结点的单链表结点和（递归法）

函数接口定义：

```c++
int Sum(LinkList L);
```
裁判测试程序样例：
```c++
#include<iostream>
#define OK 1
#define ERROR 0
typedef int ElemType;
using namespace std;

typedef struct LNode {
    ElemType data;
    struct LNode *next; 
} LNode, *LinkList; 

void CreateList(LinkList &L, int n) {
    LinkList p;
    int length=1;
    L = new LNode;  
    cin>>L->data;
    L->next = NULL; 
    while (length<n) {
        p = new LNode; 
        cin >> p->data; 
        p->next = L->next;
        L->next = p; 
        length++;
    }
} 

int Sum(LinkList L);

int main() {
    LinkList L;
    ElemType e;
    int length; 
    cin >> length;
    CreateList(L,length);
    int x=Sum(L);
    cout<<x;
    return 0;
}

/* 请在这里填写答案 */
```

输入样例：

第一行输入一个数n，第二行输入n个数。
```
12
19 14 23 1 68 20 84 27 55 11 10 79
```
输出样例：
输出结点和。
```
411
```

<hr>

## [6-5 数组最大元素值（递归法） (10 分)](e.cpp)
数组最大元素值（递归法）

函数接口定义：
```c++
int fmax(int a[],int i);
```
裁判测试程序样例：
```c++
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100 

int fmax(int a[],int i);

int main() {
    int A[N],n,i; 
    cin >> n;
    for(i=0;i<n;i++)
        cin>>A[i];
    int x=fmax(A,n);
    cout<<x;
    return 0;
}

/* 请在这里填写答案 */
```
输入样例：

第一行输入一个数n，第二行输入n个数。
```
12
19 14 23 1 68 20 84 27 55 11 10 79
```
输出样例：

输出数组中的最大元素值。
```
84
```

<hr>

## [6-6 冒泡排序（递归法） (10 分)](f.cpp)

冒泡排序（递归法）

函数接口定义：
```c++
void BubbleSort(int a[],int n,int i);
```
裁判测试程序样例：
```c++
#include <iostream>
#define N 1000
using namespace std;

void BubbleSort(int a[],int n,int i);

void show(int A[],int n)
{
 int i;
 for(i=0;i<n;i++)
  if(i==0) 
   cout<<A[i];
  else
   cout<<" "<<A[i];
}

int main()
{
 int A[N];
 int i,n;
 cin>>n;
 for(i=0;i<n;i++)
   cin>>A[i];
 BubbleSort(A,n,0);
 show(A,n);
 return 0;
}

/* 请在这里填写答案 */
```
输入样例：

第一行输入一个数n，接下来输入n个数。
```
7
24 53 45 45 12 24 90
```
输出样例：

输出按升序排序的结果。
```
12 24 24 45 45 53 90
```
<hr>

## [6-7 查找第K小元素（分治法） (10 分)](g.cpp)

查找第K小元素（分治法）

函数接口定义：
```c++
int Kminselect(int a[],int s,int t,int k);
```
在a[s..t]序列中找第k小的元素 。

裁判测试程序样例：
```c++
#include <iostream>
#define N 1000
using namespace std;

int Kminselect(int a[],int s,int t,int k);

int main()
{
    int A[N],i,k,n;
    cin>>n;
    for(i=0;i<n;i++) 
      cin>>A[i];
    cin>>k;    
    cout<<Kminselect(A,0,n-1,k); 
    return 0;
 } 

/* 请在这里填写答案 */
```
输入样例：

第一行输入一个数n，第二行输入n个数，第三行输入一个数表示第K小元素
```
12
19 14 23 1 68 20 84 27 55 11 10 79
5
```
输出样例：

输出序列中第K小元素的值。
```
19
```

<hr>


## [6-8 二分搜索（分治法） (10 分)](h.cpp)

二分搜索（分治法）

函数接口定义：
```c++
int binsearch(int A[],int key,int low,int high);
```
裁判测试程序样例：
```c++
#include <iostream>
#include<algorithm>
#define N 1000
using namespace std;

int binsearch(int A[],int key,int low,int high);

int main()
{
    int n,i,A[N],key;
    cin>>n;
    for(i=0;i<n;i++) 
      cin>>A[i];
    cin>>key;
    cout<<binsearch(A,key,0,n-1);    
    return 0;
}
/* 请在这里填写答案 */
```

输入样例：

第一行输入一个数n，第二行输入n个数，第三行输入要查的值。
```
12
11 14 23 25 68 78 84 97 155 201 310 479
97
```
输出样例：

输出key在序列中的位置。
```
7
```

<hr>
