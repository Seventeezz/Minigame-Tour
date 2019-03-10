#include "Judge.h"
#include <cmath>
#include <iostream>
using namespace std;

int Judge::nextplayer()
{
	if(currentcolor==1)
	{
		currentcolor=0;
		return 0;
	}
	else
	{
		currentcolor=1;
		return 1;
	}

}

int Judge::judgeresult(int state[19][19])
{
	int result;
	//判断是否有和局情况出现
	int i,j;
	int flag=0;
	for(i=0;i<19;i++)
	{
		for(j=0;j<19;j++)
		{
			if(state[i][j]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		break;
	} 
	if(i==19&&j==19)
	{
		return 3;
	}
	flag=0;
	int lastrow,lastcol;
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			if(state[i][j]>2)
			{
				lastrow=i;
				lastcol=j;
				result=state[i][j]-2;
				flag=1;
			}
		}
		if(flag)
		break;
	}
	
	int count;
	int rowmin,rowmax,colmin,colmax;
	rowmin=lastrow-4<0?0:lastrow-4;
	rowmax=lastrow+4>18?18:lastrow+4;
	colmin=lastcol-4<0?0:lastcol-4;
	colmax=lastcol+4<0?0:lastcol+4;
	
	//横向看有没有五连棋子
	count=0;
	for(int i=lastrow,j=colmin;j<=colmax;j++)
	{
		if(state[i][j]==result||state[i][j]==result+2)
		{
			count++;
			if(count==5)
			return result;
		}
		else
		count=0;	
	}
	
	//纵向看有没有五连棋子
	count=0;
	for(int i=rowmin,j=lastcol;i<=rowmax;i++)
	{
		if(state[i][j]==result||state[i][j]==result+2)
		{
			count++;
			if(count==5)
			return result;
		}
		else
		count=0;	
	} 
	
	//西北
	count=0;
	rowmin=lastrow-4;
	colmin=lastcol-4;
	int min1=min(rowmin,colmin);
	if(min1<0)
	{
		rowmin+=(-min1);
		colmin+=(-min1);
	} 
	rowmax=lastrow+4;
	colmax=lastrow+4;
	int max1=max(rowmax-18,colmax-18);
	if(max1>0)
	{
		rowmax-=max1;
		colmax-=max1;
	}
	for(int i=rowmin,j=colmin;i<=rowmax;i++,j++)
	{
		if(state[i][j]==result||state[i][j]==result+2)
		{
			count++;
			if(count==5)
			return result;
		}
		else
		count=0;
	}
	
	//东北
	count=0;
	rowmin=lastrow-4;
	colmax=lastcol+4;
	int c1=rowmin<0?abs(rowmin):0;
	int c2=colmax>18?colmax-18:0;
	int c=max(c1,c2);
	rowmin+=c;
	colmax-=c;
	
	rowmax=lastrow+4;
	colmin=lastcol-4;
	c1=rowmax>18?rowmax-18:0;
	c2=colmin<0?abs(colmin):0;
	c=max(c1,c2);
	rowmax-=c;
	colmin+=c;
	for(int i=rowmin,j=colmax;i<=rowmax;i++,j--)
	{
		if(state[i][j]==result||state[i][j]==result+2)
		{
			count++;
			if(count==5)
			return result;
		}
		else
		count=0;
	}
	 
	return 0;
	
	
}

