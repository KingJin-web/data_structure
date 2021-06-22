#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
/*
1. 楼梯问题
1级：1种
2级：2种
3级：4种
4级：1+2+4=7种 （前3个和）
5级：2+4+7=13种 （前3个和）
6级：4+7+13=24种 （前3个和）
7级：7+13+24=44种 （前3个和）
8级：13+24+44=81种（前3个和）
*/
int get(int m)
{
    int F[5] = {0, 1, 2, 4, 0};

    if (m > 0 && m < 4)
        return F[m];

    for (int i = 4; i <= m; i++)
    {
        F[4] = F[1] + F[2] + F[3];
        F[1] = F[2];
        F[2] = F[3];
        F[3] = F[4];
    
    }

    return F[4];
}

//2。数组对称
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
    cout << get(7) << endl;
    int arr[] = {1, -1, -1, 1};
    int n = sizeof(arr) / sizeof(int) - 1;
    cout << isDuciCheng(arr, 0, n) << endl;
    return 0;
}
