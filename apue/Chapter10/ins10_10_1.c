/*************************************************************************
    > File Name: ins10_10_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年09月05日 星期二 21时33分45秒
 ************************************************************************/

#include <signal.h>
#include <unistd.h>

static void
sig_alrm(int signo)
{
	/*  nothing to do, just return to wake up the pause */
}


unsigned int
sleep1(unsigned int seconds)
{
	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		return(seconds);

	alarm(seconds);							/*  start the timer  */
	pause();								/*  next caught signal wakes us up  */
	return(alarm(0));						/*  turn off timer, return unslept time  */
}
