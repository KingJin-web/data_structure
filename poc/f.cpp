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
    {{' ', 0}, {'R', 2}, {'S', 7}, {' ', 0}, {'R', 2}, {'R', 2}},
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
typedef struct stack
{
    int s;
    int v;
} Stack;
Stack st[100] = {{0, 0}};

int sp = 0;
char buf[100];
int p = 0;

int main(int argc, char const *argv[])
{
    char c;
    int s;
    int v;
    int sn;
    int r;
    int j;
    printf("");
    gets(buf);
    s = st[sp].s;
    c = buf[p++];
    while (1)
    {
        if (c >= '0' && c <= '9')
        {
            v = c - '0';
            c = 'd';
        }
        switch (c)
        {
        case 'd':
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
            sp++;
            st[sp].s = at[s][r].j;
            if (c == 'd')
                st[sp].v = v;
            s = st[sp].s;
            c = buf[p++];
        }
        else if (at[s][r].a == 'R')
        {
            j = at[s][r].j;
            switch (j)
            {
            case 1:
                st[sp - 2].v = st[sp - 2].v + st[sp].v;
                break;
            case 3:
                st[sp - 2].v = st[sp - 2].v * st[sp].v;
                break;
            case 5:
                st[sp - 2].v = st[sp-1].v;
                break;
            }
            sp = sp -pd[j].len;
            sn = st[sp].s;
            st[++sp].s = gt[sn][pd[j].col];
            s = st[sp].s;
        }
        else if (at[s][r].a == 'A')
        {
            printf("Right!\n");
            printf("Value= %d\n",st[sp].v);
            break;
        }
        else
        {
            printf("Woring! Position = %d Symbol = %c\n", p, c);
            break;
        }
    }

    return 0;
}
