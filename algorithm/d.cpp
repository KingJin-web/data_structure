#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
int x[100];

char *str = "abcd";
int n = 4;
void T1(int t)
{

    if (t >= n)
    {
        for (int i = 0; i < t; i++)
        {
            if (x[i] == 1)
            {
                cout << str[i];
            }
        }
        cout << endl;
        return;
    }
    for (int pv = 0; pv <= 1; pv++)
    {
        x[t] = pv;
        T1(t + 1);
    }
}

void backtrack(vector<vector<int>> &res, vector<int> &output, int first, int len)
{
    // 所有数都填完了
    if (first == len)
    {
        res.emplace_back(output);
        return;
    }
    for (int i = first; i < len; ++i)
    {
        // 动态维护数组
        swap(output[i], output[first]);
        // 继续递归填下一个数
        backtrack(res, output, first + 1, len);
        // 撤销操作
        swap(output[i], output[first]);
    }
}
vector<vector<int>> T2(vector<int> &nums)
{
    vector<vector<int>> res;
    backtrack(res, nums, 0, (int)nums.size());
    return res;
}

void printfVet(vector<vector<int>> arrs)
{
    for (vector<int> arr : arrs)
    {
        for (int a : arr)
        {
            printf("%d ", a);
        }
        printf("\n");
    }
}

/**
 * 楼梯有 totalStep 级台阶，可以一步走一级台阶，也可以一步走两级台阶，
 * 请问一共有多少种走法？这些走法分别是什么？
 */

int routeNo = 1;

void climbStairs(int totalStep, int currentStep, string route)
{
    //如果已经超过了总步数
    if (currentStep > totalStep)
    {
        //方案失效，直接结束递归
        return;
    }

    //如果刚刚等于总步数
    if (currentStep == totalStep)
    {
        //打印路线图
        string a = "第" + to_string(routeNo) + "种方案：" + route;

        cout << a << endl;
        //方案编号+1
        routeNo++;

        //结束递归
        return;
    }

    //还没到总步数，递归尝试下步走一个台阶，同时记录路径
    climbStairs(totalStep, currentStep + 1, route + " -> " + to_string(1));

    //递归尝试下步走两个台阶，同时记录路径
    climbStairs(totalStep, currentStep + 2, route + " -> " + to_string(2));
}

void climbStairs(int totalStep)
{
    //先将路线的编号初始化
    routeNo = 1;

    //初始走一步
    climbStairs(totalStep, 1, "1");

    //初始走两步
    climbStairs(totalStep, 2, "2");
}

int main(int argc, char const *argv[])
{
    T1(0);

    // int a[6] = {1, 2, 3, 4, 5, 6};
    // vector<int> arr(a, a + 6);
    // printfVet(T2(arr));

    climbStairs(3);
    return 0;
}
