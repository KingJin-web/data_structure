// • 例：某公司拟将4万元，向A、B、C三个项目追加投资，三个项目可以有不同的投资额度，相应的效益值如表所示，
// 问如何分配资金，才使总效益值最大？最优值：190

#include <bits/stdc++.h>
using namespace std;


int getMaxLcsLength(char *x, char *y);
int getMaxValue(int *w, int *v, int c, int n) ;
int longestCommonSubsequence(char *x, char *y)
{
    int m = strlen(x), n = strlen(y);
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++)
    {
        char c1 = x[i - 1];
        for (int j = 1; j <= n; j++)
        {
            char c2 = y[j - 1];
            if (c1 == c2)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int getMaxLcsLength(char *x, char *y)
{
    string x = x; 
    int m = x.length(); 
    string y = y;
    int n = y.length();

    //int m = x.length(), n = y.length();
    vector<vector<int>> dp (m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
    {
        char c1 = x.at(i - 1);
        for (int j = 1; j <= n; j++)
        {
            char c2 = y.at(j - 1);
            if (c1 == c2)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int getMaxValue(int *w, int *v, int c , int n ){
    int x[3];
    int V[200][200]; //前i个物品装入容量为j的背包中获得的最大价值
    int i, j;
    for (i = 0; i <= n; i++)
        V[i][0] = 0;
    for (j = 0; j <= c; j++)
        V[0][j] = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < c + 1; j++)
        {
            if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
        }
    }
    j = c;
    for (i = n - 1; i >= 0; i--)
    {
        if (V[i][j] > V[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        else
            x[i] = 0;
    }

    return V[n - 1][c];
}


int main(int argc, char const *argv[])
{
    char x[10] = "ABCDEFG";
    char y[10] = "BCD";
    cout<<getMaxLcsLength(x, y)<<endl;

    //背包问题，背包限重50. 物品重量 分别为10，20，30  价值分别为60,100,120，

    int s;                     //获得的最大价值
    int w[3] = {10, 20, 30};   //物品的重量 
    int v[3] = {60, 100, 120}; //物品的价值
              
    int n = 3;
    int C = 50; //背包最大容量

    s = getMaxValue(w,v,C,n);

    printf("最大物品价值为:\n");
    printf("%d\n", s);
    system("pause");
    return 0;
   
}
