/*
实验三  栈和队列的实现
一、目的：
  巩固栈和队列数据结构，学会运用栈和队列。
1.回顾栈和队列的逻辑结构和受限操作特点，栈和队列的物理存储结构和常见操作。
2.学习运用栈和队列的知识来解决实际问题。
3.进一步巩固程序调试方法。
4.进一步巩固模板程序设计。
二、实验内容：
 1. 编写程序实现顺序栈的各种基本运算：在main函数里实现并测试以下功能：
（1）初始化栈s；
（2）判断栈s是否为空；
（3）依次进栈元素a，b，c，d；
（4）判断栈s是否为空；
（5）输出栈s的长度；
（6）栈里元素依次出栈,并输出；
（7）销毁栈s。
2.编写程序实现链队列的各种基本运算，在main函数里实现并测试以下功能：
（1）初始化链队列q；
（2）判断链队列q是否为空；
（3）依次入队元素a，b，c；
（4）出队一个元素，并输出该元素；
（5）输出链队列q的长度；
（6）依次入队元素d，e，f；
（7）输出链队列q的长度；
（8）出队所有元素，并输出出队序列；
（9）销毁链队列q。

三、附加内容（详细内容略，请同学们自行找相关书籍进行练习）
  1. 括号匹配
  2. 表达式求值
  3. 使用两个栈实现一个队列
  4. 用栈实现判断出站顺序是否正确:
      比如入栈顺序是1 2 3 4；则出栈顺序4 3 2 1，1 4 3 2而1 4 2 3就不是
*/

#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>
typedef char ElemType;
typedef struct linknode
{
    ElemType data;              //数据域
    struct linknode *next;      //指针域
} LiStack;

void InitStack(LiStack *&s)     //初始化栈s
{   s=(LiStack *)malloc(sizeof(LiStack));
    s->next=NULL;
}

void DestroyStack(LiStack *&s)  //销毁栈
{   LiStack *p=s,*q=s->next;
    while (q!=NULL)
    {   free(p);
        p=q;
        q=p->next;
    }
    free(p);    //此时p指向尾节点,释放其空间
}
bool StackEmpty(LiStack *s) //判断栈是否为空
{
    return(s->next==NULL);
}
void Push(LiStack *&s,ElemType e)   //进栈
{   LiStack *p;
    p=(LiStack *)malloc(sizeof(LiStack));
    p->data=e;              //新建元素e对应的节点*p
    p->next=s->next;        //插入*p节点作为开始节点
    s->next=p;
}
bool Pop(LiStack *&s,ElemType &e)   //出栈
{   LiStack *p;
    if (s->next==NULL)      //栈空的情况
        return false;
    p=s->next;              //p指向开始节点
    e=p->data;
    s->next=p->next;        //删除*p节点
    free(p);                //释放*p节点
    return true;
}
bool GetTop(LiStack *s,ElemType &e) //取栈顶元素
{   if (s->next==NULL)      //栈空的情况
        return false;
    e=s->next->data;
    return true;
}
extern void InitStack(LiStack *&s);
extern void DestroyStack(LiStack *&s);
extern bool StackEmpty(LiStack *s);
extern void Push(LiStack *&s,ElemType e);
extern bool Pop(LiStack *&s,ElemType &e);
extern bool GetTop(LiStack *s,ElemType &e);

int length(LiStack *s)
{
    int i=0;
    LiStack *p=s;
    while(p->next!=NULL)
    {
    p=p->next;
    i++;
    }
    return i;
}
int  main()
{
    ElemType e;
    LiStack *s;
    printf("栈s的基本运算如下:\n");
    printf("  (1)初始化栈s\n");
    InitStack(s);
    printf("  (2)栈为 %s\n",(StackEmpty(s)?" 空":" 非空"));
    printf("  (3)依次进栈元素a,b,c,d,e\n");
    Push(s,'a');
    Push(s,'b');
    Push(s,'c');
    Push(s,'d');
    Push(s,'e');
    printf("  (4)栈为 %s\n",(StackEmpty(s)?" 空": "非空"));
    printf("  (5)栈长度: %d\n",length(s));
    printf("  (6)出栈序列:");
    while (!StackEmpty(s))
    {
        Pop(s,e);
        printf("%c ",e);
    }
    printf("\n");
    
    printf("  (7)栈为 %s\n",(StackEmpty(s)?" 空":" 非空"));
    printf("  (8)释放栈\n");
    DestroyStack(s);
    system("pause");
}
