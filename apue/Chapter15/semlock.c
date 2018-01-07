/*************************************************************************
    > File Name: ins15_35.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月24日 星期日 16时16分23秒
 ************************************************************************/

#include "slock.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <semaphore.h>

struct slock *
s_alloc(int value)
{
	struct slock *sp;
	static int cnt;

	if ((sp = (struct slock *)malloc(sizeof(struct slock))) == NULL)
		return NULL;

	do
	{
		snprintf(sp->name, sizeof(sp->name), "/%ld.%d", (long)getpid(),
				cnt++);
		sp->semp = sem_open(sp->name, O_CREAT | O_EXCL, S_IRWXU, value);
	}
	while ((sp->semp == SEM_FAILED) && (errno == EEXIST));
	if (sp->semp == SEM_FAILED)
	{
		free(sp);
		return(NULL);
	}
	sem_unlink(sp->name);
	return(sp);
		
}


void 
s_free(struct slock *sp)
{
	sem_close(sp->semp);
	free(sp);
}

int 
s_lock(struct slock *sp)
{
	return(sem_wait(sp->semp));
}


int 
s_trylock(struct slock *sp)
{
	return(sem_trywait(sp->semp));
}


int
unlock(struct slock *sp)
{
	return(sem_post(sp->semp));
}
