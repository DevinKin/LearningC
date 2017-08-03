/*************************************************************************
    > File Name: test1_4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月24日 星期一 11时41分41秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define		MAX_LINE_INPUT	1001

int main(void)
{
	char	buffer[MAX_LINE_INPUT];
	char	longest[MAX_LINE_INPUT];
	int		len=0;
	int		maxlen=0;
	int		temp;
	while( fgets(buffer,MAX_LINE_INPUT,stdin) != NULL)
	{
		len = strlen(buffer);
		if (len > maxlen)
		{
			temp = len;
			len = maxlen;
			maxlen = temp;
			strcpy(longest,buffer);
		}
	}
	printf("MAX_STR_LEN:%d\n",maxlen);
	puts(longest);
	return	EXIT_SUCCESS;

}

