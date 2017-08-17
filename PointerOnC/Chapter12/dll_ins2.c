/*************************************************************************
    > File Name: dll_ins1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Wed 16 Aug 2017 10:18:46 PM CST
 ************************************************************************/

/*
 * 啊一个值插入到一个双链表，rootp是一个指向根节点的指针，
 * value 是欲插入的新值
 * 返回值：如果欲插值原先已经存在于链表中，函数返回0；
 * 如果内存不足导致无法插入，函数返回-1；如果插入成功，函数返回1
 */

#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked_list_node.h"

int
dll_insert(Node *rootp, int value)
{
	Node	*thisp;
	Node	*next;
	Node	*newnode;

	/*
	 * 查看value是否已经存在于链表，如果是就返回
	 * 否则，为新值创建一个新节点（"newnode"将指向它）
	 * "thisp"将指向应该在新节点之前的那个节点。
	 * "next"将指向应该在新节点之后的那个节点。
	 */
	for (thisp = rootp; (next = thisp->fwd) != NULL; thisp = next)
	{
		if (next->value == value)
			return 0;
		if (next->value > value)
			break;
	}
	newnode = (Node *)malloc(sizeof(Node));
	if (newnode == NULL)
		return -1;
	newnode->value = value; 

	/*
	 * 把新值添加到链表中
	 */
	if (next != NULL)
	{
		/*
		 * 情况1或情况2，并非位于链表尾部。
		 */
		newnode->fwd = next;
		if (thisp != rootp)			/*  情况1：并非位于链表的起始位置  */
		{
			newnode->bwd = thisp;
			thisp->fwd = newnode;
		}
		else						/*  情况2：位于链表的起始位置  */
		{
			rootp->fwd = newnode;
			newnode->bwd = NULL;
		}
		next->bwd = newnode;
	}
	else
	{
		/*
		 * 情况3或4：位于链表的尾部
		 */
		newnode->fwd = NULL;
		if (thisp != rootp)			/*  情况3：并非位于链表的起始位置  */
		{
			thisp->fwd = newnode;
			newnode->bwd = thisp;

		}
		else						/*	情况4：位于链表的起始位置  */
		{
			rootp->fwd = newnode;
			newnode->bwd = NULL;
		}
		rootp->bwd = newnode;
	}
	return 1;
}

