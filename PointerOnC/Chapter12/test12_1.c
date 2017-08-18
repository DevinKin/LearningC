/*************************************************************************
    > File Name: test12_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月18日 星期五 14时34分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "sll_node.h"


int
linknum(Node *str)
{
	int		lnum = 1;
	while (str->link != NULL)
		++lnum;
	return lnum;
}
