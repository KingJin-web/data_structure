#include "GameLib.h"
/*******************************
*文件名：GameLib.c
*实现Game.h中定义的操作函数
*******************************/


void SetTitle(char *title)
{
    SetConsoleTitle(title);
}
void SetColor(int foreColor, int backColor)
{
    HANDLE winHandle;       //句柄
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);    //拿到控制台窗口
    //设置文字颜色
    SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);
}

void SetPosition(int x, int y)
{
    HANDLE winHandle;       //句柄
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);    //拿到控制台窗口
    COORD pos = {x, y};
    /*设置光标的位置*/
    SetConsoleCursorPosition(winHandle, pos);
}
