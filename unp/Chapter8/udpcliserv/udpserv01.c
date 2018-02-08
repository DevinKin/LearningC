/*************************************************************************
    > File Name: udpserv01.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年02月08日 星期四 23时37分22秒
 ************************************************************************/

#include "unp.h"

int main(int argc, char **argv)
{
	int		sockfd;
	struct	sockaddr_in servaddr, cliaddr;

	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	Bind(sockfd, (SA *) &servaddr, sizeof(servaddr));

	dg_echo(sockfd, (SA *) &cliaddr, sizeof(cliaddr));
}
