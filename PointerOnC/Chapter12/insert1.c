/*************************************************************************
    > File Name: insert1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Wed 16 Aug 2017 04:46:56 PM CST
 ************************************************************************/

/*
 * 插入到一个有序的单链表。函数的参数是一个指向链表第一个节点的指针以及需要插入的值
 */

#include <stdio.h>
#include <stdlib.h>
#include "sll_node.h"

#define		FALSE	0
#define		TRUE	1

int
sll_insert(Node *current, int new_value)
{
	Node	*previous;
	Node	*newN;

	/*
	 * 寻找正确的插入位置，方法是按原顺序访问链表，直到其值大于或等于
	 * 新插入的节点
	 */

	while(current->value < new_value)
	{
		previous = current;
		current = current->link;
	}

	/*
	 * 为新节点分配内存，并把值存储到新节点中，如果内存分配失败
	 * 函数返回FALSE
	 */
	newN =(Node *)malloc(sizeof(Node));
	if (newN == NULL)
		return	FALSE;
	newN->value = new_value;

	/*
	 * 把新节点插入到链表中，并返回TRUE
	 */
	new->link = current;
	previous->link = new;
	return TRUE;
}


