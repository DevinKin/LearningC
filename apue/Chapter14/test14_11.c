/*************************************************************************
    > File Name: ins14_27.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月12日 星期二 20时22分54秒
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>
#include <sys/mman.h>

#define COPYINCR (1024*1024*1024)		/* 1GB */

int 
main(int argc, char *argv[])
{
	int					fdin, fdout;
	void				*src, *dst;
	size_t				copysz;
	struct stat			sbuf;
	off_t				fsz = 0;

	if (argc != 3)
		err_quit("usage: %s <fromfile> <tofile>", argv[0]);

	if ((fdin = open(argv[1], O_RDONLY)) < 0)
		err_sys("can't open %s for reading" ,argv[1]);

	if ((fdout = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0)
		err_sys("fstat error");

	if (fstat(fdin, &sbuf) < 0)
		err_sys("fstat error");

	if (ftruncate(fdout, sbuf.st_size) < 0)			/* set output file size */
		err_sys("ftruncate error");


	while (fsz < sbuf.st_size)
	{
		if ((sbuf.st_size - fsz) > COPYINCR)
			copysz = COPYINCR;
		else
			copysz = sbuf.st_size - fsz;

		if ((src = mmap(0, copysz, PROT_READ, MAP_SHARED, fdin, fsz)) == MAP_FAILED)
			err_sys("mmap error for input");
		close(fdin);
		if ((dst = mmap(0, copysz, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, fsz)) == MAP_FAILED)
			err_sys("mmap error for output");
		close(fdout);

		memcpy(dst, src, copysz);					/*  does the file copy */
		munmap(src, copysz);
		munmap(dst, copysz);
		fsz += copysz;
	}
	exit(0);

}

