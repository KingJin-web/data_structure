
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <malloc.h>
#define N 1000
using namespace std;

int Partition(int a[], int low, int high)
{
    int i = low, j = high;
    int pivot;
    pivot = a[low];
    while (i < j)
    {
        while (i < j && a[j] >= pivot)
            --j;
        a[i] = a[j];
        while (i < j && a[i] <= pivot)
            ++i;
        a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}
int solve(int a[], int n);
int main()
{
    int a[N], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(a, n);
    return 0;
}

/* 请在这里填写答案 */
int solve(int a[], int n)
{
    int pivotkey, low = 0, low0 = 0, high = n - 1, high0 = n - 1, flag = 1, k = n / 2, i;
    int s1 = 0, s2 = 0;
    while (flag)
    {
        pivotkey = a[low]; //选择枢轴
        while (low < high) //基于枢轴对数据进行划分
        {
            while (low < high && a[high] >= pivotkey)
                --high;
            if (low != high)
                a[low] = a[high];
            while (low < high && a[low] <= pivotkey)
                ++low;
            if (low != high)
                a[high] = a[low];
        } //end of while(low<high)
        a[low] = pivotkey;
        if (low == k - 1) //如果枢轴是第n/2小元素，划分成功
            flag = 0;
        else //否则继续划分
        {
            if (low < k - 1)
            {
                low0 = ++low;
                high = high0;
            }
            else
            {
                high0 = --high;
                low = low0;
            }
        }
    }
    for (i = 0; i < k; i++)
        s1 += a[i];
    for (i = k; i < n; i++)
        s2 += a[i];
    return s2 - s1;
}