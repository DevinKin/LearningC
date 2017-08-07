/*************************************************************************
    > File Name: test10_3.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Mon 07 Aug 2017 10:11:27 PM CST
 ************************************************************************/

#include <stdio.h>



typedef	union {
	unsigned short	addr;
	struct {
		unsigned	dst_reg	: 3;
		unsigned	dst_mode : 3;
		unsigned	opcode : 9;
	}	sgl_op;

	struct {
		unsigned	dst_reg : 3;
		unsigned	dst_mode : 3;
		unsigned	src_reg	: 3;
		unsigned	src_mode : 3;
		unsigned	opcode : 4;
	}	dbl_op;

	struct	branch {
		unsigned	offset : 8;
		unsigned	opcode : 8;
	};

	struct {
		unsigned	dst_reg : 3;
		unsigned	dst_mode : 3;
		unsigned	src_reg : 3;
		unsigned	opcode : 7;
	}	src_reg;

	struct {
		unsigned	opcode : 16;
	}	misc;

} machine_inst;
