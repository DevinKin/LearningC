/*************************************************************************
    > File Name: insert3.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Wed 16 Aug 2017 09:13:46 PM CST
 ************************************************************************/

/*
 * 插入到一个有序单链表中。函数的参数是一个指向链表第一个节点的指针，以及一个需要插入的新值
 */

#include <stdio.h>
#include <stdlib.h>
#include "sll_node.h"

#define		FALSE	0
#define		TRUE	1

int
sll_insert(register Node **linkp, int new_value)
{
	register Node	*current;
	register Node	*newN;

	/*
	 * 寻找正确的插入位置，方法是按序访问链表，直到到达一个其值大于或等于
	 * 新值的节点
	 */

	while ((current = *linkp) != NULL &&
			current->value < new_value)
		linkp = &current->link;

	/*
	 * 为新节点分配内存，并把新值存储到新节点中，如果内存分配失败，
	 * 函数返回FALSE。
	 */

	newN = (Node *)malloc(sizeof(Node));
	if (newN == NULL)
		return FALSE;
	newN->value = new_value;

	/*
	 * 在链表中插入新节点，并返回TRUE
	 */

	*linkp = newN;
	newN->link = current;
	return TRUE;
}
