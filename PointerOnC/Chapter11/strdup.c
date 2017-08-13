/*************************************************************************
    > File Name: strdup.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Sun 13 Aug 2017 08:21:30 PM CST
 ************************************************************************/

/*
 * 用动态分配内存制作一个字符串的一份拷贝，注意：调用程序应该负责检查这块内
 * 存是否成功分配！这样调用程序以任何它所希望的方式对错误作出反应。
 */

#include <stdlib.h>
#include <string.h>

char *
strdup(char const *string)
{
	char	*new_string;

	/*
	 * 请求足够长度的内存，用于存储字符串和它的结尾NUL字节
	 */

	new_string = malloc(strlen(string) + 1);

	/*
	 * 如果我们得到内存，就复制字符串
	 */

	if (new_string != NULL)
		strcpy(new_string, string);

	return new_string;
}

