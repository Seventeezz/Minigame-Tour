#pragma once
#include "Chess.h" 
#include <string>
using namespace std;
/*Chesser��Ϊ����࣬�ṩ�̳У���Ϊ�����������ֺ�AI���֣�*/ 
class Chesser 
{
	public:
		virtual Chess givenext(int chesspadstate[19][19])=0;//��������״̬�������� 
	
	
	
	protected:
		int color;//0�����ɫ��1�����ɫ 
		string name;
		
	
};
