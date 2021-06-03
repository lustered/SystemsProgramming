CC = gcc
CFLAGS = -Wall


mywords: mywords.c
	$(CC) $(CFLAGS) mywords.c -o mywords 

testfile:
	@echo "If you look at what you have in life, you'll always have more. \
	If you look at what you don't have in life, you'll never have enough." > testfile

tests: mywords testfile
	- @printf "\nTest 1: Pass\n"
	- ./mywords -c -s you testfile 

	- @printf "\nTest 2: Pass\n"
	- ./mywords -s you testfile 

	- @printf "\nTest 3: Pass\n"
	- ./mywords -c testfile 

	- @printf "\nTest 4: Fail - No filename\n"
	- ./mywords -s you

	- @printf "\nTest 5: Fail - No filename\n"
	- ./mywords -c 

clean:
	- rm mywords testfile
