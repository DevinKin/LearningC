/*************************************************************************
    > File Name: test9_4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月01日 星期二 11时17分22秒
 ************************************************************************/

#include <stdio.h>


char *
my_strcat(char *dst, const char *src, int size)
{
	int		length;
	size -= 1;
	length = size - (int)my_strlen(dst,size);
	if(length > 0)
	{
		strncat(dst, src, length);
		dst[size] = '\0';
	}
	return	dst;
}
