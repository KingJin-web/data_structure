#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED
/*******************************
*文件名：GameLib.h
*用来定义游戏中常用的系统操作
*例如：更改文字颜色，清屏等
*******************************/
#include<stdio.h>
#include<windows.h>
/*设置控制台的标题*/
void SetTitle(char *title);
/*设置游戏的前景色（文字颜色）和背景色*/
void SetColor(int foreColor, int backColor);
/*设置光标的位置*/
void SetPosition(int x, int y);
#endif // GAMELIB_H_INCLUDED
