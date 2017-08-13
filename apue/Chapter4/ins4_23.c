/*************************************************************************
    > File Name: ins4_23.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Mon 14 Aug 2017 07:38:23 AM CST
 ************************************************************************/

/*  an instance of change directory  */
#include "apue.h"

int
main(void)
{
	if (chdir("/tmp") < 0)
		err_sys("chdir failed");
	printf("chdir to /tmp successded\n");
	exit(0);	
}


