#include <bits/stdc++.h>
// int main(int argc, char const *argv[])
// {

//     int i = 5;
//     int j = 5;
//     int a = (i++) + (i++) + (i++);
//     int b = (++j) + (++j) + (++j);

//     printf("%d\n", a);
//     printf("%d\n", b);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define N 5
// int main()
// {
//     int i;
//     int sum = 0;
//     double avg;
//     int searchNum;
//     int nums[] = {8, 4, 2, 1, 23, 344, 12};
//     printf("输出数组元素:\n");

//     for (i = 0; i < 7; i++)
//     {
//         printf("%d\t", nums[i]);
//     }
//     printf("\n*******************\n");
//     for (i = 0; i < 7; i++)
//     {
//         sum += nums[i];
//     }
//     avg = sum / 7.0;
//     printf("请输入要查找的数字:");
//     scanf("%d", &searchNum);
//     for (i = 0; i < 7; i++)
//     {
//         if (searchNum == nums[i])
//             ;
//         {
//             printf("缘分啊,找到了相同的元素!\n");
//             break;
//         }
//     }
//     if (i == 7)
//     {
//         printf("茫茫人海,没有找到合意的数字!\n");
//     }
// }

// #define a "你好"
// #define AREA(a, b) a + b
// int main(int argc, char const *argv[])
// {
//     int s = AREA(3, 4) * AREA(3, 4);
//     return 0;
// }

// union uni
// {
//     int a;
//     char b;
// };
// struct str
// {
//     int a;
//     char b;
// };
// int main(int argc, char **argv)
// {
//     printf("%d %d\n", sizeof(union uni), sizeof(struct str));
//     return 0;
// }

// #include <stdio.h>
// #pragma pack(2)
// struct A
// {
//     int a;
//     char b;
//     short c;
// } A;
// #pragma pack()

// #pragma pack(4)
// struct B
// {
//     char b;
//     int a;
//     short c;
// } B;
// #pragma pack()

// int main()
// {
//     printf("sizeof(A) = % d, sizeof(B) = % d\n", sizeof(A), sizeof(B));
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define N 5
// int main()
// {
//     int array[N] = {15, 20, 25, 30, 35};
//     //实现数组的逆序-原理就是数组的首位元素进行交换
//     int temp; //临时变量
//     int i;
//     int *ptr_array_start = array;       //指向数组首元素的指针
//     int *ptr_array_end = array + N - 1; //指向数组末元素的指针
//     while (ptr_array_start != ptr_array_end)
//     {
//         //首位交换，指针分别进行更新
//         temp = *ptr_array_start;
//         *ptr_array_end = temp;
//         //首元素指针要向后移动
//         ptr_array_start++;
//         //末元素指针要向前移动
//         ptr_array_end--;
//     }
//     /*for(i=0;i<N/2;i++)
//     {
//         //第i个的值和第N-i-1个值交换
//        // temp=array[i];
//        // array[i]=array[N-i-1];
//        // array[N-i-1]=temp;

//     }*/
//     printf("\n");
//     for (i = 0; i < N; i++)
//     {
//         printf("%d\t", *(array + i));
//     }
// }
// struct A
// {
//     unsigned int a;
//     char b[2];
//     double c;
//     short d;
// } Aa;

// int
// main(int argc, char const *argv[])
// {

//     printf("sizeof(A) = % d, sizeof(B) = % d\n", sizeof(Aa), sizeof(Aa.d));

//     return 0;
// }
// #include <stdlib.h>
// #define DECLARE(name, type) type name##_##type##_type
// int main(void)
// {

//     return 0;
// }

// /* 初始化材料属性、光源属性、光照模型，打开深度缓冲区 */
// void init(void)
// {
//     GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
//     GLfloat mat_shininess[] = {50.0};
//     GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

//     glClearColor(0.0, 0.0, 0.0, 0.0);
//     glShadeModel(GL_SMOOTH);

//     glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//     glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//     glLightfv(GL_LIGHT0, GL_POSITION, light_position);

//     glEnable(GL_LIGHTING);
//     glEnable(GL_LIGHT0);
//     glEnable(GL_DEPTH_TEST);
// }

// /*调用GLUT函数，绘制一个球*/
// void display(void)
// {
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//     glutSolidSphere(1.0, 40, 50);
//     glFlush();
// }

// /* 定义GLUT的reshape函数，w、h分别是当前窗口的宽和高*/
// void reshape(int w, int h)
// {
//     glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     if (w <= h)
//         glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w, 1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
//     else
//         glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();
// }

// /* 定义对键盘的响应函数 */
// void keyboard(unsigned char key, int x, int y)
// {
//     /*按Esc键退出*/
//     switch (key)
//     {
//     case 27:
//         exit(0);
//         break;
//     }
// }

// int main(int argc, char **argv)
// {
//     /* GLUT环境初始化*/
//     glutInit(&argc, argv);
//     /* 显示模式初始化 */
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//     /* 定义窗口大小 */
//     glutInitWindowSize(300, 300);
//     /* 定义窗口位置 */
//     glutInitWindowPosition(100, 100);
//     /* 显示窗口，窗口标题为执行函数名 */
//     glutCreateWindow(argv[0]);
//     /* 调用OpenGL初始化函数 */
//     init();
//     /* 注册OpenGL绘图函数 */
//     glutDisplayFunc(display);
//     /* 注册窗口大小改变时的响应函数 */
//     glutReshapeFunc(reshape);
//     /* 注册键盘响应函数 */
//     glutKeyboardFunc(keyboard);
//     /* 进入GLUT消息循环，开始执行程序 */
//     glutMainLoop();
//     return 0;
// }

#include <stdio.h>