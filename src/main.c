#include <stdio.h>
#include <string.h>
#include "yallic.h"

int main() {
	yallicList test = createList();
	struct dummyData {
		int bar;
		char str[16];
	};

	struct dummyData foo;
	struct dummyData * cat;

	foo.bar = 42;
	strcpy(foo.str, "foobar");

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
	cat = findIn(test, "2308");
	printf("%s\n", cat->str);

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

	/*FIND IN LIST*/
	cat = findIn(test, "2308");
	if (cat) {
		printf("%s\n", "Fundet igen!");
		printf("%s\n", cat->str);
	}

	return 0;
}