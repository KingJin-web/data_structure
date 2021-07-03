#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Suject
{
    char name[20];      //课程名称
                        //开课学期可以用一个字符串存储，也可以用三个整形数组存储
    char openTime[15];  //开课时间
                        //课程性质可以用整数表示
    char attribute[10]; //课程性质
    char discrip[10];   //教学效果
} Subject;

typedef struct Element
{
    char num[10];
    char name[10];
    char title[10];
    char sex[5];
    Subject subject1;
    Subject subject2;
    int score; //综合评分
} Element;

typedef struct Info
{
    Element data;
    struct Info *next;
} Info, *pInfo;

typedef struct List
{
    int len;
    pInfo next;
} List, *pList;

/** 初始化 */
void ListInit(pList *list);

/** 输入功能 */
void ListInput(pList list);

/** 显示功能 */
void ListDisplay(pList list);

/** 查找功能 */
void ListSearch(pList list, char *key);

/** 排序功能 */
void ListSort(pList list, int way);

/** 插入功能 */
void ListInsert(pList list, Element data);

/** 修改功能 */
void ListChange(pList list, char *num, Element data);

/** 删除功能 */
void ListDelete(pList list, char *name);

/** 销毁一条链 */
void ListDestroy(pList list);

/** 输入一条记录 */
void ListInputSingle(Element *data);

/** 显示一条记录的信息 */
void ListPrint(Element data);

int main()
{
    pList list = NULL;
    Element data;
    ListInit(&list);

    int way; //排序方式
    char input[10];
    char key[20];
    do
    {
        scanf("%s", input);
        if (strcmp("input", input) == 0)
        {
            ListInput(list);
        }
        else if (strcmp("display", input) == 0)
        {
            ListDisplay(list);
        }
        else if (strcmp("search", input) == 0)
        {
            scanf("%s", key);
            ListSearch(list, key);
        }
        else if (strcmp("sort", input) == 0)
        {
            scanf("%d", &way);
            ListSort(list, way);
        }
        else if (strcmp("insert", input) == 0)
        {
            ListInputSingle(&data);
            ListInsert(list, data);
        }
        else if (strcmp("change", input) == 0)
        {
            scanf("%s", key);
            ListInputSingle(&data);
            ListChange(list, key, data);
        }
        else if (strcmp("delete", input) == 0)
        {
            scanf("%s", key);
            ListDelete(list, key);
        }
        else if (strcmp("quit", input) == 0)
            break;
    } while (1);
    ListDestroy(list);
    return 0;
}

/** 初始化 */
void ListInit(pList *list)
{
    if (*list == NULL)
        *list = (pList)malloc(sizeof(List)); //头结点
    (*list)->next = NULL;
    (*list)->len = 0;
}

/** 输入功能: 一次完成若干条信息的输入 */
void ListInput(pList list)
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        pInfo temp = (pInfo)malloc(sizeof(Info));
        ListInputSingle(&temp->data);
        temp->next = list->next; //头插法插入链表   也可以直接使用insert函数
        list->next = temp;
        list->len++;
    }
}

/** 显示功能 */
void ListDisplay(pList list)
{
    pInfo p = list->next;
    if (p == NULL)
    {
        return;
    }
    while (p)
    {
        ListPrint(p->data);
        p = p->next;
    }
}

/** 查找功能 key 为姓名或课程名称 */
void ListSearch(pList list, char *key)
{
    int flag = 0;     //标记是否找到
    if (list == NULL) //理论上list不会为空
    {
        return;
    }
    pInfo p = list->next;
    while (p)
    {
        if (strcmp(key, p->data.name) == 0 || strcmp(key, p->data.subject1.name) == 0 || strcmp(key, p->data.subject2.name) == 0) //分别与教师姓名，两个课程的名称匹配
        {
            ListPrint(p->data); //打印匹配的记录
            flag = 1;
        }
        p = p->next;
    }
    if (!flag)
        printf("NO match!\n");
}

/** 排序功能 0按照教职工号排序， 1按照教学效果综合评分排序*/
void ListSort(pList list, int way)
{
    if (way != 0 && way != 1)
    {
        return;
    }

    Element temp;
    pInfo p;
    int counti, countj; //内层向后遍历到第 list->len - count个
    for (counti = 0; counti < list->len; counti++)
    {
        p = list->next;
        for (countj = 0; p->next && countj < list->len - counti - 1; countj++)
        {
            if ((way == 0 && strcmp(p->data.num, p->next->data.num) < 0) || (way == 1 && p->data.score < p->next->data.score))
            {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
    }
}

/** 插入功能 */
void ListInsert(pList list, Element data)
{
    if (list == NULL)
    {
        return;
    }
    pInfo temp = (pInfo)malloc(sizeof(Info));

    temp->data = data;
    temp->next = list->next;
    list->next = temp;

    list->len++;
}

/** 修改功能 */
void ListChange(pList list, char *num, Element data)
{
    pInfo p = list->next;
    while (p)
    {
        if (strcmp(num, p->data.num) == 0)
        {
            p->data = data;
            return;
        }
        p = p->next;
    }
}

/** 删除功能 */
void ListDelete(pList list, char *name)
{
    if (list == NULL)
    {
        return;
    }
    pInfo p = list->next;
    pInfo q = NULL; //指向要删除结点的下一结点
    while (p)
    {
        if (strcmp(name, p->data.name) == 0)
        {
            if (q == NULL)
            {
                list->next = p->next;
                free(p);
                p = NULL;
                list->len--;
                return;
            }
            else
            {
                q->next = p->next;
                free(p);
                p = NULL;
                list->len--;
                return;
            }
        }
        q = p;
        p = p->next;
    }
}

/** 销毁一条链 */
void ListDestroy(pList list)
{
    pInfo p = list->next;
    pInfo q;
    free(list);
    list = NULL;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
        q = NULL;
    }
}

/** 输入一条记录 */
void ListInputSingle(Element *data)
{
    //11个字符串，1个整形
    scanf("%s %s %s %s %s %s %s %s %s %s %s %s %d",
          data->num, data->name, data->title, data->sex,
          data->subject1.name, data->subject1.openTime, data->subject1.attribute, data->subject1.discrip,
          data->subject2.name, data->subject2.openTime, data->subject2.attribute, data->subject2.discrip, &data->score);
}

/** 显示一条记录的信息 */
void ListPrint(Element data)
{
    printf("%s %s %s %s %s %s %s %s %s %s %s %s %d\n",
           data.num, data.name, data.title, data.sex,
           data.subject1.name, data.subject1.openTime, data.subject1.attribute, data.subject1.discrip,
           data.subject2.name, data.subject2.openTime, data.subject2.attribute, data.subject2.discrip, data.score);
}
