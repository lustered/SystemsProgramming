CC = gcc
CFLAGS = -Wall

test: test1 test2 test3 test4

bstsort: bst.c
	$(CC) $(CFLAGS) bst.c -o bst

test1: bst
	./bst -o test1.txt inputfile.txt

test2: bst
	./bst -c -o test2.txt inputfile.txt

test3: bst
	./bst -o test3.txt inputfile.txt

test4: bst
	./bst -c -o test4.txt 

clean:
	- rm  bst
