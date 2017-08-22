/*************************************************************************
    > File Name: test6_5.c
    > Author: Elliot
 ************************************************************************/
#include "apue.h"
#include <time.h>

#define		BUFFERSIZE	256

int
main(void)
{
	time_t	t;
	char	buf[BUFFERSIZE];
	struct	tm *tmp;
	if (time(&t) < 0)
		err_sys("time error!");

	if ((tmp = localtime(&t)) == NULL)
		err_sys("localtime error!");

	if (strftime(buf, BUFFERSIZE,
				"%Y年 %m月 %d日 %A %H:%M:%S %Z",
				tmp) == 0)
		err_sys("strftime error!");
	else
		printf("%s\n", buf);

	exit (0);
}

