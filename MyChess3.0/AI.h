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
		//������ɫ����� 
		static const int BLACK=1;
		static const int WHITE=2;
		static const int NOTHING=0;
		
		//����״̬
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
		
		//��ֵȼ�
		static const int Level_1 = 100000;//����
		static const int Level_2 = 10000;//�ɻ�4 �� ˫��4 �� ��4��3
		static const int Level_3 = 5000;//˫��3
		static const int Level_4 = 1000;//��3�߼���3
		static const int Level_5 = 500;//����
		static const int Level_6 = 400;//�ͼ�����
		static const int Level_7 = 100;//����3
		static const int Level_8 = 90;//����3
		static const int Level_9 = 50;//˫��2
		static const int Level_10 = 10;//��2
		static const int Level_11 = 9;//�ͼ���2
		static const int Level_12 = 5;//��3
		static const int Level_13 = 2;//��2
		static const int Level_14 = 1;//û����в
		static const int Level_15 = 0;//������ 
		
		
			
		int evaluate(int state[19][19],Position p,int color);
		//�ۺ��ĸ����������ǰλ�õ����� 
		int givescore(Situation situation);
		//���ݵ�ǰ���Ƹ����÷� 
		void getchess(int chess[9],int state[19][19],Position p,int color,int direction);
		//���ݵ�ǰ���ⶨ��λ�û�ȡ�ض������ϵ�9��״̬ 
		int gettype(int state[19][19],Position p,int color,int direction);
		//����Ŀǰ9��λ�û�ȡ������
		int judgetype(const int chess[9]);
		//����9���ж����� 
		Position bestchoice(int myscore[19][19],int hisscore[19][19]);
		//���ݵ���˫���ķ���ѡ�����λ�� 
		
		
		
	
	
};


