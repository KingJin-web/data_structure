
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int n;
    // res是结果
    // cuur是当前的路径，会按照路径做回溯来修改
    // start表示路径的起点，会不断增加
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

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        n = nums.size();
        vector<vector<int>> res;
        vector<int> curr;
        dfs(nums, res, curr, 0);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int dp[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<int> nums(dp, dp + n);

    Solution *s = new Solution();
    vector<vector<int>> res = s->subsets(nums);
    for (vector<int> re : res)
    {
        int size = re.size();
        if (size == 0)
        {
            printf("{}\n");
            continue;
        }
        
        printf("{");
       
        for (int i = 0; i < re.size() - 1; i++) //size()容器中实际数据个数
        {
            printf("%d,", re[i]);
        }
        printf("%d", re[re.size() - 1]);
        printf("}\n");
    }

    return 0;
}
