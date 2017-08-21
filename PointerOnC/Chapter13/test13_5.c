/*************************************************************************
    > File Name: test13_5.c
    > Author: Elliot
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define		FALSE	0
#define		TRUE	1

enum {NONE, FLAG, ARG};

argtype(register int ch, register int control)
{
	while (*control != '\0')
		if (ch == *control++)
			return	*control == '+' ? ARG : FLAG;
	return NONE;
}

char **
do_args(int argc, char **argv, char *control, 
		void (*do_arg) (int ch, char *value),
		void (*illegal_arg) (int ch))
{
	register	char	*argp;
	register	int		ch;
	register	int		skip_arg;


	while ((argp = *++argv) != NULL && *argp == '-')
	{
		skip_arg = FALSE;
		while (!skip_arg && (ch = *++argp) != '\0')
			switch(argtype(ch, control))	
			{
				case FLAG:
					do_arg(ch, NULL);
					break;
				case ARG:
					if (*++argp != '\0' || (argp = *++argv) != NULL)
					{
						do_arg(ch, argp);
						skip_arg = TRUE;
						break;
					}
					illegal_arg(ch);
					return	argv;
				
				case NONE:
					illegal_arg(ch);
					break;
			}
	}
	return	argv;
/*
	if (argc < 1)
		return NULL;

	while (**argv == '-' &&
			*argv++ != NULL)
	{
		if (strchr(control, *++*argv) != NULL)			//  位于control字符串内  
		{
			if (*(*argv + 1) != '+')					//  后跟的不是一个+号  
				do_arg(**argv, NULL);
			else
			{
				if (*argv != NULL)
					do_arg(**argv, *argv);
				else
					illegal_arg(*(*argv + 2));
			}
		}
		else											//  不在control字符串内  
		{
			illegal_arg(**argv);
		}
	}
*/

}
