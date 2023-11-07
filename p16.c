/*Assignment No 16:==Write a program to draw curve using Bezier's Algorithm.
Example:-
enter coordinates of 4 sides of polygon enter xy(first point):-150 100 enter xy(second point):-450 100
enter xy(third point):-450 300
enter xy(fourth point):-150 300
*/
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
void bezi(float x1[4], float y1[4]);
void init();
void main()
{
    float x1[4], y1[4], x, y;
    int gd = DETECT, gm, i;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    for (i = 0; i < 4; i++)
    {
        printf("enter x,y");
        scanf("%f%f", &x1[i], &y1[i]);
    }
    bezi(x1, y1);
    getch();
    closegraph();
}
void bezi(float x1[4], float y1[4])
{
    int x, y;
    float t = 0;
    for (t = 0; t <= 1; t = t + 0.00001)
    {
        x = x1[0] * pow((1 - t), 3) + 3 * x1[1] * t * pow((1 - t), 2) + 3 * x1[2] * pow(t, 2) * (1 - t) + x1[3] * pow(t, 3);
        y = y1[0] * pow((1 - t), 3) + 3 * y1[1] * t * pow((1 - t), 2) + 3 * y1[2] * pow(t, 2) * (1 - t) + y1[3] * pow(t, 3);
        putpixel(x, y, 14);
    }
}
