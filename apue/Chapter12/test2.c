/*************************************************************************
    > File Name: test2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年11月23日 星期四 15时16分22秒
 ************************************************************************/

// no reentry version
#include <string.h>
#include <errno.h>	
#include <pthread.h>
#include <stdlib.h>

extern	char **environ;

pthread_mutex_t	env_mutex;

static pthread_once_t init_done = PTHREAD_ONCE_INIT;


static void
thread_init(void)
{
	pthread_mutexattr_t attr;

	
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&env_mutex, &attr);
	pthread_mutexattr_destroy(&attr);
}


int 
putenv_r(const char *str)
{
	int		i;
	char	*name;

	pthread_once(&init_done, thread_init);
	pthread_mutex_lock(&env_mutex);

	for (i = 0; environ[i] != NULL; i++)
	{
		name = strchr(str, '=');
		if (strncmp(str, environ[i], name - str) == 0)
		{
			strcpy(environ[i], str);
			pthread_mutex_unlock(&env_mutex);
			return(0);
		}
	}
	environ = realloc(environ, (i + 1)*sizeof(char *));
	environ[i] = (char *)malloc(sizeof(char) * 200);
	strcpy(environ[i], str);
	environ[i + 1] = NULL;
	pthread_mutex_unlock(&env_mutex);
	return(0);
}
