/*************************************************************************
    > File Name: strcliselect01.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年02月02日 星期五 00时46分02秒
 ************************************************************************/

#include "unp.h"

void
str_cli(FILE *fp, int sockfd)
{
	int		maxfdp1;
	fd_set	rset;
	char	sendline[MAXLINE], recvline[MAXLINE];

	FD_ZERO(&rset);
	for ( ; ; ) {
		FD_SET(fileno(fp), &rset);
		FD_SET(sockfd, &rset);
		maxfdp1 = max(fileno(fp), sockfd) + 1;
		Select(maxfdp1, &rset, NULL, NULL, NULL);

		if (FD_ISSET(sockfd, &rset)) {				/*  socket is readable */
			if (Readline(sockfd, recvline, MAXLINE) == 0)
				err_quit("str_cli: server terminated prematurely");
			Fputs(recvline, stdout);
		}

		if (FD_ISSET(fileno(fp), &rset)) {			/*  input is readable  */
			if (Fgets(sendline, MAXLINE, fp) == NULL)
				return;								/*  all done  */
			Writen(sockfd, sendline, strlen(sendline));

		}
	}
}
