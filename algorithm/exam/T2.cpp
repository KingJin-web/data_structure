#include <cmath>
#include <iostream>
using namespace std;

//2。数组对称
bool isDuciCheng(int a[], int left, int right)
{
    if (left >= right)
        return true;

    bool b = a[left] == a[right] && isDuciCheng(a, left + 1, right - 1);
    return b;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, -1, -1, 1};
    int n = sizeof(arr) / sizeof(int) - 1;
    cout << isDuciCheng(arr, 0, n) << endl;
    return 0;
}
