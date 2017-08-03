/*************************************************************************
    > File Name: ins1_6-2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月15日 星期六 20时11分34秒
 ************************************************************************/

#include "apue.h"
#include <wait.h>

int main(void)
{
	char	buf[MAXLINE];	/* form apue.h */
	pid_t	pid;
	int		status;

	printf("%% ");			/* print prompt (printf requires %% to print %)) */
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf)-1] == '\n')
			buf[strlen(buf)-1]=0;		/*replace newline with null */

		if ((pid = fork()) < 0) {
			err_sys("fork error");
		} else if (pid == 0) {	/* child */
			execlp(buf, buf, (char *)0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}

		/* parent */
		if ((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		printf("%% ");

	}

}

