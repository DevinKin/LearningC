/*************************************************************************
    > File Name: test16_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月01日 星期一 19时45分36秒
 ************************************************************************/

#include <stdio.h>

void 
show_bytes(unsigned char *bytes, size_t len)
{
	size_t i;
	for (i=0; i < len; ++i)
		printf("%.2x", bytes[i]);
	printf("\n");
}


void
show_int(int x)
{
	show_bytes((unsigned char *)&x, sizeof(int));
}


void
show_float(int x)
{
	show_bytes((unsigned char *)&x, sizeof(float));
}


void 
show_double(int x)
{
	show_bytes((unsigned char *)&x, sizeof(double));
}


void 
show_pointer(void *p)
{
	show_bytes((unsigned char *)&p, sizeof(void *));
}


int main(void)
{
	int a=1234;
	float b=1.234;
	double c=1.2345;
	int		*p = &a;

	show_int(a);
	show_float(b);
	show_double(c);
	show_pointer(p);
}
