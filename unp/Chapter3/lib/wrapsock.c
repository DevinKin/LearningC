/*************************************************************************
    > File Name: wrapsock.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月27日 星期六 13时17分10秒
 ***********************************************************************/

void 
Listen(int fd, int backlog)
{
	char *ptr;

	/* 4 can override 2nd argument with environment variable */
	if ((ptr = getenv("LESTENQ")) != NULL)
		backlog = atoi(ptr);

	if (listen(fd, backlog) < 0)
		err_sys("listen error");
}
