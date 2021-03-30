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