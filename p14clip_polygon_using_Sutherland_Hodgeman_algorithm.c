/*Assignment No 14:==Implement Sutherland-Hodgeman
algorithm for Polygon Clipping*/
/*Example:enter number of
edges 4 enter coordinates
:x1,y1:100 100 x2,y2:300
100 x3,y3:300 200
x4,y4:100 200
enter top left window coordinate:150 75
enter length & width of window coordinate:200 150*/
#include <conio.h>
#include <iostream.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
float
    px[20],
    py[20], wx[4], wy[4], vx[20], vy[20];
int wl, wb, j, n;
void draw(float x[], float y[], int lim, int color)
{
    setcolor(color);
    for (int i = 0; i < lim - 1; i++)
    {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[lim - 1], y[lim - 1], x[0], y[0]);
    return;
}
void restore()
{
    n = j;
    for (int i = 0; i < j; i++)
    {
        px[i] = vx[i];
        py[i] = vy[i];
    }
    px[i] = px[0];
    py[i] = py[0];
    draw(wx, wy, 4, 4);
    draw(px, py, n, 14);
}
void left_clip()
{
    j = 0;
    for (int i = 0; i < n; i++)
    {
        if (px[i] <= wx[0] && px[i + 1] >= wx[0])
        {
            if (py[i] - py[i + 1] != 0)
                vy[j] = (py[i + 1] - py[i]) / (px[i + 1] - px[i]) * (wx[0] - px[i]) + py[i];
            else
                vy[j] = py[i];
            vx[j] = wx[0];
            j++;
            vx[j] = px[i + 1];
            vy[j] = py[i + 1];
            j++;
        }
        else if (px[i] >= wx[0] && px[i + 1] <= wx[0])
        {
            if (py[i] - py[i + 1] != 0)
                vy[j] = (py[i + 1] - py[i]) / (px[i + 1] - px[i]) * (wx[0] - px[i]) + py[i];
            else
                vy[j] = py[i];
            vx[j] = wx[0];
            j++;
        }
        else if (px[i] >= wx[0] && px[i + 1] >= wx[0])
        {
            vx[j] = px[i + 1];
            vy[j] = py[i + 1];
            j++;
        }
    }
    restore();
}
void right_clip()
{
    j = 0;
    for (int i = 0; i < n; i++)
    {
        if (px[i] >= wx[1] && px[i + 1] <= wx[1])
        {
            if (py[i] - py[i + 1] != 0)
                vy[j] = (py[i + 1] - py[i]) / (px[i + 1] - px[i]) * (wx[1] - px[i]) + py[i];
            else
                vy[j] = py[i];
            vx[j] = wx[1];
            j++;
            vx[j] = px[i + 1];
            vy[j] = py[i + 1];
            j++;
        }
        else if (px[i] <= wx[1] && px[i + 1] >= wx[1])
        {
            if (py[i] - py[i + 1] != 0)
                vy[j] = (py[i + 1] - py[i]) / (px[i + 1] - px[i]) * (wx[1] - px[i]) + py[i];
            else
                vy[j] = py[i];
            vx[j] = wx[1];
            j++;
        }
        else if (px[i] <= wx[1] && px[i + 1] <= wx[1])
        {
            vx[j] = px[i + 1];
            vy[j] = py[i + 1];
            j++;
        }
    }
    restore();
}
void top_clip()
{
    j = 0;
    for (int i = 0; i < n; i++)
    {
        if (py[i] <= wy[0] && py[i + 1] >= wy[0])
        {
            if (px[i] - px[i + 1] != 0)
                vx[j] = (px[i + 1] - px[i]) / (py[i + 1] - py[i]) * (wy[0] - py[i]) + px[i];
            else
                vx[j] = px[i];
            vy[j] = wy[0];
            j++;
            vx[j] = px[i + 1];
            vy[j] = py[i + 1];
            j++;
        }
        else if (py[i] >= wy[0] && py[i + 1] <= wy[0])
        {
            if (px[i] - px[i + 1] != 0)
vx[j]=(px[i+1]-px[i])/py[i+1]-py[i])*(wy[0]-py[i])+px[i];
            else
vx[j] = px[i];
            vy[j] = wy[0];
            j++;
        }
        else if (py[i] >= wy[0] && py[i + 1] >= wy[0])
        {
            vx[j] = px[i + 1];
            vy[j] = py[i + 1];
            j++;
        }
    }
    restore();
}
void bottom_clip()
{
    j = 0;
    for (int i = 0; i < n; i++)
    {
        if (py[i] >= wy[2] && py[i + 1] <= wy[2])
        {
            if (px[i] - px[i + 1] != 0)
vx[j] = (px[i + 1] - px[i]) / (py[i + 1] - py[i]) * (wy[2] - py[i]) + px[i];
            else
vx[j] = px[i];
            vy[j] = wy[2];
            j++;
            vx[j] = px[i + 1];
            vy[j] = py[i + 1];
            j++;
        }
        else if (py[i] <= wy[2] && py[i + 1] >= wy[2])
        {
            if (px[i] - px[i + 1] != 0)
vx[j] = (px[i + 1] - px[i]) / (py[i + 1] - py[i]) * (wy[2] - py[i]) + px[i];
            else
vx[j] = px[i];
            vy[j] = wy[2];
            j++;
        }
        else if (py[i] <= wy[2] && py[i + 1] <= wy[2])
        {
            vx[j] = px[i + 1];
            vy[j] = py[i + 1];
            j++;
        }
    }
    restore();
}
void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    setcolor(4);
    printf("enter the no of edges : ");
    scanf(“% d”, &n);
printf(”enter the coordinates : ");
for(int i=0;i<n;i++)
{
printf(“x"<<i+1<<" "<<"y"<<i+1<<" : ");
scanf(“%d,%d”,&px[i],&py[i]);
}
cleardevice();
draw(px,py,n,15)
;
prinft("enter top left window coordinate : ");
scanf(“%d%d”,&wx[0],&wy[0]);
printf("enter length & width of window : ");
scnaf(“%d%d”,&wl,&wb);
wx[1]=wx[0]+wl;
wy[1]=wy[0];
wx[2]=wx[0]+wl;
wy[2]=wy[0]+wb;
wx[3]=wx[0];
wy[3]=wy[0]+wb;
cleardevice();
draw(px,py,n,15);
draw(wx,wy,4,4);
getch();
cleardevice();
left_clip();
getch();
cleardevice();
right_clip();
getch();
cleardevice();
top_clip();
getch();
cleardevice();
bottom_clip();
getch();
closegraph();
}
