/*************************************************************************
    > File Name: test7_6.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月27日 星期四 09时17分51秒
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

void 
do_one_group(unsigned int amount,char *buffer, char ** magnitudes);

void
written_amount(unsigned int amount, char *buffer)
{
	if(amount == 0)
		strcat(buffer, "ZERO");
	else
	{
		*buffer = '\0';
		do_one_group(amount, buffer, magnitudes);
		printf("%s\n", buffer);
	}

}


void
do_one_group(unsigned int amount,char *buffer, char ** magnitudes)
{
	int		rec;
	rec = amount / 1000;
	amount %= 1000;
	if(rec > 0)
		do_one_group(rec, buffer, magnitudes + 1);
	
	if(amount <= 20)
		strcat(buffer, digits[amount]);
	else if(amount > 20 && amount < 100)
	{
		strcat(buffer, tens[amount / 10]);
		strcat(buffer, digits[amount % 10]);
	}
	else if(amount >= 100 && amount < 1000)
	{
		strcat(buffer, digits[amount / 100]);
		strcat(buffer, "HUNDRED ");
		if ((amount % 100) <= 20)
			strcat(buffer, digits[amount % 100]);
		else
		{
			strcat(buffer, tens[amount / 10 % 10]);
			strcat(buffer, digits[amount % 10 % 10]);
		}
	}
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
	printf("%f\n", whole);
	return EXIT_SUCCESS;
}
