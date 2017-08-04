/*************************************************************************
    > File Name: test9_16.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月03日 星期四 17时26分10秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define		FALSE	0
#define		TRUE	1

int
format(char *format_string,
		char const *digit_string);


int
main(void)
{
	char	formatstr[15] = "#####.#####";
	format(formatstr, "1");
	printf("%s\n", formatstr);
	return	EXIT_SUCCESS;
}


int 
format(char *format_string, char const *digit_string)
{
	register	char *formatp = format_string + strlen(format_string) - 1;
	register	char *digitp = digit_string + strlen(digit_string) - 1;

	if (digit_string == NULL || format_string == NULL)
		return	FALSE;


	if(strlen(format_string) < strlen(digit_string))
	{
		for(;digitp >= digit_string;)
		{
			if (*formatp == '#' )
				*formatp = *digitp;
			if(formatp >= format_string)
				formatp--;
			if(*formatp != ',')
				digitp--;
		}
		return FALSE;
	}
	else
	{
		while (formatp >= format_string && digitp >= digit_string)
		{
			if (*formatp == '#' )
			{
				*formatp-- = *digitp--;
				continue;
			}
			formatp--;
		}
		while(formatp >= format_string)
		{
			if(*formatp == '.')
			{
				char	*p0;
				for(p0 = formatp + 1; *p0 == ' '; *p0++ ='0')
					;
				*--formatp = '0';
				--formatp;
				continue;
			}
			*formatp-- = ' ';
		}

	}
	return TRUE;

}

