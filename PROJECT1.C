#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
void drawstars();
void drawroad();
void drawstreetlights();
void main()
{
    int gd=DETECT, gm;
    clrscr();
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    printf("Width=%d",getmaxx());
    printf("\nHeight=%d",getmaxy());

    /* Draw the sky */
    setbkcolor(BLACK);
    cleardevice();

    /* Draw the moon */
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(500, 80, 35);
    floodfill(500, 80, WHITE);

    /* Draw stars */
    drawstars();

    //draw street lights
    drawstreetlights();

    /* Draw road */
    drawroad();

    /* Display project title */
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(250, 270, "NIGHT VIEW ");

    getch();
    closegraph();
}
void drawstars()
{
    int i, x, y;
    randomize();
    for(i=0; i<200; i++)
    {
	x=random(getmaxx()+1);
	y=random(280);

	putpixel(x, y, WHITE);
    }
}
void drawroad()
{
    int mid;
    int road[8];
    int y, w, h;
    mid = getmaxx()/2;

    /* Draw wide perspective road */
    road[0] = mid-70;
    road[1] = 300;

    road[2] = mid+70;
    road[3] = 300;

    road[4] = getmaxx();
    road[5] = getmaxy();

    road[6] = 0;
    road[7] = getmaxy();

    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    fillpoly(4, road);

    /* Road edges */
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);

    line(mid-70,300,0,getmaxy());
    line(mid+70,300,getmaxx(),getmaxy());

    /* Large centre markings */
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);

    bar(mid-2, 320, mid+2, 330);
    bar(mid-4, 350, mid+4, 370);
    bar(mid-7, 390, mid+7, 420);
    bar(mid-10, 445, mid+10, 479);
}
void drawstreetlights()
{
    int mid;
    mid = getmaxx()/2;
    /* LEFT STREETLIGHT */

    /* Pole */
    setcolor(LIGHTGRAY);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(mid-180, 220, mid-180, 350);

    /* Lamp holder */
    line(mid-180,220,mid-160,220);

    /* Yellow lamp */
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(mid-155,220,10,6);

    /* Light glow */
    setcolor(WHITE);
    circle(mid-155,220,15);
    circle(mid-155,220,22);

    /* RIGHT STREETLIGHT */

    /* Pole */
    setcolor(LIGHTGRAY);
    line(mid+180,220,mid+180,350);

    /* Lamp holder */
    line(mid+180,220,mid+160,220);

    /* Yellow lamp */
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,YELLOW);
    fillellipse(mid+155,220,10,6);

    /* Light glow */
    setcolor(WHITE);
    circle(mid+155,220,15);
    circle(mid+155,220,22);
}
