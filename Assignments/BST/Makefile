CC = gcc
CFLAGS = -Wall

test: test1 test2 

bstsort: bstsort.c
	$(CC) $(CFLAGS) bstsort.c -o bstsort

test1: bstsort
	-@printf "\nTest1\n"
	./bstsort -o test1.txt inputfile.txt
	-@cat test1.txt

test2: bstsort
	-@printf "\nTest2\n"
	./bstsort -c -o test2.txt inputfile.txt
	-@cat test2.txt

test3: bstsort
	-@printf "\nTest3\n"
	./bstsort -c

test4: bstsort
	-@printf "\nTest4\n"
	./bstsort -c wronginputfile.txt

clean:
	- rm -f bstsort test1.txt test2.txt 
