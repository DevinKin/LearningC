/*************************************************************************
    > File Name: test15_10.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月03日 星期三 16时06分02秒
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>

#define		FIFO		"temp.fifo"


int 
main(void)
{
	int		fdread, fdwrite;

	if (mkfifo(FIFO, FILE_MODE) < 0)
		err_sys("mkfifo error");
	if ((fdread = open(FIFO, O_RDONLY | O_NONBLOCK)) < 0)
		err_sys("open error for reading");
	if ((fdwrite = open(FIFO, O_WRONLY)) < 0)
		err_sys("open error for writing");

	clr_fl(fdread, O_NONBLOCK);
	exit(0);
}
