/*************************************************************************
    > File Name: test9_9.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月01日 星期二 14时43分21秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define		TRUE	1
#define		FALSE	0

int
palidrome(char *string)
{
	char	*right = string + strlen(string) - 1;
	while(string < right)
	{
		while(!isalpha(*string))
			string++;
		while(!isalpha(*right))
			right--;
		if(tolower(*string) != tolower(*right))
			return FALSE;
		string++;
		right--;
	}
	return	TRUE;

}
