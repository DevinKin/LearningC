/*************************************************************************
    > File Name: ins14_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年11月29日 星期三 23时21分30秒
 ************************************************************************/

#include "apue.h"
#include <errno.h>
#include <fcntl.h>
#include "setcls.h"


char		buf[500000];

int 
main(void)
{
	int			ntowrite, nwrite;
	char		*ptr;

	ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
	fprintf(stderr, "read %d bytes\n", ntowrite);
	set_fl(STDOUT_FILENO, O_NONBLOCK);				/*  set nonblocking  */

	ptr = buf;

	while (ntowrite > 0)
	{
		errno = 0;
		nwrite = write(STDOUT_FILENO, ptr, ntowrite);
		fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);

		if (nwrite > 0)
		{
			ptr += nwrite;
			ntowrite -= nwrite;
		}
	}

	clr_fl(STDOUT_FILENO, O_NONBLOCK);			/*  clear nonblocking  */
	exit(0);
}
