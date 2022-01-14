#include "Game.h"
    int id;             //编号
    char name[50];      //道具名称
    int leve;           //道具级别
    int stock;          //道具库存
    double price;       //道具的单价
    PropType type;      //道具类型
    union{//联合，多选1 对应道具相应类型的数值
        int attack;     //对应武器攻击力
        int defence;    //对应防具防御力
        int power;      //血瓶蓝瓶对应值
    };
    char desc[200];     //道具描述
Prop propArray[] = {
    {1, "长剑", 1, 100, 5000, Weapon, .minAttack=1, .maxAttack=5, "攻击力增加1~5"},
    {2, "布甲", 2, 100, 10000, Armor, .minDefence=2, .maxDefence=6, "防御力增加2~6"},
    {3, "饼干", 3, 100, 20000, Con, .minPower=3, .maxPower=10, "血量增加3~10"},
};
Map mapArray[8][8] = {
    {
        {1, "天山", 1, {0, 0}, "这里充满了灵力"}, {2, "楼兰", 1, {0, 1}, "这里充满了灵力"},
        {3, "白蛇山", 1, {0, 3}, "这里充满了灵力"}, {4, "野猪林", 1, {0, 4}, "这里充满了灵力"},
        {5, "水晶洞", 1, {0, 5}, "这里充满了灵力"}, {6, "天蚕洞", 1, {0, 6}, "这里充满了灵力"},
        {7, "黑风暴", 1, {0, 7}, "这里充满了灵力"}, {8, "冰火岛", 1, {0, 8}, "这里充满了灵力"},
    },
    {
        {9, "迷宫", 2, {1, 1}, "这里充满了灵力"}, {10, "凌霄城", 2, {1, 2}, "这里充满了灵力"},
        {11, "轩辕岭", 2, {1, 3}, "这里充满了灵力"}, {12, "华山", 2, {1, 4}, "这里充满了灵力"},
        {13, "嵩山", 2, {1, 5}, "这里充满了灵力"}, {13, "紫禁城", 2, {1, 6}, "这里充满了灵力"},
        {15, "快活林", 2, {1, 7}, "这里充满了灵力"}, {16, "神龙岛", 2, {1, 8}, "这里充满了灵力"},
    },
    {
        {17, "西域", 3, {2, 1}, "这里充满了灵力"}, {18, "葫芦岛", 3, {2, 2}, "这里充满了灵力"},
        {19, "唐门", 3, {2, 3}, "这里充满了灵力"}, {20, "终南山", 3, {2, 4}, "这里充满了灵力"},
        {21, "石窟", 3, {2, 5}, "这里充满了灵力"}, {22, "客栈", 3, {2, 6}, "这里充满了灵力"},
        {23, "玉皇顶", 3, {2, 7}, "这里充满了灵力"}, {24, "灵蛇岛", 3, {2, 8}, "这里充满了灵力"},
    },
    {
        {25, "光明顶", 4, {3, 1}, "这里充满了灵力"}, {26, "摩天崖", 4, {3, 2}, "这里充满了灵力"},
        {27, "聚贤庄", 4, {3, 3}, "这里充满了灵力"}, {28, "后山", 4, {3, 4}, "这里充满了灵力"},
        {29, "武当山", 4, {3, 5}, "这里充满了灵力"}, {30, "开封府", 4, {3, 6}, "这里充满了灵力"},
        {31, "二十四桥", 4, {3, 7}, "这里充满了灵力"}, {32, "蓬莱仙境", 4, {3, 8}, "这里充满了灵力"},
    },
    {
        {33, "擂鼓山", 5, {5, 1}, "这里充满了灵力"}, {34, "峨眉山", 5, {5, 2}, "这里充满了灵力"},
        {35, "迷踪山", 5, {5, 3}, "这里充满了灵力"}, {36, "五虎岭", 5, {5, 4}, "这里充满了灵力"},
        {37, "天宁寺", 5, {5, 5}, "这里充满了灵力"}, {38, "积善堂", 5, {5, 6}, "这里充满了灵力"},
        {39, "镇江府", 5, {5, 7}, "这里充满了灵力"}, {40, "桃花岛", 5, {5, 8}, "这里充满了灵力"},
    },
    {
        {41, "恶人谷", 6, {6, 1}, "这里充满了灵力"}, {42, "大理", 6, {6, 2}, "这里充满了灵力"},
        {43, "百花谷", 6, {6, 3}, "这里充满了灵力"}, {44, "孔雀山庄", 6, {6, 4}, "这里充满了灵力"},
        {45, "五霸岗", 6, {6, 5}, "这里充满了灵力"}, {46, "万仞堂", 6, {6, 6}, "这里充满了灵力"},
        {47, "千年古刹", 6, {6, 7}, "这里充满了灵力"}, {48, "六和塔", 6, {6, 8}, "这里充满了灵力"},
    },
    {
        {49, "玩偶庄", 7, {7, 1}, "这里充满了灵力"}, {50, "黑木崖", 7, {7, 2}, "这里充满了灵力"},
        {51, "蝴蝶谷", 7, {7, 3}, "这里充满了灵力"}, {52, "铁花堡", 7, {7, 4}, "这里充满了灵力"},
        {53, "霹雳堂", 7, {7, 5}, "这里充满了灵力"}, {54, "关帝庙", 7, {7, 6}, "这里充满了灵力"},
        {55, "麒麟庄", 7, {7, 7}, "这里充满了灵力"}, {56, "销魂宫", 7, {7, 8}, "这里充满了灵力"},
    },
    {
        {57, "石府", 8, {8, 1}, "这里充满了灵力"}, {58, "金三角", 8, {8, 2}, "这里充满了灵力"},
        {59, "忏悔崖", 8, {8, 3}, "这里充满了灵力"}, {60, "通吃岛", 8, {8, 4}, "这里充满了灵力"},
        {61, "通天观", 8, {8, 5}, "这里充满了灵力"}, {62, "紫霞亭", 8, {8, 6}, "这里充满了灵力"},
        {63, "天弃庵", 8, {8, 7}, "这里充满了灵力"}, {64, "侠客岛", 8, {8, 8}, "这里充满了灵力"},
    },

};
void Init()    //初始化数据
{

}

void Show()    //显示全局数据
{
    int propCount = sizeof(propArray) / sizeof(Prop);
    int i,j;
    /*for(i = 0; i < propCount; i++)
    {
        printf("%d\t%s\t%.0lf\n", propArray[i].id, propArray[i].name, propArray[i].price);
        switch(propArray[i].type)
        {
            case Weapon:
            printf("最小攻击力：%d\t最大攻击力：%d\n", propArray[i].minAttack, propArray[i].maxAttack);
            break;
            case Armor:
            printf("最小防御力：%d\t最大防御力：%d\n", propArray[i].minDefence, propArray[i].maxDefence);
            break;
        }
    }*/
    printf("                                     地图信息\n");
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            printf("%-10s",mapArray[i][j].name);
        }
        printf("\n");
    }
}

void Register()
{
    printf("                                游戏登录页面\n");
    char username[50];      //玩家用户名
    char password[50];      //玩家密码
    printf("账号注册\t账号\t");
    gets(username);
    printf("                密码\t");
    gets(password);
    printf("\n");
    printf("                                欢迎来到笑傲江湖\n\n");
}
/*显示游戏欢迎页面*/
void ShowWelcome()
{
    /*1,所显示的文字 2，控制光标*/
    SetPosition(MARGIN_X, 0);
    printf("%s\n", SEP);
    SetPosition(MARGIN_X, 1);
    printf("|");
    SetPosition(MARGIN_X + 30, 1);
    printf("%s\n", GAME_NAME);
    SetPosition(MARGIN_X + 77, 1);
    printf("|");
    SetPosition(MARGIN_X, 2);
    printf("%s\n", SEP);
}
/*显示游戏地图*/
void ShowMap()
{
    /*要根据当前玩家的坐标显示地图的文字*/
    int i, j;
    printf("\n");
    for(i = 0; i < 8; i++)
    {
        SetPosition(MARGIN_X, 3 + i);
        for(j = 0; j < 8; j++)
        {
            if(j == 0)
                printf("|   ");
            if(i == Y && j == X)
            {
                //更改当前地图的颜色和背景色
                SetColor(5,10);
            }
            printf("%-9s", mapArray[i][j].name);
            //打印完当前地图后，将颜色变回默认颜色
            SetColor(10,0);
        }
        SetPosition(MARGIN_X + 77, 3 + i);
        printf("|");
        SetPosition(MARGIN_X, 11);
        printf(SEP);
    }
}
/*显示游戏地图下方的游戏信息*/
void ShowInfmation()
{
    SetPosition(MARGIN_X, 12);
    int i;
    for(i = 0; i < 7; i++)
    {
        SetPosition(MARGIN_X, 12 + i);
        printf("|");
        SetPosition(MARGIN_X + 77, 12 + i);
        printf("|");
    }
    SetPosition(MARGIN_X, 19);
    printf(SEP);
}
/*显示游戏菜单*/
void ShowMainMenu()
{
    SetPosition(MARGIN_X, MAINMENU_START_Y);
    printf("游戏菜单：");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 1);
    printf("1,查看个人信息");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 2);
    printf("2,查找怪物");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 3);
    printf("3,回到总部");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 4);
    printf("4,购买装备");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 5);
    printf("5，退出游戏");
}









