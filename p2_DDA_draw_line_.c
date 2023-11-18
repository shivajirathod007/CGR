#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
void main()
{
    float x, y, x1, y1, x2, y2, dx, dy, length;
    int I, gd = DETECT, gm;
    clrscr();
    /* Read two end points of line
   ---------------------------------- */
    printf(“Enter the value of x1
           :\t”);
    scanf(“% f”, &x1);
    printf(“Enter the value of y1
           :\t”);
    scanf(“% f”, &y1);
    printf(“Enter the value of x2
           :\t”);
    scanf(“% f”, &x2);
    printf(“Enter the value of y2
           :\t”);
    scanf(“% f”, &y2);
    /* Initialise graphics mode
    ---------------------------------- */
    // detectgraph(&gd,&gm);
    initgraph(&gd, &gm,”C
              :\\turboc3\\BGI”);
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (dx >= dy)
    {
        length = dx;
    }
    else
    {
        length = dy;
    }
    dx = (x2 - x1) / length;
    dy = (y2 - y1) / length;
    x = x1 + 0.5; /* Factor 0.5 is added to round
   the values */
    y = y1 + 0.5; /* Factor 0.5 is added to round
   the values */
    
        I = 1; /* Initialise loop counter */
    while (I <= length)
    {
        putpixel(x, y, 15);  // x&y are coordinates & the 15 is the color of o/p
        x = x + dx;
        y = y + dy;
        I = I + 1;
        delay(100); /* Delay is purposely inserted to see
         observe the line drawing process */
    }
    getch();
    closegraph();
}
