/*************************************************************************
    > File Name: test14_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月12日 星期二 21时10分23秒
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>
#include <errno.h>

void 
sigint(int signo)
{

}

int
main()
{
	pid_t	pid1, pid2, pid3;
	int		fd;

	setbuf(stdout, NULL);

	/*
	 * Create a file 
	 */
	if ((fd = open("lockfile2", O_RDWR | O_CREAT, 0666)) < 0)
		err_sys("can't open/create lockfile2");

	/*
	 * Read-lock the file.
	 */
	if ((pid1 = fork()) < 0)
		err_sys("fork failed");
	else if (pid1 == 0)					/* child */
	{
		if (lock_reg(fd, F_SETLK, F_RDLCK, 0, SEEK_SET, 0) < 0)				/* lock all file */
			err_sys("child1: can't read-lock file");
		printf("child1: obtained read lock on file\n");
		pause();
		printf("child1: exit after pause\n");
		exit(0);
	}
	else								/* parent */
	{
		sleep(2);
	}

	/*
	 * Parent continues ... read-lock the file again.
	 */

	if ((pid2 = fork()) < 0)
		err_sys("fork failed");
	else if (pid2 == 0)					/* child */
	{
		if (lock_reg(fd, F_SETLK, F_RDLCK, 0, SEEK_SET, 0) < 0)
			err_sys("child2: can't read-lock file");
		printf("child2: obtained read lock on file\n");
		pause();
		printf("child2: exit after pause\n");
		exit(0);
	}
	else								/* parent */
	{
		sleep(2);
	}


	/*
	 * Parent continues ... read-lock the file again.
	 */
	if ((pid3 = fork()) < 0)
		err_sys("fork failed");
	else if (pid3 == 0)					/* child3 */
	{
		if (lock_reg(fd, F_SETLK, F_WRLCK, 0, SEEK_SET, 0) < 0)
			err_sys("child 3 about to block in write-lock...\n");
		printf("child 3 return and got write lock???\n");
		pause();
		printf("child3: exit after pause\n");
		exit(0);
	}
	else								/* parent */
	{
		sleep(2);
	}


	/*
	 * See if a pending write lock will block next
	 * read-lock attempt.
	 */
	if (lock_reg(fd, F_SETLK, F_RDLCK, 0, SEEK_SET, 0) < 0)
		printf("parent: can't set read lock: %s\n", strerror(errno));
	else
		printf("parent obtained additional read lock while write lock is pending\n");
	printf("killing child 1...\n");
	kill(pid1, SIGINT);
	printf("killing child 2...\n");
	kill(pid2, SIGINT);
	printf("killing child 3...\n");
	kill(pid3, SIGINT);
	exit(0);



}
