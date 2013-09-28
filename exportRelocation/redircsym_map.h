/*
 * redircsym_map.h
 * Author: z00189112 Date: 2013/09/28
 */
#ifndef __REDIRCSYM_MAP_H__
#define __REDIRCSYM_MAP_H__

#include <stdio.h>
#include "exportRelocation.h"

struct redircsym_map {
	char symname[SYM_NAME_LEN];
	int offset;
	int matchflag;
};

extern int redircsym_map_add(char *str);
extern void redircsym_map_show(void);
extern struct list *redircsym_map_find(char *str);
extern void redircsym_map_set_matchflag(struct list *p);
extern void redircsym_map_set_offset(void);
extern void redircsym_map_write_to_file(FILE *f);

#endif
