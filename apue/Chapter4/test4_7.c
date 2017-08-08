/*************************************************************************
    > File Name: test4_7.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Tue 08 Aug 2017 10:27:52 AM CST
 ************************************************************************/

/*  the instance of function access  */
#include <apue.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
	if (argc != 2)
		err_quit("usage: test4_3 <pathname>");
	if (access(argv[1], R_OK) < 0)
		err_ret("access error for %s", argv[1]);
	else
		printf("read access OK\n");

	if (open(argv[1], O_RDONLY) < 0)
		err_ret("open error for %s", argv[1]);
	else
		printf("open for reading OK\n");
	exit (0);
}

