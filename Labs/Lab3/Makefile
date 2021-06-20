CC=gcc
CFLAGS=-Wall

mywords: mywords.c
	$(CC) $(CFLAGS) $< -o $@ 

testfile:
	@printf "Creating test file.\n"
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
	- @printf "\nTest 6: Fail - No substring\n"
	- ./mywords -s testfile 
	- @printf "\nTest 7: No flags passed\n"
	- ./mywords testfile 
	- @printf "\nRemoving test file\n"
	- @rm -f testfile

clean:
	- rm -f mywords testfile
