/**
 * 输入的第一行是一个待查找的字符。第二行是一个以回车结束的非空字符串（不超过80个字符）。
 * 如果找到，在一行内按照格式“index = 下标”输出该字符在字符串中所对应的最大下标（下标从0开始）；否则输出"Not Found"。
 * */
#include<stdio.h>
#include<string.h>
int main()
{
    char s[80];
    char sh;
    int i,len,index = -1;
    sh = getchar();
    scanf("%s",&s);
    len = strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i] == sh)
            {
                index = i;
            }
        }
    if(index == -1)
        printf("Not Found");
    else 
        printf("index = %d",index);
}
