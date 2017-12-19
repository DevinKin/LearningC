/*************************************************************************
    > File Name: test14_5_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月19日 星期二 20时52分12秒
 ************************************************************************/

#include "apue.h"
#include <sys/select.h>
#include <sys/poll.h>

void
sleep_us_select(int nusec)
{
	struct timeval	tv;
	tv.tv_sec = nusec / 1000000;
	tv.tv_usec = nusec % 1000000;
	select(0, NULL, NULL, NULL, &tv);
}


void 
sleep_us_poll(int nusecs)
{
	struct pollfd		dummy;
	int					timeout;

	if ((timeout = nusecs / 1000) <= 0)
		timeout = 1;
	poll(&dummy, 0, timeout);

}

