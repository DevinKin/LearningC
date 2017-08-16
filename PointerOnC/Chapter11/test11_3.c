/*************************************************************************
    > File Name: test11_3.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Wed 16 Aug 2017 11:31:56 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define		NCHAR	5
char *
getstring()
{
	char	*str;
	char	*getstr;
	register	int	ch;
	register	int len = 0;
	register	int count = 0;
	str = malloc(sizeof(char) * NCHAR);
	getstr = str;
	if (getstr == NULL)
		return NULL;
	len = NCHAR;

	do	
	{
		ch = getchar();
		if (ch == '\n' || ch == EOF)
			ch = '\0';
		*getstr++ = ch;		
		count++;
		if (len < count)
		{
			len += NCHAR;
			str = realloc(str, len); 
			getstr = str + count;
			/*  realloc 会free掉之前的内存，分配新的内存空间，所以getstr的指向位置必须随着str改变	*/
			assert(str != NULL);
			printf("%d\n",len);
		}
	}
	while(ch != '\0');

	return str;
}


int main(void)
{
	char	*getstr;
	getstr = getstring();
	printf("%s\n", getstr);

	return EXIT_SUCCESS;
}
