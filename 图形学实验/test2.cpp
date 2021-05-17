#include "graphics.h"
#include <conio.h>
#include <math.h>
#include <stdio.h>

#pragma comment(lib, "winbgi.lib")

#define G 0.618
#define PAI 3.1415926

#define MAX 50
#define PI 3.1415926

float theta = 60.0;

void diamond(int n, double r, int x0, int y0)
{
    double x[MAX], y[MAX];
    int i, j;
    double theta;
    theta = 2.0 * PI / n;
    for (i = 0; i < n; i++)
    {
        x[i] = x0 + r * cos(theta * (i + 1));
        y[i] = y0 - r * sin(theta * (i + 1));
    }
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            line((int)x[i], (int)y[i], (int)x[j], (int)y[j]);
}

void tree(int x, int y, float lenth, float fai)
{
    int x1, y1;
    int nx, ny, count;
    float nlenth;
    x1 = x + lenth * cos(fai * PAI / 180.0);
    y1 = y - lenth * sin(fai * PAI / 180.0);
    line(x, y, x1, y1);
    if (lenth < 10)
        return;
    nlenth = lenth;
    nx = x;
    ny = y;
    for (count = 0; count < 7; count++)
    {
        nx = nx + nlenth * (1 - G) * cos(fai * PAI / 180.0);
        ny = ny - nlenth * (1 - G) * sin(fai * PAI / 180.0);
        tree(nx, ny, nlenth * (1 - G), fai + theta);
        tree(nx, ny, nlenth * (1 - G), fai - theta);
        nlenth *= G;
    }
}

void fishingnet(int r, int x0, int y0)
{
    int x, y, x1, y1;
    int i, j, n = 5;
    line(-1, -1, -1, -1);
    for (i = 0; i <= 2 * n; i++)
    {
        x1 = x0 - i * r;
        y1 = y0 + i * r;
        for (j = 0; j <= n - 1; j++)
        {
            x = x1 + 2 * j * r;
            y = y1 + 2 * j * r;
            arc(x, y, 180, 270, r);
            arc(x, y + 2 * r, 0, 90, r);
        }
    }
    x1 = x0 - 2 * r;
    y1 = y0;
    for (i = 0; i <= 2 * n; i++)
    {
        x1 = x1 + r;
        y1 = y1 + r;
        for (j = 0; j <= n - 1; j++)
        {
            x = x1 - 2 * j * r;
            y = y1 + 2 * j * r;
            arc(x, y, 90, 180, r);
            arc(x - 2 * r, y, 270, 360, r);
        }
    }
}

void main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "C:\\TC");
    diamond(15, 100.0, 120, 200);
    fishingnet(15, 360, 150);
    tree(500, 300, 280.0, 90.0);
    getch();
    closegraph();
}