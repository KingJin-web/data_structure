
#include <iostream>
#include <algorithm>
#include<cstring>
#define N 1000
using namespace std;

void maxmin(int A[], int &e_max, int &e_min, int low, int high);

int main()
{
    int A[N], i, e_max, e_min, n;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> A[i];
    maxmin(A, e_max, e_min, 0, n - 1);
    cout << e_max << " " << e_min;
    return 0;
}

/* 注释max */
int max(int a, int b)
{
    return (a > b) ? a : b;
}
/* 注释min */
int min(int a, int b)
{
    return (a < b) ? a : b;
}
/* 注释maxmin */
void maxmin(int A[], int &e_max, int &e_min, int low, int high)
{
    int mid, x1, y1, x2, y2;
    if (high - low <= 1)
    { //<=,可能为1个
        if (A[high] > A[low])
        {
            e_max = A[high];
            e_min = A[low];
        }
        else
        {
            e_max = A[low];
            e_min = A[high];
        }
    } //特征1：小到容易求解
    else
    {
        mid = (low + high) / 2;      //特征2：可分解　
        maxmin(A, x1, y1, low, mid); //特征4：子问题独立
        maxmin(A, x2, y2, mid + 1, high);
        e_max = max(x1, x2); //特征3：可合并
        e_min = min(y1, y2);
    }
}

void FindMinMax(int *Array, int left, int right, int *min, int *max)
{
    if ((right - left) == 1)

    {
        *max = Array[left];

        *min = Array[right];
        if (Array[left] < Array[right])
        {
            *max = Array[right];
            *min = Array[left];
        }
    }
    else if ((right - left) == 0)

    {
        *max = *min = Array[left];
    }
    else
    {
        int min1, min2, max1, max2;
        FindMinMax(Array, left, (right - left) / 2 + left, &min1, &max1);
        FindMinMax(Array, (right - left) / 2 + 1 + left, right, &min2, &max2);
        (min1 > min2) ? *min = min2 : *min = min1;
        (max1 > max2) ? *max = max1 : *max = max2;
    }
}