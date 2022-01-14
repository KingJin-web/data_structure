#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "GameLib.h"
#include "Game.h"
#include <math.h>
#include "GameLib.c"
#include "Game.c"
extern int X, Y;

int main()
{

    char key;           //接收的用户按键
    SetTitle("笑傲江湖之精忠报国");
    /*SetColor(4, 7);
    Register();
    Show();*/
    SetColor(10, 0);
    ShowWelcome();
    ShowMap();
    ShowInfmation();
    ShowMainMenu();
    while(1)
    {
        key = getch();      //getchar
        if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5')
        {
            printf("1~5之间的菜单");
        }
        else if(key == 37)  //左键
        {
            X--;
        }
        else if(key == 38)  //上键
        {
            Y--;
        }
        else if(key == 39)  //右键
        {
            X++;
        }
        else if(key == 40)  //下键
        {
            Y++;
        }
        if(X > 7) X = 0;
        if(X < 0) X = 7;
        if(Y > 7) Y = 0;
        if(Y < 0) Y = 7;
        ShowMap();  //重新显示地图
    }
    return 0;
}
