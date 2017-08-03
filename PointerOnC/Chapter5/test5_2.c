/*************************************************************************
    > File Name: test5_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月25日 星期二 11时35分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define		MAX_CODE	256

char *	coded(char *code)
{
	int		len = strlen(code);

	for (int i=0; i < len ; ++i)
	{
		if ( (code[i] >= 65 && code[i] < 78) || (code[i] >= 97 && code[i] < 110))
			code[i] += 13;
		else if ( (code[i] >= 78 && code[i] <= 90) || (code[i] >= 110 && code[i] <= 122))
			code[i] -= 13;
	}
	return code;
}
int main(void)
{
	char	code[MAX_CODE];
	while (fgets(code, MAX_CODE, stdin) != NULL)
	{
		coded(code);
	}
	printf("coded: %s\n", code);
}
