/*************************************************************************
    > File Name: test8_3.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月29日 星期六 12时02分21秒
 ************************************************************************/

#include <stdio.h>



bool
identity_matrix(int *iden, int size)
{
	int		cnt_row;
	int		cnt_col;
	bool	test = false;
	for(cnt_row = 0; cnt_row < size; ++cnt_row)
		for(cnt_col = 0; cnt_col < size; ++cnt_col)
			test = (*iden++ && cnt_row == cnt_col);
	return	test;
}
