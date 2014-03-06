#include <stdio.h>
#include <string.h>
#include "../src/yallic.h"
#include "minunit.h"

int tests_run = 0;

static char * testCreateList() {
	yallicList test = createList();
	assert("Error; list not created", test != NULL);
	destroyList(test);
	return 0;
}

static char * allTests() {
	run_test(testCreateList);
	return 0;
}

int main(int argc, char **argv) {
	char *result = allTests();
	if (result != 0) {
	    printf("%s\n", result);
	} else {
	    printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);
	return result != 0;
}