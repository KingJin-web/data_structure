#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
/*
1. 楼梯问题
1级：1种
2级：2种
3级：4种
4级：1+2+4=7种 （前3个和）
5级：2+4+7=13种 （前3个和）
6级：4+7+13=24种 （前3个和）
7级：7+13+24=44种 （前3个和）
8级：13+24+44=81种（前3个和）
*/
int get(int m)
{
    int F[5] = {0, 1, 2, 4, 0};

    if (m > 0 && m < 4)
        return F[m];

    for (int i = 4; i <= m; i++)
    {
        F[4] = F[1] + F[2] + F[3];
        F[1] = F[2];
        F[2] = F[3];
        F[3] = F[4];
    }

    return F[4];
}

//2。数组对称
bool isDuciCheng(int a[], int left, int right)
{
    if (left >= right)
        return true;

    bool b = a[left] == a[right] && isDuciCheng(a, left + 1, right - 1);
    return b;
}

//3.最大子段和问题：

//请用回溯法实现：将正整数n表示成一系列正整数之和
int x[10];
int n;
void bt(int t)
{
    //if (getsum(t) == n)
    {
        // printOneSolution(t);
        return;
    }
    for (int i = (t = 0 ? n : x[t - 1]); i >= 1; i--)
    {
        x[t] = i;
        bt(t + 1);
    }
}

//7、用回溯法解决：给定n个正整数wi和一个正整数m，在这n个正整数中找出一个子集，使得子集中的正整数之和等于m。

int *arr, *result;          // arr表示数据数组；result表示解数组，用于存储解向量
int M, n, sum = 0, cnt = 0; // M表示目标正整数，n表示集合中的元素个数，cnt表示解的个数
void T7(int k)
{
    if (sum > M || k > n)
    {
        return;
    }
    if (sum == M)
    {          // 找到符合条件的解集，输出
        cnt++; // 解个数+1
        for (int i = 0; i < n; i++)
        {
            if (result[i] == 1)
            { // 解数组内，1表示该数（arr[i]）存在于子集和中
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
    else
    { // 未符合条件，继续
        for (int i = 0; i <= 1; i++)
        { // i=0表示该数arr[k]未装入解集。i=1表示已装入
            if (i == 0)
            {
                sum = sum + arr[k]; // 装入该数
                result[k] = 1;      // 更改标记为已装入
                T7(k + 1);          // 继续下一个数
                result[k] = 0;      // 回溯回来后，更改该数标记为未装入
                sum = sum - arr[k]; // 将该数移出目标子集和
            }
            else
            {
                T7(k + 1); // 该数已装入，继续下一个数
            }
        }
    }
}
/*
8、给定一个存放整数的数组，重新排列数组使得数组左边为偶数，右边为奇数。
如对数组：1,2,3,4,5,6,7,8,9处理后，该数组变为：2,4,6,8,1,3,5,7,9。
     解决思路：数组左边left，右边right。左边遇到第一个偶数停止，右边遇到第一个奇数停止。二者进行交换
     直到left>right操作结束
    */
void t8(int *arr, int length)
{
    int left = 0;
    int right = length - 1;
    int flag;
    while (left < right)
    {
        //如果为偶数 左下标 + 1
        if (arr[left] % 2 == 0)
        {
            left++;
            continue;
        }
        if (arr[right] % 2 != 0)
        {
            right--;
            continue;
        }
        if (left < right)
        {
            flag = arr[left];
            arr[left++] = arr[right];
            arr[right--] = flag;
        }
    }
}

//9、编写函数double getRestul(int n)并测试，它的功能是：根据以下公式计算结果
//s = 1/1 - 1/3 + 1/5 + 1/2n-1
double getRestul(int n)
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
    // cout << get(7) << endl;

    //int arr[] = {1, -1, -1, 1};
    //int n = sizeof(arr) / sizeof(int) - 1;
    //cout << isDuciCheng(arr, 0, n) << endl;

    cout << getRestul(3) << endl;

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]);

    t8(arr, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d,", arr[i]);
    }


    return 0;
}
