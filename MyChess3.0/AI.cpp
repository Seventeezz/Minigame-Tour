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
		switch (type) //�������Ͷ�situation����
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
				//������
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
		return Level_1;//Ӯ5

	if (situation.alive4 >= 1 || die4 >= 2 || (die4 >= 1 && alive3 >= 1))
		return Level_2;//��4 ˫��4 ��4��3

	if (alive3 >= 2)
		return Level_3;//˫��3

	if (situation.die3 >= 1 && situation.alive3 >= 1)
		return Level_4;//��3�߼���3

	if (situation.die4 >= 1)
		return Level_5;//�߼���4

	if (situation.lowdie4 >= 1)
		return Level_6;//�ͼ���4

	if (situation.alive3 >= 1)
		return Level_7;//����3

	if (situation.tiao3 >= 1)
		return Level_8;//����3

	if (alive2 >= 2)
		return Level_9;//˫��2

	if (situation.alive2 >= 1)
		return Level_10;//��2

	if (situation.lowalive2 >= 1)
		return Level_11;//�ͼ���2

	if (situation.die3 >= 1)
		return Level_12;//��3

	if (situation.die2 >= 1)
		return Level_13;//��2

	return Level_14;//û����в

	
	
	
}



int AI::gettype(int state[19][19],Position p,int color,int direction)//����Ŀǰ9��λ��ȷ��������
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
		case 0://����
			for(int i=position.x,j=1;j<=4;j++)//��4 
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
			
		case 1://���� 
			for (int j = position.y, i = 1;i <= 4;i++) 
			{//���Ͽ����ĸ�
				int row = position.x - i;
				if (row < 0) 
				{
					for (;i <= 4;i++)
						chess[4 - i] = hiscolor;//�������ö�����ɫ
					break;
				}
					chess[4 - i] = state[row][j];//û���磬����state����
			}
			for (int i = 1, j = position.y;i <= 4;i++) 
			{//���¿����ĸ�
				int row = position.x + i;
				if (row > 18) {
					for (;i <= 4;i++)
						chess[4+i] = hiscolor;//�������ö�����ɫ
					break;
				}
				chess[4+i] = state[row][j];//û���磬����state����
			}
			break;
		case 2://����
		for (int i = 1, j = 1;i <= 4;i++,j++) 
		{
			int row = position.x - i;
			int column = position.y - j;
			if (row < 0 || column <0) 
			{
				for (;i <= 4;i++)
					chess[4 - i] = hiscolor;//�������ö�����ɫ
				break;
			}
			chess[4 - i] = state[row][column];//û���磬����state����
		}
		for (int i = 1, j = 1;i <= 4;i++, j++) 
		{
			int row = position.x + i;
			int column = position.y + j;
			if (row > 18 || column > 18) 
			{
				for (;i <= 4;i++)
					chess[4 + i] = hiscolor;//�������ö�����ɫ
				break;
			}
			chess[4 + i] = state[row][column];//û���磬����state����
		}
		break;
		case 3://����
			for (int i = 1, j = 1;i <= 4;i++, j++) 
			{
				int row = position.x + i;
				int column = position.y - j;
				if (row > 18 || column <0) 
				{
					for (;i <= 4;i++)
						chess[4 - i] = hiscolor;//�������ö�����ɫ
					break;
				}
				chess[4 - i] = state[row][column];//û���磬����state����
			}
			for (int i = 1, j = 1;i <= 4;i++, j++) {//�����Ͽ����ĸ�
				int row = position.x - i;
				int column = position.y + j;
				if (row < 0  || column > 18) {//����һ�����߽�
					for (;i <= 4;i++)
						chess[4 + i] = hiscolor;//�������ö�����ɫ
					break;
				}
				chess[4 + i] = state[row][column];//û���磬����state����
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
	int left, right;//��ʼ�������߶Ͽ���λ��
	int colorleft, colorright;//��ʼ�������߶Ͽ�����ɫ��NOTHING����hiscolor
	int count = 1;//�������ж��ٸ�����ʼ��
	for (int i = 1;i <= 4;i++) {
		if (chess[4 - i] == mycolor)
			count++;//ͬɫ
		else {
			left = 4 - i;//����Ͽ�λ��
			colorleft = chess[4 - i];//����Ͽ���ɫ
			break;
		}
	}
	for (int i = 1;i <= 4;i++) {
		if (chess[4 + i] == mycolor)
			count++;//ͬɫ
		else {
			right = 4 + i;//����Ͽ�λ��
			colorright = chess[4 + i];//����Ͽ���ɫ
			break;
		}
	}


	if (count >= 5)//������5��
		return WIN5;//5����

	if (count == 4)//������4��
	{
		if (colorleft == NOTHING && colorright == NOTHING)//���߶Ͽ�λ�þ���
			return ALIVE4;//����
		else if (colorleft == hiscolor && colorright == hiscolor)//���߶Ͽ�λ�þ��ǿ�
			return NOTHREAT;//û����в
		else if (colorleft == NOTHING || colorright == NOTHING)//���߶Ͽ�λ��ֻ��һ����
			return DIE4;//����
	}

	if (count == 3) {//������3��
		int colorleft1 = chess[left - 1];
		int colorright1 = chess[right + 1];

		if (colorleft == NOTHING && colorright == NOTHING)//���߶Ͽ�λ�þ���
		{

			if (colorleft1 == hiscolor && colorright1 == hiscolor)//��Ϊ��������
				return DIE3;
			else if (colorleft1 == mycolor || colorright1 == mycolor)//ֻҪһ��Ϊ�Լ�������
				return LOWDIE4;
			else if (colorleft1 == NOTHING || colorright1 == NOTHING)//ֻҪ��һ����
				return ALIVE3;

		}
		else if (colorleft == hiscolor && colorright == hiscolor)//���߶Ͽ�λ�þ��ǿ�
		{
			return NOTHREAT;//û����в
		}
		else if (colorleft == NOTHING || colorright == NOTHING)//���߶Ͽ�λ��ֻ��һ����
		{

			if (colorleft == hiscolor) {//��߱��Է���ס
				if (colorright1 == hiscolor)//�ұ�Ҳ���Է���ס
					return NOTHREAT;
				if (colorright1 == NOTHING)//�ұ߾���
					return DIE3;
				if (colorright1 == mycolor)
					return LOWDIE4;

			}
			if (colorright == hiscolor) {//�ұ߱��Է���ס
				if (colorleft1 == hiscolor)//���Ҳ���Է���ס
					return NOTHREAT;
				if (colorleft1 == NOTHING)//��߾���
					return DIE3;
				if (colorleft1 == mycolor)//��߻����Լ�������
					return LOWDIE4;
			}
		}
	}

	if (count == 2) {//������2��
		int colorleft1 = chess[left - 1];
		int colorright1 = chess[right + 1];
		int colorleft2 = chess[left - 2];
		int colorright2 = chess[right + 2];

		if (colorleft == NOTHING && colorright == NOTHING)//���߶Ͽ�λ�þ���
		{
			if ((colorright1 == NOTHING && colorright2 == mycolor) ||
				(colorleft1 == NOTHING && colorleft2 == mycolor))
				return DIE3;//��3
			else if (colorleft1 == NOTHING && colorright1 == NOTHING)
				return ALIVE2;//��2

			if ((colorright1 == mycolor && colorright2 == hiscolor) ||
				(colorleft1 == mycolor && colorleft2 == hiscolor))
				return DIE3;//��3
			 
			if ((colorright1 == mycolor && colorright2 == mycolor) ||
				(colorleft1 == mycolor && colorleft2 == mycolor))
				return LOWDIE4;//��4

			if ((colorright1 == mycolor && colorright2 == NOTHING) ||
				(colorleft1 == mycolor && colorleft2 == NOTHING))
				return TIAO3;//����3
			//����������±߷���NOTHREAT
		}
		else if (colorleft == hiscolor && colorright == hiscolor)//���߶Ͽ�λ�þ��ǿ�
		{
			return NOTHREAT;
		}
		else if (colorleft == NOTHING || colorright == NOTHING)//���߶Ͽ�λ��ֻ��һ����
		{
			if (colorleft == hiscolor) {//��߱��Է���ס
				if (colorright1 == hiscolor || colorright2 == hiscolor) {//ֻҪ�жԷ���һ������
					return NOTHREAT;//û����в
				}
				else if (colorright1 == NOTHING && colorright2 == NOTHING) {//����
					return DIE2;//��2
				}
				else if (colorright1 == mycolor && colorright2 == mycolor) {//��Ϊ�Լ�������
					return LOWDIE4;//��4
				}
				else if (colorright1 == mycolor || colorright2 == mycolor) {//ֻ��һ���Լ�������
					return DIE3;//��3
				}
			}
			if (colorright == hiscolor) {//�ұ߱��Է���ס
				if (colorleft1 == hiscolor || colorleft2 == hiscolor) {//ֻҪ�жԷ���һ������
					return NOTHREAT;//û����в
				}
				else if (colorleft1 == NOTHING && colorleft2 == NOTHING) {//����
					return DIE2;//��2
				}
				else if (colorleft1 == mycolor && colorleft2 == mycolor) {//��Ϊ�Լ�������
					return LOWDIE4;//��4
				}
				else if (colorleft1 == mycolor || colorleft2 == mycolor) {//ֻ��һ���Լ�������
					return DIE3;//��3
				}
			}
		}
	}
		
	if (count == 1) {//������1��
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

		//�������±߷���û����в

	}
	return NOTHREAT;//����û����в
	
	
}

Position AI::bestchoice(int myscore[19][19],int hisscore[19][19])
{
	Position position = {0, 0};

	int mymaxscore = 0;//��ʼ��Ϊ0
	int hismaxscore = 0;

	vector<Position> mypositionvector;//�洢���ֵ��Ӧ��λ������
	vector<Position> hispositionvector;

	for (int i = 0;i < 19;i++)//�����ҵ����ֵ����
		for (int j = 0;j < 19;j++) {
			if (myscore[i][j] == mymaxscore) {//���λ����������
				position.x = i;
				position.y = j;
				mypositionvector.push_back(position);
			}
			if (myscore[i][j]>mymaxscore) {//�϶��д���0�ķ���
				mymaxscore = myscore[i][j];//�滻���ֵ
				mypositionvector.clear();//���λ����������
				//�����λ������
				position.x = i;
				position.y = j;
				mypositionvector.push_back(position);
			}
		}

	for (int i = 0;i < 19;i++)//���ö��ֵ����ֵ����
		for (int j = 0;j < 19;j++) {
			if (hisscore[i][j] == hismaxscore) {
				position.x = i;
				position.y = j;
				hispositionvector.push_back(position);
			}
			if (hisscore[i][j]>hismaxscore) {//�϶��д���0�ķ���
				hismaxscore = hisscore[i][j];//�滻���ֵ
				hispositionvector.clear();//���λ����������

				position.x = i;
				position.y = j;
				hispositionvector.push_back(position);
			}
			
		}

	if (mymaxscore >= hismaxscore) {//���� 
		int temp = 0;//�洢��������Щλ���е�������
		
		vector<Position>::iterator iter;
		for (iter = mypositionvector.begin();iter != mypositionvector.end();iter++)
		{
			Position maxtemp = *iter;
			if (hisscore[maxtemp.x][maxtemp.y] >= temp) {//�϶������
				temp = hisscore[maxtemp.x][maxtemp.y];//�滻���ֵ
				position = maxtemp;//�滻λ��
			}
		}

		return position;//�����ҵ����ֵ�ж���Ҳ����λ��
	}
	else {//����
		int temp = 0;//�洢�Լ�����Щλ���е�������

		vector<Position>::iterator iter;
		for (iter = hispositionvector.begin();iter != hispositionvector.end();iter++)
		{
			Position maxtemp = *iter;
			if (myscore[maxtemp.x][maxtemp.y] >= temp) {//�϶������
				temp = myscore[maxtemp.x][maxtemp.y];//�滻���ֵ
				position = maxtemp;//�滻λ��
			}
		}

		return position;//���ض��ֵ����ֵ����Ҳ����λ��
	}
	
	
}














