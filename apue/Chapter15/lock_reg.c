/*************************************************************************
    > File Name: ins14_5.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月02日 星期六 21时48分37秒
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>

int 
lock_reg(int fd, int cmd, int type, off_t offset, int whence, off_t len)
{
	struct flock lock;

	lock.l_type = type;			/* F_RDLCK, F_WRLCK, F_UNLCK */
	lock.l_start = offset;		/* byte offset, relative to l_whence */
	lock.l_whence = whence;		/* SEEK_SET, SEEK_CUR, SEEK_END */
	lock.l_len = len;			/*  #bytes (0 means to EOF) */

	return(fcntl(fd, cmd, &lock));
}
