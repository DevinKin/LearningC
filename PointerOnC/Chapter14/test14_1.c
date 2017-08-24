/*************************************************************************
    > File Name: test14_1.c
    > Author: Elliot
 ************************************************************************/


void
print_ledger(int value)
{
#ifdef	OPTION_LONG
#define		OK	1
	print_ledger_long(value);
#endif
#ifdef	OPTION_DETAILED
#define		OK	1
	print_ledger_detailed(value);
#endif

#ifndef		OK	
	print_ledger_default(value);
#endif

}
