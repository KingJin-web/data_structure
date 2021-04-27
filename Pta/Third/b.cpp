#include <iostream>
#include <bits/stdc++.h>
// using namespace std;

// const int v[6] = {5, 10, 20, 50, 100, 200};; //储存硬币的面值

// int a, c[6]; //c[0]= C1，c[1] = C5,c[2] = C10,...

// int main()
// {
//     int n ;
//     cin>>n;

//     while (n)
//     {
//         /* code */
//         for (int i = 0; i < 6; i++)
//         {

//             cin>>c[i]; //依次输入C1、C5、C10、C50、C100、C500
//         }
//         double aa;
//         cin>>aa;
//         //scanf("%lf", &aa); //输入需支付的金额
//         a = (int) (aa * 100);
//         int ans = 0;

//         for (int i = 5; i >= 0; i--)
//         { //尽可能取大的面值

//             int temp = min(c[i], a / v[i]); //取'当前面值硬币数量'和

//             //'待支付金额/面值'的较小值

//             ans += temp; //结果加上取走的张数

//             a -= temp * v[i]; //待支付金额减去这一轮支付的金额
//         }

//         printf("%d\n", ans); //输出答案

//         n--;
//     }

//     return 0;
// }

#include <iostream>
#include <cstring>
using namespace std;
int val[55] = {0, 5, 10, 20, 50, 100, 200};
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int w[1001] = {0}, v[1001] = {0}, n = 0, a[10001], sum;
        memset(a, 0x3f, sizeof(a));
        for (int i = 1; i <= 6; i++)
        {
            int s;
            cin >> s;
            for (int j = 1; j <= s; j++)
            {
                n++;
                w[n] = val[i];
                v[n] = 1;
            }
        }
        double s;
        cin >> s;
        sum = s * 100;
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = sum; j >= w[i]; j--)
            {
                a[j] = min(a[j], a[j - w[i]] + v[i]);
                //				cout<<w[i]<<" "<<v[i]<<endl;
            }
        }
        if (a[sum] != 1061109567)
            cout << a[sum] << endl;
        else
            cout << "impossible" << endl;
    }
    return 0;
}
