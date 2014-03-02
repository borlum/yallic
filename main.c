#include <stdio.h>
#include "yallic.h"

int main() {
	yallicList test = createList();

	if (test) {
		printf("%s\n", "Listen er lavet!");
	} else {
		printf("%s\n", "Listen er ikke lavet!");
	}

	return 0;
}