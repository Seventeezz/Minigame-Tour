#pragma once
#include "Chesser.h"
#include "AI.h"
using namespace std;

class AIChesser:public Chesser
{
	public:
		AIChesser(int color,string name)
		{
			this->color=color;
			this->name=name;
		}
		virtual Chess givenext(int chesspadstate[19][19]);
	private:
		AI computer;
	
};
