// 3D Translation :
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
    int maxx,
    maxy,
    midx,
    midy;
void axis()
{
    cleardevice();
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);
}
void main()
{
    int x, y, z, o, x1, x2, y1, y2;
    int gd = DETECT, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy / 2;
    axis();
    bar3d(midx + 50, midy - 100, midx + 60, midy - 90, 10, 1);
    printf("Enter translation factor");
    scanf("%d%d", &x, &y);
    printf("After translation:");
    bar3d(midx + x + 50, midy - (y + 100), midx + x + 60, midy - (y + 90), 10, 1);
    getch();
    closegraph();
}

// 3D Scaling:
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
int maxx, maxy, midx, midy;
void axis()
{
    cleardevice();
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);
}
void main()
{
    int x, y, z, o, x1, x2, y1, y2;
    int gd = DETECT, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy / 2;
    axis();
    bar3d(midx + 50, midy - 100, midx + 60, midy - 90, 5, 1);
    printf("Enter scaling factors");
    scanf("%d%d%d", &x, &y, &z);
    printf("After scaling");
    bar3d(midx + (x * 50), midy - (y * 100), midx + (x * 60), midy - (y * 90), 5 * z, 1);
    getch();
    closegraph();
}