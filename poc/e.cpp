
#include <bits/stdc++.h>
using namespace std;

int E();
int M(int);
int T();
int N(int);
int F();

char buf[100];
int p = 0;
char c;

int main(int argc, char const *argv[])
{
    int es;
    printf("11\n");
    gets(buf);
    c = buf[p++];
    es = E();
    if (c == '#')
    {
        printf("Right!\n");
        printf("Value= %d\n", es);
    }
    else
    {
        printf("Wrong!\n");
    }

    return 0;
}

int E()
{
    int es, ts, mi, ms;
    ts = T();
    mi = ts;
    ms = M(mi);
    es = ms;
    return es;
}
int M(int mi)
{
    int ms, ts, mls, mli;
    if (c == '+')
    {
        c = buf[p++];
        ts = T();
        mli = mi + ts;
        mls = M(mli);
        ms = mls;
    }
    else
    {
        ms = mi;
    }
    return ms;
}
int T()
{
    int ts, fs, ni, ns;
    fs = F();
    ni = fs;
    ns = N(ni);
    ts = ns;
    return ts;
}

int N(int ni)
{
    int ns, fs, nls, nli;
    if (c == '*')
    {
        c = buf[p++];
        fs = F();
        nli = ni * fs;
        nls = N(nli);
        ns = nls;
    }
    else
    {
        ns = ni;
    }

    return ns;
}
int F()
{
    int fs, es, ds;
    if (c == '(')
    {
        c = buf[p++];
        es = E();

        if (c == ')')
        {
            c = buf[p++];
            fs = es;
            return fs;
        }
        else
        {
            printf("Wrong!\n");
            exit(EXIT_FAILURE);
        }
    }

    else
    {
        if (c >= '0' && c <= '9')
        {
            ds = c - '0';
            c = buf[p++];
            fs = ds;
            return fs;
        }
        else
        {
            printf("Wrong!\n");
            exit(EXIT_FAILURE);
        }
    }
}