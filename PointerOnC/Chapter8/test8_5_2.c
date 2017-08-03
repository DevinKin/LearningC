/*************************************************************************
    > File Name: test8_5_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月29日 星期六 13时51分11秒
 ************************************************************************/

#include <stdio.h>


void 
matrix_multiply(int *m1, int *m2, int *r,
		int x, int y, int z)
{
	register int	*m1p;
	register int	*m2p;
	register int	k;
	int		row;
	int		col;

	for(row = 0; row < x; ++row)
	{
		for(col = 0; col < z; ++col)
		{
			m1p = m1 + row * y;
			m2p = m2 + col;
			*r = 0;
			for(k=0; k < y; ++k)
			{
				*r += *m1p * *m2p;
				m1p += 1;
				m2p += z;
			}
			r++;
		}
	}
}
