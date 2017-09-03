/*************************************************************************
    > File Name: ins10_6.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年09月03日 星期日 22时38分46秒
 ************************************************************************/

#include "apue.h"
#include <pwd.h>

static void
my_alarm(int signo)
{
	struct passwd *rootptr;
	
	printf("in signal handler\n");
	if ((rootptr = getpwnam("root")) == NULL)
		err_sys("getpwnam(root) error");
	alarm(1);
}

int
main(void)
{
	struct passwd *ptr;
	signal(SIGALRM, my_alarm);
	alarm(1);

	for (; ;)
	{
		if ((ptr = getpwnam("sar")) == NULL)
			err_sys("getpwnam error");
		if (strcmp(ptr->pw_name, "sar") != 0)
			printf("return value corrupted, pw_name = %s\n",
				ptr->pw_name);
	}

}
