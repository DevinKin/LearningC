/*************************************************************************
    > File Name: test8_8_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月30日 星期日 21时21分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define		FALSE	0
#define		TRUE	1	
int		board[8][8];


void
print_board()
{
	int		row;
	int		column;
	static	int		n_solutions;

	n_solutions += 1;
	printf("Solution #%d:\n",n_solutions);

	for(row = 0; row < 8; row +=1)
	{
		for(column = 0; column < 8; column +=1)
		{
			if(board[row][column])
				printf(" Q");
			else
				printf(" +");
		}
		putchar('\n');
	}
	putchar('\n');
}


int 
conflicts(int row, int column)
{
	int		i;
	for(i = 1; i < 8; i += 1)
	{
		if(row - i >= 0 && board[row - i][column])
			return TRUE;
		if(column - i >= 0 && board[row][column - i])
			return TRUE;
		if(column + 1 < 8 && board[row][column + i])
			return TRUE;

		if(row - i >= 0 && column - i >= 0
				&& board[row - i][column - i])
			return	TRUE;

		if(row - i >= 0 && column + i < 8
				&& board[row - i][column + i])
			return	TRUE;
	}
	return	FALSE;
}


void place_queen(int row)
{
	int		column;

	for(column = 0; column < 8; column +=1)
	{
		board[row][column] = TRUE;

		if(row == 0 || !conflicts(row, column))
			if(row < 7)
				place_queen(row + 1);
			else
				print_board();
		board[row][column] = FALSE;
	}
}


int main(void)
{
	place_queen(0);
	return EXIT_SUCCESS;
}
