#pragma once
#include "Chesser.h"

class HumanChesser:public Chesser
{
	public:
	HumanChesser(int color,string name)
	{
		this->color=color;
		this->name=name;
	}
	virtual Chess givenext(int chesspadstate[19][19]);
	
};
