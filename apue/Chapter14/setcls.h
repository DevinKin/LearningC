/*************************************************************************
    > File Name: setcls.h
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年11月29日 星期三 23时31分09秒
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>


void set_fl(int fd, int flags)	/*  flags are file status flags to turn on  */
{
	int		val;

	if ((val = fcntl(fd, F_GETFL, 0)) < 0)
		err_sys("fcntl F_GETFL error");

	val |= flags;				/*  turn on flags  */


	if (fcntl(fd, F_SETFL, val) < 0)
		err_sys("fcntl F_SETFL error");
}


void clr_fl(int fd, int flags)
{
	int		val;

	if ((val = fcntl(fd, F_GETFL, 0)) < 0)
		err_sys("fcntl F_GETFL, error");

	val &= ~flags;				/*  turn off flags  */

	if (fcntl(fd, F_SETFL, val) < 0)
		err_sys("fcntl F_SETFL error");
}


