/*************************************************************************
    > File Name: test11_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年11月10日 星期五 16时13分43秒
 ************************************************************************/

#include "apue.h"
#include <pthread.h>

struct foo {
	int a, b, c, d;
};

struct foo	fo = {1, 2, 3, 4};

void printfoo(const char *s, const struct foo *fp)
{
	printf("%s", s);
	printf(" structure at 0x%lx\n", (unsigned long) fp);
	printf(" foo.a = %d\n", fp->a);
	printf(" foo.b = %d\n", fp->b);
	printf(" foo.c = %d\n", fp->c);
	printf(" foo.d = %d\n", fp->d);
}

void *
thr_fn1(void *arg)
{
	printfoo("thread 1:\n", &fo);
	pthread_exit((void *)&fo);
}


void *
thr_fn2(void *arg)
{
	printf("thread2: ID is %lu\n", (unsigned long) pthread_self());
	pthread_exit((void *) 0);
}


int
main(void)
{
	int		err;
	pthread_t	tid1, tid2;
	struct	foo		*fp;

	err = pthread_create(&tid1, NULL, thr_fn1, NULL);
	if (err != 0)
		err_exit(err, "can't create thread 1");
	err = pthread_join(tid1, (void *)&fp);
	if (err != 0)
		err_exit(err, "can't join with thread 1");

	sleep(1);

	printf("parent starting second thread\n");

	err = pthread_create(&tid2, NULL, thr_fn2, NULL);
	if (err != 0)
		err_exit(err, "can't create thread 2");
	sleep(1);
	printfoo("parent:\n", fp);
	exit(0);

}
