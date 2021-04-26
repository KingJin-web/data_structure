#include <bits/stdc++.h>
using namespace std;
string a; //输入高精度的数
int n, maxn = -100, maxn1 = -100;
int main()
{
    int x = 1;
    cin >> a >> n; //输入
    while (x <= n) //判断有没有删到最大限度
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] - '0' > maxn)
            {
                maxn = a[i] - '0'; //枚举最大值
            }
        }
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] - '0' > a[i + 1] - '0')
            {
                maxn1 = i; //判断前一个数位的数是否大于后一个数位的数
                break;
            }
        }
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] - '0' == maxn && i > maxn1) //如果最大值的位置大于上述的数（即前一个数位的数大于后一个数位的数）
            {
                a.erase(i, 1); //删掉字符串中的最大值
                break;
            }
            else //否则
            {
                a.erase(maxn1, 1); //删掉上述的数
                break;
            }
        }
        x++;
        maxn = -100; //更新最大值
    }
    cout << a;
    return 0;
}
