/*************************************************************************
    > File Name: ins10_14.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年09月10日 星期日 10时15分02秒
 ************************************************************************/

#include <apue.h>

/*  Reliable version of signal(), using POSIX sigaction().  */

Sigfunc *
signal(int signo, Sigfunc *func)
{
	struct	sigaction act, oact;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	if (signo == SIGALRM)
	{
#ifdef	SA_INTERUPT
		act.sa_flags |= SA_INTERRUPT;
#endif
	}
	else 
	{
		act.sa_flags |= SA_RESTART;
	}

	if (sigaction(signo, &act, &ocat) < 0) 
		return(SIG_ERR);

	return(oact.sa_handler);
}
