#include <windows.h>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
void E();
void M();
void T();
void N();
void F();

char buf[100];
int p = 0;
char c;

int main(int argc, char const *argv[])
{

    cout << "Input string, include: i + * () End #" << endl;
    gets_s(buf);
    //i+(i*i)#
    c = buf[p++];
    //cout << buf << "," << c << endl;
    E();
    //cout << c << endl;
    if (c == '#')
    {
        printf("Right!\n");
    }
    else
    {
        printf("Worng!\n");
    }

    return 0;
}

void E()
{
    T();
    M();
}

void M()
{
     
    if (c == '+')
    {
        c = buf[p++];
      
        E();
    }
}

void T()
{
    F();
    N();
}

void N()
{
    
    if (c == '*')
    {
        c = buf[p++];
        T();
    }
}

void F()
{
     
    if (c == '(')
    {
        c = buf[p++];
        E();
         
        if (c == ')')
        {
            c = buf[p++];
        }
        else
        {
            printf("Wrong\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
         
        if (c == 'i')
        {
            c = buf[p++];
        }
        else
        {

            printf("Wrong\n");
            exit(EXIT_FAILURE);
        }
    }
}