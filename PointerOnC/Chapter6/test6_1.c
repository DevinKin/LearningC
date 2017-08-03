/*************************************************************************
    > File Name: test6_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月25日 星期二 18时18分23秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char * find_char( char const * source,
		char const * chars)
{
	char	*ret;
	if ( source != NULL && chars != NULL)
	{
		for(; *source != '\0' ; ++source)
		{
			for (ret = (char *)chars; *ret != '\0'; ++ret)
			{
				if ( *ret == *source )
					return ret;
			}

		}
	}
	return	NULL;
}
