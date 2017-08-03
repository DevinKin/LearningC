/*************************************************************************
    > File Name: test5_3.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月25日 星期二 12时43分29秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

unsigned long int reverse_bits( unsigned int value )
{
	unsigned long int sum = 0;
	int bit = 0;
	for ( int i =1;
			i < sizeof(unsigned int)*8; ++i)
	{
		bit = value & 1;
		value >>= 1;
		sum += bit;
		sum <<= 1;
		printf("%ld\n",sum);
	}
	return sum;
}

int main(void)
{
	int		value = 25;
	printf("%ld\n", reverse_bits(value));
	return	EXIT_SUCCESS;
}
