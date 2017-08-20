/*************************************************************************
    > File Name: ins5_13.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月20日 星期日 21时57分37秒
 ************************************************************************/

#include "apue.h"

/*
 * 函数tmpnam和函数tmpfile的引用
 */


int
main(void)
{
	char	name[L_tmpnam], line[MAXLINE];
	FILE	*fp;

	printf("%s\n", tmpnam(NULL));			/*  first temp name  */

	tmpnam(name);							/*  second  temp name  */
	printf("%s\n", name);

	if ((fp = tmpfile()) == NULL)			/*  create temp file  */
		err_sys("tempfile error");
	fputs("one line of output\n", fp);		/*  write to temp file  */
	rewind(fp);								/*  then read it back  */

	if (fgets(line, sizeof(line), fp) == NULL)
		err_sys("fgets error");
	fputs(line, stdout);					/*  print the line we wrote  */

	exit (0);
}

