/*************************************************************************
    > File Name: slock.h
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月24日 星期日 16时16分56秒
 ************************************************************************/

#ifndef _SLOCK_H
#include "apue.h"
#include <semaphore.h>
#define _POSIX_NAME_MAX 14
#define _SLOCK_H

struct slock {
	sem_t *semp;
	char name[_POSIX_NAME_MAX];
};
#endif
