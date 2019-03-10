#include "AI.h"
#include <vector>
using namespace std;
Position AI::getPosition(const int state[19][19],int color)
{
	int mycolor=color+1;
	int hiscolor=3-mycolor;
	int myscore[19][19]={0};
	int hisscore[19][19]={0};
	int tmpstate[19][19]={0};
	
	int flag=1;
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			if(state[i][j]>0)
			{
				flag=0;
				j=20;
				i=20;
			}
		} 
	}
	if(flag)
	{
		Position p={9,9};
		return p;
	
	}
	
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			if(state[i][j]>2)
			{
				tmpstate[i][j]=state[i][j]-2;
			}
			else
				tmpstate[i][j]=state[i][j];
		}
	}
	
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			int score;
			Position p;
			p.x=i;
			p.y=j;
			score=evaluate(tmpstate,p,mycolor);
			myscore[i][j]=score;
			
			score=evaluate(tmpstate,p,hiscolor);
			hisscore[i][j]=score; 
	
		}
	}
	return bestchoice(myscore,hisscore);
}

int AI::evaluate(int state[19][19],Position p,int color)
{
	Situation situation={0};
	if(state[p.x][p.y]>0)
	return Level_15;
	
	for(int direction=0;direction<4;direction++)
	{
		int type=gettype(state,p,color,direction);
		switch (type) //根据类型对situation设置
		{
			case WIN5:
				situation.win5++;
				break;
			case ALIVE4:
				situation.alive4++;
				break;
			case DIE4:
				situation.die4++;
				break;
			case LOWDIE4:
				situation.lowdie4++;
				break;
			case ALIVE3:
				situation.alive3++;
				break;
			case TIAO3:
				situation.tiao3++;
				break;
			case DIE3:
				situation.die3++;
				break;
			case ALIVE2:
				situation.alive2++;
				break;
			case LOWALIVE2:
				situation.lowalive2++;
				break;
			case DIE2:
				situation.die2++;
				break;
			case NOTHREAT:
				situation.nothreat++;
				break;
			default:
				//差错控制
				break;
		}
		
		
		
		
	}
	
	return givescore(situation);
	
	
	
	
	
}

int AI::givescore(Situation situation)
{
	int die4 = situation.die4 + situation.lowdie4;
	int alive3 = situation.alive3 + situation.tiao3;
	int alive2 = situation.alive2 + situation.lowalive2;
	if (situation.win5 >= 1)
		return Level_1;//赢5

	if (situation.alive4 >= 1 || die4 >= 2 || (die4 >= 1 && alive3 >= 1))
		return Level_2;//活4 双死4 死4活3

	if (alive3 >= 2)
		return Level_3;//双活3

	if (situation.die3 >= 1 && situation.alive3 >= 1)
		return Level_4;//死3高级活3

	if (situation.die4 >= 1)
		return Level_5;//高级死4

	if (situation.lowdie4 >= 1)
		return Level_6;//低级死4

	if (situation.alive3 >= 1)
		return Level_7;//单活3

	if (situation.tiao3 >= 1)
		return Level_8;//跳活3

	if (alive2 >= 2)
		return Level_9;//双活2

	if (situation.alive2 >= 1)
		return Level_10;//活2

	if (situation.lowalive2 >= 1)
		return Level_11;//低级活2

	if (situation.die3 >= 1)
		return Level_12;//死3

	if (situation.die2 >= 1)
		return Level_13;//死2

	return Level_14;//没有威胁

	
	
	
}



int AI::gettype(int state[19][19],Position p,int color,int direction)//根据目前9子位置确定其棋型
{
	int type;
	int chess[9]={0};
	getchess(chess,state,p,color,direction);
	type=judgetype(chess);
	return type;
} 

void AI::getchess(int chess[9],int state[19][19],Position position,int color,int direction)
{
	int hiscolor=3-color;
	chess[4]=color;
	switch(direction)
	{
		case 0://横向
			for(int i=position.x,j=1;j<=4;j++)//左4 
			{
				int col=position.y-j;
				if(col<0)
				{
					for(;j<=4;j++)
					chess[4-j]=hiscolor;
					break;
				}
				chess[4-j]=state[i][col];
			} 
			for(int i=position.x,j=1;j<=4;j++)
			{
				int col=position.y+j;
				if(col>18)
				{
					for(;j<=4;j++)
					chess[4+j]=hiscolor;
					break;
				}
				chess[4+j]=state[i][col];
			}
			break;
			
		case 1://纵向 
			for (int j = position.y, i = 1;i <= 4;i++) 
			{//往上拷贝四个
				int row = position.x - i;
				if (row < 0) 
				{
					for (;i <= 4;i++)
						chess[4 - i] = hiscolor;//出界设置对手颜色
					break;
				}
					chess[4 - i] = state[row][j];//没出界，复制state数组
			}
			for (int i = 1, j = position.y;i <= 4;i++) 
			{//往下拷贝四个
				int row = position.x + i;
				if (row > 18) {
					for (;i <= 4;i++)
						chess[4+i] = hiscolor;//出界设置对手颜色
					break;
				}
				chess[4+i] = state[row][j];//没出界，复制state数组
			}
			break;
		case 2://左上
		for (int i = 1, j = 1;i <= 4;i++,j++) 
		{
			int row = position.x - i;
			int column = position.y - j;
			if (row < 0 || column <0) 
			{
				for (;i <= 4;i++)
					chess[4 - i] = hiscolor;//出界设置对手颜色
				break;
			}
			chess[4 - i] = state[row][column];//没出界，复制state数组
		}
		for (int i = 1, j = 1;i <= 4;i++, j++) 
		{
			int row = position.x + i;
			int column = position.y + j;
			if (row > 18 || column > 18) 
			{
				for (;i <= 4;i++)
					chess[4 + i] = hiscolor;//出界设置对手颜色
				break;
			}
			chess[4 + i] = state[row][column];//没出界，复制state数组
		}
		break;
		case 3://右上
			for (int i = 1, j = 1;i <= 4;i++, j++) 
			{
				int row = position.x + i;
				int column = position.y - j;
				if (row > 18 || column <0) 
				{
					for (;i <= 4;i++)
						chess[4 - i] = hiscolor;//出界设置对手颜色
					break;
				}
				chess[4 - i] = state[row][column];//没出界，复制state数组
			}
			for (int i = 1, j = 1;i <= 4;i++, j++) {//往右上拷贝四个
				int row = position.x - i;
				int column = position.y + j;
				if (row < 0  || column > 18) {//其中一个出边界
					for (;i <= 4;i++)
						chess[4 + i] = hiscolor;//出界设置对手颜色
					break;
				}
				chess[4 + i] = state[row][column];//没出界，复制state数组
			}
			break;
		default:
			break;
	}

}

int AI::judgetype(const int chess[9])
{
	int mycolor=chess[4];
	int hiscolor=3-mycolor;
	int left, right;//开始和中心线断开的位置
	int colorleft, colorright;//开始和中心线断开的颜色，NOTHING或者hiscolor
	int count = 1;//中心线有多少个，初始化
	for (int i = 1;i <= 4;i++) {
		if (chess[4 - i] == mycolor)
			count++;//同色
		else {
			left = 4 - i;//保存断开位置
			colorleft = chess[4 - i];//保存断开颜色
			break;
		}
	}
	for (int i = 1;i <= 4;i++) {
		if (chess[4 + i] == mycolor)
			count++;//同色
		else {
			right = 4 + i;//保存断开位置
			colorright = chess[4 + i];//保存断开颜色
			break;
		}
	}


	if (count >= 5)//中心线5连
		return WIN5;//5连珠

	if (count == 4)//中心线4连
	{
		if (colorleft == NOTHING && colorright == NOTHING)//两边断开位置均空
			return ALIVE4;//活四
		else if (colorleft == hiscolor && colorright == hiscolor)//两边断开位置均非空
			return NOTHREAT;//没有威胁
		else if (colorleft == NOTHING || colorright == NOTHING)//两边断开位置只有一个空
			return DIE4;//死四
	}

	if (count == 3) {//中心线3连
		int colorleft1 = chess[left - 1];
		int colorright1 = chess[right + 1];

		if (colorleft == NOTHING && colorright == NOTHING)//两边断开位置均空
		{

			if (colorleft1 == hiscolor && colorright1 == hiscolor)//均为对手棋子
				return DIE3;
			else if (colorleft1 == mycolor || colorright1 == mycolor)//只要一个为自己的棋子
				return LOWDIE4;
			else if (colorleft1 == NOTHING || colorright1 == NOTHING)//只要有一个空
				return ALIVE3;

		}
		else if (colorleft == hiscolor && colorright == hiscolor)//两边断开位置均非空
		{
			return NOTHREAT;//没有威胁
		}
		else if (colorleft == NOTHING || colorright == NOTHING)//两边断开位置只有一个空
		{

			if (colorleft == hiscolor) {//左边被对方堵住
				if (colorright1 == hiscolor)//右边也被对方堵住
					return NOTHREAT;
				if (colorright1 == NOTHING)//右边均空
					return DIE3;
				if (colorright1 == mycolor)
					return LOWDIE4;

			}
			if (colorright == hiscolor) {//右边被对方堵住
				if (colorleft1 == hiscolor)//左边也被对方堵住
					return NOTHREAT;
				if (colorleft1 == NOTHING)//左边均空
					return DIE3;
				if (colorleft1 == mycolor)//左边还有自己的棋子
					return LOWDIE4;
			}
		}
	}

	if (count == 2) {//中心线2连
		int colorleft1 = chess[left - 1];
		int colorright1 = chess[right + 1];
		int colorleft2 = chess[left - 2];
		int colorright2 = chess[right + 2];

		if (colorleft == NOTHING && colorright == NOTHING)//两边断开位置均空
		{
			if ((colorright1 == NOTHING && colorright2 == mycolor) ||
				(colorleft1 == NOTHING && colorleft2 == mycolor))
				return DIE3;//死3
			else if (colorleft1 == NOTHING && colorright1 == NOTHING)
				return ALIVE2;//活2

			if ((colorright1 == mycolor && colorright2 == hiscolor) ||
				(colorleft1 == mycolor && colorleft2 == hiscolor))
				return DIE3;//死3
			 
			if ((colorright1 == mycolor && colorright2 == mycolor) ||
				(colorleft1 == mycolor && colorleft2 == mycolor))
				return LOWDIE4;//死4

			if ((colorright1 == mycolor && colorright2 == NOTHING) ||
				(colorleft1 == mycolor && colorleft2 == NOTHING))
				return TIAO3;//跳活3
			//其他情况在下边返回NOTHREAT
		}
		else if (colorleft == hiscolor && colorright == hiscolor)//两边断开位置均非空
		{
			return NOTHREAT;
		}
		else if (colorleft == NOTHING || colorright == NOTHING)//两边断开位置只有一个空
		{
			if (colorleft == hiscolor) {//左边被对方堵住
				if (colorright1 == hiscolor || colorright2 == hiscolor) {//只要有对方的一个棋子
					return NOTHREAT;//没有威胁
				}
				else if (colorright1 == NOTHING && colorright2 == NOTHING) {//均空
					return DIE2;//死2
				}
				else if (colorright1 == mycolor && colorright2 == mycolor) {//均为自己的棋子
					return LOWDIE4;//死4
				}
				else if (colorright1 == mycolor || colorright2 == mycolor) {//只有一个自己的棋子
					return DIE3;//死3
				}
			}
			if (colorright == hiscolor) {//右边被对方堵住
				if (colorleft1 == hiscolor || colorleft2 == hiscolor) {//只要有对方的一个棋子
					return NOTHREAT;//没有威胁
				}
				else if (colorleft1 == NOTHING && colorleft2 == NOTHING) {//均空
					return DIE2;//死2
				}
				else if (colorleft1 == mycolor && colorleft2 == mycolor) {//均为自己的棋子
					return LOWDIE4;//死4
				}
				else if (colorleft1 == mycolor || colorleft2 == mycolor) {//只有一个自己的棋子
					return DIE3;//死3
				}
			}
		}
	}
		
	if (count == 1) {//中心线1连
		int colorleft1 = chess[left - 1];
		int colorright1 = chess[right + 1];
		int colorleft2 = chess[left - 2];
		int colorright2 = chess[right + 2];
		int colorleft3 = chess[left - 3];
		int colorright3 = chess[right + 3];

		if (colorleft == NOTHING && colorleft1 == mycolor && 
			colorleft2 == mycolor && colorleft3 == mycolor)
			return LOWDIE4;
		if (colorright == NOTHING && colorright1 == mycolor && 
			colorright2 == mycolor && colorright3 == mycolor)
			return LOWDIE4;

		if (colorleft == NOTHING && colorleft1 == mycolor && 
			colorleft2 == mycolor && colorleft3 == NOTHING && colorright == NOTHING)
			return TIAO3;
		if (colorright == NOTHING && colorright1 == mycolor &&
			colorright2 == mycolor && colorright3 == NOTHING && colorleft == NOTHING)
			return TIAO3;

		if (colorleft == NOTHING && colorleft1 == mycolor &&
			colorleft2 == mycolor && colorleft3 == hiscolor && colorright == NOTHING)
			return DIE3;
		if (colorright == NOTHING && colorright1 == mycolor &&
			colorright2 == mycolor && colorright3 == hiscolor && colorleft == NOTHING)
			return DIE3;

		if (colorleft == NOTHING && colorleft1 == NOTHING &&
			colorleft2 == mycolor && colorleft3 == mycolor)
			return DIE3;
		if (colorright == NOTHING && colorright1 == NOTHING &&
			colorright2 == mycolor && colorright3 == mycolor)
			return DIE3;

		if (colorleft == NOTHING && colorleft1 == mycolor &&
			colorleft2 == NOTHING && colorleft3 == mycolor)
			return DIE3;
		if (colorright == NOTHING && colorright1 == mycolor &&
			colorright2 == NOTHING && colorright3 == mycolor)
			return DIE3;

		if (colorleft == NOTHING && colorleft1 == mycolor &&
			colorleft2 == NOTHING && colorleft3 == NOTHING && colorright == NOTHING)
			return LOWALIVE2;
		if (colorright == NOTHING && colorright1 == mycolor &&
			colorright2 == NOTHING && colorright3 == NOTHING && colorleft == NOTHING)
			return LOWALIVE2;

		if (colorleft == NOTHING && colorleft1 == NOTHING &&
			colorleft2 == mycolor && colorleft3 == NOTHING && colorright == NOTHING)
			return LOWALIVE2;
		if (colorright == NOTHING && colorright1 == NOTHING &&
			colorright2 == mycolor && colorright3 == NOTHING && colorleft == NOTHING)
			return LOWALIVE2;

		//其余在下边返回没有威胁

	}
	return NOTHREAT;//返回没有威胁
	
	
}

Position AI::bestchoice(int myscore[19][19],int hisscore[19][19])
{
	Position position = {0, 0};

	int mymaxscore = 0;//初始化为0
	int hismaxscore = 0;

	vector<Position> mypositionvector;//存储最大值对应的位置向量
	vector<Position> hispositionvector;

	for (int i = 0;i < 19;i++)//设置我的最大值向量
		for (int j = 0;j < 19;j++) {
			if (myscore[i][j] == mymaxscore) {//添加位置向量数据
				position.x = i;
				position.y = j;
				mypositionvector.push_back(position);
			}
			if (myscore[i][j]>mymaxscore) {//肯定有大于0的分数
				mymaxscore = myscore[i][j];//替换最大值
				mypositionvector.clear();//清除位置向量数据
				//添加新位置数据
				position.x = i;
				position.y = j;
				mypositionvector.push_back(position);
			}
		}

	for (int i = 0;i < 19;i++)//设置对手的最大值向量
		for (int j = 0;j < 19;j++) {
			if (hisscore[i][j] == hismaxscore) {
				position.x = i;
				position.y = j;
				hispositionvector.push_back(position);
			}
			if (hisscore[i][j]>hismaxscore) {//肯定有大于0的分数
				hismaxscore = hisscore[i][j];//替换最大值
				hispositionvector.clear();//清除位置向量数据

				position.x = i;
				position.y = j;
				hispositionvector.push_back(position);
			}
			
		}

	if (mymaxscore >= hismaxscore) {//进攻 
		int temp = 0;//存储对手在这些位置中的最大分数
		
		vector<Position>::iterator iter;
		for (iter = mypositionvector.begin();iter != mypositionvector.end();iter++)
		{
			Position maxtemp = *iter;
			if (hisscore[maxtemp.x][maxtemp.y] >= temp) {//肯定会进来
				temp = hisscore[maxtemp.x][maxtemp.y];//替换最大值
				position = maxtemp;//替换位置
			}
		}

		return position;//返回我的最大值中对手也最大的位置
	}
	else {//防守
		int temp = 0;//存储自己在这些位置中的最大分数

		vector<Position>::iterator iter;
		for (iter = hispositionvector.begin();iter != hispositionvector.end();iter++)
		{
			Position maxtemp = *iter;
			if (myscore[maxtemp.x][maxtemp.y] >= temp) {//肯定会进来
				temp = myscore[maxtemp.x][maxtemp.y];//替换最大值
				position = maxtemp;//替换位置
			}
		}

		return position;//返回对手的最大值中我也最大的位置
	}
	
	
}














