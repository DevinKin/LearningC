/*************************************************************************
    > File Name: dgcliloop1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年02月21日 星期三 23时05分24秒
 ************************************************************************/

#include "unp.h"

#define NDG 2000			/* datagrams to send */
#define DGLEN 1400			/* length of each datagram */

void
dg_cli(FILE *fp, int sockfd, const SA* pservaddr, socklen_t servlen)
{
	int		i;
	char	sendline[DGLEN];

	for (i = 0; i < NDG; i++) {
		Sendto(sockfd, sendline, DGLEN, 0, pservaddr, servlen);
	}
}
