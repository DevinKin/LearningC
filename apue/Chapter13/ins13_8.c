/*************************************************************************
    > File Name: ins13_8.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年11月28日 星期二 14时06分49秒
 ************************************************************************/

#include "apue.h"
#include <syslog.h>
#include <errno.h>


extern int lockfile(int);
extern int already_running(void);
extern void daemonize(const char *);


void
reread(void)
{
	/* ...  */
}


void
sigterm(int signo)
{
	syslog(LOG_INFO, "get SIGTERM exiting");
	exit(0);
}


void
sighup(int signo)
{
	syslog(LOG_INFO, "Re-reading configuration file");
	reread();
}


int
main(int argc, char *argv[])
{
	char		*cmd;
	struct sigaction sa;

	if ((cmd = strrchr(argv[0], '/')) == NULL)
		cmd = argv[0];
	else
		cmd++;

	/*
	 * Become a damon.
	 */
	daemonize(cmd);

	/*
	 * Make sure only one copy of the daemon is running 
	 */
	if (already_running()) {
		syslog(LOG_ERR, "daemon already running");
		exit(1);
	}


	/*
	 * Handle signals of interest.
	 */
	sa.sa_handler = sigterm;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGHUP);
	sa.sa_flags = 0;
	if (sigaction(SIGTERM, &sa, NULL) < 0)
	{
		syslog(LOG_ERR, "can't catch SIGTERM: %s", strerror(errno));
		exit(1);
	}
	sa.sa_handler = sighup;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGTERM);
	sa.sa_flags = 0;
	if (sigaction(SIGHUP, &sa, NULL) < 0)
	{
		syslog(LOG_ERR, "can't catch SIGHUP: %s", strerror(errno));
		exit(1);
	}

	
	/*
	 * Proceed with the rest of the daemon.
	 */
	/* ... */
	pause();
	exit(0);
}
