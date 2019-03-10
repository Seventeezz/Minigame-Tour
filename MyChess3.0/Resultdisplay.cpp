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
				case 0://�հ� 
					cout<<Chesspad_Shape.at((row*19+col)*2)<<Chesspad_Shape.at((row*19+col)*2+1);
					break;
				case 1://�к���
					cout<<"��";
					break;
				case 2://�а��� 
					cout<<"��";
					break;
				case 3://��һ���Ǻ��� 
					cout<<"��";
					break;
				case 4://��һ���ǰ��� 
					cout<<"��";
					break;
					
			}
			

		}
		cout<<endl;

	}
	cout<<msg<<endl;
	
	
	
}

