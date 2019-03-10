#pragma once
#include <windows.h>
class KeyboardConsole
{
	public:
		KeyboardConsole()
		{
			x=10;
			y=20;
			gotoxy(y,x);
		}
		void Move_and_Stop();
		int getx()
		{
			return x;
		}
		int gety()
		{
			return y;
		}
		void gotoxy(int x,int y)
		{
			COORD pos={x,y};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
		}
	private:
		int x,y;
		
	
	
};



