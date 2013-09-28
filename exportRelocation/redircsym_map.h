/*
 * redircsym_map.h
 * Author: z00189112 Date: 2013/09/28
 */
#ifndef __REDIRCSYM_MAP_H__
#define __REDIRCSYM_MAP_H__

#include "exportRelocation.h"

struct redircsym_map {
	char symname[SYM_NAME_LEN];
	int offset;
	int matchflag;
};

#endif
