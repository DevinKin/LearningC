/*************************************************************************
    > File Name: ins12_4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年11月11日 星期六 19时34分20秒
 ************************************************************************/

#include "apue.h"
#include <pthread.h>

int
makethread(void *(*fn) (void *), void *arg)
{
	int				err;
	pthread_t		tid;
	pthread_attr_t	attr;


	err = pthread_attr_init(&attr);
	if (err != 0)
		return(err);
	err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if (err == 0)
		err = pthread_create(&tid, &attr, fn, arg);
	printf("pthread create success\n");
	pthread_attr_destroy(&attr);
	return err;
}

