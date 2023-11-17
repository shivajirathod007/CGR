/* Implement FloodFill Algorithm for polygon
filling(8connected region)
*/
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
void main()
{
    int gd = DETECT, gm;
    void flood(int, int, int, int);
    /* Initialise graphics mode
    ---------------------------------- */
    initgraph(&gd, &gm, “c
              :\\turboc3\\bgi”);
    rectangle(50, 50, 100, 100);
    flood(55, 55, 4, 15);
    getch();
    closegraph();
}
void flood(seed_x, seed_y, foreground_col, background_col)
{
    if (getpixel(seed_x, seed_y) != background_col &&
        getpixel(seed_x, seed_y) != foreground_col)
    {
        delay(2);
        putpixel(seed_x, seed_y, foreground_col);
        flood(seed_x + 1, seed_y, foreground_col, background_col);
        flood(seed_x – 1, seed_y, foreground_col, background_col);
        flood(seed_x, seed_y + 1, foreground_col, background_col);
        flood(seed_x, seed_y – 1, foreground_col, background_col);
        flood(seed_x + 1, seed_y + 1, foreground_col,
              background_col);
        flood(seed_x – 1, seed_y – 1, foreground_col,
              background_col);
        flood(seed_x + 1, seed_y – 1, foreground_col,
              background_col);
        flood(seed_x – 1, seed_y + 1, foreground_col,
              background_col);
    }
}
