CC = gcc
CFLAGS = -Wall

counter: counter.c
	$(CC) $(CFLAGS) -o counter counter.c 

test: counter
	- ./counter

clean:
	- rm counter
