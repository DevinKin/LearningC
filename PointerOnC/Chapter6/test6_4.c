/*************************************************************************
    > File Name: test6_4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月25日 星期二 21时31分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define		SIZE	1000
#define		TRUE	1	
#define		FALSE	0

int main(void)
{
	char	sieve[SIZE];
	char	*sp;
	int		i;
	clock_t		start,finish;
	double		wholetime;
	start = clock();
	for (sp = sieve; sp != &sieve[SIZE];)
		*sp++ = TRUE;

	sp = sieve;
	for (i = 3; ;i += 2)
	{
		sp =  &sieve[0] + (i-3) / 2;
		if (sp >= &sieve[SIZE])
			break;
		while( sp += i , sp < &sieve[SIZE] )
			*sp = FALSE;
	}
	finish = clock();

	// show 
	printf("2\n");
	for (i = 3, sp = &sieve[0];
			sp < &sieve[SIZE];
			i += 2, sp++)	
	{
		if (*sp)
			printf("%d\n",i);
	}

	wholetime = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Using time:%f\n", wholetime);

	return	EXIT_SUCCESS;
}

