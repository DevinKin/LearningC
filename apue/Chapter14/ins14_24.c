/*************************************************************************
    > File Name: ins14_24.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月12日 星期二 19时43分52秒
 ************************************************************************/

#include "apue.h"

ssize_t				/* Read "n" bytes from a descriptor */
readn(int fd, void *ptr, size_t n)
{
	size_t nleft;
	ssize_t nread;

	nleft = n;
	while (nleft > 0)
	{
		if ((nread = read(fd, ptr, nleft)) < 0)
		{
			if (nleft == n)
				return(-1);			/* error, return -1 */
			else
				break;				/* error, return amount read so far */
		}
		else if (nread == 0)
			break;			/* EOF */
		nleft -= nread;
		ptr += nread;
	}
	return(n- nleft);			/* return >= 0 */
}

ssize_t				/*  Write "n" bytes to descriptor */
writen(int fd, const void *ptr, size_t n)
{
	size_t nleft;
	ssize_t nwritten;

	nleft = n;

	while (nleft > 0) 
	{
		if ((nwritten = write(fd, ptr, nleft)) < 0)
		{
			if (nleft == n)
				return(-1);			/* error return -1 */
			else
				break;				/*  error, return amount written so fat */
		}
		else if (nwritten == 0)
			break;
		nleft -= nwritten;
		ptr += nwritten;
	}
}
