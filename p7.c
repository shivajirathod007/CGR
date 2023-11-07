/*Experiment No7&8 :==Write A Program for 2D Transformation
(Translation,Scaling,Rotation)*/
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
void main()
{
    int I, gd, gm, choice;
    char ch;
    void translation();
    void scaling();
    void rotation();
    clrscr();
    /* initialise graphics */
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    do
    {
        printf(“\n 1
               : Translation \n 2
               : Scaling \n 3
               : rotation”);
        printf(“\n Enter choice
               :”);
        scanf(“% d”, &choice);
        switch (choice)
        {
        case 1:
            translation();
            break;
        case 2:
            scaling();
            break;
        case 3:
            rotation();
            break;
        }
        printf("\n Do youwant to Continue(y / n)
               :");
        scanf(“% s”, &ch);
    } while (ch != ‘n’);
    getch();
    closegraph();
}
void translation()
{
    int x1, y1, x2, y2;
    int x11, y11, x22, y22;

    int tx, ty;
    /* Read the x1,y1,x2,y2 line endpoints */
    cleardevice();
    printf(“Enter the x1, y1
           : = >”);
    scanf(“% d % d”, &x1, &y1);
    printf(“Enter the x2, y2
           :”);
    scanf(“% d % d”, &x2, &y2);
    line(x1, y1, x2, y2);
    printf(“Enter the x & y distances(tx, ty) to move object
           :”);
    scanf(“% d % d”, &tx, &ty);
    x11 = x1 + tx;
    y11 = y1 + ty;
    x22 = x2 + tx;
    y22 = y2 + ty;
    line(x11, y11, x22, y22);
}
void scaling()
{
    int x1, y1, x2, y2;
    int x11, y11, x22, y22;
    int sx, sy;
    /* Read the x1,y1,x2,y2 line endpoints */
    cleardevice();
    printf(“Enter the x1, y1
           : = >”);
    scanf(“% d % d”, &x1, &y1);
    printf(“Enter the x2, y2
           :”);
    scanf(“% d % d”, &x2, &y2);
    line(x1, y1, x2, y2);
    printf(“Enter the x & y distances to scale(sx, sy) object
           :”);
    scanf(“% d % d”, &sx, &sy);
    x11 = x1 * sx;
    y11 = y1 * sy;
    x22 = x2 * sx;
    y22 = y2 * sy;
    line(x11, y11, x22, y22);
}
void rotation()
{
    int x1, y1, x2, y2;
    int x11, y11, x22, y22, a;
    float theta;
    /* Read the x1,y1,x2,y2 line endpoints- */
    cleardevice();
    printf(“Enter the x1, y1
           : = >”);
    scanf(“% d % d”, &x1, &y1);
    printf("Enter the x2,y2:==>");

    scanf("%d%d", &x2, &y2);
    line(x1, y1, x2, y2);
    printf("Enter Rotation angle:==>");
    scanf("%d", &a);
    theta = ((a * 3.14) / 180);
    x11 = x1 * cos(theta) - y1 * sin(theta);
    y11 = x1 * sin(theta) + y1 * cos(theta);
    x22 = x2 * cos(theta) - y2 * sin(theta);
    y22 = x2 * sin(theta) + y2 * cos(theta);
    line(x11, y11, x22, y22);
}
