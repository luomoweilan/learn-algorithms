/*
 * redircsym_map.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "exportRelocation.h"
#include "redircsym_map.h"

struct list *redircsym_map_list;

static void redircsym_map_print(void *data)
{
	struct redircsym_map *p = (struct redircsym_map *)data;
	printf("%-16s %-5d %-5d\n", p->symname, p->offset, p->matchflag);
}

void redircsym_map_show(void)
{
	list_show(redircsym_map_list, redircsym_map_print);
}

int redircsym_map_add(char *str)
{
	struct redircsym_map *tmp;

	if ((tmp = (struct redircsym_map *)malloc(sizeof(struct redircsym_map))) == NULL) 
		return -1;
	memset(tmp, 0, sizeof(struct redircsym_map));
	memcpy(tmp->symname, str, SYM_NAME_LEN);
	(tmp->symname)[strlen(str) - 1] = 0;

	if (!list_add(&redircsym_map_list, (void *)tmp))
		return -1;
	return 0;
}

struct list *redircsym_map_find(char *str)
{
	struct list *p = redircsym_map_list;
	struct redircsym_map *tmp;

	while (p != NULL) {
		tmp = (struct redircsym_map *)(p->data);
		if (!strcmp(tmp->symname, str))
			break;
		p = p->next;
	}
	return p;
}

void redircsym_map_set_matchflag(struct list *p)
{
	struct redircsym_map *tmp;

	tmp = (struct redircsym_map *)(p->data);
	tmp->matchflag = 1;
}

void redircsym_map_set_offset(void)
{
	struct list *p = redircsym_map_list;
	struct redircsym_map *tmp;
	int offset = 0;

	while (p != NULL) {
		tmp = (struct redircsym_map *)(p->data);
		if (tmp->matchflag) {
			tmp->offset = offset;
			offset++;
		}
		p = p->next;
	}
}

void redircsym_map_write_to_file(FILE *f)
{
	struct list *p = redircsym_map_list;
	struct redircsym_map *tmp;

	while (p != NULL) {
		tmp = (struct redircsym_map *)(p->data);
		if (tmp->matchflag) {
			fwrite(tmp->symname, 1, SYM_NAME_LEN, f);
		}
		p = p->next;
	}
}
