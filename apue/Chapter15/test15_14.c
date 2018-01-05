/*************************************************************************
    > File Name: ins15_33.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月24日 星期日 12时55分51秒
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>

#define NLOOPS	1000
#define SIZE	sizeof(long)			/* size of shared memory area */

static int
update(long *ptr)
{
	printf("%ld\n", *ptr);
	return((*ptr)++);					/* return value before increment */
}


int 
main(void)
{
	int		i, counter;
	pid_t	pid;
	void	*shmptr;
	int		shmid;


	if ((shmid = shmget(IPC_PRIVATE, SIZE, 0666 | IPC_CREAT)) < 0)
		err_sys("shmget error");
	if ((shmptr = shmat(shmid, 0, 0)) == (void *)-1)
		err_sys("shmat error");

	TELL_WAIT();

	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid > 0)					/* parent */
	{
		for (i = 0; i < NLOOPS; i += 2)
		{
			printf("parent\n");
			if ((counter = update((long *)shmptr)) != i)
				err_quit("parent: expected %d, got %d", i, counter);
			TELL_CHILD(pid);
			WAIT_CHILD();
		}
	}
	else								/* child */
	{
		for (i = 1; i < NLOOPS + 1; i += 2)
		{
			WAIT_PARENT();
			printf("child\n");
			if ((counter = update((long *) shmptr)) != i)
				err_quit("child: expected %d, got %d", i, counter);

			TELL_PARENT(getppid());
		}
	}

	if (shmdt(shmptr) < 0)
		err_sys("shmdt error");

	exit(0);
}
