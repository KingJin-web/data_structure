#include <iostream>
#include <algorithm>
using namespace std;
#define N 100

int fmax(int a[], int i);

int main()
{
    int A[N], n, i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> A[i];
    int x = fmax(A, n);
    cout << x;
    return 0;
}

int fmax(int a[], int i){
    int max = a[0];
    for (int j = 0; j < i; j++)
    {
        if (max < a[j])
        {
            max = a[j];
        }
        
    }

    return max;
    
}

/* 请在这里填写答案 */