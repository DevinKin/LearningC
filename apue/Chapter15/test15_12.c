/*************************************************************************
    > File Name: test15_12.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月03日 星期三 16时14分08秒
 ************************************************************************/

#include "apue.h"
#include <sys/msg.h>

#define		TEXT_SIZE	512
struct mymesg {
	long mtype;					/* positive message type */
	char mtext[TEXT_SIZE];			/* message data, of length nbytes */
};


int main(void)
{
	int		i;
	int		msgid;
	struct	mymesg	ms_st;
	ms_st.mtype = 1;
	strcpy(ms_st.mtext,"hello world");


	for (i = 0; i < 5; ++i)
	{
		if ((msgid = msgget((key_t)1234, 0666 | IPC_CREAT)) < 0)
			err_sys("msgget error");
		printf("msgid=%d\n", msgid);
		msgctl(msgid, IPC_RMID, NULL);

	}

	for (i = 0; i < 5; ++i)
	{
		if ((msgid = msgget((key_t)1234, 0666 | IPC_CREAT | IPC_PRIVATE)) < 0)
			err_sys("msgget error");
		if (msgsnd(msgid, (void *)&ms_st, TEXT_SIZE, 0) < 0)
			err_sys("msgsnd error");
		printf("msgid=%d\n", msgid);
	}

	exit(0);
}
