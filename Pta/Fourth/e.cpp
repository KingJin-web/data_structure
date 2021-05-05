
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct my
{
    ll w, g;
    int num;
    double g_w;
    bool operator<(const my &t) { return g_w > t.g_w; }
} tr[5];
ll ans = 1e18, sum, res = 0, sres = 0;
double n[5];
void dfs(ll V, int u)
{
    if (V <= 0)
    {
        if (ans > res)
        {
            ans = res;
            sum = sres;
        }
        return;
    }
    if (u == 4)
    {
        ll t = min((ll)tr[u].num, V / tr[u].g + 1);
        if (t * tr[u].g >= V)
        {
            if (ans > res + t * tr[u].w)
            {
                ans = res + t * tr[u].w;
                sum = sres + t * tr[u].g;
            }
        }
        return;
    }
    if (V % tr[u].g == 0 && V / tr[u].g <= tr[u].num)
    {
        if (ans > res + V / tr[u].g * tr[u].w)
        {
            ans = res + V / tr[u].g * tr[u].w;
            sum = sres + V;
        }
    }
    else
    {
        ll up = min((ll)tr[u].num, (ll)n[u] + 9), down = max(0ll, (ll)n[u] - 9);
        for (int i = down; i <= up; i++)
        {
            res += i * tr[u].w;
            sres += i * tr[u].g;
            dfs(V - i * tr[u].g, u + 1);
            res -= i * tr[u].w;
            sres -= i * tr[u].g;
        }
    }
}
void solve()
{
    ans = 1e18, sum = 0, res = 0, sres = 0;
    ll Vt, V;
    scanf("%lld", &V);
    Vt = V;
    for (int i = 0; i < 5; i++)
        n[i] = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d %lld %lld", &tr[i].num, &tr[i].g, &tr[i].w);
        tr[i].g_w = (double)tr[i].g / tr[i].w;
    }
    sort(tr, tr + 5);
    for (int i = 0; i < 5; i++)
    {
        if (!V)
            break;
        if (tr[i].g * tr[i].num >= V)
        {
            n[i] = (double)V / tr[i].g;
            V = 0;
        }
        else
            V -= tr[i].g * tr[i].num, n[i] = tr[i].num;
    }
    dfs(Vt, 0);
    if (ans == 1e18)
        puts("Impossible!");
    else
        printf("%lld %lld\n", ans, sum);
}
int main()
{
    int Case;
    cin >> Case;
    while (Case--)
        solve();
    return 0;
}
