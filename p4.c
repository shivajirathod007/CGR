// Circle using DDA Algorithm
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
void main()
{
    float x1, y1, x2, y2, startx, starty, epsilon;
    int gd = DETECT, gm, I, val;
    int r;
    clrscr();
    printf(“Enter the radius of a circle
           :”);
    scanf(“% d”, &r);
    /* Initialise graphics mode
    ---------------------------------- */
    initgraph(&gd, &gm,”c
              :\\turboc3\\bgi”);
    /* Initialise starting point
    -------------------------------- */
    x1 = r * cos(0);
    y1 = r * sin(0);
    startx = x1;
    starty = y1;
    /*Calculations for epsilon
   -----------------------------*/
    i = 0;
    do
    {
        val = pow(2, i);
        i++;
    } while (val < r);
    epsilon = 1 / pow(2, i - 1);
    do
    {
        x2 = x1 + y1 * epsilon;
        y2 = y1 – epsilon * x2;
        putpixel(200 + x2, 200 + y2, 15);
        /* Reinitialise the current point
        ---------------------------------- */
        x1 = x2;
        y1 = y2;
        delay(100); /* Delay is purposely inserted to see
        observe the line drawing process */
    } while ((y1 – starty) < epsilon || (startx – x1) > epsilon);
    getch();
    closegraph();
}

// Circle using the Bresenham’s Algorithm
// Program: -
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
void main()
{
    float d;
    int gd = DETECT, gm, x, y;
    int r;
    clrscr();
    /* Read the radius of the circle
    ---------------------------------- */
    printf(“Enter the radius of a circle
           :”);
    scanf(“% d”, &r);
    /* Initialise graphics mode
    ------------------------------*/
    initgraph(&gd, &gm,”c
              :\\turboc3\\bgi”);
    /* Initialise starting points
    -------------------------------*/
    x = 0;
    y = r;
    /* initialise the decision variable
    ---------------------------------------*/
    d = 3 – 2 * r;
    do
    {
        putpixel(200 + x, 200 + y, 15);
        putpixel(200 + y, 200 + x, 15);
        putpixel(200 + y, 200 - x, 15);
        putpixel(200 + x, 200 - y, 15);
        putpixel(200 - x, 200 - y, 15);
        putpixel(200 - y, 200 - x, 15);
        putpixel(200 - y, 200 + x, 15);
        putpixel(200 - x, 200 + y, 15);
        if (d <= 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y = y – 1;
        }
        x = x + 1;
        delay(50); /* Delay is purposely inserted to see
        observe the line drawing process */
    } while (x < y);
    getch();
    closegraph();
}
