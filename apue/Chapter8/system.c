/*************************************************************************
    > File Name: ins8_13.c
    > Author: Elliot
 ************************************************************************/

/*
 * system函数的一种实现。它对信号没有处理。
 */


#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include "apue.h"

int
system(const char *cmdstring)			/*  version without signal handling  */
{
	pid_t	pid;
	int		status;

	if (cmdstring == NULL)
		return(1);						/*  always a command processor with UNIX  */

	if ((pid = fork()) < 0)
	{
		status = -1;					/*  probably out of processes  */
	}
	else if (pid == 0)
	{
		execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
		_exit(127);						/*  execl error  */
	}
	else
	{
		while (waitpid(pid, &status, 0) < 0)
			if (errno != EINTR)
			{
				status = -1;				/*  error other than EINTR from waitpid()  */
				break;
			}
	}
	return(status);

}


void
pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("nomal termination, exit status %d\n",
			   	WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n",
				WTERMSIG(status),
#ifdef	WCOREDUMP
	WCOREDUMP(status) ? " (core file generated) " : "");
#else
		"");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n",
				WSTOPSIG(status));
}
