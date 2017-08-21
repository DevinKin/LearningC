/*************************************************************************
    > File Name: ins6_2.c
    > Author: Elliot
 ************************************************************************/

/*
 * 程序给出了getpwnam函数的一个实现
 */

#include <pwd.h>
#include <cstddef>
#include <string.h>

struct	passwd	*
getpwname(const char *name)
{
	struct	passwd	*ptr;

	setpwent();
	while ((ptr = getpwent()) != NULL)
		if (strcmp(name, ptr->pw_name) == 0)
			break;					/*  found a match  */
	endpwent();
	return(ptr);					/*  ptr is NULL if no match found  */
}
