#include <windows.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     char ch = '9';
//     //scanf("%c", &ch);
//     if (ch >= 'A' && ch <= 'Z')
//     {
//         ch = ch + 32;
//     }
//     else if (ch >= 'a' && ch <= 'z')
//     {
//         ch = ch - 32;
//     }

//     printf("%c\n", ch);
//     return 0;
// }

int main()
{
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);
    printf("%d--%d--%d\n", y, m, d);
    system("pause");
}