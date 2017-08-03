/*************************************************************************
    > File Name: 1_1.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年07月18日 星期二 22时13分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define		MAX_COLS	20				/* Maximum Line that you can handle */
#define		MAX_INPUT	1000			/* Maximum length each line	*/

int read_column_numbers( int column[], int max );
void rearrange( char *output, char const *input,
		int n_columns, int const columns[]);

int main( void )
{
	int		n_columns;			/* Line Number that you will handle */
	int		columns[MAX_COLS];	/* handle Line */
	char	input[MAX_INPUT];	/* included input line */
	char	output[MAX_INPUT];	/* included output line */

	/*	Read Line Number */
	n_columns = read_column_numbers( columns, MAX_COLS );


	/*	Read,handle and print rest line */
	while ( gets(input) != NULL){
		printf("Original input : %s\n", input );
		rearrange(output, input, n_columns, columns );
		printf("Rearranged line: %s\n", output);
	}
	return EXIT_SUCCESS;

}

int read_column_numbers( int columns[], int max)
{
	int		num = 0;
	int		ch;
	while ( num < max && scanf("%d",&columns[num]) == 1 && columns[num] > 0 )
		num +=1;
	printf("%d\n",num);

	if ( num % 2 != 0)
	{
		puts("Last column number is not pared.");
		exit( EXIT_FAILURE);
	}

	while ( (ch = getchar()) != EOF && ch != '\n');
	return num;
	
}

void rearrange(char * output, char const *input,
		int n_columns, int const columns[])
{
	int		col;			/* under line */
	int		output_col;		/* output count */
	int		len;			/* output length */

	len = strlen( input );
	output_col = 0;
	
	for ( col =0; col < n_columns; col += 2) {
		int nchars = columns[col+1] - columns[col] + 1;

		if ( columns[col] > len ||
				output_col == MAX_INPUT - 1)
			break;
		strncpy( output + output_col, input + columns[col],nchars);
		output_col += nchars;
	}
	output[output_col] = '\0';
}
