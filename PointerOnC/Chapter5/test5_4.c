/*************************************************************************
    > File Name: test5_4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月25日 星期二 14时37分59秒
 ************************************************************************/

#include <stdio.h>
#include <limits.h>

#define		INT_BITS	(CHAR_BIT*sizeof(int))

int store_bit_field(int orginal_value,
		int value_to_store,
		unsigned starting_bit, unsigned ending_bit)
{
	/*	 create mask	*/
	unsigned	mask;
	
	if (starting_bit <= INT_BITS && ending_bit <= INT_BITS && starting_bit > ending_bit)
	{
		mask = -1;				//0xfffff
		mask >>= INT_BITS - (starting_bit - ending_bit + 1);
		mask <<= ending_bit;

		//step 2
		orginal_value &= ~mask;

		//step 3
		value_to_store <<= ending_bit;

		//step 4 
		value_to_store &= mask;

		//step 5
		orginal_value |= value_to_store;

	}
	return orginal_value;
}

