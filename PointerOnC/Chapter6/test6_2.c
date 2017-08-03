/*************************************************************************
    > File Name: test6_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月25日 星期二 19时31分37秒
 ************************************************************************/

#include <stdio.h>

char * match(char *str, char *want)
{
	while( *want != '\0' )
	{
		if (*str++ != *want++)
			return NULL;
	}
	return want;
}

int del_substr(char *str, char const *substr)
{
	char	*temp;
	while ( *str != '\0')
	{
		str++;
		temp = match(str,substr);
		if (temp != NULL)
			break;
	}

	if (*str=='\0')
		return 0;

	while (*temp++ != '\0')
	{
		str = temp;
		str++;
	}
	return 1;
}
