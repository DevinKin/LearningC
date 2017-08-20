/*************************************************************************
    > File Name: ins5_12.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月20日 星期日 20时40分53秒
 ************************************************************************/

#include "apue.h"

/*
 * 程序为3个标准流以及一个普通文件相关联的流打印有关缓冲的状态信息。
 */

void	pr_stdio(const char *, FILE *);
int		is_unbuffered(FILE *);
int		is_linebuffered(FILE *);
int		buffer_size(FILE *);

int
main(void)
{
	FILE	*fp;

	fputs("enter any character\n", stdout);
	if (getchar() == EOF)
		err_sys("getchar error");

	fputs("one line to standard error\n", stderr);

	pr_stdio("stdin", stdin);
	pr_stdio("stdout", stdout);
	pr_stdio("stderr", stderr);

	if ((fp = fopen("/etc/passwd", "r")) == NULL)
		err_sys("fopen error");

	if (getc(fp) == EOF)
		err_sys("getc error");
	pr_stdio("/etc/passwd", fp);
	exit (0);
}

void 
pr_stdio(const char *name, FILE *fp)
{
	printf("stream = %s", name);
	if (is_unbuffered(fp))
		printf("unbuffered");
	else if (is_linebuffered(fp))
		printf("line buffered");
	else	/*  if neither of above  */
		printf("fully buffered");
	printf(", buffer size =%d\n", buffer_size(fp));
}

/*
 * The following is nonportable.
 */

#if	defined(_IO_UNBUFFERED)

int
is_unbuffered(FILE *fp)
{
	return(fp->_flag & _IO_UNBUFFERED);
}

int 
is_linebuffered(FILE *fp)
{
	retun(fp->_flags & _IO_LINE_BUF);
}

int
buffer_size(FILE *fp)
{
	return (fp->_IO_buf_end - fp->_IO_buf_base);
}

#elif	defined(__SNBF)

int
is_unbuffered(FILE *fp)
{
	return(fp->_flags & __SNBF);
}

int
is_linebuffered(FILE *fp)
{
	return(fp->_flags & __SLBF);
}

int buffer_size(FILE *fp)
{
	return(fp->_bf._size);
}

#elif	defined(_IONBF)

#ifdef	_LP64
#define		_flag __pad[4]
#define		_ptr	__pad[1]
#define		_base	__pad[2]
#endif

int 
is_unbuffered(FILE *fp)
{
	return(fp->_flag & _IONBF);
}

int
is_linebuffered(FILE *fp)
{
	return(fp->_flag & _IOLBF);
}

int
buffer_size(FILE *fp)
{
#ifdef	_LP64
	return(fp->_base - fp->_ptr);
#else
	return(BUFFSIZ);		/*  just a guess  */
#endif
}

#else
#error	unknown	stdio implementation!

#endif
