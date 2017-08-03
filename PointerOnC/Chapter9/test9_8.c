/*************************************************************************
    > File Name: test9_8.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月01日 星期二 14时31分06秒
 ************************************************************************/

#include <stdio.h>


char *
my_strnchr(char const *str, int ch, int which)
{
	while(str != NULL && which > 0)
	{
		str = strch(str, ch);
		which--;
		str++;
	}
	return	str;
}
