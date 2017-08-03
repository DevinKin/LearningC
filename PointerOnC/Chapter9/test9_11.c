/*************************************************************************
    > File Name: test9_11.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月01日 星期二 15时06分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char	whitespace[] = "\n\t \r\f\v";

int 
scan_char(char const *search)
{
	int		count = 0;
	char	buffer[101];
	char	*word;
	while(fgets(buffer, 100, stdin))
	{
		for(word = strtok(buffer, whitespace); 
				word != NULL;
				word = strtok(NULL, whitespace))
			if(strcmp(word, search) == 0)
				count++;

	}
	printf("%d\n", count);
}


int main(void)
{
	char *search = "the";
	scan_char(search);
	return	EXIT_SUCCESS;
}
