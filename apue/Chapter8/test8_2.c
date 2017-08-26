/*************************************************************************
    > File Name: test8_2.c
    > Author: Elliot
 ************************************************************************/
#include "apue.h"

#define		SIZE 15
static void f1(void);
static void f2(char *buf);

int
main(void)
{
	f1();
	f2();
}

static void
f1(void)
{
	if (vfork() < 0)
		err_sys("vfork error");
}

static void
f2(char *buf)
{
	char	buf[1000];
	int		i;
	for (i =0; i < 1000; i++)
		buf[i] = 0;
}
