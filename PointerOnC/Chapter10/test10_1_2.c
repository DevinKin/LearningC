/*************************************************************************
    > File Name: test10_1_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Mon 07 Aug 2017 08:54:43 PM CST
 ************************************************************************/

#include <stdio.h>
struct	PHONE_NUMBER;

struct	LONG_DISTANCE_BILL {
	short	month;
	short	day;
	short	year;
	int		time;
	struct	PHONE_NUMBER	called;
	struct	PHONE_NUMBER	calling;
	struct	PHONE_NUMBER	billed;
};

struct PHONE_NUMBER {
	short	area;
	short	exchange;
	short	station;
};
