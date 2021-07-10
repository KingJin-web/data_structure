#include <iostream>
using namespace std;

int n, j, sum, maxx;
/* 
    输入
    8
    1 -1 2 2 3 -3 4 -4 
*/
/*
    输出
    8
*/
int main()
{
    scanf("%d%d", &n, &maxx);
    sum = maxx; //输入n
    while (--n)
    {
        scanf("%d", &j);
        sum = sum > 0 ? sum : 0;
        sum += j;
        maxx = maxx > sum ? maxx : sum;
    }                                //贪心，如果负了就舍去
    return (printf("%d", maxx)) & 0; //输出并return 0
}
