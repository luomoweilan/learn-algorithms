/*
 * redircsym_info.h
 * Author: z00189112 Date: 2013/09/28
 */

#include "list.h"

struct redircsym_info {
	int  symaddr;
	char symtype;
	char rev1;
	char redirctype;
	int  offset;
	int  rev2;
	struct list *map;
};
