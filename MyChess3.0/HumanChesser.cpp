#include "HumanChesser.h"
#include <iostream>
#include "KeyboardConsole.h"
using namespace std;
Chess HumanChesser::givenext(int chesspadstate[19][19])
{
	int x,y;
	char a,b;

	cout<<"请通过键盘上下左右控制光标,按空格落子";
	KeyboardConsole cursor;
	while(1)
	{
		
		cursor.Move_and_Stop();
		x=cursor.getx()-1;
		y=cursor.gety()/2-1;
		if(chesspadstate[x][y])//如果已经有棋子了
		{
			cursor.gotoxy(0,24);
			cout<<"该处已有棋子,请下别处"<<endl;
			cursor.gotoxy(2,1);
			continue;
		} 
		else
			break;
		
		
		
	} 
	return Chess(color,x,y);
	
	
}
