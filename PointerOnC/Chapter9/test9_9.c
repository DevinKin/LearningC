/*************************************************************************
    > File Name: test9_9.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月01日 星期二 14时56分16秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int 
count_chars(char const *str,
		char const *chars)
{
	int		count = 0;
	while( (str = strpbrk(str, chars)) != NULL)
	{
		count += 1;
		str++;
	}
	return	count;
}
