/*************************************************************************
    > File Name: ins4_24.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Mon 14 Aug 2017 09:34:24 AM CST
 ************************************************************************/


/*	程序为每个命令行参数打印设备号，另外，若此参数引用的是字符特殊文件或块特殊文件，则还打印特殊文件的st_rdev值。*/
#include "apue.h"
#include <sys/sysmacros.h>				//major 和 minor 宏定义在/usr/include/sys/sysmacors.h中

#ifdef		SOLARIS
#include <sys/mkdev.h>
#endif

int
main(int argc, char *argv[])
{
	int		i;
	struct	stat buf;
	for (i = 1; i < argc; i++)
	{
		printf("%s: ",argv[i]);
		if (stat(argv[i], &buf) < 0)
		{
			err_ret("stat error");
			continue;
		}

		printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));
		if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
			printf(" (%s) rdev = %d/%d", 
					(S_ISCHR(buf.st_mode)) ? "character" : "block",
					major(buf.st_rdev), minor(buf.st_rdev));
		printf("\n");
	}
	exit (0);
}
