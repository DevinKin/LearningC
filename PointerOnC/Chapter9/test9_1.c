/*************************************************************************
    > File Name: test9_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月01日 星期二 01时47分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int		n_cntrl;
int		n_space;
int		n_digit;
int		n_lower;
int		n_upper;
int		n_punct;
int		n_nprint;
int		total;


int 
main(void)
{
	int		ch;
	double	percentage;
	while((ch = getchar()) != EOF)
	{
		if(iscntrl(ch))
			n_cntrl++;
		if(isspace(ch))
			n_space++;
		if(isdigit(ch))
			n_digit++;
		if(islower(ch))
			n_lower++;
		if(isupper(ch))
			n_upper++;
		if(ispunct(ch))
			n_punct++;
		if(!isprint(ch))
			n_nprint++;
		total += 1;
	}
	if(total == 0)
		printf("No characters in the input!\n");
	else
	{
		printf("Percentage:\n");
		percentage = (double)n_cntrl / total * 100;
		printf("n_cntrl: %3.0f %%\n", percentage);
		percentage = (double)n_space / total * 100;
		printf("n_space: %3.0f %%\n", percentage);
		percentage = (double)n_digit / total * 100;
		printf("n_digit: %3.0f %%\n", percentage);
		percentage = (double)n_lower / total * 100;
		printf("n_lower: %3.0f %%\n", percentage);
		percentage = (double)n_upper / total * 100;
		printf("n_upper: %3.0f %%\n", percentage);
		percentage = (double)n_punct / total * 100;
		printf("n_punct: %3.0f %%\n", percentage);
		percentage = (double)n_nprint / total * 100;
		printf("n_nprint: %3.0f %%\n", percentage);
	}

	return	EXIT_SUCCESS;
}

