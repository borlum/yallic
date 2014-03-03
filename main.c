#include <stdio.h>
#include "yallic.h"

int main() {
	yallicList test = createList();
	int foo = 42;
	int * bar;

	/*LIST CREATED*/
	if (test) {
		printf("%s\n", "List created!");
	} else {
		printf("%s\n", "List not created!!");
	}

	/*APPEND NODE TO LIST*/
	if (appendTo(test, "2308", &foo, sizeof(int))) {
		printf("%s\n", "We appended something!");
	} else {
		printf("%s\n", "Nothing appended?!");
	}

	/*SAVE LIST*/
	if (saveList(test, "test.yallic")) {
		printf("%s\n", "Saved!");
	}

	/*FIND IN LIST*/
	bar = findIn(test, "2308");
	printf("%d\n", *bar);

	/*DELETE IN LIST*/
	if (deleteIn(test, "2308")) {
		printf("%s\n", "Deleted!");
	} else {
		printf("%s\n", "Could not delete?!");
	}

	if (findIn(test, "2308")) {
		printf("%s\n", "Whoops, still exists!");
	}

	/*DESTROY LIST*/
	if (!(test = destroyList(test))) {
		printf("%s\n", "List destroyed!");
	}

	/*CREATE LIST AGAIN*/
	test = createList();

	/*LOAD LIST*/
	if ((test = loadList(test, "test.yallic"))) {
		printf("%s\n", "Data loaded!");
	}

	while (test) {
		printf("%s\n", test->id);
		test = test->next;
	}

	/*FIND IN LIST*/
	bar = findIn(test, "2308");
	printf("%d\n", *bar);

	return 0;
}