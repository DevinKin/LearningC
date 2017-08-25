/*************************************************************************
    > File Name: ins8_14.c
    > Author: Elliot
 ************************************************************************/
/*
 * 为了得到某些会计数据以便查看
 */


#include "apue.h" 

int
main(void)
{
	pid_t	pid;

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid != 0)				/*  parent  */
	{
		sleep(2);
		exit(2);					/*  terminate with exit status 2  */
	}

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid != 0)				/*  first child  */
	{
		sleep(4);
		abort();					/*  terminate with core dump  */
	}

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid != 0)
	{
		execl("/bin/dd", "dd", "if = /etc/passwd", "of=/dev/null", NULL);
		exit(7);					/*  shouldn't get here  */
	}

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid != 0)				/*  third child  */
	{
		sleep(8);
		exit(0);					/*  normal exit  */
	}

	sleep(6);						/*  fourth child  */
	kill(getpid(), SIGKILL);		/*  terminate w/signal, no core dump  */
	exit(6);						/*  should't get here  */
}
