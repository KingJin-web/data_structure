#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

//数组对称
bool isDuciCheng(int a[], int left, int right)
{
    if (left >= right)
        return true;

    bool b = a[left] == a[right] && isDuciCheng(a, left + 1, right - 1);
    return b;
}

int x[10];
int n;
void bt(int t)
{
    for (int i = (t = 0 ? n : x[t - 1]); i >= 1; i--)
    {
        x[t] = i;
        bt(t + 1);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, -1, -1, 1};
    int n = sizeof(arr) / sizeof(int) - 1;
    cout << isDuciCheng(arr, 0, n) << endl;
    return 0;
}
