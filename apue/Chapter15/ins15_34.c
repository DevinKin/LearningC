/*************************************************************************
    > File Name: ins15_33.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月24日 星期日 12时55分51秒
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>
#include <sys/mman.h>

#define NLOOPS	1000
#define SIZE	sizeof(long)			/* size of shared memory area */
#define MAP_ANONYMOUS 0x20

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
	void	*area;

	if ((area = mmap(0, SIZE, PROT_READ | PROT_WRITE,  MAP_ANONYMOUS | MAP_SHARED, -1, 0)) == MAP_FAILED)
		err_sys("mmap error");

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
			if ((counter = update((long *)area)) != i)
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
			if ((counter = update((long *) area)) != i)
				err_quit("child: expected %d, got %d", i, counter);

			TELL_PARENT(getppid());
		}
	}

	exit(0);
}
