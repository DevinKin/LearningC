/*************************************************************************
    > File Name: test11_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Wed 16 Aug 2017 10:47:50 AM CST
 ************************************************************************/

/*
 * 从标准输入中读取一列整数，把这些值存储于一个动态分配的数组中病返回叔祖包含值的个数。
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define		DELTA	4


int *
save_arr()
{
	int		*arr;
	int		*save;
	int		size;
	int		input;

	size = DELTA;

	arr = malloc(sizeof(int) * (size + 1));

	if (arr != NULL)
	{
		if (scanf("%d", &input))
		{
			if (input > size)
			{
				size = input;
			}
			arr = realloc(arr, sizeof(int) * (size + 1));
			save = arr;
			*save++ = input;
		}
		while(size-- && scanf("%d", &input))
		{
			*save++ = input;
		}
		return	arr;
	}

	return NULL;
}

int main(void)
{
	int		*arr;
	arr = save_arr();
	printf("\n");
	for(int i = 0; i < 10; ++i)
		printf("%d\n",*arr++);
	return EXIT_SUCCESS;

}
