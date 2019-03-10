#include "Chesspad.h"

using namespace std;

void Chesspad::change_state(Chess chess)//chess�������� 
{
	if(chesspadstate[lastrow][lastcol])
	{
		chesspadstate[lastrow][lastcol]-=2;
	}
	chess.update_pos(lastrow,lastcol);//���������ӵ�λ�ã����������һ���µ�����
	if(chess.getcolor())//����ǰ���
	{
		chesspadstate[lastrow][lastcol]=4;
	} 
	else
	{
		chesspadstate[lastrow][lastcol]=3;
	}
	
	
	
}

void Chesspad::givestate(int state[19][19])
{
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			state[i][j]=chesspadstate[i][j];
		}
	}
}



