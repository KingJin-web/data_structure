
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define LIST_INIT_SIZE 50 //顺序表的最大长度
#define LISTINCREMENT 10  //可增加长度
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define CANCEL 0
typedef struct
{               //顺序表结构定义
    int *elem;  //存储空间的基地址
    int length; //长度
    int listsize;
} sqlist;
int compare(int X, int Y) //compare的关系判断
{
    if (X == Y)
        return X;
    else
        return FALSE;
}

void visit(int &y) //将y值增加为原来的2倍
{
    y = 2 * y;
    cout << y << " ";
}

int initlist(sqlist &L) //构造一个空的线性表L
{
    L.elem = new int[LIST_INIT_SIZE]; //动态分配一个存储空间
    if (!L.elem)
        exit(0);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

int destroylist(sqlist &L) //销毁线性表L
{
    delete[] L.elem;
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
    return OK;
}

int clearlist(sqlist &L) //将L重置为空表
{
    L.length = 0; //逻辑删除 标记   L.elem[l.length] = newvalue  L.length++
    return OK;
}

int listempty(sqlist L) //求当前表L是否为空
{
    if (0 == L.length)
        return TRUE;
    else
        return FALSE;
}

int listlength(sqlist L) //求当前线性表L的长度
{
    return L.length;
}

int getelem(sqlist L, int i, int &e) //用e返回L中第i个数据元素的值
{
    if (i < 0 || i >= L.length)
        exit(ERROR);
    e = L.elem[i - 1];
    return OK;
}

//求L中第一个与e满足关系compare()的数据元素的位序，若不存在则返回0
int locateelem(sqlist L, int e, int (*compare)(int x1, int x2))
{
    for (int i = 0; i < L.length; i++)
    {
        if (compare(e, L.elem[i]))
            return i;
    }
    return 0;
}

//若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义
int priorelem(sqlist L, int cur_e, int &pre_e)
{
    int i = 2, *p;
    p = L.elem + 1;
    while (i <= L.length && *p != cur_e)
    {
        p++;
        i++;
    }
    if (i > L.length)
        return CANCEL;
    else
    {
        pre_e = *--p;
        return OK;
    }
    return OK;
}

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义
int nextelem(sqlist L, int cur_e, int &next_e)
{
    int i = 1, *p;
    p = L.elem;
    while (i <= L.length && *p != cur_e)
    {
        p++;
        i++;
    }
    if (i = L.length)
        return CANCEL;
    else
    {
        next_e = *++p;
        return OK;
    }
}

int listinsert(sqlist &L, int i, int e) //在线性表L中第i个位置插入元素e
{
    int *newbase;
    if ((i < 1) || (i > L.length + 1)) //  位序 从1开始
        return ERROR;
    if (L.length >= L.listsize) //当前存储空间已满
    {
        newbase = (int *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(int));
        if (!newbase)
        {
            exit(0);
        }
        L.elem = newbase;                        //新基址
        L.listsize = L.listsize + LISTINCREMENT; //增加后的存储空间
    }
    int k = 0;
    for (k = L.length - 1; k >= i - 1; k--) //数据往后面移动  0 1  2  3 4 5 6
    {
        L.elem[k + 1] = L.elem[k];
    }
    L.elem[k + 1] = e; //插入元素
    ++L.length;
    return OK;
}

int listdelete(sqlist &L, int i, int &e) //将线性表中的第i个元素删除并返回其值
{

    if (i < 1 || i > L.length) //位序从1
        return ERROR;
    else
    {
        e = L.elem[i - 1];
        for (int k = i; k < L.length; k++) // k = l.length
        {
            L.elem[k - 1] = L.elem[k];
        }

        --L.length;
        return OK;
    }
}

//依次对L中的每一个元素调用函数visit(),一旦visit()失败，则操作失败
int listtraverse(sqlist L, void (*visit)(int &p))
{

    for (int i = 0; i < L.length; i++)
    {
        visit(L.elem[i]);
    }
    printf("\n");
    return OK;
}

//（1）	将顺序表的a[i]元素删除（i为３的倍数）
void test1(sqlist &L)
{
    int oldLength = L.length;
    for (int i = oldLength; i >= 3; i--) //1 1 2 3 4 5 6 7 8 9
    {
        if (i % 3 == 0)
        {
            int e = 0;

            listdelete(L, i, e); //
            cout << "delte " << e << endl;
        }
    }
}

//（2）	判断该顺序表中元素是否对称,对称返回1,否则返回0
int test2(sqlist L)
{
    for (int i = 0; i < L.length / 2; i++) // 0 1 2 3 4 5 6 7 8 9
    {

        if (L.elem[i] != L.elem[L.length - i - 1])
            return false;
    }
    return true;
}

//（3）	实现把该表中所有奇数排在偶数之前,即表的前面为奇数,后面为偶数

void test3(sqlist L)
{
    int i = 0;
    int j = L.length - 1;

    while (i < j)
    {
        while (i < j && L.elem[i] % 2 != 0)
            i++;
        while (i < j && L.elem[j] % 2 == 0)
            j--;
        if (i < j)
            swap(L.elem[i], L.elem[j]); //交换
    }
}

void print(sqlist L) //显示当前线性表所有元素
{
    int i;
    for (i = 0; i < L.length; i++)
        cout << L.elem[i] << " ";
}
//（4）	把两个有序顺序表进行有序合并为新的顺序表
sqlist mergeSortedList(sqlist &L1, sqlist &L2)
{
    sqlist newlist;
    newlist.elem = new int[L1.length + L2.length];
    newlist.length = 0;
    newlist.listsize = L1.length + L2.length;

    int i = 0;
    int j = 0;

    while (i < L1.length && j < L2.length)
    {

        if (L1.elem[i] < L2.elem[j])
        {
            newlist.elem[newlist.length++] = L1.elem[i];
            i++;
        }
        else
        {
            newlist.elem[newlist.length++] = L2.elem[j];
            j++;
        }
    }
    //有个表全部 处理完了
    if (i == L1.length) //第一个表都处理完了
    {
        for (; j < L2.length; j++)
            newlist.elem[newlist.length++] = L2.elem[j];
    }
    if (j == L2.length) //第二个表都处理完了
    {
        for (; i < L1.length; i++)
            newlist.elem[newlist.length++] = L1.elem[i];
    }

    return newlist;
}
//(5) 在有序表删除重复数据
void deleteRepeatedData(sqlist &list) // 1 2 3  3 4 5 6 6 8 8 9
{
    for (int i = list.length; i > 0; i--) // i = list.length - 1
        if (list.elem[i] == list.elem[i - 1])
        {
            int e;
            listdelete(list, i + 1, e);
            cout << "delete:" << e << endl;
        }
}

int main(void)
{
    sqlist L1;
    initlist(L1);
    int a[] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 5, 6, 6, 8, 8, 9};
    for (int i = 0; i < sizeof(a) / 4; i++)
    {
        listinsert(L1, i + 1, a[i]);
    }

    sqlist L2;
    initlist(L2);
    int b[] = {1, 2, 3, 3, 2, 1};
    for (int i = 0; i < sizeof(b) / 4; i++)
    {
        listinsert(L2, i + 1, b[i]);
    }
    // deleteRepeatedData(L1);
    // print(L1);
    // cout << "\ntest1,delete a[i]:";
    // test1(L1);
    print(L1);


    
    // if (test2(L1))
    //     cout << "\n对称!\n";
    // else
    //     cout << "\n不对称!\n";
    // print(L2);         
    // if (test2(L2))
    //     cout << "\n对称!\n";
    // else
    //     cout << "\n不对称!\n";
    
    sqlist L3;
    initlist(L3);
    int c[] = {1, 2, 3, 4, 5, 6, 7, 8};

    for (int i = 0; i < sizeof(c) / 4; i++)
    {
        listinsert(L3, i + 1, c[i]);
    }
    printf("\n");
    //test3(L1);
    
    //（3）	实现把该表中所有奇数排在偶数之前,即表的前面为奇数,后面为偶数
    //print(L1);
    
//（4）	把两个有序顺序表进行有序合并为新的顺序表
    print(L3);
    printf("\n");
    print(mergeSortedList(L1,L3));



    /*  sqlist L; //初始化
    
    if (initlist(L))
        cout << "build sqlist success!\n";
    else
        cout << "buildsqlist failed!\n";

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};

    for (int i = 0; i < sizeof(a) / 4; i++)
    {
        listinsert(L, i + 1, a[i]);
    }
    cout << "\n sqlist inited:";
    print(L);
    cout << "\ntest1,delete a[i]:";
    // test1(L);
    print(L);

    if (test2(L))
    {
        cout << "\nIs DuiCheng!\n";
    }
    else
        cout << "\nNo DuiCHeng!\n";

    test3(L);
    print(L); */
    /*  sqlist L1;
    initlist(L1);
    int a[] = {1, 1, 1, 1, 9};
    for (int i = 0; i < sizeof(a) / 4; i++)
    {
        listinsert(L1, i + 1, a[i]);
    }

    sqlist L2;
    initlist(L2);
    int b[] = {1, 4, 6, 8, 10, 12, 14, 16};
    for (int i = 0; i < sizeof(b) / 4; i++)
    {
        listinsert(L2, i + 1, b[i]);
    }

    sqlist newlist = mergeSortedList(L1, L2);
    cout << "merged:";
    print(newlist); */

    return 1;
}