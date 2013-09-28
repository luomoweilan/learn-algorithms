/*
 * list.c
 * Autor: z00189112 Date: 2013/09/28
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int list_add(struct list **head, void *data)
{
	struct list *p = *head;
	struct list *tmp;

	if ((tmp = (struct list *)malloc(sizeof(struct list))) == NULL) 
		return -1;
	tmp->data = data;
	tmp->next = NULL;

	if (*head == NULL) {
		*head = tmp;
		return 0;
	} 

	while (p->next != NULL)
		p = p->next;
	p->next = tmp;
	return 0;
}

void list_show(struct list *head, void (*fp)(void *data))
{
	struct list *p = head;

	while (p != NULL) {
		fp(p->data);
		p = p->next;
	}
}
