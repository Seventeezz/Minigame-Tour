#include "Resultdisplay.h"
#include <iostream>
using namespace std;
void Resultdisplay::display(string msg)
{
	int init_state[19][19]={0};
	display(init_state,msg);

}

void Resultdisplay::display(int chesspadstate[19][19],string msg)
{
	system("cls");
	cout<<Row_and_Column<<endl;
	for(int row=0;row<19;row++)
	{
		cout<<Row_and_Column.at((row+1)*2+1)<<" "; 
		for(int col=0;col<19;col++)
		{
			switch(chesspadstate[row][col])
			{
				case 0://空白 
					cout<<Chesspad_Shape.at((row*19+col)*2)<<Chesspad_Shape.at((row*19+col)*2+1);
					break;
				case 1://有黑棋
					cout<<"○";
					break;
				case 2://有白棋 
					cout<<"●";
					break;
				case 3://上一步是黑棋 
					cout<<"▽";
					break;
				case 4://上一步是白旗 
					cout<<"▼";
					break;
					
			}
			

		}
		cout<<endl;

	}
	cout<<msg<<endl;
	
	
	
}

