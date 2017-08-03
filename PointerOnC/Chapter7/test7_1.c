/*************************************************************************
    > File Name: test7_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月26日 星期三 16时27分48秒
 ************************************************************************/

#include <stdio.h>

int 
hermite(int n, int x)
{
	if(n <= 0)
		return 1;

	if(n == 1)
		return 2*x;

	if(n >= 2)
		return	2 * x * hermite(n-1, x) - 2 * (n-1) * hermite(n-2, x);
}
