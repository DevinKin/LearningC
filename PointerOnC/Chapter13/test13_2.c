/*************************************************************************
    > File Name: test13_2.c
    > Author: Elliot
 ************************************************************************/

#include "node.h"
#include <stdio.h>
#include <stdlib.h>


void
ergodicnode(Node *current, void (*callback)(Node *np))
{
	while (current != NULL)
	{
		callback(current);
		current = current->link;
	}
}

