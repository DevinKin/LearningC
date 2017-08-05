/*************************************************************************
    > File Name: ins3_9.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月05日 星期六 08时08分13秒
 ************************************************************************/

/*  Effciency of IO  */
#include <apue.h>

#define		BUFFSIZE	4096

int
main(void)
{
	int		n;
	char	buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");

	if (n < 0)
		err_sys("read error");
}

