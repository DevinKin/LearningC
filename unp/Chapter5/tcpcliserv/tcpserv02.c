/*************************************************************************
    > File Name: tcpserv01.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月28日 星期日 20时46分19秒
 ************************************************************************/

#include "unp.h"

void
sig_chld(int signo);

int
main(int argc, char *argv[])
{
	int		listenfd, connfd;
	pid_t	childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr,  servaddr;
	
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);				/* 9877 */
	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	Listen(listenfd, LISTENQ);							/* LISTENQ = 1024 */
	Signal(SIGCHLD, sig_chld);
	for( ; ; ) {
		clilen = sizeof(cliaddr);
		connfd = Accept(listenfd, (SA *)&cliaddr, &clilen);

		if ((childpid = Fork()) == 0) {				/* child process */
			Close(listenfd);						/* close listening socket */
			str_echo(connfd);						/* process the request */
			exit(0);
		}
		Close(connfd);								/* parent closes connected socket */
	}
}
