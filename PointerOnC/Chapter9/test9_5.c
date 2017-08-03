/*************************************************************************
    > File Name: test9_5.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月01日 星期二 11时30分19秒
 ************************************************************************/

#include <stdio.h>

void
my_strncat(char *dest, char *src, int dest_len)
{
	register	 int		len;
	len = strlen(dest);
	dest_len -= len + 1;
	if(len > 0)
	{
		strncat(dest, src, length);
		dest[dest_len] = '\0';
	}
}
