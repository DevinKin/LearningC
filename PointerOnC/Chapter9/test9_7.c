/*************************************************************************
    > File Name: test9_7.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月01日 星期二 14时26分54秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char *
my_strrchr(char const *str,	int ch)
{
	char	*last = NULL;
	while(str != NULL)
	{
		str = strchr(str,ch);
		last = str++;
	}
	return	last;
}
