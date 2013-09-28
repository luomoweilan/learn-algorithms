/*
 * list.h
 * Author: z00189112 Date: 2013/09/28
 */

#include <stdio.h>
#include <stdlib.h>

struct list {
	void *data;
	struct list *next;
};

extern int list_add(struct list **head, void *data);
extern void list_show(struct list *head, void (*p)(void *data));
