/*************************************************************************
    > File Name: test9_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月01日 星期二 11时01分35秒
 ************************************************************************/

#include <stdio.h>

size_t
my_strlen(const char *string, int size)
{
	register	int		length;
	for(length = 0; length < size; ++length)
		if(*string++ == '\0')
			break;
	return	length;
}
