#include "AIChesser.h"
using namespace std;

Chess AIChesser::givenext(int chesspadstate[19][19]) 
{
	Position position;
	position = computer.getPosition(chesspadstate, color);
	return Chess(color, position.x, position.y);//返回棋子对象
}
