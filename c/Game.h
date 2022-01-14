#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#define SEP "------------------------------------------------------------------------------"
#define COL 78      //游戏界面的宽度
#define MARGIN_X 20 //左边距
#define MAP_START_Y 3
#define MAP_END_Y   11
#define INFO_START_Y  12
#define MAINMENU_START_Y 20
#define GAME_NAME "欢迎来到笑傲江湖！"
/*******************************
*文件名：Game.h
*用来定义游戏的一些核心结构和函数
*******************************/
#include<stdio.h>
#include<string.h>
#include<windows.h>

/***********************  游戏的结构类型定义   **************************/
/*假设当前用户的坐标是3，2*/
int X =3, Y = 2;
//玩家，地图，装备，怪物，
/*
*游戏地图结构
*编号，名称，介绍，玩家的进入等级,当前的地图坐标
*/
typedef struct _map{
    int id;             //地图编号
    char name[50];      //地图名称
    int minLevel;       //玩家的进入等级
    //坐标结构
    COORD coord;
    char desc[500];     //地图介绍
}Map;
/*游戏道具类型枚举-游戏道具  武器  防具  消耗品  卡片*/
typedef enum _proptype{
    Weapon, Armor, Con, Card, Frag
}PropType;
/*游戏道具  武器  防具  消耗品  卡片*/
typedef struct _prop{
    int id;             //编号
    char name[50];      //道具名称
    int leve;           //道具级别
    int stock;          //道具库存
    double price;       //道具的单价
    PropType type;      //道具类型
    union{//联合，多选1 对应道具相应类型的数值
        int minAttack;     //对应武器攻击力
        int minDefence;    //对应防具防御力
        int minPower;      //血瓶蓝瓶对应值
    };union{//联合，多选1 对应道具相应类型的数值
        int maxAttack;     //对应武器攻击力
        int maxDefence;    //对应防具防御力
        int maxPower;      //血瓶蓝瓶对应值
    };
    char desc[200];     //道具描述
}Prop;
typedef struct _players{
    int id;                 //玩家编号
    char username[50];      //玩家用户名
    char password[50];      //玩家密码

}Players;

void Init();    //初始化数据
void Show();    //显示全局数据
void Register();

/*显示游戏欢迎页面*/
void ShowWelcome();
/*显示游戏地图*/
void ShowMap();
/*显示游戏地图下方的游戏信息*/
void ShowInfmation();
/*显示游戏菜单*/
void ShowMainMenu();

#endif // GAME_H_INCLUDED
