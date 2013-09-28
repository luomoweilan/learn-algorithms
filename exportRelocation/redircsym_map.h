/*
 * redircsym_map.h
 * Author: z00189112 Date: 2013/09/28
 */

#include "exportRelocation.h"

struct redircsym_map {
	char symname[SYM_NAME_LEN];
	int offset;
	int matchflag;
};

