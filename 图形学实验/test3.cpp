#pragma comment(lib, "winbgi.lib")

#include "graphics.h"
#include "conio.h"
#include "stdio.h"

typedef struct
{
    double x, y;
} DPOINT;

class Bezier
{
private:
    DPOINT *bP;
    int m_maxIndex;
    void drawFrame();
    void drawCurve();
    void drawCurve(int p0, int p1, int p2, int p3);

public:
    Bezier::Bezier(DPOINT *p, int len);
    void draw();
};

Bezier::Bezier(DPOINT *p, int len)
{
    this->bP = p;
    m_maxIndex = len - 1;
}

void Bezier::draw()
{
    drawFrame();
    drawCurve();
}

void Bezier::drawFrame()
{
    setcolor(12);
    for (int i = 0; i < m_maxIndex; i++)
    {
        line(bP[i].x, bP[i].y, bP[i + 1].x, bP[i + 1].y);
        circle(bP[i].x, bP[i].y, 5);
    }
    circle(bP[m_maxIndex].x, bP[m_maxIndex].y, 5);
}

void Bezier::drawCurve()
{
    for (int i = 0; i <= m_maxIndex - 3; i += 3)
    {
        drawCurve(i, i + 1, i + 2, i + 3);
    }
}

void Bezier::drawCurve(int p0, int p1, int p2, int p3)
{
    double tmpx = 0.0;
    double tmpy = 0.0;
    double t = 0.0;
    for (; t <= 1.0; t += 0.001)
    {
        tmpx = (-bP[p0].x + 3 * bP[p1].x - 3 * bP[p2].x + bP[p3].x) * t * t * t + (3 * bP[p0].x - 6 * bP[p1].x + 3 * bP[p2].x) * t * t + (-3 * bP[p0].x + 3 * bP[p1].x) * t + bP[p0].x;
        tmpy = (-bP[p0].y + 3 * bP[p1].y - 3 * bP[p2].y + bP[p3].y) * t * t * t + (3 * bP[p0].y - 6 * bP[p1].y + 3 * bP[p2].y) * t * t + (-3 * bP[p0].y + 3 * bP[p1].y) * t + bP[p0].y;
        putpixel(tmpx, tmpy, 3);
    }
}

void main()
{
    int graphdriver = DETECT, graphmode;
    initgraph(&graphdriver, &graphmode, "E:\\tc3\\bgi");
    setbkcolor(15);
    DPOINT *p;
    p = new DPOINT[10];
    p[0].x = 50.0;
    p[0].y = 100.0;
    p[1].x = 80.0;
    p[1].y = 230.0;
    p[2].x = 100.0;
    p[2].y = 270.0;
    p[3].x = 140.0;
    p[3].y = 160.0;
    p[4].x = 180.0;
    p[4].y = 50.0;
    p[5].x = 240.0;
    p[5].y = 65.0;
    p[6].x = 270.0;
    p[6].y = 120.0;
    p[7].x = 330.0;
    p[7].y = 230.0;
    p[8].x = 380.0;
    p[8].y = 230.0;
    p[9].x = 430.0;
    p[9].y = 150.0;
    Bezier bzr(p, 10);
    bzr.draw();
    delete p;
    getch();
    closegraph();
}