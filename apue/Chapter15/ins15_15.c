/*************************************************************************
    > File Name: ins15_15.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月16日 星期六 20时34分17秒
 ************************************************************************/

#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
	char	line[MAXLINE];
	FILE	*fpin;

	if ((fpin = popen("./myuclc", "r")) == NULL)
		err_sys("popen error");

	for (; ;)
	{
		fputs("prompt> ", stdout);
		fflush(stdout);
		if (fgets(line, MAXLINE, fpin) == NULL)					/* read from pipe */
			break;
		if (fputs(line, stdout) == EOF)
			err_sys("fputs error to pipe");
	}
	if (pclose(fpin) == -1)
		err_sys("pclose error");
	putchar('\n');
	exit(0);
}
