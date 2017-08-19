/*************************************************************************
    > File Name: test12_6.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月19日 星期六 20时13分24秒
 ************************************************************************/

#include <stdio.h>
#include "doubly_linked_list_node.h"
#include <stdlib.h>
#define		TRUE	1
#define		FALSE	0

int
dll_remove(struct NODE *rootp, struct NODE *deleten)
{
	Node	*current;
	
	for (current = rootp->fwd; current != NULL && current != deleten; 
			current = current->fwd);
	
	if (current == deleten)
	{
		if (current->fwd == NULL)				/*  在链表结束位置  */
			rootp->bwd = current->bwd;
		else
			current->bwd->fwd = current->fwd;

		if (current->bwd == NULL)				/*  在链表起始位置  */
			rootp->fwd = current->fwd;
		else
			current->fwd->bwd = current->bwd;
		free(current);
		return TRUE;
	}
	else
		return FALSE;
}
