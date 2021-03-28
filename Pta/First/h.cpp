#include <iostream>
#include <algorithm>
#define N 1000
using namespace std;

int binsearch(int A[], int key, int low, int high);

int main()
{
    int n, i, A[N], key;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> A[i];
    cin >> key;
    cout << binsearch(A, key, 0, n - 1);
    return 0;
}
/* 请在这里填写答案 */


int BinSrch(int a[], int i, int l, int x)
{
    while (i <= l)
    {
        int mid = (i + l) / 2;
        if (x == a[mid])
            return mid;
        else if (x > a[mid])
            i = mid + 1;
        else if (x < a[mid])
            l = mid - 1;
    }
    return 0;
}
int binsearch(int a[], int key, int low, int high)
{
    return BinSrch(a,low,high,key);
}