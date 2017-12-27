/*************************************************************************
    > File Name: ins16_10.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月27日 星期三 15时45分11秒
 ************************************************************************/

#include "apue.h"
#include <sys/socket.h>


#define MAXSLEEP 128

int
connect_retry(int sfd, const struct sockaddr *addr, socklen_t alen)
{
	int numsec;

	/*
	 * Try to connect with exponential backoff
	 */
	for (numsec = 1; numsec <= MAXSLEEP; numsec <<= 1)
	{
		if (connect(sfd, addr, alen) == 0)
			/*
			 * Connection accepted.
			 */
			return(0);

		/*
		 * Display before trying again.
		 */
		if (numsec <= MAXSLEEP / 2)
			sleep(numsec);
	}
	return(-1);
}

