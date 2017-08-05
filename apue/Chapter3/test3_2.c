/*************************************************************************
    > File Name: test3_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月05日 星期六 10时12分01秒
 ************************************************************************/

#include <apue.h>

int
my_dup2(int fd, int fd2)
{
	int		t;
	int		dups[256];
	int		i = 0;

	if (fd2 < 0 || fd2 > 256)
	{
		printf("fd2 must more than 0 less than 256");
	}
	if (fd == fd2)
		return fd2;
	else
	{
		if (close(fd2) == 0)
		{
			return dup(fd);
		}
		else
		{
			do
			{
				t = dup(fd);
				dups[i] = t;
				i++;
			}
			while (t != fd2);

			while (i)
				close(dups[--i]);
			return t;
		}
	}
}

