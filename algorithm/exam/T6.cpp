//6、给定一个高度为 n 的“数字三角形”，其中第 i 行（1\<= i\<= n）有 i个数。
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
// ================= 代码实现开始 =================
//dp:用于动态规划的数组，d[i][j]表示要走到第i行第j列能得到最大数字总和
vector<vector<int>> dp;
// 本函数计算答案（最大经过位置数字总和）
// n：描述数字三角形大小，意义同题目描述
// a：描述整个数字三角形，第 i 行的第 j 个数存放在 a[i][j]
// 中（你需要特别注意的是，所有下标均从 1 开始，也就是说下标为 0 的位置将存放无效信息）
// 返回值：最大经过位置数字总和
//https://blog.csdn.net/qq_45968259/article/details/107131205?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_baidulandingword-1&spm=1001.2101.3001.4242
vector<vector<int>> a ;
int init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            // scanf("%d", &a[i - 1][j - 1]);     //输入三角形
            // b[i - 1][j - 1] = a[i - 1][j - 1]; //复制
        }
    }
}
int getAnswer(int n, vector<vector<int>> a)
{
    dp.resize(n + 1);
    for (int i = 0; i <= n; ++i)
        dp[i].resize(i + 2);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j]; //用左上角和正上方的dp值更新
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[n][i]); //求最大的数字之和
    return ans;
}


int T6(){
    int i, j, n;
    int a[100][100]; //用于存放三角形
    int b[100][100]; //用于复制a数组
    printf("请输入数字三角形的行数：\n");
    scanf("%d", &n); //获取输入的行数
    printf("请输入数字三角形：\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            scanf("%d", &a[i - 1][j - 1]);     //输入三角形
            b[i - 1][j - 1] = a[i - 1][j - 1]; //复制
        }
    }
    for (int row = n - 2; row >= 0; row--)
    { //从倒数第二行开始往上递推
        for (int col = 0; col <= row; col++)
        {
            if (a[row + 1][col] > a[row + 1][col + 1])
            {                                   //将每个数下面的两个数进行比较
                a[row][col] += a[row + 1][col]; //取较大的数加
            }
            else
            {
                a[row][col] += a[row + 1][col + 1];
            }
        }
    }
    printf("路径总和最大为：\n");
    printf("%d\n", a[0][0]);
    //后面的不用记
    printf("自顶向下的路径为:\n");
    printf("%d ", b[0][0]); //先输出第一行的数字
    int l = 0;              //定义列
    for (int m = 1; m < n; m++)
    { //从第二行开始往下递推
        if (a[m][l] > a[m][l + 1])
        {
            printf("%d ", b[m][l]); //根据数值较大的数的位置输出b数组中指定位置的值
        }
        else
        {
            printf("%d ", b[m][l + 1]);
            l = l + 1; //如果较大的数为右边的数则下次开比较的列加1
        }
    }
    printf("\n");
    return 0;
}


int main(int argc, char const *argv[])
{
    T6();
    return 0;
}
