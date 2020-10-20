#include <bits/stdc++.h>
using namespace std;

void FCFS(int cidao[], int m)
{
    int begin = 100; //当前磁道位置
    int sum = 0;     //移动的总磁道数
    float ave;       //平均寻道长度
    int difference;  //每次相减差值

    sum = abs(cidao[0] - begin);
    printf("%d \n", sum);
    for (int i = 0; i < m - 1; i++)
    {
        difference = abs(cidao[i] - cidao[i + 1]);
        sum += difference;
        printf("%d \n", difference);
    }
    ave = (float)(sum) / (float)(m);
    printf("平均寻道长度：%.1f \n", ave);
}

int main(int argc, char const *argv[])
{
    int cidao[] = {55, 58, 39, 18, 90, 160, 150, 38, 184};

    int length = sizeof(cidao) / sizeof(cidao[0]);
    FCFS(cidao, length);
    return 0;
}
