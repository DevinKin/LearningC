/*************************************************************************
    > File Name: test12_4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月19日 星期六 07时37分40秒
 ************************************************************************/

#include <stdio.h>
#include "sll_node.h"

struct	NODE *
sll_reverse(struct	NODE *first)
{
	Node	*str;
	Node	**linkp;
	str = first->link;
	first->link = NULL;
	for (linkp = &str->link; (*linkp != NULL) ; str = str->link)
	{
		(*linkp)->link = str;
		str->link = first;
		first = first->link;
	}
	return str;
}

/* answer  */

struct	NODE *
sll_reverse(struct	NODE *current)
{
	Node	*previous;
	Node	*next;

	for (previous = NULL; current != NULL; current = next)
	{
		next = current->link;
		current->link = previous;
		previous = current;
	}
	return current;

}
