/*************************************************************************
    > File Name: ins15_33.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月24日 星期日 12时55分51秒
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define NLOOPS	1000
#define SIZE	sizeof(long)			/* size of shared memory area */

extern int lock_reg(int, int, int, off_t, int, off_t);
extern pid_t lock_test(int, int, off_t, int, off_t);

static int
update(long *ptr)
{
	printf("%ld\n", *ptr);
	return((*ptr)++);					/* return value before increment */
}


int 
main(void)
{
	int		fd, i, counter;
	pid_t	pid;
	pid_t	pid2;
	void	*area;


	if ((fd = open("/dev/zero", O_RDWR)) < 0)
		err_sys("open error");
	if ((area = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
		err_sys("mmap error");
	//close(fd);							/* can close /dev/zero now that it's mapped */

	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid > 0)					/* parent */
	{
		for (i = 0; i < NLOOPS; i += 2)
		{
			if (write_lock(fd, 0, SEEK_SET, 1) < 0) 
				err_sys("parent writew_lock error");
			while((pid2 = lock_test(fd, F_WRLCK, 1, SEEK_SET, 1)) > 0)
				;
			printf("parent\n");
			if ((counter = update((long *)area)) != i)
				err_quit("parent: expected %d, got %d", i, counter);
			if (un_lock(fd, 0, SEEK_SET, 1) < 0)
				err_sys("parent un_lock error");
		}
	}
	else								/* child */
	{
		for (i = 1; i < NLOOPS + 1; i += 2)
		{
			if (write_lock(fd, 1, SEEK_SET, 1) < 0) 
				err_sys("child writew_lock error");
			while((pid2 = lock_test(fd, F_WRLCK, 0, SEEK_SET, 1)) > 0)
				;
			printf("child\n");
			if ((counter = update((long *) area)) != i)
				err_quit("child: expected %d, got %d", i, counter);
			if (un_lock(fd, 1, SEEK_SET, 1) < 0)
				err_sys("parent un_lock error");
		}
	}

	exit(0);
}
