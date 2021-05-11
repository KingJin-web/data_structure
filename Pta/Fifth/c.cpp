#include <bits/stdc++.h>
using namespace std;

int F(int n, int m)
{
    if (n <= 2)
        return 1;
    if (m == 1 || n == m)
        return 1;
    else
        return F(n - 1, m - 1) + m * F(n - 1, m);
}
int main(int argc, char const *argv[])
{
    int n;
    int result = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        result = result + F(n, i);
    }

    printf("%d",result);
    
    return 0;
}
