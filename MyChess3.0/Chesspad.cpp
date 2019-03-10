#include "Chesspad.h"

using namespace std;

void Chesspad::change_state(Chess chess)//chess是新棋子 
{
	if(chesspadstate[lastrow][lastcol])
	{
		chesspadstate[lastrow][lastcol]-=2;
	}
	chess.update_pos(lastrow,lastcol);//根据新棋子的位置，将其变成最后一次下的棋子
	if(chess.getcolor())//如果是白棋
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



