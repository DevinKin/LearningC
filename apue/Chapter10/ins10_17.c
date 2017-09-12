/*************************************************************************
    > File Name: ins10_17.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年09月12日 星期二 13时44分58秒
 ************************************************************************/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void
abort(void)						/*  POSIX-style abort() function  */
{
	sigset_t	mask;
	struct	sigaction	action;

	/*  Caller can't  ignore SIGABRT, if so reset to default  */
	sigaction(SIGABRT, NULL, &action);
	if (action.sa_handler == SIG_IGN)
	{
		action.sa_handler = SIG_DFL;
		sigaction(SIGABRT, &action, NULL);				
	}

	if (action.sa_handler == SIG_DFL)
		fflush(NULL);						/*  flush all open stdio streams  */


	/*  Caller can't block SIGABRT; make sure it's unblocked  */
	sigfillset(&mask);
	sigdelset(&set, SIGABRT);				/*  MASK HAS ONLY sigabrt turned off  */
	sigprocmask(SIG_SETMASK, &mask, NULL);
	kill(getpid(), SIGABRT);				/*  send the signal  */

	/*  if we're here, process caught SIGABRT and returned  */
	fflush(NULL);							/*  flush all open stdio streams  */
	action.sa_handler = SIG_DFL;			
	sigaction(SIGABRT, &action, NULL);		/*  reset to default  */
	kill(getpid(), SIGABRT);				/*  and one more time  */
	exit(1);								/*  this should never be executed ...  */
}

