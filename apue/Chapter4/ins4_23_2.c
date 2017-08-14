/*************************************************************************
    > File Name: ins4_23_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Mon 14 Aug 2017 07:48:09 AM CST
 ************************************************************************/

/*  将工作目录更改至一个指定的目录，然后调用getcwd，最后打印该工作目录。*/
/*  Complie : gcc ins4_23_2.c error.c pathallocate.c -o ins4_23_2		*/

#include "apue.h"
int
main(void)
{
	char	*ptr;
	size_t	size;
	if (chdir("/home/king/LearningC/apue/Chapter4/testdir") < 0)
		err_sys("chdir failed");

	ptr = path_alloc(&size);			/*  our own function  */
	if (getcwd(ptr, size) == NULL)
		err_sys("getcwd failed");
	printf("cwd = %s\n", ptr);
	exit (0);
}

