#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include"function.h"

///////////////////////////////////////////////////////////////////////////////// 
             //查询相关函数 共有2个：按学号，按姓名查找 
                        

/* 
函数功能：按学号查找并输出一个学生的具体信息 
输入参数：学生结构体数组，课程名字数据，学生人数 
返回值：无  
*/ 

void FindByNumber(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) 
{
	printf("\n\t\t这里是按学号查找一个学生模块\n"); 
 	int  x=0;
 	int flag=0;
	printf("\n\t\t请输入学生学号：");
	scanf("%d",&x);
	for(int i=0;i<nStudentNum;i++)
	{
		if(x==stu[i].nNumber)
		{
			printf("\n\t\t学号  姓名      语文    数学    英语    总成绩    平均成绩");
			printf("\n\t\t==========================================================");
			printf("\n\t\t%d    %s        %.2f    %.2f    %.2f     %.2f        %.2f",stu[i].nNumber,stu[i].szName[STRLENGTH],stu[i].fScore[1],stu[i].fScore[2],stu[i].fScore[3],stu[i].fAveScore,stu[i].fSumScore);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\n\t\t没有此学号的学生，请重新输入！\n");
	}
	
		
}//按学号查询结束 

/* 
函数功能：按姓名查找并输出一个学生的具体信息 
输入参数：学生结构体数组，课程名字数据，学生人数 
返回值：无  
*/ 
void FindByName(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) 
{
	printf("\n\t\t这里是按姓名查找学生信息模块\n"); 
 	char x[STRLENGTH];
 	int flag=0;
	printf("\n\t\t请输入学生姓名：");
	scanf("%s",&x);
	for(int i=0;i<nStudentNum;i++)
	{
		if(strcmp(x,stu[i].szName) == 0)
		{
			printf("\n\t\t学号  姓名      语文    数学    英语    总成绩    平均成绩");
			printf("\n\t\t==========================================================");
			printf("\n\t\t%d    %s         %f      %f      %f       %f        %f",stu[i].nNumber,stu[i].szName[STRLENGTH],stu[i].fScore[1],stu[i].fScore[2],stu[i].fScore[3],stu[i].fAveScore,stu[i].fSumScore);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\n\t\t没有此姓名的学生，请重新输入！\n");
	}	
}//按姓名查询结束 
