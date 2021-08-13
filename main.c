#include <bits/stdc++.h>
// int main(int argc, char const *argv[])
// {

//     int i = 5;
//     int j = 5;
//     int a = (i++) + (i++) + (i++);
//     int b = (++j) + (++j) + (++j);

//     printf("%d\n", a);
//     printf("%d\n", b);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define N 5
// int main()
// {
//     int i;
//     int sum = 0;
//     double avg;
//     int searchNum;
//     int nums[] = {8, 4, 2, 1, 23, 344, 12};
//     printf("输出数组元素:\n");

//     for (i = 0; i < 7; i++)
//     {
//         printf("%d\t", nums[i]);
//     }
//     printf("\n*******************\n");
//     for (i = 0; i < 7; i++)
//     {
//         sum += nums[i];
//     }
//     avg = sum / 7.0;
//     printf("请输入要查找的数字:");
//     scanf("%d", &searchNum);
//     for (i = 0; i < 7; i++)
//     {
//         if (searchNum == nums[i])
//             ;
//         {
//             printf("缘分啊,找到了相同的元素!\n");
//             break;
//         }
//     }
//     if (i == 7)
//     {
//         printf("茫茫人海,没有找到合意的数字!\n");
//     }
// }

// #define a "你好"
// #define AREA(a, b) a + b
// int main(int argc, char const *argv[])
// {
//     int s = AREA(3, 4) * AREA(3, 4);
//     return 0;
// }

// union uni
// {
//     int a;
//     char b;
// };
// struct str
// {
//     int a;
//     char b;
// };
// int main(int argc, char **argv)
// {
//     printf("%d %d\n", sizeof(union uni), sizeof(struct str));
//     return 0;
// }

// #include <stdio.h>
// #pragma pack(2)
// struct A
// {
//     int a;
//     char b;
//     short c;
// } A;
// #pragma pack()

// #pragma pack(4)
// struct B
// {
//     char b;
//     int a;
//     short c;
// } B;
// #pragma pack()

// int main()
// {
//     printf("sizeof(A) = % d, sizeof(B) = % d\n", sizeof(A), sizeof(B));
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define N 5
// int main()
// {
//     int array[N] = {15, 20, 25, 30, 35};
//     //实现数组的逆序-原理就是数组的首位元素进行交换
//     int temp; //临时变量
//     int i;
//     int *ptr_array_start = array;       //指向数组首元素的指针
//     int *ptr_array_end = array + N - 1; //指向数组末元素的指针
//     while (ptr_array_start != ptr_array_end)
//     {
//         //首位交换，指针分别进行更新
//         temp = *ptr_array_start;
//         *ptr_array_end = temp;
//         //首元素指针要向后移动
//         ptr_array_start++;
//         //末元素指针要向前移动
//         ptr_array_end--;
//     }
//     /*for(i=0;i<N/2;i++)
//     {
//         //第i个的值和第N-i-1个值交换
//        // temp=array[i];
//        // array[i]=array[N-i-1];
//        // array[N-i-1]=temp;

//     }*/
//     printf("\n");
//     for (i = 0; i < N; i++)
//     {
//         printf("%d\t", *(array + i));
//     }
// }
// struct A
// {
//     unsigned int a;
//     char b[2];
//     double c;
//     short d;
// } Aa;

// int
// main(int argc, char const *argv[])
// {

//     printf("sizeof(A) = % d, sizeof(B) = % d\n", sizeof(Aa), sizeof(Aa.d));

//     return 0;
// }
#include <stdlib.h>
#define DECLARE(name, type) type name##_##type##_type
int main(void)
{
   
    
    return 0;
}
