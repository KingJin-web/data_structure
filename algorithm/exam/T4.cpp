#include <bits/stdc++.h>
using namespace std;

//输出正整数n的不同划分个数及具体的划分形式。
/* int a[100] = {0};
int c = 0;
void print(int m)
{

    c++;
    for (int i = 0; i < m - 1; i++)
        printf("%d+", a[i]);
    printf("%d\n", a[m - 1]);
}

void T4(int n, int m) //n要划分的整数,m已划分的划分数，a[0]~a[m-1]保存了已划分的值
{
    int i;
    if (n == 0)
        print(m);
    else
        for (i = n; i >= 1; i--)
            if (m == 0 || i <= a[m - 1]) //只有当刚开始划分m==0或者i小于最大已划分的值时，将i作为下一个要划分的值，继续划分
            {
                a[m] = i;
                T4(n - i, m + 1);
            }
} */

// int main()
// {
//     T4(6, 0);
//     printf("共有%d种\n", c);
// }
void printfArr(int *arr)
{
    int length = sizeof(arr) / sizeof(int);
    printf("[");
    for (int i = 0; i < length - 1; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("%d]\n", arr[length - 1]);
}

int cnt = 0, tot;
int a[100];
int c = 0;
void fun(int n, int sum)
{

    // printf("1 n=%d sum=%d tot = %d\n\n", n, sum, tot);
    if (sum == tot) //注意这里的打印技巧
    {
        c++;
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
    cout << c;
}
