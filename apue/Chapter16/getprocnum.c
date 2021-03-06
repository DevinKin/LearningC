/*************************************************************************
    > File Name: getprocnum.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月08日 星期一 13时53分52秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	int i, len, count = 0;

	if ((dp = opendir("/proc")) == NULL)
	{
		fprintf(stderr, "%s file %d line %s", __FILE__, __LINE__, strerror(errno));
		exit(1);
	}

	while ((dirp = readdir(dp)) != NULL)
	{
		if (dirp->d_type == DT_DIR)
		{
			len = strlen(dirp->d_name);
			for (i = 0; dirp->d_name[i] != 0; ++i)
				if (!isdigit(dirp->d_name[i]))
					break;
		}
		if (len == i)
		{
			//printf("d_name: %s\n", dirp->d_name);
			++count;
		}
	}
	fprintf(stdout ,"当前系统运行进程数: %d\n", count);
	closedir(dp);
	return(0);
}
