/*************************************************************************
    > File Name: ruptimeserv.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月27日 星期三 17时00分29秒
 ************************************************************************/

#include "apue.h"
#include <netdb.h>
#include <errno.h>
#include <syslog.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/socket.h>

#define BUFLEN 128
#define QLEN 10

#ifndef HOST_NAME_MAX
#define	HOST_NAME_MAX 256
#endif

fd_set	allset;
int		servers[FD_SETSIZE];
int		maxi=-1;

extern int initserver(int, const struct sockaddr *, socklen_t, int);

void
serve(int maxfd)
{
	int			i = 0, clfd, nready = 0;
	int			sockfd;
	FILE		*fp;
	char		buf[BUFLEN];
	fd_set		readfds;

	FD_ZERO(&readfds);

	set_cloexec(maxfd);
	for (;;)
	{
		readfds = allset;
		nready = select(maxfd + 1, &readfds, NULL, NULL, NULL);
		if (nready < 0)
		{
			syslog(LOG_ERR, "getprocnumed: select error:%s", 
					strerror(errno));
			exit(1);
		}

		for (i = 0; i <= maxi; i++)
		{
			sockfd = servers[i];
			if (FD_ISSET(sockfd, &readfds))
			{
				clfd = accept(sockfd, NULL, NULL);
				if (clfd < 0)
					continue;
				break;
			}
		}
		if (clfd < 0)
		{
			syslog(LOG_ERR, "ruptimed: accept error: %s", 
				strerror(errno));
			exit(1);
		}
		set_cloexec(clfd);

		if ((fp = popen("/usr/bin/getprocnum", "r")) == NULL)
		{
			sprintf(buf, "error: %s\n", strerror(errno));
			send(clfd, buf, strlen(buf), 0);
		}
		else
		{
			while (fgets(buf, BUFLEN, fp) != NULL)
				send(clfd, buf, strlen(buf), 0);
			pclose(fp);
		}
		close(clfd);
	}
}


int 
main(int argc, char *argv[])
{
	struct addrinfo			*ailist, *aip;
	struct addrinfo			hint;
	int						sockfd, err, n, i = 0, maxfd = -1;
	char					*host;
	struct sockaddr_in		*sinp;							//保存服务器端点地址
	char					*addr, abuf[INET_ADDRSTRLEN];	//保存服务器端点地址的字符串格式

	if (argc != 1)
		err_quit("usage: getprocnumed");
	if ((n = sysconf(_SC_HOST_NAME_MAX)) < 0)
		n = HOST_NAME_MAX;						/* best guest */
	if ((host = malloc(n)) == NULL)
		err_sys("malloc error");
	if (gethostname(host, n) < 0)
		err_sys("gethostname error");

	daemonize("getprocnumed");

	for(i = 0; i < FD_SETSIZE; i++)
		servers[i] = -1;
	memset(&hint, 0, sizeof(hint));
	FD_ZERO(&allset);
	hint.ai_flags = AI_CANONNAME;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;
	if ((err = getaddrinfo(host, "getprocnum", &hint, &ailist)) != 0)
	{
		syslog(LOG_ERR, "getprocnum: getaddrinfo error: %s", gai_strerror(err));
		exit(1);
	}
	for (aip = ailist; aip != NULL; aip = aip->ai_next)
	{
		if ((sockfd = initserver(SOCK_STREAM, aip->ai_addr,
						aip->ai_addrlen, QLEN)) >= 0)
		{
			sinp = (struct sockaddr_in *)aip->ai_addr;
			addr = inet_ntop(AF_INET, &sinp->sin_addr, abuf, INET_ADDRSTRLEN);
			syslog(LOG_INFO, "canonname:%s, address:%s, port:%d", aip->ai_canonname, 
					addr, ntohs(sinp->sin_port));
			for (i = 0; i < FD_SETSIZE; i++)
			{
				if (servers[i] < 0)					
					servers[i] = sockfd;

				if (i > maxi)
				{
					maxi = i;
					break;
				}
			}

			if (maxfd < sockfd)
				maxfd = sockfd;

			FD_SET(sockfd, &allset);
		}
	}
	if (maxfd >= 0)
		serve(maxfd);
	else
		exit(1);
	exit(0);
}

