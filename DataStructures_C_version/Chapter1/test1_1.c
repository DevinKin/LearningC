/*************************************************************************
    > File Name: test1_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月30日 星期日 23时26分26秒
 ************************************************************************/

// k = N/2 selecting question

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define		N		1000000
int
max(int *array, int len)
{
	int		k = len / 2;
	int		temp;
	int		n;
	int		buffer[k];
	for(int j = 0; j < k; ++j)
		buffer[j] = *array++;
	// sort
	
	for(int l = k; l >= 1; l--)
	{
		for(int l2 = 0; l2 < l - 1; ++l2)
		{
			if(buffer[l2] < buffer[l2 + 1])
			{
				temp = buffer[l2];
				buffer[l2] = buffer[l2 + 1];
				buffer[l2 + 1] = temp;
			}
		}
	}

	

	for(int m = k; m < len; ++m)
	{
		if(*array > buffer[k - 1])
		{
			for(n = k - 1; n >= 1; n--)
			{
				if(buffer[n] > *array)
					break;
				else
					buffer[n] = buffer[n - 1];
			}
			buffer[n] = *array;
		}
		array++;
	}
	return buffer[k - 1];
}


int main(void)
{
	int		array[N];
	srand((unsigned)(time(NULL)));
	clock_t		start,end;
	double	 time;
	for(int i = N - 1; i >= 0; i--)
		array[i] = rand() % 10000;

	start = clock();
	printf("%d\n", max(array, N));
	end = clock();
	time = (double) (end - start) / CLOCKS_PER_SEC;
	printf("time: %f\n", time);

	return EXIT_SUCCESS;
}
