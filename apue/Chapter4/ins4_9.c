/*************************************************************************
    > File Name: ins4_9.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Tue 08 Aug 2017 10:51:21 AM CST
 ************************************************************************/

/*  modifity the permission of file bar and foo  */
/*
-rw------- 1 king king 0 Aug  8 10:46 bar
-rw-rw-rw- 1 king king 0 Aug  8 10:46 foo
*/

#include <apue.h>

int
main(void)
{
	struct	stat	statbuf;
	/*  turn on set-group-ID and turn off group-execute  */

	if (stat("foo", &statbuf) < 0)
		err_sys("stat error for foo");
	if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
		err_sys("chmod error for foo");

	/*  set absolute mode to "rw-r--r--"  */

	if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
		err_sys("chmod error for bar");
	exit (0);
}

