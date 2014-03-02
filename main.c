#include <stdio.h>
#include "yallic.h"

int main() {
	yallicList test = createList();
	int foo = 42;
	int * bar;

	if (test) {
		printf("%s\n", "List created!");
	} else {
		printf("%s\n", "Listen not created!!");
	}

	if (appendTo(test, "2308", &foo, sizeof(int))) {
		printf("%s\n", "We appended something!");
	} else {
		printf("%s\n", "Nothing appended?!");
	}

	bar = findIn(test, "2308");
	printf("%d\n", *bar);

	if (deleteIn(test, "2308")) {
		printf("%s\n", "Deleted!");
	} else {
		printf("%s\n", "Could not delete?!");
	}

	if (findIn(test, "2308")) {
		printf("%s\n", "Whoops, still exists!");
	}

	if (!(test = destroyList(test))) {
		printf("%s\n", "List destroyed!");
	}



	return 0;
}