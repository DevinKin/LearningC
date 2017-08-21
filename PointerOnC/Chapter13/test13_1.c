/*************************************************************************
    > File Name: test13_1.c
    > Author: Elliot
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int
is_not_print(int ch)
{
	return !isprint(ch);
}

static	int	(* funcarray[]) (int) =
{
	iscntrl,
	isspace,
	isdigit,
	islower,
	isupper,
	ispunct,
	is_not_print,
};
static	char * label[] =
{
	"control",
	"white space",
	"digit",
	"lower case",
	"upper case",
	"punctuation",
	"non-printable"
};


#define		N_CATEGGORY		sizeof(funcarray) / sizeof(funcarray[1])

#define		STR_SIZE		256	
int		count[N_CATEGGORY];
int		total;

int
main(void)
{
	int		ch;
	
	char	*str;

	str = malloc(sizeof(char) * STR_SIZE);
	if (str == NULL)
	{
		printf("malloc error!");
		return EXIT_FAILURE;
	}

	while ((ch = getchar()) != '\n')
	{
		for (int i = 0; i < N_CATEGGORY; ++i)
			if (funcarray[i](ch))
				count[i] += 1;
		total += 1;
	}

	for (int i = 0; i < N_CATEGGORY; ++i)
		printf("%s : %f\n", label[i], (double)count[i] / total * 100);
}
