#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#define _INT_MAX_  10
using namespace std;

//插入排序
void insert_Sort(int *a,int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        int j=0;
        for(j=i-1;j>=0;j--)
        {
            if(temp<a[j])
            {
                a[j+1]=a[j];
            }else{
                break;
            }
        }
        a[j+1]=temp;
    }
}

//冒泡排序
void Bubble_Sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
}

//选择排序
void selectSort(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minj=0;
        int min=_INT_MAX_;
        for(int j=i;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                minj=j;
            }
        }
        swap(a[i],a[minj]);

    }
}

int onePartion(int *a,int left,int right)
{
    int pivot=a[left];
    int i=left;
    int j=right;
    while(i<j)
    {
        while(i<j&&a[j]>pivot)
        {
            j--;
        }
        swap(a[i],a[j]);
        while(i<j&&a[i]<pivot)
        {
            i++;
        }
        swap(a[i],a[j]);
    }
    return j;
}

//快速排序
void quickSort(int *a,int left,int right)
{
    if(left>=right)
    {
        return ;
    }
    int k=onePartion(a,left,right);
    quickSort(a,left,k-1);
    quickSort(a,k+1,right);
}

void merge(int *a,int *b,int low,int high)
{
    int mid=(low+high)/2;
    int i=low;
    int j=mid+1;
    int bindex=low;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
        {
            b[bindex++]=a[i];
            i++;
        }else{
            b[bindex++]=a[j];
            j++;
        }
    }
    for(;i<=mid;i++)
    {
        b[bindex++]=a[i];
    }
    for(;j<=high;j++)
    {
        b[bindex++]=a[j];
    }
}

void mergeSort(int a[],int b[],int low,int high)
{
    if(low>high)
    {
        return;
    }
    if(low==high)
    {
        b[low]=a[low];
        return;
    }
    int mid=(low+high)/2;
    mergeSort(a,b,low,mid);
    mergeSort(a,b,mid+1,high);

    merge(b,a,low,high);
    for(int i=low;i<=high;i++)
    {
        b[i]=a[i];
    }
}


void BuildMaxHead(int *a,int n,int heap[],int &headLen)
{
    for(int i=0;i<n;i++)
    {
        int pos=headLen;
        heap[pos]=a[i];
        headLen++;

        int currentPos=pos;
        int parentPos=currentPos/2;
        while(parentPos>=0)
        {
            if(heap[currentPos]>heap[parentPos])
            {
                swap(heap[currentPos],heap[parentPos]);
            }
            if(parentPos==0)
            {
                break;
            }
            currentPos=parentPos;
            parentPos=currentPos/2;
        }
    }
}
void printMaxHeap(int heap[],int heapLen)
{
    if(heapLen==0)
    {
        return;
    }
    cout<<heap[0]<<" ";
    heap[0]=heap[heapLen-1];
    int currentPos = 0;
    int lefSon=2*currentPos;
    int rightSon=lefSon+1;
    while(true)
    {
        if(rightSon>heapLen-1||lefSon>heapLen-1)
        {
            break;
        }
        if(heap[currentPos]>=heap[lefSon]&&heap[currentPos]>=heap[rightSon])
        {
            break;
        }else{
            if(heap[lefSon]>heap[rightSon])
            {
                swap(heap[currentPos],heap[lefSon]);
                currentPos=lefSon;
                lefSon=2*currentPos;
                rightSon=lefSon+1;
            }else{
                swap(heap[currentPos],heap[rightSon]);
                currentPos=rightSon;
                lefSon=2*currentPos;
                rightSon=lefSon+1;
            }
        }
    }
    printMaxHeap(heap,heapLen-1);
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

void quick_sort(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}


int PartSort(int*arr, int left, int right)
{
    assert(arr);

    int begin = left, end = right;
    int key = arr[right];
    while (begin < end)
    {
        while (begin < end && arr[begin] <= key)
            ++begin;

        arr[end] = arr[begin];

        while (begin < end && arr[end] >= key)
            --end;

        arr[begin] = arr[end];
    }

    arr[begin] = key;

    return begin;
}

void QuickSort(int*arr,int left,int right)
{
    assert(arr);

    if (left >= right)  //1 2 3 4这时就会出现 left>right 的情况
        return;

    int div = PartSort(arr,left,right);

    QuickSort(arr,left,div-1);
    QuickSort(arr,div+1,right);
}

int main()
{
    int a[20]={0};
    srand((int)time(NULL));
    for(int i=0;i<20;i++)
        a[i]=rand()%100;//伪随机数
    int n=sizeof(a)/4;
    int heap[12];
    for(size_t i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // insert_Sort(a,n);
    // cout<<"插入排序:";
    // for(int i=0;i<n;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    selectSort(a,n);
    cout<<"简单选择:";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // quick_sort(a,20);
    // cout<<"快速排序:";
    // for(int i=0;i<n;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    QuickSort(a,0,19);
    cout<<"快速排序:";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // Bubble_Sort(a,n);
    // cout<<"冒泡排序:";
    // for(int i=0;i<n;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    // int heapLen=0;
    // mergeSort(a,heap,0,n-1);
    // cout<<"归并排序:";
    // for(int i=0;i<n;i++)
    // {
    //     cout<<heap[i]<<" ";
    // }
    // cout<<endl;
    // BuildMaxHead(a,n,heap,heapLen);
    // cout<<"堆排序:";
    // printMaxHeap(heap,heapLen);
    return 0;
}