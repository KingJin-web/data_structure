#include <bits/stdc++.h>
using namespace std;

struct action
{
    char a;
    int j;
};

struct action at[12][6] = {
    {{'S', 5}, {' ', 0}, {' ', 0}, {'S', 4}, {' ', 0}, {' ', 0}},
    {{' ', 0}, {'S', 6}, {' ', 0}, {' ', 0}, {' ', 0}, {'A', 0}},
    {{' ', 0}, {'R', 2}, {'R', 7}, {' ', 0}, {'R', 2}, {'R', 2}},
    {{' ', 0}, {'R', 4}, {'R', 4}, {' ', 0}, {'R', 4}, {'R', 4}},

    {{'S', 5}, {' ', 0}, {' ', 0}, {'S', 4}, {' ', 0}, {' ', 0}},
    {{' ', 0}, {'R', 6}, {'R', 6}, {' ', 0}, {'R', 6}, {'R', 6}},
    {{'S', 5}, {' ', 0}, {' ', 0}, {'S', 4}, {' ', 0}, {' ', 0}},
    {{'S', 5}, {' ', 0}, {' ', 0}, {'S', 4}, {' ', 0}, {' ', 0}},

    {{' ', 0}, {'S', 6}, {' ', 0}, {' ', 0}, {'S', 11}, {' ', 0}},
    {{' ', 0}, {'R', 1}, {'S', 7}, {' ', 0}, {'R', 1}, {'R', 1}},
    {{' ', 0}, {'R', 3}, {'R', 3}, {' ', 0}, {'R', 3}, {'R', 3}},
    {{' ', 0}, {'R', 5}, {'R', 5}, {' ', 0}, {'R', 5}, {'R', 5}},

    //GOTO

};

int gt[12][3] =
    {
        {1, 2, 3},
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
        {8, 3, 2},
        {0, 0, 0},
        {0, 9, 3},
        {0, 0, 10},
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
};

struct production
{
    int col;
    int len;
};

struct production pd[7] =
    {
        {0, 0},
        {0, 3},
        {0, 1},
        {1, 3},
        {1, 1},
        {2, 3},
        {2, 1},

};
int st[100] = {0};
int sp = 0;
char buf[100];
int p = 0;

int main(int argc, char const *argv[])
{
    char c;
    int s;
    int sn;
    int r;
    int j;
    printf("Input string include : i + * () End #\n");
    gets(buf);
    c = buf[p++];
    s = st[sp];
    while (1)
    {
        switch (c)
        {
        case 'i':
            r = 0;
            break;
        case '+':
            r = 1;
            break;
        case '*':
            r = 2;
            break;
        case '(':
            r = 3;
            break;
        case ')':
            r = 4;
            break;
        case '#':
            r = 5;
            break;
        }

        if (at[s][r].a == 'S')
        {
            st[++sp] = at[s][r].j;
            s = st[sp];
            c = buf[p++];
        }
        else if(at[s][r].a == 'R')
        {
            j = at[s][r].j;
            sp = sp - pd[j].len;
            sn = st[sp];
            st[++sp] = gt[sn][pd[j].col];
            s = st[sp];
        }
        else if (at[s][r].a == 'A')
        {
            printf("Right!\n");
            break;
        }else
        {
            printf("Woring! Position = %d Symbol = %c\n", p, c);
            break;
        }
        
    }

    return 0;
}
