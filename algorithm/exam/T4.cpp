#include <iostream>
using namespace std;

int cnt = 0, tot;
int a[100];
void fun(int n, int sum)
{
    if (sum == tot) //注意这里的打印技巧
    {
        for (int i = 0; i < cnt - 1; ++i)
            printf("%d+", a[i]);
        if (tot - a[0] == cnt - 1)
            printf("%d\n", a[cnt - 1]);
        else
            printf("%d,", a[cnt - 1]);
        return;
    }
    for (int i = n; i > 0; --i)
    {
        if (sum + i <= tot)
        {
            a[cnt++] = i;
            fun(i, sum + i); //注意这里不是fun (n - i, sum+i),因为每次的划分结果都是从大到小排序的
                             //所以每次枚举的最大数不能大于上一次的值;
            cnt--;           //  记得这里要回溯
        }
    }
}
int main()
{

    //正整数n
    tot = 6;
    fun(tot, 0);
}