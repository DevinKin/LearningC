/*************************************************************************
    > File Name: dgecholoop1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年02月21日 星期三 23时09分18秒
 ************************************************************************/

#include "unp.h"

static void recvfrom_int(int);
static int count;

void
dg_echo(int scokfd, SA* pcliaddr, socklen_t clilen)
{
	socklen_t len;
	char mesg[MAXLINE];

	Signal(SIGINT, recvfrom_int);

	for ( ; ; ) {
		len = clilen;
		Recvfrom(scokfd, mesg, MAXLINE, 0, pcliaddr, &len);
		count++;
	}
}

static void
recvfrom_int(int signo)
{
	printf("\nreceived %d datagrams\n", count);
	exit(0);
}
