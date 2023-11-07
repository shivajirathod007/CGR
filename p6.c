
/* Experiment No 6:-Implement Scan_line algorithm for polygon
filling */
/* Example:- Enter vertices:-3
x[0]=100,y[0]=50,x[1]=150,y[1]=100,x[2]=50,y[2]=100*/
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
// Defining the structure to store edges-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
struct edge
{
    int x1;
    int y1;
    int x2;
    int y2;
    int flag;
};
void main()
{
    int gd = DETECT, gm, n, I, j, k;
    struct edge ed[10], temped;
    float dx, dy, m[10], x_int[10], inter_x[10];
    int x[10], y[10], ymax = 0, ymin = 480, yy, temp;
    initgraph(&gd, &gm, “c
              :\\turboc3\\bgi”);
    /* Read the number of vertices of the polygon
    ------------------------------------------------ */
    printf(“Enter the number vertices of the graph
           : “);
    scanf(“% d”, &n);
    /* Read the vertices of the polygon and also find Ymax and
   Ymin
    ------------------------------------------------------------
   --- */
    printf(“Enter the vertices
           : \n”);
    for (I = 0; I < n; i++)
    {
        printf(“x[% d]
               : “, i);
        scanf(“% d”, &x[i]);
        printf(“y[% d]
               : “, i);
        scanf(“% d”, &y[i]);
        if (y[i] > ymax)
            ymax = y[i];
        if (y[i] < ymin)
            ymin = y[i];

        ed[i].x1 = x[i];
        ed[i].y1 = y[i];
    }
    /* Store the edge information
    -------------------------------*/
    for (I = 0; I < n – 1; i++)
    {
        ed[i].x2 = ed[I + 1].x1;
        ed[i].y2 = ed[I + 1].y1;
        ed[i].flag = 0;
    }
    ed[i].x2 = ed[0].x1;
    ed[i].y2 = ed[0].y1;
    ed[i].flag = 0;
    /* Check for y1>y2, if not interchange y1 and y2
    with corresponding x1 and x2
    --------------------------------*/
    for (I = 0; I < n; i++)
    {
        if (ed[i].y1 < ed[i].y2)
        {
            temp = ed[i].x1;
            ed[i].x1 = ed[i].x2;
            ed[i].x2 = temp;
            temp = ed[i].y1;
            ed[i].y1 = ed[i].y2;
            ed[i].y2 = temp;
        }
    }
    /* Draw the polygon
    ---------------------- */
    for (I = 0; I < n; i++)
    {
        line(ed[i].x1, ed[i].y1, ed[i].x2, ed[i].y2);
    }
    /* sorting of edges in the order of y1,y2,x1
    --------------------------------------------- */
    for (I = 0; I < n – 1; i++)
    {
        for (j = 0; j < n – 1; j++)
        {
            if (ed[j].y1 < ed[j + 1].y1)
            {

                temped = ed[j];
                ed[j] = ed[j + 1];
                ed[j + 1] = temped;
            }
            if (ed[j].y1 == ed[j + 1].y1)
            {
                if (ed[j].y2 < ed[j + 1].y2)
                {
                    temped = ed[j];
                    ed[j] = ed[j + 1];
                    ed[j + 1] = temped;
                }
                if (ed[j].y2 == ed[j + 1].y2)
                {
                    if (ed[j].x1 < ed[j + 1].x1)
                    {
                        temped = ed[j];
                        ed[j] = ed[j + 1];
                        ed[j + 1] = temped;
                    }
                }
            }
        }
    }
    /* calculating 1/slope of each edge and storing top x
    coordinate of the edge --------------------------- */
    for (I = 0; I < n; i++)
    {
        dx = ed[i].x2 – ed[i].x1;
        dy = ed[i].y2 – ed[i].y1;
        if (dy == 0)
        {
            m[i] = 0;
        }
        else
        {
            m[i] = dx / dy;
        }
        inter_x[i] = ed[i].x1;
    }
    yy = ymax;
    while (yy > ymin)
    {
        /* Marking active egdes
        -------------------------- */

        for (I = 0; I < n; i++)
        {
            if (yy > ed[i].y2 && yy <= ed[i].y1 && ed[i].y1 != ed[i].y2)
            {
                ed[i].flag = 1;
            }
            else
            {
                ed[i].flag = 0;
            }
        }
        /* Finding the x intersections
        -------------------------------- */
        j = 0;
        for (I = 0; I < n; i++)
        {
            if (ed[i].flag == 1)
            {
                if (yy == ed[i].y1)
                {
                    x_int[j] = ed[i].x1;
                    j++;
                    if (ed[I – 1].y1 == yy && ed[I – 1].y1 < yy)
                    {
                        x_int[j] = ed[i].x1;
                        j++;
                    }
                    if (ed[I + 1].y1 == yy && ed[I + 1].y1 < yy)
                    {
                        x_int[j] = ed[i].x1;
                        j++;
                    }
                }
                else
                {
                    x_int[j] = inter_x[i] + (-m[i]);
                    inter_x[i] = x_int[j];
                    j++;
                }
            }
        }
        /* Sorting the x intersections
        --------------------------------*/
        for (I = 0; I < j; i++)

        {
            for (k = 0; k < j – 1; k++)
            {
                if (x_int[k] > x_int[k + 1])
                {
                    temp = x_int[k];
                    x_int[k] = x_int[k + 1];
                    x_int[k + 1] = temp;
                }
            }
        }
        /* Extracting pairs of x values to draw lines
        ---------------------------------------------- */
        for (I = 0; I < j; I += 2)
        {
            line(x_int[i], yy, x_int[I + 1], yy);
        }
        yy--;
        delay(50);
    }
    getch();
}
