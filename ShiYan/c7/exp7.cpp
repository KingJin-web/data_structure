#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/**
 * 
1.顺序查找：使用数组或链表结构，初始化相应数值(整数）， 输入待查找的整数，返回查找成功与否，若成功则返回该整数所在的位置（序号），并计算比较次数。

2.折半查找：用数组实现，查找前元素先排序。计算比较次数。分别用查找成功、不成功进行测试。

3. 在n个数中，找出出现次数最多那个数字，并且输出出现的次数。如果有多个结果，输出数字最小的那一个。
 * 
 * 
**/

//顺序查找
int seq_search(int arr[], int n, int key)
{
    int i;
    int c = 0;
    for (i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            printf("查找 %d 次\n", c);
            return i;
            //查找成功
        }
        else
        {
            c++;
        }
    }
    printf("查找 %d 次\n", c);
    return -1; //查找失败
}
// 2.冒泡排序
void bubble_sort(int *arr, int len)
{
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
}
//折半查找
int binary_search(int arr[], int k, int left, int right)
{
    bubble_sort(arr, right);
    int c = 0;
    printf("排序后：");
    for (int i = 0; i < right; i++)
        printf("%d ", arr[i]);
    printf("\n");
    while (left <= right) //建立一个循坏
    {
        int mid = left + (right - left) / 2;
        //cout<<arr[mid]<<endl;//下标中间值
        if (arr[mid] > k)
        {

            right = mid - 1;
        }
        else if (arr[mid] < k)
        {
            left = mid + 1;
        }
        else
        {
            c++;
            printf("查找了%d次\n", c);
            return mid; //走到这就是等于。K就是要找的 ,返回的是下标值
        }
        c++;
    }
    printf("查找了%d次\n", c);
    return -1;   //这里即left>right .找不到这个数
}

void test3(int arr[], int len)
{
    
    int ay[10000];
    int temp = 0;
    int i , j;
    int number1 = 0;
   
    int *amax = (int *)malloc(sizeof(int));
    *amax = arr[0];
    for (i = 0; i < len; i++)
    {
        if (*amax < arr[i])
            *amax = arr[i];
    }
    for (i = 0; i < len; i++)
    {
        temp = arr[i];

        ay[temp]++;
    }
    int *max = (int *)malloc(sizeof(int));
    *max = ay[0];

    for (j = 0; j <= *amax; j++)
    {
        if (*max < ay[j])
        {
            *max = ay[j];
            number1 = j;
        }
    }
    printf("%d\n", number1);
}

int main()
{

    //int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int arr[] = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 6, 7, 8, 9, 10};
    int len = (int)sizeof(arr) / sizeof(*arr);

    //test3(arr, len);

    printf("原数组：");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("出现最多的数字是：");
    test3(arr, len);
    // int key = 70;
    // int a = binary_search(arr, key, 0, len);

    //int a = seq_search(arr,len,key);
    // if (a != -1)
    // {
    //     printf("找到%d了：在序号是 %d ", key, a);
    // }
    // else
    // {
    //     printf("没找到 %d", key);
    // }
}