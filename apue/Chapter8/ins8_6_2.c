/*************************************************************************
    > File Name: ins8_6_2.c
    > Author: Elliot
 ************************************************************************/

/*
 * 如果一个进程fork一个子进程，但不要它等待子进程终止，也不希望进程
 * 处于僵死状态直到父进程终止，实现这一要求的诀窍是调用fork两次。
 */

#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
	pid_t	pid;
	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
	{
		if ((pid = fork()) < 0)				/*  first child  */
			err_sys("fork error");
		else if (pid > 0)
			exit(0);						/*  parent from second fork == first child  */
		/*
		* We're the second child; our parent become init as soon
		* as our real parent calls exit() in the statement above.
		* Here's where we'd continue executing, knowing that when
		* We're done, init will reap our status.
		*/
		sleep(2);
		printf("second child, parent pid = %ld\n", (long)getppid());
		exit(0);
	}
	if (waitpid(pid, NULL, 0) != pid)		/* wait for first child and don't care its ending state  */
		err_sys("waitpid error");

	/*
	 * We're the parent (the original process); we continue executing,
	 * knowing that we're not the parent of the second child.
	 */
	exit(0);

}
