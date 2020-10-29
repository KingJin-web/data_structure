#include <windows.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     char ch ;
//     scanf("%c", &ch);
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

// int main()
// {
//     int y, m, d;
//     scanf("%d/%d/%d", &y, &m, &d);
//     printf("%d--%d--%d\n", y, m, d);
//     system("pause");
// }

// 在任意一个四位整数中，如果该数的个位数和百位数之和大于16，并且十位数和千位数之和小于3，就称这种数为“老九幸运数“，
// 请小伙伴编程计算出在1000~9999中，一共有多少个满足老九幸运数的四位整数呢，打印出最终的个数

// int main()
// {
//     int a, b, c, d, co = 0;
//     for (int i = 1000; i <= 9999; i++)
//     {

//         a = i % 10;
//         b = i / 10 % 10;
//         c = i / 100 % 10;
//         d = i / 1000;
//         if (a + c > 16 && b + d < 3)
//         {
//             cout<<i<<endl;
//             co ++;
//         }
//     }
//     cout<<"一共有 "<<co<<" 个"<<endl;
// }

// int main()
// {
//     int num = 1234;
//     int a, b, c, d;

//     a = num % 10;
//     c = num / 100 % 10;
//     b = num / 10 % 10;
//     d = num / 1000;
//     cout << a << b << c << d << endl;
// }

// #define N 5 //宏定义 ，并不是必须的  好处是功能方便
// int main()
// {
//     int nums[N] = {16, 25, 9, 90, 23};
//     int i, j;
//     int temp;
//     // 先确定外层循环
//     for (i = 0; i < N - 1; i++)
//     {
//         for (j = 0; j < N - i - 1; j++)
//         {
//             if (nums[j] < nums[j + 1])
//             {
//                 temp = nums[j];
//                 nums[j] = nums[j + 1];
//                 nums[j + 1] = temp;
//             }
//         }
//     }
//     printf("排序后的数组是：\n");
//     for (i = 0; i < N; i++)
//     {
//         printf("%d\t", nums[i]);
//     }
// }

// int main()
// {
//     int a,b,c;
//     a = 72, b = 73, c = 74;
//     printf("%f%f%f\n", a, b, c);
//     return 0;
// }

int main(int argc, char const *argv[])
{
    char a, as, bs, cs, ds;
    int n;
    for (a = 'A'; a <= 'D'; a++)
    {
        as = (a != 'A');
        bs = (a == 'C');
        cs = (a == 'D');
        ds = (a != 'D');
        n = as + bs + ds +cs;
        if (n == 3)
            printf("%c\n", a);
    }
 
    return 0;
}
