/*************************************************************************
    > File Name: ins10_16_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年09月12日 星期二 09时37分24秒
 ************************************************************************/

#include "apue.h"

volatile sig_atomic_t	quitflag;			/*  set nonzero by signal handler  */

static void
sig_int(int signo)
{
	if (signo == SIGINT)
		printf("\ninterrupt\n");	
	else if (signo == SIGQUIT)
		quitflag = 1;						/*  set flag main loop  */
}


int
main(void)
{
	sigset_t	newmask, oldmask, zeromask;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");

	if (signal(SIGQUIT, sig_int) == SIG_ERR)
		err_sys("signal(SIGQUIT) error");

	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGQUIT);

	/*
	 * Block SIGQUIT and save current signal mask
	 */
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error");

	while (quitflag == 0)
		sigsuspend(&zeromask);

	/*
	 * SIGQUIT has been caught and is now blocked; do whatever.
	 */
	quitflag = 0;

	/*
	 * Reset signal mask which unblocks SIGQUIT.
	 */
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
	
	exit(0);
}
