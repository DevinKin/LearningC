/*************************************************************************
    > File Name: ins4_21.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Sun 13 Aug 2017 10:09:06 AM CST
 ************************************************************************/

/*  turncate the file length to zero, and keep the modifity time and change time  */
#include "apue.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
	int		i,fd;
	struct	stat	statbuf;
	struct	timespec	times[2];
	if (argc < 2)
		err_ret("Usage: ./ins4_21 <filename>");
	for (i = 1; i < argc; i++)
	{
		if (stat(argv[i],&statbuf) < 0)		/*  fetch current times  */
		{
			err_ret("%s: stat error", argv[i]);
		}

		if ((fd = open(argv[i],O_RDWR | O_TRUNC)) < 0)
		{
			err_ret("%s: open error", argv[i]);
			continue;
		}
		times[0] = statbuf.st_atim;
		times[1] = statbuf.st_mtim;

		if (futimens(fd, times) < 0)
			err_ret("%s: futimens error", argv[i]);
		close(fd);
	}
	exit (0);
}


