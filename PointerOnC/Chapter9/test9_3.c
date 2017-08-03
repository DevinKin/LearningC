/*************************************************************************
    > File Name: test9_3.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月01日 星期二 11时05分28秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>


char *
my_strcpy(const char *src, char *dst, int size)
{
	/*
	register	int		length;
	for(length = 0; length < size; ++length)
		if(*src != '\0')
			dst[length] = src[length];
		else
			break;
	dst[size - 1] = '\0';
	*/
	strncpy(dst, src, size);
	dst[size - 1] = '\0';
	return dst;
}
