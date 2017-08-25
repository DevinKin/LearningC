/*************************************************************************
    > File Name: ins8_9.c
    > Author: Elliot
 ************************************************************************/

/*
 * 程序输出两个字符串：一个由子进程输出，另一个由父进程输出。
 * 因为输出依赖于内核使这两个进程运行的顺序及每个进程运行的时间，
 * 所以该程序包含了一个竞争条件。
 */

#include "apue.h"

static void charactatime(char *);

int
main(void)
{
	pid_t	pid;
	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		charactatime("output from child\n");
	else
		charactatime("output from parent\n");

	exit(0);
}

static void
charactatime(char *str)
{
	char	*ptr;
	int		c;

	setbuf(stdout, NULL);				/*  set unbuffered  */

	for(ptr = str; (c = *ptr++) != 0;)
		putc(c, stdout);
}
