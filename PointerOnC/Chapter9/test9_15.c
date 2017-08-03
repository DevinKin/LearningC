/*************************************************************************
    > File Name: test9_15.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月02日 星期三 20时00分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
dollars(char *dest, char const *src)
{
	register	char *cp;
	register	char *dp = dest;
	register	int	len = strlen(src);
	cp = src;
	*dp++ = '$';

	for(int i = len - 2; i >= 1;)	
	{
		*dp++ = *cp++;
		if( --i && i % 3 == 0)
			*dp++ = ',';
	}
	*dp++ = '.';
	*dp++ = *cp;
	cp += 1;
	*dp++ = *cp;
	printf("dollars: %s\n", dest);
}

int main(void)
{
	char	dest[10];
	char	src[10]="123456789";
	dollars(dest, src);
	return	EXIT_SUCCESS;
}
