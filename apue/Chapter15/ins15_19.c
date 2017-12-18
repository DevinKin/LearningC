/*************************************************************************
    > File Name: ins15_19.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月18日 星期一 11时02分02秒
 ************************************************************************/

#include "apue.h"

int 
main(void)
{
	int		int1, int2;
	char	line[MAXLINE];

	while (fgets(line, MAXLINE, stdin) != NULL)
	{
		if (sscanf(line, "%d%d", &int1, &int2) == 2)
		{
			if (printf("%d\n", int1 + int2) == EOF)
				err_sys("printf error");
		}
		else 
		{
			if (printf("invalid args\n") == EOF)
				err_sys("printf error");
		}
	}
	exit(0);
}
