#include <stdio.h>
#include <conio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
int area[80][23]={0};
int k,l;
int TailColum[300];
int TailRow[300];
int i;
int Continue=1;

void gotoxy(short x, short y) {
 HANDLE hConsoleOutput;
 COORD Cursor_Pos = {x-1, y-1};

 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}

void Case(int x1,int y1,int x2,int y2,int type)
{
	int i;
	for (i=x1;i<=x2;i++)
	{
		area[i][y1]=type;
		area[i][y2]=type;
	}
	
		for (i=y1;i<=y2;i++)
	{
		area[x1][i]=type;
		area[x2][i]=type;
	}
}
void writeScreen()
{

int x,y;
for (x=0;x<80;x++)
{
	for (y=0;y<23;y++)
	{
		gotoxy(x+1,y+1);
		if (area[x][y]==2)
		{
			printf("%c",176);
		}
		
	}
  }
}

int randomAssign()
{
	srand(time(NULL));
	k=4+rand()%65;
	l=4+rand()%15;
}



void main()
{
	randomAssign();
	Case(0,0,79,22,2);
    writeScreen();	
    int sx=40,sy=12;
	unsigned char key;
	int dy=0;
	int dx=0;
	int a=0;
	
	do{
		if(kbhit())
		{
			key=getch();
			if(key==224)
			{
				key=getch(); 
				switch(key)
				{
					case 72:dy=-1;dx=0;
					break;
					case 80:dy=1;dx=0;
					break;
					case 77:dx=1; dy=0;
					break;
					case 75: dx=-1; dy=0;
				} 
			}
		}
		sx=sx+dx;
		sy=sy+dy;
		if (sx>78)
		sx=2;
		if(sx<2)
		sx=78;
		if(sy>22)
		sy=2;
		if(sy<2)
		sy=22;
		
		TailColum[0]=sx;
		TailRow[0]=sy;			
		
     for(i=1;i<=a;i++)
	 {
	 	if(sx==TailColum[i]&&sy==TailRow[i])
	 	{
	 		gotoxy(sx,sy);
	 		printf("---Failed---");
	 		getch();
	 		Continue=0;
		 }
	 }
		
	gotoxy(sx,sy);printf("*");
	for(i=0;i<=a;i++)
	{
		gotoxy(TailColum[i],TailRow[i]);
		printf("*");
	}
			if(sx==k && sy==1)
		{
			randomAssign();
			a++;
			gotoxy(2,2);
			printf("Puan: %d",a);
		}
		gotoxy(k,l);
		printf("A");
	Sleep(60);
	gotoxy(sx,sy);printf(" ");
	
	for(i=0;i<=a;i++)
	{
		gotoxy(TailColum[i],TailRow[i]);
		printf(" ");
	}
	
	for(i=a;i>0;i--)
	{
		TailColum[i]=TailColum[i-1];
		TailRow[i]=TailRow[i-1];
	}
	
}while(Continue==1);

}
