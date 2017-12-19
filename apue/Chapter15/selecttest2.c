/*************************************************************************
    > File Name: selecttest2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月18日 星期一 23时42分47秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <stropts.h>
#include <sys/select.h>
#include <sys/stropts.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>


#define		BUFSIZE		1024

int main(int argc, char *argv[])
{
	char				buf[BUFSIZE];
	int					bytes;
	int					i = 0;
	fd_set				rfds;
	int					fd[i];
	int					nummonitor = 0;
	int					numready = 0;
	int					errno;
	char				*str;
	struct timeval		tval;

	// 初始化时间
	tval.tv_sec = 5;
	tval.tv_usec = 0;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: the argc num error\n");
		exit(1);
	}
	
	FD_ZERO(&rfds);					/* clear rfdset */

	for (; i < 2; i++)
	{
		str = (char *)malloc(6 * sizeof(char));
		memcpy(str, "./", 6);
		strcat(str, argv[i+1]);
		printf("str%d:%s\n", i, str);
		if ((fd[i] = open(str, O_RDONLY)) < 0)
			fprintf(stderr, "open %s error", str);
		else
		{
			nummonitor++;
			FD_SET(fd[i], &rfds);
		}
	}

	printf("nummonitor=%d\n", nummonitor);

	while (nummonitor > 0)
	{
		numready = select(fd[1] + 1, &rfds, NULL, NULL, NULL);
		printf("ready:%d\n", numready);
		if ((numready == -1) && (errno == EINTR))
			continue;
		else if (numready == -1)
			break;
		for (i=0; nummonitor > 0 && numready > 0; i++)
		{
			bytes = read(fd[i], buf, BUFSIZE);
			numready--;
			printf("select fd(%d) read buf:\n%s\n", fd[i], buf);
			nummonitor--;
		}
	}

	for (i=0; i < nummonitor; i++)
		close(fd[i]);
	return(0);
}

