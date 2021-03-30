#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
using namespace std;
typedef int ElemType;
typedef struct
{
    ElemType *r;
    int length;
} SqList;

void Create_Sq(SqList &L); //建立待排序列，实现细节隐藏
void Merge(SqList L, int low, int m, int high);

void MSort(SqList L, int low, int high)
{ /*用分治法进行二路归并排序*/
    int mid;
    if (low < high)
    {                             /*区间长度大于1*/
        mid = (low + high) / 2;   /*分解*/
        MSort(L, low, mid);       /*递归地对low到mid序列排序 */
        MSort(L, mid + 1, high);  /*递归地对mid+1到high序列排序 */
        Merge(L, low, mid, high); /*归并*/
    }
}

int main()
{
    SqList L;
    int i;
    L.r = new ElemType[MAXSIZE + 1];
    L.length = 0;
    Create_Sq(L);
    MSort(L, 1, L.length);
    for (i = 1; i <= L.length; i++)
        if (i == 1)
            cout << L.r[i];
        else
            cout << " " << L.r[i];

    return 0;
}
/* 请在这里填写答案 */


void Merge(SqList L, int low, int m, int high)
{
    int b[1001];
    int p1 = low, p2 = m + 1;
    for (int i = low; i <= high; i++)
    {
        if ((p1 <= m) && ((p2 > high) || (L.r[p1] < L.r[p2])))
        {
            b[i] = L.r[p1++];
        }
        else
        {
            b[i] = L.r[p2++];
        }
    }
    for (int i = low; i <= high; i++)
        L.r[i] = b[i];
}
/* 本题要求实现二路归并排序中的归并操作，待排序列的长度1<=n<=1000。

函数接口定义：
void Merge(SqList L,int low,int m,int high);
其中L是待排序表，使排序后的数据从小到大排列。

输入样例：
第一行输入关键字个数(输入的值不大于 MAXSIZE)，接下来输入n个关键字。

7
24 53 45 45 12 24 90
输出样例：
输出由小到大的有序序列，每一个关键字之间由空格隔开。

12 24 24 45 45 53 90
 */
