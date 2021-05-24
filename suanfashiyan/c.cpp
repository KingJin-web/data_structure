#include <iostream>
#include <cstring>
using namespace std;
int T1(int[], int);
int T2(int[], int);
int T1(int a[], int num)
{
    int localSum = 0;
    int b = 0;
    for (int i = 0; i < num; i++)
    {
        if (b > 0)
            b += a[i];
        else
            b = a[i];
        if (b > localSum)
            localSum = b;
    }
    return localSum;
}

int T2(int a[], int n)
{
    int dp[100001];
    dp[0] = 100000;
    dp[1] = a[1];
    int i, j, s = 1, l, r, mid, ans;
    for (i = 2; i <= n; i++)
    {
        if (a[i] <= dp[s])
        {
            s++;
            dp[s] = a[i];
        }
        else
        {
            l = 0;
            r = s;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (dp[mid] >= a[i])
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            dp[ans + 1] = a[i];
        }
    }
    return s;
}

int T4()
{

    int t, n, x[102][102];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                scanf("%d", &x[i][j]);
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                x[i][j] = x[i][j] + max(x[i + 1][j], x[i + 1][j + 1]);
        printf("%d\n", x[0][0]);
    }
    return 0;
}
int main()
{
    int arr[] = {1, -1, 2, 2, 3, -3, 4, -4};
    int n = sizeof(arr) / sizeof(int);
    cout << T1(arr, n) << endl;

    int arr2[] = {389, 207, 155, 300, 299, 170, 158, 65};
    int n2 = sizeof(arr2) / sizeof(int);
    cout << T2(arr2, n2) << endl;

    T4();
    /*
1
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/
}