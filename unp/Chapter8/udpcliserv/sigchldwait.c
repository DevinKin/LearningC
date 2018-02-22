/*************************************************************************
    > File Name: sigchldwait.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月28日 星期日 21时58分45秒
 ************************************************************************/

#include "unp.h"

void
sig_chld(int signo)
{
	pid_t pid;
	int stat;

	pid = wait(&stat);
	printf("child %d terminated\n", pid);
	return;
}
