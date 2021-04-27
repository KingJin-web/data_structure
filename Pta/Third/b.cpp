#include <iostream>
#include <bits/stdc++.h>
// using namespace std;

// const int v[6] = {5, 10, 20, 50, 100, 200};; //储存硬币的面值

// int a, c[6]; //c[0]= C1，c[1] = C5,c[2] = C10,...

// int main()
// {
//     int n ;
//     cin>>n;

//     while (n)
//     {
//         /* code */
//         for (int i = 0; i < 6; i++)
//         {

//             cin>>c[i]; //依次输入C1、C5、C10、C50、C100、C500
//         }
//         double aa;
//         cin>>aa;
//         //scanf("%lf", &aa); //输入需支付的金额
//         a = (int) (aa * 100);
//         int ans = 0;

//         for (int i = 5; i >= 0; i--)
//         { //尽可能取大的面值

//             int temp = min(c[i], a / v[i]); //取'当前面值硬币数量'和

//             //'待支付金额/面值'的较小值

//             ans += temp; //结果加上取走的张数

//             a -= temp * v[i]; //待支付金额减去这一轮支付的金额
//         }

//         printf("%d\n", ans); //输出答案

//         n--;
//     }

//     return 0;
// }


//这是java 上面的只有五分 这个有满分
/**
 * @program: leetcode
 * @description:
 * @author: King
 * @create: 2021-04-27 10:49
 */

import java.util.Scanner;

public
class Main
{
    static int[] cnts = new int[6];
    //一开始就选择下标为最大的500
    //d = [0.05, 0.1, 0.2, 0.5, 1, 2]
    static double[] coins = {5, 10, 20, 50, 100, 200};

public
    static void main(String[] args)
    {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        //        for (int i = 0; i < 6; i++) {
        //            cnts[i] = sc.nextInt();
        //        }
        //        double aa = sc.nextDouble();
        //        test((int) (aa * 100));
        while (n > 0)
        {
            for (int i = 0; i < 6; i++)
            {
                cnts[i] = sc.nextInt();
            }
            double aa = sc.nextDouble();
            test((int)(aa * 100));
            n--;
        }
    }

private
    static void test(int aa)
    {
        double count = 0;
        int c = 0;
        int i = 0, n = 0;
        for (i = 0; i < 6; i++)
        {
            count += cnts[i] * coins[i];
        }
        if (count < aa)
        {
            System.out.println("impossible");
            return;
        }
        i = 5;
        while (i >= 0)
        {
            if (aa >= coins[i])
            {
                n = (int)(aa / coins[i]);
                if (n >= cnts[i])
                {
                    n = cnts[i];
                }
                aa -= n * coins[i];
                //System.out.println(aa);
                c += n;
                //System.out.println("使用了" + n + "个" + coins[i]);
            }
            i--;
        }
        System.out.println(c);
    }
}
