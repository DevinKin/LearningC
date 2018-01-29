/*************************************************************************
    > File Name: sigchldwaaitpid.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月28日 星期日 22时42分41秒
 ************************************************************************/

#include "unp.h"

void
sig_chld(int signo)
{
	pid_t pid;
	int stat;

	while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
		printf("child %d terminated\n", pid);
	return;
}
