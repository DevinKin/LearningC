/*************************************************************************
    > File Name: sockfd_to_family.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月27日 星期六 15时40分12秒
 ************************************************************************/

#include "unp.h"

int
sockfd_to_family(int sockfd)
{
	struct sockaddr_storage ss;
	socklen_t len;

	len = sizeof(ss);
	if (getsockname(sockfd, (SA *) &ss, &len) < 0)
		return(-1);
	return(ss.ss_family);
}
