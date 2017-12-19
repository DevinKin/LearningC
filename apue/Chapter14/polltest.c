/*************************************************************************
    > File Name: polltest.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月18日 星期一 22时55分40秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <stropts.h>
#include <sys/poll.h>
#include <sys/stropts.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <poll.h>

#define		BUFSIZE 1024

int main(int argc, char *argv[])
{
	char			buf[BUFSIZE];
	int				bytes;
	struct pollfd	*pollfd;
	int				i = 0;
	int				nummonitor = 0;
	int				numready;
	int				errno;
	char			*str;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: the argc num error\n");
		exit(1);
	}

	if ((pollfd = (struct pullfd *)calloc(2, sizeof(struct pollfd))) == NULL)			//为poll分配内存空间
	{
		fprintf(stderr, "calloc error");
		exit(1);
	}

	for (; i < 2; i++)				//初始化pollfd结构
	{
		str = (char *)malloc(14 * sizeof(char));
		memcpy(str, "./", 6);
		strcat(str, argv[i+1]);					//需要把路径信息放到str中
		printf("str=%s\n", str);
		(pollfd+i)->fd = open(str, O_RDONLY);
		if ((pollfd+i)->fd >= 0)
			fprintf(stderr, "open(pollfd+%d)->fd:%s\n", i, argv[i+1]);
		nummonitor++;
		(pollfd+i)->events = POLLIN;
	}

	printf("nummonitor=%d\n", nummonitor);

	while (nummonitor > 0)
	{
		numready = poll(pollfd, 2, -1);
		if ((numready == -1) && (errno == EINTR))
			continue;				//被信号中断，继续等待
		else if(numready == -1)
			break;					//poll真正错误，退出
		printf("numready=%d\n", numready);
		for (i = 0; nummonitor > 0 && numready > 0; i++)
		{
			if ((pollfd+i)->revents & POLLIN)
			{
				bytes = read(pollfd[i].fd, buf, BUFSIZE);
				numready--;
				printf("pollfd[%d]->fd read buf:\n%s\n", i, buf);
				nummonitor--;
			}
		}
	}
	for (i = 0; i < nummonitor; i++)
		close(pollfd[i].fd);
	free(pollfd);
	return(0);
}
