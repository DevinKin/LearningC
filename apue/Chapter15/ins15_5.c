/*************************************************************************
    > File Name: ins15_5.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月15日 星期五 20时23分53秒
 ************************************************************************/

#include "apue.h"
int 
main(void)
{
	int		n;
	int		fd[2];
	pid_t	pid;
	char	line[MAXLINE];

	if (pipe(fd) < 0)
		err_sys("pipe error");
	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid > 0)				/* parent */
	{
		close(fd[0]);				/* close read port */
		write(fd[1], "hello world\n", 12);
	}
	else							/*  child */
	{
		close(fd[1]);				/* close write port */
		n = read(fd[0], line, MAXLINE);
		write(STDOUT_FILENO, line, n);
	}
	exit(0);
}
