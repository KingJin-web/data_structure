#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include"function.h"

////////////////////////////////////////////////////////////////////////////////////// 
                         /*排序计算相关函数*/ 
/* 
函数功能：选择法实现按学号升序排序 
输入参数：学生结构体数组，学生人数 
返回值：修改共用的学生结构体数组每个学生的顺序     
*/ 

void SortOnNumAs(struct student stu[],int nStudentNum)
{
	printf("\n\t\t\t这里是按学号升序排序模块\n"); 
	struct student temp;
	for(int i=0;i<nStudentNum;i++)
	{
		for(int j=i+1;j<nStudentNum;j++)
		{
			if(stu[j].nNumber>stu[i].nNumber)
			{
				temp=stu[j];
				stu[j]=stu[i];
				stu[i]=temp;
			}
		}
	}
}
//按学号升序排序结束

/* 
函数功能：选择法实现按总成绩降序排序 
输入参数：学生结构体数组，学生人数 
返回值：修改共用的学生结构体数组每个学生的顺序    
*/ 
void SortOnSumDs(struct student stu[],int nStudentNum)
{
	printf("\n\t\t\t这里是计算总成绩，并按总成绩降序排序模块\n"); 
	for(int i=0;i<nStudentNum;i++)
	{
		for(int j=0;j<COURSENUM;j++)
		{
			stu[i].fSumScore+=stu[i].fScore[j];
		}
	}
	struct student temp;
	for(int i=0;i<nStudentNum;i++)
	{
		for(int j=i+1;j<nStudentNum;j++)
		{
			if(stu[j].fSumScore<stu[i].fSumScore)
			{
				temp=stu[j];
				stu[j]=stu[i];
				stu[i]=temp;
			}
		}
	}
}
//总成绩降序排序结束 


/* 
函数功能：计算各科平均分 
输入参数：学生结构体数组，课程名字数据，学生人数 
返回值：修改共用的学生结构体数组的每个成员的平均分    
*/ 

void ComputeAverageScore(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum)
{
	printf("\n\t\t\t这里是计算学生各科平均分数模块\n"); 
	float x[COURSENUM];
	for(int i=0;i<COURSENUM;i++)
	{
		for(int j=0;j<nStudentNum;j++)
		{
			x[i]+=stu[j].fScore[i];
		}
	}
	for(int i=0;i<COURSENUM;i++)
	{
		printf("\n\t\t\t班级的%s平均分：%.2f\n",szCourseName[i],(double)x[i]/nStudentNum);
	}
	for(int i=0;i<nStudentNum;i++)
	{
		for(int j=0;j<COURSENUM;j++)
		{
			stu[i].fAveScore+=stu[i].fScore[j];
		}
		stu[i].fAveScore=stu[i].fAveScore/COURSENUM;
	}
}

/* 
函数功能：计算并输出班级语文成绩各分数段分布情况 
    定义学生成绩分布等级如下：
    60分以下：fail
    60~70分 ：pass
    70~80分 ：good
    80~90分 ：great
    90分以上：excellent 
输入参数：学生结构体数组，课程名字数据，学生人数 
返回值：无  
*/ 
void ComputeDistribution(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum)
{
	printf("\n\t\t\t 这里是计算各分数段分布模块\n"); 
 	int x[5]={0},y[5]={0},z[5]={0};
 	for(int i=0;i<nStudentNum;i++)
 	{
		if(stu[i].fScore[0]<60)
		{
			x[0]++;
		} 
		else if(stu[i].fScore[0]>=60&&stu[i].fScore[0]<70)
		{
			x[1]++;
		}
		else if(stu[i].fScore[0]>=70&&stu[i].fScore[0]<80)
		{
			x[2]++;
		}
		else if(stu[i].fScore[0]>=80&&stu[i].fScore[0]<90)
		{
			x[3]++;
		}
		else if(stu[i].fScore[0]>=90)
		{
			x[4]++;
		}
	} 
	for(int i=0;i<nStudentNum;i++)
 	{
		if(stu[i].fScore[1]<60)
		{
			y[0]++;
		} 
		else if(stu[i].fScore[1]>=60&&stu[i].fScore[1]<70)
		{
			y[1]++;
		}
		else if(stu[i].fScore[1]>=70&&stu[i].fScore[1]<80)
		{
			y[2]++;
		}
		else if(stu[i].fScore[1]>=80&&stu[i].fScore[1]<90)
		{
			y[3]++;
		}
		else if(stu[i].fScore[1]>=90)
		{
			y[4]++;
		}
	} 
	for(int i=0;i<nStudentNum;i++)
 	{
		if(stu[i].fScore[2]<60)
		{
			z[0]++;
		} 
		else if(stu[i].fScore[2]>=60&&stu[i].fScore[2]<70)
		{
			z[1]++;
		}
		else if(stu[i].fScore[2]>=70&&stu[i].fScore[2]<80)
		{
			z[2]++;
		}
		else if(stu[i].fScore[2]>=80&&stu[i].fScore[2]<90)
		{
			z[3]++;
		}
		else if(stu[i].fScore[2]>=90)
		{
			z[4]++;
		}
	} 
	printf("\n                        班级语文成绩分布为:\n\n");
	printf("90~100分数段人数：%d人, 占比 %.2f%%;  80~90分数段人数：%d人, 占比 %.2f%%;\n",x[0],(double)x[0]/nStudentNum*100,x[1],(double)x[1]/nStudentNum*100);
	printf("70~80 分数段人数：%d人, 占比 %.2f%%;  60~70分数段人数：%d人, 占比 %.2f%%\n;",x[2],(double)x[2]/nStudentNum*100,x[3],(double)x[3]/nStudentNum*100);
	printf("60分下不及格人数：%d人, 占比 %.2f%%;\n",x[4],(double)x[4]/nStudentNum*100);
	printf("**************************************************************************\n");
	printf("\n                        班级数学成绩分布为:\n\n");
	printf("90~100分数段人数：%d人, 占比 %.2f%%;  80~90分数段人数：%d人, 占比 %.2f%%;\n",y[0],(double)y[0]/nStudentNum*100,y[1],(double)y[1]/nStudentNum*100);
	printf("70~80 分数段人数：%d人, 占比 %.2f%%;  60~70分数段人数：%d人, 占比 %.2f%%;\n",y[2],(double)y[2]/nStudentNum*100,y[3],(double)y[3]/nStudentNum*100);
	printf("60分下不及格人数：%d人, 占比 %.2f%%;\n",y[4],(double)y[4]/nStudentNum*100);
	printf("**************************************************************************\n");
	printf("\n                        班级英语成绩分布为:\n\n");
	printf("90~100分数段人数：%d人, 占比 %.2f%%;  80~90分数段人数：%d人, 占比 %.2f%%;\n",z[0],(double)z[0]/nStudentNum*100,z[1],(double)z[1]/nStudentNum*100);
	printf("70~80 分数段人数：%d人, 占比 %.2f%%;  60~70分数段人数：%d人, 占比 %.2f%%;\n",z[2],(double)z[2]/nStudentNum*100,z[3],(double)z[3]/nStudentNum*100);
	printf("60分下不及格人数：%d人, 占比 %.2f%%;\n",z[4],(double)z[4]/nStudentNum*100);
}// 计算成绩分布情况函数结束 
