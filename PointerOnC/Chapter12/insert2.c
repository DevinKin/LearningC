/*************************************************************************
    > File Name: insert2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Wed 16 Aug 2017 08:17:27 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlio.h>
#include "sll_node.h"

#define		FALSE	0
#define		TRUE	1

int
sll_insert(Node **rootp, int new_value)
{
	Node	*current;
	Node	*previous;
	Node	*newN;

	/*
	 * 得到第1个节点的指针。
	 */
	current = *rootp;
	previous = NULL;

	/*
	 * 寻找正确的插入位置，方法是按序访问链表，直到到达一个其值大于或等于
	 * 新值的节点。
	 */
	while(current != NULL && current->value < new_value )
	{
		previous = current;
		current = current->link;
	}

	/*
	 * 为新节点分配内存，并把新值存储到新节点中。如果内存分配失败，
	 * 函数返回FALSE
	 */

	newN = malloc(sizeof(Node));
	newN->value = new_value;

	/*
	 * 把新节点插入到链表中。并返回TRUE。
	 */
	newN->link = current;
	if (previous == NULL)
		*rootp = newN;
	else
		previous->link = newN;
	return TRUE;
}
