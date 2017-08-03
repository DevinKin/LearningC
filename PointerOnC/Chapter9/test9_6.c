/*************************************************************************
    > File Name: test9_6.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月01日 星期二 11时46分54秒
 ************************************************************************/

#include <stdio.h>


char *
my_strcpy_end(char *dest, const char *src)
{
	strcpy(dest, src);
	return dest + strlen(src);

}
