/*************************************************************************
    > File Name: bitarray.h
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月26日 星期三 08时22分04秒
 ************************************************************************/
#include <limits.h>
#ifndef _BITARRAY_H
#define	_BITARRAY_H

void set_bit(char bit_array[],
		unsigned bit_number);

void clear_bit(char bit_array[],
		unsigned bit_number);

void assign_bit(char bit_array[],
		unsigned bit_number, int value);

int test_bit(char bit_array[],
		unsigned bit_number);

#endif	
