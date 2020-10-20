// 这是一个简单的模拟题,你-开始在坐标(0,0), 问你经过一系列走动后你所在的坐标是哪里。
//L表示向左走一步, R表示向右走一步, U表示向上走一步, D表示向下走-步。


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
    int x = 0,y = 0,n;
    
    char s;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        getchar();
        s = getchar();//scanf("%s",s);
        if (s=='L')
        {
           x =x - 1;
        }
         if (s=='R')
        {
           x =x + 1;
        }
         if (s=='U')
        {
           y = y + 1;
        }
         if (s=='D')
        {
           y = y - 1;
        }
        s = NULL;
    }
    printf("%d %d",x,y);

}