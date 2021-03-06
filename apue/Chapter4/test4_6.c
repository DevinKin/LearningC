/*************************************************************************
    > File Name: test4_6.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Mon 14 Aug 2017 10:26:02 AM CST
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char * argv[])
{
	int		fdr;
	int		fdw;
	int		ch;
	if (argc != 3)
		err_quit("Usage: ./test4_6 <srcfile> <dstfile>");

	if ((fdr = open(argv[1], O_RDONLY)) < 0)
		err_sys("Open %s: error", argv[1]);

	if ((fdw = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE)) < 0)
		err_sys("Open %s: error", argv[2]);

	while(read(fdr, &ch, 1) == 1)
	{
		if(ch == '\0')
			continue;
		if (write(fdw, &ch, 1) != 1)
			err_sys("Write to %s: error!", argv[2]);
		
	}
	exit (0);
}


