/*************************************************************************
    > File Name: test12_7.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: 2017年08月19日 星期六 20时53分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "concordance_list.h"

#define		TRUE	1
#define		FALSE	0

int
concordance_insert(WORD_LIST **listp, char *the_word)
{
	WORD_LIST	*currentwl;
	Word		*currentwd;
	int		len = strlen(the_word);
	int		first_char;
	first_char = the_word[0];
	if (!isalpha(first_char))
		return	FALSE;
	
	for (currentwl = (*listp)->corlist; currentwl != NULL; currentwl=currentwl->corlist)
		if (currentwl->letter > first_char)
			break;

	if (currentwl == NULL || currentwl->letter > first_char)	/*  插入新的字母  */
	{
		WORD_LIST	*new_list;

		new_list = (WORD_LIST *)malloc(sizeof(WORD_LIST));
		if (new_list == NULL)
			return FALSE;

		new_list->letter = first_char;
		new_list->word_list = NULL;
		new_list->corlist = currentwl;
		*listp = new_list;
		currentwl =  new_list;
	}

	for (currentwd = currentwl->word_list; currentwd != NULL; currentwd = currentwd->next)
		if (*currentwd->word == *the_word)
			break;

	if (currentwd != NULL)			/*  在列表中找到单词  */
		return FALSE;
	else							/*  在列表中找不到单词  */
	{
		currentwd->next = malloc(sizeof(Word));
		if (currentwd->next == NULL)
			return	FALSE;
		currentwd->next->word = malloc(sizeof(char) * (len + 1));
		if (currentwd->next->word == NULL)
			return	FALSE;
		strcpy(currentwd->next->word, the_word);
		currentwd->next->next = currentwd;			/*  NULL  */
	}
	return TRUE;
}
