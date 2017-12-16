/*************************************************************************
    > File Name: ins15_14.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月16日 星期六 20时30分09秒
 ************************************************************************/

#include "apue.h"
#include <ctype.h>

int main(void)
{
	int		c;

	while ((c = getchar()) != EOF)
	{
		if (isupper(c))
			c = tolower(c);
		if (putchar(c) == EOF)
			err_sys("output error");
		if (c == '\n')
			fflush(stdout);
	}
	exit(0);
}
