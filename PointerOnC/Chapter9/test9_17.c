/*************************************************************************
    > File Name: test9_17.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月04日 星期五 20时10分12秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define	 TRUE	1
#define	 FALSE	0

char *
edit(char *pattern, char const *digits);


int main(void)
{
	char	pattern[10] = "*#,####";
	char	*digits = "12";
	printf("%s\n", edit(pattern, digits));
}


char *
edit(char *pattern, char const *digits)
{
	register	int		signif;	
	register	int		fill;
	register	int		p_character;
	register	int		d_character;
	char	*firstp;
	signif = FALSE;
	if (pattern == NULL || digits == NULL || (fill = *pattern) == '\0')
		return NULL;
	firstp = NULL;

	/* Handle character  */
	while ((p_character = *++pattern) != '\0')
	{
		switch (p_character)
		{
			case '#':
			case '!':
				if ((d_character = *digits++) == '\0')
				{
					*pattern = '\0';
					return	firstp;
				}
				if (d_character == ' ')
					d_character = '0';
				
				if (d_character != '0' || p_character == '!')
				{
					if (!signif)
						firstp = pattern;
					signif = TRUE;
				}
				break;
			default:
				d_character = p_character;
				break;
		}
		*pattern = signif ? d_character : fill;
	}
	return	firstp;
}

