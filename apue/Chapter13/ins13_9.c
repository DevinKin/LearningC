/*************************************************************************
    > File Name: ins13_9.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年11月28日 星期二 14时52分32秒
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>

int
set_cloexec(int fd)
{
	int		val;

	if ((val = fcntl(fd, F_GETFD, 0)) < 0)
		return(-1);

	val |= FD_CLOEXEC;				/*  enable close-on-exec  */

	return(fcntl(fd, F_SETFD, val));
}
