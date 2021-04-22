#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int a = 0, b = 0, c = 0, m = 0;
        int k[4000] = {0};
        for (int j = 0; str[j] != '\0'; j++)
        {

            if (str[j] == 'a')
                a++;
            if (str[j] == 'b')
                b++;
            if (str[j] == 'c')
                c++;

            if (a == 0 && b != 0 || a == 0 && c != 0 || b == 0 && c != 0)
            {
                a = 0;
                b = 0;
                c = 0;
            } //不成立重开
            if (b > a)
            {
                a = 0;
                b = 0;
                c = 0;
            } //不成立
            if (b <= a && b <= c && b > 0)
            {
                k[m] = b;
                m++;
                a = 0;
                b = 0;
                c = 0;
            } //唯一成立，然后重开
            if (str[j] == 'c' && (str[j + 1] == 'a' || str[j + 1] == 'b'))
            {
                a = 0;
                b = 0;
                c = 0;
            } //之前全没用重开
            if (str[j] == 'b' && str[j + 1] == 'a')
            {
                a = 0;
                b = 0;
                c = 0;
            } //不成立重开
            if (str[j] == 'a' && str[j + 1] == 'c')
            {
                a = 0;
                b = 0;
                c = 0;
            } //不成立
        }
        int max = k[0];
        for (int i = 0; i < 4000; i++)
            if (k[i] > max)
                max = k[i];
        cout << max << endl;
    }
}
