CC = gcc
CFLAGS = -Wall

all: bitflip test1

bitflip: bitflip.c
	$(CC) $(CFLAGS) bitflip.c -o bitflip 

test1: bitflip
	- @printf "\nTest 1\n"
	- ./bitflip

clean:
	rm bitflip
