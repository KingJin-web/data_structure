/*实验二  单链表的插入和删除
 
一、目的：
了解和掌握线性表的逻辑结构和链式存储结构，掌握单链表的基本算法及相关的时间性能分析。
二、要求：
建立一个数据域定义为整数的单链表，实现线性表各个常用功能并测试分析。 
三、实验内容
1、 给定链表程序框架，请分析、理解程序，补充完整并测试。	 
3. 增加功能：链表逆转
4. 增加功能：两个有序链表合并为一个有序链表

四、实验报告要求
实验报告的内容：1.实验目的 2.实验内容  3.实验步骤  4. 程序源代码(程序测试运行截图) 5.实验小结  
 
 
*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include <iostream>
using namespace std;

typedef struct node //定义结点
{
    int data;          //结点的数据域为字符串
    struct node *next; //结点的指针域
} ListNode;
typedef ListNode *LinkList; // 自定义LinkList单链表类型

LinkList initList()
{
    LinkList head = (ListNode *)malloc(sizeof(ListNode)); //生成头结点
    head->next = NULL;
    return head;
}
LinkList CreateListByHeadInsert(int *a, int n) //头插法
{

    LinkList head = (ListNode *)malloc(sizeof(ListNode)); //生成头结点
    head->next = NULL;
    head->data = 0; // 不要

    for (int i = 0; i < n; i++) //  head->1->2->3->NULL
    {
        ListNode *newnode = (ListNode *)malloc(sizeof(ListNode)); //生成头结点
        newnode->next = head->next;
        head->next = newnode;
        newnode->data = a[i];
    }

    return head; //返回头指针
}

LinkList CreateListByTailInsert(int *a, int n) //尾插法
{

    LinkList head = (ListNode *)malloc(sizeof(ListNode)); //生成头结点
    head->next = NULL;
    head->data = 0; // 不要
    ListNode *tailNode = head;
    for (int i = 0; i < n; i++) //  head
    {
        ListNode *newnode = (ListNode *)malloc(sizeof(ListNode)); //生成头结点
        newnode->next = NULL;
        newnode->data = a[i];
        tailNode->next = newnode;
        tailNode = newnode;
    }

    return head; //返回头指针
}
//==========按值查找结点，找到则返回该结点的位置，否则返回NULL==========
ListNode *LocateNode(LinkList head, int key) //相当于 判断
{
    ListNode *p = head->next; //从开始结点比较 经典语句 指的是第一个数据节点

    while (p != NULL)
    {
        if (p->data == key) //
            return p;
        else
        {
            p = p->next; // 经典语句 指的是下一个数据节点
        }
    }
    return NULL;
}
//==========删除带头结点的单链表中的指定结点=======
void DeleteList(LinkList head, int key)
{

    ListNode *p = head; //从开始结点比较 经典语句 指的是第一个数据节点
    ListNode *deleteNode = NULL;
    while (p->next != NULL)
    {
        if (p->next->data == key) //    p = deleteNode->priory
            deleteNode = p->next;
        else
        {
            p = p->next; // 经典语句 指的是下一个数据节点
        }
    }
    //删除p->next  deleteNode倒数第一个节点
    if (deleteNode != NULL) //deleteNOde->prority ==  p ？？？
    {
        p->next = deleteNode->next;
        delete deleteNode;
    }
}

ListNode *findNode(LinkList head, int pos) //第pos个节点返回 pos从0
{
    ListNode *p = head;

    int index = 0; //遍历节点的下标

    while (p != NULL)
    {
        if (index == pos)
            return p;
        p = p->next;
        index++;
    }
    return NULL;
}

//==========插入带头结点的单链表中的指定结点=======
//head->1->2->3   pos= 2
bool InsertList(LinkList head, int pos, int key)
{
    if (pos >= 0)
        return false;
    ListNode *p = findNode(head, pos - 1); //
    if (p == NULL)
        return false;

    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode)); //生成头结点
    newnode->data = key;
    newnode->next = p->next;
    p->next = newnode;

    return true;
}
//===========打印链表=======
void printlist(LinkList head)
{
    ListNode *p = head; //从开始结点打印
    while (p->next)
    {
        printf("%d ", p->next->data);
        p = p->next;
    }
    printf("\n");
}
//==========删除所有结点，释放空间===========
void DeleteAll(LinkList &head)
{
    ListNode *deleteNode;

    // head->1->2->3->4->NULL
    while (head->next)
    {
        deleteNode = head->next;
        head->next = deleteNode->next;
        free(deleteNode);
    }
    free(head);
    head = NULL;
}

/**
 * 3. 增加功能：链表逆转
 * */
void reverseList_recur(LinkList head, LinkList current)
{
    if (current == NULL)
        return;

    if (head == NULL)
        return;
    ListNode *p = head->next;
    ListNode *q = current->next;

    head->next = current;
    current->next = p;
    reverseList_recur(head, q);
}
/**
 * 3. 增加功能：链表逆转
 * */
void reverseList(LinkList list)
{
    if (list == NULL)
        return;
    if (list->next == NULL)
        return;
    if (list->next->next == NULL)
        return;
    ListNode *p = list->next->next;
    list->next->next = NULL;
    reverseList_recur(list, p);
}

void reverseList2(LinkList head)
{
    if (head == NULL)
        return;

    ListNode *p = head->next; //first data node
    ListNode *oldHeadNext = head->next;
    while (p != NULL)
    {
        ListNode *q = p->next;
        ListNode *originHeadNext = head->next;

        head->next = p;

        if (oldHeadNext == p)
            p->next = NULL;
        else
            p->next = originHeadNext;

        p = q;
    }
}

//4. 增加功能：两个有序链表合并为一个有序链表
LinkList mergeSort(LinkList list1, LinkList list2)
{
    ListNode *p1 = list1->next;
    ListNode *p2 = list2->next;
    ListNode *newHead = new ListNode();
    ListNode *p3 = newHead; //指新表的尾节点
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data <= p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        else if (p1->data > p2->data)
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    }

    if (p1 == NULL)
    {
        p3->next = p2;
    }
    if (p2 == NULL)
    {
        p3->next = p1;
    }
    return newHead;
}

//==========主函数==============
int main()
{
    int a[] = {1, 3};
    int b[] = {2, 4, 6, 8, 10, 12, 14};
    LinkList list = CreateListByTailInsert(a, 2);
    LinkList list2 = CreateListByTailInsert(b, 7);
    // cout<<"逆转前"<<endl;
    // printlist(list2);
    // reverseList(list2);
    // cout<<"逆转后"<<endl;
    printlist(list2);
    printlist(list);
    // reverseList(list);
    // printlist(list);

    //reverseList(list);
    LinkList list3 = mergeSort(list, list2);
    printlist(list3);

    system("pause");
    //单步调试
    return 1;
}
