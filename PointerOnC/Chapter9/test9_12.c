/*************************************************************************
    > File Name: test9_12.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月02日 星期三 07时32分26秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define		FALSE	0
#define		TRUE	1


int
prepare_key(char *key)
{
	static	char	alpha[26] = {
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
		'O','P','Q','R','S','T','U','V','W','X','Y','Z'
	};
	register	char *pkey;
	register	char *dup;
	dup = key + strlen(key);
	if(*key == '\0')
		return	FALSE;
	for(pkey = key; pkey < key + strlen(key); pkey += 1)
	{
		if(!isalpha(*pkey))
			return FALSE;
		*pkey = toupper(*pkey);
		dup = strchr(alpha, *pkey);
		if(dup != NULL)
		{
			*dup = ';';
		}
		dup += 1;
	}
	for(dup = strtok(alpha, ";"); 
			dup != NULL;
			dup = strtok(NULL, ";"))
			{
				key = strcat(key, dup);
			}
	return	TRUE;

}


int main(void)
{
	char	key[50] = "trailbzes";
	prepare_key(key);
	printf("%s\n",key);
	return	EXIT_SUCCESS;
}
