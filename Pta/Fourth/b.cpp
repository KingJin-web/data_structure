#include <bits/stdc++.h>
using namespace std;

int b[1024];
int a[1024];

int cnt, n, n_num, num, judge;

void Num(int i)
{
    int k, flag = 0;
    if (n_num < num)
    {
        for (; i < n; i++)
        {
            if (!b[i])
            {
                b[i] = 1;
                n_num += a[i];
                Num(i + 1);
                n_num -= a[i];
                b[i] = 0;
            }
        }
    }
    else if (n_num == num)
    {
        for (k = 0; k < n; k++)
        {
            if (b[k])
            {
                if (flag)
                {
                    putchar(' ');
                }
                flag = 1;
                cout << a[k];
            }
        }
        putchar('\n');
        cnt++;
    }
}

int main()
{
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> num;
    Num(0);
    if (!cnt)
    {
        cout << "None" << endl;
    }
    return 0;
}
