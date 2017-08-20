/*************************************************************************
    > File Name: ins5_8_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月20日 星期日 15时35分35秒
 ************************************************************************/

/*
 * 用fgets和fputs读、写行的版本。
 */

#include "apue.h"

int
main(void)
{
	char	buf[MAXLINE];

	while (fgets(buf, MAXLINE, stdin) != NULL)
		if (fputs(buf, stdout) == EOF)
			err_sys("output error");

	if (ferror(stdin))
		err_sys("input error");

	exit(0);
}

