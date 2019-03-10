#pragma once
using namespace std;

struct Position
{
	int x;
	int y;
};

struct Situation{
	int win5;
	int alive4;
	int die4;
	int lowdie4;
	int alive3;
	int tiao3;
	int die3;
	int alive2;
	int lowalive2;
	int die2;
	int nothreat;
};



class AI
{
	public:
		Position getPosition(const int state[19][19],int color);
		 
	
	
	
	
	
	
	
	
	
	
	private:
		//代表颜色方标记 
		static const int BLACK=1;
		static const int WHITE=2;
		static const int NOTHING=0;
		
		//棋型状态
		static const int WIN5=0;
		static const int ALIVE4=1;
		static const int DIE4=2;
		static const int LOWDIE4=3;
		static const int ALIVE3=4;
		static const int TIAO3=5;
		static const int DIE3=6;
		static const int ALIVE2=7;
		static const int LOWALIVE2=8;
		static const int DIE2=9;
		static const int NOTHREAT=10;
		
		//打分等级
		static const int Level_1 = 100000;//成五
		static const int Level_2 = 10000;//成活4 或 双死4 或 死4活3
		static const int Level_3 = 5000;//双活3
		static const int Level_4 = 1000;//死3高级活3
		static const int Level_5 = 500;//死四
		static const int Level_6 = 400;//低级死四
		static const int Level_7 = 100;//单活3
		static const int Level_8 = 90;//跳活3
		static const int Level_9 = 50;//双活2
		static const int Level_10 = 10;//活2
		static const int Level_11 = 9;//低级活2
		static const int Level_12 = 5;//死3
		static const int Level_13 = 2;//死2
		static const int Level_14 = 1;//没有威胁
		static const int Level_15 = 0;//不能下 
		
		
			
		int evaluate(int state[19][19],Position p,int color);
		//综合四个方向给出当前位置的评分 
		int givescore(Situation situation);
		//根据当前形势给出得分 
		void getchess(int chess[9],int state[19][19],Position p,int color,int direction);
		//根据当前虚拟定的位置获取特定方向上的9子状态 
		int gettype(int state[19][19],Position p,int color,int direction);
		//根据目前9子位置获取其棋型
		int judgetype(const int chess[9]);
		//根据9子判断棋型 
		Position bestchoice(int myscore[19][19],int hisscore[19][19]);
		//根据敌我双方的分数选择最佳位置 
		
		
		
	
	
};


