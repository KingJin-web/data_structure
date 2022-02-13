#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include"function.h"

////////////////////////////////////////////////////////////////////////////////////// 
                            /*文件相关函数*/
 /* 
函数功能：创建文件，并将现有的数据写入文件 
输入参数：学生结构体数组，学生人数，文件格式标志 
           注意有两种存储文件格式,1种是没有平均成绩和总成绩的,1种是有的
		   为了区分两种文件格式,将文件格式标志写到数据文件里面 
          文件格式标志：0 表示 "STL" 是存储为基本学生数据表信息文件 (无总成绩和平均成绩) 
                        1 表示 "STLSA" 是基本学生数据表+总成绩和平均成绩 
            ***文件格式标志为程序员自己定义的，用记事本打开studentlist.txt可以看到存储数据内容 
返回值：0: 创建成功，1，创建不成功 
*/ 

int CreateFile(struct student stu[],int nStudentNum,int nFlag)
{
		//数据写入文件
		FILE* fp=fopen(FILENAME,"w");
		if(fp!=NULL)
		{	
			WriteToFile(fp,stu,nStudentNum,nFlag);
			printf("\t\t已成功将%d个学生数据写入数据文件%s.......\n",nStudentNum,FILENAME);
			//给用户显示目前的信息
	 		return 1;
		}
		  
		else //文件创建不成功 
			return 0;
		
	
}//创建文件结束 

 /* 
函数功能：另存为文件，并将现有的数据写入文件 
输入参数：学生结构体数组，学生人数，文件格式标志 
          文件格式标志：0 表示 "STL" 是存储为基本学生数据表信息文件 
                        1 表示 "STLSA" 是基本学生数据表+总成绩和平均成绩 
            ***文件格式标志为程序员自己定义的，用记事本打开dd.txt，和  
			    Studentscore.data可以看到存储数据内容 
返回值：0: 创建成功，1，创建不成功 
*/ 
			
int CreateFileAs(struct student stu[],int nStudentNum,int nFlag)
{
    char szFileName[STRLENGTH];
    if(nStudentNum<1)
	{
			printf("\t\t当前没有学生数据，请到信息管理模块添加数据！\n");
			return 0;
	}
	if(nFlag==1&&stu[0].fSumScore<1)
	{
			printf("\t\t当前没有总成绩和平均成绩信息，请到排序计算模块计算成绩！\n");
			return 0;
	}
	 
	while(1)
   {
	    printf("\n\t\t请输入拟保存的文件名: ");
	  
	    scanf("%s",szFileName);
	    if(strcmp(szFileName,FILENAME)==0)
	    	printf("\n\t\t该文件名为系统文件名，不可使用！\n");
	    else
	    	break; 
	}
	//数据写入文件
	FILE* fp=fopen(szFileName,"w");
	if(fp!=NULL)
	{
		WriteToFile(fp,stu,nStudentNum,nFlag);
		printf("\t\t已成功将%d个学生数据写入数据文件%s.......\n",nStudentNum,szFileName);
		fclose(fp);
		//给用户显示目前的信息
 		return 1;
	}
	  
	else //文件创建不成功 
		return 0;
		
	
}//创建另存为文件结束 


/* 
函数功能：读取文件，并提取文件中的元素信息保存到学生结构体中
   注意：如果从数据文件中读到的起始字符串是"STL" 表示是基本学生数据表信息文件 
                          读到 "STLSA" 是基本学生数据表+总成绩和平均成绩 
            ***文件格式标志为程序员自己规定的，用记事本打开dd.txt，和  
			    Studentscore.data可以看到存储数据内容  
输入参数：文件指针，学生结构体数组
          
返回值：读到的学生数 
*/ 

int ReadFromFile(FILE *fp,struct student stu[])
{
	int i=0;
	char szFileFlag[STRLENGTH];//先读文件标记
	fscanf(fp,"%s",szFileFlag) ;
	int nFlag=-1;
	if(strcmp(szFileFlag,FILEFLAG1)==0)
		nFlag=0;
	if(strcmp(szFileFlag,FILEFLAG2)==0)
		nFlag=1;
	if (nFlag==-1)
	  return 0; //如果是未知的文件头，返回0 
	do
	{
		int nReadNum=0;
		//读学号和姓名 
		nReadNum+=fscanf(fp,"%d%s",&stu[i].nNumber,&stu[i].szName);
		//读各科成绩 
		for(int j=0;j<COURSENUM;j++)
		  nReadNum+=fscanf(fp,"%f",&stu[i].fScore[j]);
		//如果是STLSA，读总成绩和平均成绩
		if(nFlag==1)
		  fscanf(fp,"%f%f",&stu[i].fSumScore,&stu[i].fAveScore); 
		//成功读取，计数器+1 
		if (nReadNum==(COURSENUM+2))
			i++;
		else
			break;
	}
	while(1);
	return i;//返回读到的学生数 
	
}
//ReadFromFile 函数结束		



/* 
函数功能：将目前学生结构体的数据，写入一个文件
输入参数：文件指针，学生结构体数组，学生人数，文件格式标志 
          文件格式标志：0 表示 "STL" 是存储为基本学生数据表信息文件 
                        1 表示 "STLSA" 是基本学生数据表+总成绩和平均成绩 
            ***文件格式标志为程序员自己定义的，用记事本打开dd.txt，和  
			    Studentscore.data可以看到存储数据内容 
          
返回值：读到的学生数 
*/ 
 void WriteToFile(FILE* fp,struct student stu[],int nStudentNum,int nFlag)
{
	//输出标题 
	if(nFlag==0)
		fprintf(fp,FILEFLAG1);
	else if(nFlag==1)
		fprintf(fp,FILEFLAG2);
	fprintf(fp,"\n");
	for(int i=0;i<nStudentNum;i++)	
 	{
  		//写入数据文件 
  		fprintf(fp,"%d %s ",stu[i].nNumber,stu[i].szName);
  		//写各科成绩 
		for(int j=0;j<COURSENUM;j++)
			fprintf(fp,"%.2f ",stu[i].fScore[j]);
		if(nFlag==1) 
			fprintf(fp,"%.2f %.2f",stu[i].fSumScore,stu[i].fAveScore);
		fprintf(fp,"\n");  		

 	}//for循环结束  
	
}//Write to File 函数结束

