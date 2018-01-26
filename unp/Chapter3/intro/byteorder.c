/*************************************************************************
    > File Name: byteorder.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2018年01月26日 星期五 22时59分44秒
 ************************************************************************/

#include "unp.h"

int main(int argc, char **argv)
{
	union {
		short s;
		char c[sizeof(short)];
	} un;

	un.s = 0x0102;
	printf("%s: ", CPU_VENDOR_OS);
	if (sizeof(short) == 2) {
		if (un.c[0] == 1 && un.c[1] == 2)
			printf("big-endian\n");
		else if (un.c[0] == 2 && un.c[1] == 1)
			printf("little-endian\n");
		else
			printf("unknown\n");
	}
	else
		printf("sizeof(short) = %d\n", sizeof(short));
	exit(0);

}