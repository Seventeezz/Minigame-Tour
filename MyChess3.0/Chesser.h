#pragma once
#include "Chess.h" 
#include <string>
using namespace std;
/*Chesser作为虚基类，提供继承（因为会有人类棋手和AI棋手）*/ 
class Chesser 
{
	public:
		virtual Chess givenext(int chesspadstate[19][19])=0;//根据棋盘状态给定棋子 
	
	
	
	protected:
		int color;//0代表黑色，1代表白色 
		string name;
		
	
};
