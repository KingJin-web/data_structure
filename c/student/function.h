#define COURSENUM 3//课程门数 
#define STRLENGTH 30//字符串长度 
#define STUDENTNUM 100//学生人数 
#define FILENAME "studentlist.txt"//缺省数据文件名 
#define FILEFLAG1  "STL" //数据文件格式标记，基本学生数据表
#define  FILEFLAG2 "STLSA" //数据文件格式标记，基本学生数据表+总成绩和平均成绩 

/* 学生结构体定义 */ 
struct student   
{
  int nNumber;  	//学号,4位
  char szName[STRLENGTH];	//姓名，2-3个汉字
  float fScore[COURSENUM];//学生几门课的成绩
  float fAveScore;	//平均分  
  float fSumScore;	//总成绩 
};

/*菜单相关函数 共计5个*/ 
//一级主菜单选项显示
void Select_MainMenu(struct student stu[],char szCourseName[][STRLENGTH],int* pNum);	
/* 二级菜单：信息管理模块菜单选项显示  */
void Select_ManageMenu(struct student stu[],char szCourseName[][STRLENGTH],int* pNum);
/* 二级菜单：排序计算菜单选项显示 */ 
void Select_SortMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum);
/* 二级菜单：条件查询菜单选项显示 */ 
void Select_QueryMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum);
/* 二级菜单：文件保存菜单选项显示 */ 
void Select_SaveMenu(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum);
////////////////////////////////////////////////////////////////////////////////////////

/*信息管理相关函数，共计4个*/ 
//添加个学生信息 
int AddStudentInfo(struct student stu[],char szCourseName[][STRLENGTH],int*npStudentNum);
//输出学生信息				
void OutputStudentInfo(struct student stu[],char szCourseName[][STRLENGTH],int num,int flag,int nFrom,int nTo);
// 删除1个学生信息,返回正常删除了还是没有删除 
int DeleteStudentInfo(struct student stu[],char szCourseName[][STRLENGTH],int* npStudentNum); 
/* 修改指定学生的成绩信息 */ 
int ModifyStudentScore(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum);  
/////////////////////////////////////////////////////////////////////////////////////////////

/*文件相关函数，共计4个*/
//创建文件，并将现有的数据写入文件				
int CreateFile(struct student stu[],int nStudentNum,int nFlag);
//创建另存为其它文件名 
int CreateFileAs(struct student stu[],int nStudentNum,int nFlag);
//读取文件，并提取文件中的元素信息保存到学生结构体中				
int ReadFromFile(FILE* fp,struct student stu[]);
//将当前的学生信息写入文件 
void WriteToFile(FILE* fp,struct student stu[],int nStudentNum,int nFlag);
////////////////////////////////////////////////////////////////////////////////

/* 排序计算相关函数，共计4个  */ 
//按学号升序排序 
void SortOnNumAs(struct student stu[],int nStudentNum);
// 选择法实现按总成绩降序排序   
void SortOnSumDs(struct student stu[],int nStudentNum);
// 计算各科平均分 */ 
void ComputeAverageScore(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum); 
//计算各科的成绩分布
void ComputeDistribution(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum); 
/////////////////////////////////////////////////////////////////////////////////////////////

/*查询相关函数，共计2个*/
/*按学号查找 */
void FindByNumber(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) ; 
/*按姓名查找 */
void FindByName(struct student stu[],char szCourseName[][STRLENGTH],int nStudentNum) ;
/////////////////////////////////////////////////////////////////////////////////////////////
