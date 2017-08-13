/*************************************************************************
    > File Name: inventor.c
    > Author: King
    > Mail: arturiapendragon_1@163.com 
    > Created Time: Sun 13 Aug 2017 08:58:22 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "inventor.h"

Invrec *
create_subassy_record(int n_parts)
{
	Invrec	*new_rec;
	
	/*
	 * 试图为Invrec部分分配内存
	 */
	new_rec = malloc(sizeof(Invrec));
	if (new_rec != NULL)
	{
		/*
		 * 内存分配成功，现在存储SUBASSYINFO部分
		 */
		new_rec->info.subassy 
			= malloc(sizeof(Subassyinfo));
		if (new_rec != NULL)
		{
			/*
			 * 为零件获取一个足够大的数组
			 */
			new_rec->info.subassy->part
				= malloc(n_parts * sizeof(struct SUBASSYPART));
			if (new_rec->info.subassy->part != NULL)
			{
				/*
				 * 获取内存，填充我们已经知道的字段，然后返回 
				 */
				new_rec->type = SUBASSYPART;
				new_rec->info.subassy->n_parts = 
					nparts;
				return new_rec;
			}

			/*
			 * 内存已经用完，释放我们原先分配的内存。
			 */
			free(new_rec->info.subassy);
		}
		free(new_rec);
	}
	return NULL;
}
