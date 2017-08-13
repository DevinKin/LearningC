/*************************************************************************
    > File Name: rename.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Sat 12 Aug 2017 07:33:40 PM CST
 ************************************************************************/

#include <apue.h>


int main(int argc, char *argv[])
{
	if (argc != 3)
		err_sys("Usage: ./a.out oldname newname\n");

	if (rename(argv[1], argv[2]) < 0)
		err_sys("rename error");

	exit (0);

}
