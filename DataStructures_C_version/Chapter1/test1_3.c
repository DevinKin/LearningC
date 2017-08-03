/*************************************************************************
    > File Name: test1_3.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月31日 星期一 11时42分38秒
 ************************************************************************/

#include <stdio.h>

#include <stdlib.h>

void
PrintInt(int value)
{
	if(value >= 10)
		PrintInt(value / 10);
	putchar(value % 10 + '0');
}

void	PrintDigit(double digit)
{
	int		in ;
	if(digit < 0)
	{
		putchar('-');
		digit *= -1;
	}
	in = digit;
	digit -= in;
	PrintInt(in);

	putchar('.');
	
	while(digit != 0 && in != 0)
	{
		digit *= 10;
		in = digit;
		digit -= in;
		PrintInt(in);
	}
}

int main(void)
{
	double	num = -827383.141516;
	PrintDigit(num);
	return	EXIT_SUCCESS;
}
