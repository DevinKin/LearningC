/*************************************************************************
    > File Name: ins10_14_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年09月10日 星期日 10时25分50秒
 ************************************************************************/

#include "apue.h"

Sigfunc *
signal_intr(int signo, Sigfunc *func)
{
	struct	sigaction	act, oact;

	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

#ifdef	SA_INTERRUPT
	act.sa_flags |= SA_INTERRUPT;
#endif
	if (sigaction(signo, &act, &oact) < 0)
		return (SIG_ERR);
	return(oact.sa_handler);
}


