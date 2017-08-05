/*************************************************************************
    > File Name: test3_6.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月05日 星期六 14时49分51秒
 ************************************************************************/

#include <apue.h>
#include <fcntl.h>

#define		BUFFSIZE	4096

int
main(void)
{
	int		fd;
	int		rdbyte;
	int		wdbyte;
	char	buf[BUFFSIZE];

	if ((fd = open("testfile", O_RDWR | O_APPEND)) == -1)
		err_sys("Open file error");

	/*  lseek and read the file  */

	/*  offset = 0  */
	if (lseek(fd, 0, SEEK_SET) == -1)
		err_sys("Lseek file error");
	if ((rdbyte = read(fd, buf, 10)) == -1)
		err_sys("Read file error");

	/*  offset = 10  */
	if ((lseek(fd, 10, SEEK_SET)) == -1)
		err_sys("Lseek file error");

	if ((wdbyte = write(fd, buf, 10)) != 10)
		err_sys("Write file error");

	exit (0);
}

