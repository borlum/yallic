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

int appendTo(yallicList listHead, char * itemID, void * itemData, int itemDataSize) {
	yallicList newNode, lastNode, currentNode;

	newNode = (yallicList)malloc(sizeof(struct yallicNode));
	if (!newNode) {
		return 0;
	}

	/*Populate our node with ID*/
	strcpy(newNode->id, itemID);
	/*and Data (allocate)*/
	newNode->data = malloc(itemDataSize);
	
	if (!newNode->data) {
		free(newNode);
		return 0;
	}
	/*Copy the memory at itemData to our nodes data-pointer*/
	memcpy(newNode->data, itemData, itemDataSize);
	newNode->next = NULL;

	/*Find the last element in our list, and append!*/
	lastNode    = listHead;
	currentNode = listHead->next;
	while (currentNode) {
		lastNode = currentNode;
		currentNode = currentNode->next;
	}
	lastNode->next = newNode;
	return 1;
}

void *findIn(yallicList listHead, char * itemID) {
	yallicList currentNode;

	currentNode = listHead->next;

	while (currentNode) {
		if (!strcmp(currentNode->id, itemID)) {
			return currentNode->data;
		}
		currentNode = currentNode->next;
	}
	return NULL;
}