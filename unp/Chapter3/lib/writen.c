/*************************************************************************
    > File Name: writen.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月27日 星期六 00时27分29秒
 ************************************************************************/

#include "unp.h"

ssize_t									/* Write "n" bytes to a descriptor. */
writen(int fd, const void *vptr, size_t n)
{
	size_t nleft;
	ssize_t nwritten;
	const char *ptr;

	ptr = vptr;
	nleft = n;
	while (nleft > 0) {
		if ((nwritten = write(fd, ptr, nleft)) <= 0) {
			if (nwritten == 0 && errno == EINTR)
				nwritten = 0;				/* and call write() again */
			else
				return(-1);					/* error */
		}
		nleft -= nwritten;
		ptr += nwritten;
	}
	return(n);
}

