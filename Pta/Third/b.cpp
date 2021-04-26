//7 - 2 硬币找钱问题(10 分)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 20000;
int change[N];                        //change[i]为面值为i的钱至少需要的硬币个数
int dp[N];                            //dp[i]为当前拥有的硬币数量条件下表示面值为i的最少硬币个数
int value[6] = {1, 2, 4, 10, 20, 40}; //每种硬币对应面值，依次为1，2,4,10,20,40个五分，即5,10,20,50,100,200；
int number[6];                        //对应于当前拥有的每种硬币个数

void init() //计算change[i]
{
    int i, j;
    for (i = 0; i < N; i++)
        change[i] = -1;
    change[0] = 0;
    for (i = 0; i < 6; i++)
    {
        for (j = value[i]; j < N; j++) //这里使用完全背包，不能理解的话可参考背包九讲
        {
            if (change[j - value[i]] != -1)
            {
                int temp = change[j - value[i]] + 1;
                if (change[j] == -1 || temp < change[j])
                    change[j] = temp;
            }
        }
    }
}
int main()
{
    //freopen("change.in","r",stdin);

    init(); //计算出change[i]

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        while (scanf("%d%d%d%d%d%d", &number[0], &number[1], &number[2], &number[3], &number[4], &number[5]) != EOF)
        {
            int sum = 0;
            int kk;
            for (kk = 0; kk < 6; kk++)
                sum += number[kk];
            if (sum == 0)
                break;
            double weight;
            scanf("%lf", &weight);
            weight = weight * 100;
            // printf("weight = %lf\n",weight);
            int w = int(weight + 0.0000001); //处理精度问题
            //printf("%d\n",w);

            if (w % 5 != 0) //若不能整除，则无法表示
            {
                printf("impossible\n");
                continue;
            }
            else
                w = w / 5;

            int i, j;
            memset(dp, -1, sizeof(dp));
            dp[0] = 0;
            int bigger = 0;
            for (i = 0; i < 6; i++) //计算顾客支付面值i需要的最少硬币数dp[i]
            {
                while (number[i]--) //将混合背包拆成01背包做，写水了点。。。
                {
                    bigger = bigger + value[i];
                    for (j = bigger; j >= value[i]; j--)
                    {
                        if (dp[j - value[i]] != -1)
                        {
                            int temp = dp[j - value[i]] + 1;
                            if (dp[j] == -1 || temp < dp[j])
                            {
                                dp[j] = temp;
                            }
                        }
                    }
                }
            }

            int ans = -1;
            for (i = w; i <= bigger; i++) //寻找最少硬币组合
            {
                if (dp[i] != -1)
                {
                    int need = i - w;
                    if (change[need] != -1)
                    {
                        int temp = dp[i] + change[need];
                        if (ans == -1 || ans > temp)
                            ans = temp;
                    }
                }
            }

            // for(i=0;i<N;i++)
            //   if(dp[i]!=-1)
            //  printf("dp[%d]=%d\n",i,dp[i]);

            if (ans != -1)
                printf("%d\n", ans);
            else
                printf("impossible\n");
        }
    }

    return 0;
}
