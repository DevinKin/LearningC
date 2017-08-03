/*************************************************************************
    > File Name: ins1_9.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月03日 星期四 06时40分53秒
 ************************************************************************/

#include <apue.h>
#include <wait.h>

static	void	sig_int(int);			/*	our signal-catching function  */

int
main(void)
{
	char	buf[MAXLINE];			/* from apue.h */
	pid_t	pid;
	int		status;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal error");

	printf("%% ");				/*  print prompt (printf requires %% to print %)*/
	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;			/*  replace newline with null  */
		
		if((pid = fork()) < 0)
		{
			err_sys("fork error");
		}
		else if (pid == 0)		/*  child  */
		{
			execlp(buf, buf, (char *)0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}

		if ((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		printf("%% ");
	}
	exit(0);
}

void
sig_int(int signo)
{
	printf("interrupt\n%% ");
}
