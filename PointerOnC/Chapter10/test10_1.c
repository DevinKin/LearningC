/*************************************************************************
    > File Name: test10_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Mon 07 Aug 2017 08:48:26 PM CST
 ************************************************************************/

#include <stdio.h>

struct Information {
	char *date;
	char *time;
	struct	PhoneNum	*usernum;
	struct	PhoneNum	*callednum;
	struct	PhoneNum	*paidnum;
};

struct PhoneNum {
	unsigned	areacode : 3;
	unsigned	swapcode : 4;
	unsigned	statecode : 1;
};
