/*************************************************************************
    > File Name: test8_8.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月30日 星期日 15时44分06秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

static	int		answer = 0;
static	char	chessboard[8][8];


void 
print_board(void)
{
	static	int cnt = 1;
	printf("answer %d\n", cnt++);
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
			printf("%c ",chessboard[i][j]);
		putchar('\n');
	}
	putchar('\n');
}


int	
conflicts(int row, int column)
{
	int		i;
	for(i = 1; i < 8; ++i)
	{
		if(row - i >= 0 && chessboard[row -i][column] == 'Q')
			return 1;
		if(column - i >= 0 && chessboard[row][column -i] == 'Q')
			return 1;
		if(column + i < 8 && chessboard[row][column + i] == 'Q')
			return 1;

		if(row - i >= 0 && column -i >= 0
				&& chessboard[row - i][column -i] == 'Q')
			return 1;
		if(row - i >= 0 && column + i < 8 
				&& chessboard[row - i][column + i] == 'Q')
			return 1;
	}
	//no conflicts
	return 0;
}


void
place_queen(int row)
{
	int column;
	for(column = 0; column < 8; column += 1)
	{
		chessboard[row][column] = 'Q';
		
		if(row == 0 || !conflicts(row,column))
			if(row < 7)
				place_queen(row + 1);
			else
				print_board();
		chessboard[row][column] = '+';
		
	}
}


int 
main(void)
{
	place_queen(0);
	return	EXIT_SUCCESS;
}
