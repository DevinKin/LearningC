/*************************************************************************
    > File Name: test8_5.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月29日 星期六 12时32分12秒
 ************************************************************************/

#include <stdio.h>



void
matrix_multiply(int *m1, int *m2, int *r,
		int x, int y, int z)
{
	for(int i = 0; i < x; ++i)
	{
		*r = 0;
		for(int j = 0; j < z; ++j)
		{
			for(int k = 0; k < y; ++k)
			{
				*r = *(m1 + k) * (*(m2 + k * z));
			}
			r++;
			m2 = m2 - z + 1;
		}
		m1 += y;
	}
}


