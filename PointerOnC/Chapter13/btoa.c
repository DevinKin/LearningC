/*************************************************************************
    > File Name: btoa.c
    > Author: Elliot
 ************************************************************************/

/*
 * 接受一个整型值（无符号），把它转换为字符，病打印出来，前导被去除
 */

#include <stdio.h>

void
binary_to_ascii(unsigned int value)
{
	unsigned int	quotient;
	quotient = value / 10;
	if (quotient != 0)
		binary_to_ascii(quotient);
	putchar(value % 10 + '0');
}
