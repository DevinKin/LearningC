/*************************************************************************
    > File Name: test6_5_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月26日 星期三 11时17分01秒
 ************************************************************************/

#include <stdio.h>
#include "bitarray.h"
#include <time.h>
#include <stdlib.h>

#define		MAX_VALUE	51000
#define		MAX_BIT_NUMBER	((MAX_VALUE -3) / 2)
#define		SIZE	(MAX_BIT_NUMBER / CHAR_BIT +1)

int main(void)
{
	char	sieve[SIZE];
	int		number;
	int		bit_number;
	char	*sp;
	clock_t		start,finish;
	double		wholetime;
	start = clock();
	printf("%d\n",SIZE);
	printf("%d\n",MAX_BIT_NUMBER);

	for(sp = sieve; sp <&sieve[SIZE];
			*sp++ = 0xff);
	
	for(number = 3; number <= MAX_VALUE; number += 2)
	{
		bit_number = (number - 3) / 2;

		if ( !test_bit(sieve, bit_number))
			continue;

		while ((bit_number += number) <= MAX_BIT_NUMBER)
			clear_bit(sieve,bit_number);
	}
	finish = clock();

	printf("2\n");
	for(bit_number = 0, number = 3; 
			number <= MAX_VALUE;
			bit_number += 1, number += 2)
		if(test_bit(sieve,bit_number))
			printf("%d\n",number);
	wholetime = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Using time:%f\n", wholetime);
	return	EXIT_SUCCESS;
}
