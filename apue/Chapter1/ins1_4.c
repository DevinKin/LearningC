/*************************************************************************
    > File Name: ins1_4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月15日 星期六 19时54分44秒
 ************************************************************************/

#include "apue.h"

#define		BUFFSIZE	4096

int main(int argc,char * argv[])
{
	int		n;
	char	buf[BUFFSIZE];

	while((n=read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO,buf,n) != n)
			err_sys("write error");
	if (n < 0)
		err_sys("read error");

	exit(0);

}
