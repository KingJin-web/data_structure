#include <bits/stdc++.h>
using namespace std;
int sum[325], l[237250], r[237250], u[237250], d[237250], c[237250], mplist[730][325], o[730], num, ans[10][10];
void remove(int x)
{
    int i, i1;
    l[r[x]] = l[x];
    r[l[x]] = r[x];
    for (i = d[x]; i != x; i = d[i])
    {
        for (i1 = r[i]; i1 != i; i1 = r[i1])
        {
            u[d[i1]] = u[i1];
            d[u[i1]] = d[i1];
            sum[c[i1]]--;
        }
    }
}
void resume(int x)
{
    int i, i1;
    r[l[x]] = x;
    l[r[x]] = x;
    for (i = d[x]; i != x; i = d[i])
    {
        for (i1 = r[i]; i1 != i; i1 = r[i1])
        {
            u[d[i1]] = i1;
            d[u[i1]] = i1;
            sum[c[i1]]++;
        }
    }
}
int dfs()
{
    int i, i1, x, min;
    if (r[0] == 0)
    {
        return 1;
    }
    min = 1000000007;
    for (i = r[0]; i != 0; i = r[i])
    {
        if (sum[i] < min)
        {
            min = sum[i];
            x = i;
        }
    }
    remove(x);
    for (i = d[x]; i != x; i = d[i])
    {
        o[num] = (i - 1) / 324;
        num++;
        for (i1 = r[i]; i1 != i; i1 = r[i1])
        {
            remove(c[i1]);
        }
        if (dfs() == 1)
        {
            return 1;
        }
        for (i1 = l[i]; i1 != i; i1 = l[i1])
        {
            resume(c[i1]);
        }
        num--;
    }
    resume(x);
    return 0;
}
int build()
{
    int i, i1, pre, first, pos;
    num = 0;
    for (i = 0; 324 > i; i++)
    {
        r[i] = i + 1;
        l[i + 1] = i;
    }
    r[324] = 0;
    l[0] = 324;
    for (i = 1; 324 >= i; i++)
    {
        pre = i;
        sum[i] = 0;
        for (i1 = 1; 729 >= i1; i1++)
        {
            if (mplist[i1][i] == 1)
            {
                sum[i]++;
                pos = i1 * 324 + i;
                c[pos] = i;
                d[pre] = pos;
                u[pos] = pre;
                pre = pos;
            }
        }
        u[i] = pre;
        d[pre] = i;
        if (sum[i] == 0)
        {
            return 0;
        }
    }
    for (i = 1; 729 >= i; i++)
    {
        pre = -1;
        first = -1;
        for (i1 = 1; 324 >= i1; i1++)
        {
            if (mplist[i][i1] == 1)
            {
                pos = i * 324 + i1;
                if (pre == -1)
                {
                    first = pos;
                }
                else
                {
                    r[pre] = pos;
                    l[pos] = pre;
                }
                pre = pos;
            }
        }
        if (first != -1)
        {
            r[pre] = first;
            l[first] = pre;
        }
    }
    return 1;
}
void output()
{
    int i, i1, x, y, k, r, t;
    for (i = 0; num > i; i++)
    {
        r = o[i];
        k = r % 9;
        if (k == 0)
        {
            k = 9;
        }
        t = (r - k) / 9 + 1;
        y = t % 9;
        if (y == 0)
        {
            y = 9;
        }
        x = (t - y) / 9 + 1;
        ans[x][y] = k;
    }
    for (i = 1; 9 >= i; i++)
    {
        for (i1 = 1; 9 >= i1; i1++)
        {
            printf("%d", ans[i][i1]);
        }
    }
    printf("\n");
}
int main()
{
    int i, i1, i2, top, t;
    char m[82];
    while (scanf("%s", m) != EOF && strcmp(m, "end") != 0)
    {
        top = 0;
        memset(mplist, 0, sizeof(mplist));
        for (i = 1; 9 >= i; i++)
        {
            for (i1 = 1; 9 >= i1; i1++)
            {
                t = (i - 1) * 9 + i1;
                if (m[top] == '.')
                {
                    for (i2 = 1; 9 >= i2; i2++)
                    {
                        mplist[9 * (t - 1) + i2][t] = 1;
                        mplist[9 * (t - 1) + i2][81 + (i - 1) * 9 + i2] = 1;
                        mplist[9 * (t - 1) + i2][162 + (i1 - 1) * 9 + i2] = 1;
                        mplist[9 * (t - 1) + i2][243 + ((i - 1) / 3 * 3 + (i1 + 2) / 3 - 1) * 9 + i2] = 1;
                    }
                }
                else
                {
                    i2 = m[top] - '0';
                    mplist[9 * (t - 1) + i2][t] = 1;
                    mplist[9 * (t - 1) + i2][81 + (i - 1) * 9 + i2] = 1;
                    mplist[9 * (t - 1) + i2][162 + (i1 - 1) * 9 + i2] = 1;
                    mplist[9 * (t - 1) + i2][243 + ((i - 1) / 3 * 3 + (i1 + 2) / 3 - 1) * 9 + i2] = 1;
                }
                top++;
            }
        }
        build();
        dfs();
        output();
    }
    return 0;
}