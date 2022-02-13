#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include"function.h"

////////////////////////////////////////////////////////////////////////////////
                              /*菜单相关函数*/

/* 
函数功能：一级主菜单选项显示 
输入参数：学生结构体数组，课程名数组
返回参数：学生人数（因为可能一直改变，用指针变量实现）
*/ 
void Select_MainMenu(struct student stu[],char szCourseName[][STRLENGTH],int*npStudentNum) 
{	
	int nMainchoose;
	//主菜单无限循环 
	while(1)
	{
		system("CLS"); //系统屏幕清空 
		//输出菜单主界面 
		printf("\t\t   ------------------------  \n");
		printf("\t\t|      学生成绩管理系统      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|  1.信息显示   2.信息管理   |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|  3.排序计算   4.条件查询   |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|  5.文件保存   0.退出系统   |\n");
		printf("\t\t   ------------------------  \n");
		//根据宏定义的文件名和学生数额显示 
		printf("\n\t数据文件%s中目前共有%d名学生 \n\n",FILENAME,*npStudentNum);
		//请用户输入选择的数字 
		printf("\t\t   请选择功能序号(0~5):");
		//用户根据界面提示输入数字 
	    scanf("%d",&nMainchoose);	
		//根据用户输入的数字看如何行动					
		switch(nMainchoose)
		{
		   //信息显示 
			case 1: printf("\n");
			        //调用输出学生信息函数 
				    OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);	//转到输出显示函数 
				    system("PAUSE");
			        break;
			//转到二级菜单：信息管理模块菜单选项显示 
			case 2: Select_ManageMenu(stu,szCourseName,npStudentNum);
					break;
			//转到二级菜单：条件排序模块菜单选项显示
			case 3:Select_SortMenu(stu,szCourseName,*npStudentNum);	
					break;
			//转到二级菜单：条件查询模块菜单选项显示
			case 4:Select_QueryMenu(stu,szCourseName,*npStudentNum);
					break;
			//转到二级菜单：文件保存模块菜单选项显示
			case 5:Select_SaveMenu(stu,szCourseName,*npStudentNum);
					break;
			//用户选择退出		
			case 0: printf("\n\n\t\t感谢使用我们的软件，欢迎下次再来！") ;
			        exit(0);
					break; 
			//用户选择有误 
			default:printf("选择有误，请重选！\n");
		}//switch结束 
	}//while(1)函数结束 
}//Select_MainMenu函数结束 

/* 
函数功能：一级菜单：信息管理模块菜单选项显示  
输入参数：学生结构体数组，课程名数组
返回参数：学生人数（因为可能一直改变，用指针变量实现）
*/ 
void Select_ManageMenu(struct student stu[],char szCourseName[][STRLENGTH],int* npStudentNum)
{
	int nManageChoose;
	while(1)
	{   system("CLS");
		printf("\t\t------------------------------\n");
		printf("\t\t|********信息管理模块********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        1.增加学生信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        2.删除学生信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        3.修改学生信息      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|        0.返回上级菜单      |\n");
		printf("\t\t|                            |\n");
		printf("\t\t   ------------------------  \n");
		printf("\n\t数据文件%s中目前共有%d名学生 \n\n",FILENAME,*npStudentNum);
		printf("\t\t   请选择功能序号(0~3):");
		//读入用户选择 
		scanf("%d",&nManageChoose);
		switch(nManageChoose)
		{
			case 1:AddStudentInfo(stu,szCourseName,npStudentNum);//转到增加学生信息函数 
			       OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);//输出给用户看一下 
			       	system("PAUSE");
				   break;
			case 2:DeleteStudentInfo(stu,szCourseName,npStudentNum);//转到删除学生信息函数
			       OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);//输出给用户看一下 
			       	system("PAUSE");
				   break;
			case 3:ModifyStudentScore(stu,szCourseName,*npStudentNum);//转到修改学生信息函数
			        OutputStudentInfo(stu,szCourseName,*npStudentNum,0,0,*npStudentNum);//输出给用户看一下 
			       	system("PAUSE");
					break;
			case 0: Select_MainMenu(stu,szCourseName,npStudentNum);			//返回一级主菜单函数 
			        break;
					
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 */
	}//while(1)结束 

	
}//Select_ManageMenu函数结束 

/* 
函数功能：二级菜单：排序和计算菜单选项显示  
输入参数：学生结构体数组，课程名数组，学生人数
返回值：无 
*/ 
void Select_SortMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum)
{
	int nSortChoose;

	while(1)
	{	system("CLS");
		printf("\t\t------------------------------\n");
		printf("\t\t|********排序计算模块********|\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   1.按学号升序排序         |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   2.总成绩计算及降序排序   |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   3.各科平均成绩计算           |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   4.各科成绩分布计算       |\n");
		printf("\t\t|                            |\n");
		printf("\t\t|   0.返回上级菜单           |\n");
		printf("\t\t|                            |\n");
		printf("\t\t------------------------------  \n");
		printf("\n\t数据文件%s中目前共有%d名学生 \n\n",FILENAME,nStudentNum);
		printf("\t\t   请选择功能序号(0~4):");	
		//读入用户选择 
		scanf("%d",&nSortChoose);
		
		switch(nSortChoose)
		{
			case 1:SortOnNumAs(stu,nStudentNum);//按学号升序排序 
			        //添加完函数后这里就可以解开注释了	
					OutputStudentInfo(stu,szCourseName,nStudentNum,0,0,nStudentNum);//输出给用户看一下 
			       	system("PAUSE");
					break;
			case 2: SortOnSumDs(stu,nStudentNum);//按总成绩降序排序	
			        //添加完函数后这里就可以解开注释了	
					printf("\n\t\t\t计算各人总成绩及平均成绩......\n");
					OutputStudentInfo(stu,szCourseName,nStudentNum,1,0,nStudentNum);//输出给用户看一下 
			       	system("PAUSE");
					break;
			case 3: //添加完函数后这里就可以解开注释了	
			        printf("\n\t\t\t计算总成绩及平均成绩......\n");
			        ComputeAverageScore(stu,szCourseName,nStudentNum);//按总成绩降序排序	
					system("PAUSE");
					break;
			case 4: //添加完函数后这里就可以解开注释了	
			        printf("\n\t\t\t计算各科平均成绩及分布......\n");
			        ComputeDistribution(stu,szCourseName,nStudentNum);//按总成绩降序排序	
					system("PAUSE");
					break;
			case 0:Select_MainMenu(stu,szCourseName,&nStudentNum);//返回一级主菜单选项显示 
					break;
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 
	}//while(1)结束 
}//Select_SortMenu函数结束 


/* 
函数功能：二级菜单：信息查询菜单选项显示  
输入参数：学生结构体数组，课程名数组，学生人数
返回值：无 
*/ 

void Select_QueryMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) 
{	
	int nQueryChoose;
	while(1)
	{
		system("CLS");
		printf("\t\t---------------------------------------\n");
		printf("\t\t|*************信息查询模块************|\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         1.根据学号查询信息          |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         2.根据姓名查询信息          |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         0.返回上级菜单              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t---------------------------------------\n");
		printf("\t\t                            \n");
		printf("\t\t   请选择功能序号(0~2):");
		
		
		scanf("%d",&nQueryChoose);
		
		switch(nQueryChoose)
		{
			case 1: FindByNumber(stu,szCourseName,nStudentNum);	//按学号查询学生信息 
			        system("PAUSE");
					break;
			case 2: FindByName(stu,szCourseName,nStudentNum); //按姓名查询学生信息 
			        system("PAUSE");
					break;
			case 0: Select_MainMenu(stu,szCourseName,&nStudentNum); 	//返回一级主菜单选项 
					break;
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 
		
	}//while结束 
}//信息查询菜单结束 


/* 
函数功能：二级菜单：文件保存选项显示  
输入参数：学生结构体数组，课程名数组，学生人数
返回值：无 
*/ 
void Select_SaveMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) 
{	
	int nSaveChoose;
	while(1)
	{
		system("CLS");
		printf("\t\t---------------------------------------\n");
		printf("\t\t|*************文件保存模块************|\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         1.当前文件保存              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         2.另存其它文件              |\n");
		printf("\t\t|                                     |\n");
	    printf("\t\t|         3.保存平均和总成绩          |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t|         0.返回上级菜单              |\n");
		printf("\t\t|                                     |\n");
		printf("\t\t---------------------------------------\n");
		printf("\t\t                            \n");
		printf("\t\t   请选择功能序号(0~3):");
		scanf("%d",&nSaveChoose);
		switch(nSaveChoose)
		{
			case 1:
				//重新创建数据文件
				CreateFile(stu,nStudentNum,0);
		  		break;
		    case 2:	//另存为其它文件 
				CreateFileAs(stu,nStudentNum,0);
		  		break;
		    case 3:	//另存为其它文件并保存总成绩和其它成绩 
				CreateFileAs(stu,nStudentNum,1);
		  		break;
			case 0:Select_MainMenu(stu,szCourseName,&nStudentNum); 				//返回一级主菜单选项 
					break;
			default:printf("\t\t选择有误，请重选！\n");
		}//switch结束 
		system("PAUSE");
	}//while结束 
}//文件保存菜单结束 


