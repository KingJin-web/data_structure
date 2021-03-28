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

int tmp[N];
void merge(int *a, int low, int mid, int high)
{
    int i;
    int j;
    int k;

    for (i = low; i <= high; i++)
    {
        tmp[i] = a[i];
    }

    j = low;
    k = mid + 1;
    for (i = low; i <= high && j <= mid && k <= high;)
    {
        if (tmp[j] <= tmp[k])
        {
            a[i++] = tmp[j++];
        }
        else
        {
            a[i++] = tmp[k++];
        }
    }

    while (j <= mid)
        a[i++] = tmp[j++];
    while (k <= high)
        a[i++] = tmp[k++];
}

void mergeSort(int *a, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) >> 1;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void printArray(int *a, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

