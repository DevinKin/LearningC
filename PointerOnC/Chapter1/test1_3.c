/*************************************************************************
    > File Name: test1_3.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月24日 星期一 11时38分17秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int		c;
	signed char		sum = -1;

	while ( (c=getchar()) != EOF && c != '\n')
	{
		putchar(c);
		sum+=c;
	}
	printf("%d\n",sum);
	return	EXIT_SUCCESS;
}

