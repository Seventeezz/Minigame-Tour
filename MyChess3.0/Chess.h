#pragma once

class Chess
{
	public:
		Chess(int colour,int r,int c):color(colour),row(r),column(c){}
		void update_pos(int &lastrow,int &lastcol)
		{
			lastrow=row;
			lastcol=column;
		}
		int getcolor()
		{
			return color;
		}
	private:
		int color;
		int row;
		int column;
	
	
};
