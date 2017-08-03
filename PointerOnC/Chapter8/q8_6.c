/*************************************************************************
    > File Name: q8_6.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月28日 星期五 11时48分14秒
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define		MAX_SIZE	1000000
static	int		source[MAX_SIZE];

void
try1(int *x, int *y)
{
	for(int i = 0; i < MAX_SIZE; ++i)
		x[i] = y[i];
}

void
try5(int *x, int *y)
{
	register	int		*p1, *p2;
	for(p1 = x, p2 = y; p1 < &x[MAX_SIZE];)
		*p1++ = *p2++;
}

int main(void)
{
	int		*sp;
	int 	buffer[MAX_SIZE];	
	clock_t	start;
	clock_t finish;
	double	whole;
	for(sp = source; sp < source + MAX_SIZE; ++sp)
		*sp = 5;
	start = clock();
	try1(buffer, source);
	finish = clock();
	whole = (start - finish) / CLOCKS_PER_SEC;
	printf("%d\n", start);
	printf("%d\n", finish);
	printf("%f\n", whole);
	return	EXIT_SUCCESS;
}
