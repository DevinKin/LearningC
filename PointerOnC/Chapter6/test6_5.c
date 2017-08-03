/*************************************************************************
    > File Name: test6_4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月25日 星期二 21时31分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "bitarray.h"
#include <time.h>
#include <limits.h>

#define		SIZE	1000
#define		TRUE	1	
#define		FALSE	0

int main(void)
{
	char	sieve[SIZE];
	char	*sp;
	unsigned		i;
	unsigned		bit_number;
	int		offset;
	clock_t		start,finish;
	double		wholetime;
	start = clock();

	for (int j = 0; j < SIZE*CHAR_BIT; ++j)
		set_bit(sieve,j);

	sp = &sieve[0];
	for (offset = 0,i = 3; 
			offset < SIZE*CHAR_BIT;i += 2,++offset)
		for (bit_number = i; 
				(offset+bit_number) < SIZE*CHAR_BIT; bit_number += i)
			clear_bit(sieve,offset+bit_number);
	finish = clock();

	// show 
	printf("2\n");
	for(int j = 0, i = 3; j < SIZE*CHAR_BIT; ++j, i += 2)
		if(test_bit(sp,j))
			printf("%d\n",i);

	wholetime = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Using time:%f\n", wholetime);

	return	EXIT_SUCCESS;
}

