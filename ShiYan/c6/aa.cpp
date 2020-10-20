# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>

typedef struct statu{
	int weight;
	int p,l,r;
}JD;

void zuixao(JD *L, int n,int *s1, int *s2);
void chushi(JD *L,int n);
void bianli(JD *L,int n);

int main(void)
{
	int n;
	JD L;

	printf("请输入您要创建的节点的个数!\n");
	scanf("%d", &n);

	chushi(&L,n);
	bianli(&L,n);


	return 0;
}

void chushi(JD *L,int n)
{
    int s1,s2;

	if(n<=0)
	{
		printf("输入节点的个数有错误!\n");
		exit(-1);
	}

	L = (JD*)malloc(2*n*sizeof(JD));
	for(int j=0;j<2*n;j++)
	{
		L[j].l = 0;
		L[j].p = 0;
		L[j].r = 0;
		L[j].weight = 0;
	}

	for(int i=1;i<n+1;i++)
	{
		printf("请输入第%d个节点的权值！ ", i);
		scanf("%d", &L[i].weight);
	}

	for(int i=n+1;i<2*n;i++)
	{
		zuixao(L,i-1,&s1,&s2);

		L[i].weight = L[s1].weight + L[s2].weight;
		L[s1].p = i;
		L[s2].p = i;
		L[i].l = s1;
		L[i].r = s2;
	}
	printf("创造完成！\n");
}

void zuixao(JD *L, int n,int *s1, int *s2)
{
	int min1=10000,min2=10000;

	for(int i=1;i<=n;i++)
	{
		if(L[i].p == 0&&L[i].weight < min1)
		{
		    min1 = L[i].weight;
			*s2 = i;
		}

	}
	for(int i=1;i<=n;i++)
	{
		if(i!=(*s1)&&L[i].p == 0)
		{
			if(L[i].weight < min1)
			{
				min2 = L[i].weight;
				*s2 = i;
			}
		}

	}


}

void bianli(JD *L,int n)
{
	printf("输出哈夫曼树表格！\n");
	printf("节点  weight  p  l  r  \n");

	for(int i=1;i<2*n;i++)
	{
		printf("%d  %d  %d  %d  %d\n", i, L[i].weight, L[i].p, L[i].l, L[i].r);
	}

}
