/*************************************************************************
    > File Name: ins7_10.c
    > Author: Elliot
 ************************************************************************/

#include "apue.h"

#define		TOK_ADD		5

jmp_buf		jmpbuffer;

void	do_line(char *);
void	cmd_add(void);
int		get_token(void);

int
main(void)
{
	char	line[MAXLINE];

	if (setmp(jmpbuffer) != 0)
		printf("error");

	while (fgets(line, MAXLINE, stdin) != NULL)
		do_line(line);
	exit (0);
}

char *tok_ptr;				/* global pointer for get_token()  */

void
do_line(char *ptr)
{
	int		cmd;
	tok_ptr = ptr;
	while ((cmd = get_token()) > 0)
		switch (cmd)				/*  one case for each command  */
		{
			case TOK_ADD:
				cmd_add();
				break;
		}
}

void
cmd_add(void)
{
	int		token;

	token = get_token();
	/*  reset of processing for this command  */
	if (token < 0)				/*  an error has occurred  */
		longjmp(jmpbuffer, 1);
}

int
get_token(void)
{
	/*  foreach next token from line pointed to by tok_ptr  */
}
