/*************************************************************************
    > File Name: ins8_1.c
    > Author: Elliot
 ************************************************************************/

/*
 * 程序演示了fork函数，从中可以看到子进程对变量所做的改变并不影响父进程中该变量的值。
 */

#include "apue.h"

int		globvar = 6;			/*  external variable in initialized data  */
char	buf[] = "a write to stdout\n";

int
main(void)
{
	int		var;				/*  automatic variable on the stack  */
	pid_t	pid;

	var = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
		err_sys("write error");

	printf("before fork\n");			/*  we don't flush stdout  */

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)					/*  child */
	{
		globvar++;						/*  modify variables  */
		var++;
	}
	else
		sleep(2);						/*  parent  */
	
	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
	exit (0);
}
