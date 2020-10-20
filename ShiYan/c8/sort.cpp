#include <iostream>
using namespace std;

void insertsort(int *a, int n) //O(n^2)
{

    for (int i = 1; i < n; i++) //a[0]已经有序，所以从1开始
    {
        int temp = a[i];
        int j = 0;

        for (j = i - 1; j >= 0; j--)
        {
            if (temp < a[j])
                a[j + 1] = a[j]; //挪动
            else
            {
                break;
            }
        }
        a[j + 1] = temp; //插入
    }
}

void insertsort_2(int *a, int n) //O(n^2)
{

    for (int i = 1; i < n; i++) //a[0]已经有序，所以从1开始
    {
        int temp = a[i];

        int low = 0;
        int high = i - 1;
        while (low <= high)
        {
            int m = (low + high) / 2;
            if (temp < a[m])
                high = m - 1; // 插入点在低半区
            else
                low = m + 1; // 插入点在高半区
        }
        int k = high + 1;
        int j = 0;
        for (j = i - 1; j >= k; j--)
        {
            a[j + 1] = a[j]; //挪动
        }
        a[k] = temp; //插入
    }
}

void Bubble_Sort(int a[], int n) // O(n ^ 2)
{
    for (int i = 1; i < n; ++i)              //比较的趟数
        for (int j = 0; j <= n - i - 1; ++j) //该趟起始从0开始到n-i-1结束，这个范围两两比较
                                             //
        {
            if (a[j] > a[j + 1]) //大数沉底
                swap(a[j], a[j + 1]);
        }
}

int onePartion(int *a, int left, int right)
{
    int pivot = a[left];

    int i = left;
    int j = right;

    while (i < j) // i == j 交叉，结束
    {
        while (i < j && a[j] > pivot)
            j--;
        swap(a[i], a[j]);

        while (i < j && a[i] < pivot)
            i++;
        swap(a[i], a[j]);
    }

    return j;
}

void quicksort(int *a, int left, int right)
{
    if (left >= right)
        return;

    int k = onePartion(a, left, right); //

    quicksort(a, left, k - 1);
    quicksort(a, k + 1, right);
}

int main()
{
    int a[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a) / 4;
    // Bubble_Sort(a, n);
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
    return 1;
}
