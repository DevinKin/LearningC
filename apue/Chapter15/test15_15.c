/*************************************************************************
    > File Name: ins15_33.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月24日 星期日 12时55分51秒
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/mman.h>

#define NLOOPS	1000
#define SIZE	sizeof(long)			/* size of shared memory area */
static int		semid;

union semun {
	int		val;						/* for SETVAL */
	struct	semid_ds *buf;				/* for IPC_STAT and IPC_SET */
	unsigned short *array;				/* for GETALL and SETALL */
};


static int
update(long *ptr)
{
	printf("%ld\n", *ptr);
	return((*ptr)++);					/* return value before increment */
}

void delsem(union semun *sem_set);


int 
main(void)
{
	int		i, counter;
	//int		*add = 0;
	void	*shmptr;
	pid_t	pid;
	union	semun sem_set;
	struct	sembuf sem_b;
	int		shmid;

		
	if ((shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT)) < 0)
		err_sys("shmget error");
	if ((shmptr = shmat(shmid, 0, 0)) == (void *)-1)
		err_sys("shmat error");


	if ((semid = semget(IPC_PRIVATE, 2, 0666 | IPC_CREAT)) < 0)
		err_sys("semid error");

	//信号量0值为1，可以调用占用信号量0的进程
	sem_set.val = 1;								
	if (semctl(semid, 0, SETVAL, sem_set) < 0)
		err_sys("semctl 0 error");
	//信号量1值为0，进程进入休眠状态。
	sem_set.val = 0;
	if (semctl(semid, 1, SETVAL, sem_set) < 0)
		err_sys("semctl 0 error");
	

	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid > 0)					/* parent */
	{
		for (i = 0; i < NLOOPS; i += 2)
		{
			printf("parent\n");
			sem_b.sem_num = 0;
			sem_b.sem_op = -1;
			sem_b.sem_flg = SEM_UNDO;
			if (semop(semid, &sem_b, 1) < 0)
				delsem(&sem_set);
			if ((counter = update((long *)shmptr)) != i)
				err_quit("parent: expected %d, got %d", i, counter);
			sem_b.sem_num = 1;
			sem_b.sem_op = 1;
			sem_b.sem_flg = SEM_UNDO;
			if (semop(semid, &sem_b, 1) < 0)
				delsem(&sem_set);
		}
	}
	else								/* child */
	{
		for (i = 1; i < NLOOPS + 1; i += 2)
		{
			printf("child\n");
			sem_b.sem_num = 1;
			sem_b.sem_op = -1;
			sem_b.sem_flg = SEM_UNDO;
			if (semop(semid, &sem_b, 1) != 0)
				delsem(&sem_set);
			if ((counter = update((long *)shmptr)) != i)
				err_quit("child: expected %d, got %d", i, counter);
			sem_b.sem_num = 0;
			sem_b.sem_op = 1;
			sem_b.sem_flg = SEM_UNDO;
			if (semop(semid, &sem_b, 1) != 0)
				delsem(&sem_set);

		}
	}
	delsem(&sem_set);
	exit(0);
}



void delsem(union semun *sem_set)
{
	sem_set->val = 0;
	semctl(semid, 0, IPC_RMID, sem_set);
	sem_set->val = 1;
	semctl(semid, 1, IPC_RMID, sem_set);
	exit(EXIT_FAILURE);
}
