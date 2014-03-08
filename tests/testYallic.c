#include <stdio.h>
#include <string.h>
#include "../src/yallic.h"
#include "minunit.h"

int tests_run = 0;

static char * testCreateList() {
	int returnVal = 0;
	yallicList sampleList = createList();
	if (sampleList) {
		returnVal = 1;
	}
	destroyList(sampleList);
	assert("Error; list not created", returnVal != 0);
	return 0;
}

static char * testDestroyList() {
	void *returnVal;
	yallicList sampleList = createList();
	sampleList = destroyList(sampleList);
	returnVal = sampleList;
	assert("Error; list still exists", returnVal == NULL);
	return 0;
}

static char * testAppendNode() {
	struct dummyData {
		int bar;
		char str[16];
	};

	struct dummyData foo;
	int returnVal = 0;
	yallicList sampleList = createList();

	foo.bar = 42;
	strcpy(foo.str, "foobar");

	returnVal = appendTo(sampleList, "2308", &foo, sizeof(struct dummyData));
	destroyList(sampleList);
	assert("Error; nothing appended to list", returnVal != 0);
	return 0;
}

static char * testSaveList() {
	struct dummyData {
		int bar;
		char str[16];
	};

	struct dummyData foo;
	int returnVal = 0;
	yallicList sampleList = createList();

	foo.bar = 42;
	strcpy(foo.str, "foobar");

	if (appendTo(sampleList, "2308", &foo, sizeof(struct dummyData))) {
		returnVal = saveList(sampleList, "sampleList.yallic");
	}

	destroyList(sampleList);
	assert("Error; could not save list to file", returnVal != 0);
	return 0;
}

static char * testFindInListSuccess() {
	struct dummyData {
		int bar;
		char str[16];
	};

	struct dummyData foo;
	void * returnVal = NULL;
	yallicList sampleList = createList();

	foo.bar = 42;
	strcpy(foo.str, "foobar");

	if (appendTo(sampleList, "2308", &foo, sizeof(struct dummyData))) {
		returnVal = findIn(sampleList, "2308");
	}

	destroyList(sampleList);
	assert("Error; nothing found!", returnVal != NULL);
	return 0;
}

static char * testFindInListFail() {
	struct dummyData {
		int bar;
		char str[16];
	};

	struct dummyData foo;
	void * returnVal = NULL;
	yallicList sampleList = createList();

	foo.bar = 42;
	strcpy(foo.str, "foobar");

	if (appendTo(sampleList, "2307", &foo, sizeof(struct dummyData))) {
		returnVal = findIn(sampleList, "2308");
	}

	destroyList(sampleList);
	assert("Error; something found!", returnVal == NULL);
	return 0;
}

static char * testDeleteInList() {
	struct dummyData {
		int bar;
		char str[16];
	};

	struct dummyData foo;
	int returnVal = 0;
	yallicList sampleList = createList();

	foo.bar = 42;
	strcpy(foo.str, "foobar");

	if (appendTo(sampleList, "2308", &foo, sizeof(struct dummyData))) {
		returnVal = deleteIn(sampleList, "2308");
	}

	if (returnVal) {
		if (findIn(sampleList, "2308")) {
			returnVal = 0;
		}
	}

	destroyList(sampleList);
	assert("Error; nothing deleted!", returnVal != 0);
	return 0;
}

static char * testLoadListSuccess() {
	void *returnVal;
	yallicList sampleList = createList();

	sampleList = loadList(sampleList, "sampleList.yallic");

	returnVal = findIn(sampleList, "2308");
	destroyList(sampleList);
	assert("Error; nothing loaded from file!", returnVal != NULL);
	return 0;
}

static char * testLoadListFileNotFound() {
	yallicList sampleList, loadedList;

	sampleList = createList();
	loadedList = loadList(sampleList, "wrongFileName.yallic");

	destroyList(sampleList);
	assert("Error; the file was found?!", sampleList == loadedList);
	return 0;
}

static char * allTests() {
	run_test(testCreateList);
	run_test(testDestroyList);
	run_test(testAppendNode);
	run_test(testSaveList);
	run_test(testFindInListSuccess);
	run_test(testFindInListFail);
	run_test(testDeleteInList);
	run_test(testLoadListSuccess);
	run_test(testLoadListFileNotFound);
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