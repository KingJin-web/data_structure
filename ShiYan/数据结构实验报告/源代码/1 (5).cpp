// 实验五  哈夫曼编码
// 1.实验目的
// 1、掌握哈夫曼编码原理；
// 2、熟练掌握哈夫曼树的生成方法；
// 3、掌握树形结构在实际问题中的应用
// 2.实验内容
// 1)对明文数据进行哈夫曼编码
// 2)对密文数据进行哈夫曼译码
//  要求实现功能：
//   统计字符出现频率
//   建树
//   建立编码表
//   编码
//   译码
//   编码长度分析 

/*
	1、对明文数据进行哈夫曼编码
	2、对密文数据进行哈夫曼译码
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char info;
	int weight;//权重
	int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef char**HuffmanCode;

HuffmanTree HT;
HuffmanCode HC;
int n = 8;

void Select(HuffmanTree HT, int t, int *s1, int *s2) {
	int i, temp1, temp2;
	temp1 = temp2 = 1000;

	for (i = 1; i <= t; i++) {
		if (HT[i].parent == 0 && (HT[i].weight < temp1 || HT[i].weight < temp2)) {
			if (temp1 < temp2) {
				temp2 = HT[i].weight;
				*s1 = i;
			} else {
				temp1 = HT[i].weight;
				*s2 = i;
			}
		}
	}
	//s1 放较小的序号
	if (*s1 > *s2) {
		i = *s1;
		*s1 = *s2;
		*s2 = i;
	}
}

HuffmanTree HuffmanCoding(int *w, int n, char *info) {
	// n 为字符串个数
	HuffmanTree HT, p;
	char *cd;
	int m, s1, s2, i, start, f, c;

	if (n <= 1) {
		return 0;
	}
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
	p = HT + 1;

	for (i = 1; i <= n; ++i, ++p, ++w) {
		p->weight = *w;
		p->info = info[i-1];
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for (; i <= m; ++i, ++p) {
		p->weight = 0;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for (i = n+1; i <= m; ++i) {
		// 在 HT 中选择 parent 为 0 且 weight 最小的两个结点，其序号分别为 s1, s2
		Select(HT, i-1, &s1, &s2);

		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

	//逆向求哈夫曼编码
	HC = (HuffmanCode)malloc((n+1)*sizeof(char *));
	cd = (char *)malloc(n*sizeof(char));
	cd[n-1] = '\0';

	for (i = 1; i <= n; ++i) {
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) {
			if (HT[f].lchild == c) {
				cd[--start] = '0';
			} else {
				cd[--start] = '1';
			}
		}
		HC[i] = (char *)malloc((n-start)*sizeof(char));
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
	return HT;
}

//1、对明文数据进行哈夫曼编码
void TextToCode() {
	char str[50];
	int i, j, p;

	if (HT == NULL) {
		printf("请先进行初始化！\n");
		return ;
	}

	printf("请输入文本：\n");
	getchar();
	gets(str);
	printf("编码结果如下：\n");
	p = strlen(str);
	for (i = 1; i <= p; i++) {
		for (j = 1; j <= n; j++) {
			if (str[i-1] == HT[j].info) {
				printf("%s", HC[j]);
				break;
			}
		}
	}
	printf("\n");
}

//2、对密文数据进行哈夫曼译码
void CodeToText() {
	int i = 1, j, key;
	int i1, i2;
	char str[100];
	int a = 1;
	int m = 2 * n - 1;

	if (HT == NULL) {
		printf("请先进行初始化！\n");
		return ;
	}

	printf("\n请输入哈夫曼编码：\n");
	scanf("%s", str);
	j = strlen(str);
	key = m;
	printf("哈夫曼编码译码如下：\n");
	while (i <= j) {
		while (HT[key].lchild != 0) {
			if (str[i-1] == '0') {
				key = HT[key].lchild;
				i++;
				continue;
			}
			if (str[i-1] == '1') {
				key = HT[key].rchild;
				i++;
				continue;
			}
		}
		printf("%c", HT[key].info);
		key = m;
	}
	printf("\n");
}

int main() {
	int i, j = 1;
	int wei[8] = {5, 25, 7, 8, 14, 20, 3, 11};
	char info[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	HT = HuffmanCoding(wei, n, info);
	TextToCode();
	CodeToText();

	return 0;
}


  
