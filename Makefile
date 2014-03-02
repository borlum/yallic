all:
	gcc -Wall -c -pedantic yallic.c
	gcc -Wall -pedantic main.c yallic.o -o yallic-test.out