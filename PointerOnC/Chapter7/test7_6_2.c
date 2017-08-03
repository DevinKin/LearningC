/*************************************************************************
    > File Name: test7_6_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月27日 星期四 11时44分36秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define		SIZE	1000
static	char *digits[] =
{
	" ", "ONE ", "TWO ", "THREE ", "FOUR ", "FIVE ", "SIX ", "SEVEN ", "EIGHT ", "NINE ", "TEN ",
	"ELEVEN ", "TWELVE ", "THIRTEEN ", "FOURTEEN ", "FIFTEEN ", "SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ", "NINETEEN ", "TWENTY ",
};

static	char *tens[] =
{
	" ", " ", "TWENTY ", "THIRTY ", "FORTY ", "FIFTY ", "SIXTY ", "SEVENTY ", "EIGHTY ", "NINETY ",
};

static	char *magnitudes[] = 
{
	" ", "THOUSAND ", "MILLION ", "BILLION ",
};

static void 
do_one_group(unsigned int amount,char *buffer, char ** magnitudes);

void
written_amount(unsigned int amount, char *buffer)
{
	if(amount == 0)
		strcpy(buffer, "ZERO");
	else
	{
		*buffer = '\0';
		do_one_group(amount, buffer, magnitudes);
	}
}


static void
do_one_group(unsigned int amount, char *buffer, char **magnitudes)
{
	int		value;

	value = amount / 1000;
	if(value > 0)
		do_one_group(value, buffer, magnitudes+1);


	amount %= 1000;
	value = amount / 100;

	if(value > 0)
	{
		strcat(buffer, digits[value]);
		strcat(buffer, "HUNDRED ");
	}
	value = amount % 100;
	if(value >= 20)
	{
		strcat(buffer, tens[value / 10]);
		value %= 10;
	}

	if(value > 0)
		strcat(buffer, digits[value]);

	if(amount > 0)
		strcat(buffer, *magnitudes);
}



int main(void)
{
	unsigned int	input = 1632;
	clock_t		start,finish;
	char buffer[SIZE];
	double	whole;
	start = clock();
	written_amount(input, buffer);
	finish = clock();
	whole = (double) (finish - start) / CLOCKS_PER_SEC;
	printf("%s\n", buffer);
	printf("%f\n", whole);
	return EXIT_SUCCESS;
}
