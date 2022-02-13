#include <windows.h>
#include <bits/stdc++.h>

using namespace std;

//int main(){
//    int num1 = -5,num2 = 2;
//    num1 = num2++ - --num2;
//    cout<<num1<<" "<<num2;
//}
//int main() {
//    int i, j, t, k, a[10] = {2, 4, 67, 3, 7, 5, 7, 3, 4, 6};
//    for (i = 0; i < 10 - 1; i++) {
//        k = i;
//        for (j = i + 1; j < 10; j++) {
//            if (a[k] > a[j]) {
//                k = j;
//            }
//        }
//        t = a[i];
//        a[i] = a[k];
//        a[k] = t;
//
//    }
//
//    for (i = 0; i < 10; i++) {
//        printf("%d ", a[i]);
//    }
//}

#define N 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "function.h"

///////////////////////////////////////////////////////////////////////////////
/*学生信息处理函数---增加，删除，修改*/

/* 
函数功能：将输入N个学生信息，返回增加的学生数，并修改学生目前的数目 
输入参数：学生结构体数组，课程名称数组
返回值：学生人数（用指针变量返回，因为这个人数会变化      
返回值：添加的学生人数 
*/
int AddStudentInfo(struct student stu[], char szCourseName[][STRLENGTH], int *npStudentNum)
{
	int n = 0;
	printf("\n\t\t\t这里是增加学生信息模块\n");
	printf("                请输入添加的学生人数：");
	scanf("%d", &n);
	for (int i = 1 + *npStudentNum; i <= n + *npStudentNum; i++)
	{
		printf("                请输入第 %d 个学生学号:", i);
		scanf("%d", &stu[i].nNumber);
		printf("                姓名：");
		scanf("%s", &stu[i].szName[STRLENGTH]);
		printf("                语文成绩：");
		scanf("%d", &stu[i].fScore[0]);
		printf("                数学成绩：");
		scanf("%d", &stu[i].fScore[1]);
		printf("                英语成绩：");
		scanf("%d", &stu[i].fScore[2]);
		printf("                ======================================\n\n\n");
	}
	*npStudentNum += n;
	return 1; //返回添加的学生数

} //AddSudentInfo函数结束

/* 
函数功能：输出学生信息函数 ，可以输出两种，1种是有平均成绩和总成绩的，1种是没有 
输入参数：学生结构体数组，课程名称数组，学生人数，文件格式标志（是否有平均成绩和总成绩）
          没有平均成绩和总成绩文件标志为 0，有平均成绩和总成绩文件标志为 1 
         nFrom 表示从第几个开始输出，nTo表示输到第几个结束  
返回值：无      
*/

void OutputStudentInfo(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum, int nFlag,
					   int nFrom, int nTo)
{
	printf("\n\t\t\t这里是显示学生信息模块\n");
	printf("        数据文件studentlist.txt中目前共有%d名学生\n\n", nStudentNum);
	if (nFlag == 0)
	{
		printf("STL             学号  姓名      语文    数学    英语\n");
		printf("                ======================================\n");
		for (int i = nFrom; i <= nTo; i++)
		{
			printf("\n\t\t%d    %s        %.2f    %.2f    %.2f", stu[i].nNumber, stu[i].szName[STRLENGTH], stu[i].fScore[1], stu[i].fScore[2], stu[i].fScore[3], stu[i].fAveScore, stu[i].fSumScore);
		}
	}
	else if (nFlag == 1)
	{
		printf("STLSA           学号  姓名      语文    数学    英语    总成绩    平均成绩\n");
		printf("                ============================================================\n");
		for (int i = nFrom; i <= nTo; i++)
		{
			printf("\n\t\t%d    %s        %.2f    %.2f    %.2f     %.2f        %.2f", stu[i].nNumber, stu[i].szName[STRLENGTH], stu[i].fScore[1], stu[i].fScore[2], stu[i].fScore[3], stu[i].fAveScore, stu[i].fSumScore);
		}
	}
}
//输出学生信息函数结束

/* 
函数功能：删除某位学生信息的函数，函数内部自带输入 
输入参数：学生结构体数组，课程名称数组
返回值：学生人数（以指针变量形式，因为人数会变化） 
         nFrom 表示从第几个开始输出，nTo表示输到第几个结束  
返回值：是否成功删除，0为没成功删除，1为成功删除      
*/
int DeleteStudentInfo(struct student stu[], char szCourseName[][STRLENGTH], int *npStudentNum)
{
	int num = 0;
	int flag = 0;
	printf("\n\t\t\t这里是删除学生信息模块\n");
	printf("                请输入要删除的学生学号：");
	scanf("%d", &num);
	for (int i = 0; i < *npStudentNum; i++)
	{
		if (num == stu[i].nNumber)
		{
			for (int j = i; j < *npStudentNum; j++)
			{
				stu[j] = stu[j + 1];
				flag = 1;
				return 1;
			}
		}
		if (flag == 0)
		{
			return 0;
		}
		return 1;
	} //DeleteStudentInfo函数结束

	/* 
函数功能：修改某位学生的成绩信息，函数内部自带输入 
输入参数：学生结构体数组，课程名称数组，学生人数 
返回值：是否成功修改，0为没成功修改，1为成功修改     
*/
	int ModifyStudentScore(struct student stu[], char szCourseName[][STRLENGTH], int nStudentNum)
	{
		int num = 0;
		printf("\n\t\t\t 这里是修改学生信息模块\n");
		int flag = 1;
		printf("                请输入要修改的学生学号：");
		scanf("%d", &num);
		for (int i = 0; i < nStudentNum; i++)
		{
			if (stu[i].nNumber == num)
			{
				flag = 0;
				printf("\n");
				printf("                        ************************************\n");
				printf("                        *         0.语文成绩               *\n");
				printf("                        *         1.数学成绩               *\n");
				printf("                        *         2.英语成绩               *\n");
				printf("                        ************************************\n");
				printf("                请选择要修改什么成绩(press 0.1.2)：");
				int x = 0;
				scanf("%d", &x);
				printf("                请输入修改后的成绩(0-100):");
				scanf("%d", &stu[i].fScore[x]);
				printf("                ......已修改%d号学生的数学成绩......", num);
			}
		}
		if (flag == 1)
		{
			printf("                没有您输的学号，请输入正确的学号");
		}
		return 1;
	} //ModifyScore函数结束

	//
	//
	//void Srand(int a, int b, int r[]);
	//
	//void Adder(int *p);
	//
	//int main() {
	//    int x, y, num[N], tz;
	//    printf("生成(m,n)范围内的N个随机数，请输入m,n(m<n&&n-m>N):");
	//    scanf("%d%d", &x, &y);
	//    do {
	//        Srand(x, y, num);
	//        Adder(num);
	//        printf("是否继续？\n1.是\t2.否\n");
	//        scanf("%d", &tz);
	//        system("cls");
	//    } while (tz == 1);
	//    return 0;
	//}
	//
	//void Srand(int a, int b, int r[]) {
	//    srand(time(nullptr));
	//    int i;
	//    for (i = 1; i < 2 * N + 1; i++) {
	//        r[i] = a + rand() % (b - a + 1);        //产生一组随机数
	//    }
	////    for(i=1;i<2*N+1;i++)
	////      {
	////        printf("%d\t",r[i]);
	////        if(i%5==0)
	////            printf("\n");
	////      }
	//}
	//
	//void Adder(int *p) {
	//    int answer[N], error[N];
	//
	//    int i, j = 0, k = 0, gg = 0;
	//    for (i = 1; i < N + 1; i++, p += 2) {
	//        printf("%d: %d + %d =", i, *(p + 1), *(p + 2));
	//        scanf("%d", answer + i);
	//        if (*(p + 2) + *(p + 1) == *(answer + i)) {
	//            gg++;
	//        } else {
	//            error[j] = i;
	//            j++;
	//        }
	//        k = j;
	//    }
	//    if (!k) {
	//        printf("恭喜你,全对了！");
	//        gg = 0;
	//    } else {
	//        printf("你的得分是%d\n", gg);
	//        gg = 0;
	//        printf("其中你的错题是:\n");
	//        for (j = 0; j < k; j++)
	//            printf("%d题\t", error[j]);
	//
	//    }
	//    printf("\n");
	//}
