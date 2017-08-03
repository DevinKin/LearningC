/*************************************************************************
    > File Name: test7_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月26日 星期三 16时34分33秒
 ************************************************************************/

#include <stdio.h>

int 
gcd(int M, int N)
{
	int R = M % N;
	//return R > 0 ? gcd(N,R) : N;
	if( M < 0 || N < 0)
		return 0;
	do
	{
		R = M % N;
		M = N;
		N = R;
	}
	while (R > 0);

	return 0;
}

