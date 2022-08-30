CC=gcc.exe
CFLAGS=-Wall -g 

all: test

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

test: test.c linked_list.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm test.exe *.o