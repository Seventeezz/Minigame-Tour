#include "HumanChesser.h"
#include <iostream>
#include "KeyboardConsole.h"
using namespace std;
Chess HumanChesser::givenext(int chesspadstate[19][19])
{
	int x,y;
	char a,b;

	cout<<"��ͨ�������������ҿ��ƹ��,���ո�����";
	KeyboardConsole cursor;
	while(1)
	{
		
		cursor.Move_and_Stop();
		x=cursor.getx()-1;
		y=cursor.gety()/2-1;
		if(chesspadstate[x][y])//����Ѿ���������
		{
			cursor.gotoxy(0,24);
			cout<<"�ô���������,���±�"<<endl;
			cursor.gotoxy(2,1);
			continue;
		} 
		else
			break;
		
		
		
	} 
	return Chess(color,x,y);
	
	
}
