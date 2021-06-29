#include <iostream>

using namespace std;
//### 用回溯法解决： https://blog.csdn.net/qwqc262/article/details/111320112
//给定n个正整数wi和一个正整数m，在这n个正整数中找出一个子集，使得子集中的正整数之和等于m。
int *arr, *result;          // arr表示数据数组；result表示解数组，用于存储解向量
int M, n, sum = 0, cnt = 0; // M表示目标正整数，n表示集合中的元素个数，cnt表示解的个数
void backTrack(int k)
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
        return;
    }
    else
    { // 未符合条件，继续
        for (int i = 0; i <= 1; i++)
        { // i=0表示该数arr[k]未装入解集。i=1表示已装入
            if (i == 0)
            {
                sum = sum + arr[k]; // 装入该数
                result[k] = 1;      // 更改标记为已装入
                backTrack(k + 1);   // 继续下一个数
                result[k] = 0;      // 回溯回来后，更改该数标记为未装入
                sum = sum - arr[k]; // 将该数移出目标子集和
            }
            else
            {
                backTrack(k + 1); // 该数已装入，继续下一个数
            }
        }
    }
}

int main()
{
    //4 31
    // 13 24 11 7

    n = 4;
    M = 31;
    //cin >>n >> M; // 输入集合元素个数n和目标正整数M
    arr = new int[n]{13, 24, 11, 7};
    result = new int[n];
    // for (int i = 0; i < n; i++)
    // { // 输入集合元素数据
    //     cin >> arr[i];
    // }
    for (int i = 0; i < n; i++)
    { // 初始化解数组
        result[i] = 0;
    }
    backTrack(0); // 进入回溯
    return 0;
}
