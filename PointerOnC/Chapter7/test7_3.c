/*************************************************************************
    > File Name: test7_3.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月26日 星期三 19时56分17秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
ascii_to_integer(char *string)
{
	int		len = strlen(string);
	int		sum = 0;
	for(int i = 0; i < len; ++i)
	{
		if(string[i] >= '1' && string[i] <= '9')
		{
			sum += string[i] - '0';
			sum *= 10;
		}
		else
			return 0;
	}
	sum /= 10;
	return	sum;

}

int main(void)
{
	char	*string = "1234";
	printf("%d\n",ascii_to_integer(string));
	return	EXIT_SUCCESS;
}
