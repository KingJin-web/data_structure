// #include<stdio.h> 
// #include<string.h> 
// #include<stdlib.h> 
// #include<iostream> 
// #define LIST_INIT_SIZE 50 
// #define LISTINCREMENT 10 
// #define TRUE 1 
// #define FALSE 0 
// #define OK 1 
// #define ERROR 0 
// #define CANCEL 0 
// typedef struct{ 
// 	int *elem; 
// 	int length; 
// 	int listsize; 
// }sqlist; 
// int compare(int X,int Y) 
// {
// 	if(X==Y) 
// 		return X; 
// 	else return FALSE; 
// }//compare的关系判断 
// void visit(int &y) 
// { 
// 	y=2*y; 
// 	cout<<y<<" "; 
// }//将y值增加为原来的2倍 
// int initlist(sqlist &L) 
// { 
// 	XXXXXXXXXXXXXXXX 
// 	return OK; 
// }//构造一个空的线性表L 
// int destroylist(sqlist &L) 
// { 
// 	XXXXXXXXXXXXXXXXXXXXX
// 	return OK; 
// }//销毁线性表L 
// int clearlist(sqlist &L) 
// { 
// 	L.length=0; 
// 	return OK; 
// }//将L重置为空表 
// int listempty(sqlist L) 
// { 
// 	if (0==L.length) 
// 		return TRUE; 
// 	else 
// 		return FALSE; 
// }//求当前表L是否为空 
// int listlength(sqlist L) 
// { 
// 	return L.length; 
// }//求当前线性表L的长度 
// int getelem(sqlist L,int i,int &e) 
// { 
// 	if(i<0||i>=L.length) 
// 		exit(ERROR); 
// 	XXXXXXXXXXXXXXXXXXXXXXXXX
// 	return OK; 
// }//用e返回L中第i个数据元素的值 
// int locateelem(sqlist L,int e,int(*compare)(int x1,int x2)) 
// { 
// 	int i=1,j=0,*p; 
// 	XXXXXXXXXXXXXXXXXXXXXXX
// 		return FALSE; 
// }//求L中第一个与e满足关系compare()的数据元素的位序，若不存在则返回0 
// int priorelem(sqlist L,int cur_e,int &pre_e) 
// { 
// 	int i=2,*p; 
// 	p=L.elem+1; 
// XXXXXXXXXXXXXXXXXXXXXXX
//  XXXXXXXXXXXXXXXXXXXXXXX
// }//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义 
// int nextelem(sqlist L,int cur_e,int &next_e) 
// { 
// 	int i=1,*p; 
// 	p=L.elem; 
// XXXXXXXXXXXXXXXXXXXXXXX
// }//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义 
// int listinsert(sqlist &L,int i,int e) 
// { 
// 	int *newbase,*p,*q; 
// 	if((i<1)||(i>L.length+1)) 
// 		return ERROR; 
// 	if (L.length>=L.listsize) 
// 	{ 
// 		newbase=XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX; 
// 		if(!newbase) 
// 		{ 
// 			exit(0); 
// 		} 
// 		L.elem=newbase; 
// 		L.listsize=L.listsize+LISTINCREMENT; 
// 	} 
// XXXXXXXXXXXXXXXXXXXXXXX
// 	++L.length; 
// 	return OK; 
// }//在线性表L中第i个位置插入元素e 
// int listdelete(sqlist &L,int i,int &e) 
// { 
// 	int *p,*q; 
// 	if(i<1||i>L.length) 
// 		return ERROR; 
// 	else 
// 	{ 
// 	XXXXXXXXXXXXXXXXXXXXXXX
// 		return OK; 
// 	} 
// }//将线性表中的第i个元素删除并返回其值 
// int listtraverse(sqlist L,void(*visit)(int &p)) 
// { 
// 	XXXXXXXXXXXXXXXXXXXXXXX
// 	return OK; 
// }//依次对L中的每一个元素调用函数visit(),一旦visit()失败，则操作失败 

// //（1）	将顺序表的a[i]元素删除（i为３的倍数）。
// //（2）	判断该顺序表中元素是否对称,对称返回1,否则返回0。
// //（3）	实现把该表中所有奇数排在偶数之前,即表的前面为奇数,后面为偶数。
// //（4）	把两个有序顺序表进行有序合并为新的顺序表
// void main() 
// {
 
// }