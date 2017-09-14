/*************************************************************************
    > File Name: ins10_18.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年09月14日 星期四 10时22分35秒
 ************************************************************************/

#include "apue.h"

static void
sig_int(int signo)
{
	printf("caught SIGINT\n");
}


static void
sig_child(int signo)
{
	printf("caught SIGCHLD\n");
}

int
main(void)
{
	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");
	if (signal(SIGCHLD, sig_child) == SIG_ERR)
		err_sys("signal(SIGCHLD) error");

	if (system("/bin/ed") < 0)
		err_sys("system() error");
	exit(0);
}
