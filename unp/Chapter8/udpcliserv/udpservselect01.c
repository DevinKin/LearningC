/*************************************************************************
    > File Name: udpservselect01.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年02月22日 星期四 14时27分03秒
 ************************************************************************/

#include "unp.h"

int
main(int argc, char **argv)
{
	int listenfd, connfd, udpfd, nready, maxfdp1;
	char mesg[MAXLINE];
	pid_t childpid;
	fd_set rset;
	ssize_t n;
	socklen_t len;
	const int on = 1;
	struct sockaddr_in cliaddr, servaddr;
	void sig_chld(int);

	/* create listening TCP socket */
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));
	Listen(listenfd, LISTENQ);

	/* create UDP socket */
	udpfd = Socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	Bind(udpfd, (SA *)&servaddr, sizeof(servaddr));

	Signal(SIGCHLD, sig_chld);				/* must call waitpid() */

	FD_ZERO(&rset);
	maxfdp1 = max(listenfd, udpfd) + 1;
	for ( ; ; ) {
		FD_SET(listenfd, &rset);
		FD_SET(udpfd, &rset);

		if ((nready = select(maxfdp1, &rset, NULL, NULL, NULL)) < 0) {
			if (errno == EINTR)
				continue;			/* back to for() */
			else
				err_sys("select error");
		}

		if (FD_ISSET(listenfd, &rset)) {
			len = sizeof(cliaddr);
			connfd = Accept(listenfd, (SA *)&cliaddr, &len);

			if ((childpid = Fork()) == 0) {		/* child process */
				Close(listenfd);			/* close listening socket */
				str_echo(connfd);			/* process the request */
			}
			printf("Connect from tcp client:%s\n", Sock_ntop((SA *)&cliaddr, len));
			Close(connfd);				/* parent closes connected socket */
		}

		if (FD_ISSET(udpfd, &rset)) {
			len = sizeof(cliaddr);
			n = Recvfrom(udpfd, mesg, MAXLINE, 0, (SA*)&cliaddr, &len);
			printf("Connect from udp client:%s\n", Sock_ntop((SA *)&cliaddr, len));
			Sendto(udpfd, mesg, n, 0, (SA*)&cliaddr, len);
		}
	}
}
