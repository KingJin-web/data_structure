

/*实验四  二叉树的操作

一、目的：
1、熟悉二叉树的结点类型和二叉树的基本操作。
2、掌握二叉树常用操作的算法。
3、加深对二叉树的理解，逐步培养解决实际问题的编程能力

四、实验内容
采用二叉树链表作为存储结构，完成二叉树的基本操作如下，
0.建树
1.叶子点总数
2.节点总数
3.二叉树镜像
4.先序遍历
5.层次遍历
6.二叉树复制
7.二叉树深度



五、附加内容
1.求二叉树中第k层节点的个数
2.判断二叉树是否是完全二叉树-- queue 层次标记 记数     1 2 4 8 15 8
3.两个二叉树是否完全相同  1.求二叉树中第k层节点的个数
4.非递归中序遍历
5.根据先序和中序序列建立一个二叉树
6. 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
   路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
*/

#include <iostream>
#include <string.h>
#include <queue>
#include <cmath>
using namespace std;

typedef char TElemType;

typedef struct BiTNode
{ // 结点结构
    TElemType data;

    struct BiTNode *lchild; //left child       8
    struct BiTNode *rchild; // right child     8
                            // 左右孩子指针
} BiTNode;                  //binary tree node

//深度 statck  广度 queque

typedef BiTNode *BiTree;

void preOrderTraverse(BiTree &tree) //时间复杂度  O(n) n是节点数
                                    //空间复杂度   O(logn)
{
    if (tree == NULL)
        return;
    cout << tree->data << " ";
    preOrderTraverse(tree->lchild);
    preOrderTraverse(tree->rchild);
}

void inOrderTraverse(BiTree &tree) // 分子问题
{
    if (tree == NULL)
        return;
    inOrderTraverse(tree->lchild);
    cout << tree->data << " ";
    inOrderTraverse(tree->rchild);
}

void postOrderTraverse(BiTree &tree)
{
    if (tree == NULL)
        return;
    postOrderTraverse(tree->lchild);
    postOrderTraverse(tree->rchild);
    cout << tree->data << " ";
}

//AB#C##D##
/*

inOrderTraverse:B C A D
postOrderTraverse:C B D A
先根 中根 可以唯一确定
先跟 后跟  能不能唯一确定？不能确定
中跟  后跟  可以唯一确定
*/
BiTree createBiTree(const char *str, int &startindex)
{
    if (startindex >= strlen(str))
        return NULL;
    if (str[startindex] == '#')
    {
        startindex++;
        return NULL;
    }

    BiTNode *root = new BiTNode();
    root->data = str[startindex];
    startindex++;
    root->lchild = createBiTree(str, startindex);
    root->rchild = createBiTree(str, startindex);

    return root;
}

//统计二叉树中叶子结点的个数

int getLeafNodeCount(BiTree tree) //把子树作为一个整体
{
    if (tree == NULL)
        return 0;

    if (tree->lchild == NULL && tree->rchild == NULL)
    {
        // cout << tree->data << endl;
        return 1;
    }
    else
        return getLeafNodeCount(tree->lchild) + getLeafNodeCount(tree->rchild);
}

//求二叉树的深度
int getTreeDepth(BiTree tree)
{
    if (tree == NULL)
        return 0;
    return max(getTreeDepth(tree->lchild), getTreeDepth(tree->rchild)) + 1;
}

//复制二叉树
BiTree copyTree(BiTree tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    BiTNode *rootNode = new BiTNode();
    rootNode->data = tree->data;
    rootNode->lchild = copyTree(tree->lchild);
    rootNode->rchild = copyTree(tree->rchild);
    return rootNode;
}
// 二叉树镜像
BiTree mirrorTree(BiTree tree) //递归
{
    if (tree == NULL)
    {
        return NULL;
    }

    BiTNode *temp = mirrorTree(tree->lchild);
    tree->lchild = mirrorTree(tree->rchild);
    tree->rchild = temp;
    return tree;
}

void traversByLevel(BiTree tree)
{
    queue<BiTNode *> que; //queue用法
    que.push(tree);
    while (!que.empty())
    {
        BiTNode *ext = que.front();
        que.pop();

        cout << ext->data;

        if (ext->lchild != NULL)
            que.push(ext->lchild);

        if (ext->rchild != NULL)
            que.push(ext->rchild);
    }
}
//判断二叉树是否是完全二叉树-- queue 层次标记 记数     1 2 4 8 15 8
bool isCompleteTree(BiTree &tree)
{

    int count[100] = {0}; // count[1]
    queue<BiTNode *> que;

    que.push(tree);
    que.push(NULL); //同层的标记
    int sameLevelCount = 0;
    int levelId = 1;

    while (!que.empty())
    {
        BiTNode *ext = que.front();
        que.pop();
        if (ext != NULL)
        {
            sameLevelCount += 1;
            if (ext->lchild != NULL)
            {
                que.push(ext->lchild);
                if (ext->rchild != NULL)
                    que.push(ext->rchild);
            }
            if (ext->lchild == NULL && ext->rchild != NULL)
                return false; //"AB#E##C##"
        }
        else
        {
            if (que.size() >= 1)
                que.push(NULL); //同层结束的标记
            count[levelId] = sameLevelCount;
            sameLevelCount = 0;
            levelId++;
        }
    }

    //cout << count[k] << endl;

    for (int i = 1; i < levelId; i++) //第i層
    {
        if (count[i + 1] != 0 && count[i] != pow(2, i - 1))
            return false;
    }
    return true;
}

//3.两个二叉树是否完全相同  //数据是否相同
bool isSameTree(BiTree &t1, BiTree &t2)
{
    //根节点
    if (t1 == NULL && t2 != NULL)
        return false;
    if (t2 == NULL && t1 != NULL)
        return false;
    if (t1 == NULL && t2 == NULL)
    {
        return true;
    }
    if (t1->data == t2->data)
    {
        return isSameTree(t1->lchild, t2->lchild) && isSameTree(t1->rchild, t2->rchild);
    }
    else
        return false;
    //左子树
    //右子树
}
/*
	 1
	/  \
   2    3
  / \   / \
4    5  6  7

*/
//1.求二叉树中第k层节点的个数  k= 1
int getKLevelNodes(BiTree tree, int k)
{
    if (tree == NULL)
        return 0;
    if (k == 1)
    {
        return 1;
    }
    int t1 = getKLevelNodes(tree->lchild, k - 1);
    int t2 = getKLevelNodes(tree->rchild, k - 1);

    return t1 + t2;
}
//根据先序和中序序列建立一个二叉树

int findPos(const char *str, int left, int right, char a)
{
    if (left > right)
        return -1;
    for (int i = left; i <= right; i++)
        if (str[i] == a)
            return i;
    return -1;
}
//P abcdefg
//M cbdaegf
BiTree buildTree(const char *strP, int leftP, int rightP,
                 const char *strM, int leftM, int rightM)
{                       //  a
    if (leftM > rightM) //ab   ba   //  /
        return NULL;    //   b
    BiTNode *root = new BiTNode();
    root->data = strP[leftP];

    int rootInMPos = findPos(strM, leftM, rightM, strP[leftP]);
    int preorderLeftEndPos = leftP;
    for (int i = leftP; i <= rightP; i++)
    {
        if (findPos(strM, leftM, rootInMPos - 1, strP[i]) != -1)
            preorderLeftEndPos = i;
        else
        {
            break;
        }
    }
    root->lchild = buildTree(strP, leftP + 1, preorderLeftEndPos, strM, leftM, rootInMPos - 1);
    root->rchild = buildTree(strP, preorderLeftEndPos + 1, rightP, strM, rootInMPos + 1, rightM);

    return root;
}

int main()
{

    const char *str11 = "abc";
    const char *str22 = "bac";
    BiTree tree00 = buildTree(str11, 0, strlen(str11) - 1, str22, 0, strlen(str22) - 1);
    preOrderTraverse(tree00);
    cout << endl;
    inOrderTraverse(tree00);
    cout << endl;

    const char *str = "AB#E##C##"; //"AB#C##D##";
    int startindex = 0;
    // BiTree tree = NULL;
    BiTree tree0 = createBiTree(str, startindex);

    const char *str1 = "ABE###C##"; //"AB#C##D##";
                                    //       A
                                    //     B   C
                                    //   E
    startindex = 0;

    BiTree tree1 = createBiTree(str1, startindex);

    if (isSameTree(tree0, tree1))
    {
        cout << "same tree";
    }
    else
    {
        cout << "no same";
    }

    cout << "\n k level nodes:" << getKLevelNodes(tree0, 3) << endl;
    //return 1;
    if (isCompleteTree(tree0))
    {
        cout << "isCompleteTree";
    }
    else
    {
        cout << "is not CompleteTree";
    }

    // BiTree tree = copyTree(tree0);
    // tree = mirrorTree(tree);
    // cout << tree0 << endl;
    // cout << tree << endl;
    // cout << "preOrderTraverse:";
    // preOrderTraverse(tree);
    // cout << endl;

    // cout << "inOrderTraverse:";
    // inOrderTraverse(tree);
    // cout << endl;

    // cout << "postOrderTraverse:";
    // postOrderTraverse(tree);
    // cout << endl;

    // cout << "getLeafNodeCount=" << getLeafNodeCount(tree) << endl;
    // cout << "getTreeDepth=" << getTreeDepth(tree) << endl;
    return 0;
}