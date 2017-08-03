/*************************************************************************
    > File Name: test1_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月03日 星期四 07时00分43秒
 ************************************************************************/

#include <apue.h>
#include <dirent.h>

int
main(int argc, char *argv[])
{
	DIR		*dp1, *dp2;
	struct	dirent	*dirp1, *dirp2;

	if (argc != 3)
		err_quit("Usage: test1_1 directory_name");

	if ((dp1 = opendir(argv[1])) == NULL)
		err_sys("can't open %s", argv[1]);

	if ((dp2 = opendir(argv[2])) == NULL)
		err_sys("can't open %s", argv[1]);

	while((dirp1 = readdir(dp1)) != NULL
			&& (dirp2 = readdir(dp2)) != NULL)
	{
		printf("%s\n", dirp1->d_name);
		printf("%s\n", dirp2->d_name);
		if(strcmp(dirp1->d_name, dirp2->d_name))
		{
			printf("Different directory");
			exit(0);
		}
	}
	closedir(dp1);
	closedir(dp2);
	printf("Same directory");
	exit(0);

}

