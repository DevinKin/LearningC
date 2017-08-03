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


static	char	alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int
prepare_key(char *key);

void
encrypt(char *data, char const *key);

void 
decrypt(char *data, char const *key);


int main(void)
{
	char	key[27] = "trailbzes";
	prepare_key(key);
	printf("%s\n", key);
	char	code[50] = "kingoliver2398";
	encrypt(code, key);
	printf("encrypt: %s\n", code);
	decrypt(code, key);
	printf("decrypt: %s\n", code);
	return	EXIT_SUCCESS;
}



int
prepare_key(char *key)
{
	register	char *pkey;
	register	char *dup;
	register	int	character;
	if(*key == '\0')
		return	FALSE;
	for(pkey = key; (character = *pkey) != '\0'; pkey += 1)
	{
		if(!isalpha(character))
			return FALSE;
		*pkey = toupper(character);
	}

	for(pkey = key; (character = *pkey) != '\0';)
	{
		dup = ++pkey;
		while((dup = strchr(dup, character)) != NULL)
			strcpy(dup, dup + 1);
	}

	for(character = 'A'; character <= 'Z'; character += 1)
		if(strchr(key, character) == NULL)
		{
			*pkey++ = character;
			*pkey = '\0';
		}

	return	TRUE;

}



void
encrypt(char *data, char const *key)
{
	register	int		character;
	for(; (character = *data) != '\0'; data++)
	{
		if(!isalpha(character))
			continue;
		if(islower(character))
			*data = tolower(key[character - 'a']);
		else if(isupper(character))
			*data = key[character - 'A'];
	}
}



void 
decrypt(char *data, char const *key)
{
	register	int		character;
	for(; (character = *data) != '\0'; data++)
	{
		if(!isalpha(character))
			continue;
		if(islower(character))
			*data = tolower(alphabet[strchr(key, toupper(character)) - key]);
		else if(isupper(character))
			*data = alphabet[strchr(key, character) - key];
	}

}
