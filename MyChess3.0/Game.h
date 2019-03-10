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
		void init_game();//��ʼ�� 
		void start_game();//��ʼ��Ϸ 
		void play_chess(Chesser &,Chesser &,Chesspad,Judge,Resultdisplay);
		Game()
		{
			mode=-1;
		}
		void chooseMode();
		void initOrder();
	private:
		string blackname;//�ڷ��� 
		string whitename;//�׷��� 
		Chesspad chesspad;//���� 
		Judge judge;//�жϻ� 
		Resultdisplay resultdisplay;//չʾ�� 
		int mode;
		int first;
		
}; 
