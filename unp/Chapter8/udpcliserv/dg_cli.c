/*************************************************************************
    > File Name: dg_cli.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年02月09日 星期五 00时51分15秒
 ************************************************************************/

#include "unp.h"

void
dg_cli(FILE *fp, int sockfd, const SA* pservaddr, socklen_t servlen)
{
	int		n;
	char	sendline[MAXLINE], recvline[MAXLINE + 1];
	
	while (Fgets(sendline, MAXLINE, fp) != NULL) {
		Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);

		n = Recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);

		recvline[n] = 0;		/* null */
		Fputs(recvline, stdout);
	}
}
