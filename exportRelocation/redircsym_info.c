/*
 * redircsym_info.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "exportRelocation.h"
#include "list.h"
#include "redircsym_info.h"

struct list *redircsym_info_list;

int redircsym_info_isppc(char *line, char *symaddr, char *symtype, char *symname)
{
	return 0;

}
static void redircsym_info_print(void *data)
{
	struct redircsym_info *tmp = (struct redircsym_info *)data;
	printf("%-10d %-5d %-5d %-5d %-5d %-10x\n", tmp->symaddr, tmp->symtype, tmp->rev1,
			tmp->redirctype, tmp->offset, tmp->rev2, tmp->map);
}

int redircsym_info_show()
{
	list_show(redircsym_info_list, redircsym_info_print);
}

int redircsym_info_add(char *symadd, char *symtype, struct list *p)
{
	struct redircsym_info *tmp;

	if ((tmp = (struct redircsym_info *)malloc(sizeof(struct redircsym_info))) == NULL)
		return -1;
	memset(tmp, 0, sizeof(struct redircsym_info));
	//memcpy(tmp->symaddr, )
	
	if (!strcmp("R_386_PC32", symtype))
		tmp->symtype = 0x06;
	tmp->rev1 = 1;
	tmp->redirctype = 2;
	tmp->offset = 0;
	tmp->rev2 = 0;
	tmp->map = p;
	if (!list_add(&redircsym_info_list, (void *)tmp))
		return -1;
	return 0;
}

void redircsym_info_set_offset(void)
{
	struct list *p = redircsym_info_list;
	struct redircsym_info *tmp_info;
	struct redircsym_map *tmp_map;
	struct list *tmp_list;

	while (p != NULL) {
		tmp_info = (struct redircsym_info *)(p->data);
		tmp_list = (struct list *)(tmp_info->map);
		tmp_map = (struct redircsym_map *)(tmp_list->data);
	//	tmp_info->offset = tmp_map->offset;
		p = p->next;
	}
}

void redircsym_info_write_to_file(FILE *f)
{
	struct list *p = redircsym_info_list;
	struct redircsym_info *tmp;

	while (p != NULL) {
		tmp = (struct redircsym_info *)(p->data);
		fwrite((char *)tmp->symaddr, 1, sizeof(int), f);
		p = p->next;
	}
}
