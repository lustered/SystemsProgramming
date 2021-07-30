CC=gcc
CFLAGS=-pthread -Wall

threadcircuit: threadcircuit.c
	$(CC) $(CFLAGS) -o $@ $^

test: threadcircuit
	./threadcircuit

clean:
	rm -f threadcircuit

