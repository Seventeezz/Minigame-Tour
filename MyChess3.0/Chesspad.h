#pragma once
#include "Chess.h"
using namespace std;

class Chesspad
{
	public:
		Chesspad()
		{
			lastrow=0;
			lastcol=0;
			for(int i=0;i<19;i++)
			{
				for(int j=0;j<19;j++)
				chesspadstate[i][j]=0;
			}
		}
		void change_state(Chess);
		void givestate(int state[19][19]);
		
		
	
	
	private:
		int lastrow;
		int lastcol;
		int chesspadstate[19][19];
	
	
	
};








