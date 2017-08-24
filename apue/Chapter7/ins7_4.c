/*************************************************************************
    > File Name: ins7_4.c
    > Author: Elliot
 ************************************************************************/

/*
 * 程序将其所有命令行参数都回显到标准输出上。注意，通常的echo(1)程序不会回显第0个参数
 */

#include "apue.h"
int
main(int argc, char *argv[])
{
	int		i;

	for (i = 0; i < argc; ++i)		/*  echo all command-line args  */
		printf("argv[%d]: %s\n", i, argv[i]);
	exit(0);
}
