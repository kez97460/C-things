test: test.o linked_lists.o adjacency_matrix.o
	gcc test.o adjacency_matrix.o -o test -lm

test.o: test.c
	gcc -c test.c

adjacency_matrix.o: adjacency_matrix.c
	gcc -c adjacency_matrix.c