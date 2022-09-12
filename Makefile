CC=gcc.exe
CFLAGS=-Wall -g 

all: test

test: test.c linked_list.c doubly_linked_list.c arraylist.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm test.exe