/*实验六　图的遍历操作
1.实验目的：
掌握有向图和无向图的概念；
掌握邻接矩阵和邻接链表建立图的存储结构；
掌握DFS及BFS对图的遍历操作；
2.实验内容
设计一个有向图和一个无向图，任选一种存储结构，
完成有向图和无向图的DFS（深度优先遍历）和BFS（广度优先遍历）的操作。
3.附加内容：
1）最小生成树算法prime      更新
2) 最小生成树算法kruscal    更新
3) 实现dijkstra最短路径算法 更新  dist[0,3] <  dist[0,2] + adj[2][3]
4) floyd算法               更新
4.实验探讨：
1)、邻接矩阵表示图时的特点；
2)、用邻接链表表示图时的特点；
3)、深度优先遍历和广度优先遍历算法与二叉树的遍历算法有没有相似性*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define _INT_MAX_  10

#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const char *vex="ABCDEFGH";
int n=8;


typedef struct Edge
{
    int form;
    int to;
    int cost;
    bool isSelected;
}Edge;

bool compare(Edge &e1,Edge &e2)
{
    return e1.cost<e2.cost;
}






//邻接矩阵
int adj[8][8]={0,1,0,0,1,0,0,0,
               1,0,0,0,1,1,0,0,
               0,0,0,1,0,1,0,0,
               0,0,1,0,0,1,0,0,
               1,1,0,0,0,0,0,0,
               0,1,1,1,0,0,0,0,
               0,0,0,0,0,0,0,1,
               0,0,0,0,0,0,1,0};
bool isVisited[8]={false};

int getAdj(int v,int w=0)//FIRST,NEXT 相对
{
    for(int i=w+1;i<n;i++)
        if(adj[v][i==1])
            return i;
    return -1;
}

void Kruskal()
{
    //提取边
    Edge edges[1000];
    int edgescount=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(adj[i][j]==_INT_MAX_)
                continue;
            edges[edgescount].form=i;
            edges[edgescount].to=j;
            edges[edgescount].cost=adj[i][j];
            edgescount++;

        }
        sort(edges,edges+edgescount,compare);
        int costsum=0;
        int ids[7];
        for(int i=0;i<n;i++)
        {
            ids[i]=i;
        }
        edges[0].isSelected=true;
        ids[edges[0].to]=ids[edges[0].form];//联通
        costsum+=edges[0].cost;

        cout<<edges[0].form<<"--"<<edges[0].to<<":"<<edges[0].cost<<endl;

        for(int k=1;k<edgescount;k++)
        {
            if(ids[edges[k].to]==ids[edges[k].form])//判断是否联通
                continue;
            edges[k].isSelected=true;
            cout<<edges[k].form<<"--"<<edges[k].to<<":"<<edges[k].cost<<endl;
            costsum+=edges[k].cost;
            //更新ids
            int temp=ids[edges[k].to];
            for(int i=0;i<n;i++)
            {
                if(ids[i]==temp)
                    ids[i]=ids[edges[k].form];
            }
        }
        cout<<costsum<<endl;

    }

}



void getRoute(int v,int w,int *route,int len)
{
    route[len]=v;
    //isVisited[v]=true;
    if(v==w)
    {
        for(int i=0;i<len+1;i++)
            cout<<vex[route[i]]<<"-->";
        cout<<endl;
        return;
    }
    for(int i=getAdj(v,0);i!=-1;i=getAdj(v,i))
    {
        bool isexisted=false;
        for(int j=0;j<len;j++)
            if(i==route[j])
                isexisted=true;

        if(!isexisted)
        {
            getRoute(i,w,route,len+1);
        }
    }
}
//DFS（深度优先遍历）
void dfs(int v)//连通图		n^2
{
    cout<<vex[v]<<" ";
    isVisited[v]=true;
    for(int i=getAdj(v,0);i!=-1;i=getAdj(v,i))
    {
        if(!isVisited[i])
        {
            cout<<v<<"-->"<<i<<endl;
            dfs(i);
        }
    }
}

void dfs_all()
{
    for(int i=0;i<n;i++)
    {
        if(!isVisited[i])
        {
            cout<<"dfs connect component:";
            dfs(i);
            cout<<endl;
        }
    }
}
//BFS（广度优先遍历）
void bfs(int v)
{
    queue<int> que;
    que.push(v);
    isVisited[v]=true;

    while(!que.empty())
    {
        int ext=que.front();
        que.pop();
        cout<<vex[ext]<<" ";
        for(int i=getAdj(ext,0);i!=-1;i=getAdj(ext,i))
        {
            if(!isVisited[i])
            {
                que.push(i);
                isVisited[i]=true;
            }
        }
    }
}




void dijstra()
{
    int dist[6]={0};
    int isSelected[6]={false};
    isSelected[0]=true;

    for(int i=1;i<n;i++)
        dist[i]=adj[0][i];
    for(int k=1;k<n;k++)
    {
        int mindist=_INT_MAX_;
        int mini=0;
        for(int i=0;i<n;i++)

            if(!isSelected[i]&&dist[i]<mindist)
            {
                mindist=dist[i];
                mini=i;
            }
        isSelected[mini]=true;
        for(int i=0;i<n;i++)
        {
            if(!isSelected[i])
            {
                if(dist[mini]+adj[mini][i]<dist[i])
                    dist[i]=dist[mini]+adj[mini][i];
            }
        }
    }
}



void floyd()
{
    int d[5][5];
    for(int k=0;k<n;k++)
    {
        //以k为中间
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(d[i][j]>d[i][k]<d[k][j])
                    d[i][j]=d[i][k]+d[k][j];
            }
    }
}




void primel()
{
    bool isSelect[7]={false};//区分到底有没有选中
    isSelect[6]=true;
    int costsum=0;
    for(int k=1;k<n;k++)//要选择多少条边	n-1		o(n)
    {
        int minedgecost=_INT_MAX_;
        int mini=0;
        int minj=0;
        for(int i=0;i<n;i++)//从已经选中的点里面换一个		o(n)
        {
            if(!isSelect[i])
                continue;
            for(int j=0;j<n;j++)//从未选中的点里面换一个		o(n)
            {
                if(isSelect[j])
                    continue;
                if(adj[i][j]<minedgecost)
                {
                    minedgecost=adj[i][j];
                    mini=i;
                    minj=j;
                }
            }
        }
        cout<<mini<<"---"<<minj<<":"<<minedgecost<<endl;
        isSelect[minj]=true;
        costsum+=minedgecost;
    }
    cout<<costsum<<endl;
}


int main()
{
    Kruskal();
    int	v=2;
    getAdj(v,0);
    int w=2;
    int *route;
    int len=1;

    dfs(v);
    dfs_all();
    bfs(v);
    //getRoute(v,w,route,len);
    primel();
    dijstra();
    floyd();



    return 0;
}

