/*************************************************************************
    > File Name: q2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月25日 星期二 11时06分02秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int func(void)
{
	static	int		counter = 1;
	return ++counter;
}
int main(void)
{
	int		answer;
	answer = func() - func() * func();
	printf("%d\n", answer);
}
