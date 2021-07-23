#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
//需要在设置→编译器→链接器设置→其他链接器选项中添加：-lwinmm
//或Setting→Compiler→Linker settings→Other link option 添加：-lwinmm
/*
 * 需要特别列出的扩展知识点：
 * 1、播放声音的函数及链接器设置
 * 2、Sleep()函数
 * 3、字符串数组及简单的字符串函数，如比较、复制
 * 4、时间函数和exit函数
 */
#pragma comment(lib, "Winmm.lib")
#define DAY_COUNT 10
int main()
{
    int i;          //循环变量，多次使用
    int count = 5;  //存放当前娘娘的总数
    int currDay = 0;//游戏当前进行到了第几天
    int choice;     //用来存放用户的选择
    int tempCount;  //临时变量，用来存放好感度低于60的个数
    int index = -1; //用来存放删除、查找时的索引
    char name[8];   //用来存放用户输入的姓名
    //姓名数组，最多容纳6个字符串，每个字符串的最大长度为8个字符（英文）
    char names[6][8] = {"西施", "貂蝉", "王昭君", "杨玉环", "赵飞燕"};
    //级别数组，最多容纳5个字符串，每个字符串的最大长度为8个字符（英文）
    char levelNames[5][8] = {"贵人", "嫔妃", "贵妃", "皇贵妃", "皇后"};
    //用来存放每个妃子的等级，与levelNames联用。-1表示未启用
    int level[] = {0, 2, 0, 0, 0, -1};
    //用来存放每个妃子的好感度，-1表示未启用
    int loves[] = {100, 100, 100, 100, 100, -1};
    do{
        PlaySound(TEXT("sounds\\背景音乐.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        printf("第%d天：\n", ++currDay);
        printf("1、皇帝下旨选妃！\t（增加）\n");
        Sleep(500);
        printf("2、翻牌宠幸\t\t（修改状态）\n");
        Sleep(500);
        printf("3、打入冷宫！\t\t（删除）\n");
        Sleep(500);
        printf("4、朕的爱妃呢？\t\t（查找）\n");
        printf("陛下请选择：");
        scanf("%d", &choice);
        switch(choice){
        case 1://新增妃子，其他人好感度-10
            PlaySound(TEXT("sounds\\选妃.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            //首先判断数组长度是否可以增加元素
            if(count >= sizeof(level)/sizeof(int))
            {
                printf("\n后宫人满为患，陛下还是再等等吧！\n\n");
                break;
            }
            printf("爱江山更爱美人，万千佳丽一点红~\n");
            printf("娘娘名讳：");
            scanf("%s", name);
            //将新增元素放在count处
            strcpy(names[count], name);
            level[count] = 0;
            loves[count] = 100;
            printf("\n新增妃子，其他人好感度-10\n\n");
            for(i = 0; i < count; i++){
                loves[i] -= 10;
            }
            count++;
            break;
        case 2://翻牌宠幸，宠幸的妃子好感度+20，其他人-10
            PlaySound(TEXT("sounds\\翻牌.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("陛下请输入要宠幸的姓名：");
            scanf("%s", &name);
            for(i = 0; i < count; i++){
                if(strcmp(name, names[i]) == 0){
                    index = i;
                    continue;
                }
                loves[i] -= 10;
            }
            if(index == -1)//没有找到
            {
                printf("\n祖国尚未统一，怎能儿女情长！\n\n");
            }
            else
            {
                loves[index] += 20;
                //每临幸一次，级别提升1级，最高为4级，皇后
                level[index] == 4 ? 4 : level[index]++;
                printf("\n******************************\n");
                printf("Duang~%s提升等级为：%s\n", names[index], levelNames[level[index]]);
                printf("******************************\n\n");
                printf("憔悴容华怯对春，寂寥宫殿锁闭门。\n此身却羡宫中树，不失芳时雨露恩。 \n");
                printf("所有娘娘好感度-10！\n\n");
            }
            index = -1;
            break;
        case 3://打入冷宫，执行删除操作，其他妃子好感度统一+10
            PlaySound(TEXT("sounds\\冷宫.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("陛下要将哪位娘娘打入冷宫呢：");
            scanf("%s", &name);
            for(i = 0; i < count; i++){
                if(strcmp(name, names[i]) == 0){
                   index = i;
                   break;
                }
            }
            if(index == -1)//未找到要删除的姓名
            {
                printf("\n虚惊一场，无人打入冷宫，该吃吃该喝喝~\n\n");
                break;
            }
            //执行删除操作
            for(i = index; i < count - 1; i++)
            {
                strcpy(names[i], names[i + 1]);
                level[i] = level[i + 1];
                loves[i] = loves[i + 1];
            }
            count--;//总人数-1
            index = -1;//变量用完重置为初始值，方便下次使用
            printf("\n%s已被打入冷宫，人情冷暖，所有娘娘好感度+10！\n\n", name);
            for(i = 0; i < count; i++){
                loves[i] += 10;
            }
            index = -1;
            break;
        case 4://根据姓名查找，好感度+10
            PlaySound(TEXT("sounds\\一笑倾城.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            printf("请输入要查找的姓名：");
            scanf("%s", name);
            for(i = 0; i < count; i++){
                if(strcmp(name, names[i]) == 0){
                    printf("\n微微一笑挺倾城，%s的好感度+10\n\n", name);
                    loves[i] += 10;
                    break;
                }
            }
            break;
        }// end of switch
        printf("姓名\t等级\t好感度\n");
        printf("-----------------------\n");
        for(i = 0; i < count; i++){
            printf("%s\t%s\t%d\n", names[i], levelNames[level[i]], loves[i]);
        }
        //每天结算好感度，一旦有三个或以上的嫔妃好感度低于60，则发生暴乱，游戏结束
        tempCount = 0;//临时变量，用来存放好感度低于60的个数
        for(i = 0; i < count; i++){
            if(loves[i] < 60)
                tempCount++;
        }
        if(tempCount >= 3){
            printf("觉醒的嫔妃：姐妹们，组队刷皇上去了！\n");
            //时间函数的固定用法
            time_t timep;
            struct tm * p;
            time(&timep);
            p = gmtime(&timep);
            printf("公元%d年%d月%d日，皇帝卒！共执政%d天\n", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday, currDay);
            exit(0);
        }
    }while(currDay < DAY_COUNT);

    printf("皇帝登基10天来，五谷丰登、风调雨顺、妻妾成群。。。。。\n");
    printf("没羞没臊的生活继续进行着。。。。。。。\n");
    printf("姓名\t等级\t好感度\n");
    printf("-----------------------\n");
    for(i = 0; i < count; i++){
        printf("%s\t%s\t%d\n", names[i], levelNames[level[i]], loves[i]);

    }
    return 0;
}
