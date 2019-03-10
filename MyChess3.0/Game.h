#pragma once
#include <string> 
#include "Resultdisplay.h"
#include "Chesser.h"
#include "HumanChesser.h"
#include "Chess.h"
#include "Chesspad.h"
#include "Judge.h"
#include "AIChesser.h"
using namespace std;
class Game
{
	public:
		void init_game();//初始化 
		void start_game();//开始游戏 
		void play_chess(Chesser &,Chesser &,Chesspad,Judge,Resultdisplay);
		Game()
		{
			mode=-1;
		}
		void chooseMode();
		void initOrder();
	private:
		string blackname;//黑方名 
		string whitename;//白方名 
		Chesspad chesspad;//棋盘 
		Judge judge;//判断机 
		Resultdisplay resultdisplay;//展示机 
		int mode;
		int first;
		
}; 
