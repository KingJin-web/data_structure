#include <iostream>
#define N 1000
using namespace std;

void BubbleSort(int a[], int n, int i);

void show(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (i == 0)
            cout << A[i];
        else
            cout << " " << A[i];
}

int main()
{
    int A[N];
    int i, n;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> A[i];
    BubbleSort(A, n, 0);
    show(A, n);
    return 0;
}

/* 请在这里填写答案 */
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(int a[], int n, int i)
{
    if (1 == n)
    {

        return;
    }

    for (i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            swap(&a[i], &a[i + 1]);
    }

    BubbleSort(a, n - 1, 0);
}