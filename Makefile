CC=gcc.exe
CFLAGS=-Wall -g 
FILES= test.c linked_list.c doubly_linked_list.c arraylist.c hashmap.c binary_tree.c

all: test

test: $(FILES) 
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm test.exe