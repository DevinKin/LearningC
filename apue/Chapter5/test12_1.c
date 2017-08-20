/*************************************************************************
    > File Name: test12_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月21日 星期一 07时32分01秒
 ************************************************************************/

/*
 * 用setvbuf实现setbuf
 */

#include "apue.h"

void
setbuf(FILE *fp, char *restrict_buf)
{
	if (restrict_buf == NULL)
	{
		setvbuf(fp, restrict_buf, _IONBF, 0);
		printf("No buf");
	}
	else
	{
		if (fp == stdin)
		{

			if (setvbuf(fp, restrict_buf, _IOLBF, BUFSIZ) != 0)
			{
				err_sys("setvbuf error");
				exit(-1);
			}
		}
		else if(fp == stdout)
		{
			if (setvbuf(fp, restrict_buf, _IOLBF, BUFSIZ) != 0)
			{
				err_sys("setvbuf error");
				exit(-1);
			}
		}
		else if(fp == stderr)
		{
			if (setvbuf(fp, restrict_buf, _IOLBF, BUFSIZ) != 0)
			{
				err_sys("setvbuf error");
				exit(-1);
			}
		}
		else
		{
			if (setvbuf(fp, restrict_buf, _IOFBF, BUFSIZ) != 0)
			{
				err_sys("setvbuf error");
				exit(-1);
			}

		}
	printf("Line buf");
	}
}
