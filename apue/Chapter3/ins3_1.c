/*************************************************************************
    > File Name: ins3_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月05日 星期六 07时47分03秒
 ************************************************************************/

/* testing whether standard input can set the offset */
#include <apue.h>
int
main(void)
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("cannot seek\n");
	else
		printf("seek OK\n");
	exit (0);
}

