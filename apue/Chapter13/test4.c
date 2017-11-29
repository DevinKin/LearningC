/*************************************************************************
    > File Name: test4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年11月29日 星期三 23时03分21秒
 ************************************************************************/

#include "apue.h"


extern void daemonize(const char *);

int main(void)
{
	FILE	*fp;
	char	*p;

	daemonize("getlog");
	p = getlogin();
	fp = fopen("/tmp/getlog.out", "w");

	if (fp != NULL)
	{
		if(p == NULL)
			fprintf(fp, "no login name\n");
		else 
			fprintf(fp, "login name is: %s", p);
	}

	exit(0);
}
