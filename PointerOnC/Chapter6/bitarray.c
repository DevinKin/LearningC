/*************************************************************************
    > File Name: bit.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月26日 星期三 08时18分18秒
 ************************************************************************/

#include <stdlib.h>
#include "bitarray.h"

unsigned character_offset(unsigned bit_number);
unsigned bit_offset(unsigned bit_number);

void set_bit(char bit_array[],
		unsigned bit_number)
{
	bit_array[character_offset(bit_number)] |= 1 << bit_offset(bit_number);

}

void clear_bit(char bit_array[],
		unsigned bit_number)
{
	bit_array[character_offset(bit_number)] &= ~(1 << bit_offset(bit_number));
}

void assign_bit(char bit_array[],
		unsigned bit_number, int value) 
{
	if (value != 0)
		set_bit(bit_array,bit_number);
	else
		clear_bit(bit_array,bit_number);

}


int test_bit(char bit_array[],
		unsigned bit_number)
{
	unsigned short int mask = 0;
	mask = 1 << bit_offset(bit_number);
	int value = bit_array[character_offset(bit_number)] & mask;
	if (value)
		return 1;
	else
		return 0;
}

unsigned character_offset(unsigned bit_number)
{
	return bit_number / CHAR_BIT;
}

unsigned bit_offset(unsigned bit_number)
{
	return bit_number % CHAR_BIT;
}
