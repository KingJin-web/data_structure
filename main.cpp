#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
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


