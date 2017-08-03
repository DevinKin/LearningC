/*************************************************************************
    > File Name: test2_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月24日 星期一 13时21分38秒
 ************************************************************************/

#include <stdio.h>
#include "increment.h" 
#include "negate.h"

int main(void)
{
	int		arg;
	printf("Please Enter the arg:\t");
	scanf("%d",&arg);
	printf("increment: %d\n",increment(arg));
	printf("increment: %d\n",negate(arg));
}
