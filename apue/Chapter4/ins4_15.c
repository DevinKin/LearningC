/*************************************************************************
    > File Name: ins4_15.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Tue 08 Aug 2017 02:56:22 PM CST
 ************************************************************************/

#include <apue.h>
#include <fcntl.h>

int
main(void)
{
	if (open("tempfile", O_RDWR) < 0)
		err_sys("open error");
	if (unlink("tempfile") < 0)
		err_sys("unlink error");
	printf("file unlink\n");
	sleep(15);
	printf("done\n");
	exit (0);
}

