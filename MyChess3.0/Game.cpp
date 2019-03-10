#include "Game.h"
#include <iostream>
using namespace std;

void Game::chooseMode() 
{
	do {
		resultdisplay.display("选择对弈模式0为人机对弈，1为人人对弈：");
		cin.clear();
		cin.sync();//VS2015不能清空缓冲区，vs2012可以！！！
		cin >> mode;
	} while (2 <= mode || mode < 0);
}

void Game::initOrder() 
{
	do {
		resultdisplay.display("电脑先下请输入0，你先下请输入1：");
		cin.clear();
		cin.sync();//VS2015不能清空缓冲区，vs2012可以！！！
		cin >> first;
	} while (2 <= first || first < 0);
}



void Game::init_game()
{
	chooseMode();
	if(mode==1)
	{
		resultdisplay.display("请输入黑方姓名：");//初始化棋盘并展示，输出信息 
		cin.clear();
		cin.sync();//使输入不会有误 
		cin>>blackname;
	
		resultdisplay.display("请输入白方姓名：");
		cin.clear();
		cin.sync();
		cin>>whitename;
	}
	else 
	{
		initOrder();
		if (first) 
		{
			blackname = "用户";
			whitename = "电脑";
		}
		else 
		{
			blackname = "电脑";
			whitename = "用户";
		}
	}
	
	
}



void Game::start_game()
{
	if(mode==1)
	{
		HumanChesser black(0,blackname);//初始化黑方棋手信息，0代表黑方
		HumanChesser white(1,whitename);//初始化白方棋手信息，1代表白方
		play_chess(black,white,chesspad,judge,resultdisplay);
	}
	else
	{
		if (first) 
		{
			//初始化选手
			AIChesser white(1, "电脑");
			HumanChesser black(0, "用户");
			//下棋
			play_chess(black, white,chesspad ,judge , resultdisplay);
		}
		else {
			//初始化选手
			AIChesser black(0, "电脑");
			HumanChesser white(1, "用户");
			//下棋
			play_chess(black, white,chesspad ,judge , resultdisplay);
		}
	}
	
}

void Game::play_chess(Chesser &black,Chesser &white,Chesspad chesspad,Judge judge,Resultdisplay resultdisplay)
{
	int result;//result为0表示还未分出胜负 
	int state[19][19]={0};
	do
	{
		if(judge.nextplayer())//nextplayer返回值是1代表是白棋下
		{
			resultdisplay.display(state,"白方:" + whitename + '\n');//展示当前棋盘格局并且输出信息 
			chesspad.change_state(white.givenext(state)); //棋盘中添加新白棋的信息，更新棋盘状态 
			
			
		} 
		else //nextplay返回值是0代表是黑棋下
		{
			resultdisplay.display(state,"黑方:" + blackname + '\n');
			chesspad.change_state(black.givenext(state)); 
		}
		chesspad.givestate(state);//从棋盘信息中获取更新state 
	} while(!(result=judge.judgeresult(state)));
	//分出胜负 
	switch(result)
	{
		case 1:
			resultdisplay.display(state,"黑方" + blackname + "胜利\n按E/e退出");
			break;
		case 2: 
			resultdisplay.display(state,"白方" + whitename + "胜利\n按E/e退出");
			break;
		case 3:
			resultdisplay.display(state,"双方平局\n按E/e退出");
	}
	char exit;
	do{
		cin.clear();
		cin.sync();
		cin>>exit;
	} while(exit!='e'&&exit!='E');
	
}





