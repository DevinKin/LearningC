/*************************************************************************
    > File Name: test1_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月24日 星期一 11时24分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define		MAX_INPUT	1024
int main(void)
{
	char	buffer[MAX_INPUT];
	int		linenum=1;
	while (fgets(buffer,MAX_INPUT,stdin) != NULL) 
	{
		printf("%d\t\t\t",linenum);
		puts(buffer);
		linenum++;
	}
	return	EXIT_SUCCESS;
}

