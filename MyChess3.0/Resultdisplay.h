#pragma once
#include <string>
using namespace std;
class Resultdisplay
{
	public:
		Resultdisplay()
		{
			Row_and_Column="   A B C D E F G H I J K L M N O P Q R S";
			Chesspad_Shape=
			"┌┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┐"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤"
			"└┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┘" ;
		}
		void display(string);//初始化棋盘并输出要求信息
		void display(int [19][19],string); 
	private:
		string Row_and_Column;
		string Chesspad_Shape;
		
	
	
};
