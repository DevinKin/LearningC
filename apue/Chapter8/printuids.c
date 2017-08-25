/*************************************************************************
    > File Name: ins8_13_2.c
    > Author: Elliot
 ************************************************************************/

#include "apue.h"

int
main(void)
{
	printf("real uid = %d, effective uid = %d\n", getuid(), geteuid());
	exit(0);
}
