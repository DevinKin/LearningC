/*************************************************************************
    > File Name: double_linked_list_node.h
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Wed 16 Aug 2017 10:21:00 PM CST
 ************************************************************************/

#ifndef		_DOUBLY_LINKED_LIST_NODE_H
#define		_DOUBLY_LINKED_LIST_NODE_H

typedef		struct	NODE {
	struct	NODE	*fwd;
	struct	NODE	*bwd;
	int		value;
} Node;
#endif

