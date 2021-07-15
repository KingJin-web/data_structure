//直接复制PTA 上面的
#include <bits/stdc++.h>
using namespace std;
int n, *x, m = 1;
long num;
char a[80000][50];
bool check(int k)
{
    for (int j = 1; j < k; j++)
    {
        if (abs(k - j) == abs(x[j] - x[k]) || (x[j] == x[k]))
        {
            return false;
        }
    }
    return true;
}
void backtrack(int k)
{
    int i;
    if (k > n)
    {
        num++;
        for (i = 1; i <= n; i++)
        {
            a[m][x[i]] = 'Q';
            m++;
        }
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            x[k] = i;
            if (check(k))
            {
                backtrack(k + 1);
            }
        }
    }
}
int main()
{
    memset(a, '.', sizeof(a));
    cin >> n;
    x = new int[n + 1];
    backtrack(1);
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j];
            if (j < n)
                cout << " ";
        }
        cout << endl;
        if (i % n == 0 && i != m - 1)
        {
            cout << endl;
        }
    }
    if (num == 0)
        cout << "None";
    delete[] x;
    return 0;
}
