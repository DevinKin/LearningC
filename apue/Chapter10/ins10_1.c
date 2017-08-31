/*************************************************************************
    > File Name: ins10_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月31日 星期四 15时50分46秒
 ************************************************************************/

#include <stdio.h>
#include "apue.h"

static void sig_usr(int);			/*  one handler for both signals  */


int
main(void)
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		err_sys("can't catch SIGUSR1");

	if (signal(SIGUSR2, sig_usr) ==SIG_ERR)
		err_sys("cant't catch SIGUSR2");

	for (; ;)
		pause();
}

static void
sig_usr(int signo)			/*  argument is signal number  */
{
	if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
		err_dump("received signal %d\n", signo);
}

