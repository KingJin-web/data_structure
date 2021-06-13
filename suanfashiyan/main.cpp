#include <bits/stdc++.h>
using namespace std;

/**
 * 根据区间随机
 * @param start
 * @param end
 * @return
 */
int mt_rand(int start, int end)
{
    srand(time(0));
    return rand() % (end + 1 - start) + start; /*生成一个[start,end)区间内的整数*/
}

int main(int argc, char const *argv[])
{
    while (1)
    {cout<<mt_rand(1000,10000)<<endl;
        _sleep(100);
    }
    
    
    
    return 0;
}
