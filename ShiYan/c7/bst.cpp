
#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct BiNode
{ // 结点结构
    ElemType data;

    struct BiNode *lchild; //left child       8
    struct BiNode *rchild; // right child     8
    // 左右孩子指针
} BiNode; //binary tree node

//深度 statck  广度 queque

typedef BiNode *BiTree;

int searchCount = 0;
bool SearchBST(BiTree &t, ElemType key, BiTree &f, BiTree &p)
{
    searchCount++;

    if (t == 0) //NULL  0
    {
        p = f;
        return false;
    }
    if (t->data == key)
    {
        p = t;
        return true;
    }
    if (key < t->data)
    {
        return SearchBST(t->lchild, key, t, p);
    }
    if (key > t->data)
    {
        return SearchBST(t->rchild, key, t, p);
    }
}

bool InsertBST(BiTree &T, ElemType e)
{
    // 当二叉排序树中不存在关键字等于 e.key 的
    // 数据元素时，插入元素值为 e 的结点，并返
    // 回 TRUE; 否则，不进行插入并返回FALSE
    BiNode *p = NULL;

    BiNode *tempNode = NULL;

    if (!SearchBST(T, e, tempNode, p)) //p=应该插入位置
    {
        BiNode *newnode = new BiNode();
        newnode->data = e;
        newnode->lchild = NULL;
        newnode->rchild = NULL;

        if (p == NULL)
        {
            T = newnode;
            return true;
        }
        if (e < p->data) //p==NULL
            p->lchild = newnode;

        if (e > p->data)
            p->rchild = newnode;

        return true;
    }

    return false;
} // Insert BST

BiNode *findMaxInLeftChildTree(BiTree &t, BiTree &parentofMaxNode)
{
    if (t == NULL)
        return NULL;
    if (t->rchild != NULL)
    {
        parentofMaxNode = t; //???????????????
        return findMaxInLeftChildTree(t->rchild, parentofMaxNode);
    }
    if (t->rchild == NULL)
    {
        return t;
    }
}

void deleteNode(BiNode *p, BiNode *parent)
{
    if (p->lchild == NULL)
    {
        if (parent->lchild == p)
            parent->lchild = p->rchild;

        if (parent->rchild == p)
            parent->rchild = p->rchild;
        delete p;
        return;
    }

    if (p->rchild == NULL)
    {
        if (parent->lchild == p)
            parent->lchild = p->lchild;

        if (parent->rchild == p)
            parent->rchild = p->lchild;
        delete (p);
        return;
    }
    BiNode *parentofMaxNode = NULL;
    parentofMaxNode = p;
    BiNode *maxInLeftChildTree = findMaxInLeftChildTree(p->lchild, parentofMaxNode);
    cout << "Test findMaxInLeftChildTree" << endl;
    cout << maxInLeftChildTree->data << endl;
    cout << parentofMaxNode->data << endl;

    p->data = maxInLeftChildTree->data;
    deleteNode(maxInLeftChildTree, parentofMaxNode);
}
bool deleteBst(BiTree &T, ElemType e, BiTree &parent)
{
    BiNode *p = NULL;
    if (T->data == e)
        deleteNode(T, parent);
    else if (e < T->data)
        deleteBst(T->lchild, e, T);
    else if (e > T->data)
        deleteBst(T->rchild, e, T);
}
void inOrderTraverse(BiTree &tree) // 分子问题
{
    if (tree == NULL)
        return;
    inOrderTraverse(tree->lchild);
    cout << tree->data << " ";
    inOrderTraverse(tree->rchild);
}
void preOrderTraverse(BiTree &tree) //时间复杂度  O(n) n是节点数
                                    //空间复杂度   O(logn)
{
    if (tree == NULL)
        return;
    cout << tree->data << " ";
    preOrderTraverse(tree->lchild);
    preOrderTraverse(tree->rchild);
}

int main()
{
    BiTree t = NULL; //排序树
    int a[] = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    for (int i = 0; i < sizeof(a) / 4; i++)
        InsertBST(t, a[i]);
    preOrderTraverse(t);
    cout << endl;
    inOrderTraverse(t);
    BiTree temp = NULL;
    BiTree p = NULL;
    searchCount = 0;
    if (SearchBST(t, 6, temp, p))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    cout << searchCount << endl;
    BiTree temp1 = NULL;
    deleteBst(t, 8, temp1);
    cout << "1111" << endl;
    if (SearchBST(t, 8, temp, p))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    preOrderTraverse(t);
    cout << endl;
    inOrderTraverse(t);
}