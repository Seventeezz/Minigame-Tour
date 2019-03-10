#include "KeyboardConsole.h"
#include <conio.h>
void KeyboardConsole::Move_and_Stop()
{
	int ch1,ch2;
	while(ch1=getch())
	{
		if(ch1==32)
		{
			return ;
		}
		ch2=getch();
		if(ch2==72&&x>=2)
		{
			x--;
		}
		else if(ch2==80&&x<=18)
		{
			x++;
		} 
		else if(ch2==75&&y>=4)
		{
			y-=2;
		}
		else if(ch2==77&&y<=38)
		{
			y+=2;
		}
		gotoxy(y,x);
	}
	
	
}
