/*************************************************************************
    > File Name: dg_echo.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年02月08日 星期四 23时42分14秒
 ************************************************************************/

#include "unp.h"

void
dg_echo(int sockfd, SA* pcliaddr, socklen_t clilen)
{
	int		n;
	socklen_t len;
	char	mesg[MAXLINE];

	for ( ; ; ) {
		len = clilen;
		n = Recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &clilen);

		Sendto(sockfd, mesg, MAXLINE, 0, pcliaddr, len);

	}
}
