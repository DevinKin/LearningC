/*************************************************************************
    > File Name: test13_4.c
    > Author: Elliot
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void
swap(char *i, char *j, int elesize)
{
	char	x;
	while (elesize--)
	{
		x = *i;
		*i++ = *j;
		*j++ = x;
	}
}

int 
comp(char *i, char *j)
{
	return *i > *j ? 1 : 
		*i < *j ? -1 : 0;
}

void
sort(char *array, int elenum, int elesize, int (*compare)(char *, char *))
{
	register	char *i;
	register	char *j;
	register	char *last;
	
	last = array + (elenum - 1) * elesize;
	for (i = array; i < last ; i += elesize)	
		for (j = i + elesize; j <= last; j += elesize)
			if (compare(i, j) > 0)
				swap(i, j, elesize);

}

#define		SIZE	5

int
main(void)
{
	int		iarray[SIZE] = {99, 18, 98, 126, 48};
	char	carray[SIZE] = {'B', 'M', 'O', 'C', 'A'};

	for (int i = 0; i < SIZE; ++i)
		printf("%d\n", iarray[i]);

	sort((char *)iarray, (int)SIZE, (int)sizeof(int), comp);

	printf("after sort: \n");
	for (int i = 0; i < SIZE; ++i)
		printf("%d\n", iarray[i]);
	return	EXIT_SUCCESS;
}
