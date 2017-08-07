/*************************************************************************
    > File Name: answer10_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Mon 07 Aug 2017 09:20:12 PM CST
 ************************************************************************/

#include <stdio.h>

struct	INFO1 {
	char	cust_name[21];
	char	cust_addr[41];
	char	model[21];
	enum	{	PURE_CASH,	CASH_LOAN,	LEASE	} type;
	union {
		struct {
			float	msrp;
			float	sales_price;
			float	sales_tax;
			float	licesing_fee;
		} pure_cash;

		struct {
			float	msrp;
			float	sales_price;
			float	sales_tax;
			float	licesing_fee;
			float	down_payment;
			int		loan_duration;
			float	interest_rate;
			float	monthly_payment;
			char	bank[21];
		} cash_loan;

		struct {
			float	msrp;
			float	sales_price;
			float	down_payment;
			float	security_deposit;
			float	monthly_payment;
			float	lease_term;
		} lease;
	};
};
