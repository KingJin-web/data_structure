#ifndef DATAELEMENT_H_INCLUDED
#define DATAELEMENT_H_INCLUDED

#include <bits/stdc++.h>

#include"DataElement.h"
using namespace std;
/**
 * 初始化顺序表
 * @param seqList   要初始化的顺序表
 * @param elemArary 初始化时要添加的元素内容数组
 * @param length    初始化时添加的元素个数
 */
void InitList(SeqList * seqlist, ElementType * elemArry,int length);
/**
 * 向顺序表中的index下标处插入某个元素
 * @param seqList
 * @param index     要插入的下标
 * @param element   要插入的元素
 */
void InsertElement(SeqList * seqlist,int index,ElementType element);

void PrintList(SeqList * seqList);
void TestSeqentList();


#endif