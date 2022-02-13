/**********************************************
程序编号：11-01-1.1
程序名称：学生成绩管理系统     Student Score Management System  
程序功能：1）读取文件并显示,若指定文件不存在则创建文件并引导用户手动录入并保存在文件中 
          2）对已有学生信息进行增加、删除和修改
		  3)可根据学生学号、语文、数学、英语及总成绩进行排序
		  4）可根据学号、姓名查询学生信息；可查询语数英的班级平均分及各分数段分布
程序输入：学生成绩信息数据文件 
程序输出：对程序功能实现的屏幕显示输出 
程序员：  杨雯雯 1.0
编程时间：2016-08-16 
修改人：冯筠
修改时间：2022-01-18，主要添加了注释，将退出本级菜单全部改为0 
版本号：  1.1
*************************************************/
/*对库函数的定义*/ 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>
#include"function.h"

/* 系统主函数，初始化，调用等功能 */ 
int main() 
{	
 /* 基本数据结构 */ 
  
     //定义学生结构体数组，这个数组一直作为参数在需要的函数之间传递 
    struct student stu[STUDENTNUM];
    //存储学生个数 ，这个个数一直作为参数在需要的函数之间传递 
	int nStudentNum=0;
	//定义课程名称 
	char szCourseName[COURSENUM][STRLENGTH]={"语文","数学","英语"};
	
///////////////////////////////////////////////////////////////////////////////	
       /* 显示菜单前的准备 */ 	
	system("color 5e") ;//改变背景前景色

	//打开学生数据文件 
	FILE * fp=fopen(FILENAME,"r"); //为简化系统，文件名在宏定义里面给定 
	
	//若数据文件不存在，新建数据文件 
	if(fp==NULL)
	{	
	     printf("\t\t系统指定数据文件: %s 不存在，需要手工输入数据\n",FILENAME);	
	    //调用添加学生信息函数	
		AddStudentInfo(stu,szCourseName,&nStudentNum);
		printf("\t\t已成功添加%d个学生数据.......\n",nStudentNum);
		
		//调用创建数据文件函数 
		if(!CreateFile(stu,nStudentNum,0))
			printf("\t\t创建数据文件: %s 失败，添加的数据没有保存在数据文件中\n",FILENAME);	
		//创建数据文件失败不影响数据添加，只是告知用户没有保存在数据文件中就行啦。 
		
	}//创建文件结束 
	
	//若数据文件现成有，读取现有数据文件信息
	else 
	{	//调用读取数据文件函数 
	    nStudentNum=ReadFromFile(fp,stu);
	    
	    //输出读取文件状态 
		if(nStudentNum>0)
			printf("\t\t已成功从数据文件中%s读取了%d个学生的数据.......\n\t\t",FILENAME,nStudentNum);
		else
			printf("\t\t数据文件%s没有数据或格式不对，请使用信息管理功能添加数据.......\n\t\t",FILENAME);
		fclose(fp); 
		
	}//关闭文件
	
	//让用户看完回车反馈后继续进行 
    system("pause");
///////////////////////////////////////////////////////////////////////////////   
    /*给用户显示主菜单,将程序控制交给主菜单控制程序*/
	Select_MainMenu(stu,szCourseName,&nStudentNum); 	 
} 
