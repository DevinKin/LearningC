/*************************************************************************
    > File Name: test12_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月18日 星期五 14时47分29秒
 ************************************************************************/

#include <stdio.h>
#include "sll_node.h"

Node *
find_value(Node *str, int value)
{
	for (; str != NULL; str = str->link)
		if (value == str->value)
			return str;
	return NULL;
}

