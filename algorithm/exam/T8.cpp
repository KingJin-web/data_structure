#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
/*
8、给定一个存放整数的数组，重新排列数组使得数组左边为偶数，右边为奇数。
如对数组：1,2,3,4,5,6,7,8,9处理后，该数组变为：2,4,6,8,1,3,5,7,9。
     解决思路：数组左边left，右边right。左边遇到第一个偶数停止，右边遇到第一个奇数停止。二者进行交换
     直到left>right操作结束
 */
void T8(int *arr, int length)
{
    int left = 0;
    int right = length - 1;
    int flag;
    while (left < right)
    {
        //如果为偶数 左下标 + 1
        if (arr[left] % 2 == 0)
        {
            left++;
            continue;
        }
        if (arr[right] % 2 != 0)
        {
            right--;
            continue;
        }

        flag = arr[left];
        arr[left++] = arr[right];
        arr[right--] = flag;
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]);

    T8(arr, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d,", arr[i]);
    }
    return 0;
}
