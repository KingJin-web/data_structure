#include<stdio.h>
#include"Sequencelist.cpp"


ElementType dataArray[] = {
    {1, (char*)"1"},
    {2, (char*)"2"},
    {3, (char*)"3"},
    {4, (char*)"4"},
    {5, (char*)"蔡徐坤"},
};

void TestSeqentList(){
    SeqList seqList;    //要操作的顺序表
    ElementType *delElement;
    InitList(&seqList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    printf("初始化后\n");
    PrintList(&seqList);

}


int main(){
    TestSeqentList();
    //PrintList(dataArray);
    return 0;
}