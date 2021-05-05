#include <bits/stdc++.h>
using namespace std;
int n, total = 0;
int a[10001] = {1};

int print(int t)
{
    //total++;
    //cout<<n<<"=";
    printf("%d=", n);
    for (int i = 1; i <= t; i++)
    {
        if (i == t)
        {
            printf("%d\n",a[i]);
            // cout << a[i];
            // cout << endl;
        }
        else
            printf("%d+", a[i]);
            // cout << a[i] << "+";
    }
}

int search(int s, int t)
{
    int i;
    for (i = a[t - 1]; i <= s; i++)
        if (i < n) //当前数i要大于等于前1位数，且不过n
        {
            a[t] = i; //保存当前拆分的数i
            s -= i;   //s减去i，s的值继续拆分
            if (s == 0)
                print(t); //s==0  拆分结束输出结果
            else
                search(s, t + 1); //s>0，继续递归
            s += i;               //回溯：加上拆分的数，以便产分所有可能的拆分
        }
    return 0;
}
int main()
{
    cin >> n;
    search(n, 1); //将要拆分的数n传递给s
    printf("%d=%d\n", n, n);
    //   cout<<total<<endl;       //这是总方案数
    return 0;
}
