/*************************************************************************
    > File Name: ins5_13_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月20日 星期日 22时17分13秒
 ************************************************************************/

#include "apue.h"
#include <error.h>

void
make_temp(char *);

int 
main(void)
{
	char	good_template[] = "/tmp/dirXXXXXX";			/*  right way  */
	char	*bad_template = "/tmp/dirXXXXXX";			/*  wrong way  */

	printf("trying to create first temp file...\n");
	make_temp(good_template);
	printf("trying to create second temp file...\n");
	make_temp(bad_template);
}

void
make_temp(char *template)
{
	int		fd;
	struct		stat	sbuf;
	
	if ((fd = mkstemp(template)) < 0)
		err_sys("can't create temp file ");
	printf("temp name = %s\n", template);
	close(fd);

	if (stat(template, &sbuf) < 0)
	{
		if (errno == ENOENT)
			printf("file does't exist\n");
		else
			err_sys("stat failed");
	} else {
		printf("file exists\n");
		unlink(template);
	}
}

