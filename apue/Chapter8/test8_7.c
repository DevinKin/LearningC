/*************************************************************************
    > File Name: test8_7.c
    > Author: Elliot
 ************************************************************************/
#include "apue.h"
#include <dirent.h>
#include <fcntl.h>
#include <sys/wait.h>

int
main(void)
{
	DIR		*dir;
	int		fd;
	int		fd_flags;
	int		status;
	char	buf[10];				/*  save fd  */
	pid_t	pid;

	if ((dir = opendir("/")) == NULL)
		err_sys("opendir error");

	if ((fd = dirfd(dir)) < 0)		/*  get fd  */
		err_sys("get dir fd error");

	sprintf(buf, "%d\0", fd);

	if ((fd_flags = fcntl(fd, F_GETFD, 0)) < 0)
		err_sys("get fd flags error");

	if (fd_flags & FD_CLOEXEC)
		printf("close-on-exec is on\n");
	else
		printf("close-on-exec is off\n");

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
	{
		execl("/home/king/LearningC/apue/Chapter8/child", "child", buf, NULL);
		exit(0);
	}
	
	if ((pid = waitpid(pid, NULL, 0)) < 0)
		err_sys("waitpid erro");

	exit(0);
}
