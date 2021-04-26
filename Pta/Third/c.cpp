#include <bits/stdc++.h>
using namespace std;
struct student
{
    int t, index;
} a[1001];
bool complare(student x, student y)
{
    if (x.t == y.t)
        return x.index < y.index;
    return x.t < y.t;
}
int main()
{
    int n;
    double time = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].t, a[i].index = i;
    sort(a + 1, a + 1 + n, complare);
    for (int i = 1; i <= n; ++i)
    {
        time += a[i].t * (n - i);
    }
    time /= n;

    printf("%.2lf", time);
    return 0;
}