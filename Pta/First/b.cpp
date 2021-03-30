#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <malloc.h>
#define N 1000
using namespace std;
int ans = 0;

void Merge(int a[], int low, int mid, int high);
void mergesort(int a[], int low, int high);
void printArray(int *a, int len);

int main()
{
    int a[N], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergesort(a, 0, n - 1);
    cout << ans;
    return 0;
}

/* 请在这里填写答案 */
void Merge(int r[], int p[], int h, int m, int t);


void Merge(int r[], int p[], int h, int m, int t)
{

    int i = h, j = m + 1, k = 0;
    while (i <= m && j <= t)
    {
        if (r[i] <= r[j])
            p[k++] = r[i++];
        else
        {
            p[k++] = r[j++];
            ans += m + 1 - i;
        }
    };

    while (i <= m)
        p[k++] = r[i++];

    while (j <= t)
    {
        p[k++] = r[j++];
    }
}

void MergeSort(int r[], int h, int t)
{ //对序列h-t进行归并排列
    if (h >= t)
        return;
    else
    {
        int n = t - h + 1;
        int *p = new int[n];  //临时数组
        int m = (h + t) >> 1; //序列h-t中数
        MergeSort(r, h, m);
        MergeSort(r, m + 1, t);
        Merge(r, p, h, m, t);
        for (int i = 0; i < n; i++)
        {
            r[h + i] = p[i];
        }
        delete[] p;
    }
}

void mergesort(int a[], int low, int high)
{
    MergeSort(a, low, high);
}
void Merge(int a[], int low, int mid, int high)
{
}

/* 6 - 2 求解逆序数问题（分治法）(10 分)
        设a1,
    a2,…, an是集合{1, 2, …, n} 的一个排列，如果i<j且ai> aj，则序偶(ai, aj) 称为该排列的一个逆序。例如，2, 3, 1有两个逆序：(3, 1)和(2, 1)。设计算法统计给定排列中含有逆序的个数。

    函数接口定义： void Merge(int a[], int low, int mid, int high);
void mergesort(int a[], int low, int high);
用二路归并法求逆序数；




 */