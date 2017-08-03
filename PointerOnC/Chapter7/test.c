/*************************************************************************
    > File Name: test.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月26日 星期三 16时21分23秒
 ************************************************************************/

#include <stdio.h>

int
find_max(int array[10])
{
	int		i;
	int		max = array[0];

	for(i = 1; i < 10; ++i)
		if(array[i] > max)
			max = array[i];
	return	max;
}

int main(void)
{
	int array[10]={1,2,3,4};
	printf("%d\n",find_max(array));
	return 0;
}
