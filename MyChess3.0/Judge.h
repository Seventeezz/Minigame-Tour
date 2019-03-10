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
		int currentcolor;//flag为1代表是白棋,0是黑棋 
		
};
