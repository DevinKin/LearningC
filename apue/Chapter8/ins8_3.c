/*************************************************************************
    > File Name: ins8_3.c
    > Author: Elliot
 ************************************************************************/

#include "apue.h"
int		globvar = 6;				/*  external variable in initialized data  */

int
main(void)
{
	int		var;					/*  automatic variable on the stack  */
	pid_t	pid;

	var = 88;

	printf("before vfork\n");			/*  we don't flush stdio  */
	if ((pid = vfork()) < 0)
		err_sys("vfork error");
	else if(pid == 0)
	{
		globvar++;						/*  child  */
		var++;							/*  modify parent's variables  */
		_exit(0);
	}

	/*  parent continus here  */
	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar,
			var);
	exit(0);

}
