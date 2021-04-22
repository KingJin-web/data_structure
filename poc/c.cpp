#include <windows.h>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
char m[5][6][10] = {
    {"MT", "", "", "MT", "", ""},
    {"", "MT+", "", "", "\a", "\a"},
    {"NF", "", "", "NF", "", ""},
    {"", "\a", "NF*", "", "\a", "\a"},
    {"i", "", "", ")E(", "", ""}};

char st[100];
int sp = 0;
char buf[100];
int p = 0;
char t[10] = "i+*()#";

void push(char c)
{
    st[++sp] = c;
}

void pop()
{
    sp--;
}

int isterminal(char c)
{
    int i;
    for (i = 0; t[i] != '\0'; i++)
    {
        if (c == t[i])
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int flag = 1;
    int row, col;
    int i;
    char x;
    char c;
    printf("Input string include : i + * () End #\n");
    gets(buf);
    c = buf[p++];
    push('#');
    push('E');
    while (flag)
    {
        x = st[sp];
        if (isterminal(x))
        {
            if (x == c)
            {
                if (c = '#')
                {
                    printf("Right !");
                }
                else
                {
                    pop();
                    c = buf[p++];
                }
            }
            else
            {
                printf("Woring! Postion = %d Symbol = %c\n", p, c);
                flag = 0;
            }
        }
        else
        {
            switch (x)
            {
            case 'E':
                row = 0;
                break;
            case 'M':
                row = 1;
                break;
            case 'T':
                row = 2;
                break;
            case 'N':
                row = 3;
                break;
            case 'F':
                row = 4;
                break;
            default:
                break;
            }
            switch (c)
            {
            case 'i':
                row = 0;
                break;
            case '+':
                row = 1;
                break;
            case '*':
                row = 2;
                break;
            case '(':
                row = 3;
                break;
            case ')':
                row = 4;
                break;
            case '#':
                row = 5;
                break;
            default:
                break;
            }
            if (m[row][col][0] != '\0')
            {
                pop();
                if (m[row][col][0] != '\a')
                {
                    for (i = 0; m[row][col][i] != '\0'; i++)
                    {
                        push(m[row][col][i]);
                        printf("aa");
                   }
                   
                }
                
            }else
            {
                printf("Woring! Postion = %d Symbol = %c\n", p, c);
                flag = 0;
            }
            
            
        }

        return 0;
    }
}