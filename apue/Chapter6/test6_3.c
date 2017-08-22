/*************************************************************************
    > File Name: test6_3.c
    > Author: Elliot
 ************************************************************************/

#include <sys/utsname.h>
#include "apue.h"
int
main(void)
{
	struct	utsname		utsnamebuf;

	if (uname(&utsnamebuf) < 0)
		err_sys("uname error!");
	printf("sysname = %s\n", utsnamebuf.sysname);
	printf("nodename = %s\n", utsnamebuf.nodename);
	printf("release = %s\n", utsnamebuf.release);
	printf("version = %s\n", utsnamebuf.version);
	printf("machine = %s\n", utsnamebuf.machine);
	exit (0);
}

