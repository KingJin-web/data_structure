#include <stdio.h>
#include <iostream>
using namespace std;
struct xs
{
    int num;
    float scoe;
    struct xs *next;
};
// int main(void)
// {
//     struct xs *head;
//     struct xs *p1, *p2;
//     struct xs *p;
//     int n = 0;
//     p2 = p1 = new xs();
//     printf("请输入学号及分数：\n");
//     scanf("%d%f", &p1->num, &p1->scoe);
//     head = NULL;
//     while (p1->num)
//     {
//         n++;
//         if (n == 1)
//         {
//             head = p1;
//         }
//         else
//         {
//             p2->next = p1;
//         }
//         p2 = p1;
//         p1 = new xs();
//         scanf("%d%f", &p1->num, &p1->scoe);
//     }
//     n = 0;
//     p = head;
//     if (head)
//     {
//         while (p->next)
//         {
//             printf("第%d个同学学号：%d 分数：%f\n", n + 1, p->num, p->scoe);
//             p = p->next;
//         }
//     }
// }
// int main(int argc, char const *argv[])
// {
//     string *str_heart = new string;
//     *str_heart = "abcd";
//     cout << *str_heart << endl;

//     //delete str_heart;
//     free(str_heart);
//     cout << "a" << *str_heart << "b" << endl;
//     return 0;
// }
