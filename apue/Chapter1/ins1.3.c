/*************************************************************************
    > File Name: ls.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月15日 星期六 19时42分51秒
 ************************************************************************/

#include "apue.h"
#include <dirent.h>
int main(int argc,char *argv[])
{
	DIR				*dp;
	struct	dirent	*dirp;

	if( argc != 2)
		err_quit("usage:ls directory_name");
	if((dp = opendir(argv[1])) == NULL)	
		err_sys("can't open %s",argv[1]);
	while((dirp=readdir(dp)) != NULL)
		printf("%s\n",dirp->d_name);
	closedir(dp);
	exit(0);
	
}
