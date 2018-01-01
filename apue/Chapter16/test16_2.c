/*************************************************************************
    > File Name: test16_2.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月01日 星期一 20时08分42秒
 ************************************************************************/

#include "apue.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int sfd;
	struct stat		buf;
	char		*filetpye;
	if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		err_quit("socket error");


	if (fstat(sfd, &buf) < 0)
		err_quit("fstat error");

	printf("stat.st_dev: %ld\n", buf.st_dev);
	printf("stat.st_gid: %d\n", buf.st_gid);
	printf("stat.st_ino: %ld\n", buf.st_ino);
	printf("stat.st_uid: %d\n", buf.st_uid);
	printf("stat.st_atime.tv_sec: %ld\n", buf.st_atim.tv_sec);
	printf("stat.st_atime.ntv_nsec: %ld\n", buf.st_atim.tv_nsec);
	printf("stat.st_ctime.tv_sec: %ld\n", buf.st_ctim.tv_sec);
	printf("stat.st_ctime.tv_nsec: %ld\n", buf.st_ctim.tv_nsec);
	printf("stat.st_mtime.tv_sec: %ld\n", buf.st_mtim.tv_sec);
	printf("stat.st_mtime.tv_nsec: %ld\n", buf.st_mtim.tv_nsec);

	if (S_ISREG(buf.st_mode))
		filetpye = "regular";
	else if (S_ISDIR(buf.st_mode))
		filetpye = "directory";
	else if (S_ISCHR(buf.st_mode))
		filetpye = "character special";
	else if (S_ISBLK(buf.st_mode))
		filetpye = "block special";
	else if (S_ISLNK(buf.st_mode))
		filetpye = "symbolic link";
	else if (S_ISFIFO(buf.st_mode))
		filetpye = "fifo";
	else if (S_ISSOCK(buf.st_mode))
		filetpye = "socket";
	else
		filetpye = " ** unknow mode **";
	printf("filetpye: %s\n", filetpye);


}
