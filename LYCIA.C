#include<stdio.h>
#include<dos.h>
#include<graphics.h>

int initmouse();
void mouseclk(int *button);
void drawScreen(int screen);
void drawConsole();
void rect(int left,int top,int right,int bottom,int color);
void cir(int x,int y,int radius,int color);

union REGS i,o;

int main()
{
	int status,gd=DETECT,gm;
	int button,pressed=0;
	int screen=0;
	char msg[100];
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
		mouseclk(&button);
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

void cir(int x,int y,int radius,int color)
{
	setcolor(BLACK);
	circle(x,y,radius);
	setfillstyle(SOLID_FILL,color);
	floodfill(x,y,BLACK);
}

void drawConsole()
{
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,639,479);

	rect(10,110,630,370,LIGHTGRAY);
	rect(150,130,490,350,DARKGRAY);
	//dpad
	rect(68,204,92,228,DARKGRAY);
	rect(68,252,92,276,DARKGRAY);
	rect(44,228,68,252,DARKGRAY);
	rect(92,228,116,252,DARKGRAY);
	rect(68,228,92,252,DARKGRAY);
	rect(515,310,555,320,DARKGRAY);//select button
	rect(570,310,610,320,DARKGRAY);//start button
	cir(570,225,16,RED);//A button
	cir(535,255,16,RED);//B button
	//line
	setcolor(DARKGRAY);
	setlinestyle(SOLID_LINE,0,3);
	line(60,300,75,340);
	line(75,300,90,340);
	line(90,300,105,340);
	setlinestyle(SOLID_LINE,0,1);
	//texts
	setcolor(RED);
	outtextxy(290,357,"NOAKI 01");
	outtextxy(515,325,"SELECT");
	outtextxy(570,325,"START");
	setcolor(BLACK);
	outtextxy(568,222,"A");
	outtextxy(533,252,"B");
}

void drawScreen(int screen)
{
	if(screen==1)
	{
		cir(160,140,5,RED);
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
		rect(220,210,240,272,BROWN);
		rect(190,180,270,210,GREEN);
		rect(205,160,255,180,GREEN);
		//sun
		cir(420,170,15,YELLOW);
		//humanoid
		rect(290,200,310,220,LIGHTRED);
		rect(285,220,315,245,BLUE);
		rect(275,220,285,250,BLUE);//left hand
		rect(315,220,325,250,BLUE);//right hand
		rect(285,245,300,272,LIGHTBLUE);//left leg
		rect(300,245,315,272,LIGHTBLUE);//right leg
	}else
	{
		cir(160,140,5,LIGHTGRAY);
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