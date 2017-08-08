/*************************************************************************
    > File Name: ins4_8.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Tue 08 Aug 2017 10:40:58 AM CST
 ************************************************************************/

/*  using mask to create a file  */
#include <apue.h>
#include <fcntl.h>


#define		RWRWRW	(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int
main(void)
{
	umask(0);
	if (creat("foo", RWRWRW) < 0)
		err_sys("creat error for foo");
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	/*  close the read、write and execute permission of group  */

	if (creat("bar", RWRWRW) < 0)
		err_sys("creat error for bar");
	exit(0);
}
