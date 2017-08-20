/*************************************************************************
    > File Name: ind5_8.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月20日 星期日 15时28分34秒
 ************************************************************************/

/*  它使用getc和putc将标准输入复制到标准输出  
 *  这两个历程可以实现为宏
 */

#include "apue.h"

int
main(void)
{
	int		c;

	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF)
			err_sys("output error");

	if (ferror(stdin))
		err_sys("input error");

	exit(0);
}

