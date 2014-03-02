#include <stdio.h>
#include "yallic.h"

int main() {
	yallicList test = createList();
	int foo = 42;
	int * bar;

	if (test) {
		printf("%s\n", "Listen er lavet!");
	} else {
		printf("%s\n", "Listen er ikke lavet!");
	}

	if (appendTo(test, "2308", &foo, sizeof(int))) {
		printf("%s\n", "Så har vi tilføjet noget!");
	} else {
		printf("%s\n", "Vi fik ikke tilføjet noget!");
	}

	bar = findIn(test, "2308");
	printf("%d\n", *bar);
	
	return 0;
}