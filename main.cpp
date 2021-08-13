#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

// void printfArr(int arr[])
// {
//     int length = sizeof(arr) / sizeof(int);
//     printf("[");
//     for (int i = 0; i < length - 1; ++i)
//     {
//         printf("%d,", arr[i]);
//     }
//     printf("%d]\n", arr[length - 1]);
// }
// int main()
// {
//     char ch ;
//     scanf("%c", &ch);
//     if (ch >= 'A' && ch <= 'Z')
//     {
//         ch = ch + 32;
//     }
//     else if (ch >= 'a' && ch <= 'z')
//     {
//         ch = ch - 32;
//     }

//     printf("%c\n", ch);
//     return 0;
// }

// int main()
// {
//     int y, m, d;
//     scanf("%d/%d/%d", &y, &m, &d);
//     printf("%d--%d--%d\n", y, m, d);
//     system("pause");
// }

// 在任意一个四位整数中，如果该数的个位数和百位数之和大于16，并且十位数和千位数之和小于3，就称这种数为“老九幸运数“，
// 请小伙伴编程计算出在1000~9999中，一共有多少个满足老九幸运数的四位整数呢，打印出最终的个数

// int main()
// {
//     int a, b, c, d, co = 0;
//     for (int i = 1000; i <= 9999; i++)
//     {

//         a = i % 10;
//         b = i / 10 % 10;
//         c = i / 100 % 10;
//         d = i / 1000;
//         if (a + c > 16 && b + d < 3)
//         {
//             cout<<i<<endl;
//             co ++;
//         }
//     }
//     cout<<"一共有 "<<co<<" 个"<<endl;
// }

// int main()
// {
//     int num = 1234;
//     int a, b, c, d;

//     a = num % 10;
//     c = num / 100 % 10;
//     b = num / 10 % 10;
//     d = num / 1000;
//     cout << a << b << c << d << endl;
// }

// #define N 5 //宏定义 ，并不是必须的  好处是功能方便
// int main()
// {
//     int nums[N] = {16, 25, 9, 90, 23};
//     int i, j;
//     int temp;
//     // 先确定外层循环
//     for (i = 0; i < N - 1; i++)
//     {
//         for (j = 0; j < N - i - 1; j++)
//         {
//             if (nums[j] < nums[j + 1])
//             {
//                 temp = nums[j];
//                 nums[j] = nums[j + 1];
//                 nums[j + 1] = temp;
//             }
//         }
//     }
//     printf("排序后的数组是：\n");
//     for (i = 0; i < N; i++)
//     {
//         printf("%d\t", nums[i]);
//     }
// }

// int main()
// {
//     int a,b,c;
//     a = 72, b = 73, c = 74;
//     printf("%f%f%f\n", a, b, c);
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     char a, as, bs, cs, ds;
//     int n;
//     for (a = 'A'; a <= 'D'; a++)
//     {
//         as = (a != 'A');
//         bs = (a == 'C');
//         cs = (a == 'D');
//         ds = (a != 'D');
//         n = as + bs + ds + cs;
//         if (n == 3)
//             printf(" %c\n", a);
//     }

//     return 0;
// }

// int main()
// {
//     int a, b, c, a1, b1, sum, count = 10, Ming = 0;

//     scanf("%d %d", &a, &b);

//     c = a + b;

//     while (a > 0 && b > 0)
//     {
//         a1 = a % 10;
//         b1 = b % 10;
//         if ((a1 + b1) >= 10)
//             Ming = Ming + 1 * count;
//         count = count * 10;
//         a = a / 10;
//         b = b / 10;
//     }
//     sum = c - Ming;
//     printf("%d %d\n", c, sum);

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main()
// {
//     int a, b, index;
//     int c[12];
//     while (scanf("%d %d", &a, &b) != EOF)
//     {
//         //正确答案
//         printf("%d ", a + b);
//         //求小名的答案
//         if (a == 0 && b == 0)
//         {
//             printf("%d", a + b);
//         }
//         index = 0;
//         while (a || b)
//         {
//             int sum = a % 10 + b % 10;
//             if (sum > 9)
//             {
//                 sum -= 10;
//             }
//             c[index++] = sum;
//             a /= 10;
//             b /= 10;
//         }
//         //去掉前导0
//         index = index - 1;
//         while (c[index] == 0 && index > 0)
//         {
//             index--;
//         }
//         //输出答案
//         for (int i = index; i >= 0; i--)
//         {
//             printf("%d", c[i]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// class Student
// {
// private:
//     int sno;
//     string sname;
//     int sage;

// public:
//     Student()
//     {
//         sno = 0;
//         sname = "";
//         sage = 0;
//     }
//     Student(int no, string name, int age)
//     {
//         sno = no;
//         sname = name;
//         sage = age;
//     }
//     void show();
//     ~Student()
//     {
//         cout << "学生析构函数调用" << endl;
//     }
// };

// void Student::show()
// {
//     cout << "学号：" << sno << endl;
//     cout << "姓名：" << sname << endl;
//     cout << "年龄：" << sage << endl;
// }
// class Teacher
// {
// private:
//     int tnum;
//     string tname;
//     string tdepart;

// public:
//     Teacher()
//     {
//         tnum = 0;
//         tname = "";
//         tdepart = "";
//     }
//     Teacher(int num, string name, string depart)
//     {
//         tnum = num;
//         tname = name;
//         tdepart = depart;
//     }
//     void Show();
//     ~Teacher()
//     {
//         cout << "教师析构函数调用" << endl;
//     }
// };
// void Teacher::Show()
// {
//     cout << "学号：" << tnum << endl;
//     cout << "姓名：" << tname << endl;
//     cout << "??：" << tdepart << endl;
// }

// class GradOnWork : public Student, public Teacher
// {
// private:
//     string research;
//     string professor;

// public:
//     GradOnWork(){
//         research = "计算机学院";
//         professor = "计算机应用技术";
//     }
//     GradOnWork(int id, string name, int age, string tdepart, string research1, string professor2){
//         cout << research1 << "- " << professor2 << endl;
//     }

//     void ShowMe(){

//     }
//     ~GradOnWork()
//     {
//         cout << "在职研究生析构函数调用" << endl;
//     }
// };
// GradOnWork::GradOnWork(int id, string name, int age, string tdepart, string research,
//                        string professor)
//     : Student(id, name, age), Teacher(id, name, tdepart) {}
// void GradOnWork::ShowMe()
// {
//     Student::show();
//     Teacher::Show();

// }
// int main()
// {
//     GradOnWork Gwork(12, "蔡徐坤", 18, "???", "计算机学院", "计算机应用技术");
//     Gwork.ShowMe();
//     return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;
// class Person
// {
//     char Name[20];
//     char Sex;
//     int Age;

// public:
//     void Register(char name[], int age, char sex);
//     void ShowMe();
// };
// void Person::Register(char name[], int age, char sex)
// {
//     strcpy(Name, name);
//     Age = age;
//     Sex = sex;
// }
// void Person::ShowMe()
// {
//     cout << "姓名 " << Name << endl;
//     cout << "性别 " << (Sex == 'm' ? "男" : "女") << endl;
//     cout << "年龄 " << Age << endl;
// }
// class Teacher : virtual public Person
// {
//     char Dept[20];
//     int Salary;

// public:
//     Teacher(char name[], int age, char sex, char dept[], int salary);
//     void Show(); //显示新增数据成员
// };
// Teacher::Teacher(char name[], int age, char sex, char dept[], int salary)
// {
//     Person::Register(name, age, sex);
//     strcpy(Dept, dept);
//     Salary = salary;
// }
// void Teacher::Show()
// {
//     cout << "工作单位 " << Dept << endl;
//     cout << "月薪 " << Salary << endl;
// }
// class Student : virtual public Person
// {
//     char ID[12];
//     char Class[12];

// public:
//     Student(char name[], int age, char sex, char ID[], char Class[]);
//     void Show(); //显示新增数据成员
// };
// Student::Student(char name[], int age, char sex, char id[], char classname[])
// {
//     Person::Register(name, age, sex);
//     strcpy(ID, id);
//     strcpy(Class, classname);
// }
// void Student::Show()
// {
//     cout << "班级 " << Class << endl;
//     cout << "学号 " << ID << endl;
// }
// class Graduate : public Student, public Teacher
// {
// public:
//     Graduate(char name[], int age, char sex, char dept[], int salary, char id[], char classid[]);
//     void ShowMe(); //显示数据成员，要求调用基类的Show和ShowMe
// };
// Graduate::Graduate(char name[], int age, char sex, char dept[], int salary, char id[], char classid[])
//     : Student(name, age, sex, id, classid), Teacher(name, age, sex, dept, salary) {}
// void Graduate::ShowMe()
// {
//     Student::Show();
//     Person::ShowMe();
//     Teacher::Show();
// }
// int main()
// {

//     return 0;
// }

// #include <iostream>
// #include <string.h>
// using namespace std;
// class BirthDate
// {
// public:
//     BirthDate(int, int, int);
//     void display();
//     void setbirthday(int, int, int);

// private:
//     int year;
//     int month;
//     int day;
// };
// class Teacher
// {
// public:
//     Teacher(int, string, char);
//     void display();

// private:
//     int num;
//     string name;
//     char sex;
// };
// class Professor : public Teacher
// {
// public:
//     Professor(int, string, char, string research, BirthDate);
//     void display();
//     void setbirthday(int, int, int);

// private:
//     BirthDate birthday;
//     string research;
// };

// BirthDate::BirthDate(int y, int m, int d) : year(y), month(m), day(d) {}
// void BirthDate::display()
// {
//     cout << "birthday:" << year << "/" << month << "/" << day << endl;
// }
// void BirthDate::setbirthday(int y, int m, int d)
// {
//     year = y;
//     month = m;
//     day = d;
// }
// Teacher::Teacher(int n, string na, char s) : num(n), name(na), sex(s) {}
// void Teacher::display()
// {
//     cout << "num:" << num << endl;
//     cout << "name:" << name << endl;
//     cout << "sex:" << sex << endl;
// }
// Professor::Professor(int n, string na, char s, string research, BirthDate birthdate) : Teacher(n, na, s), birthday(birthdate)
// {
//     this->research = research;
// }
// void Professor::display()
// {
//     cout << "research:" << research << endl;
//     Teacher::display();
//     birthday.display();
// }

// void Professor::setbirthday(int y, int m, int d)
// {
//     birthday.setbirthday(y, m, d);
// }

// int main()
// {
//     int num = 1;
//     string name = "蔡徐坤";
//     char sex = 'n';
//     int year = 1999, month = 1, day = 1;
//     string research = "蔡徐坤";
//     // cin >> num >> name >> sex;
//     // cin >> year >> month >> day;
//     Professor prof(num, name, sex, research, BirthDate(year, month, day));
//     //cin >> research;
//     prof.setbirthday(year, month, day);
//     prof.display();
//     return 0;
// }

//求一个3*3矩阵对角线元素之和
// #include <stdio.h>
// int main()
// {

//     int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; //定义二维数组
//     int i, j;
//     int sum = 0;
//     printf("请输入3*3矩阵的元素\n");
//     for (i = 0; i < 3; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             //scanf("%d", &a[i][j]);   //输入数组数组元素
//             if (i == j)              //判断是否是对角线元素
//                 sum = sum + a[i][j]; //求和
//         }
//     }
//     printf("3*3矩阵对角线元素之和为%6.2d\n", sum);
//     printf("输出3*3的数组：\n");
//     for (i = 0; i < 3; i++) //输出二维数组
//     {
//         for (j = 0; j < 3; j++)
//         {
//             printf("%6d", a[j][i]);
//         }
//         printf("\n"); //换行输出*
//     }

//     return 0;
// }

// double add(double x, double y)
// {
//     return x + y;
// }

// // int main(int argc, char const *argv[])
// // {
// //     double c = add(123.33,12);
// //     cout<<c<<endl;
// //     return 0;
// // }

// double mypow(double x, int n)
// {
//     return pow(x, n);
// }

// int sum(int n)
// {
//     if (n == 1)
//         return 1;
//     else
//         return n + sum(n - 1);
// }

// int main(int argc, char const *argv[])
// {
//     //double c = mypow(5, 5);
//     int c = sum(100);
//     cout << c << endl;
//     return 0;
// }

// 1、某学校对教师每月工资的计算公式如下：固定工资 + 课时补贴。教授的固定工资为5000元,
// 每个课时补贴50元；副教授的固定工资为3000元, 每个课时补贴30元;讲师的固定工资为2000元,
//  每个课时补贴20元。定义教师抽象类, 派生不同职称的教师类, 编写程序求若干教师的月工资。

// //教师抽象类
// class Teacher
// {
// protected:
//     double salary;
//     int workhours;

// public:
//     Teacher(int wh = 0) { workhours = wh; }
//     virtual void cal_salary() = 0;
//     void print() { cout << salary << endl; }
// };
// //教授
// class Prof : public Teacher
// {
// public:
//     Prof(int wh = 0) : Teacher(wh) {}
//     void cal_salary()
//     {
//         salary = workhours * 50 + 5000;
//     }
// };
// //副教授
// class Vice_Prof : public Teacher
// {
// public:
//     Vice_Prof(int wh = 0) : Teacher(wh) {}
//     void cal_salary()
//     {
//         salary = workhours * 30 + 3000;
//     }
// };
// //讲师
// class Lecture : public Teacher
// {
// public:
//     Lecture(int wh = 0) : Teacher(wh) {}
//     void cal_salary()
//     {
//         salary = workhours * 20 + 2000;
//     }
// };
// int main()
// {
//     Teacher *pt;
//     Prof prof(200);
//     pt = &prof;
//     pt->cal_salary();
//     prof.print();
//     Vice_Prof vice_prof(250);
//     pt = &vice_prof;
//     pt->cal_salary();
//     vice_prof.print();
//     Lecture lecture(100);
//     pt = &lecture;
//     pt->cal_salary();
//     lecture.print();
//     return 0;
// }
//getSuperficialArea计算表面积、getVolume 计算体积、showAll 输出所有信息。
//●派生类Cuboid表示长方体类，增加3个属性(width表示宽度、length表示长度、height表示高度)。
//.派生类Sphere 表示球体类，增加1个属性(radius 表示半径)。
//●派生类Cylinder表示圆柱体类，增加2个属性(radius表示半径，high表示高度)。
// class SolidFigue
// {
// public:
//     virtual double getSuperficialArea() const = 0;
//     virtual double getVolume() const = 0;
//     virtual void showAll() const = 0;
// };

// class Cuboid : public SolidFigue
// {
// protected:
//     double width;
//     double length;
//     double heigh;

// public:
//     Cuboid(double width, double length, double heigh)
//     {
//         this->width = width;
//         this->heigh = heigh;
//         this->length = length;
//     }

//     virtual double getSuperficialArea() const { return (width * heigh + width * length + heigh * length) * 2; };
//     virtual double getVolume() const { return width * heigh * length; };
//     virtual void showAll() const { cout << "长方体面积  " << getSuperficialArea() << "\t体积 " << getVolume() << endl; };
// };
// //.派生类Sphere 表示球体类，增加1个属性(radius 表示半径)。V=(4/3)πr^3 
// //●派生类Cylinder表示圆柱体类，增加2个属性(radius表示半径，high表示高度)。
// class Sphere : public SolidFigue
// {
// protected:
//     double radius;

// public:
//     Sphere(double radius)
//     {
//         this->radius = radius;
//     }
//     virtual double getSuperficialArea() const { return 4 * 3.14 * radius * radius; };
//     virtual double getVolume() const { return 3.14 * radius * radius * radius * (4 / 3); };
//     virtual void showAll() const { cout << "球的面积  " << getSuperficialArea() << "\t体积 " << getVolume() << endl; };
// };
// class Cylinder : public SolidFigue
// {
// protected:
//     double radius;
//     double heigh;

// public:
//     Cylinder(double radius, double heigh)
//     {
//         this->radius = radius;
//         this->heigh = heigh;
//     }
//     //圆柱体表面积公式bai：duS=2πr²+2πrh
//     //体积zhi公式：daoV = πr²h
//     virtual double getSuperficialArea() const { return 2 * 3.14 * heigh * heigh + 2 * 3.14 * heigh * heigh; };
//     virtual double getVolume() const {return 3.14 * heigh * radius * radius;};
//     virtual void showAll() const { cout << "圆柱体的面积  " << getSuperficialArea() << "\t体积 " << getVolume() << endl; };
// };
// void print(const SolidFigue &s)
// {
//     s.showAll();
// }

// int main(int argc, char const *argv[])
// {
//     Cuboid cb(1, 2, 3);
//     print(cb);
//     Sphere s(4);
//     print(s);
//     Cylinder c(4,10);
//     print(c);
//     return 0;
// }
// int main(int argc, char const *argv[])
// {
//     int i = 2;
//     int j = 2;
//     for (i; i <= 20; i++)

//         for (j; j <= i; j++)

//             if (i % j == 0)

//                 break;

//     if (j > i - i)

//         cout << i << endl;

// }

// int main()
// {
//     int n, x, max = 0, min = 10, sum = 0;
//     double aa;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> x;
//         if (x > max)
//             max = x;
//         if (x < min)
//             min = x;
//         sum += x;
//     }
//     int a = n - 2;
//     aa = (double)(sum - max - min) / a;
//     printf("%.2f\n", aa);
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     for (int i = 2; i < 6; i++, i++)
//     {
//         printf("##%*d",i);
//     }
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     int a;
//     float b, c;

//     scanf("%d", &a);

//     scanf("%f", &b);

//     c = b;

//     if ((a >= 10) && (b >= 10000))
//         c = b * (1 - 0.15);
//     printf("Should pay:%9.2f\n", c);
//     /* code */
//     return 0;
// }

// int main()
// {
//     char ch;                    //定义字符变量ch
//     scanf("%c", &ch);           //键盘输入ch的值
//     if (ch >= 'a' && ch <= 'z') //如果ch属于小写字母
//         printf("lower");
//     else if (ch >= 'A' && ch <= 'Z') //如果ch属于大写字母
//         printf("upper");
//     else if (ch >= '0' && ch <= '9') //如果ch属于数字
//         printf("digit");
//     else //否则
//         printf("other");
//     return 0; //程序正常退出
// }

// int main()
// {
//     //定义字符变量ch
//     int num = 108;
//     int &rel_num = num;

//     cout << num << endl;
//     cout << &num << endl;

//     cout << rel_num << endl;
//     cout << &rel_num << endl;

//     int num2 = 108;

//     cout << num2 << endl;
//     cout << &num2 << endl;

//     return 0; //程序正常退出
// }

// int main(int argc, char const *argv[])
// {
//     char p[20] = "123456789zxcvbnm,./<>?";
//     int i;
//     int str_length = strlen(p);

//     int num[20];
//     char str1[20];
//     char str2[20];

//     for (i = 0; i < str_length; i++)
//     {

//         if ((p[i] >= 48) && (p[i] <= 59))
//         {

//             cout << "数字" << p[i] << endl;

//         }
//         else if ((p[i] >= 65) && (p[i] <= 90) || (p[i] >= 97) && (p[i] <= 122))
//         {
//             cout << "字母" << p[i] << endl;
//         }
//         else
//         {
//             cout << "符号" << p[i] << endl;
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {

//     //使用指针建立二维数组，这里重点来搞清他们之间的关系
//     int nums[5][3] = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9},
//         {10, 11, 12},
//         {13, 14, 15}};

//     //循环打印输出
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cout << nums[i][j] << "\t";
//         }
//         cout << endl;
//     }

//     //循环打印地址的位置输出
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cout << &nums[i][j] << "\t";
//         }
//         cout << endl;
//     }
//     cout << endl;

//     int(*ptr)[3] = nums;

//     //看一下指针所指向的地址的情况
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cout << *(ptr + i) + j << "\t";
//         }
//         cout << endl;
//     }

//     cout << endl;
//     for (int i = 0; i < 5; i++)
//     {
//         cout << ptr + i << endl;
//     }
//     cout << endl;
//     for (int i = 0; i < 5; i++)
//     {
//         cout << *(ptr + i) << endl;
//     }
// }

// #include <stdio.h>
// #include <ctype.h>
// #include <iostream>
// #include <bits/stdc++.h>
// void readfile();
// void writefile();
// void scanner();

// char rbuf[10000] = {'\0'};
// char wbuf[10000] = {'\0'};

// int main()
// {
//     readfile();
//     scanner();
//     writefile();
//     return 0;
// }

// void readfile()
// {
//     FILE *fp;
//     int ch;
//     if ((fp = fopen("read.txt", "r")) == NULL)
//     {
//         printf("open ");
//         exit(EXIT_FAILURE);
//     }
//     int i = 0;
//     while (ch = fgetc(fp) != EOF)
//     {
//         rbuf[i++];
//     }
//     rbuf[i++] = '#';
//     rbuf[i++] = '#';
//     fclose(fp);
// }
// void writefile()
// {
//     FILE *fp;

//     if ((fp = fopen("write.txt", "w")) == NULL)
//     {
//         printf_s("open");
//         exit(EXIT_FAILURE);
//     }
//     fputs(wbuf, fp);
//     fclose(fp);
// }
// void scanner()
// {
//     int bg = 0, fd = 0;
//     int wi = 0;
//     int state = 0;
//     char c;

//     while (rbuf[fd] != '\0')
//     {
//         switch (state)
//         {
//         case 0:
//             c = rbuf[fd++];
//             if (!isdigit(c) && !isalpha(c))
//             {
//                 state = 0;
//                 bg++;
//             }
//             else if (isdigit(c))
//             {
//                 state = 2;
//             }
//             else if (isalpha(c))
//             {
//                 state = 1;
//             }
//             break;
//         case 1:
//             c = rbuf[fd++];
//             if (isalpha(c))
//             {
//                 state = 1;
//             }
//             else
//             {
//                 state = 3;
//             }
//             break;
//         case 2:
//             c = rbuf[fd++];
//             if (isdigit(c))
//             {
//                 state = 2;
//             }
//             else
//             {
//                 state = 4;
//             }
//             break;
//         case 3:
//             while (bg <= fd - 2)
//             {
//                 wbuf[wi++] = rbuf[bg++];
//             }
//             wbuf[wi++] = ' ';

//             fd--;
//             state = 0;
//             break;

//         case 4:
//             while (bg <= fd - 2)
//             {
//                 wbuf[wi++] = rbuf[bg++];
//             }
//             wbuf[wi++] = ' ';

//             fd--;
//             state = 0;
//             break;
//         default:
//             break;
//         }
//     }
// }

// #include <cstring>

// int main(int argc, char const *argv[])
// {
//     cout << "hello world" << endl;
//     cout << "你好 c++" << endl;
//     scanf("\n");
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//    int n;
//    cin >> n;
//    getchar();
//    string a;
//    for (int i = 0; i < n; i++)
//    {
//       getline(cin,a);

//       cout<<" s = " << a<<endl;
//    }

//     return 0;
// }

// struct user
// {
//     string name;
//     string age;
// };

// struct addUser
// {
//     struct user addArr[100];
//     int num;
// };
// //定义联系人结构体
// struct contacts
// {
//     string name;
//     string sex;
//     int age;
//     int num;
//     string address;
// };
// //定义通讯录结构体
// struct addressBook
// {
//     //通讯录中保存的联系人数组
//     struct contacts addrArray[100];
//     //通讯录中保存的联系人个数
//     int addrSize;
// };

// //声明函数
// void menu();
// void function1(addressBook *book);
// void function2();
// void function3();
// void function4();
// void function5();
// void function6();

// int main()
// {

//     //调用开始菜单功能
//     menu();
//     //定义一个通讯录结构体变量
//     addressBook book;
//     while (true)
//     {

//         int num1 = 0;
//         cout << "请输出你想要运行的功能:";
//         cin >> num1;

//         if (num1 > 6 || num1 < 0)
//         {

//             cout << "您输入的数字无效果,请从新输入!" << endl;
//             continue;
//         }
//         else
//         {

//             switch (num1)
//             {

//             case 1:
//                 function1(&book);
//                 break;
//             case 2:
//                 function2();
//                 break;
//             case 3:
//                 function3();
//                 break;
//             case 4:
//                 function4();
//                 break;
//             case 5:
//                 function5();
//                 break;
//             case 6:
//                 function6();
//                 break;
//             case 0:
//                 cout << "退出成功!欢迎下次使用!" << endl;
//                 return 0;
//                 break;
//             }
//         }
//     }
// }

// //菜单函数
// void menu()
// {

//     cout << "********************************************" << endl;
//     cout << "|**********   1、添加联系人(输入1)  **********|" << endl;
//     cout << "|**********   2、显示联系人(输入2)  **********|" << endl;
//     cout << "|**********   3、删除联系人(输入3)  **********|" << endl;
//     cout << "|**********   4、查找联系人(输入4)  **********|" << endl;
//     cout << "|**********   5、修改联系人(输入5)  **********|" << endl;
//     cout << "|**********   6、清空联系人(输入6)  **********|" << endl;
//     cout << "|**********   0、推出通讯录(输入0)  **********|" << endl;
//     cout << "***********     清空通讯录请慎用    ***********" << endl;
// }

// //功能函数1:添加联系人
// void function1(addressBook *add)
// {

//     //添加姓名
//     string name;
//     cout << "请输入您所要添加联系人的姓名:";
//     cin >> name;
//     add->addrSize = 0;
//     add->addrArray[add->addrSize]
//         .name = name;

//     while (true)
//     { //添加性别
//         int sex = 0;
//         cout << "请输入您所要添加联系人的性别:" << endl;
//         cout << "0代表男/1代表女" << endl;
//         cin >> sex;

//         if (sex == 0)
//         {
//             add->addrArray[add->addrSize].sex = "男";
//         }
//         else if (sex == 1)
//         {
//             add->addrArray[add->addrSize].sex = "女";
//         }
//         else
//         {
//             cout << "您输入的性别是个笑话,请从新输入!" << endl;
//             continue;
//         }
//         break;
//     }

//     //添加年龄
//     int age = 0;
//     cout << "请输入您所要添加联系人的年龄:" << endl;
//     cin >> age;
//     add->addrArray[add->addrSize].age = age;

//     //添加电话号3
//     long long num = 0;
//     cout << "请输入您所添加联系人的电话:" << endl;
//     cin >> num;
//     add->addrArray[add->addrSize].num = num;

//     //添加地址
//     string address;
//     cout << "请输入您所添加联系人的地址:" << endl;
//     cin >> address;
//     add->addrArray[add->addrSize].address = address;

//     cout << add->addrArray[add->addrSize].age <<","<< add->addrArray[add->addrSize].address << endl;
//     add->addrSize++ ;
// }

// void function2()
// {
// }

// void function3()
// {
// }

// void function4()
// {
// }

// void function5()
// {
// }

// void function6()
// {
// }
// int main(int argc, char const *argv[])
// {
//     int a = -2;

//     printf("%d,%d\n", a, a--);
//     a = -2;
//     printf("%d,%d", a, --a);
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     vector<int> a;
//     a.push_back(1);
//     a.push_back(2);
//     a.push_back(3);
//     a.push_back(4);
//     a.push_back(6);
//     a.push_back(5);

//     for (int b : a)
//     {
//         cout << b << endl;
//     }
//     return 0;
// }

// class Building
// {
// public:
//     Building();

//     string visitRoom;

// private:
//     string bedRoom;
// };
// Building::Building()
// {
//     visitRoom = "客厅"; //客厅
//     bedRoom = "卧室";   //卧室
// }
// class GoodGay
// {
// public:
//     GoodGay();
//     Building *building;
//     void visit();
// };
// GoodGay::GoodGay()
// {

//     building = new Building();
// }
// void GoodGay::visit()
// {
//     cout << "visit()" << endl;
// }
// int main()
// {
//     GoodGay *g = new GoodGay();
//     g->visit();
//     cout<<g->building<<endl;
// }

//冒泡排序函数  参数一 数组的首地址  参数二 数组长度
// void bubbleSort(int *arr, int len)
// {
//     for (int i = 0; i < len  ; i++)
//     {
//         for (int j = 0; j < len ; i++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }
// //打印数组
// void printArray(int *arr, int len)
// {
//     for (int i = 0; i < len; i++)
//     {
//         cout << arr[i] << endl;
//     }
// }

// int main()
// {
//     //先创建数组
//     int arr[] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 50};

//     //数组长度
//     int len = sizeof(arr) / sizeof(arr[0]);
//     //2.创建函数，实现冒泡排序
//     bubbleSort(arr, len);
//     //3.打印排序后的数组
//     printArray(arr, len);
// }

// int main(int argc, char const *argv[])
// {
//     bool b_show = true;
//     cout<<(b_show ? "是的" : "不是")<<endl;

//     return 0;
// }
//实现斗地主的信息显示，摸牌发牌等
// #include <iostream>
// #include "Landowner.h"
// #include "Landowner.cpp"
// using namespace std;

// int main()
// {
//     Landowner *ptr_landownerv1 = new Landowner();
//     Landowner *ptr_landownerv2 = new Landowner("大金牙");
//     Landowner *ptr_landownerv3 = new Landowner("王胖子");

//     ptr_landownerv1->showinfo();
//     ptr_landownerv2->showinfo();
//     ptr_landownerv3->showinfo();

//     delete ptr_landownerv1;
//     delete ptr_landownerv2;
//     delete ptr_landownerv3;

//     cout << "Hello world!" << endl;
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     for(;;){
//         char aaa[1];
//         char aa[10];

//         scanf("%s",aaa);

//         printf("输出  %s \n",aaa);
//         printf("输出  %d \n", sizeof(aaa));
//         printf("输出2 %s \n", aa);
//     }
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     int T = 4;
//     while(T--){
//         char ch;
//         printf("press a key and then press enter:\n");
//         scanf("%c", &ch);
//         getchar()
//         if ((ch >= 0 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 127))
//             printf(" %c is 其他字符 ,ASCII is %d\n", ch, ch);
//         if (ch >= 48 && ch <= 57)
//             printf("%c is 数字字符,ASCII is %d\n", ch, ch);
//         if (ch >= 65 && ch <= 90)
//             printf("%c is 大写字母,ASCII is %d\n", ch, ch);
//         if (ch >= 97 && ch <= 122)
//             printf("%c is 小写字母,ASCII is %d\n", ch, ch);
//     }
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     float price = 0.0;
//     int m = 0;
//     int d = 0;
//     int flag = 0;
//     int i ;
//     for (i = 0; i < 4; i++)
//     {
//         scanf("%f%d%d%d", &price, &m, &d, &flag);
//         if (m == 11 && d == 11)
//         {
//             price *= 0.7;
//             if (flag == 1)
//                 price -= 50;
//         }
//         else if (m == 12 && d == 12)
//         {
//             price *= 0.8;
//             if (flag == 1)
//                 price -= 50;
//         }
//         if (price < 0.0)
//             price = 0.0;
//         printf("%.2f\n", price);

//     }
//      return 0;
// }

// int main()
// {

//     while (1)
//     {
//         SYSTEMTIME sys;
//         GetLocalTime(&sys);
//         printf("%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);
//         cout<<(sys.wSecond == 20)<<endl;
//         _sleep(1 * 1000);
//     }
//     return 0;
// }
// double *retArr(double arr[],int len)
// {
//     int i, j;
//     double temp;
//     //int len = (int)sizeof(arr) / sizeof(*arr);
//     for (i = 0; i < len - 1; i++)
//         for (j = 0; j < len - 1 - i; j++)
//             if (arr[j] > arr[j + 1])
//             {
//                 temp = arr[j];
//                 arr[j] = arr[j + 1];

//                 arr[j + 1] = temp;
//             }
//     return arr;
// }
// int main()
// {
//     double dp[10] = {11.1, 22.2, 13.3, 34.4, 15.5, 36.6, 57.7, 38.8, 91.9, 10.1};
//     int len = (int)sizeof(dp) / sizeof(*dp);
//     double *arr = retArr(dp,len);
//     for (int i = 0; i < 10; ++i)
//     {
//         printf("arr[%d] = %.1lf\n", i, arr[i]);
//     }

//     return 0;
// }

// 书写函数实现冒泡排序并返回排序后的数组
// double *sort();
// double *sort()
// {
//     int i, j;    //循环变量
//     double temp; //临时变量
//     static double arr[5] = {20, 30, 501, 22, 3334};
//     for (i = 0; i < 5 - 1; i++)
//     {
//         for (j = 0; j < 5 - i - 1; j++)
//         {
//             if (arr[j] < arr[j + 1])
//             {
//                 temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
//     return arr;
// }
// int main()
// {
//     int i; //循环变量
//     double *arri = sort();
//     //int sum = search();
//     //printf("查找到的下标为:%d\n", sum);

//     printf("数组排序后:\n");
//     for (i = 0; i < 5; i++)
//     {
//         printf("arr[%d] = %.2lf\n", i, *(arri + i));
//     }
//     for (size_t i = 0; i < 5; i++)
//     {
//         printf("arr[%d] = %.2lf\n", i, *(arri + i));
//     }

// }
// int main(int argc, char const *argv[])
// {
//     char a = getchar();
//     return 0;
// }

// int main()
// {
//     float f, c;
//     printf("输入华氏温度F\n");
//     scanf("%f", &f);
//     c = 5 / 9.0 * (f - 32);
//     printf("华氏温度F=%.2f °F, \n摄氏温度C=%.2f °C", f, c);
// }

// #include <stdio.h>

// typedef struct A
// {
//     char title[50];
//     char author[50];
//     char subject[100];
//     int id;
// }  AA;

// AA book = {"C 语言", "RUNOOB", "编程语言", 123456};

// int main()
// {
//     printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.id);
// }

//主要看一下虚函数virtual函数重写，找一个程序看一下
// #include <iostream>
// using  namespace std;
// class Parent
// {
//  public:

//      void Function1();
//      virtual void Function2();   // 这里声明Function2是虚函数

//  };

//  void Parent::Function1()
//  {
//      printf("This is parent,function1\n");
//  }

//  void Parent::Function2()
//  {
//      printf("This is parent,function2\n");
//  }

//  class Child:public Parent
//  {
//      void Function1();
//      void Function2();

//  };

//  void Child::Function1()
//  {
//      printf("This is child,function1\n");
//  }

//  void Child::Function2()

//  {
//      printf("This is child,function2\n");
//  }

//  int main()
//  {
//      Parent parent;
//      Child child;
//      Parent *p = &child;
//      p->Function1();
//      p->Function2();
//     //  p.Function1();
//     //  p.Function2();

//      return 0;

//  }
// #include <iostream>
// #include <string>

// #include <ctime>
// using namespace std;

// int main()
// {
//     srand(time(NULL));
//     int hp1 = 100, hp2 = 100;    //双方的初始血量
//     int att1, att2;              //p1和p2的普通攻击力
//     int i = 0;                   //对战轮数
//     while (hp1 >= 0 && hp2 >= 0); //两个都活着的时候，继续对战
//     {
//         //默认p1先攻击
//         att1 = rand() % 11 + 5; //每次攻击5——15
//         att2 = rand() % 11 + 5;
//         //玩家1攻击，玩家2掉血
//         hp2 -= att1;
//         //玩家2攻击，玩家1掉血
//         hp1 -= att2;
//         printf("第%d轮：\n", i + 1);
//         printf("玩家1攻击力%d，玩家2剩余血量%d\n", att1, hp2);
//         printf("玩家2攻击力%d,玩家1剩余血量%d\n", att2, hp1);
//         i++;

//         printf("OK!游戏结束！玩家1剩余血量：%d\t玩家2剩余血量：%d\n", hp1, hp2);
//     }
//     return 0;
// }
// int main(int argc, char const *argv[])
// {
// //     char ch[100];
// //     //gets(ch);
// //     int a = 200;
// //    // HWND hwnd = FindWindow(NULL, "Slaver");
// //     while (a)
// //     {

// //        printf("a = %d\t",a);
// //        if(a % 6 == 0){
// //            printf("\n");
// //        }
// //        a--;
// //     }
//     double a;
//     scanf("%if",&a);
//     printf("%lf\n",a);
//     printf("%i\n", a);
//     printf("%d\n", a);
//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     int i;
//     double gz;      //工资
//     double zgj = 0; //总工资
//     double pjgz;    //平均工资
//     for (i = 0; i < 6; i++)
//     {
//         printf("请输入第%d个月工资：", i); //这已经循环完
//         scanf("%lf", &gz);                 //输入工资
//         zgj += gz;                         //总工资计算//这好像没循环累加 scanf
//     }

//     printf("打印总工资：%lf", zgj);

//     pjgz = zgj / 6; //平均工资计算

//     printf("打印平均工资：%lf", pjgz);

// }
// void printfArr(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// class Box
// {
// public:
//     char arr[50];
//     double length;  // 长度
//     double breadth; // 宽度
//     double height;  // 高度
//     // 成员函数声明
//     double get(void);
//     void set(char arr[], double length, double bre, double hei);
//     Box(char arr[], double length, double breadth, double height)
//     {
//         //this->arr = arr;
//         strcpy(this->arr, arr);
//         this->length = length;
//         this->breadth = breadth;
//         this->height = height;
//     }
// };

// void Box::set(char arr[], double length, double breadth, double height)
// {
//     //this->arr = arr;
//     strcpy(this->arr, arr);
//     this->length = length;
//     this->breadth = breadth;
//     this->height = height;
// }
// int main()
// {

//     Box Box3; // 声明 Box3，类型为 Box

//     char arr[] = "指针真好玩";
//     Box3.set(arr, 16.0, 8.0, 12.0);
//     cout << Box3.arr << endl;

//     double volume = 0.0; // 用于存储体积
//                          // box 3 详述
//     Box Box1;            // 声明 Box1，类型为 Box
//     Box Box2;            // 声明 Box2，类型为 Box
//     // // box 1 详述
//     // Box1.height = 5.0;
//     // Box1.length = 6.0;
//     // Box1.breadth = 7.0;

//     // // box 2 详述
//     // Box2.height = 10.0;
//     // Box2.length = 12.0;
//     // Box2.breadth = 13.0;

//     // // box 1 的体积
//     // volume = Box1.height * Box1.length * Box1.breadth;
//     // cout << "Box1 的体积：" << volume << endl;

//     // // box 2 的体积
//     // volume = Box2.height * Box2.length * Box2.breadth;
//     // cout << "Box2 的体积：" << volume << endl;

//     return 0;
// }

// // 成员函数定义
// double Box::get(void)
// {
//     return length * breadth * height;
// }

// int main()
// {
//     //利用冒泡排序实现升序序列
//     int arr[9] = {
//         4,
//         3,
//         8,
//         1,
//         5,
//         7,
//         2,
//         6,
//         9,
//     };
//     cout << "排序前；" << endl;
//     for (int z = 0; z < 9; z++)
//     {
//         cout << arr[z] << "  ";
//     }
//     cout << endl;
//     //总排序轮数为元素个数-1
//     for (int i = 0; i < 9; i++)
//     { //内层循环对比   次数=元素个位-当前轮数-1
//         for (int j = 0; j < 9 -i -1; j++)
//         { //如果第一个数字比第二个数字大，那就交换2个数字
//             if (arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
//     cout << "排序后；" << endl;
//     for (int q = 0; q < 9; q++)
//     {
//         cout << arr[q] << "  ";
//     }
//     cout << endl;

//     return 0;
// }

// #include <stdio.h>
// float fun(float a, float b, float c)
// { /****/
//     float sum = 0, i;
//     for (i = a; i <= b; i = i + c)
//     {
//         sum = sum + 3.14 * i * i;

//     }
//     return sum;

//     /****/
// }
// int main()
// {
//     float x;
//     float y;
//     float z;
//     float sumS;
//     float d;
//     printf("请输入3个成等差数列的半径值:");
//     scanf("%f,%f,%f", &x, &y, &z);
//     d =y-x;
//     sumS = fun(x, z, d);

//     printf("总面积:%.2f\n", sumS);
//     return 0;
// }

// int main()
// {
//     vector<int> a;
//     int i = 0;
//     for (i = 0; i < 10; i++)
//     {
//         a.push_back(i);
//     }
//     for(int i:a){
//         printf("%d, " ,i);
//     }
//     printf("\n");
//      return 0;
// }
// #include <iostream>
// #include <string>
// #include <vector> //类模板
// template <typename T>
// T fun(T a, T b);

// int main()
// {
//     /*
// cout<<"put number: " ;
// string s1 = "hello";
// cout<<s1;
// */
//     string s1 = "hello", s2 = "world";
//     cout << fun<string>(s1, s2) << endl;    //输出s1+s2这个字符串
//     cout << fun<double>(30.22, 20) << endl; //输出数值调用函数的结果
//     string s3 = s1.substr(1, 3);            //拿出s1字符串的1-3
//     cout << s3 << endl;                     //输出拿到的新字符串s3
//     s3.insert(1, "hhhhhh");
//     cout << s3 << endl;        //向s3第一个元素之后插入新的字符串
//     cout << s3.size() << endl; //输出s3的长度
//     std::vector<int> v = {2,47,89,45};
//     //可以通过  push.back（）   最后添加一个元素
//     v.push_back(88);
//     v.push_back(99);
//     v.push_back(45);
//     v.push_back(32);
//     v.push_back(23);
//     v.push_back(666);
//     //成员函数size（）、下标运算符[]
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << '\t';
//     }
//     cout << '\n';
//     v.pop_back(); //删除最后一个

//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << "删掉一个之后的元素：" << v[i] << '\t';
//         cout << '\n';
//     }
//     v.resize(3); //讲大小设置为3，如果resize设置的空间大于现有个数，就会在后面补0
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << "输出设置为3动态大小的元素：" << v[i] << '\t';
//         cout << '\n';
//     }
//     return 0;
// }
// template <typename T>
// T fun(T a, T b)
// {
//     //cout<<a.size()<<endl;
//     return a + b;
// }

// struct A
// {
//     vector<string> data {"A","B","C","D"};
//     int l = data.size();
// } a, *aa = &a;

// void printLi(){

//     for (int i = 0; i < a.l; i++)
//     {
//         cout<<a.data[i]<<" ";
//     }
//     cout<<endl;
//     for (int i = 0; i < aa->l; i++)
//     {
//         cout << aa->data[i]<<" ";
//     }
//     struct A *aaa = aa;
//     for (int i = 0; i < aaa->l; i++)
//     {
//         cout << aaa->data[i] << " ";
//     }
// }

// int main(int argc, char const *argv[])
// {
//     printLi();
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     int a[] = {1, 2, 3, 4, 5, 6}, *p;
//     p = a;
//     // printf("%p\n", &a);
//     // printf("%p\n", p);
//     // printf("%p\n", &a[0]);
//     // printf("%p\n", p);
//     // printf("%p\n", &a[1]);
//     // printf("%p\n", p + 1);
//     // printf("%p\n", &a[4]);
//     // printf("%p\n",&a[5]);
//     // printf("%p\n", p + 5);
//     // printf("%p\n", p + 6);
//     // printf("%d\n%d\n", p[5], a[5]);

//     return 0;
// }

// int strlen(char *str)
// {
//     string s = str;
//     return s.length();
// }
// // int strlen2(char *str)
// // {

// //     return sizeof(str) / sizeof(char);
// // }

// // int main(int argc, char const *argv[])
// // {
// //     cout<<strlen2("123456789");
// //     return 0;
// // }
// // #include <stdlib.h>
// // #include <stdio.h>
// // void jiuzhe()
// // {
// //     int i;
// //     double *ptr;
// //     ptr = (double *)malloc(5 * sizeof(double));
// //     for (i = 0; i < 3; i++)
// //     {
// //         scanf("%lf", &ptr[i]);
// //     }
// //     for (i = 0; i < 3; i++)
// //     {
// //         printf("%lf", ptr[i]);
// //         /* code */
// //     }

// //     printf("jiuzhe");
// // }
// // int main()
// // {
// //     printf("jiuzhea!");
// //     jiuzhe();
// // }

// //定义一个结构体

// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #define MAX 100
// typedef struct Student
// {
//     int stu_id;
//     char name[100];
// } Stu;

// Stu stuw[2] = {
//     {20180001, "xiaoming"},
//     {20180002, "小明"}};

// void write()
// {
//     // 定义一个文件指针
//     FILE *fp;

//     // 初始化一个结构体数组

//     // 打开文件，没有文件自动创建
//     fp = fopen("student.dat", "wb");          // b:表示以二进制写入
//                                               // 写入数据
//     fwrite((char *)stuw, sizeof(Stu), 2, fp); //2：表示将数组中两个元素写入文件
//     // 关闭文件
//     fclose(fp);
// }

// void read()
// {
//     // 定义一个文件指针
//     FILE *fp;
//     // 定义一个buf结构体，用于得到文件内容
//     struct stat buf;
//     // 定义一个文件行数记录变量
//     int rows;
//     // 定义一个Student结构体
//     Stu stur[10];

//     // 求文件中的行数（记录个数）
//     stat("student.dat", &buf);
//     rows = buf.st_size / sizeof(Stu);

//     // 打开文件
//     fp = fopen("student.dat", "rb");
//     // 读取数据到数组中
//     fread((char *)stur, sizeof(Stu), rows, fp);
//     // 关闭文件
//     fclose(fp);

//     // 遍历数组，打印数据信息
//     for (int i = 0; i < rows; i++)
//         printf("%d\t%s\n", stur[i].stu_id, stur[i].name);
// }
// int main(int argc, char const *argv[])
// {
//     write();
//     read();
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     int n, m, i, j;
//     char x, s[20];
//     while (scanf("%s", s) != EOF)
//     {

//         if (strlen(s) != 1)
//         {
//             printf("输入错误,请重新输入\n");
//             continue;
//         }
//         m = s[0] - '0';
//         if (m == 1)
//             printf("%d\n", n);
//         else
//             printf("输入错误,请重新输入\n");
//     }

//     return 0;
// }

// int strlen(char *str)
// {
//     string s = str;
//     return s.length();
// }

// int main(int argc, char const *argv[])
// {
//     /* code */
//     cout<<strlen("444444");
//     int a, b = 1;
//     for (a = 1; a <= 10; a++)
//     {
//         b *= a;
//     }
//     printf("  1到100的累乘值为：%d\n", b);

//     return 0;
// }
// #include <stdio.h>

// #include <string.h>

// int main()
// {
//     FILE *ff, *fp;
//     int temp = 0;      //temp主要用来某行判断是否删除，0表示不删除，1表示删除
//     char a[1000];      //放置fgets的某一行内容
//     char b[1000];      //保存用户输入的内容
//     char c[5] = "*\n"; //这里将特定字符设置为 “*”

//     printf("请输入要删除的开始行（的内容）:\n");
//     scanf("%s", b);  //输入要删除的内容
//     strcat(b, "\n"); //因为fgets函数在读取的字符后面自动添加一个换行符，为能用strcmp比较a和b,这里为b加上“\n”

//     ff = fopen("input.txt", "r");  //读打开原文件index.txt
//     fp = fopen("output.txt", "w"); //写打开临时文件result.txt

//     if (ff == NULL || fp == NULL)
//     {
//         printf("打开文件失败\n");
//         exit(0); //退出
//     }

//     while (fgets(a, 1000, ff)) //逐行执行index.tzt里面的内容
//     {
//         if (strcmp(a, b) != 0 && temp == 0) //如果与输入的内容不相等temp不等于0，则不删除
//         {
//             printf("%s", a); //将不删除的内容输出在控制台上（跟result文件内容是一致的）
//             fputs(a, fp);    //将不删除的内容写入result.txt中
//         }
//         else //找到与输入内容匹配的行
//         {
//             temp = 1;
//             if (strcmp(a, c) == 0) //遇到下一个*，则从该行开始不再删除
//                 temp = 0;
//         }
//     }
//     fclose(ff); //关闭index文件
//     fclose(fp); //关闭result文件
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int MaxSubsequenceSum(const int A[], int n)
// {
//     int tempSum = 0;
//     int maxSum = 0;
//     for (int j = 0; j < n; j++) // 子问题后边界
//     {
//         tempSum = (tempSum + A[j]) > A[j] ? (tempSum + A[j]) : A[j];
//         if (tempSum > maxSum) // 更新最大和
//             maxSum = tempSum;
//     }
//     return maxSum;
// }

// int main()
// {
//     const int a[] = {1, -1, 2, 2, 3, -3, 4, -4};
//     int maxSubSum = MaxSubsequenceSum(a, 8);
//     cout << "The max subsequence sum of a is: " << maxSubSum << endl;
//     return 0;
// }

// int a[100] = {0};

// void print(int m)
// {

//     //printfArr(a);
//     for (int i = 0; i < m - 1; i++)
//         printf("%d+", a[i]);
//     printf("%d\n", a[m - 1]);
// }

// void T4(int n, int m) //n要划分的整数,m已划分的划分数，a[0]~a[m-1]保存了已划分的值
// {
//     int i;
//     if (n == 0)

//         print(m);
//     else
//         for (i = n; i >= 1; i--)
//             if (m == 0 || i <= a[m - 1]) //只有当刚开始划分m==0或者i小于最大已划分的值时，将i作为下一个要划分的值，继续划分
//             {
//                 a[m] = i;
//                 T4(n - i, m + 1);
//             }
// }

// int main()
// {
//     int n, m = 0;
//     scanf("%d", &n);
//     T4(n, m);
// }

// int main(int argc, char const *argv[])
// {
//     int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 99};

//     int *a = arr;

//     for (int i = 0; i < 10; i++)
//     {
//         printf("%d, ", arr[i]);
//     }
//     printf("\n");
//     for (int i = 0; i < 10; ++i)
//     {
//         printf("%d, ", a[i]);
//     }
//     // printf("\n");
//     // for (int i = 0; i < 10; ++i)
//     // {
//     //     printf("%d, ", (*a + i));
//     // }

//     return 0;
// }
// #include <iostream>
// using namespace std;
// int T6()
// {
//     int i, j, n;
//     int a[100][100];
//     printf("请输入数字三角形的行数：\n");
//     scanf("%d", &n);
//     printf("请输入数字三角形：\n");
//     for (i = 1; i <= n; i++)
//     {
//         for (j = 1; j <= i; j++)
//         {
//             scanf("%d", &a[i - 1][j - 1]);
//         }
//     }
//     for (int row = n - 2; row >= 0; row--)
//     {
//         for (int col = 0; col <= row; col++)
//         {
//             a[row][col] += max(a[row + 1][col], a[row + 1][col + 1]);
//         }
//     }
//     cout << "最大路径和:" << a[0][0] << endl;
// }
// int main()
// {
//     T6();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int T6()
// {
//     int n;
//     int a[100][100];
//     printf("请输入数字三角形的行数：\n");
//     scanf("%d", &n);
//     printf("请输入数字三角形：\n");
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             scanf("%d", &a[i - 1][j - 1]);
//         }
//     }
//     for (int i = n - 2; i >= 0; i--)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
//         }
//     }
//     cout << "最大路径和:" << a[0][0] << endl;
// }
// int main()
// {
//     T6();
//     return 0;
// // }
// struct Books
// {
//    char  title[50];
//    char  author[50];
//    char  subject[100];
//    int   book_id;
// } book[] = {{"a", "b", "c", 1},
//             {"a", "b", "c", 1}};
// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     double flowerPrice;
//     printf("今天刚互相认识的小女孩小男孩，约好了晚上一起压马路\n");
//     printf("小男生用自己的工资买了一束花给小女生\n");
//     printf("小女生害羞的接过了花并问道：你怎么就送我花了呢，看起来挺贵吧？\n");
//     printf("小男生回答道：");
//     scanf("%0lf", &flowerPrice);
//     if (flowerPrice > 999999)
//     {
//         printf("小女孩吓得直接晕了过去！\n");
//     }
//     else if (flowerPrice >= 100000 && flowerPrice <= 999999)
//     {
//         printf("小女孩高兴的叫到：欧巴！明天我们就结婚吧！\n");
//     }
//     else if (flowerPrice >= 10000 && flowerPrice < 100000)
//     {
//         printf("小女孩说道：怪不好意思的，你对女孩子真好，你现在缺女朋友吗？嘻嘻嘻！\n");
//     }
//     else if (flowerPrice >= 500 && flowerPrice < 10000)
//     {
//         printf("小女孩笑的很开心：谢谢你的花，它们很漂亮呢！你真好！\n");
//     }
//     else
//     {
//         printf("小女孩说道：好吧，我们是普通朋友，你是个好人\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// int main()
// {
//     //用时间做种子，每次产生随机数字不一样
//     srand(time(NULL));
//     //rand()取值范围：0-32767
//     printf("随机数字：%d\n", rand());
//     int hp1 = 100, hp2 = 100;
//     int att1, att2;
//     while (hp1 >= 0 && hp2 >= 0)
//     {

//         //默认1p首先攻击
//         att1 = rand() % 11 + 5; //5-15之间的攻击力
//         att2 = rand() % 11 + 5;
//         //玩家1攻击，玩家2掉血
//         hp2 -= att1;
//         //玩家2攻击，玩家1掉血
//         hp1 -= att2;
//         printf("********************************\n");
//             printf("玩家1攻击力：%的，玩家2剩余血量：%\natt1,att2");
//         printf("玩家2攻击力：%的，玩家1剩余血量：%d\n", att2, hp1);
//         printf("************************************\n");
//     }
//     printf("KO`~游戏结束，玩家1的血量：%d\t玩家2的血量：%d\n");
//     return 0;
// }
// int main(int argc, char const *argv[])
// {

//     int i = 5;
//     int j = 5;
//     int a = (i++) + (i++) + (i++);
//     int b = (++j) + (++j) + (++j);

//     cout << a << endl;
//     cout << b << endl;
// }
// #define AREA(a, b) a + b
// void t1();
// void t2();
// int main(int argc, char const *argv[])
// {
//     t1();
//     t2();
//     return 0;
// }

// void t1()
// {
//     int s = AREA(3, 4) * AREA(3, 4);
//     cout<<s<<endl;
// }

// void t2()
// {
//     int a = 5, b = 6, c = 12;
//     int z = (a * b - c) / a;
//     cout << z;
// }

// int main(int argc, char const *argv[])
// {
//     int n = 0;
//     cin >> n;
//     if (n % 3 != 0 && n % 5 != 0 && n % 7 != 0)
//     {
//         cout << 'n' << endl;
//         return 0;
//     }
//     if (n % 3 == 0)
//     {
//         cout << 3 << " ";
//     }
//     if (n % 5 == 0)
//     {
//         cout << 5 << " ";
//     }
//     if (n % 7 == 0)
//     {
//         cout << 7 << " ";
//     }
//     cout << endl;

//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     float a = 1.1f;
//     cout << a;

//     return 0;
// }

// #define DECLARE(name, type) type name##_##type##_type
// int main(void)
// {

//     cout << DECLARE(1, 2);
//      return 0;
// }

// void foo(int *a, int *b)
// {
//     *a = *a + *b;
//     *b = *a - *b;
//     *a = *a - *b;
// }
// int main()
// {

//     int a = 666, b = 888;
//     printf("%d\n", a, b);

// }
// int main()
// {

//     int week = 0;
//     printf("星期几:");
//     scanf("%d", &week);

//     switch (week)
//     {
//     case 1:
//         printf("星期一\n");
//         break;
//     case 2:
//         printf("星期二\n");
//         break;
//     case 3:
//         printf("星期三\n");
//         break;
//     case 4:
//         printf("星期四\n");
//         break;
//     case 5:
//         printf("星期五\n");
//         break;
//     case 6:
//         printf("星期六\n");
//         break;
//     case 7:
//         printf("星期七\n");
//         break;
//     default:
//         printf("输入的数据有误！\n");
//     }
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     //名字
//     char a[100] = "你好";

//     int b[3][4];

//     int *p[] = {b[0],b[1]};
//     cout<<a;
//     return 0;
// }

// int main()
// {
//     int i, u[4], v[4], x, y = 10;
//     for (i = 0; i <= 3; i++)
//     {
//         cin >> u[i];
//     }
//     v[0] = (u[0] + u[1] + u[2] + u[3]) / 7;
//     v[1] = u[0] / ((u[1] - u[2]) / u[3]);
//     v[2] = u[0] * u[1] / u[2] * u[3];
//     v[3] = v[0] * v[1];
//     x = (v[0] + v[1] + 2) - u[(v[3] + 3) % 4];
//     if (x > 10)
//         y += (v[2] * 100 - v[3]) / (u[u[0] % 3] * 5);
//     else
//         y += 20 + (v[2] * 100 - v[3]) / (u[v[0] % 3] * 5);
//     cout << x << "," << y << endl;
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     char a, b, c, d, e;
//     a = getchar() - '0';
//     b = getchar() - '0';
//     c = getchar() - '0';
//     d = getchar() - '0';
//     e = a + b + c + d;
//     printf("%d",e);
//     return 0;
// }
// #include <stdlib.h>

// bool not7(int n)
// {

//     int i = n;
//     n = n / 10;
//     if (n < 1)
//     {
//         return true;
//     }
//     return not7(n) && i % 10 == 7;
// }
// int main(int argc, char const *argv[])
// {

//     int n = 177;
//     if(n / 7 == 0){
//         cout<<"aa";
//     }else if (not7(n))
//     {
//         cout<<"bb";
//     }

//     return 0;
// }

// #include <vector>
// struct A
// {
//     vector<int> a;
// };

// struct B
// {
//     int a;
// };

// int main(int argc, char const *argv[])
// {
//     B b;
//     b.a = 12;
//     vector<B> c;
//     c.push_back(b);
//     c.push_back(b);
//     c.push_back(b);
//     c.push_back(b);
//     for(B bs : c){
//         cout<<bs.a<<" ";
//     }
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     int a[] = {1, 2, 3, 4, 5};
//     int *p[] = {a, a + 1, a + 2, a + 3};
//     int **q = p;
//     cout << *(p[0] + 1) + **(q + 2);
//     return 0;
// }

// int func(int x, int y)
// {
//     return (x + y);
// }
// int main()
// {
//     int a = 1, b = 2, c = 3, d = 4, e = 5;
//     printf(" %d\n", func((a + b, b + c, c + a), (d, e)));

//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     unsigned char *p1;
//     unsigned long *p2;
//     p1 = (unsigned char *)0x801000;
//     p2 = (unsigned long *)0x810000;

//     cout << p1 + 5 << endl;

//     cout << p2 + 5;
//     return 0;
// }

// int main(void)
// {
//     int x = 10, y = 20, t = 0;
//     if (x == y)
//         t = x;
//     x = y;
//     y = t;
//     printf("%d,%d\n", x, y);
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     int a[3][3] = {{1, 2}, {3, 4}, {5, 6}}, i, j, s = 0;
//     for (i = 1; i < 3; i++)
//         for (j = 0; j <= i; j++)
//             s += a[i][j];
//     printf("%d\n", s++);
//     return 0;
// }

// #pragma comment(linker,"/SECTION:.rdata,RW")
// //加这句可以让常量区可写，后果自负！
// #include <stdio.h>
// #include <malloc.h>
// #include <string.h>
// enum Status {OK,ERROR1};
// /** 串的堆式顺序存储结构（heap）*/
// typedef struct hstring
// {
//     char * ch;
//     int length;
// }Hstring;
// int Index_HeapString(Hstring *str,Hstring *findstr,int start)
// {
//     int i;
//     for (i=start-1;i<str->length - findstr->length;i++) {
//         if (0==strncmp(str->ch+i,findstr->ch,findstr->length)) return i+1;
//     }
//     return 0;
// }
// /** 将串str中的oldStr替换成newStr */
// Status Replace_HeapString(Hstring * str, Hstring oldStr, Hstring newStr)
// {
//     int i,index;
//     if(!str || oldStr.length!=newStr.length)
//         return ERROR1;
//     index = Index_HeapString(str, &oldStr, 1);
//     if(index && index <= str->length)
//     {
//         for(i = 0; i < newStr.length; i++)
//         {
//             str->ch[index - 1 + i] = newStr.ch[i];
//         }
//         return OK;
//     }
//     return ERROR1;
// }
// void StrAssign(Hstring *str,const char *val)
// {
//     str->ch=(char *)val;
//     str->length=strlen(val);
// }
// void PrintString(Hstring *str)
// {
//     printf("%.*s\n",str->length,str->ch);
// }
// int main() {
//     Hstring * str1 = NULL;
//     Hstring str4;
//     Hstring str5;
//     str1 = (Hstring*)malloc(sizeof(Hstring));
//     //为str1赋值
//     StrAssign(str1, "helloword");
//     //为str4赋值
//     StrAssign(&str4, "eee");
//     //为str5赋值
//     StrAssign(&str5, "llo");
//     //将串str1中的"llo"替换成"eee"
//     Replace_HeapString(str1, str5, str4);
//     PrintString(str1); //heeeeword
//     free(str1);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     int i;
//     double score[] = {98, 87, 65, 43, 76};
//     double *ptr_score = score;
//     printf("double型数组的地址占%d个字节\n", sizeof(score));
//     printf("double型数组的地址占%d个字节\n", sizeof(ptr_score));
//     printf("数组的首地址:%p\t数组首元素的地址:%p\n", score, &score[0]);
//     for (i = 0; i < 5; i++)
//     {
//         //printf("%.2lf\n",ptr_score[i]);
//         //printf("%.2lf\n",*ptr_score);
//         printf("%.2lf\n", *(ptr_score + i));
//         //printf("%.2lf\n",*ptr_score++);
//     }
// }

// typedef struct B
// {
//     union
//     {
//         int n;
//         char *c;
//     } Ls;
// } b;

// int main(int argc, char const *argv[])
// {
//     b bs;
//     bs.Ls.n = 1;
//     bs.Ls.c = "aaa";
//     cout << bs.Ls.n << "\n";
//     cout << bs.Ls.c;
//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// int a[55];
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     string res = "YES";
//     for (int i = 0; i < n; i++)
//     {
//         while (!(a[i] & 1))
//             a[i] >>= 1;
//     }
//     for (int i = 1; i < n; i++)
//     {
//         if (a[i] != a[0])
//             res = "NO";
//     }
//     cout << res << endl;
// }

#include <iostream>
using namespace std;
// int main()
// {
//     long long n; //这里题目要求的正整数范围是“一个正整数N(N <= 2,000,000)”，所以，要用精度更高的类型，用“int”会溢出。
//     cin >> n;
//     if (n == 1)
//     {
//         cout << "End" << endl;
//     }
//     else if (n % 2 == 0)
//     {
//         while (n % 2 == 0)
//         {
//             long long C;
//             C = n / 2;
//             cout << n << "/2=" << C << endl;
//             n = C;
//             if (n % 2 && n != 1)
//             {
//                 cout << n;
//                 n = n * 3 + 1;
//                 cout << "*3+1=" << n << endl;
//             }
//         }
//         cout << "End" << endl;
//     }
//     else
//     {
//         long long B;
//         B = n * 3 + 1;
//         cout << n << "*3+1=" << B << endl;
//         while (B % 2 == 0)
//         {
//             long long C;
//             C = B / 2;
//             cout << B << "/2=" << C << endl;
//             B = C;
//             if (B % 2 && B != 1)
//             {
//                 cout << B;
//                 B = B * 3 + 1;
//                 cout << "*3+1=" << B << endl;
//             }
//         }
//         cout << "End" << endl;
//     }
//     return 0;
// }

// void lg(long long n)
// {
//     if (n == 1)
//     {
//         printf("End\n");
//         return;
//     }
//     long long c;
//     if (n % 2 == 0)
//     {
//         c = n / 2;

//         printf("%lld/2=%lld\n",n,c);
//         lg(c);
//     }
//     else
//     {

//         printf("%lld", n);
//         n = n * 3 + 1;
//         printf("*3+1=%lld\n", n);

//         lg(n);
//     }
// }

// int main(int argc, char const *argv[])
// {
//     lg(159487);
//     return 0;
// }
// #include <iostream>
// using namespace std;
// int main()
// {
//     long long n; //这里题目要求的正整数范围是“一个正整数N(N <= 2,000,000)”，所以，要用精度更高的类型，用“int”会溢出。
//     cin >> n;
//     if (n == 1)
//     {
//         cout << "End" << endl;
//     }
//     else if (n % 2 == 0)
//     {
//         while (n % 2 == 0)
//         {
//             long long C;
//             C = n / 2;
//             cout << n << "/2=" << C << endl;
//             n = C;
//             if (n % 2 && n != 1)
//             {
//                 cout << n;
//                 n = n * 3 + 1;
//                 cout << "*3+1=" << n << endl;
//             }
//         }
//         cout << "End" << endl;
//     }
//     else
//     {
//         long long B;
//         B = n * 3 + 1;
//         cout << n << "*3+1=" << B << endl;
//         while (B % 2 == 0)
//         {
//             long long C;
//             C = B / 2;
//             cout << B << "/2=" << C << endl;
//             B = C;
//             if (B % 2 && B != 1)
//             {
//                 cout << B;
//                 B = B * 3 + 1;
//                 cout << "*3+1=" << B << endl;
//             }
//         }
//         cout << "End" << endl;
//     }
//     return 0;
// }

// int main(int argc, char const *argv[])
// {
//     int a = 0;
//     int b = 0;
//     while ((cin>>a>>b)&&(a || b))
//     {
//         cout <<"输出"<< a << " " << b;

//     }

//     cout << a << " " << b;
//     return 0;
// }


int main(int argc, char const *argv[])
{
   
    cout<< sqrt(9)<<endl;
    cout << pow(3,-2) << endl;
    return 0;
}
