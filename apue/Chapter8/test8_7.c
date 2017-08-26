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

	//sprintf(buf, "%d\0", fd);

	if ((fd_flags = fcntl(fd, F_GETFD, 0)) < 0)
		err_sys("get fd flags error");

	/*
	 * prove: close the flags of FD_CLOEXEC
	 */


	if (fd_flags & FD_CLOEXEC)
		printf("close-on-exec is on\n");
	else
		printf("close-on-exec is off\n");

	fd_flags &= ~FD_CLOEXEC;
	/*
	 * 关闭FD_CLOEXEC标志后，执行exec函数，关闭打开的目录流，但不会关闭与该流相关的
	 * 文件描述符。
	 */

	fcntl(fd, F_SETFD, fd_flags);
	sprintf(buf, "%d\0", fd);

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
