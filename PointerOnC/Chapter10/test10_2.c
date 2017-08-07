/*************************************************************************
    > File Name: test10_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Mon 07 Aug 2017 09:03:56 PM CST
 ************************************************************************/

#include <stdio.h>

struct	ALL_PAY_SELL {
	float	retail_price;
	float	ac_price;
	float	sales_tax;
	float	licensing_fee;
};

struct	RENT {
	float	retail_price;
	float	ac_price;
	float	down_payment;
	float	security_deposit;
	float	monthly_payment;
	int		lease_term;
};

struct	LOAN {
	float	retail_price;
	float	ac_price;
	float	sales_tax;
	float	licensing_fee;
	float	down_payment;
	int		loan_duration;
	float	interest_rate;
	float	monthly_payment;
	char	*name_of_bank;
};

struct	CAR_SELL {
	char	*customer_name;
	char	*customer_address;
	char	*model;
	struct	RENT *rent;
	struct	ALL_PAY_SELL *all_pay_sell;
	struct	LOAN	*loan;
};
