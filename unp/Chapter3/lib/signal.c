/*************************************************************************
    > File Name: signal.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月28日 星期日 21时51分36秒
 ************************************************************************/

#include "unp.h"

Sigfunc *
signal(int signo, Sigfunc *func)
{
	struct sigaction act, oact;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if (signo == SIGALAM) {
#ifdef SA_INTERRUPT
		act.sa_flags |= SA_INTERRUPT;			/* SunOS 4.x */
#endif
	} else {
#ifdef SA_RESTART
		act.sa_flags |= SA_RESTART;				/* SVR4, 4.4BSD */
#endif
	}
	if (sigaction(signo, &act, &oact) < 0)
		return(SIG_ERR);
	return(oact.sa_handler);
}
