#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 150005;
int n;
int v[MAX_N];
int fa[MAX_N];

void show(int i)
{

    if (i)
        cout << " ";
    cout << i;
    if (i > n - 3)
        return;
    else
        show(fa[i]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    memset(v, 0, sizeof(v));
    for (int i = 0; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = n - 3; i >= 0; i--)
    {
        int tmp = i + 3;
        if (v[i + 2] <= v[i + 3])
            tmp = i + 2;
        if (v[tmp] >= v[i + 1])
            tmp = i + 1;
        v[i] = v[i] + v[tmp];
        fa[i] = tmp;
    }
    cout << v[0] << endl;
    show(0);
    return 0;
}
