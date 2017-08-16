/*************************************************************************
    > File Name: test11_4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Wed 16 Aug 2017 02:09:35 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct	 node {
	int data;
	struct node *nd;
}NODE;

NODE *
newnode(int value)
{
	NODE	*newN;
	newN = malloc(sizeof(NODE));
	assert(newN != NULL);
	newN->data = value;
	return newN;
}

int
main(void)
{
	NODE	*head;
	head = newnode(5);
	head->nd = newnode(10);
	head->nd->nd = newnode(15);
	head->nd->nd->nd = 0;
	printf("Link = %d - %d - %d\n",head->data, head->nd->data, head->nd->nd->data);
}


