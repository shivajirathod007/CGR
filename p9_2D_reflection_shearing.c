#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
void main()
{
    int i, gd = DETECT, gm, choice;
    char ch;
    void translation();
    void x_shear();
    void y_shear();
    clrscr();
    /* initialise graphics
    ------------------------ */
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    do
    {
        printf("\n 1:==>Translation \n 2:==>X-Shear \n 3:==>YShear \n ");
        printf("Enter choice:==>");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            translation();
            break;
        case 2:
            x_shear();
            break;
        case 3:
            y_shear();
            break;
        }
        printf("\n Do youwant to Continue(y/n):==>");
        scanf("%s", &ch);
    } while (ch != 'n');
    getch();
    closegraph();
}
void x_shear()
{

    float x1 = 10, y1 = 10, x2 = 100, y2 = 10, x3 = 10, y3 = 100;
    float x11, y11, x22, y22, x33, y33, tx, ty;
    float shx;
    cleardevice();
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
 printf("Enter the x-shear (shx) to move object to left and 
right:==>");
 scanf("%f", &shx);
 x11 = x1 + shx * y1;
 y11 = y1;
 x22 = x2 + shx * y2;
 y22 = y2;
 x33 = x3 + shx * y3;
 y33 = y3;
 line(x11, y11, x22, y22);
 line(x22, y22, x33, y33);
 line(x33, y33, x11, y11);
}
void y_shear()
{
 float x1 = 10, y1 = 10, x2 = 100, y2 = 10, x3 = 10, y3 = 100;
 float x11, y11, x22, y22, x33, y33, tx, ty;
 float shy;
 cleardevice();
 line(x1, y1, x2, y2);
 line(x2, y2, x3, y3);
 line(x3, y3, x1, y1);
 printf("Enter the y-shear(shy) to move object to up and down 
:==>");
 scanf("%f", &shy);
 x11 = x1;
 y11 = y1 + shy * x1;
 x22 = x2;
 y22 = y2 + shy * x2;
 x33 = x3;
 y33 = y3 + shy * x3;
 line(x11, y11, x22, y22);
 line(x22, y22, x33, y33);
 line(x33, y33, x11, y11);
}

void translation()
{
 int x1 = 10, y1 = 10, x2 = 100, y2 = 10, x3 = 10, y3 = 100;
 int x11, y11, x22, y22, x33, y33, tx, ty;
 cleardevice();
 line(x1, y1, x2, y2);
 line(x2, y2, x3, y3);
 line(x3, y3, x1, y1);
 printf("Enter translation distance tx :==>");
 scanf("%d", &tx);
 printf("Enter translation distance ty :==>");
 scanf("%d", &ty);
 x11 = x1 + tx;
 y11 = y1 + ty;
 x22 = x2 + tx;
 y22 = y2 + ty;
 x33 = x3 + tx;
 y33 = y3 + ty;
 line(x11, y11, x22, y22);
 line(x22, y22, x33, y33);
 line(x33, y33, x11, y11);
}
