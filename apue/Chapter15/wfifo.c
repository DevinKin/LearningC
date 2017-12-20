/*************************************************************************
    > File Name: wfifo.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月20日 星期三 20时54分17秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define ZIGBEE_PIPEOW		"/tmp/pipeZBToGW"

#define JSON_DATA_1			"{"\
							"\"method\": \"HOST_GET_Ret_Eui64\"," \
							"\"longAddress\":{" \
							"{\"eui64\": \"AAA\", \"type\": 1, \"devinceEndpoint\"1:}," \
							"{\"eui64\": \"BBB\", \"type\": 2, \"devinceEndpoint\"2:}," \
							"}"


/*
 * 功能：			管道的写端
 * 返回值：　		>=0表示成功，<0表示失败
 */
int fifoWrite()
{
	int		nRet = -1;
	int		pipe_fd = -1;

	pipe_fd = open(ZIGBEE_PIPEOW, O_WRONLY | O_NONBLOCK);
	if (pipe_fd == -1)
	{
		printf("fifoWrite pipe error\n");
		return -1;
	}

	nRet = write(pipe_fd, JSON_DATA_1, strlen(JSON_DATA_1) + 1);
	if (nRet == -1)
	{
		printf("pipe write error\n");
		close(pipe_fd);
		return -1;
	}
	close(pipe_fd);

	return 0;
}


int main(int argc, char *argv[])
{
	fifoWrite();
	return 0;
}
