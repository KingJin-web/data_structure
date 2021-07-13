#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

//9、编写函数double getRestul(int n)并测试，它的功能是：根据以下公式计算结果
//s = 1/1 - 1/3 + 1/5 + 1/2n-1
//老师复习课讲的 非常人性 建议用这个
double getRestul(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return getRestul(n - 1) + pow(-1, n - 1) * 1 / (2 * n - 1);
}

double getRestul1(int n)
{
    double c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            c -= (double)1 / (2 * i - 1);
        else
            c += (double)1 / (2 * i - 1);
    }
    return c;
}

int main(int argc, char const *argv[])
{
    printf("%lf\n", getRestul(5));
    printf("%lf\n", getRestul1(5));
    return 0;
}


