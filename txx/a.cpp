#include "graphics.h"
#include "stdlib.h"
#include "conio.h"
#include "stdio.h"

#pragma comment(lib, "wingbi.lib")

int main()
{

    void *w;
    int s = 70;
    int driver = DETECT, mode = 0, i, start, end, j;
    initgraph(&driver, &mode, " ");
    cleardevice();
    setbkcolor(0);
    setcolor(CGA - LIGHTGREEN);
    start = 0;
    end = 180;

    circle(457, 290, 37);
    circle(595, 290, 37);
    line(474, 217, 468, 230);
    line(506, 217, 499, 230);
    line(468, 230, 499, 230);
    line(483, 230, 457, 290);
    line(457, 290, 595, 290);
    line(478, 243, 554, 243);
    line(457, 290, 554, 243);
    line(554, 243, 595, 290);
    line(514, 290, 554, 243);
    line(514, 290, 516, 279);
    line(514, 290, 513, 300);
    line(508, 277, 514, 278);
    line(505, 300, 521, 301);
    line(554, 243, 557, 233);
    line(542, 233, 572, 233);
    w = malloc(imagesize(350 + s, 200, 562 + s, 327));
    getimage(350 + s, 200, 562 + s, 327, w);

    for (i = 420, j = 0; i > 0; i--, j--)
    {
        setfillstyle(EMPTY_FILL, 0);
        pieslice(457 + j, 290, start, end, 37);
        pieslice(595 + j, 290, start, end, 37);
        start += 40;
        end += 40;
        delay(5);
        putimage(i - 1, 200, w, COPY_PUT);
        line(2, 327, 632 + s, 327);
        delay(10);
    }

    for (i = 0; i < 10; i++)
    {
        pieslice(37, 290, start, end, 37);
        pieslice(175, 290, start, end, 37);
        start += 40;
        end += 40;
    }

    getch();
    restorecrtmode();
    closegraph();
}