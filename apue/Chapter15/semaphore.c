/*************************************************************************
    > File Name: semaphore.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月24日 星期日 17时00分43秒
 ************************************************************************/

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX 100
sem_t sem1, sem2;


void *
th_fn1(void *arg)
{
	int	i;
	for(i = 0; i < MAX; i++)
	{
		sem_wait(&sem1);
		printf("number in thread1 is %d\n", i);
		sem_post(&sem2);
	}
	pthread_exit((void *)"thread1 exit\n");
}


void *
th_fn2(void *arg)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		sem_wait(&sem2);
		printf("number in thread2 is %d\n", i);
		sem_post(&sem1);
	}
	pthread_exit((void *)"thread2 exit\n");
}


int main(int argc, char *argv[])
{
	pthread_t tid1, tid2;
	void *tret;
	if (sem_init(&sem1, 0, 5) == -1)
	{
		perror("sem1 init failed\n");
		return -1;
	}
	if (sem_init(&sem2, 0, 5) == -1)
	{
		perror("sem2 init failed\n");
		return -1;
	}

	pthread_create(&tid1, NULL, th_fn1, NULL);
	pthread_create(&tid2, NULL, th_fn2, NULL);

	pthread_join(tid1, &tret);
	pthread_join(tid2, &tret);

	sem_destroy(&sem1);
	sem_destroy(&sem2);

	return 0;
}
