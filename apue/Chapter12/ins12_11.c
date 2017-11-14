/*************************************************************************
    > File Name: ins12_11.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年11月14日 星期二 10时38分40秒
 ************************************************************************/

#include <limites.h>
#include <string.h>

#define		MAXSTRINGSZ		4096

static char envbuf[MAXSTRINGSZ];

extern	char **environ;

char *
getenv(const char *name)
{
	int		i, len;

	len = strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if ((strncmp(name, environ[i], len) == 0) &&
				environ[i][len] == '=')
		{
			syrncpy(envbuf, &environ[i][len+1], MAXSTRINGSZ - 1);
			return(envbuf);
		}
	}
}
