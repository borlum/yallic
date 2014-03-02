#include <stdlib.h>
#include <string.h>

#include "yallic.h"

yallicList createList() {
	yallicList head;
	
	head = (yallicList)malloc(sizeof(struct yallicNode));
	if (head) {
		head->next = NULL;
	}

	return head;
}