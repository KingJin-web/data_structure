# 算法设计与分析第二次作业动态规划

## [6-1 Programming Contest (30 分)](a.cpp)

Bob will participate in a programming contest. There are altogether `n` problems in the contest. Unlike in PAT (Programming Ability Test), in a programming contest one can not obtain partial scores. For problem `i`, Bob will need `time[i]` to solve it and obtains the corresponding `score[i]`, or he may choose not to solve it at all. Bob will be happy when he obtains a total score no less than `happy_score`. You are supposed to find the minimum time needed for Bob to be happy. The function `need_time` must return the minimum time, or `-1` if it is impossible for Bob to obtain a score no less than `happy_score`.

### Format of function:

```cpp
int need_time(const int time[], const int score[], int happy_score, int n);

```

Here `n` (**1**≤**`n`**≤ `MAXN`) is the number of problems; `happy_score` (**1**≤`happy_score` **≤** `MAXS`) is the minimum score for Bob to be happy; `time[]` is the array to store `time[i]` (**1****≤**`time[i]`**≤****1****0****0**) which is the time to solve problem `i`; `score[]` is the array to store `score[i]` (**1****≤**`score[i]`**≤****1****0****0**) which is the score Bob gets for solving problem `i`.


### Sample program of judge:

```cpp
#include <stdio.h>

#define MAXN 10
#define MAXS 1000

int need_time(const int time[], const int score[], int happy_score, int n);

int main() {
  int n, i, happy_score;
  int time[MAXN], score[MAXN];
  scanf("%d %d", &n, &happy_score);
  for (i = 0; i < n; ++i)
      scanf("%d", &time[i]);
  for (i = 0; i < n; ++i)
      scanf("%d", &score[i]);
  printf("%d\n", need_time(time, score, happy_score, n));
  return 0;
}

/* Your function will be put here */

```

### Sample Input:

```cpp
6 121

84 87 78 16 94 38
87 93 50 22 63 28
```


### Sample Output:

```cpp
125
```


## [6-2 求解拆分集合为相等的子集合问题（动态规划法） (30 分)](b.cpp)

求解拆分集合为相等的子集合问题。将1～n的连续整数组成的集合划分为两个子集合，且保证每个集合的数字和相等。例如：对于n=4，对应的集合{1,2,3,4}能被划分为{1,4}、{2,3}两个集合，使得1＋4＝2＋3，且划分方案只有这一种。


### 函数接口定义：

```cpp
int split(int n);
```

### 裁判测试程序样例：

```cpp
#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXN 20

using namespace std;
int dp[MAXN*MAXN/2][MAXN*MAXN/2];
int split(int n);
int main()
{
    int n;
    cin>>n;
    cout<<split(n);
    return 0;
}

/* 请在这里填写答案 */
```


### 输入格式:

输入正整数n（测试数据已确保{1,2,3,…,n}的和是2的倍数。）

```cpp
3
```


### 输出格式:

输出拆分方案数。（可划分方案{1,2}、{3}）

```cpp
1 
```


## [7-1 最长公共子序列 (10 分)](c.cpp)


给定两个长度分别为N和M的字符串A和B，求既是A的子序列又是B的子序列的字符串长度最长是多少。

### 输入格式:

第一行包含两个整数N和M。1≤N,M≤1000

第二行包含一个长度为N的字符串，表示字符串A。

第三行包含一个长度为M的字符串，表示字符串B。

字符串均由小写字母构成。

### 输出格式:

输出一个整数，表示最大长度。

### 输入样例:

```
4 5
acbd
abcbd
```

### 输出样例:

```out
4
```
