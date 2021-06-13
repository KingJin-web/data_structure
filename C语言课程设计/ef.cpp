#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<string.h> 
#include<conio.h> 
#include<math.h>
#include<MMSystem.h>//导入声音头文件
#pragma comment(lib,"winmm.lib")

//手机开机倒计时
void one();
//手机主菜单选择
void mainmenu();
//外观
void waiguan();
//登录
void login();

//用户其他时间
void shijian();
//菜单显示时间
void menushijian();
//电量显示
void power();
//菜单
void menu();
//用户设置
void setmenu();
//用户设置密码
void setreg();
//工具箱
void tool();
//电话簿
void dianhuabu();
void query();
void showClientMenu();
void add();
void d();
void lookup();
int tmp=1; 
//拨号
void bohao();
//计算器
void jisuanqi();
void jia();
void jian();
void cheng();
void chu();
//音乐
void music();
void face();
void chosemusic();
void chosemusic1();
void chosemenu();

void chosemenu1();//功能选择菜单1
void chosemenu2();//2
void chosemenu3();
void chosemenu4();//3

void chosemenu1_1();//上一首
void chosemenu1_2();
void chosemenu1_3();

void chosemenu1_10();//下一首
void chosemenu1_20();
void chosemenu1_30();

void downmusic();

//坐标函数
void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

/*int color(int c){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);	
	return 0;
}*/
//隐藏光标
void HideCursor(){
CONSOLE_CURSOR_INFO cursor_info = {1, 0};
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

//开机用户登录
struct Emp{
	char name[20];
	char pwd[10];
};

struct Emp emps[]={
	{"523","123456"},0,0
};

//手机联系人
struct Client{
	int t;
	char name[20];
	char phone[20];
};
struct Client loginedClient;


	void main(){
		system("color FC");
		
		login();
	
	
		
		getch();
	 }

	void mainmenu(){
		
		char key;
		HideCursor();
	    menushijian();
		power();
		while(1){
		gotoxy(1,11);
		printf("7.菜单                      9.关机");
		key=getch();
		if(key=='7'){
			system("cls");
			menu();
			break;
		}if(key=='9'){
			system("cls");
			printf("再见\n");
			Sleep(500);
			gotoxy(5,8);
		    printf("手机将在3秒后关机");
				Sleep(500);
			system("cls");
			one();
			exit(0);
			break;
		}
	}
	}
	void power(){
		int power=100,cpu=50;
		char t='%';
		power--;cpu++;
		gotoxy(1,2);
		printf("电量:%d%c             内存使用:%d%c ",power,t,cpu,t);
}
 
    
//菜单
void menu(){
	
	int key;
	system("cls");
	waiguan();
	while(1){
	gotoxy(1,2);
	printf("菜 单:");
	//power();
	gotoxy(12,4);
	printf("1.电话簿");
	gotoxy(12,5);
	printf("2.拨号");
	gotoxy(12,6);
	printf("3.工具箱");
	gotoxy(12,7);
	printf("4.世界时间");
	gotoxy(12,8);
	printf("5.返回");
	key=getch();

		if(key=='1'){
		  dianhuabu();
		   break;
		}else if(key=='2'){
		   bohao();
		  break;
		}else if(key=='3'){
		  tool();
		    break;
		}else if(key=='4'){
             shijian();
			break;
		}else if(key=='5'){
			system("cls");
			mainmenu();
			break;
		}
	}
}
//工具箱
	void tool(){
	char key;
	system("cls");
	waiguan();
	while(1){
	gotoxy(1,2);
	printf("工具箱:");
	gotoxy(12,6);
	printf("1.大熊音乐");
	gotoxy(12,7);
	printf("2.计算器");
	gotoxy(12,8);
	printf("3.返回");
	key=getch();

	if(key=='1'){
		music();
		break;
	}else if(key=='2'){
		jisuanqi();
		break;
	}else if(key=='3'){
		menu();
		break;
	}	
	}	
}
	//设置
/*	void setmenu(){
	char key;
	system("cls");
	waiguan();
	while(1){
	gotoxy(1,2);
	printf("设 置:");
	gotoxy(12,6);
	printf("1.时间显示");
	gotoxy(12,7);
	printf("2.修改登录密码");
	gotoxy(12,8);
	printf("3.返回");
	key=getch();

	if(key=='1'){
		shijian();
		break;
	}else if(key=='2'){
		
	}else if(key=='3'){
		
		menu();
		break;
	}	
	}	
}*/
//修改登录密码
	/*void setmenu(){
		struct Emp set;
		FILE*file;
		printf("\n请输入用户名：");
		scanf("%s",set.name);
		printf("\n请输入密码：");
		scanf("%s",set.pwd);*/
	void jia(){
		char key;
double bNumber, Number, Result; 
			system("cls");
			waiguan();
			 gotoxy(1,2);
			printf("计算器:");
            printf ("        请输入被加数:");
            scanf ("%lf",&bNumber);
            printf ("        请输入加数:");
            scanf ("%lf",&Number);
            Result = bNumber + Number;
            printf (" 结果是: %lf\n\n",Result);
			while(1){
				gotoxy(1,11);
		printf("1.返回");
	key=getch();
		if(key=='1'){
		tool();
		break;
		}
			}
	}
	void jian(){
		char key;
		double bNumber, Number, Result; 
		system("cls");
						waiguan();
						 gotoxy(1,2);
						printf("计算器:");
                        printf ("        请输入被减数:");
                        scanf ("%lf",&bNumber);
                        printf ("        请输入减数:");
                        scanf ("%lf",&Number);
                        Result = bNumber - Number;
                        printf (" 结果是: %lf\n\n",Result);
						while(1){
				gotoxy(1,11);
		printf("1.返回");
	key=getch();
		if(key=='1'){
	tool();
		break;
		}
			}
	}
	void cheng(){
		char key;
		double bNumber, Number, Result; 
		system("cls");
						waiguan();
						 gotoxy(1,2);
						printf("计算器:");
                        printf ("        请输入被乘数:");
                        scanf ("%lf",&bNumber);
                        printf ("        请输入乘数:");
                        scanf ("%lf",&Number);
                        Result = bNumber * Number;
                        printf (" 结果是: %lf\n\n",Result);
						while(1){
				gotoxy(1,11);
		printf("1.返回");
	key=getch();
		if(key=='1'){
		tool();
		break;
		}
			}
	}
	void chu(){
		char key;
		double bNumber, Number, Result; 
			system("cls");
						waiguan();
						 gotoxy(1,2);
						printf("计算器:");
                        printf ("        请输入被除数:");
                        scanf ("%lf",&bNumber);
                        printf ("        请输入除数:");
                        scanf ("%lf",&Number);
                        Result = bNumber / Number;
                        printf (" 结果是: %lf\n\n",Result);
						while(1){
				gotoxy(1,11);
		printf("1.返回");
	key=getch();
		if(key=='1'){
		tool();
		break;
		}
			}
	}
void jisuanqi()
{
                       //给加减乘除定义的变量
				char No;                //选项的定义变量 
				system("cls");
		        waiguan();
				gotoxy(1,2);
		       printf("计算器:");
				gotoxy(1,4);
                printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ");
					gotoxy(1,5);
                printf ("┇    请选择你要计算的方法:            ");
					gotoxy(1,6);
                printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅");
					gotoxy(1,7);
                printf ("┇	   加法请按_1              ");
					gotoxy(1,8);
                printf ("┇         减法请按_2   		    ");
					gotoxy(1,9);
                printf ("┇         乘法请按_3              ");
					gotoxy(1,10);
                printf ("┇         除法请按_4		        ");
					gotoxy(1,11);
                printf ("┇           返回_0		        ");
					gotoxy(1,12);
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ");
				 No=getch();
				while(1){
                if (No =='1')
                {
                    	jia();
						break;
						
                }
                else if (No =='2')
                {
                        //        减法
						jian();
						break;
                }
                else if (No =='3')
                {
                        //        乘法
					cheng();
					break;
                }
                else if (No =='4')
                {
                        //        除法
					chu();
					break;
                }
                
                else if (No =='0')
                {
                        //        退出程序
                       tool();
					   break;
                }
          
                         
        }
 
}




//音乐函数

	void music()
{

	char key;
	int a;

	face();
	getch();
	system("cls");
	while(1){
	chosemenu();//选择菜单
	waiguan();
	gotoxy(1,9);
	printf("请选择你需要的服务:");
	scanf("%d",&a);
	getch();
	system("cls");
	
	
	
	if(a==1)
	{
	chosemusic();//选择音乐
	system("cls");
	}else if(a==2){
	downmusic();
	chosemusic1();
	system("cls");
	}else{
	tool();
	}
	}
	
	key=getch();
 
	
}



void stopmusic1(){
	PlaySound("D://1//1",NULL,SND_FILENAME);
}
void playmusic1()
{
	PlaySound("D://1//1",NULL,SND_FILENAME | SND_ASYNC );
}
void playmusic2()
{
	PlaySound("D://1//2",NULL,SND_FILENAME | SND_ASYNC );
}
void playmusic3()
{
	PlaySound("D://1//3",NULL,SND_FILENAME | SND_ASYNC );
}
void playmusic4()
{
	PlaySound("D://1//4",NULL,SND_FILENAME | SND_ASYNC );
}

void face()
{	
	system("cls");
	waiguan();
	gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,4);
	printf("==================================");
	gotoxy(1,5);
	printf("============音乐播放器============");
	gotoxy(1,6);
	printf("==================================");
		gotoxy(1,7);
	printf("========因为热爱，所以音乐========");
	gotoxy(1,9);
	printf("====按任意键开始我们的欢乐时光====");

}

void downmusic()
	{
	system("cls");
	waiguan();
	gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,4);
	printf("==================================");
	gotoxy(1,5);
	printf("=======请选择你要下载的音乐=======");
		gotoxy(1,6);
	printf("==================================");
		gotoxy(1,7);
	printf("======1.This Will Be the Day======");
		gotoxy(1,8);
	printf("==================================");
	getch();
	Sleep(2000);
		gotoxy(1,9);
	printf("=============下载成功=============");
	
		
	

		
}

void chosemenu()
{	
	PlaySound(NULL,NULL,SND_FILENAME);
		gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,4);
	printf("==================================");
		gotoxy(1,5);
	printf("============1.播放音乐============");
		gotoxy(1,6);
	printf("============2.下载音乐============");
		gotoxy(1,7);
	printf("============0.退出系统============");
		gotoxy(1,8);
	printf("==================================");
	
	
}

void chosemusic()
{
	char key;
	system("cls");
	waiguan();
	gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,4);
	printf("==================================");
    gotoxy(1,5);
	printf("======请选择你需要播放的音乐======");
	gotoxy(1,6);
	printf("==================================");
	gotoxy(1,7);
	printf("============1.铿剑慨歌============");
	gotoxy(1,8);
	printf("============2.命运之轮============");
	gotoxy(1,9);
	printf("============3.第一乐章============");
	key=getch();
	if(key=='1'){
		playmusic1();
	
		system("cls");
		chosemenu1();
	

	}else if(key=='2'){
		playmusic2();
	
		system("cls");
		chosemenu2();
		
	}else{
		playmusic3();
	
		system("cls");
		chosemenu3();
		
	}
	
}
void chosemusic1()
{
	char key;
	system("cls");
	waiguan();
	gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,4);
	printf("==================================");
    gotoxy(1,5);
	printf("======请选择你需要播放的音乐======");
	gotoxy(1,6);
	printf("==================================");
	gotoxy(1,7);
	printf("===========1.铿剑慨歌=============");
	gotoxy(1,8);
	printf("===========2.命运之轮=============");
	gotoxy(1,9);
	printf("===========3.第一乐章=============");
	gotoxy(1,10);
	printf("======4.This Will Be the Day======");
	key=getch();
	if(key=='1'){
		playmusic1();
		system("cls");
		chosemenu1();
	

	}else if(key=='2'){
		playmusic2();
	
		system("cls");
		chosemenu2();
		
	}else if(key=='3'){
		playmusic3();
	
		system("cls");
		chosemenu3();
	}else{
		playmusic4();
	
		system("cls");
		chosemenu3();
	}
	
}
void chosemenu1()
{

	char key;
	system("cls");
	waiguan();
	gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,4);
	printf("=================================");
    gotoxy(1,5);
	printf("===========1.重新播放============");
	gotoxy(1,6);
	printf("===========2.上一首==============");
	gotoxy(1,7);
	printf("===========3.下一首==============");
	gotoxy(1,8);
	printf("====4.停止当前音乐返回主界面=====");
	gotoxy(1,9);
	printf("=================================");
	key=getch();
	while(1){
	if(key=='1'){
	
		PlaySound("D://1//1",NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
		getch();
		system("cls");
		waiguan();
			gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,10);
	printf("==按任意键停止当前音乐返回主界面=");
		getch();
		break;

	}else if(key=='2'){
		chosemenu1_1();
		break;
	}else if(key=='3'){
		chosemenu1_10();
		break;
	}else{
		
		PlaySound(NULL,NULL,SND_FILENAME);
		break;
	}	
	}
	
}


void chosemenu1_1()
{
	playmusic3();
	system("cls");
	waiguan();
		gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,6);
	printf("=============3.第一乐章==========");
	gotoxy(1,7);
	printf("========按任意键返回主界面=======");
	getch();
}

void chosemenu1_10()
{
	playmusic2();
	system("cls");
	waiguan();
		gotoxy(1,2);
	printf("大熊音乐:");
	printf("=============2.命运之轮===========");
gotoxy(1,6);
	printf("========按任意键返回主界面========");
	gotoxy(1,7);
	getch();
}

void chosemenu2()
{

	char key;
	system("cls");

	waiguan();
	gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,4);
	printf("=================================");
    gotoxy(1,5);
	printf("===========1.重新播放============");
	gotoxy(1,6);
	printf("===========2.上一首==============");
	gotoxy(1,7);
	printf("===========3.下一首==============");
	gotoxy(1,8);
	printf("====4.停止当前音乐返回主界面=====");
	gotoxy(1,9);
	printf("=================================");
	key=getch();
	
	if(key=='1'){
		PlaySound("D://1//2",NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
		getch();
		system("cls");
		waiguan();
			gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,10);
	printf("==按任意键停止当前音乐返回主界面=");
		getch();
	}else if(key=='2'){
		chosemenu1_2();
	}else if(key=='3'){
		chosemenu1_20();
	}else{
		PlaySound(NULL,NULL,SND_FILENAME);
	
}
}

void chosemenu1_2()
{
	playmusic1();
	system("cls");
	waiguan();
		gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,6);
	printf("============1.铿剑慨歌===========");
	gotoxy(1,7);
	printf("=======按任意键返回主界面========");
	getch();
}

void chosemenu1_20()
{
	playmusic3();
	system("cls");
	waiguan();
	gotoxy(1,6);
	printf("============3.第一乐章===========");
	gotoxy(1,7);
	printf("=======按任意键返回主界面========");
	getch();
}
void chosemenu3()
{

	char key;
	system("cls");
	waiguan();
	gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,4);
	printf("=================================");
    gotoxy(1,5);
	printf("===========1.重新播放============");
	gotoxy(1,6);
	printf("===========2.上一首==============");
	gotoxy(1,7);
	printf("===========3.下一首==============");
	gotoxy(1,8);
	printf("====4.停止当前音乐返回主界面=====");
	gotoxy(1,9);
	printf("=================================");
	key=getch();
	
	if(key=='1'){
		PlaySound("D://1//3",NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
		getch();
		system("cls");
		waiguan();
			gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,10);
	printf("==按任意键停止当前音乐返回主界面=");
		getch();
	}else if(key=='2'){
		chosemenu1_3();
	}else if(key=='3'){
		chosemenu1_30();
	}else{
		PlaySound(NULL,NULL,SND_FILENAME);
		
}
}

void chosemenu1_3()
{
	playmusic2();
	system("cls");
	waiguan();
		gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,6);
	printf("===========2.命运之轮============");
	gotoxy(1,7);
	printf("=======按任意键返回主界面========");
	getch();
}
void chosemenu1_30()
{
	playmusic1();
		system("cls");
	waiguan();
		gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,6);
	printf("============1.铿剑慨歌===========");
	gotoxy(1,7);
	printf("========按任意键返回主界面=======");
	getch();
}
void chosemenu4()
{

	char key;
system("cls");
	waiguan();
	gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,4);
	printf("=================================");
    gotoxy(1,5);
	printf("===========1.重新播放============");
	gotoxy(1,6);
	printf("===========2.上一首==============");
	gotoxy(1,7);
	printf("===========3.下一首==============");
	gotoxy(1,8);
	printf("====4.停止当前音乐返回主界面=====");
	gotoxy(1,9);
	printf("=================================");
	key=getch();
	
	if(key=='1'){
		PlaySound("D://1//4",NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
		getch();
	system("cls");
		waiguan();
			gotoxy(1,2);
	printf("大熊音乐:");
	gotoxy(1,10);
	printf("==按任意键停止当前音乐返回主界面=");
		getch();
	}else if(key=='2'){
		chosemenu1_20();
	}else if(key=='3'){
		chosemenu1_30();
	}else{
		PlaySound(NULL,NULL,SND_FILENAME);
	
}
}



	//主界面时间
	void menushijian(){
		time_t t;
		struct tm * lt;
		time (&t);
		lt = localtime (&t);
		waiguan();
		gotoxy(14,5);
		printf("北 京 ");
		gotoxy(10,7);
		printf("%d / %d / %d ",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday);
		gotoxy(13,9);
		printf("%d:%d:%d", lt->tm_hour, lt->tm_min, lt->tm_sec);
	}

	void waiguan(){
		int i;
		for(i=0;i<35;i++)
		{
		gotoxy(i,0);
		printf("-");
		gotoxy(i,14);
		printf("-");

		gotoxy(i,1);
		printf("-");
		gotoxy(i,13);
		printf("-");

		gotoxy(i,16);
		printf("-");
		gotoxy(i,18);
		printf("-");
		gotoxy(i,20);
		printf("-");
		gotoxy(i,22);
		printf("-");
		gotoxy(i,24);
		printf("-");
		gotoxy(i,26);
		printf("-");
		}
		for(i=0;i<27;i++)
		{
		gotoxy(0,i);
		printf("|");
		gotoxy(35,i);
		printf("|");

		}
		gotoxy(1,12);
		printf("        请输入数字进行选择      "); 
		gotoxy(0,15);
		printf("【+】     ===============     【-】");
		gotoxy(0,17);
		printf("【@】     =  [ enter ]  =     【&】");
		gotoxy(0,19);
		printf("【1】     |    【2】    |     【3】");
		gotoxy(0,21);
		printf("【4】     |    【5】    |     【6】");
		gotoxy(0,23);
		printf("【7】     |    【8】    |     【9】");
		gotoxy(0,25);  
		printf("【*】     |    【0】    |     【#】");
		}

	//显示时间
	void shijian(){
		char key;
	time_t t;
    struct tm * lt;
    time (&t);
    lt = localtime (&t);
	system("cls");
	    waiguan();
		while(1){
	gotoxy(5,3);
	printf("地点   日期       时间");
	gotoxy(5,5);
	printf("莫斯科%d/%d/%d %d:%d:%d",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour-5, lt->tm_min, lt->tm_sec);
	gotoxy(5,6);
	printf("纽约  %d/%d/%d  %d:%d:%d",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour-12, lt->tm_min, lt->tm_sec);
	gotoxy(5,7);
	printf("悉尼  %d/%d/%d %d:%d:%d",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour+2, lt->tm_min, lt->tm_sec);
	gotoxy(5,8);
	printf("柏林  %d/%d/%d %d:%d:%d",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour-6, lt->tm_min, lt->tm_sec);
	gotoxy(5,9);
	printf("东京  %d/%d/%d %d:%d:%d",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour+1, lt->tm_min, lt->tm_sec);
	gotoxy(1,11);
		printf("1.返回");
	key=getch();
		if(key=='1'){
	menu();
		break;
		}
		}
}

	//登录界面
	void login(){
	char name[20];
	char pwd[10];
	int i,j;
    
	for(j=3;j>0;j--){
		waiguan();
		gotoxy(5,5);
		printf("请输入用户名：");
		scanf("%s",name);
		gotoxy(5,6);
		printf("请输入密码：");
		getchar();
	for (i=0;i<20;i++)
	{
	pwd[i]=getch();
	if (pwd[i]=='\r')	
	break;
	 printf("*");
	}
	pwd[i]='\0';
		for(i=0;i<3;i++){
			if(strcmp(emps[i].name,name)==0 && strcmp(emps[i].pwd,pwd)==0){
			break;
			}
		}
		if(i<3){
			gotoxy(5,7);
			printf("登陆成功!");
			Sleep(500);
			gotoxy(5,8);
			printf("手机将在3秒后开机....");
			Sleep(600);
			system("cls");
			HideCursor();
			one();
			mainmenu();
			break;
		}else if(j>1){
			gotoxy(5,7);
			printf("用户名或者密码错误\n");
			gotoxy(5,8);
			printf("您还有%d次机会\n",j-1);
			Sleep(300);
			system("cls");
		}else{
			system("cls");
			waiguan();
			gotoxy(5,6);
			printf("密码次数已用完");
			Sleep(500);
			gotoxy(5,7);
		    printf("请你思考一下再来");
			Sleep(500);
			gotoxy(5,8);
		    printf("手机将在3秒后关机");
				Sleep(500);
			system("cls");
			one();
			system("exit");

	}
	}
	}


	//拨号
	void bohao()
	{   
	int u;
	char num[20];
		struct Client client;
	system("cls");
	waiguan();
	gotoxy(1,2);
	printf("拨 号:");
	gotoxy(3,5);
	printf("请输入对方电话号码: ");
		gotoxy(10,8);
	scanf("%s",num);
	if (strcmp(client.phone,num)==0)
		u=1;
	if (strcmp("15080696429",num)==0)
		u=2;
	switch (u)
	{
	case 1: 
		system("cls");
		system("ping 192.168.19.22 ");printf("\n通话结束");
		break;
	case 2: 
		system("cls");
		system("ping 192.168.19.21 ");printf("\n通话结束");
		break;
	default : printf("号码错误\n");
	}
	printf("\n\t请按任意键返回主菜单");
		getchar();
		getchar();
		menu();
	}

	//倒计时
	void one(){
	gotoxy(24,8);
	printf("■");
	gotoxy(26,8);
	printf("■");
	gotoxy(28,8);
	printf("■");
	gotoxy(30,8);
	printf("■");
	gotoxy(32,8);
	printf("■");
	gotoxy(32,9);
	printf("■");
	gotoxy(32,10);
	printf("■");
	gotoxy(32,11);
	printf("■");
	gotoxy(32,12);
	printf("■");
	gotoxy(24,12);
	printf("■");
	gotoxy(26,12);
	printf("■");
	gotoxy(28,12);
	printf("■");
	gotoxy(30,12);
	printf("■");
	gotoxy(32,13);
	printf("■");
	gotoxy(32,14);
	printf("■");
	gotoxy(32,15);
	printf("■");
	gotoxy(32,16);
	printf("■");
	gotoxy(24,16);
	printf("■");
	gotoxy(26,16);
	printf("■");
	gotoxy(28,16);
	printf("■");
	gotoxy(30,16);
	printf("■");
	Sleep(1000);
	system("cls");
	gotoxy(24,8);
	printf("■");
	gotoxy(26,8);
	printf("■");
	gotoxy(28,8);
	printf("■");
	gotoxy(30,8);
	printf("■");
	gotoxy(32,8);
	printf("■");
	gotoxy(32,9);
	printf("■");
	gotoxy(32,10);
	printf("■");
	gotoxy(32,11);
	printf("■");
	gotoxy(32,12);
	printf("■");
	gotoxy(30,12);
	printf("■");
	gotoxy(28,12);
	printf("■");
	gotoxy(26,12);
	printf("■");
	gotoxy(24,12);
	printf("■");
	gotoxy(24,13);
	printf("■");
	gotoxy(24,14);
	printf("■");
	gotoxy(24,15);
	printf("■");
	gotoxy(24,16);
	printf("■");
	gotoxy(26,16);
	printf("■");
	gotoxy(28,16);
	printf("■");
	gotoxy(30,16);
	printf("■");
	gotoxy(32,16);
	printf("■");
	Sleep(1000);
	system("cls");
	gotoxy(28,8);
	printf("■");
	gotoxy(26,9);
	printf("■");
	gotoxy(28,9);
	printf("■");
	gotoxy(28,10);
	printf("■");
	gotoxy(28,11);
	printf("■");
	gotoxy(28,12);
	printf("■");
	gotoxy(28,13);
	printf("■");
	gotoxy(28,14);
	printf("■");
	gotoxy(28,15);
	printf("■");
	gotoxy(24,16);
	printf("■");
	gotoxy(26,16);
	printf("■");
	gotoxy(28,16);
	printf("■");
	gotoxy(30,16);
	printf("■");
	gotoxy(32,16);
	printf("■");
	Sleep(1000);
	system("cls");

	} 





	void dianhuabu(){
	char key;
		system("cls");
		waiguan();
		while(1){
			gotoxy(1,2);
	printf("电话簿:");
		gotoxy(12,4);
		printf("1.显示联系人");
			gotoxy(12,5);
		printf("2.添加联系人\n");
			gotoxy(12,6);
		printf("3.删除联系人\n");
			gotoxy(12,7);
		printf("4.查找联系人\n");
			gotoxy(12,8);
		printf("5.返回\n");
		key=getch();
		if(key=='1'){
			system("cls");
		    waiguan();
			query();
			break;
		}else if(key=='2'){
			add();
			break;
		}else if(key=='3'){
			d();
			break;
		}else if(key=='4'){
			lookup();
			break;
		}else if(key=='5'){
			menu();
			break;
		}
		getch();	
			}
	}
void query(){
	
    int i=4;
	char key;
	struct Client client;

	FILE*file;
	file=fopen("bank.dat","r");
	gotoxy(1,2);
	printf("显示联系人:");
	if(file==NULL){
		gotoxy(12,6);
		printf("没有联系人");
			fclose(file);
		while(1){
				gotoxy(1,11);
		printf("1.返回");
		key=getch();
		if(key=='1'){
		dianhuabu();
		break;
		}
			}
	
		
		return;
	}
	
	gotoxy(8,3);
	printf("用户名      联系电话"); 
	while(fread(&client,sizeof(client),1,file)==1){
		if(client.t==1){
			gotoxy(8,i++);
		printf("%s         %s",client.name,client.phone);
		}
	}
	fclose(file);
		while(1){
				gotoxy(1,11);
		printf("1.返回");
	key=getch();
		if(key=='1'){
		dianhuabu();
		break;
		}
			}
	}
void add(){
	
	long len;
	char key;
	char name[20];
	char phone[20];
	struct Client client;
	FILE*file;
system("cls");
	waiguan();
		gotoxy(1,2);
	printf("添加联系人:");
	gotoxy(10,6);
	printf("请输入姓名:");
	scanf("%s",name);
	gotoxy(10,7);
	printf("请输入号码:");
	scanf("%s",phone);
	file=fopen("bank.dat","r+");
	while(fread(&client,sizeof(client),1,file)==1){
		if(client.t==1&&strcmp(client.name,name)==0){
			gotoxy(7,8);
			    printf("已有此联系人,是否修改?");
			 	gotoxy(7,10);
			    printf("  1.是           2.否   ");
			    key=getch();
			    if(key=='1'){
				    strcpy(client.name,name);
				    strcpy(client.phone,phone);
					len=sizeof(client);
					len*=-1;
					fseek(file,len,1);
					fwrite(&client,sizeof(client),1,file);
					fclose(file);
					gotoxy(9,11);
					printf("修改成功！");
						while(1){
				gotoxy(1,11);
		printf("1.返回");
	key=getch();
		if(key=='1'){
		dianhuabu();
		break;
		}
			}
					return;
		    	}
		    	else if(key=='2'){
		    		fseek(file,0L,2);
		    		break;
				}
			}
		}
					client.t=1; 
					strcpy(client.name,name);
				    strcpy(client.phone,phone);
		            fwrite(&client,sizeof(client),1,file);
	   			 	fclose(file);
					gotoxy(10,8);
					printf("信息保存成功！"); 
					while(1){
				gotoxy(1,11);
		printf("1.返回");
	key=getch();
		if(key=='1'){
		dianhuabu();
		break;
		}
			}
}



void d(){
	char key;
	char name[20];
	struct Client client;
	long len=sizeof(client);
	FILE*file;
	system("cls");
	waiguan();
		gotoxy(1,2);
	printf("删除联系人:");
	gotoxy(3,5);
	printf("请输入要删除人的姓名:");
	scanf("%s",name);
	file=fopen("bank.dat","r+");
	while(fread(&client,sizeof(client),1,file)==1){
		if(client.t==1&&strcmp(client.name,name)==0){
			gotoxy(10,8);
			printf("删除成功！");
			client.t=0;
			len*=-1;
			fseek(file,len,1);
			fwrite(&client,sizeof(client),1,file);
			fclose(file);
			while(1){
				gotoxy(1,11);
		printf("1.返回");
	key=getch();
		if(key=='1'){
		dianhuabu();
		break;
		}
			}
			return;
		}
	
	}
		gotoxy(10,8);
	printf("没有此联系人！");
	while(1){
		gotoxy(1,11);
		printf("1.返回");
	key=getch();
		if(key=='1'){
		dianhuabu();
		break;
		}
	}
	fclose(file);
}

void lookup(){
	char key;
	char name[20]; 
	struct Client client;
	FILE*file;
	system("cls");
	waiguan();
		gotoxy(3,5);
	printf("请输入要查找的联系人:");
	scanf("%s",name);
	file=fopen("bank.dat","r");
	while(fread(&client,sizeof(client),1,file)==1){
		if(client.t==1&&strcmp(client.name,name)==0){
			gotoxy(3,8);
			printf("%-12s%-15s\n",client.name,client.phone);
			fclose(file);
			while(1){
				gotoxy(1,11);
		printf("1.返回");
	key=getch();
		if(key=='1'){
		dianhuabu();
		break;
		}
			}
			return;}}
		gotoxy(10,8);
		printf("没有此联系人！"); 
		fclose(file);
			while(1){
				gotoxy(1,11);
		printf("1.返回");
	key=getch();
		if(key=='1'){
		dianhuabu();
		break;
		}
			}
		
}

