#include<stdio.h>
#include<dos.h>
#include<graphics.h>

int initmouse();
void mouseclk(int *button);
void drawScreen(int screen);
void drawConsole();

union REGS i,o;

int main()
{
	int status,gd=DETECT,gm;
	int button,pressed=0;
	int screen=0;
	clrscr();
	initgraph(&gd,&gm,"C:\\BGI");
	status=initmouse();
	if(status==0)
	{
		printf("Mouse Not Connected");
		getch();
		exit(0);
	}
	else
	{
		drawConsole();
		drawScreen(screen);
		while(!kbhit())
		{
			mouseclk(&button);
			if(button==1 && pressed==0)
			{
				pressed=1;
				screen=!screen;
				drawScreen(screen);
			}
			if(button==0)
			{
				pressed=0;
			}
		}
	}
	getch();
	closegraph();
	return 0;
}

void rect(int left,int top,int right,int bottom,int color)
{
	setcolor(BLACK);
	rectangle(left,top,right,bottom);
	setfillstyle(SOLID_FILL,color);
	floodfill((left+right)/2,(top+bottom)/2,BLACK);
}

void drawConsole()
{
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,639,479);

	rect(10,110,630,370,LIGHTGRAY);

	rect(150,130,490,350,DARKGRAY);

	setcolor(RED);
	outtextxy(290,357,"LYCIA 01");
}

void drawScreen(int screen)
{
	if(screen==1)
	{
		//border
		rect(169,147,471,333,BLACK);
		//sky
		setfillstyle(SOLID_FILL,LIGHTCYAN);
		bar(170,148,470,272);
		//grass
		setfillstyle(SOLID_FILL,GREEN);
		bar(170,272,470,332);
		setcolor(BLACK);
		line(170,272,470,272);
		//tree
		rect(220,225,240,272,BROWN);
		rect(190,200,270,225,GREEN);
		rect(205,175,255,200,GREEN);
		//sun
		setcolor(BLACK);
		circle(420,180,20);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(420,180,BLACK);
	}else
	{
		setfillstyle(SOLID_FILL,BLACK);
		bar(170,148,470,332);
	}
}

//mouse functions
int initmouse()
{
	i.x.ax=0;
	int86(0X33,&i,&o);
	return(o.x.ax);
}

void mouseclk(int *button)
{
	i.x.ax=3;
	int86(0X33,&i,&o);
	*button=o.x.bx;
}