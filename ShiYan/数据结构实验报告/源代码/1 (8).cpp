// 1.插入排序
// 2.冒泡排序
// 3.简单选择
// 4.快速排序
// 5.归并排序
#include <iostream>
using namespace std;

// 1.插入排序
void insertion_sort(int *arr, int len) {
        int i,j,key;
        for (i=1;i<len;i++){
                key = arr[i];
                j=i-1;
                while((j>=0) && (arr[j]>key)) {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;
        }
}

// 2.冒泡排序
void bubble_sort(int *arr, int len) {
        int i, j, temp;
        for (i = 0; i < len - 1; i++)
                for (j = 0; j < len - 1 - i; j++)
                        if (arr[j] > arr[j + 1]) {
                                swap(arr[j], arr[j + 1]);
                        }
}
//3.简单选择
void selection_sort(int *arr, int len) 
{
    int i,j;

        for (i = 0 ; i < len - 1 ; i++)
    {
                int min = i;
                for (j = i + 1; j < len; j++)     //走訪未排序的元素
                        if (arr[j] < arr[min])    //找到目前最小值
                                min = j;    //紀錄最小值
                swap(arr[min], arr[i]);    //做交換
        }
}

int onePartion(int *a, int left, int right)
{
    int pivot = a[left];

    int i = left;
    int j = right;

    while (i < j) // i == j 交叉，结束
    {
        while (i < j && a[j] > pivot)
            j--;
        swap(a[i], a[j]);

        while (i < j && a[i] < pivot)
            i++;
        swap(a[i], a[j]);
    }

    return j;
}


void quick_sort1(int *arr, int left, int right)
{
    if (left >= right)
        return;

    int k = onePartion(arr, left, right); 

    quick_sort1(arr, left, k - 1);
    quick_sort1(arr, k + 1, right);
}
// 4.快速排序
void quick_sort(int *arr, int len) {
    int reg[len];
    quick_sort1(arr,  0, len - 1);
}

void merge_sort_recursive(int arr[], int reg[], int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}
// 5.归并排序
void merge_sort(int *arr, int len) {
    int reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}

void adjuctHeap(int i, int *arr, int count) {
    int tmp;
    int max;
    
    while(i <= count / 2 - 1) {                 // 条件判断检测是否到了叶子节点
        tmp = 2 * i + 2 >= count ? 0 : arr[2 * i + 2];               //总数为偶数，最后一个父节点没有右孩子
        max = arr[2 * i + 1] >= tmp ? 2 * i + 1 : 2 * i + 2;         //max值：左右孩子中更大的那个孩子节点的下标
        if(arr[max] > arr[i]) {
            tmp = arr[max];
            arr[max] = arr[i];
            arr[i] = tmp;         
            i = max;
        }                       
        else
            break;
    }
}

void heap_sort(int *arr, int count) {
    int i;
    int tmp;

    for(i = count / 2 - 1; i > 0; i--) {               // 停留在构造成功大根堆的前一步。 count / 2 - 1 表示倒数第一个非叶子节点。
        adjuctHeap(i, arr, count);
    }
    
    while(count > 1) {
        adjuctHeap(0, arr, count);                     // 构造大根堆
        tmp = arr[0];
        arr[0] = arr[count - 1];                       // 交换
        arr[count - 1] = tmp;
        --count;                                       // 末尾往前移动
    }
}

int main() {
    // 1.插入排序
// 2.冒泡排序
// 3.简单选择
// 4.快速排序
// 5.归并排序
        int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
        int len = (int) sizeof(arr) / sizeof(*arr);
        int i;
        cout<<"原数组："<<endl;
        for (i = 0; i < len; i++)
                printf("%d ", arr[i]);
        cout<<""<<endl;
        // insertion_sort(arr, len);
        // cout<<"插入排序："<<endl;

        // bubble_sort(arr, len);
        // cout<<"冒泡排序："<<endl;

        // selection_sort(arr,len);
        // cout<<"简单选择："<<endl;

        // quick_sort(arr,len );
        // cout<<"快速排序："<<endl;

        merge_sort(arr,len );
        cout<<"归并排序："<<endl;

        // heap_sort(arr,len);
        //cout<<""<<endl;
        
        for (i = 0; i < len; i++)
                printf("%d ", arr[i]);
        return 0;
}