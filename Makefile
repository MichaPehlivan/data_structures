CC=gcc
CFLAGS=-Wall -g 

test: test.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm test