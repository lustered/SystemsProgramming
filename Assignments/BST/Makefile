CC = gcc
CFLAGS = -Wall

test: run

bstsort: bst.c
	$(CC) $(CFLAGS) bst.c -o bst

run: bst
	./bst -o someoutfile.txt

clean:
	- rm  bst
