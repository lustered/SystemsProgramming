CC = gcc
CFLAGS = -Wall

counter: counter.c
	$(CC) $(CFLAGS) -o $@ $^

test: counter
	- ./counter

clean:
	- rm counter
