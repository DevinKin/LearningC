/*************************************************************************
    > File Name: test1_4.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月01日 星期二 15时59分21秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define		SIZE	1024	

void 
printHeadFile(char const *filePath);


int main(void)
{
	printHeadFile("./test4.h");
	return	EXIT_SUCCESS;
}


void
printHeadFile(char const *filePath)
{
	FILE	*fp;
	char	subName[SIZE], buf[SIZE], subPath[SIZE] = "./";
	char	*pos;
	int		size;

	fp = fopen(filePath, "r");
	if(fp == NULL)
	{
		printf("Open file faild %s", filePath);
		return;
	}

	while(fgets(buf, SIZE, fp) != NULL)
	{
		if(strstr(buf, "#include"))
		{
			if((pos = strchr(buf, '<')))
			{
				pos = strchr(buf, '<') + 1;	
				size = strchr(buf, '>') - strchr(buf, '<') - 1;
			}
			else if(strchr(buf, '\"'))
			{
				pos = strchr(buf, '\"') +1;
				size = strrchr(buf, '\"') - strchr(buf, '\"') - 1;
			}
			strncpy(subName, pos, size);
			strcat(subPath, subName);
			printHeadFile(subPath);
			memset(subName, 0, SIZE);
			strncpy(subPath, "./", SIZE);
		}
		fputs(buf, stdout);
	}
	fclose(fp);

}
