/*************************************************************************
    > File Name: shmdata.h
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年12月24日 星期日 13时33分55秒
 ************************************************************************/

#ifndef _SHMDATA_H_HEADER
#define _SHMDATA_H_HEADER

#define TEXT_SZ 2048


struct shared_use_st
{
	int written;		//作为一个标志，非０，表示可读，０表示可写
	char text[TEXT_SZ];			//记录写入和读取的文本
};

#endif
