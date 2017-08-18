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
dll_insert(Node **fontp, Node **rearp, int value)
{
	Node	**fwdp;
	Node	*next;
	Node	*newnode;


	fwdp = fontp;
	while ((next = *fwdp) != NULL)
	{
		if (next->value == value)
			return 0;
		if (next->value > value)
			break;
		fwdp = &next->fwd;
	}
	newnode = (Node *)malloc(sizeof(Node));
	if (newnode == NULL)
		return -1;
	newnode->value = value; 

	/*
	 * 把新值添加到链表中
	 */
	newnode->fwd = next;
	*fwdp = newnode;

	if (fwdp != fontp)			/*  非起始位置 */
		if (next != NULL)		/*  中间位置  */
			newnode->bwd = next->bwd;
		else					/*  末尾位置  */
			newnode->bwd = *rearp;
	else						/*  起始位置  */
		newnode->bwd = NULL;


	if (next != NULL)			/*  起始位置,链表是否为空  */
		next->bwd = newnode;
	else
		*rearp = newnode;			
	return 1;
}

