/*************************************************************************
    > File Name: ruptimeserv2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月30日 星期六 14时14分13秒
 ************************************************************************/

#include "apue.h"
#include <netdb.h>
#include <errno.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <signal.h>

#define QLEN 10

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 256
#endif

extern int initserver(int, const struct sockaddr *, socklen_t, int);

static void 
sig_child(int signo)
{
	while (waitpid((pid_t)-1, NULL, WNOHANG) > 0)
		;
}


void
serve(int sockfd)
{
	int		clfd, status;
	pid_t	pid;

	set_cloexec(sockfd);

	for(;;)
	{
		if ((clfd = accept(sockfd, NULL, NULL)) < 0)
		{
			syslog(LOG_ERR, "ruptimed: accept error: %s",
					strerror(errno));
			exit(1);
		}
		
		if ((pid = fork()) < 0)
		{
			syslog(LOG_ERR, "ruptimed: fork error: %s",
					strerror(errno));
			exit(1);
		}
		else if (pid == 0)			/* child */
		{
			/*
			 * The parent called daemonize, so
			 * STDIN_FILENO, STDOUT_FILENO and  STDERR_FILENO
			 * are already open to /dev/null, Thus the call to 
			 * close doesn't need to be protected by checks that 
			 * clfd isn't  already equal to one of these values.
			 */
			if (dup2(clfd, STDOUT_FILENO) != STDOUT_FILENO ||
					dup2(clfd, STDERR_FILENO) != STDERR_FILENO)
			{
				syslog(LOG_ERR, "ruptimed: unexpected error");
				exit(1);
			}
			close(clfd);
			execl("/usr/bin/uptime", "uptime", (char *)0);
			syslog(LOG_ERR, "ruptime: unexpected return from exec: %s",
					strerror(errno));
		}
		else				/* parent */
		{
			close(clfd);
		}
	}
}


int
main(int argc, char *argv[])
{
	struct addrinfo		*alist, *aip;
	struct addrinfo		hint;
	int					sockfd, err, n;
	char				*host;

	struct	sigaction nact, oact;
	nact.sa_handler = sig_child;
	sigemptyset(&nact.sa_mask);
	if (sigaction(SIGCHLD, &nact, &oact) < 0)
		err_sys("sigaction error");

	if (argc != 1)
		err_quit("usage: ruptimed");
	if ((n = sysconf(_SC_HOST_NAME_MAX)) < 0)
		n = HOST_NAME_MAX;				/* best guest */

	if ((host = malloc(n)) == NULL)
		err_sys("malloc error");

	if (gethostname(host, n) < 0)
		err_sys("gethostname error");

	daemonize("ruptimed");
	memset(&hint, 0, sizeof(hint));
	hint.ai_flags = AI_CANONNAME;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;

	if ((err = getaddrinfo(host, "ruptime", &hint, &alist)) != 0)
	{
		syslog(LOG_ERR, "ruptimed: getaddrinfo error: %s",
				gai_strerror(err));
		exit(1);
	}

	for (aip = alist; aip != NULL; aip = aip->ai_next)
	{
		if ((sockfd = initserver(SOCK_STREAM, aip->ai_addr,
						aip->ai_addrlen, QLEN)) >= 0)
		{
			serve(sockfd);
			exit(0);
		}
	}
	if (sigaction(SIGCHLD, &oact, NULL) < 0)
		err_sys("sigaction error");
	exit(1);
}
