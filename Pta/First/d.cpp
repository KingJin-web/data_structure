#include <iostream>
#define OK 1
#define ERROR 0
typedef int ElemType;
using namespace std;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void CreateList(LinkList &L, int n)
{
    LinkList p;
    int length = 1;
    L = new LNode;
    cin >> L->data;
    L->next = NULL;
    while (length < n)
    {
        p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
        length++;
    }
}

int Sum(LinkList L);

int main()
{
    LinkList L;
    ElemType e;
    int length;
    cin >> length;
    CreateList(L, length);
    int x = Sum(L);
    cout << x;
    return 0;
}

/* 请在这里填写答案 */



int Sum(LinkList L)
{
    // while (L)
    // {
    //     cout<<L->data;
    //     L = L->next;
    // }
    
    if (L == NULL)
        return 0;
    else{
        // count += L->data;
        // L = L->next;
        return L->data + Sum(L->next);
    }
}
