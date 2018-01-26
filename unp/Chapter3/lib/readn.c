/*************************************************************************
    > File Name: readn.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月27日 星期六 00时20分22秒
 ************************************************************************/

#include "unp.h"


ssize_t							/* Read "n" bytes from a descriptor. */
readn(int fd, void *vptr, size_t n)
{
	size_t nleft;
	ssize_t nread;
	char *ptr;
	ptr = vptr;
	nleft = n;
	while(nleft > 0) {
		if ( (nread = read(fd, ptr, nleft)) < 0) {
			if (errno == EINTR)
				nread = 0;				/* and call read() again */
			else
				return(-1);
		} else if (nread == 0)
			break;						/* EOF */
		
		nleft -= nread;
		ptr += nread;
	}
	return(n - nleft);					/* return >= 0 */
}