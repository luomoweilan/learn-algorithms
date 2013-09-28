/*
 * list.h
 * Author: z00189112 Date: 2013/09/28
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef __LIST_H__
#define __LIST_H__

struct list {
	void *data;
	struct list *next;
};

#endif
