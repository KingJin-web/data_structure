
#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];
string res[100];
string temp(8, '0');
int cnt;
void dfs(int u)
{
    if (u == 8)
    {
        res[cnt++] = temp;
        return;
    }
    for (int i = 1; i <= 8; i++)
        if (!col[i] && !dg[u + i] && !udg[8 - u + i])
        {
            temp[u] += i;
            col[i] = dg[u + i] = udg[8 - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[8 - u + i] = false;
            temp[u] -= i;
        }
}
int main()
{
    dfs(0);
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        cout << res[k - 1] << endl;
    }
}
