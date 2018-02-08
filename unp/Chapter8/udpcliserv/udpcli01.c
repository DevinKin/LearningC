/*************************************************************************
    > File Name: udpcli01.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年02月09日 星期五 00时20分23秒
 ************************************************************************/

#include "unp.h"

int
main(int argc, char **argv)
{
	int		sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: udpcli <IPaddress>");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	dg_cli(stdin, sockfd, (SA *)&servaddr, sizeof(servaddr));
	exit(0);
}
