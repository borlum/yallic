all:
	@gcc -Wall -c -pedantic src/yallic.c
	@gcc -Wall -pedantic tests/testYallic.c yallic.o -o yallic-test.out
	@./yallic-test.out