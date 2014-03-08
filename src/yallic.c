#include <stdlib.h>
#include <stdio.h>
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

int appendTo(yallicList listHead, char *itemID, void *itemData, int itemDataSize) {
	yallicList newNode, lastNode, currentNode;

	/*first = head->next
	head->next = inserted
	inserted->next = first*/

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
	/*Why? Why not just point?*/
	/*memcpy(newNode->data, itemData, itemDataSize);*/
	newNode->data = itemData;
	newNode->dataSize = itemDataSize;
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

void *findIn(yallicList listHead, char *itemID) {
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

int deleteIn(yallicList listHead, char *itemID) {
	yallicList currentNode, prevNode;

	currentNode = listHead->next;
	prevNode    = listHead;
	
	while (currentNode) {
		if (!strcmp(currentNode->id, itemID)) {
			prevNode->next = currentNode->next;
			free(currentNode);
			return 1;
		}
		
		prevNode    = currentNode;
		currentNode = currentNode->next;
	}

	return 0;
}

int saveList(yallicList listHead, char *fileName) {
	FILE * file;
	yallicList currentNode;
	file = fopen(fileName, "wb");

	if (!file) {
		return 0;
	}

	currentNode = listHead->next;
	while (currentNode) {
		fwrite(currentNode, sizeof(struct yallicNode), 1, file);
		fwrite(currentNode->data, currentNode->dataSize, 1, file);
      	currentNode = currentNode->next;
	}

	fclose(file);

	return 1;
}

yallicList loadList(yallicList listHead, char *fileName) {
	FILE * file;
	yallicList currentNode, prevNode;
	file = fopen(fileName, "rb");

	if (!file) {
		return listHead;
	}

	currentNode = (yallicList)malloc(sizeof(struct yallicNode));
	prevNode = listHead;

	while (fread(currentNode,sizeof(struct yallicNode),1,file)) {
		currentNode->data = malloc(currentNode->dataSize);
		fread(currentNode->data, currentNode->dataSize, 1, file);
		prevNode->next = currentNode;
    	prevNode = currentNode;
    	currentNode = (yallicList)malloc(sizeof(struct yallicNode));
	}

	free(currentNode);
	fclose(file);

	return listHead;
}

yallicList destroyList(yallicList listHead) {
	yallicList currentNode, prevNode;

	currentNode = listHead->next;
	while (currentNode) {
		prevNode = currentNode;
		currentNode = currentNode->next;
		free(prevNode);
	}

	free(currentNode); free(listHead);
	listHead = NULL;
	return NULL;
}