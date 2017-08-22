/*************************************************************************
    > File Name: test6_2.c
    > Author: Elliot
 ************************************************************************/

#include <shadow.h>
#include "apue.h"

int
main(void)
{
	struct	spwd	*spwdp;

	if ((spwdp = getspnam("samba")) == NULL)
		err_sys("getspnam error!");

	printf("password: %s\n", spwdp->sp_pwdp == NULL ||
			spwdp->sp_pwdp[0] == 0 ? "(null)" : spwdp->sp_pwdp);
	exit(0);
}
