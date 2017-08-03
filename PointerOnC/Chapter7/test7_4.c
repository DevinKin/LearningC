/*************************************************************************
    > File Name: test7_4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月26日 星期三 20时10分55秒
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int 
max_list(int first_arg, ...)
{
	va_list		var_arg;
	int		max = 0;
	int		cmp = 0;

	if(first_arg >= 0)
	{
		va_start(var_arg, first_arg);

		do
		{
			cmp = va_arg(var_arg, int);
			if (cmp < 0)
				break;
			if(max < cmp)
				max = cmp;
		}
		while (cmp >= 0);
		va_end(var_arg);
	}

	return	max;


}


int main(void)
{
	printf("%d\n",max_list(12,10,31,22,43,54,65,86,37,28,19,10,-1));
	return	EXIT_SUCCESS;
}
