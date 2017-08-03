/*************************************************************************
    > File Name: ins1_7.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月26日 星期三 00时06分17秒
 ************************************************************************/

#include "apue.h"
#include <error.h>

int main(int argc, char *argv[])
{
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	exit(0);
}

