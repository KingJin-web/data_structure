#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int max1(int a, int b, int c)
{
    a = a > b ? a : b;
    a = a > c ? a : c;
    return a;
}
int c[100010][11];
int main()
{
    int n, a, b;
    while (scanf("%d", &n) && n != 0)
    {
        int m = 0;
        memset(c, 0, sizeof(c));
        while (n--)
        {
            scanf("%d%d", &a, &b);
            c[b][a]++;
            if (m < b)
                m = b;
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 1; j <= 9; j++)
                c[i][j] = c[i][j] + max1(c[i + 1][j - 1], c[i + 1][j], c[i + 1][j + 1]);
            c[i][0] = c[i][0] + max(c[i + 1][0], c[i + 1][1]);
            c[i][10] = c[i][10] + max(c[i + 1][9], c[i + 1][10]);
        }
        printf("%d\n", c[0][5]);
    }
    return 0;
}