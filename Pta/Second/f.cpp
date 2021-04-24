#include <bits/stdc++.h>
using namespace std;
int n;
int a[1555555];
int b[1555555];
void check(int l, int r)
{
    if (l == r)
        return;
    int n = 0;
    for (int i = l; i <= r; i += 2)
        b[++n] = a[i];
    for (int i = l + 1; i <= r; i += 2)
        b[++n] = a[i];
    for (int i = l; i <= r; i++)
    {
        a[i] = b[i - l + 1];
    }
    int mid = (l + r) >> 1;
    check(l, mid);
    check(mid + 1, r);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    check(1, n);
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (flag)
            printf(" ");
        flag = true;
        printf("%d", a[i]);
    }
    return 0;
}

// //7 - 4 Split(20 分)
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int arrCh(int arr[], int n) ;
// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     int arr2[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     double a = n;
//     for (int i = 1; i <= n; i *= 2)
//     {
//         /* code */
//         int c = n / 2;
//         for (int i = 0; i < n; i++)
//         {
//             if (i % 2 == 0)
//             {
//                 arr2[i / 2] = arr[i];
//             }
//             else
//             {
//                 arr2[c] = arr[i];
//                 c++;
//             }
//         }
//         for (int i = 0; i < n; ++i)
//         {
//             arr[i] = arr2[i];
//         }
//         for (int i = 0; i < n; ++i)
//         {
//             cout << arr[i];
//         }
//         cout << endl;
//         a = a / 2;
//     }

//     for (int i = 0; i < n; ++i)
//     {
//         cout << arr[i] << endl;
//     }
//     return 0;
// }

// int arrCh(int arr[], int n)
// {
//     double a = n;
//     int arr1[n], arr2[n];
//     for (int i = 1; i <= n; i *= 2)
//     {
//         /* code */
//         int c = n / 2;
//         for (int i = 0; i < n; i++)
//         {
//             if (i % 2 == 0)
//             {
//                 arr2[i / 2] = arr[i];
//             }
//             else
//             {
//                 arr2[c] = arr[i];
//                 c++;
//             }
//         }
//         for (int i = 0; i < n; ++i)
//         {
//             arr[i] = arr2[i];
//         }
//         for (int i = 0; i < n; ++i)
//         {
//             cout << arr[i];
//         }
//         cout << endl;
//         a = a / 2;
//     }

//     for (int i = 0; i < n; ++i)
//     {
//         cout << arr[i] << endl;
//     }
//     return 0;
// }