/*************************************************************************
    > File Name: strcliselect02.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年02月02日 星期五 15时10分33秒
 ************************************************************************/

#include "unp.h"

void
str_cli(FILE *fp, int sockfd)
{
	int		maxfdp1, stdineof;
	fd_set	rset;
	char	buf[MAXLINE];
	int		n;

	stdineof = 0;
	FD_ZERO(&rset);
	for ( ; ; ) {
		if (stdineof == 0)
			FD_SET(fileno(fp), &rset);
		FD_SET(sockfd, &rset);
		maxfdp1 = max(fileno(fp), sockfd) + 1;
		Select(maxfdp1, &rset, NULL, NULL, NULL);

		if (FD_ISSET(sockfd, &rset)) {		/* socket is readable */
			if ((n = Read(sockfd, buf, MAXLINE)) == 0) {
				if (stdineof == 1)
					return;					/* normal termination */
				else
					err_quit("str_cli: server terminated prematurely");
			}
			Write(fileno(stdout), buf, n);
		}

		if (FD_ISSET(fileno(fp), &rset)) {	/* input is readable */
			if ((n = Read(fileno(fp), buf, MAXLINE)) == 0) {
				stdineof = 1;
				Shutdown(sockfd, SHUT_WR);			/* send FIN */
				FD_CLR(fileno(fp), &rset);
				continue;
			}
			Writen(sockfd, buf, n);

		}
	}
}
