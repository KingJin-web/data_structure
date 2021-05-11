
#include <bits/stdc++.h>
using namespace std;

int n;

void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int start)
{
    res.push_back(curr);
    for (int i = start; i < n; ++i)
    {
        curr.push_back(nums[i]);
        dfs(nums, res, curr, i + 1);
        curr.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    n = nums.size();
    vector<vector<int>> res;
    vector<int> curr;
    dfs(nums, res, curr, 0);
    return res;
}

int main(int argc, char const *argv[])

{
    int a;
    cin >> a;
    int dp[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<int> nums(dp, dp + a);

    vector<vector<int>> res = subsets(nums);
    for (vector<int> re : res)
    {
        int size = re.size();
        if (size == 0)
        {
            printf("{}\n");
            continue;
        }

        printf("{");

        for (size_t i = 0; i < re.size() - 1; i++) //size()容器中实际数据个数
        {
            printf("%d,", re[i]);
        }
        printf("%d", re[re.size() - 1]);
        printf("}\n");
    }

    return 0;
}
