/*************************************************************************
    > File Name: ins15_17.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月16日 星期六 23时51分47秒
 ************************************************************************/

#include "apue.h"

int 
main()
{
	int		n, int1, int2;
	char	line[MAXLINE];

	while ((n = read(STDIN_FILENO, line, MAXLINE)) > 0)
	{
		line[n] = 0;						/* null terminate */
		if (sscanf(line, "%d%d", &int1, &int2) == 2)
		{
			sprintf(line, "%d\n", int1 + int2);
			n = strlen(line);
			if (write(STDOUT_FILENO, line, n) != n)
				err_sys("write error");
		}
		else
		{
			if (write(STDOUT_FILENO, "invalid args\n", 13) != 13)
				err_sys("write_error");
		}
	}
}
