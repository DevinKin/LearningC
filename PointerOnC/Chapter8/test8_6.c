/*************************************************************************
    > File Name: test8_6.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月29日 星期六 21时08分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>

#define		reg		register		
int 
array_offset(int arrayinfo[], ...)
{
	reg		int		offset;
	reg		va_list		arg_list;
	reg		int		hi;
	reg		int		lo;
	reg		int		n;
	reg		int		*sp;
	int		cnt = 0;
	int		s[10];
	
	n = *arrayinfo++;
	if(n >= 1 && n <= 10)
	{
		va_start(arg_list, arrayinfo);
		for(offset=0; offset < 10; ++offset)
		{
			s[offset] = va_arg(arg_list, int);
		}
		va_end(arg_list);

		offset = 0;
		sp = s;


		while(n-- >= 1)
		{
			lo = *arrayinfo++;
			hi = *arrayinfo++;

			if(*sp++ < lo || lo > hi)
				return -1;

			offset *= hi - lo + 1; 
			offset += *sp - lo;
		}
		return	offset;

	}
	return -1;


}

