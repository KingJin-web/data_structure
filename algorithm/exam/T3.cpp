#include <iostream>
using namespace std;

/* 
    输入
    8
    1 -1 2 2 3 -3 4 -4 
*/
/*
    输出
    8
*/

int maxSubArray(int *nums, int l)
{

    int pre = 0, maxAns = nums[0];
    for (int i = 0; i < l; i++)
    {
        pre = max(pre + nums[i], nums[i]);
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}
int main()
{

    int arr[] = {1, -1, 2, 2, 3, -3, 4, -4};
    int l = sizeof(arr) / sizeof(arr[0]);
    cout << maxSubArray(arr, l);

    // cout << maxSubArray(arr, 8);
    //或者将上面两行换成这一行

    return 0;
}
// cout << maxSubArray(arr, 8);
// int n, j, sum, maxx;
// scanf("%d%d", &n, &maxx);
// sum = maxx; //输入n
// while (--n)
// {
//     scanf("%d", &j);
//     sum = sum > 0 ? sum : 0;
//     sum += j;
//     maxx = maxx > sum ? maxx : sum;
// }
// //贪心，如果负了就舍去
// printf("%d", maxx);