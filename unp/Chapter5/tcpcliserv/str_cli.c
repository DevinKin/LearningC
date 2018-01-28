/*************************************************************************
    > File Name: str_cli.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月28日 星期日 21时10分44秒
 ************************************************************************/

#include "unp.h"

void
str_cli(FILE *fp, int sockfd)
{
	char	sendline[MAXLINE], recvline[MAXLINE];

	while (Fgets(sendline, MAXLINE, fp) != NULL) {
		Writen(sockfd, sendline, strlen(sendline));

		if (Readline(sockfd, recvline, MAXLINE) == 0)
			err_quit("str_cli: server terminated prematurely");

		Fputs(recvline, stdout);
	}
}
