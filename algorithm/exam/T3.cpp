#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
    /* 
    输入
    8
    1 -1 2 2 3 -3 4 -4 
*/
    /*
    输出
    8
*/

int maxSubArray(vector<int> &nums)
{
    
    int pre = 0, maxAns = nums[0];
    for (const auto &x : nums)
    {
        pre = max(pre + x, x);
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}
int main()
{
    int n, j, sum, maxx;
    scanf("%d%d", &n, &maxx);
    sum = maxx; //输入n
    while (--n)
    {
        scanf("%d", &j);
        sum = sum > 0 ? sum : 0;
        sum += j;
        maxx = maxx > sum ? maxx : sum;
    }
    //贪心，如果负了就舍去
    printf("%d", maxx);

    // vector<int> vec;
    

    // double a = floor(6.5678);
    // cout<<a<<endl;
    return 0;
    //输出并return 0
}

