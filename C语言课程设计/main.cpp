#define _CRT_SECURE_NO_WARNINGS //屏蔽vs2017安全警告
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define MAX 100
#define PS "cz666"
/****************************************
* 项目名：学生成绩管理系统
* 设计团队：锤子组
*     组长：陈栋
*     组员：金鹏
*           吴亦旋
*           邓秋豪
****************************************/

typedef struct
{
	int nb;
	char name[10];
	int score[3];
	double ave;
} STU;

void inarray(STU *p, int n);		///输入
void outarray(STU *p, int n);		///输出
void sort(STU *p, int n);			///排序
void insert(STU *p, int *n, int m); ///插入一个成绩
void reserve(STU *p, int n);		///反序
void searchByNumb(STU *p, int n);
void searchByName(STU *p, int n); ///名字查找
void search(STU *p, int n);
void del(STU *p, int *pn, int n); ///
void update(STU *p, int n);
void menu();	 ///菜单
void about();	 ///主菜单关于函数
void Feedback(); ///功能介绍
void function(); ///反馈
void upload(STU *p, int *pn);
void save(STU *p, int n);
void backup();
int binaryfile(STU *p, int n);	  ///以二进制文件形式保存当前学生信息
int rbinaryfile(STU *p, int *pn); ///从二进制文件中读取当前学生信息
int Countdown();				  ///倒计时三秒
int pass(void);					  ///登录函数
int i = 0;						  ///全局变量

int main()
{
	system("color F4");
	STU stuArray[100];
	int n = 0;
	pass();		   ///运行密码登陆函数
	system("cls"); ///清屏
	while (1)
	{
		int m;
		menu();
		int score[MAX];
		int x;
		scanf("%d", &x);
		if (x == 0)
		{
			printf(" 欢迎使用 ");
			Sleep(500);
			system("start http://s10.sinaimg.cn/orignal/002E9Pdjzy7cAlyLipH89");
			break;
		}
		switch (x)
		{
		case 1:
		{
			printf("学生人数为 n:");
			scanf("%d", &n);
			inarray(stuArray, n);
			break;
		}
		case 2:
		{
			outarray(stuArray, n);
			break;
		}
		case 3:
		{
			sort(stuArray, n);
			break;
		}
		case 4:
		{
			insert(stuArray, &n, MAX);
			break;
		}
		case 5:
		{

			reserve(stuArray, n);
			break;
		}
		case 6:
		{
			searchByNumb(stuArray, n);
			break;
		}
		case 7:
		{
			searchByName(stuArray, n);
			break;
		}
		case 8:
		{
			search(stuArray, n);
			break;
		}
		case 9:
		{
			del(stuArray, &n, n);
			break;
		}
		case 10:
		{
			update(stuArray, n);
			break;
		}
		case 11:
		{
			save(stuArray, n);
			break;
		}
		case 12:
		{
			backup();
			break;
		}
		case 13:
		{
			upload(stuArray, &n);
			break;
		}
		case 14:
		{
			binaryfile(stuArray, n);
			break;
		}
		case 15:
		{
			rbinaryfile(stuArray, &n);
			break;
		}
		case 16:
		{
			about();
			break;
		}
		default:
		{
			printf("输入错误,请重新输入");
			Sleep(500);
			system("cls");
			continue;
		}
		}
	}
}
void menu()
{
	system("cls");
	system("color F4");
	printf("\t\t\t\t\t _____________________________________ \n");
	printf("\t\t\t\t\t|      欢迎使用成绩管理系统           |\n");
	printf("\t\t\t\t\t|                     ————管理员版|    \n");
	printf("\t\t\t\t\t|_____________________________________|\n");
	printf("\t\t\t\t\t|      1:输入多个成绩                 |\n");
	printf("\t\t\t\t\t|      2:显示全部成绩                 |\n");
	printf("\t\t\t\t\t|      3:对成绩排序                   |\n");
	printf("\t\t\t\t\t|      4:新增一个成绩                 |\n");
	printf("\t\t\t\t\t|      5:逆序存放                     |\n");
	printf("\t\t\t\t\t|      6:按学号查找                   |\n");
	printf("\t\t\t\t\t|      7:按名字查找                   |\n");
	printf("\t\t\t\t\t|      8:查找(按学号或姓名)           |\n");
	printf("\t\t\t\t\t|      9:删除(按学号或姓名)           |\n");
	printf("\t\t\t\t\t|      10:修改学生信息                |\n");
	printf("\t\t\t\t\t|      11:保存当前学生信息到文件      |\n");
	printf("\t\t\t\t\t|      12:对文件学生备份              |\n");
	printf("\t\t\t\t\t|      13:从文件读取学生信息          |\n");
	printf("\t\t\t\t\t|      14:备份学生信息到二进制文件    |\n");
	printf("\t\t\t\t\t|      15:从二进制文件加载学生信息    |\n");
	printf("\t\t\t\t\t|      16:关于                        |\n");
	printf("\t\t\t\t\t|       0:退出                        |\n");
	printf("\t\t\t\t\t|_____________________________________|\n");
}
void inarray(STU *p, int n)
{
	printf("学号\t姓名\t数学\t英语\t计算机\n");
	for (i = 0; i < n; i++)
	{
		///esc();///实现退一步操作
		scanf("%d%s%d%d%d", &p[i].nb, p[i].name, &p[i].score[0], &p[i].score[1], &p[i].score[2]);
	}
	system("pause");
}
void outarray(STU *p, int n)
{
	printf("有%d名学生，其信息如下:\n", n);
	printf("学号\t姓名\t数学\t英语\t计算机\t平均分\n");
	for (i = 0; i < n; i++)
	{
		p[i].ave = (p[i].score[0] + p[i].score[1] + p[i].score[2]) / 3; ///计算平均分
		printf("%d\t%s\t%d\t%d\t%d\t%.2lf\n", p[i].nb, p[i].name, p[i].score[0], p[i].score[1], p[i].score[2], p[i].ave);
		printf("\n");
	}
	system("pause");
}
void sort(STU *p, int n)
{ ///对学号排序
	int j = 0;
	STU temp;
	char style;
	printf("现在对当前的输入信息排序处理\n");
	printf("按升序排序请输入 a,按降序排序请安d:");
	getchar(); ///作用是吸收输入缓冲区残留得字符'\n'，必不可少
	scanf("%c", &style);
	if (style == 'a')
	{ ///升序
		for (i = 0; i < n - 1; i++)
			for (j = 0; j < n - 1 - i; j++)
			{
				if (p[j].nb > p[j + 1].nb)
				{
					temp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = temp;
				}
			}
	}
	if (style == 'd')
	{ ///降序
		for (i = 0; i < n - 1; i++)
			for (j = 0; j < n - 1 - i; j++)
			{
				if (p[j].nb < p[j + 1].nb)
				{
					temp = p[j + 1];
					p[j + 1] = p[j];
					p[j] = temp;
				}
			}
	}
	system("pause");
}
void insert(STU *p, int *pn, int m) ///插入一个成绩
{
	int x;
	int n;
	while (1)
	{
		n = *pn;
		if (n > m)
		{
			printf("人满了！\n");
			break;
		}
		else
		{
			printf("输入一个学生信息成绩：\n");
			printf("学号\t姓名\t数学\t英语\t计算机\n");
			scanf("%d%s%d%d%d", &p[*pn].nb, p[*pn].name, &p[*pn].score[0], &p[*pn].score[1], &p[*pn].score[2]);
			(*pn)++;
			///if()
			printf("添加成功！继续添加请按1，退出请按0:");
			scanf("%d", &x);
			if (x == 0)
				break;
		}
	}
	system("pause");
}
void reserve(STU *p, int n)
{
	STU temp;
	int i, j;
	printf("逆序输出如下:\n");
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		temp = p[i];
		p[i] = p[j];
		p[j] = temp;
	}
	outarray(p, n);
	system("pause");
}
void searchByNumb(STU *p, int n) //只能找到第一个人 待改
{
	int num;
	int i;
	printf("请输入你要查找的学号:");
	scanf("%d", &num);
	for (i = 0; i < n; i++)
	{
		if (p[i].nb == num)
		{
			printf("找到了,位置为第%d,该学生信息如下\n", i + 1);
			p[i].ave = (p[i].score[0] + p[i].score[1] + p[i].score[2]) / 3;
			printf("学号\t姓名\t数学\t英语\t计算机\t平均分\n");
			printf("%d\t%s\t%d\t%d\t%d\t%.2lf\n", p[i].nb, p[i].name, p[i].score[0], p[i].score[1], p[i].score[2], p[i].ave);
			break;
		}
	}
	if (i == n)
	{
		printf("没有找到此人!\n");
	}
	system("pause");
}
void searchByName(STU *p, int n)
{
	char a[10];
	int i;
	printf("请输入你要查找的名字:");
	scanf("%s", a);
	for (i = 0; i < n; i++)
	{
		if (strcmp(p[i].name, a) == 0)
		{
			printf("找到了,位置为第%d,该学生信息如下\n", i + 1);
			p[i].ave = (p[i].score[0] + p[i].score[1] + p[i].score[2]) / 3;
			printf("学号\t姓名\t数学\t英语\t计算机\t平均分\n");
			printf("%d\t%s\t%d\t%d\t%d\t%.2lf\n", p[i].nb, p[i].name, p[i].score[0], p[i].score[1], p[i].score[2], p[i].ave);
			break;
		}
	}
	if (i == n)
	{
		printf("没有找到此人!\n");
	}
	system("pause");
}
void search(STU *p, int n)
{
	int x;
	printf("按学号查找请输入1,按名字查找请输入2:");
	scanf("%d", &x);
	if (x == 1)
	{
		searchByNumb(p, n);
	}
	if (x == 2)
	{
		searchByName(p, n);
	}
	system("pause");
}
void del(STU *p, int *pn, int n)
{
	int x;
	int i, j;
	printf("删除学生成绩,按学号删除请按1,按姓名删除请按2:");
	scanf("%d", &x);
	if (x == 1)
	{
		int a;
		printf("请输入需要删除学生的学号:");
		scanf("%d", &a);
		if (a > n)
			printf("未查找到此人!\n");
		for (i = 0; i < n; i++)
		{
			if (p[i].nb == a)
			{
				for (j = i; j < n - 1; j++)
					p[j] = p[j + 1];
				(*pn)--;
				printf("删除成功!\n");
				break;
			}
		}
	}
	if (x == 2)
	{
		char name2[10];

		printf("请输入需要删除学生的姓名:");
		scanf("%s", name2);
		for (i = 0; i < n; i++)
			if (strcmp(p[i].name, name2) != 0) //      待完善 ！
											   //	printf("未查找到此人\n");
				for (i = 0; i < n; i++)
				{
					if (strcmp(p[i].name, name2) == 0)
					{
						for (j = i; j < n - 1; j++)
							p[j] = p[j + 1];
						(*pn)--;
						printf("删除成功!\n");
						break;
					}
				}
	}
	system("pause");
}
void update(STU *p, int n)
{
	int a, i, j;
	int s[3];
	printf("输入待修改学生的学号:");
	scanf("%d", &a);
	if (a > n)
	{
		printf("修改失败!\n");
	}
	else
	{
		printf("学号\t姓名\t数学\t英语\t计算机\n");
		for (i = 0; i < n; i++)
			if (p[i].nb == a)
			{
				printf("%d\t%s\t", p[i].nb, p[i].name);
				for (j = 0; j < 3; j++)
				{
					scanf("%d", &s[j]);
					p[i].score[j] = s[j];
				}
			}
		printf("修改成功!\n");
	}
	system("pause");
}
void upload(STU *p, int *pn)
{
	int i, j;
	int n;
	FILE *fp;
	char str1[20], str2[10];
	printf("请输入文件名：");
	scanf("%s", str2);
	if ((fp = fopen(str2, "r")) == NULL)
	{
		printf("打开失败！\n");
	}
	else
	{

		fscanf(fp, "共有%d名学生，信息如下:\n", &n);
		for (j = 0; j < 6; j++)
			fscanf(fp, "%s", str1);
		for (i = 0; i < n; i++)
			fscanf(fp, "%d%s%d%d%d%lf", &p[i].nb, p[i].name, &p[i].score[0], &p[i].score[1], &p[i].score[2], &p[i].ave);
		*pn = n;
		printf("加载成功！\n");
		fclose(fp);
	}
	system("pause");
}
void save(STU *p, int n)
{
	FILE *fp;
	int i;
	if ((fp = fopen("学生成绩信息.txt", "w")) == NULL)
	{
		printf("打开失败!\n");
	}
	else
	{

		fprintf(fp, "共有%d名学生，信息如下:\n", n);
		//for(i=0;i<6;i++)
		fprintf(fp, "学号\t姓名\t数学\t英语\t计算机\t平均分\n");
		for (i = 0; i < n; i++)
			fprintf(fp, "%d\t%s\t%d\t%d\t%d\t%.2lf\n", p[i].nb, p[i].name, p[i].score[0], p[i].score[1], p[i].score[2], p[i].ave);
		printf("保存成功！\n");
	}
	fclose(fp);
	system("pause");
}
void backup()
{
	FILE *in, *out;
	int i;
	char str[20], ch;
	if ((in = fopen("学生成绩信息.txt", "r")) == NULL)
	{
		printf("打开失败！\n");
	}
	if ((out = fopen("学生成绩备份.txt", "w")) == NULL)
	{
		printf("打开失败！\n");
	}
	ch = fgetc(in);
	while (ch != EOF)
	{
		fprintf(out, "%c", ch);
		ch = fgetc(in);
	}
	printf("备份成功!");
	fclose(in);
	fclose(out);
}
int binaryfile(STU *p, int n)
{
	FILE *fp;
	printf("以二进制文件形式保存当前学生信息:\n");
	if ((fp = fopen("学生二进制文件.txt", "wb")) == NULL)
	{
		printf("打开失败！\n");
		return 0;
	}
	fwrite(&n, sizeof(n), 1, fp);
	fwrite(p, sizeof(STU), n, fp);
	printf("输出到二进制文件成功!\n");
	fclose(fp);
	system("pause");
	return 0;
}
int rbinaryfile(STU *p, int *pn)
{
	FILE *fp;
	int n;
	printf("从二进制文件中读取当前学生信息:\n");
	if ((fp = fopen("学生二进制文件.txt", "rb")) == NULL)
	{
		printf("打开失败！\n");
		return 0;
	}
	fread(&n, sizeof(n), 1, fp);
	fread(p, sizeof(STU), n, fp);
	*pn = n;
	fclose(fp);
	printf("加载成功！\n");
	system("pause");
	return 0;
}
int pass(void) ///登录函数
{
	int x, n = 1;
	char pswords[20] = PS;
	for (;; n++)
	{
		if (n <= 3)
		{
			char ch, pswords0[20];
			int i = 0;
			printf("请输入管理员登录密码");

			while ((ch = getch()) != '\r' && i <= 20) ///注意此时是'\r' 意思是当控制台没有敲入回车
			{
				if (ch == '\b') ///当控制台敲入退格键
				{
					if (i > 0)
					{
						i--;
						printf("\b \b"); /// 密码支持退格的实现
					}
					else
						putchar(7); ///退格提醒
				}
				else
				{
					pswords0[i++] = ch;
					printf("*");
				}
			}
			pswords0[i] = '\0';
			///passwords0[i]='\0'表示将结束标志字符'\0'赋值给数组元素a[i]，即去掉i+1后面的所有元素；
			if (!strcmp(pswords0, pswords))
			{
				printf("密码正确,将一秒后跳转操作界面\n");
				Sleep(1000); ///一秒
				return 1;
			}
			else
			{
				printf("密码错误,您还有%d次机会\n", 3 - n);
			}
		}
		else
		{
			puts("密码错误3次,将于3秒后退出!\n");
			Countdown(); ///倒计时函数
			exit(0);
		}
	}
	return 0;
}
int Countdown() ///倒计时三秒
{
	i = 3;
	while (i > 0)
	{
		printf("倒计时：%d\n", i);
		Sleep(1000);   //暂停1秒钟
		system("cls"); //清屏
		i--;
	}
	return 0;
}
void about()
{
	system("cls");
	system("color f5");
	printf("\t\t\t\t\t _____________________________ \n");
	printf("\t\t\t\t\t|          版本号  cz 1.40.1  |\n");
	printf("\t\t\t\t\t|                 锤子版权所有|\n");
	printf("\t\t\t\t\t|          1,功能介绍         |\n");
	printf("\t\t\t\t\t|          2,参考网址         |\n");
	printf("\t\t\t\t\t|          3,反馈             |\n");
	printf("\t\t\t\t\t|_____________________________|\n");
	int x;
	scanf("%d", &x);
	switch (x)
	{
	case 1:
	{
		Feedback();
		system("pause");
		break;
	}
	case 2:
	{
		system("start http://www.baidu.com"); ///将会打开百度
		/**
            *   此语句来源  https://jingyan.baidu.com/article/5552ef47ab8f43518ffbc9b9.html
            **/
		break;
	}
	case 3:
	{
		function();
		system("pause");
		break;
	}
	}
}
void Feedback()
{
	FILE *fp;
	char buffer[256];
	if (fp = fopen("data.txt", "r"))
	{
		while (!feof(fp))
		{
			fgets(buffer, 255, fp);
			printf("%s\n", buffer);
		}
		fclose(fp);
	}
	else
		printf("无法打开文本文件读取。\n");
}
void function()
{
	printf("联系组长QQ：1846132633\
	        微信：saber1314TT");
	printf("\n享受一对一解答哦\n");
}
