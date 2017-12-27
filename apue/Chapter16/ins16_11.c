/*************************************************************************
    > File Name: ins16_11.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月27日 星期三 15时49分54秒
 ************************************************************************/

#include "apue.h"
#include <sys/socket.h>

#define MAXSLEEP 128

int
connect_retry(int domain, int type, int protocol,
		const struct sockaddr *addr, socklen_t alen)
{
	int numsec, fd;

	/*
	 * Try to connect with exponential back off.
	 */

	for (numsec = 1; numsec <= MAXSLEEP; numsec <<= 1)
	{
		if ((fd = socket(domain, type, protocol)) < 0)
			return(-1);

		if (connect(fd, addr, alen) == 0)
			/*
			 * COnnection accepted.
			 */
			return(fd);
		close(fd);

		/*
		 * Delay before trying again.
		 */
		if (numsec <= MAXSLEEP / 2)
			sleep(numsec);
	}
	return(-1);

}
