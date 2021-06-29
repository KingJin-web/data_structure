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

///题目：求集合(1, 2, 3, 4, 5, 6)的 全排列 并打印全部
class Solution
{
public:
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};


int main(int argc, char const *argv[])
{
    T1(0);
    return 0;
}
