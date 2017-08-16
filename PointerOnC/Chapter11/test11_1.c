/*************************************************************************
    > File Name: test11_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
	j
    > Created Time: Wed 16 Aug 2017 10:32:40 AM CST
 ************************************************************************/

//编写calloc函数

#include <stdio.h>
#include <stdlib.h>

void *
calloc(size_t num_elements,
		size_t element_size)
{
	char	*ret;
	register	size_t	n_element;
	n_element = num_elements * element_size;
	ret = malloc(n_element);
	if ( ret != NULL)
	{
		char	*init = ret;
		while(n_element-- > 0)
			*init++ = '\0';
		return ret;	
	}
	return NULL;
}

