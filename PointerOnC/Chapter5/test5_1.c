/*************************************************************************
    > File Name: test5_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月25日 星期二 11时28分46秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int		ch;
	while( (ch = getchar()) != EOF) 
	{
		if( ch <= 90 && ch >= 65 )
		{
			ch += 32;
		}
		putchar(ch);
		if ( ch == '\n')
			break;
	}
	return	EXIT_SUCCESS;

}

