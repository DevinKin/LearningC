/*************************************************************************
    > File Name: tcpserv04.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月28日 星期日 23时20分17秒
 ************************************************************************/

#include "unp.h"

int 
main(int arc, char **argv)
{
	int listenfd, connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, servaddr;
	void sig_chld(int);

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));
	Listen(listenfd, LISTENQ);
	Signal(SIGCHLD, sig_chld);				/* must call */

	for ( ; ; ) {
		clilen = sizeof(cliaddr);
		if ((connfd = accept(listenfd, (SA *)&cliaddr, &clilen)) < 0) {
			if (errno == EINTR)
				continue;					/* back to for() */
			else
				err_sys("accept error");

		}

		if ((childpid = Fork()) == 0) {							/* child process */
			Close(listenfd);
			str_echo(connfd);									/* process the request */
			exit(0);
		}	
		Close(connfd);
	}
}
