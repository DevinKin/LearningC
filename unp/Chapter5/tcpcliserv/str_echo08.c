/*************************************************************************
    > File Name: str_echo08.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月30日 星期二 14时56分51秒
 ************************************************************************/

#include "unp.h"

void 
str_echo(int sockfd)
{
	long	arg1, arg2;
	ssize_t n;
	char line[MAXLINE];

	for ( ; ; ) {
		if ((n =  Readline(sockfd, line, MAXLINE)) == 0)
			return;								/* connection closed by other end */
		if (sscanf(line, "%ld%ld", &arg1, &arg2) == 2)
			snprintf(line, sizeof(line), "%ld\n", arg1 + arg2);
		else
			snprintf(line, sizeof(line), "input error");
		n = strlen(line);
		Writen(sockfd, line, n);
	}
}
