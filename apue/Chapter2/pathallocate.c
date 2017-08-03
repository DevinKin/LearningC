/*************************************************************************
    > File Name: pathallocate.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月03日 星期四 09时35分43秒
 ************************************************************************/

#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef	PATH_MAX
static	long pathmax = PATH_MAX;
#else
static	long pathmax = 0;
#endif

/*  If PATH_MAX is ideterminate, no guarantee this is adequate  */
#define		PATH_MAX_GUESS	1024

char *
path_alloc(size_t *sizep)		/*  also return allocated size, if nonull*/
{
	char	*ptr;
	size_t	size;
	if (posix_version == 0)
		posix_version = sysconf(_SC_VERSION);

	if (xsi_version == 0)
		xsi_version = sysconf(_SC_XOPEN_VERSION);

	if (pathmax == 0)	/*  first time through  */
	{
		errno = 0;
		if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0)
		{
			if(errno == 0)
				pathmax = PATH_MAX_GUESS;		/*  it's indeterminate */
			else
				err_sys("pathconf error for _PC_PATH_MAX");
		}
		else
		{
			pathmax++;			/*  add one since it's relative to root*/
		}
	}


	/*
	 * Before POSIX.1-2001, we aren't guaranteed that PATH_MAX includes
	 * the terminating null byte. Same goes for XPG3.
	 */
	if ((posix_version < 200112L) && (xsi_version < 4))
		size = pathmax + 1;
	else
		size = pathmax;

	if ((ptr = malloc(size)) == NULL)
		err_sys("malloc error for pathname");

	if (sizep != NULL)
		*sizep = size;

	return	(ptr);
}

