#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

//1.用递归找个整数数组的最大值
int maxNum(int a[], int begin);
//2.用递归实现冒泡排序
void sort2(int arr[], int left, int right);
void sort(int a[],int length)
{
    for (int j = length - 1; j > 0; j--)
    {
        if (a[j] < a[j - 1])
        {
            int t = a[j];
            a[j] = a[j - 1];
            a[j - 1] = t;
            sort(a,length);
        }
    }
}

//3． 整数因子分解问题
void divide(int n);
//4.参见教材整数划分问题（打印出各种划分方案）
void show(int *dnum, int len);
int q(int n, int m, int *dnum, int len);
int maxNum(int *arr, int n)
{
    if (n == 1)
        return arr[0];
    int tem = maxNum(arr + 1, n - 1);
    return max(arr[0], tem);
}
int fundMax(int a[], int n)
{
    if (n >= 1)
    {
        if (fundMax(a, n - 1) > a[n])
            return fundMax(a, n - 1);
        else
            return a[n];
    }
    else
        return a[0];
}
void sort(int arr[], int left, int right)
{
    int count = 0;
    if (right < 1)
    {
        return;
    }
    count++;

    if (arr[left] > arr[left + 1])
    {
        int temp = arr[left + 1];
        arr[left + 1] = arr[left];
        arr[left] = temp;
    }

    if (left >= right)
    {
        sort(arr, 0, right - 1);
    }
    else
    {
        sort(arr, left + 1, right);
    }
}

void printfArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//整数因子分解
int qq = 0;
void divide(int n)
{

    if (n == 1)
    {

        qq++;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                // printf("%d ",i);
                divide(n / i);
            }
        }

        printf("\n");
    }
}

//4.参见教材整数划分问题（打印出各种划分方案）
void show(int *dnum, int len)
{
    int i;
    printf("%d=", dnum[0]);
    if (len == 1)
    {
        printf("%d", dnum[1]);
    }
    else
    {
        for (i = 1; i < len - 1; i++)
        {
            printf("%d+", dnum[i]);
        }
    }
    printf("%d\n", dnum[len - 1]);
}

//递归划分整数，n为待划分的整数，m为最大加数上限
int q(int n, int m, int *dnum, int len)
{

    if (n >= 0 && m == 1)
    {
        if (n == 0)
        {
            show(dnum, len);
        }
        else
        {
            dnum[len] = 1;
            q(n - 1, m, dnum, len + 1);
        }
        return 1;
    }
    else if (n == 1 && m > 1)
    {
        dnum[len] = n;
        show(dnum, len + 1);
        return 1;
    }
    //当n<m时候的情况
    else if (n < m)
    {
        return q(n, n, dnum, len);
    }
    //当n=m时候的情况
    else if (n == m)
    {
        dnum[len] = m;
        show(dnum, len + 1);
        return q(n, m - 1, dnum, len) + 1;
    }
    //当n>m>1时候的情况
    else
    {
        dnum[len] = m;
        return q(n - m, m, dnum, len + 1) + q(n, m - 1, dnum, len);
    }
}

void c5()
{
    double s, a, b, x;
    cin >> s >> a >> b;
    x = (a + b) * s / (3 * a + b);
    printf("%.6f", x / b + (s - x) / a);
}
void test5(){
    double s, s1, s2, v1, v2, t1, t2, p;
    double a, b;
    scanf("%lf%lf%lf", &s, &v1, &v2);
    s1 = 0;
    s2 = s;
    do
    {
        p = (s1 + s2) / 2.0;
        a = p / v2;
        b = (p - a * v1) / (v1 + v2);
        t1 = a + (s - p) / v1;
        t2 = a + b + (s - (a + b) * v1) / v2;
        if (t1 < t2)
            s2 = p;
        else
            s1 = p;
    } while (fabs(t1 - t2) > 1e-8);
    printf("%.10e", t1);
}
int main(int argc, char const *argv[])
{
    test5();
     int arr[] = {1, 9, 2, 8, 1, 3, 9, 488, 49, 46};
    int length = sizeof(arr) / sizeof(int);

    //1
   // printf("%d\n", fundMax(arr, length));

     printfArr(arr, length);

    //2
    sort(arr, length );

    printfArr(arr, length);

    //3
    // divide(12);
    // printf("%d ", qq);

    // int dnum[100] = {0};
    // int t, len;
    // len = 1;
    // printf("please enter the a:");
    // scanf("%d", dnum);
    // printf("the result is:\n");
    // t = q(dnum[0], dnum[0], dnum, len);
    // printf("the a is:%d\n", t);

    // c5();
    return 0;
}
