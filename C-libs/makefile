test: test.o linked_lists.o queues.o
	gcc linked_lists.o test.o queues.o -o test -lm

linked_lists.o: linked_lists.c
	gcc -c linked_lists.c -lm

test.o: test.c
	gcc -c test.c

queues.o: queues.c
	gcc -c queues.c