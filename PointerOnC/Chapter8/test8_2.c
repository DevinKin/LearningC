/*************************************************************************
    > File Name: test8_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月28日 星期五 20时49分44秒
 ************************************************************************/

#include <stdio.h>
#include <cfloat>

static	double income_limits[] = {
	50, 23350, 56550, 117950, 256500, DBL_MAX
};

static	float base_tex[] = {
	0,	3502.50,	12789.50,	31832.50,	81710.50
};

static	float precentage[] = {
	.15,	.28,	.31,	.36,	.396
};

float
single_tax(float income)
{
	int		count;
	for(count = 0; income >= *income_limits; ++count)
		;

	return	(income - income_limits[count]) * precentage[count] +base_tex[count];

}

