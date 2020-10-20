#include <iostream>
using namespace std;

void FCFS(int cidao[], int m)
{
    int begnber = 100;
    int sum = 0; //移动的总磁道数
    float ave;   //平均寻道长度

    sum = abs(cidao[0] - begnber);
    printf("%d \n", abs(cidao[0] - begnber));
    for (int i = 0, j = 1; j < m; i++, j++)
    {
        printf("%d \n", abs(cidao[j] - cidao[i]));
        sum += abs(cidao[j] - cidao[i]);
        ave = (float)(sum) / (float)(m);
    }

    cout << "平均寻道长度：";
    printf("%.1f \n", ave);
}

int main(int argc, char const *argv[])
{
    int cidao[] = {55, 58, 39, 18, 90, 160, 150, 38, 184};

    int length = sizeof(cidao) / sizeof(cidao[0]);
    FCFS(cidao, length);
    return 0;
}
