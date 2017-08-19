/*************************************************************************
    > File Name: test12_5.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月19日 星期六 18时42分48秒
 ************************************************************************/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "sll_node.h"

#define		TRUE	1
#define		FALSE	0

int
sll_remove(struct NODE **rootp, struct NODE *node)
{
	Node	*current;

	assert(node != NULL);

	while ((current = *rootp) != NULL && current != node)
		rootp = &(*rootp)->link;

	if (current == node)
	{
		(*rootp)->link = current->link;
		free(current);
		return TRUE;
	}
	else
		return	FALSE;

}
