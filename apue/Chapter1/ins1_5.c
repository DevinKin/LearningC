/*************************************************************************
    > File Name: ins1_5.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月15日 星期六 20时01分55秒
 ************************************************************************/

#include "apue.h"
int main(void)
{
	int		c;
	while ((c=getc(stdin)) != EOF)
		if (putc(c,stdout) == EOF)
			err_sys("output error");

	if (ferror(stdin))
		err_sys("input error");
	exit(0);

}
