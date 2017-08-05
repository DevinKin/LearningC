/*************************************************************************
    > File Name: ins3_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月05日 星期六 07时51分44秒
 ************************************************************************/

/*  Create a file with hole  */
#include <apue.h>
#include <fcntl.h>

char	buf1[] = "abcdefghij";
char	buf2[] = "ABCDEFGHIJ";

int 
main(void)
{
	int		fd;

	if ((fd = creat("file.hole", FILE_MODE)) < 0)
		err_sys("creat error");

	if (write(fd, buf1, 10) != 10)
		err_sys("buf1 write error");

	/*  offset now = 10  */

	if (lseek(fd, 16384, SEEK_SET) == -1)
		err_sys("lseek error");

	/*  offset now = 16384  */
	if (write(fd, buf2, 10) != 10)
		err_sys("buf2 write error");

	/*  offset now 16934  */
	exit (0);
}

