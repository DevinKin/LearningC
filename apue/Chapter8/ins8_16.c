/*************************************************************************
    > File Name: ins8_16.c
    > Author: Elliot
 ************************************************************************/

/*
 * 进程度量了调用进程nice值的效果。两个进程并行运行，各自增加自己的计数器。
 * 父进程使用了默认的nice值，子进程以可选命令参数指定的调整后的nice值运行。
 * 运行10s后，两个进程都打印各自的计数值并中止。通过比较不同nice值的进程计数值的差异，
 * 我们可以了解nice值是如何影响进程调度的。
 */

#include "apue.h"
#include <errno.h>
#include <sys/time.h>

#if		defined(MACOS)
#include <sys/syslimits.h>
#elif	defined(SOLARIS)
#include <limits.h>
#elif	defined(BSD)
#include <sys/param.h>
#endif

unsigned long long count;
struct	timeval end;

void
checktime(char *str)
{
	struct	timeval tv;

	gettimeofday(&tv, NULL);

	if (tv.tv_sec >= end.tv_sec && tv.tv_usec >= end.tv_usec)
	{
		printf("%s count = %lld\n", str, count);
		exit(0);
	}
}

int
main(int argc, char *argv[])
{
	pid_t	pid;
	char	*s;
	int		nzero, ret;
	int		adj = 0;

	setbuf(stdout, NULL);			/*  关闭缓冲  */

#if		defined(NZERO)
	nzero = NZERO;
#elif	defined(_SC_NZERO)
	nzero = sysconf(_SC_NZERO);
#else
#error	NZERO	undefined
#endif 
	printf("NZERO = %d\n", nzero);
	if (argc == 2)
		adj = strtol(argv[1], NULL, 10);
	gettimeofday(&end, NULL);
	end.tv_sec += 10;						/*  run for 10 seconds  */
	
	if ((pid = fork()) < 0)
		err_sys("fork failed");
	else if (pid == 0)						/*  child  */
	{
		s = "child";
		printf("current nice value in child is %d, adjusting by %d\n",
				nice(0)+nzero, adj);
		errno = 0;
		if ((ret = nice(adj)) == -1 && errno != 0)
			err_sys("child set scheduling priorty");
		printf("now child nice value is %d\n", ret + nzero);
	}
	else				/*  parent  */
	{
		s = "paren";
		printf("current nice value in parent is %d\n", nice(0) + nzero);
	}
	for (;;)
	{
		if (++count == 0)
			err_quit("%s counter wrap", s);
		checktime(s);
	}

}
