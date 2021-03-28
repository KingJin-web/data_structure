#include <iostream>
#define N 1000
using namespace std;

int Kminselect(int a[], int s, int t, int k);

int main()
{
    int A[N], i, k, n;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> A[i];
    cin >> k;
    cout << Kminselect(A, 0, n - 1, k);
    return 0;
}

/* 请在这里填写答案 */
int Kminselect(int a[], int s, int t, int k)
{
    int i = s, j = t;
    int tmp;
    if (s < t)
    {
        tmp = a[s];
        while (i != j)
        {
            while (j > i && a[j] >= tmp)
                j--;
            a[i] = a[j];
            while (i < j && a[i] <= tmp)
                i++;
            a[j] = a[i];
        }
        a[i] = tmp;
        if (k - 1 == i)
            return a[i];
        else if (k - 1 < i)
            return Kminselect(a, s, i - 1, k);
        else
            return Kminselect(a, i + 1, t, k);
    }
    else if (s == t && s == k - 1)
        return a[k - 1];
}