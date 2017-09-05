/*************************************************************************
    > File Name: ins10_10_4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年09月05日 星期二 22时44分53秒
 ************************************************************************/

#include "apue.h"

static void		sig_alrm(int);

int
main(void)
{
	int		n;
	char	line[MAXLINE];
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		err_sys("signal(SIGALRM) error");

	alarm(10);
	if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
		err_sys("read error");
	alarm(0);

	write(STDOUT_FILENO, line, n);
	exit(0);
}

static void
sig_alrm(int signo)
{
	/*  nothing to do, just return to interupt the read  */
}


