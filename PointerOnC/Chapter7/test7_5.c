/*************************************************************************
    > File Name: test7_5.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月26日 星期三 20时38分30秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

void print_integer(int value)
{
	printf("%d",value);
}

void print_float(float value)
{
	printf("%f",value);
}

void
easy_printf(char *format, ...)
{
	char	ch;
	va_list		arg;
	char	*str;
	va_start(arg, format);

	while((ch = *format++) != '\0')
	{
		if(ch != '%')
		{
			putchar(ch);
			continue;
		}
		switch(*format != '\0' ? *format++ : '\0' )
		{
			case 'd' :
				print_integer(va_arg(arg, int));
				break;
			case 'c' :
				putchar(va_arg(arg, int));
				break;
			case 's' :
				str = va_arg(arg, char *);
				while(*str != '\0')
					putchar(*str++);
				break;
			case 'f' :
				print_float(va_arg(arg, double));
				break;
			default :
				break;
		}
	}
}

	

int main(void)
{
	easy_printf("%d %f %c %s", 12, 'A', 3.1415, "easy_printf");
	return	EXIT_SUCCESS;	
}

