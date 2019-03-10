#include "Game.h"
#include <iostream>
using namespace std;

void Game::chooseMode() 
{
	do {
		resultdisplay.display("ѡ�����ģʽ0Ϊ�˻����ģ�1Ϊ���˶��ģ�");
		cin.clear();
		cin.sync();//VS2015������ջ�������vs2012���ԣ�����
		cin >> mode;
	} while (2 <= mode || mode < 0);
}

void Game::initOrder() 
{
	do {
		resultdisplay.display("��������������0��������������1��");
		cin.clear();
		cin.sync();//VS2015������ջ�������vs2012���ԣ�����
		cin >> first;
	} while (2 <= first || first < 0);
}



void Game::init_game()
{
	chooseMode();
	if(mode==1)
	{
		resultdisplay.display("������ڷ�������");//��ʼ�����̲�չʾ�������Ϣ 
		cin.clear();
		cin.sync();//ʹ���벻������ 
		cin>>blackname;
	
		resultdisplay.display("������׷�������");
		cin.clear();
		cin.sync();
		cin>>whitename;
	}
	else 
	{
		initOrder();
		if (first) 
		{
			blackname = "�û�";
			whitename = "����";
		}
		else 
		{
			blackname = "����";
			whitename = "�û�";
		}
	}
	
	
}



void Game::start_game()
{
	if(mode==1)
	{
		HumanChesser black(0,blackname);//��ʼ���ڷ�������Ϣ��0����ڷ�
		HumanChesser white(1,whitename);//��ʼ���׷�������Ϣ��1����׷�
		play_chess(black,white,chesspad,judge,resultdisplay);
	}
	else
	{
		if (first) 
		{
			//��ʼ��ѡ��
			AIChesser white(1, "����");
			HumanChesser black(0, "�û�");
			//����
			play_chess(black, white,chesspad ,judge , resultdisplay);
		}
		else {
			//��ʼ��ѡ��
			AIChesser black(0, "����");
			HumanChesser white(1, "�û�");
			//����
			play_chess(black, white,chesspad ,judge , resultdisplay);
		}
	}
	
}

void Game::play_chess(Chesser &black,Chesser &white,Chesspad chesspad,Judge judge,Resultdisplay resultdisplay)
{
	int result;//resultΪ0��ʾ��δ�ֳ�ʤ�� 
	int state[19][19]={0};
	do
	{
		if(judge.nextplayer())//nextplayer����ֵ��1�����ǰ�����
		{
			resultdisplay.display(state,"�׷�:" + whitename + '\n');//չʾ��ǰ���̸�ֲ��������Ϣ 
			chesspad.change_state(white.givenext(state)); //����������°������Ϣ����������״̬ 
			
			
		} 
		else //nextplay����ֵ��0�����Ǻ�����
		{
			resultdisplay.display(state,"�ڷ�:" + blackname + '\n');
			chesspad.change_state(black.givenext(state)); 
		}
		chesspad.givestate(state);//��������Ϣ�л�ȡ����state 
	} while(!(result=judge.judgeresult(state)));
	//�ֳ�ʤ�� 
	switch(result)
	{
		case 1:
			resultdisplay.display(state,"�ڷ�" + blackname + "ʤ��\n��E/e�˳�");
			break;
		case 2: 
			resultdisplay.display(state,"�׷�" + whitename + "ʤ��\n��E/e�˳�");
			break;
		case 3:
			resultdisplay.display(state,"˫��ƽ��\n��E/e�˳�");
	}
	char exit;
	do{
		cin.clear();
		cin.sync();
		cin>>exit;
	} while(exit!='e'&&exit!='E');
	
}





