/*************************************************************************
    > File Name: test6_3.c
    > Author: King
    > Mail: arturiappendragon_1@163.com 
    > Created Time: 2017年07月25日 星期二 20时25分12秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char	temp;
void reverse_string(char *string)
{
	int		i = strlen(string)-1;
	char	*str = string;
	int		count = strlen(string) / 2;
	char	*pend = string+i;
	for (int j =0; j<count; ++j)
	{
		temp = *str;
		*str = *pend;
		*pend = temp;
		str++;
		pend--;
	}
}

int main(void)
{
	char	reverse[] = "Hello World!";
	printf("Before reverse:%s\n", reverse);
	reverse_string(reverse);
	printf("After reverse:%s\n", reverse);
	return 0;
}
