#pragma once
using namespace std;

class Judge
{
	public:
		Judge()
		{
			currentcolor=1;
		}
		int nextplayer();
		int judgeresult(int state[19][19]);
	
	
	private:
		int currentcolor;//flagΪ1�����ǰ���,0�Ǻ��� 
		
};
